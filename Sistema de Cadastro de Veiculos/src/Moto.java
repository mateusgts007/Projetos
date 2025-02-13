public class Moto extends Veiculo{

    ///  atirbuto especifico da classe moto
    private int cilindradas;

    ///  construtor
    public Moto (int cilindradas, String modelo, String marca, int ano, int id){
        super(modelo,marca,ano, id);
        this.cilindradas = cilindradas;
    }

    ///  metodos get e set
    public int getCilindradas() {
        return cilindradas;
    }

    public void setCilindradas(int cilindradas) {
        this.cilindradas = cilindradas;
    }

    ///  sobreescrita do metodo da classe mãe
    @Override
    public void exibirDetalhes() {
        System.out.println("Id: " + super.id);
        System.out.println("Modelo: " + super.modelo);
        System.out.println("Marca: " + super.marca);
        System.out.println("Ano: " + super.ano);
        System.out.println("Cilindradas: " + this.cilindradas);
    }
}
