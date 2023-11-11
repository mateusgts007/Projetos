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
    int novaExclusao; ///// usado no menu de exclusão /////////////

    int confirmarEntrada; /// usado no menu de entrada de produto *****
    int quantidadeEntrada; /// usado no menu de entrada de produto ****
    int quantidadeAtual; //// usado no menu de entrada de produto ////
    int quantidadeFinal; ///// usado no menu de entrada de produto *****
    int novaEntrada; /// usado no menu de entrada de produto ******

    int confirmarSaida; //// usado no menu de saida de produto ******
    int novaSaida; ///// usado no menu de saida de produto

    float percentualReajuste; /// usado no menu de reajuste de preços
    int confirmarReajuste; //// usado no menu de reajuste de preços
    int novoReajuste; /// usado no menu de reajuste de preços
    FILE *arquivo; ///// usado no reajuste

} estoque;



void inclusaoProduto(estoque *produto){ /////////////////////////////////////// inicio da função de incluir produtos

int novaInclusao;  ////// variavel para o loop de inclusao

    FILE *arquivo = fopen("estoque.txt", "a"); /////////////////// abrindo o arquivo para modo de escrita

    if(arquivo == NULL){

        printf("Erro ao abrir o arquivo para escrita.\n");

        return;
    }

do{

   printf("Nome do Produto: ");//////////////////////////////////////// solicitando nome do produto

   fflush(stdin);////////////////////////////////////////////////////// limpa o buffer de entrada
   fgets(produto->nomeProduto, sizeof(produto->nomeProduto), stdin); /////// fgets caso o nome do produto tenha espaços
    produto->nomeProduto[strcspn(produto->nomeProduto, "\n")] = '\0'; // Remove a quebra de linha se presente

   printf("Preco: ");//////////////////////////////////////////////////// solicitando preço do produto
   scanf("%f", &produto->preco); 

   if(produto->preco <=0){ ///////////////////////////////////// se o preço for menor ou igual a 0 ele exibe uma mensagem de erro

    printf("Erro: O preco deve ser maior que zero.\n");

    fclose(arquivo);  ///////  fecha o arquivo se o preço for menor ou igual a 0

    break;

   }

   printf("Unidade: ");///////////////////////////////// solicitando  a unidade do produto, ex: kg.

   fflush(stdin); /////////////////////////////////////// limpa oo buffer de entrada

    fgets(produto->unidade, sizeof(produto->unidade), stdin); /// fgets caso a descrição da unidade tiver espaços 

    produto->unidade[strcspn(produto->unidade, "\n")] = '\0'; /// elimina a quebra de linha se tiver


    printf("Quantidade em Estoque: "); //////////////////////// solicitando a quantidade em estoque do produto
    scanf("%d", &produto->quantidade_estoque);  

    if(produto->quantidade_estoque < 0){ ////////////////// se a quantidade do estoque for menor que 0 ele exibe uma mensagem de erro

        printf("Erro: A quantidade no estoque deve ser igual ou superior a 0.\n");

        fclose(arquivo); /////// fecha o arquivo se a quantidade for menor do que 0

        break;
    }

    printf("Confirmar Inclusao (1-Sim/0-Nao)"); /////////////// solicitando a confirmação da inclusao 
    scanf("%d", &produto->confirmarInclusao);   

    if(produto->confirmarInclusao == 1){  ////////// se a inclusao for confirmada ele grava os dados no arquivo estoque.txt

    fprintf(arquivo, "%s;%.2f;%s;%d\n", produto->nomeProduto, produto->preco, produto->unidade, produto->quantidade_estoque); /// gravando dados no arquivo

    } else {

        printf("inclusao cancelada\n");//////////////// se a opção escolhida for 0, ele cancela a inclusao
    }

    printf("Nova Inclusao (1-Sim/0-Nao)"); /////////// solicitando a nova inclusao
    scanf("%d", &novaInclusao);

    

} while(novaInclusao == 1); ////////////// loop infinito de nova inclusao, parando apenas quando o usuário nao quiser incluir mais nenhum produto


fclose(arquivo); ////// fechando o arquivo


} //*************// fim da função de incluir dados //****************//



int alteracaoProduto(estoque *produto) { //////////////////////////////////// inicio da função alteração produtos //////////////////////

    FILE *arquivo = fopen("estoque.txt", "r+"); /////////// abre o arquivo para escrita e leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para alteracao\n");
        return 0;
    }

    char linha[1000];   ///// array que serve para armazenar cada linha do arquivo estoque.txt
    int produtoEncontrado = 0; //// variavel que informa se o produto foi encontrado

    while (fgets(linha, sizeof(linha), arquivo)) {  ////// lê linha a linha do arquivo e armazena na linha
        char produtoAtual[50];
        float precoAtual;
        char unidadeAtual[10];
        int quantidadeAtual;

        if (sscanf(linha, "%49[^;];%f;%9[^;];%d", produtoAtual, &precoAtual, unidadeAtual, &quantidadeAtual) != 4) {
            continue;
        }

        if (strcmp(produtoAtual, produto->nomeProduto) == 0) { ///// compara o nome informado com o nome armazenado do produto
            produtoEncontrado = 1;

            fseek(arquivo, -strlen(linha), SEEK_CUR); ///// move o ponteiro para o inicio do arqui

            ////// sobrescreve os dados do arquivo
            fprintf(arquivo, "%s;%.2f;%s;%d\n", produto->nomeProduto, produto->preco, produto->unidade, produto->quantidade_estoque);

            break; 
        }
    }

    fclose(arquivo); ///////////////////////////// fechando o arquivo

    if (produtoEncontrado == 0) {

        printf("Produto alterado com sucesso.\n");

    } else {
        printf("Produto nao encontrado.\n");
    }

    return produtoEncontrado; 

}// ********* fim da função alteração produtos // ******* //


int consultaProdutoPorNome(const char *nome, estoque *produtoEncontrado){ //// inicio da função para consultar produtos

    FILE *arquivo = fopen("estoque.txt", "r");  ///// abre o arquivo em modo leitura

    if(arquivo == NULL){  /////// verifica se o arquivo foi aberto

        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    int encontrado = 0; //// variavel para contar se o item foi encontrado

    char linha[1000]; ////// array para armazenar cada linha do arquivo
    char nomeProduto[50];
    float preco;
    char unidade[10];
    int quantidade_estoque;
   

    while (fgets(linha, sizeof(linha), arquivo)) {   ///// lê cada linha do arquivo

        sscanf(linha, "%[^;];%f;%[^;];%d", nomeProduto, &preco, unidade, &quantidade_estoque);

        if (strcasecmp(nomeProduto, nome) == 0) { //// comparando o nome informado e o nome do produto no estoque
            encontrado = 1;

            strcpy(produtoEncontrado->nomeProduto, nomeProduto);
            produtoEncontrado->preco = preco;
            strcpy(produtoEncontrado->unidade, unidade);
            produtoEncontrado->quantidade_estoque = quantidade_estoque;


            break;

        }  /////// fim da comparação dos nomes

    }   ///////////////////// fim do while para ler o arquivo

      

    if(encontrado = 1) { ///// se a variavel encontrado passar a ser 1, exibe os dados do produto  (ERRO DE LOGICA!!!!!!!!!!!!!!!!!!1)

        printf("Produto encontrado!!!\n");
        printf("Nome: %s\n", produtoEncontrado->nomeProduto);
        printf("Preco: %.2f\n", produtoEncontrado->preco);
        printf("Unidade: %s\n", produtoEncontrado->unidade);
        printf("Quantidade em Estoque: %d\n", produtoEncontrado->quantidade_estoque);

    } else {

        printf("Produto nao encontrado.\n");
    }

    fclose(arquivo); //////////// fecha o arquivo

    return encontrado; 


} //// fim da função para consultar produtos


void excluirProduto(int *totalProdutos, estoque *produto) {/////////////////////// inicio da funcao de excluir produtos

    FILE *arquivo = fopen("estoque.txt", "r");
    FILE *tempArquivo = fopen("temp.txt", "w");

    if (arquivo == NULL || tempArquivo == NULL) {
        printf("Erro ao abrir os arquivos para exclusao\n");
        return;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    char nomeProdutoAExcluir[50];
    printf("Digite o nome do produto a ser excluido: ");
    fgets(nomeProdutoAExcluir, sizeof(nomeProdutoAExcluir), stdin);
    nomeProdutoAExcluir[strcspn(nomeProdutoAExcluir, "\n")] = '\0';

    int produtoExcluido = 0;
    int confirmarExclusao = 0;  // Variável para confirmar a exclusão do produto

    while (fscanf(arquivo, "%[^;];%f;%[^;];%d", produto->nomeProduto, &produto->preco, produto->unidade, &produto->quantidade_estoque) == 4) {
        if (strcmp(produto->nomeProduto, nomeProdutoAExcluir) == 0) {

            printf("Produto a ser excluido:\n");
            printf("Nome: %s\n", produto->nomeProduto);
            printf("Preco: %.2f\n", produto->preco);
            printf("Unidade: %s\n", produto->unidade);
            printf("Quantidade em Estoque: %d\n", produto->quantidade_estoque);

            printf("Confirmar Exclusao (1-Sim/0-Nao): ");
            scanf("%d", &confirmarExclusao);

            if (confirmarExclusao == 1) {
                (*totalProdutos)--;
                produtoExcluido = 1;
            } else {
                printf("Exclusao cancelada.\n");
            }
        } else {
            // Escrever no arquivo temporário
            fprintf(tempArquivo, "%s;%.2f;%s;%d\n", produto->nomeProduto, produto->preco, produto->unidade, produto->quantidade_estoque);
        }
    }

    fclose(arquivo);
    fclose(tempArquivo);

    if (produtoExcluido) {
        remove("estoque.txt");
        rename("temp.txt", "estoque.txt");
        printf("Produto excluido com sucesso.\n");
    } else {
        remove("temp.txt");
        printf("Produto nao encontrado ou exclusao cancelada.\n");
    }
    
} ////////////////////////// fim da função de excluir produtos



////////////////// Inicio Função movimentação entrada de produto
void entradaProduto(estoque *produto) {
    FILE *arquivo = fopen("estoque.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para entrada de produtos\n");
        return;
    }

    int continuarEntrada = 1;

    while (continuarEntrada) {
        rewind(arquivo);

        int produtoEncontrado = 0;
        char nomeProdutoLido[50];
        int quantidadeAdicionadaLida;

        printf("Nome do Produto: ");
        fflush(stdin);
        fgets(nomeProdutoLido, sizeof(nomeProdutoLido), stdin);
        nomeProdutoLido[strcspn(nomeProdutoLido, "\n")] = '\0'; // Remover a quebra de linha

        while (fscanf(arquivo, "%[^;];%f;%[^;];%d\n", produto->nomeProduto, &produto->preco, produto->unidade, &produto->quantidade_estoque) == 4) {
            if (strcmp(produto->nomeProduto, nomeProdutoLido) == 0) {
                produtoEncontrado++;

                // Exibir dados do produto
                printf("Produto encontrado!\n");
                printf("Nome: %s\n", produto->nomeProduto);
                printf("Quantidade Atual: %d\n", produto->quantidade_estoque);

                // Ler quantidade de entrada até que seja válida
                do {
                    printf("Quantidade de entrada: ");
                    if (scanf("%d", &quantidadeAdicionadaLida) != 1 || quantidadeAdicionadaLida <= 0) {
                        // Limpar o buffer do teclado em caso de entrada inválida
                        while (getchar() != '\n');
                        printf("Erro: A quantidade de entrada deve ser um número inteiro maior que zero.\n");
                    } else {
                        break; // Saia do loop se a entrada for válida
                    }
                } while (1);

                produto->quantidade_estoque += quantidadeAdicionadaLida; // adicionar quantidade

                printf("\nInformacoes apos a entrada:\n");
                printf("Quantidade Final: %d\n", produto->quantidade_estoque);

                // Confirmar entrada
                printf("Confirmar Entrada (1-Sim/0-Nao): ");
                scanf("%d", &produto->confirmarEntrada);

                if (produto->confirmarEntrada == 1) {
                    // Atualizar o arquivo com os novos dados
                    fseek(arquivo, -strlen(produto->nomeProduto) - 4 * sizeof(int), SEEK_CUR);
                    fprintf(arquivo, "%s;%.2f;%s;%d\n", produto->nomeProduto, produto->preco, produto->unidade, produto->quantidade_estoque);

                    // Solicitar nova entrada
                    printf("Deseja fazer outra entrada? (1-Sim/0-Nao): ");
                    scanf("%d", &continuarEntrada);

                    if (continuarEntrada == 0) {
                        break; // Saia do loop externo se não quiser fazer outra entrada
                    }
                } else {
                    printf("Operacao cancelada.\n");
                    break; // Saia do loop interno se a entrada não for confirmada
                }
            }
        }

        if (!produtoEncontrado) {
            printf("Produto nao encontrado.\n");

            // Pergunta se deve continuar
            printf("Deseja continuar a entrada de produto? (1-Sim/0-Nao): ");
            scanf("%d", &continuarEntrada);

            if (continuarEntrada == 0) {
                break; // Saia do loop externo se não quiser fazer outra entrada
            }
        }
    }

    fclose(arquivo);
}

///////////////Fim Função movimentação entrada de produto




/////////////////Função movimentação saida de produto

void saidaProduto(estoque *produto) {
    FILE *arquivo = fopen("estoque.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para saida de produtos\n");
        return;
    }

    int continuarSaida = 1;

    while (continuarSaida) {
        rewind(arquivo);

        int produtoEncontradoSaida = 0;
        char nomeProdutoSaida[50];
        int quantidadeSaidaLida;

        printf("Nome do Produto: ");
        fflush(stdin);
        fgets(nomeProdutoSaida, sizeof(nomeProdutoSaida), stdin);
        nomeProdutoSaida[strcspn(nomeProdutoSaida, "\n")] = '\0'; // Remover a quebra de linha

        while (fscanf(arquivo, "%[^;];%f;%[^;];%d\n", produto->nomeProduto, &produto->preco, produto->unidade, &produto->quantidade_estoque) == 4) {
            if (strcmp(produto->nomeProduto, nomeProdutoSaida) == 0) {
                produtoEncontradoSaida++;

                // Exibir dados do produto
                printf("Produto encontrado!\n");
                printf("Nome: %s\n", produto->nomeProduto);
                printf("Quantidade Atual: %d\n", produto->quantidade_estoque);

                // Ler quantidade de saída até que seja válida
                do {
                    printf("Quantidade de saida: ");
                    if (scanf("%d", &quantidadeSaidaLida) != 1 || quantidadeSaidaLida <= 0 || quantidadeSaidaLida > produto->quantidade_estoque) {
                        // Limpar o buffer do teclado em caso de entrada inválida
                        while (getchar() != '\n');
                        printf("Erro: Quantidade de saida invalida.\n");
                    } else {
                        break; // Saia do loop se a entrada for válida
                    }
                } while (1);

                produto->quantidade_estoque -= quantidadeSaidaLida; // subtrair quantidade

                printf("\nInformacoes apos a saida:\n");
                printf("Quantidade Final: %d\n", produto->quantidade_estoque);

                // Confirmar saída
                printf("Confirmar Saida (1-Sim/0-Nao): ");
                scanf("%d", &produto->confirmarSaida);

                if (produto->confirmarSaida == 1) {
                    // Atualizar o arquivo com os novos dados
                    fseek(arquivo, -strlen(produto->nomeProduto) - 4 * sizeof(int), SEEK_CUR);
                    fprintf(arquivo, "%s;%.2f;%s;%d\n", produto->nomeProduto, produto->preco, produto->unidade, produto->quantidade_estoque);

                    // Solicitar nova saída
                    printf("Deseja fazer outra saida? (1-Sim/0-Nao): ");
                    scanf("%d", &continuarSaida);

                    if (continuarSaida == 0) {
                        break; // Saia do loop externo se não quiser fazer outra saída
                    }
                } else {
                    printf("Operacao cancelada.\n");
                    break; // Saia do loop interno se a saída não for confirmada
                }
            }
        }

        if (!produtoEncontradoSaida) {
            printf("Produto nao encontrado.\n");

            // Pergunta se deve continuar
            printf("Deseja continuar a saida de produto? (1-Sim/0-Nao): ");
            scanf("%d", &continuarSaida);

            if (continuarSaida == 0) {
                break; // Saia do loop externo se não quiser fazer outra saída
            }
        }
    }

    fclose(arquivo);
}



//////////////////Fim da função saída movimentação de produtos



///////// INICIO DA FUNÇÃO DE REAJUSTE DE PREÇOS

void reajustePrecos(FILE *arquivo) {

    int opcaoReajuste;
    float percentualReajuste;

    printf("\nXYZ COMERCIO DE PRODUTOS LTDA.\n");
    printf("SISTEMA DE CONTROLE DE ESTOQUE\n\n");
    printf("REAJUSTE DE PRECOS\n\n");
    printf("Escolha a opcao de reajuste:\n");
    printf("1 - Reajustar um unico produto\n");
    printf("2 - Reajustar todos os produtos\n");
    printf("Opcao: ");
    scanf("%d", &opcaoReajuste);


    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para reajuste de preços\n");
        return;
    }

    if (opcaoReajuste == 1) {
        char nomeProduto[50];

        printf("Nome do Produto a ser reajustado: ");
        fflush(stdin);
        fgets(nomeProduto, sizeof(nomeProduto), stdin);
        nomeProduto[strcspn(nomeProduto, "\n")] = '\0'; // Remover a quebra de linha

        fseek(arquivo, 0, SEEK_SET);  // Retorna ao início do arquivo

        int produtoEncontrado = 0;

        while (1) {
            char nome[50];
            float preco;
            char unidade[10];
            int quantidadeEstoque;

            if (fscanf(arquivo, "%[^;];%f;%[^;];%d\n", nome, &preco, unidade, &quantidadeEstoque) != 4) {
                break;  // Sai do loop quando não há mais linhas no arquivo
            }

            if (strcmp(nome, nomeProduto) == 0) {
                produtoEncontrado = 1;

                printf("\nREAJUSTE INDIVIDUAL\n");
                printf("PRODUTO      : %s\n", nome);
                printf("UNIDADE      : %s\n", unidade);
                printf("PRECO ATUAL  : %.2f\n", preco);
                printf("\nPERCENTUAL DE REAJUSTE : ");
                scanf("%f", &percentualReajuste);
                preco += (preco * percentualReajuste / 100.0);

                    printf("\nREAJUSTE APLICADO\n");
                    printf("NOVO PRECO   : %.2f\n", preco);

                fseek(arquivo, -strlen(nome) - 4 * sizeof(int), SEEK_CUR);

                fprintf(arquivo, "%s;%.2f;%s;%d\n", nome, preco, unidade, quantidadeEstoque);
                break;  // Sai do loop após o reajuste
            }
        }

                
        if (!produtoEncontrado) {

            printf("Produto nao encontrado.\n");
            
        } else {

            printf("Reajuste aplicado com sucesso.\n");
           
        }

    } else if (opcaoReajuste == 2) {

        printf("\nREAJUSTE GERAL\n");
        printf("Percentual de Reajuste para todos os produtos: ");
        scanf("%f", &percentualReajuste);

        fseek(arquivo, 0, SEEK_SET);  // Retorna ao início do arquivo

        while (1) {
            char nome[50];
            float preco;
            char unidade[10];
            int quantidadeEstoque;

            if (fscanf(arquivo, "%[^;];%f;%[^;];%d\n", nome, &preco, unidade, &quantidadeEstoque) != 4) {
                break;  // Sai do loop quando não há mais linhas no arquivo
            }

            float novoPreco = preco + (preco * percentualReajuste / 100.0);

                    printf("\nREAJUSTE APLICADO\n");
                    printf("PRODUTO      : %s\n", nome);
                    printf("NOVO PRECO   : %.2f\n", novoPreco);

            fseek(arquivo, -strlen(nome) - 4 * sizeof(int), SEEK_CUR);

            fprintf(arquivo, "%s;%.2f;%s;%d\n", nome, preco, unidade, quantidadeEstoque);
        }

        printf("Reajuste aplicado a todos os produtos com sucesso.\n");

        } else {

        printf("Opcao invalida.\n");
    }

    fclose(arquivo);

}


//////////// FIM DA FUNÇÃO DE REAJUSTE



////////////////// INICIO DA FUNCAO GERAL LISTA DE PREÇOS

void gerarListaDePrecos(const char *nomeArquivo, const estoque *produto) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de estoque.\n");
        return;
    }

    printf("\n");
    printf("\nXYZ COMERCIO DE PRODUTOS LTDA.\n");
    printf("SISTEMA DE CONTROLE DE ESTOQUE\n\n");
    printf("LISTA DE PRECOS\t\t\tPG 009\n\n");
    printf("%-30s %-10s %-10s\n", "PRODUTO", "UND", "PRECO");

    while(fscanf(arquivo, "%[^;];%f;%[^;];%d\n", produto->nomeProduto, &produto->preco, produto->unidade, &produto->quantidade_estoque) == 4) {
        printf("%-30s %.2f %-10s\n", produto->nomeProduto, produto->preco, produto->unidade);
    }

    printf("\n");

    fclose(arquivo); /////////// fecha o arquivo
}


/////////////////////////// FIM DA FUNCAO GERAL LISTA DE PREÇOS


////////////////////// INICIO FUNCAO DE GERAR RELATORIO DE BALANCO 

void gerarRelatorioDeBalanco(const char *nomeArquivo, const estoque *produto) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de estoque.\n");
        return;
    }

    printf("\nXYZ COMERCIO DE PRODUTOS LTDA.\n");
    printf("SISTEMA DE CONTROLE DE ESTOQUE\n\n");
    printf("%-30s %-4s %-15s %-4s %-15s\n", "PRODUTO", "UND", "PRECO UNITARIO", "QTDE", "PRECO TOTAL");


    float valorTotal = 0.0;
    int totalItens = 0;

    while (fscanf(arquivo, "%[^;];%f;%[^;];%d\n", produto->nomeProduto, &produto->preco, produto->unidade, &produto->quantidade_estoque) == 4) {

        float totalItem = produto->preco * produto->quantidade_estoque;

        printf("%-30s %-4s %014.2f %-4d %014.2f\n", produto->nomeProduto, produto->unidade, produto->preco, produto->quantidade_estoque, totalItem);

        valorTotal += totalItem;
        totalItens += produto->quantidade_estoque;
    }

    printf("===============================================================\n");
    printf("TOTAL DE ITENS NO ESTOQUE : %04d\n", totalItens);
    printf("VALOR TOTAL DO ESTOQUE   : %014.2f\n", valorTotal);

    fclose(arquivo); ////////// fecha o arquivo
}

    
/////////////////// FIM DA FUNCAO DE GERAR RELATORIO DE BALANÇO 




int main (){ //// função principal main

int opcao0,opcao1; ////varivael para acessar telas do switch
int opcaoMovimentacao; //// variavel para acessar telas do switch
int opcaorelatorio;

int totalProdutos = 0;

char nomePesquisado[50]; //// usado para consultar

estoque produtoEncontrado;

 FILE *arquivo = fopen("estoque.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de estoque\n");
        return 1;
    }


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

inclusaoProduto(&novoProduto); /// chamando a função de incluir produtos



break;

case 2:

printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.1.2\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tALTERACAO DE PRODUTO\n");
printf("\n");


 estoque produtoParaAlterar; // Crie uma estrutura para armazenar os dados do produto a ser alterado

    printf("Nome do Produto a ser alterado: ");
    fflush(stdin);
    fgets(produtoParaAlterar.nomeProduto, sizeof(produtoParaAlterar.nomeProduto), stdin);

    printf("Novo Preco: ");
    scanf("%f", &produtoParaAlterar.preco);

    printf("Nova Quantidade: ");
    scanf("%d", &produtoParaAlterar.quantidade_estoque);

    printf("Nova Unidade: ");
    fflush(stdin);
    fgets(produtoParaAlterar.unidade, sizeof(produtoParaAlterar.unidade), stdin);

    printf("Confirmar Alteracao (1-Sim/0-Nao): ");
    int confirmarAlteracao;
    scanf("%d", &confirmarAlteracao);

    if (confirmarAlteracao == 1) {

        int resultado = alteracaoProduto(&produtoParaAlterar);

        if (resultado == 0) {
            
            printf("Produto alterado com sucesso.\n");
        } else {
            printf("Produto nao encontrado ou ocorreu um erro na alteracao.\n");
        }
    } else {
        printf("Alteracao cancelada.\n");
    }

    printf("Nova Alteracao (1-Sim/0-Nao): ");
    int novaAlteracao;
    scanf("%d", &novaAlteracao);


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

estoque produtoEncontrado;

int resultadoConsulta = consultaProdutoPorNome(nomePesquisado, &produtoEncontrado);

 if (resultadoConsulta) {

    printf("Nova Consulta (1-Sim/0-Nao): ");

    scanf("%d", &produtoEncontrado.novaConsulta);

    } else {
                                
        produtoEncontrado.novaConsulta = 0;
    }

} while (produtoEncontrado.novaConsulta == 1);

break;

case 4:


printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.1.4\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tEXCLUSAO\n");
printf("\n");

estoque produtoExcluir;

    excluirProduto(&totalProdutos, &produtoExcluir);

break;

}//// fim do switch 2

break ; // break para voltar para a tela 1.1 saindo de inclusao do produto para nao entrar no menu de movimentação

case 2: ///////////////// switch 1

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
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.2.1\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tMOVIMENTACAO - ENTRADA DE PRODUTO\n");
printf("\n");


estoque produto;

// Chamar a função entradaProduto
entradaProduto(&produto);


break;

case 2:


printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.2.2\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tMOVIMENTACAO - SAIDA DE PRODUTO\n");
printf("\n");

estoque produtoSaida;


saidaProduto(&produtoSaida);


break;

case 0: //////// para voltar ao menu principal

break;

default :

printf("opcao invalida. Tente novamente.\n");

break;

} //// //// /////// fim do switch de movimentacao


}while(opcaoMovimentacao != 0); ///////////fim do do-while de movimentação

break; ///// volta para 1.0


case 3: ////////// Reajute de preços


printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.3\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tREAJUSTE DE PRECOS\n");
printf("\n");
printf("REAJUSTE GERAL OU DE UM PRODUTO?\n");
printf("\n");


    reajustePrecos(arquivo);


break;

case 4: ////////// Relatorios


printf("\n");
printf("\t\tXYZ COMERCIO DE PRODUTOS LTDA. \t\t\t TELA 1.4\n");
printf("\t\tSISTEMA DE CONTROLE DE ESTOQUE\n");
printf("\n");
printf("\t\tRELATORIOS\n");
printf("\n");

printf("1 - LISTA DE PRECOS\n");
printf("2 - BALANCO FINANCEIRO\n");
printf("\t 0 - RETORNAR\n");
printf("\tOPCAO: ");
scanf("%d",&opcaorelatorio);

switch(opcaorelatorio){ ///////// inicio switch relatorios

case 1:

printf("XYZ COMERCIO DE PRODUTOS LTDA.");
printf("SISTEMA DE CONTROLE DE ESTOQUE");
printf("\n");
printf("\tLISTA DE PRECOS \t PG 009");

estoque gerarlista;

 gerarListaDePrecos("estoque.txt", &gerarlista);


break;


case 2:

printf("XYZ COMERCIO DE PRODUTOS LTDA.");
printf("SISTEMA DE CONTROLE DE ESTOQUE");
printf("\n");
printf("\tBALANCO FISICO - FINANCEIRO \t PG 009");

estoque relatoriodebalanco;

gerarRelatorioDeBalanco("estoque.txt", &relatoriodebalanco);


break;

} ////////fim do switch relatorios

case 0: ////////// finalizar o programa

break;

default:

printf("Opcao invalida. Tente Novamente.\n");

break;

} /// fim do switch 1


} while (opcao0 != 0); //// fim do do while

printf("saindo do programa de estoque. \n");

    return 0;
    
}