import java.sql.*;

public class ClienteService {

    /// Classe com a lógica de cadastramento do cliente

    public static void cadastrarCliente(String nome, String email, String cpf, String telefone, String senha) throws Exception {
        /// Aplicando o sha-256
        String senhaHash = HashUtil.hashSenha(senha);

        /// Verificando se os campos estão vazios
        if (nome.isEmpty() || email.isEmpty() || cpf.isEmpty() || telefone.isEmpty() || senha.isEmpty()) {
            throw new Exception("Todos os campos devem ser preenchidos");
        }

        /// Validar o formato do CPF
        if (!cpf.matches("\\d{11}")) {
            throw new Exception("O CPF deve conter 11 dígitos");
        }

        /// Validação do formato do email
        if (!email.matches("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$")) {
            throw new Exception("O email fornecido não tem um formato válido");
        }

        /// Validação do telefone
        if (!telefone.matches("\\d{11}")) {
            throw new Exception("O telefone deve conter 11 dígitos numéricos.");
        }

        //// Verificação do tamanho da senha
        if (senha.length() < 6) {
            throw new Exception("A senha deve ter no mínimo 6 caracteres.");
        }

        /// Conexão com o banco de dados
        try (Connection conn = Bd_Sql.conectar()) {

            /// Verifica se o email ou CPF já existem
            String sqlVerificarEmailCPF = "SELECT COUNT(*) FROM cliente WHERE email = ? OR cpf = ?";
            try (PreparedStatement stmtVerificar = conn.prepareStatement(sqlVerificarEmailCPF)) {
                stmtVerificar.setString(1, email);
                stmtVerificar.setString(2, cpf);
                ResultSet rsVerificar = stmtVerificar.executeQuery();

                if (rsVerificar.next() && rsVerificar.getInt(1) > 0) {
                    throw new Exception("E-mail ou CPF já cadastrado.");
                }
            }

            /// Verifica se o telefone já existe
            String sqlVerificarTelefone = "SELECT COUNT(*) FROM telefone WHERE numero = ?";
            try (PreparedStatement stmtVerificarTelefone = conn.prepareStatement(sqlVerificarTelefone)) {
                stmtVerificarTelefone.setString(1, telefone);
                ResultSet rsTelefone = stmtVerificarTelefone.executeQuery();

                if (rsTelefone.next() && rsTelefone.getInt(1) > 0) {
                    throw new Exception("Este telefone já está cadastrado.");
                }
            }

            /// Inserção do cliente
            String sqlCliente = "INSERT INTO cliente (nome, email, cpf, senha) VALUES (?, ?, ?, ?)";
            String sqlTelefone = "INSERT INTO telefone (id_cliente, numero, tipo) VALUES (?, ?, ?)";

            try (PreparedStatement stmtCliente = conn.prepareStatement(sqlCliente, Statement.RETURN_GENERATED_KEYS);
                 PreparedStatement stmtTelefone = conn.prepareStatement(sqlTelefone)) {

                /// Inserir o cliente na tabela 'cliente'
                stmtCliente.setString(1, nome);
                stmtCliente.setString(2, email);
                stmtCliente.setString(3, cpf);
                stmtCliente.setString(4, senhaHash);
                int rowsAffected = stmtCliente.executeUpdate();

                if (rowsAffected > 0) {
                    ResultSet generatedKeys = stmtCliente.getGeneratedKeys();
                    if (generatedKeys.next()) {
                        int idCliente = generatedKeys.getInt(1); /// Obtém o 'id' do cliente inserido
                        SessaoUsuario.setIdCliente(idCliente); // Armazena o id_cliente na sessão

                        /// Inserir o telefone na tabela 'telefone'
                        stmtTelefone.setInt(1, idCliente);
                        stmtTelefone.setString(2, telefone);
                        stmtTelefone.setString(3, "Celular");
                        stmtTelefone.executeUpdate(); /// Executa a inserção do telefone
                    } else {
                        throw new Exception("Erro ao obter ID do cliente.");
                    }
                } else {
                    throw new Exception("Erro ao salvar o cliente no banco de dados.");
                }
            }
        } catch (SQLException ex) {
            throw new Exception("Erro de banco de dados: " + ex.getMessage());
        }
    }
}
