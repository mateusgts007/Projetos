#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


typedef struct  {

    char nomeProduto[50];
    float preco;
    char unidade[10];
    int quantidade_estoque;
    int confirmarInclusao; ///// usado no menu de inclusao
    int novaInclusao;  ///////// usado no menu de inclusao
    int confirmarAlteracao; /// usado no menu de alteração
    int novaAlteracao; //// usado no menu de alteração
    int novaConsulta; //// usado no menu de consulta
    int confirmarExclusao; //// usado no menu de exclusão
    int novaExclusao; ///// usado no menu de exclusão
    int confirmarEntrada; /// usado no menu de entrada de produto
    int novaEntrada; /// usado no menu de entrada de produto
    int confirmarSaida; //// usado no menu de saida de produto
    int novaSaida; ///// usado no menu de saida de produto
    float percentualReajuste; /// usado no menu de reajuste de preços
    int confirmarReajuste; //// usado no menu de reajuste de preços
    int novoReajuste; /// usado no menu de reajuste de preços

} estoque;


void inclusaoProduto(estoque produto){ //// inicio da função de incluir produtos


    FILE *arquivo = fopen("estoque.txt","a");
    if(arquivo == NULL){

        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

do{


   printf("Nome do Produto: ");
   fflush(stdin);
   fgets(produto.nomeProduto, sizeof(produto.nomeProduto),stdin);

   printf("Preco: ");
   scanf("%f",&produto.preco);

   if(produto.preco <= 0){

    printf("O preco do produto deve ser superior a 0\n");

    fclose(arquivo);
    
    return;

   } else{ //// comeco do else


   printf("Unidade: ");
   fflush(stdin);
   fgets(produto.unidade, sizeof(produto.unidade),stdin);

    printf("Quantidade em Estoque: ");
    scanf("%d",&produto.quantidade_estoque);

    printf("Confirmar Inclusao (1-Sim/0-Nao)");
    scanf("%d",&produto.confirmarInclusao);

   } /// fim do else 

    if(produto.confirmarInclusao == 1){

    fwrite(&produto, sizeof(estoque), 1, arquivo);

    } else {

        printf("inclusao cancelada\n");
    }

    printf("Nova Inclusao (1-Sim/0-Nao)");
    scanf("%d",&produto.novaInclusao);



} while(produto.novaInclusao == 1);


fclose(arquivo); ////// fechando o arquivo


} //*************// fim da função de incluir dados //****************//



int alteracaoProduto(const char *nomeProduto, float novoPreco, int novaQuantidade, const char novaUnidade){ // inicio da função alteração produtos //

    FILE *arquivo = fopen("estoque.txt", "r+"); ///// r+ para ler e escrever no arquivo

    if(arquivo == NULL){

        printf("Erro ao abrir o arquivo para alteracao\n");

        return 0;
    }

    char linha [1000];
    char tempFile[] = "temp.txt"; //// arquivo temporario para alterar os produtos

    FILE *temp = fopen(tempFile, "w");

    if(temp == NULL){

        printf("Erro ao criar arquivo temporario\n");

        return 0;
    }

    int produtoEncontrado = 0;

    while (fgets(linha, sizeof(linha), arquivo)){

        char produtoAtual[50];
        float precoAtual;
        char unidadeAtual[10];
        int quantidadeAtual;
        int confirmarInclusao;
        int novaInclusao;

        if(sscanf(linha, "%49s %f %9s %d %d %d",produtoAtual, &precoAtual, unidadeAtual, &quantidadeAtual, &confirmarInclusao, &novaInclusao) != 6){

        fprintf(temp, "%s",linha);
        continue; 
        }

        if(strcmp(produtoAtual, nomeProduto) == 0){ /// comparou os nomes 

            produtoEncontrado = 1;
            precoAtual = novoPreco;
            quantidadeAtual = novaQuantidade;
            strcpy(unidadeAtual, novaUnidade);

        }

        fprintf(temp, "%s;%.2f;%s;%d;%d;%d\n",produtoAtual, precoAtual, unidadeAtual, quantidadeAtual, confirmarInclusao, novaInclusao);

    } //// fim do while

        fclose(arquivo);
        fclose(temp);
        remove("estoque.txt");
        rename(tempFile, "estoque.txt");

    if (!produtoEncontrado) {

        printf("Produto não encontrado.\n");

        return 0; // Retorna 0 para erro
    } else {

        printf("Produto alterado com sucesso.\n");

        return 1; // Retorne 1 para sucesso
    }


} // ********* fim da função alteração produtos // ******* //



int consultaProdutoPorNome(const char *nome, estoque *produtoEncontrado){ //// inicio da função para consultar produtos

    FILE *arquivo = fopen("estoque.txt", "r");

    if(arquivo == NULL){

        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    int encontrado = 0; //// variavel para contar se o item foi encontrado


    while (fread(produtoEncontrado, sizeof(estoque), 1, arquivo) == 1){ //// inicio do while

    if(strcmp(produtoEncontrado->nomeProduto, nome) == 0){

        encontrado = 1;


        printf("Produto encontrado:\n");
        printf("Nome: %s\n",produtoEncontrado->nomeProduto);
        printf("preco: %.2f\n",produtoEncontrado->preco);
        printf("Unidade: %s\n",produtoEncontrado->unidade);
        printf("Quantidade em Estoque: %d\n",produtoEncontrado->quantidade_estoque);
        printf("Nova Consulta (1-Sim/0-Nao): ");
        scanf("%d",&produtoEncontrado->novaConsulta);

        
    }

} /// fim do while

fclose(arquivo); //// fechando o arquivo

if(!encontrado){

    printf("Produto nao encontrado\n");

    return 0; //// erro

} else {

    return 1; //// encontrado
}


} //// fim da função para consultar produtos




int main (){ //// função principal main


int opcao0,opcao1; ////varivael para acessar telas do switch
int opcaoMovimentacao; //// variavel para acessar telas do switch

char nomePesquisado[50]; //// consulta
estoque produtoEncontrado;



do{ //// inicio do do while


printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.0\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tMENU PRINCIPAL\n");
printf("\n");
printf("1 - CADASTRO DE PRODUTOS\n");
printf("2 - MOVIMENTACAO\n");
printf("3 - REAJUSTE DE PRECOS\n");
printf("4 - RELATORIOS\n");
printf("\t0 - FINALIZAR\n");
printf("\n");
printf("\tOpcao:");
scanf("%d",&opcao0);
 

switch(opcao0){ /// inicio do switch 1

case 1:


printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.1\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tCADASTRO DE PRODUTOS\n");
printf("\n");
printf("1 - INCLUSAO\n");
printf("2 - ALTERACAO\n");
printf("3 - CONSULTA\n");
printf("4 - EXCLUSAO\n");
printf("\t0 - RETORNAR\n");
printf("\n");
printf("\tOpcao:");
scanf("%d",&opcao1);




switch(opcao1){ //////// inicio do switch 2

case 1:

printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.1.1\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tINCLUSAO DE PRODUTO\n");
printf("\n");

estoque novoProduto; /// criando uma nova variavel do tipo estoque para armazenar os novos produtos

inclusaoProduto(novoProduto); /// chamando a função de incluir produtos


break;


case 2:


printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.1.2\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tALTERACAO DE PRODUTO\n");
printf("\n");

char nomeProduto[50];
float novoPreco;
int novaQuantidade;
char novaUnidade[10];


    int resultado = alteracaoProduto(nomeProduto, novoPreco, novaQuantidade, novaUnidade);


    printf("Nome do Produto a ser alterado: ");
    fflush(stdin);
    fgets(nomeProduto, sizeof(nomeProduto), stdin);

    printf("Novo Preco: ");
    scanf("%f", &novoPreco);

    printf("Nova Quantidade: ");
    scanf("%d", &novaQuantidade);

    printf("Nova Unidade: ");
    fflush(stdin);
    fgets(novaUnidade, sizeof(novaUnidade), stdin);

    

    if (resultado == 1) {
        printf("Produto alterado com sucesso.\n");
    } else {
        printf("Produto nao encontrado ou ocorreu um erro na alteracao.\n");
    }



break;

case 3:

printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.1.3\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tCONSULTA DE PRODUTO\n");
printf("\n");

do{

printf("Nome do produto para para consulta no Estoque: ");
fflush(stdin);
fgets(nomePesquisado, sizeof(nomePesquisado), stdin);

if(consultaProdutoPorNome(nomePesquisado, &produtoEncontrado)){

    printf("Produto encontrado:\n");
    printf("Nome: %s\n",produtoEncontrado.nomeProduto);
    printf("preco: %.2f\n",produtoEncontrado.preco);
    printf("Unidade: %s\n",produtoEncontrado.unidade);
    printf("Quantidade em Estoque: %d\n",produtoEncontrado.quantidade_estoque);
    
    printf("Nova Consulta (1-Sim/0-Nao): ");
    scanf("%d",&produtoEncontrado.novaConsulta);
} else {

    printf("Produto nao encontrado\n");

    produtoEncontrado.novaConsulta = 0;
}

} while(produtoEncontrado.novaConsulta == 1);

break;

case 4:


printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.1.4\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tEXCLUSAO\n");
printf("\n");



break;

}//// fim do switch 2

break ; // break para voltar para a tela 1.1 saindo de inclusao do produto para nao entrar no menu de movimentação

case 2: //// switch 1

do {

printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.2\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tMOVIMENTACAO\n");
printf("\n");

printf("1 - ENTRADA\n");
printf("2 - SAIDA\n");
printf("\t 0 - RETORNAR\n");
printf("\tOPCAO:");
scanf("%d",&opcaoMovimentacao);

switch(opcaoMovimentacao){ //// inicio do switch de movimentacao

case 1:

printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA.\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tMOVIMENTACAO - ENTRADA DE PRODUTO\n");
printf("\n");


break;

case 2:

break;

case 0: /// para voltar ao menu principal

break;

default :

printf("opcao invalida. Tente novamente.\n");

break;

}   //// fim do switch de movimentacao

}while(opcaoMovimentacao != 0); /////fim do do-while de movimentação


case 3: //// Reajute de preços

case 4: /// Relatorios

case 0: /// finalizar o programa

break;

default:
printf("Opcao invalida. Tente Novamente.\n");
break;


} /// fim do switch 1


} while (opcao0 != 0); //// fim do do while

printf("saindo do programa de estoque. \n");



    return 0;
}