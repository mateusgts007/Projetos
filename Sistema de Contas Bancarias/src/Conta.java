public abstract class Conta {

    protected int idConta;
    protected int agencia;
    protected double saldo;

    /// construtor de conta
    public Conta(int idConta, int agencia, double saldo){
        this.idConta = idConta;
        this.agencia = agencia;
        this.saldo = saldo;
    }

    /// metodos da conta
    public abstract void sacar (double valor);

    public abstract void depositar(double valor);

    public abstract void transferir(Conta destino, double valor);


    /// metodos get dos atributos
    public int getIdConta() {
        return idConta;
    }

    public int getAgencia() {
        return agencia;
    }

    public double getSaldo() {
        return saldo;
    }

}
