#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.


int main() {
   
    int N1, N2; //navio 1 e navio 2
    int tabuleiro[10][10] = {    //tabuleiro do jogo
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

     for( N1 = 4; N1 < 7; N1++){    // primeiro navio , na vertical com o tamnho 3

        tabuleiro[N1][2] = 3;

     }

    for( N2 = 4; N2 < 7; N2++){   // segundo navio , na horizontal com o tamnho 3

        tabuleiro[4][N2] = 3;

    }

    printf("   A B C D F G H I J K \n"); //cordenadas da coluna
            
    for(int i = 0; i < 10; i++){  //imprime o tabulheiro no terminal.

        printf("%2d-", i + 1); // cordenadas das linhas
      
        for( int j = 0; j < 10; j++){
            
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }   
    
    return 0;
}
