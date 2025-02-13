import java.sql.SQLOutput;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);

        ///  preciso instanciar a classe sistema para utilizar o arraylist
        Sistema sistema = new Sistema();

        int opcao = 0;

        do{

        System.out.println("Bem vindo ao sistema de cadastramento .........");
        System.out.println("Você pode cadastrar carros, motos e caminhões");
        System.out.println("Qual veículo você quer cadastrar?");
        System.out.println("(1) Carro \n (2) Moto \n (3) Caminhão \n (4) Remover veículo \n (5) lista de veículos \n (6)sair");

         opcao = scanner.nextInt();

         scanner.nextLine(); /// limpa o buffer



        /// aqui são feitas as decisões dos veículos
        switch(opcao){

            case 1:

                ///  Pegando as informações de veiculo, pois vão aparecer em todas as subclasses
                System.out.println("Informe o modelo do veículo: ");
                String modelo = scanner.nextLine();


                System.out.println("Informe a marca do veículo: ");
                String marca = scanner.nextLine();


                System.out.println("Informe o ano do veículo: ");
                int ano = scanner.nextInt();


                System.out.println("Informe o id do veículo: ");
                int id = scanner.nextInt();

                /// essas informações / variáveis são exclusivas da classe carro
                System.out.println("Informe a quantidade de portas do carro: ");
                int quantidadeDePortas = scanner.nextInt();

                System.out.println("Informe o peso do veículo: ");
                double peso = scanner.nextDouble();


                /// criação do objeto carro
                Veiculo carro = new Carro(quantidadeDePortas, peso, modelo, marca, ano, id);

                ///  adicionando o carro à lista
                sistema.adicionarVeiculo(carro);

                break;

            case 2:

                ///  Pegando as informações de veiculo, pois vão aparecer em todas as subclasses
                System.out.println("Informe o modelo do veículo: ");
                 modelo = scanner.nextLine();


                System.out.println("Informe a marca do veículo: ");
                 marca = scanner.nextLine();


                System.out.println("Informe o ano do veículo: ");
                 ano = scanner.nextInt();


                System.out.println("Informe o id do veículo: ");
                 id = scanner.nextInt();

                System.out.println("Informe a quantidade de cilindradas da moto: ");
                int cilindradas = scanner.nextInt();

                /// criação do objeto moto
                Veiculo moto = new Moto(cilindradas, modelo, marca, ano, id);

                /// adicionando moto à lista
                sistema.adicionarVeiculo(moto);

                break;

            case 3:

                ///  Pegando as informações de veiculo, pois vão aparecer em todas as subclasses
                System.out.println("Informe o modelo do veículo: ");
                 modelo = scanner.nextLine();


                System.out.println("Informe a marca do veículo: ");
                 marca = scanner.nextLine();


                System.out.println("Informe o ano do veículo: ");
                 ano = scanner.nextInt();


                System.out.println("Informe o id do veículo: ");
                  id = scanner.nextInt();

                System.out.println("Informe a capacidade de carga do caminhão ");
                double capacidadeDeCarga = scanner.nextDouble();

                /// criando o objeto caminhao
                Veiculo caminhao = new Caminhão(capacidadeDeCarga, modelo, marca, ano, id);

                /// adicionando caminhao à lista
                sistema.adicionarVeiculo(caminhao);

                break;

            case 4:

                System.out.println("Informe o Id do veículo que você quer remover: ");
                int idRemover = scanner.nextInt();

                scanner.nextLine();

                sistema.removerVeiculo(idRemover);

                break;

            case 5:

                sistema.listarVeiculos();
                break;

            case 6:

                System.out.println("Saindo .........");
                break;

            default:
                System.out.println("Opção inválida.");

        }

    } while(opcao != 6);

    }
}