public class ContaCorrente extends Conta{

    /// limite especial da conta corrente
    public double limiteEspecial;

    /// consturtor da classe filha conta corrente
    public ContaCorrente(int idConta, int agencia, double saldo, double limiteEspecial){
        super(idConta, agencia, saldo);
        this.limiteEspecial = limiteEspecial;
    }

    ///  get do atributo limite especial
    public double getLimiteEspecial() {
        return limiteEspecial;
    }


    /// metodo para saque verificando se o valor em conta é suficiente para saque
    @Override
    public void sacar(double valor) {

        /// o saldo para saque nao pode ser maior que o saldo em conta
        if (valor > (this.saldo + limiteEspecial)) {
            System.out.println("Saldo insuficiente para saque");
        }
            else {
                saldo -= valor;
            System.out.println("Saque realizado");
        }

    }

    ///  metodo para deposito
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

    ///  metodo de transferencia de dinheiro entre contas
    @Override
    public void transferir(Conta destino, double valor) {

        if (valor > saldo + limiteEspecial) {
            System.out.println("Saldo insuficiente");
        }
            else {
                this.saldo -= valor;
                destino.depositar(valor);
            System.out.println("Tranferencia realizada com sucesso");
        }

    }
}
