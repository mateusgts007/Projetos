import java.sql.Connection;
import java.sql.SQLException;

public class Banco {

    public static void main(String[] args) throws SQLException {

        new TelaInicial(); /// executando a tela inicial swing

        /// Usando a classe Bd_Sql para conectar
        Connection conexao = Bd_Sql.conectar();

        if (conexao != null) {
            System.out.println("Conectado ao banco de dados com sucesso!");
            Bd_Sql.fecharConexao(conexao);
        } else {
            System.out.println("Falha na conexão.");
        }





    }

}
