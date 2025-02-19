import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class ContaService {

    public static void criarConta(int idCliente, String tipoConta, String agencia, double saldo) throws Exception {
        /// Verifica se o ID do cliente existe na tabela cliente
        try (Connection conn = Bd_Sql.conectar()) {
            String sqlVerificarCliente = "SELECT COUNT(*) FROM cliente WHERE id_cliente = ?";
            try (PreparedStatement stmtVerificar = conn.prepareStatement(sqlVerificarCliente)) {
                stmtVerificar.setInt(1, idCliente);
                ResultSet rs = stmtVerificar.executeQuery();
                rs.next();

                if (rs.getInt(1) == 0) {
                    throw new Exception("Cliente não encontrado. Faça login novamente.");
                }
            }

            /// Verifica se o número da agência já existe
            String sqlVerificarAgencia = "SELECT COUNT(*) FROM conta WHERE agencia = ?";
            try (PreparedStatement stmtVerificar = conn.prepareStatement(sqlVerificarAgencia)) {
                stmtVerificar.setString(1, agencia);
                ResultSet rs = stmtVerificar.executeQuery();
                rs.next();

                if (rs.getInt(1) > 0) {
                    throw new Exception("Número de agência já existente.");
                }
            }

            /// Insere a conta na tabela conta
            String sqlConta = "INSERT INTO conta (id_cliente, agencia, saldo) VALUES (?, ?, ?)";
            try (PreparedStatement stmt = conn.prepareStatement(sqlConta, PreparedStatement.RETURN_GENERATED_KEYS)) {
                stmt.setInt(1, idCliente);
                stmt.setString(2, agencia);
                stmt.setDouble(3, saldo);
                stmt.executeUpdate();

                /// Obtém o 'ID' da conta recém-criada
                ResultSet rs = stmt.getGeneratedKeys();
                int idConta = -1;
                if (rs.next()) {
                    idConta = rs.getInt(1);
                }

                /// Insere na tabela específica (conta_corrente ou conta_poupanca)
                if (tipoConta.equals("Corrente")) {
                    String sqlCorrente = "INSERT INTO conta_corrente (id_conta, limite_especial) VALUES (?, 0.00)";
                    try (PreparedStatement stmtCorrente = conn.prepareStatement(sqlCorrente)) {
                        stmtCorrente.setInt(1, idConta);
                        stmtCorrente.executeUpdate();
                    }
                } else if (tipoConta.equals("Poupança")) {
                    String sqlPoupanca = "INSERT INTO conta_poupanca (id_conta, rendimento) VALUES (?, 5.00)";
                    try (PreparedStatement stmtPoupanca = conn.prepareStatement(sqlPoupanca)) {
                        stmtPoupanca.setInt(1, idConta);
                        stmtPoupanca.executeUpdate();
                    }
                }
            }
        } catch (SQLException ex) {
            throw new Exception("Erro ao criar a conta: " + ex.getMessage());
        }
    }
}
