import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class TelaConta extends JFrame {

    public TelaConta() {
        /// Configurações da tela
        setTitle("Criação de Conta");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); /// centraliza a janela

        /// painel e layout
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 2, 10, 10));

        /// componentes da tela
        JLabel lblTipoConta = new JLabel("Escolha o tipo de conta: ");
        String[] tiposConta = {"Corrente", "Poupança"};
        JComboBox<String> comboTipoConta = new JComboBox<>(tiposConta);

        JLabel lblAgencia = new JLabel("Número da Agência: ");
        JTextField txtAgencia = new JTextField();
        txtAgencia.setEditable(false); /// Não vai deixar editar o número da agência

        /// Gerar número aleatório de agência
        Random rand = new Random();
        int numeroAgencia = rand.nextInt(90000) + 10000; /// Gera um número aleatório de 5 dígitos
        txtAgencia.setText(String.valueOf(numeroAgencia)); /// Preenche o campo da agência com o número gerado

        JLabel lblSaldo = new JLabel("Saldo inicial:");
        JTextField txtSaldo = new JTextField();

        JButton btnCriarConta = new JButton("Criar Conta");
        JButton btnCancelar = new JButton("Cancelar");

        /// Adicionando componentes ao painel
        panel.add(lblTipoConta);
        panel.add(comboTipoConta);
        panel.add(lblAgencia);
        panel.add(txtAgencia);
        panel.add(lblSaldo);
        panel.add(txtSaldo);
        panel.add(btnCriarConta);
        panel.add(btnCancelar);

        add(panel); /// Adicionando o painel à janela

        /// Ação para o botão "Criar Conta"
        btnCriarConta.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String tipoConta = (String) comboTipoConta.getSelectedItem();
                String agencia = txtAgencia.getText();
                String saldoStr = txtSaldo.getText();

                /// Verifica se o campo está vazio
                if (agencia.isEmpty() || saldoStr.isEmpty()) {
                    JOptionPane.showMessageDialog(null, "Por favor, preencha todos os campos.");
                    return;
                }

                try {
                    double saldo = Double.parseDouble(saldoStr);

                    /// O valor informado não pode ser negativo
                    if (saldo < 0) {
                        JOptionPane.showMessageDialog(null, "O saldo não pode ser negativo.");
                        return;
                    }

                    /// Valida o valor de saldo informado
                    if (!saldoStr.matches("\\d+(\\.\\d{1,2})?")) {
                        JOptionPane.showMessageDialog(null, "Formato de saldo inválido.");
                        return;
                    }

                    int idCliente = SessaoUsuario.getIdCliente(); /// Pega o ID do cliente logado

                    /// Chama o metodo de criação de conta
                    ContaService.criarConta(idCliente, tipoConta, agencia, saldo);

                    JOptionPane.showMessageDialog(null, "Conta criada com sucesso!");

                    dispose(); /// Fecha a tela de criação de conta
                    new TelaMenuPrincipal(); /// Vai para a tela de menu principal

                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Por favor, insira um valor válido para o saldo.");
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, "Erro: " + ex.getMessage());
                }
            }
        });

        /// Ação para o botão "Cancelar"
        btnCancelar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dispose(); /// Fecha a tela de criação de conta
            }
        });

        setVisible(true); // Torna a janela visível
    }
}