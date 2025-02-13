import java.util.ArrayList;


public class Sistema {

    ///  array de veiculo
    ArrayList <Veiculo> lista = new ArrayList<>();

    ///  metodo para adicionar um veiculo
    public void adicionarVeiculo(Veiculo veiculo){

        lista.add(veiculo);
    }

    /// metodo para remover um veiculo
    public void removerVeiculo(int id){

        Veiculo veiculoRemover = null;

        /// compara o objeto veiculo com o objeto dentro da lista
        /// faz a verificação pelo id
        /// atribui ao objeto sem referencia veiculoRemover o valor do objeto veiculo
        for(Veiculo veiculo : lista){
            if(veiculo.getId() == id){
                veiculoRemover = veiculo;
                break;
            }
        }

        /// se nao for nulo significa que os dados foram movidos
        if (veiculoRemover != null){

            /// removendo os dados movidos da lista
            lista.remove(veiculoRemover);
            System.out.println("Veículo rmeovido com sucesso");
        }
        else {
            System.out.println("Veículo com o Id" + id + "Não encontrado");
        }

    }

    ///  faz uma comparação do elemento veiculo com os veiculos armazenados na lista
    public void listarVeiculos(){

        for (Veiculo veiculo : lista) {
        veiculo.exibirDetalhes();
        }
    }
}
