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

void (){




    
}

int main (){ //// função principal main


int opcao0,opcao1; ////varivael para acessar telas do switch
int opcaoMovimentacao; //// variavel para acessar telas do switch


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

break;


case 2:


printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.1.2\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tALTERACAO DE PRODUTO\n");
printf("\n");



break;

case 3:

printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.1.3\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tCONSULTA DE PRODUTO\n");
printf("\n");


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