import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class OperacaoBancariaService {

    public static void sacar(int idCliente, double valor) throws Exception {
        try (Connection conn = Bd_Sql.conectar()) {
            /// Verifica saldo disponível em conta
            String sqlConsulta = "SELECT id_conta, saldo FROM conta WHERE id_cliente = ?";
            try (PreparedStatement stmtConsulta = conn.prepareStatement(sqlConsulta)) {
                stmtConsulta.setInt(1, idCliente);
                ResultSet rs = stmtConsulta.executeQuery();

                if (rs.next()) {
                    int idConta = rs.getInt("id_conta");
                    double saldoAtual = rs.getDouble("saldo");

                    if (saldoAtual >= valor) {
                        /// Atualiza o saldo na conta
                        String sqlSaque = "UPDATE conta SET saldo = saldo - ? WHERE id_conta = ?";
                        try (PreparedStatement stmtSaque = conn.prepareStatement(sqlSaque)) {
                            stmtSaque.setDouble(1, valor);
                            stmtSaque.setInt(2, idConta);
                            stmtSaque.executeUpdate();
                        }
                    } else {
                        throw new Exception("Saldo insuficiente!");
                    }
                } else {
                    throw new Exception("Conta não encontrada.");
                }
            }
        } catch (SQLException ex) {
            throw new Exception("Erro ao processar o saque: " + ex.getMessage());
        }
    }

    public static void depositar(int idCliente, double valor) throws Exception {
        try (Connection conn = Bd_Sql.conectar()) {
            /// Obtém o 'id' da conta do cliente
            String sqlConsulta = "SELECT id_conta FROM conta WHERE id_cliente = ?";
            int idConta = -1;

            try (PreparedStatement stmtConsulta = conn.prepareStatement(sqlConsulta)) {
                stmtConsulta.setInt(1, idCliente);
                ResultSet rs = stmtConsulta.executeQuery();

                if (rs.next()) {
                    idConta = rs.getInt("id_conta");
                } else {
                    throw new Exception("Conta não encontrada.");
                }
            }

            /// Atualiza o saldo no banco de dados
            String sqlDeposito = "UPDATE conta SET saldo = saldo + ? WHERE id_conta = ?";
            try (PreparedStatement stmtDeposito = conn.prepareStatement(sqlDeposito)) {
                stmtDeposito.setDouble(1, valor);
                stmtDeposito.setInt(2, idConta);
                stmtDeposito.executeUpdate();
            }
        } catch (SQLException ex) {
            throw new Exception("Erro ao processar o depósito: " + ex.getMessage());
        }
    }

    public static void transferir(int idCliente, double valor, String emailDestinatario) throws Exception {
        try (Connection conn = Bd_Sql.conectar()) {
            conn.setAutoCommit(false); /// Inicia a transação

            /// Obtém saldo e 'ID' da conta do remetente
            String sqlSaldo = "SELECT id_conta, saldo FROM conta WHERE id_cliente = ?";
            int idContaRemetente = -1;
            double saldoAtual = 0;

            try (PreparedStatement stmtSaldo = conn.prepareStatement(sqlSaldo)) {
                stmtSaldo.setInt(1, idCliente);
                ResultSet rsSaldo = stmtSaldo.executeQuery();

                if (rsSaldo.next()) {
                    idContaRemetente = rsSaldo.getInt("id_conta");
                    saldoAtual = rsSaldo.getDouble("saldo");
                } else {
                    throw new Exception("Conta de origem não encontrada.");
                }
            }

            /// Verifica se tem saldo suficiente
            if (saldoAtual < valor) {
                throw new Exception("Saldo insuficiente.");
            }

            /// Obtém 'ID' da conta do destinatário
            String sqlDestinatario = "SELECT conta.id_conta FROM conta INNER JOIN cliente ON conta.id_cliente = cliente.id_cliente WHERE LOWER(cliente.email) = LOWER(?)";
            int idContaDestinatario = -1;

            /// Converte o e-mail digitado para minúsculas antes de buscar no banco
            emailDestinatario = emailDestinatario.trim().toLowerCase();

            try (PreparedStatement stmtDestinatario = conn.prepareStatement(sqlDestinatario)) {
                stmtDestinatario.setString(1, emailDestinatario);
                ResultSet rsDestinatario = stmtDestinatario.executeQuery();

                if (rsDestinatario.next()) {
                    idContaDestinatario = rsDestinatario.getInt("id_conta");
                } else {
                    throw new Exception("Destinatário não encontrado.");
                }
            }

            /// Debita o valor do remetente
            String sqlDebitar = "UPDATE conta SET saldo = saldo - ? WHERE id_conta = ?";
            try (PreparedStatement stmtDebitar = conn.prepareStatement(sqlDebitar)) {
                stmtDebitar.setDouble(1, valor);
                stmtDebitar.setInt(2, idContaRemetente);
                stmtDebitar.executeUpdate();
            }

            /// Credita o valor no destinatário
            String sqlCreditar = "UPDATE conta SET saldo = saldo + ? WHERE id_conta = ?";
            try (PreparedStatement stmtCreditar = conn.prepareStatement(sqlCreditar)) {
                stmtCreditar.setDouble(1, valor);
                stmtCreditar.setInt(2, idContaDestinatario);
                stmtCreditar.executeUpdate();
            }

            /// Registra a transação na tabela transacao
            String sqlTransacao = "INSERT INTO transacao (id_conta_origem, id_conta_destino, tipo, valor) VALUES (?, ?, ?, ?)";
            try (PreparedStatement stmtTransacao = conn.prepareStatement(sqlTransacao)) {
                stmtTransacao.setInt(1, idContaRemetente);
                stmtTransacao.setInt(2, idContaDestinatario);
                stmtTransacao.setString(3, "transferencia");
                stmtTransacao.setDouble(4, valor);
                stmtTransacao.executeUpdate();
            }

            conn.commit(); /// Confirma a transação
        } catch (SQLException ex) {
            throw new Exception("Erro ao processar a transferência: " + ex.getMessage());
        }
    }
}