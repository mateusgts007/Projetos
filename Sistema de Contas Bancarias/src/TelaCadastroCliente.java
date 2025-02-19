import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class TelaCadastroCliente extends JFrame {

    public TelaCadastroCliente() {

        /// Configurações da janela
        setTitle("Cadastro de Cliente");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); /// Centraliza a janela

        /// Criando o painel
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(6, 2, 10, 10)); // Layout com 5 linhas e 2 coluna

        ///  COMPONENTES
        JLabel lblNome = new JLabel("Nome:");
        JTextField txtNome = new JTextField(20);

        JLabel lblEmail = new JLabel("Email:");
        JTextField txtEmail = new JTextField(20);

        JLabel lblCpf = new JLabel("CPF:");
        JTextField txtCpf = new JTextField(20);

        JLabel lblTelefone = new JLabel("telefone:");
        JTextField txtTelefone = new JTextField(20);

        JLabel lblSenha = new JLabel("Senha:");
        JPasswordField txtSenha = new JPasswordField(20);

        JButton btnCadastrar = new JButton("Cadastrar");

        /// Adicionando os componentes ao painel
        panel.add(lblNome);
        panel.add(txtNome);
        panel.add(lblEmail);
        panel.add(txtEmail);
        panel.add(lblCpf);
        panel.add(txtCpf);
        panel.add(lblTelefone);
        panel.add(txtTelefone);
        panel.add(lblSenha);
        panel.add(txtSenha);
        panel.add(new JLabel()); /// Espaço vazio
        panel.add(btnCadastrar);


        /// Adicionando ação ao botão de cadastro
        btnCadastrar.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {

                try {
                    /// Captura os dados inseridos
                    String nome = txtNome.getText();
                    String email = txtEmail.getText();
                    String cpf = txtCpf.getText();
                    String telefone = txtTelefone.getText();
                    String senha = txtSenha.getText();

                    /// Chama o método de cadastro do cliente
                    ClienteService.cadastrarCliente(nome, email, cpf, telefone, senha);

                    JOptionPane.showMessageDialog(null, "Cadastro realizado com sucesso!");

                    dispose(); /// Fecha a tela de cadastro
                    new TelaConta(); /// Abre a tela de conta
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, "Erro: " + ex.getMessage());
                }

            }
        });

        add(panel); /// Adicionando o painel à janela

        setVisible(true); /// Tornando a janela visível
    }
}
