public class Caminhão extends Veiculo {

    /// atributo especifico
    private double capaciddadeDeCarga;

    ///  construtor
    public Caminhão (double capaciddadeDeCarga, String modelo, String marca, int ano, int id){
        super(modelo,marca,ano, id);
        this.capaciddadeDeCarga = capaciddadeDeCarga;
    }

    /// metodos get e set
    public double getCapaciddadeDeCarga() {
        return capaciddadeDeCarga;
    }

    public void setCapaciddadeDeCarga(double capaciddadeDeCarga) {
        this.capaciddadeDeCarga = capaciddadeDeCarga;
    }

    @Override
    public void exibirDetalhes() {
        System.out.println("Id: " + super.id);
        System.out.println("Modelo: " + super.modelo);
        System.out.println("Marca: " + super.marca);
        System.out.println("Ano: " + super.ano);
        System.out.println("Capacidade de Carga: " + this.capaciddadeDeCarga);
    }
}
