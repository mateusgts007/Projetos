import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TelaInicial extends JFrame{

    public TelaInicial (){
        /// configurações da janela
        setTitle("Tela Inical");
        setSize(400,300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); /// centralizando a janela

        ///  painel principal
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(3, 1, 10, 10)); /// layout com 3 linhas

        /// botoes
        JButton btnLogin = new JButton("Login");
        JButton btnCadastro = new JButton("Cadastro");

        /// boas vindas
        JLabel lblTitulo = new JLabel("Bem-vindo ao banco", SwingConstants.CENTER);
        lblTitulo.setFont(new Font("Arial", Font.BOLD, 18));

        ///  componentes do painel
        panel.add(lblTitulo);
        panel.add(btnLogin);
        panel.add(btnCadastro);

        btnLogin.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                dispose(); /// fecha a tela inicial
                new TelaLogin(); /// inicia a tela de login
            }
        });

        btnCadastro.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                dispose(); /// fecha a tela incinal
                new TelaCadastroCliente(); /// inicia a tela de cadastrp
            }
        });

        add(panel); /// painel adicionado à janela

        setVisible(true); /// deixa visivel
    }
}
