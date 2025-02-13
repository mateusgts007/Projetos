public abstract class Veiculo {

    /// atributos da classe veiculo
    protected String modelo;
    protected String marca;
    protected int ano;
    public int id;

    ///  construtor
    public Veiculo(String modelo, String marca, int ano, int id){
        this.ano = ano;
        this.modelo = modelo;
        this.marca = marca;
        this.id = id;
    }

    public int getId() {
        return id;
    }

    ///  metodo abstrato para exibir detalhes
    public abstract void exibirDetalhes();

}
