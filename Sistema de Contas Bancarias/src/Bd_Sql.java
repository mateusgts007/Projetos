import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Bd_Sql {
    private static final String URL = "jdbc:mysql://localhost:3306/conta_banco?useSSL=false&serverTimezone=UTC";
    private static final String USUARIO = "root";  // Usuário padrão do WAMP
    private static final String SENHA = "";        // Senha vazia no WAMP por padrão

    public static Connection conectar() throws SQLException {
        try {
            // Estabelecer conexão com o banco de dados
            return DriverManager.getConnection(URL, USUARIO, SENHA);
        } catch (SQLException e) {
            System.out.println("Erro ao conectar ao banco de dados: " + e.getMessage());
        }
        return null;
    }

    public static void fecharConexao(Connection conexao) {
        try {
            if (conexao != null && !conexao.isClosed()) {
                conexao.close();
                System.out.println("Conexão fechada com sucesso.");
            }
        } catch (SQLException e) {
            System.out.println("Erro ao fechar conexão: " + e.getMessage());
        }
    }


}
