import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class TelaLogin extends JFrame {

    public TelaLogin() {

        /// Configurações da janela
        setTitle("Tela de Login");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); // Centraliza a janela

        /// Criando o painel
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(3, 2, 10, 10)); // Layout com 3 linhas e 2 colunas

        /// Criando componentes
        JLabel lblEmail = new JLabel("Email:");
        JTextField txtEmail = new JTextField(20);

        JLabel lblSenha = new JLabel("Senha:");
        JPasswordField txtSenha = new JPasswordField(20);

        JButton btnLogin = new JButton("Entrar");

        /// Ajustando a altura dos campos
        txtEmail.setPreferredSize(new Dimension(200, 30)); /// Ajusta o tamanho do campo de usuario
        txtSenha.setPreferredSize(new Dimension(200, 30)); /// Ajusta o tamanho do campo de senha

        /// Adicionando componentes ao painel
        panel.add(lblEmail);
        panel.add(txtEmail);
        panel.add(lblSenha);
        panel.add(txtSenha);
        panel.add(btnLogin);

        /// Adicionando ação ao botão de 'login'
        btnLogin.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String email = txtEmail.getText();
                char[] senha = txtSenha.getPassword();

                /// Converte a senha para hash 256
                String senhaDigitadaHash = HashUtil.hashSenha(new String(senha)); // Convertendo corretamente

                /// Validação do 'login' com banco de dados
                String sql = "SELECT senha FROM cliente WHERE email = ?"; // Nome da coluna corrigido para "senha"

                try (Connection conn = Bd_Sql.conectar();
                     PreparedStatement stmt = conn.prepareStatement(sql)) {

                    stmt.setString(1, email);
                    ResultSet rs = stmt.executeQuery();

                    if (rs.next()) {
                        String senhaArmazenada = rs.getString("senha"); /// Recupera a senha hash armazenada

                        if (senhaDigitadaHash.equals(senhaArmazenada)) {
                            JOptionPane.showMessageDialog(null, "Login realizado com sucesso!");

                            /// Redireciona para a tela de criação de conta, sendo corrente ou poupança
                            new TelaMenuPrincipal();

                            dispose(); /// Fecha a tela de login

                        } else {
                            JOptionPane.showMessageDialog(null, "Usuário ou senha inválidos."); /// Senha errada
                        }

                    } else {
                        JOptionPane.showMessageDialog(null, "Usuário não encontrado."); /// Usuário não existe
                    }

                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(null, "Erro de banco de dados: " + ex.getMessage());
                }
            }
        });

        /// Adicionando o painel à janela
        add(panel);

        /// Tornando a janela visível
        setVisible(true);
    }
}
