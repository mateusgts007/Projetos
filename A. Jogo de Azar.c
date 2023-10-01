#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(){

int escolha_modo_de_jogo; /// case 1 e 2

int numeroAleatorio; /// case 1
int escolha_do_jogador; /// case 1

int indice_aleatorio; /// case 2
char nome_animal[20]; /// case 2

char *nomes_animais[] = {

        "gato", "cachorro", "elefante", "leão", "tigre", "macaco", "urso",
        "veado", "vaca", "pavao", "peru", "cobra", "coelho", "cavalo",
        "borboleta", "burro", "aguia", "avestruz", "camelo", "carneiro",
        "galo", "jacare", "cabra", "touro","porco"
    };



printf("\t\t !!!!!Bem vindo ao jogo!!!!! \n\t ");

printf(" Voce prefere tentar jogar no jogo simples ou no milhar ?\n");
printf(" (1) simples\n");
printf(" (2) milhar\n");

scanf("%d",&escolha_modo_de_jogo);


printf("!!!!faca sua aposta e boa sorte!!!!\n");



switch(escolha_modo_de_jogo){ /// escolha do tipo de jogo

case 1: ///// caso a opção escolhida seja o numero 1

printf("digite um numero aleatorio para a sua aposta:\n");
scanf("%d",&escolha_do_jogador);

 srand(time(NULL)); ///// inicializa o rand

numeroAleatorio = rand () % 99; /// criando numeros aleatorios 

printf ("o numero aleatorio foi : %d\n",numeroAleatorio); /// informando qual foi o numero aleatorio

if((numeroAleatorio >= 1) && (numeroAleatorio <= 4) && (escolha_do_jogador >= 1) && (escolha_do_jogador <= 4)){  //// acertou avestruz

    printf("o animal sorteado foi: avestruz e voce acertou\n");
}

else if (( numeroAleatorio >= 1) && (numeroAleatorio <= 4) && ((escolha_do_jogador < 1) || (escolha_do_jogador > 4))) {    //// errou avestruz
        printf("O animal sorteado foi: avestruz e voce errou\n");
    }

else if ((numeroAleatorio >= 5) && (numeroAleatorio <= 8) && (escolha_do_jogador >= 5) && (escolha_do_jogador <= 8)){  /// acertou aguia

    printf("o animal sorteado foi: aguia e voce acertou\n");
}

else if((numeroAleatorio >= 5) && (numeroAleatorio <= 8) && ((escolha_do_jogador < 5) || (escolha_do_jogador > 8))){   ///// errou aguia
    printf("o animal sorteado foi: aguia e voce errou\n");
}

else if ((numeroAleatorio >= 9) && (numeroAleatorio <= 12) && ((escolha_do_jogador >= 9) && (escolha_do_jogador <= 12))){ /// acertou burro

    printf("o animal sorteado foi: burro e voce acertou\n");
}

else if((numeroAleatorio >= 9) && (numeroAleatorio <= 12) && ((escolha_do_jogador < 9) || (escolha_do_jogador > 12))){   //// errou burro
    
    printf("o animal sorteado foi: burro e voce errou\n");
}

else if ((numeroAleatorio >= 13) && (numeroAleatorio <=16) && (escolha_do_jogador >= 13) && (escolha_do_jogador <= 16)){  //// acertou borboleta

    printf("o animal sorteado foi: borboleta e voce acertou\n");
}

else if((numeroAleatorio >= 13) && (numeroAleatorio <= 16) && ((escolha_do_jogador < 13) || (escolha_do_jogador > 16))){ /// errou borboleta

    printf("o animal sorteado foi: borboleta e voce errou\n");
}

else if ((numeroAleatorio >= 17) && (numeroAleatorio <=20) && (escolha_do_jogador >= 17) && (escolha_do_jogador <= 20)){ /// acertou cachorro

    printf("o animal sorteado foi: cachorro e voce acertou\n");
}

else if((numeroAleatorio >= 17) && (numeroAleatorio <= 20) && ((escolha_do_jogador < 17) || (escolha_do_jogador > 20))){  /// errou cachorro
    printf("o animal sorteado foi: cachorro e voce errou\n");
}

else if ((numeroAleatorio >= 21) && (numeroAleatorio <=24) && (escolha_do_jogador >= 21) && (escolha_do_jogador <= 24)){ /// acertou cabra

    printf("o animal sorteado foi: cabra e voce acertou\n");
}

else if((numeroAleatorio >= 21) && (numeroAleatorio <= 24) && ((escolha_do_jogador < 21) || (escolha_do_jogador > 24))){ /// errou cabra

    printf("o animal sorteado foi: cabra e voce errou\n");
}

else if ((numeroAleatorio >= 25) && (numeroAleatorio <=28) && (escolha_do_jogador >= 25) && (escolha_do_jogador <= 28)){ /// acertou carneiro

    printf("o animal sorteado foi: carneiro e voce acertou\n");
}
else if((numeroAleatorio >= 25) && (numeroAleatorio <= 28) && ((escolha_do_jogador < 25) || (escolha_do_jogador > 28))){   /// errou carneiro

    printf("o animal sorteado foi: carneiro e voce errou");
}

else if ((numeroAleatorio >= 29) && (numeroAleatorio <=32) && (escolha_do_jogador >= 29) && (escolha_do_jogador <= 32)){ /// acertou camelo

    printf("o animal sorteado foi: camelo e voce acertou\n");
}

else if((numeroAleatorio >= 29) && (numeroAleatorio <= 32) && ((escolha_do_jogador < 29) || (escolha_do_jogador > 32))){  /// errou camelo

    printf("o animal sorteado foi: camelo e voce errou\n");
}

else if ((numeroAleatorio >= 33) && (numeroAleatorio <=36) && (escolha_do_jogador >= 33) && (escolha_do_jogador <= 36)){ /// acertou cobra

    printf("o animal sorteado foi: cobra e voce acertou\n");
}

else if((numeroAleatorio >= 33) && (numeroAleatorio <= 36) && ((escolha_do_jogador < 33) || (escolha_do_jogador > 36))){ /// errou cobra

printf("o animal sorteado foi: cobra e voce errou");

}

else if ((numeroAleatorio >= 37) && (numeroAleatorio <=40) && (escolha_do_jogador >= 37) && (escolha_do_jogador <= 40)){ /// acertou coelho

    printf("o animal sorteado foi: coelho e voce acertou\n");
}

else if((numeroAleatorio >= 37) && (numeroAleatorio <= 40) && ((escolha_do_jogador < 37) || (escolha_do_jogador > 40))){ /// errou coelho
    
    printf("o animal sorteado foi: coelho e voce errou\n");
}

else if ((numeroAleatorio >= 41) && (numeroAleatorio <= 44) && (escolha_do_jogador >= 41) && (escolha_do_jogador <= 44)){ /// acertou coelho

    printf("o animal sorteado foi: cavalo e voce acertou\n");
}

else if((numeroAleatorio >= 41) && (numeroAleatorio <= 44) && ((escolha_do_jogador < 41) || (escolha_do_jogador > 44))){ /// errou coelho

    printf("o animal sorteado foi: cavalo e voce errou\n");
}

else if ((numeroAleatorio >= 45) && (numeroAleatorio <=48) && (escolha_do_jogador >= 45) && (escolha_do_jogador <= 48)){  /// acertou elefante

    printf("o animal sorteado foi: elefante e voce acertou\n");
}

else if((numeroAleatorio >= 45) && (numeroAleatorio <= 48) && ((escolha_do_jogador < 45) || (escolha_do_jogador > 48))){  /// errou elefante

printf("o animal sorteado foi: elefante e voce errou\n");

}

else if ((numeroAleatorio >= 49) && (numeroAleatorio <=52) && (escolha_do_jogador >= 49) && (escolha_do_jogador <= 52)){ /// acertou galo

    printf("o animal sorteado foi: galo e voce acertou\n");
}

else if((numeroAleatorio >= 49) && (numeroAleatorio <=52) && ((escolha_do_jogador < 49) || (escolha_do_jogador > 52))){   /// errou galo

    printf("o animal sorteado foi: galo e voce errou\n");
}

else if ((numeroAleatorio >= 53) && (numeroAleatorio <=56) && (escolha_do_jogador >= 53) && (escolha_do_jogador <= 56)){ /// acertou gato

    printf("o animal sorteado foi: gato e voce acertou\n");
}

else if((numeroAleatorio >= 53) && (numeroAleatorio <= 56) && ((escolha_do_jogador < 53) && (escolha_do_jogador > 56))){  /// errou gato

    printf("o animal sorteado foi: gato e voce errou\n");
}

else if ((numeroAleatorio >= 57) && (numeroAleatorio <=60) && (escolha_do_jogador >= 57) && (escolha_do_jogador <= 60)){ /// acertou jacare

    printf("o animal sorteado foi: jacare e voce acertou\n");
}

else if((numeroAleatorio >= 57) && (numeroAleatorio <= 60) && ((escolha_do_jogador < 57) || (escolha_do_jogador > 60))){ /// errou jacare
    printf("o animal sorteado foi: jacare e voce errou\n");
}

else if ((numeroAleatorio >= 61) && (numeroAleatorio <=64) && (escolha_do_jogador >= 61) && (escolha_do_jogador <= 64)){ /// acertou leao

    printf("o animal sorteado foi: leao e voce acertou\n");
}

else if((numeroAleatorio >= 61) && (numeroAleatorio <= 64) && ((escolha_do_jogador < 61) || (escolha_do_jogador > 64))){  /// errou leao

    printf("o animal sorteado foi: leao e voce errou\n");
}

else if ((numeroAleatorio >= 65) && (numeroAleatorio <=68) && (escolha_do_jogador >= 65) && (escolha_do_jogador <= 68)){ /// acertou macaco

    printf("o animal sorteado foi: macaco e voce acertou\n");
}

else if((numeroAleatorio >= 65) && (numeroAleatorio <= 68) && ((escolha_do_jogador < 65) || (escolha_do_jogador > 68))){ /// errou macaco

    printf("o animal sorteado foi: macaco e voce errou\n");
}

else if ((numeroAleatorio >= 69) && (numeroAleatorio <=72) && (escolha_do_jogador >= 69) && (escolha_do_jogador <= 72)){ /// acertou porco

    printf("o animal sorteado foi: porco e voce acertou\n");
}

else if ((numeroAleatorio >= 69) && (numeroAleatorio <= 72) && ((escolha_do_jogador < 69) || (escolha_do_jogador > 72))){ /// errou porco

    printf("o animal sorteado foi: porco e voce errou\n");
}

else if ((numeroAleatorio >= 73) && (numeroAleatorio <=76) && (escolha_do_jogador >= 73) && (escolha_do_jogador <= 76)){ /// acertou pavao

    printf("o animal sorteado foi: pavao e voce acertou\n");
}

else if ((numeroAleatorio >= 73) && (numeroAleatorio <= 76) && ((escolha_do_jogador < 73) || (escolha_do_jogador > 76))){ /// errou pavao

    printf("o animal sorteado foi: pavao e voce errou\n");
}

else if ((numeroAleatorio >= 77) && (numeroAleatorio <=80) && (escolha_do_jogador >= 77)  && (escolha_do_jogador <= 80)){ /// acertou peru

    printf("o animal sorteado foi: peru e voce acertou\n");
}

else if((numeroAleatorio >= 77) && (numeroAleatorio <= 80) && ((escolha_do_jogador < 77) || (escolha_do_jogador > 80))){ /// errou peru

    printf("o animal sorteado foi: peru e voce errou\n"); 
}

else if ((numeroAleatorio >= 81) && (numeroAleatorio <=84) && (escolha_do_jogador >= 81) && (escolha_do_jogador <= 84)){ /// acertou touro

    printf("o animal sorteado foi: touro e voce acertou\n");
}

else if((numeroAleatorio >= 81) && (numeroAleatorio <= 84) && ((escolha_do_jogador < 81) || (escolha_do_jogador > 84))){ /// errou touro

    printf("o animal sorteado foi: touro e voce errou\n");
}

else if ((numeroAleatorio >= 85) && (numeroAleatorio <=88) && (escolha_do_jogador >= 85) && (escolha_do_jogador <= 88)){ /// acertou tigre

    printf("o animal sorteado foi: tigre e voce acertou\n");
}

else if((numeroAleatorio >= 85) && (numeroAleatorio <= 88) && ((escolha_do_jogador < 85) || (escolha_do_jogador > 88))){ /// errou tigre

    printf("o animal sorteado foi: tigre e voce errou\n");
}

else if ((numeroAleatorio >= 89) && (numeroAleatorio <=92) && (escolha_do_jogador >= 89) && (escolha_do_jogador <= 92)){ /// acertou urso

    printf("o animal sorteado foi: urso e voce acertou\n");
}

else if((numeroAleatorio >= 89) && (numeroAleatorio <= 92) && ((escolha_do_jogador < 89) || (escolha_do_jogador > 92))){ /// errou urso

    printf("o animal sorteado foi: urso e voce errou\n");
}

else if ((numeroAleatorio >= 93) && (numeroAleatorio <=96) && (escolha_do_jogador >= 93) && (escolha_do_jogador <= 96)){ /// acertou veado

    printf("o animal sorteado foi: veado e voce acertou\n");
}

else if((numeroAleatorio >= 93) && (numeroAleatorio <= 96) && ((escolha_do_jogador < 93) || (escolha_do_jogador > 96))){ /// errou veado

    printf("o animal sorteado foi: veado e voce errou\n");
}

else if ((numeroAleatorio >= 97) && (numeroAleatorio <=99) || (numeroAleatorio == 0) && (escolha_do_jogador >= 97) && (escolha_do_jogador <= 99) || (escolha_do_jogador == 0)){

    printf("o animal sorteado foi: vaca e voce acertou\n"); /// acertou vaca
}

else if((numeroAleatorio >= 97) && (numeroAleatorio <= 99) || (numeroAleatorio == 0) && ((escolha_do_jogador != 0) && (escolha_do_jogador > 99))){ /// errou vaca

    printf("o animal sorteado foi: vaca e voce errou\n");
}

else if(escolha_do_jogador > 99 || escolha_do_jogador < 0) {

    printf (" opcao invalida\n");
}
    break;



    case 2:                     ///// caso a opção escolhida seja a numero 2 //////////////

printf("\n");
printf("escolha o nome de algum desses animais:\n");
printf("\n");

printf("gato,cachorro,coelho,elefante,leao\n");
printf("tigre,macaco,urso,veado,vaca\n");
printf("pavao,peru,cobra,cavalo,borboleta\n");
printf("burro,aguia,avestruz,camelo,carneiro\n");
printf("galo,jacare,cabra,touro,porco\n");

printf("!!!!!boa sorte!!!!!\n");

scanf("%s",&nome_animal);

    srand(time(NULL));

    indice_aleatorio = rand() % 25;

if (strcmp(nome_animal,nomes_animais[indice_aleatorio]) == 0){ //////compara o valor das variaveis char

    printf("o animal sorteado foi %s e voce acertou\n",nomes_animais[indice_aleatorio]);
}

else {

    printf("o animal sorteado foi %s e voce errou\n",nomes_animais[indice_aleatorio]);
}


} /// final do switch



    return 0;
}