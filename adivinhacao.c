#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

enum Dificuldade { FACIL = 1, MEDIO = 2, DIFICIL = 3};

int main(){
        printf("         _-_        \n");
        printf("        |(_)|        \n");
        printf("         |||         \n");
        printf("         |||         \n");
        printf("         |||         \n");
        printf("         |||         \n");
        printf("         |||         \n");
        printf("    ^    |^|     ^   \n");
        printf("  < ^ >  <+>   < ^ > \n");
        printf("   | |   |||    | |  \n");
        printf("   \\ \\__/ | \\__/ /  \n ");
        printf("     \\,__.|.__,/     \n");
        printf("         (_)         \n\n");
        printf(" -- SEJAM BEM-VINDO AO JOGO DA ADIVINHAÇÃO MARUJOS!! --\n\n");
                      
    


    int segundos = time(0);
    srand(segundos);
    int numeroaleatorio= rand();


    int chute;
    int numero_secreto = numeroaleatorio % 101;
    int tentativas = 1;
    double pontos = 100;

    int acertou = 0;


    //-------- Dificuldade ---------------
    
    
    int nivel;

    printf("Escolha o número com base na dificuldade que desejar:\n");
    printf("\n (1) - FÁCIL\n (2) - MÉDIO\n (3) - DIFÍCIL\n");
    printf("\nEscolha: ");
    scanf("%d", &nivel);
    
    int numerodetentativas;

    if(nivel == 1){
        numerodetentativas = 15;
    }else if(nivel == 2){
        numerodetentativas = 10;
    }else if(nivel == 3){
        numerodetentativas = 5;
    }else{
        printf("Opção Inválida!!");
        return 1;
    }

    //---------------- OU -------------------

    // switch(nivel){
    //     case 1:
    //     numerodetentativas = 15;
    //     break;

    //     case 2:
    //     numerodetentativas = 10;
    //     break;

    //     default : 
    //     numerodetentativas - 5;
    //     break;
    // }
    

  for(int i=1; i <= numerodetentativas; i++){

        printf("---- \n");
        printf("Tentativa %d! \n", tentativas);
        printf("--------------\n");
        printf("Chute um número aleatório de 0 até 100: \n");
        scanf("%d", &chute);

       if(chute < 0 || chute > 100){
            printf("Você deve chutar um número entre 0 e 100: \n");
            continue;
        }

        int maior = chute > numero_secreto;
        acertou = (chute == numero_secreto);
    
        if(acertou){
            break;

        } else if(maior) {
            printf("O seu chute foi maior do que o número secreto!!\n");
            
        } else {
            printf("O seu chute foi menor do que o número secreto!!\n");
        }
        
        tentativas++;

        double pontosperdidos = abs(chute - numero_secreto) / 5.0 ; 
        pontos = pontos - pontosperdidos; //ou pontos -= pontosperdidos;

    }

    printf("\n      -- FIM DE JOGO -- \n");
    
    if(acertou){
        printf("\n   Paranéns!!! Você ganhou!\n");
        printf("Você acertou em %d tentativas!!\n", tentativas);
        printf("    Total de ponto: %.1f\n", pontos);
    }else{
        printf("-------------------------- ");
        printf("\nSuas tentativas acabaram!! O número secreto era %d.\n", numero_secreto);
    }


}
