public class Carro extends Veiculo{

    ///  atributos especificos da classe carro
    private int quantidadeDePortas;
    private double peso;

    /// construtor da classe carro
    public Carro (int quantidadeDePortas, double peso, String modelo, String marca, int ano, int id){
        super(modelo, marca, ano, id);
        this.quantidadeDePortas = quantidadeDePortas;
        this.peso = peso;

    }

    /// metodos get e set dos atributos especificos
    public double getPeso() {
        return peso;
    }

    public int getQuantidadeDePortas() {
        return quantidadeDePortas;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public void setQuantidadeDePortas(int quantidadeDePortas) {
        this.quantidadeDePortas = quantidadeDePortas;
    }

    ///reescrita do metodo da classe mãe (Veiculo)
    @Override
    public void exibirDetalhes() {
        System.out.println("Id: " + super.id);
        System.out.println("Modelo: " + super.modelo);
        System.out.println("Marca: " + super.marca);
        System.out.println("Ano: " + super.ano);
        System.out.println("Quantidade de portas: " + this.quantidadeDePortas);
        System.out.println("Peso: " + this.peso);


    }


}
