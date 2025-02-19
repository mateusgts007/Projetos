public class ContaPoupanca extends Conta{

    private double rendimento;

    public ContaPoupanca(int idConta, int agencia, double saldo, double rendimento){
    super(idConta, agencia, saldo);
    this.rendimento = rendimento;
    }

    ///  retorna o valor do rendimento
    public double getRendimento() {
        return rendimento;
    }

    /// modifica o valor do rendimento
    public void setRendimento(double rendimento) {
        this.rendimento = rendimento;
    }

    /// metodo que representa o que o banco paga de juros pelo dinheiro em conta poupança do cliente
    public void aplicarRendimento(){

        this.saldo += this.saldo * (this.rendimento / 100);
        System.out.println("Rendimento aplicado, novo saldo: " + this.saldo);
    }

    ///  metodo para sacar o dinheiro da conta
    @Override
    public void sacar(double valor) {

        /// o saldo para saque nao pode ser maior que o saldo em conta
        if (valor > (this.saldo + rendimento)){
            System.out.println("Saldo insuficiente para saldo");
        }
            else {
                saldo -= valor;
        }
    }

    /// metodo para deposito
    @Override
    public void depositar(double valor) {

        /// o valor de deposito nao pode ser negativo
        if (valor > 0){
            saldo += valor;
            System.out.println("Deposito realizado");
        }
        else {
            System.out.println("Valor insuficiente para deposito");
        }

    }

    /* metodo para transferencia de saldo entre contas
     uso o objeto destino de conta e uso o metodo depositar
     transferencia é sacar de uma conta e depositar em outra
     */

    @Override
    public void transferir(Conta destino, double valor) {

        ///  o valor de transferencia nao pode ser maior que o valor em conta
        ///  nao posso ter 5 em conta e transferir 10
        if (valor > this.saldo + this.rendimento) {
            System.out.println("Saldo insuficiente");
        }
        else {

            this.saldo -= valor;
            destino.depositar(valor);
            System.out.println("Tranferencia realizada com sucesso");
        }

    }
}
