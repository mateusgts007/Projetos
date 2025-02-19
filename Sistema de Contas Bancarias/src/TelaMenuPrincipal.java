import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TelaMenuPrincipal extends JFrame {

    public TelaMenuPrincipal() {
        /// Configurações da tela
        setTitle("Menu Principal");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); /// centraliza a janela

        /// Criando o painel
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 1, 10, 10));

        /// Criando os botões para as ações de sacar, depositar, transferir e sair
        JButton btnSacar = new JButton("Sacar");
        JButton btnDepositar = new JButton("Depositar");
        JButton btnTransferir = new JButton("Transferir");
        JButton btnSair = new JButton("Sair");

        /// Adicionando os botões ao painel
        panel.add(btnSacar);
        panel.add(btnDepositar);
        panel.add(btnTransferir);
        panel.add(btnSair);

        /// Ação para o botão de sacar
        btnSacar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String valorStr = JOptionPane.showInputDialog("Digite o valor do saque:");

                /// Verifica se o valor informado é nulo
                if (valorStr != null && !valorStr.trim().isEmpty()) {

                    try {
                        double valorSaque = Double.parseDouble(valorStr);

                        if (valorSaque > 0) {
                            int idCliente = SessaoUsuario.getIdCliente(); /// Pega o ID do cliente logado

                            try {
                                OperacaoBancariaService.sacar(idCliente, valorSaque);
                                JOptionPane.showMessageDialog(null, "Saque realizado com sucesso!");
                            } catch (Exception ex) {
                                JOptionPane.showMessageDialog(null, "Erro: " + ex.getMessage());
                            }
                        } else {
                            JOptionPane.showMessageDialog(null, "O valor do saque deve ser maior que zero.");
                        }
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(null, "Por favor, digite um valor numérico válido.");
                    }
                }
            }
        });

        /// Ação para o botão de depositar
        btnDepositar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String valorStr = JOptionPane.showInputDialog("Digite o valor de depósito:");

                if (valorStr != null && !valorStr.trim().isEmpty()) {
                    try {
                        double valorDeposito = Double.parseDouble(valorStr);

                        if (valorDeposito > 0) {
                            int idCliente = SessaoUsuario.getIdCliente(); /// Pega o ID do cliente logado

                            try {
                                OperacaoBancariaService.depositar(idCliente, valorDeposito);
                                JOptionPane.showMessageDialog(null, "Depósito realizado com sucesso!");
                            } catch (Exception ex) {
                                JOptionPane.showMessageDialog(null, "Erro: " + ex.getMessage());
                            }
                        } else {
                            JOptionPane.showMessageDialog(null, "O valor do depósito deve ser maior que zero.");
                        }
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(null, "Por favor, digite um valor numérico válido.");
                    }
                }
            }
        });

        /// Ação para o botão de transferir
        btnTransferir.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String valorStr = JOptionPane.showInputDialog("Digite o valor da transferência:");

                if (valorStr != null && !valorStr.trim().isEmpty()) {
                    try {
                        double valorTransferencia = Double.parseDouble(valorStr);

                        if (valorTransferencia > 0) {
                            String emailDestinatario = JOptionPane.showInputDialog("Digite o e-mail do destinatário:");

                            if (emailDestinatario != null && !emailDestinatario.trim().isEmpty()) {
                                int idCliente = SessaoUsuario.getIdCliente(); /// Pega o ID do cliente logado

                                try {
                                    OperacaoBancariaService.transferir(idCliente, valorTransferencia, emailDestinatario);
                                    JOptionPane.showMessageDialog(null, "Transferência realizada com sucesso!");
                                } catch (Exception ex) {
                                    JOptionPane.showMessageDialog(null, "Erro: " + ex.getMessage());
                                }
                            } else {
                                JOptionPane.showMessageDialog(null, "O e-mail do destinatário não pode estar vazio.");
                            }
                        } else {
                            JOptionPane.showMessageDialog(null, "O valor da transferência deve ser maior que zero.");
                        }
                    } catch (NumberFormatException ex) {
                        JOptionPane.showMessageDialog(null, "Por favor, digite um valor numérico válido.");
                    }
                }
            }
        });

        /// Ação para o botão de sair
        btnSair.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        add(panel); /// Adicionando o painel à janela
        setVisible(true); /// Tornando a janela visível
    }
}