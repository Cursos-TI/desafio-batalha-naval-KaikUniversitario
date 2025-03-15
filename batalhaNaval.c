#include <stdio.h>

#define TAMANHOMATRIZ 10
#define NAVIO 3
#define AGUA 0
#define AREA 5


                //função para saber se pode colocar o navio, retorna verdadeio(1) ou falso(0)
    int Pode_Colocar_Navio(int tabuleiro[TAMANHOMATRIZ][TAMANHOMATRIZ], int linha, int coluna, int tamanhoNavio, char direcao)
    {
        if (direcao == 'V'){ //vertical          
            if(linha + tamanhoNavio > TAMANHOMATRIZ) return 0; // testa se cabe no tabuleiro.
            
            for(int i = 0; i < tamanhoNavio; i++)
            {
              if(tabuleiro[linha + i][coluna] != AGUA) return 0; // testa se tem sobreposição.
            }           
        }
        
        if (direcao == 'H'){ //horizontal               
                if(coluna + tamanhoNavio > TAMANHOMATRIZ) return 0; // testa se cabe no tabuleiro.

                for(int i = 0; i < tamanhoNavio; i++)
                {
                    if(tabuleiro[linha][coluna + i] != AGUA) return 0; // testa se tem sobreposição.
                }           
        }

        if (direcao == 'D'){     //diagonal principal(esquerda para direita)          
               if (linha + tamanhoNavio > TAMANHOMATRIZ || coluna + tamanhoNavio > TAMANHOMATRIZ) return 0; //testa se cabe no tabuleiro
              
               for (int i = 0; i < tamanhoNavio; i++)
               {
                 if (tabuleiro[linha + i][coluna + i] != AGUA ) return 0; // testa se tem sobreposição.
               }                                 
        }                      
    
        if (direcao == 'd'){     //diagonal inversa(direita para esquerda)               
                if (linha + tamanhoNavio > TAMANHOMATRIZ || coluna - tamanhoNavio + 1 < 0) return 0;// testa se cabe no tabuleiro.
                
                for (int i = 0; i < tamanhoNavio; i++)
                {
                   if (tabuleiro[linha + i][coluna - i] != AGUA); return 0;  // testa se tem sobreposição.
                }           
        }                             
        return 1; // Retorna verdadeiro se o espaço estiver livre	
    }
            
            //função para colocar o navio.
            
    void ColocarNavio(int tabuleiro[TAMANHOMATRIZ][TAMANHOMATRIZ], int linha, int coluna, int tamanhoNavio, char direcao)
    {
        if (Pode_Colocar_Navio(tabuleiro, linha, coluna, tamanhoNavio, direcao)){
        
            if(direcao == 'V') //se vertical
            {
                for(int i = 0; i < tamanhoNavio; i++)
                {
                    tabuleiro[linha + i][coluna] = NAVIO;	
                }               
            }else if(direcao == 'H') //se horizontal
            {
                for(int i = 0; i < tamanhoNavio; i++)
                {
                    tabuleiro[linha][coluna + i] = NAVIO;	
                }
            }else if (direcao == 'D') // se diagonal principal(esquerda para direita)
            {
                for (int i = 0; i < tamanhoNavio; i++)
                {
                    tabuleiro[linha + i][coluna + i] = NAVIO;
                }                
            }else if (direcao == 'd') // se diagonal inversa(direita para esquerda)
            {
                for (int i = 0; i < tamanhoNavio; i++)
                {
                    tabuleiro[linha + i][coluna] = NAVIO;
                }               
            }                                      
        }else {
            printf("Erro: O navio não pode ser colocado na posição (%d, %d) com tamanho %d e direção '%c'!\n", linha, coluna, tamanhoNavio, direcao);         
        }
        
    }
            //função para imprimir o tabuleiro.
    void imprimirTabuleiro(int tabuleiro[TAMANHOMATRIZ][TAMANHOMATRIZ]){
        
        printf("   A B C D E F G H I J \n"); //cordenadas das colunas.
        
        for(int i = 0; i < TAMANHOMATRIZ; i++){
            printf("%2d ", i + 1); //cordenadas das linhas.
            
            for(int j = 0; j < TAMANHOMATRIZ; j++)
            {
                printf("%d ", tabuleiro[i][j]); //mostra valores do tabuleiro
            }            
            printf("\n");
        }
    }
        //função resetar tabuleiro
    void ResetarTabuleiro(int tabuleiro[TAMANHOMATRIZ][TAMANHOMATRIZ]) {
        for (int i = 0; i < TAMANHOMATRIZ; i++) {
            for (int j = 0; j < TAMANHOMATRIZ; j++) {
                tabuleiro[i][j] = AGUA;
            }
        }
    }
        //função habilidade cone
    void Cone(int linha, int coluna, int tabuleiro[TAMANHOMATRIZ][TAMANHOMATRIZ]){

        int tamanho = 3; // Define o tamanho do cone

        for (int i = 0; i < tamanho; i++)
        {         
            int inicio = coluna - i;  // Define a largura inicial do cone na linha atual
            int fim = coluna + i;     // Define a largura final do cone na linha atual
    
            // Garante que os valores não ultrapassem os limites do tabuleiro
            if (inicio < 0) inicio = 0;
            if (fim >= TAMANHOMATRIZ) fim = TAMANHOMATRIZ - 1;

            // Preenche a linha atual do cone
            for (int j = inicio; j <= fim; j++) {
               tabuleiro[linha + i][j] = AREA;
            }
        }                     
    }
            //Função habilidade cruz 
    void cruz(int linha, int coluna, int tabuleiro[TAMANHOMATRIZ][TAMANHOMATRIZ]){

        int tamanho = 3; // Define o tamanho da cruz
     
     if (!tamanho % 2 == 0)
        {                        
        int horizontal = tamanho / 2 ; // Define a largura inicial da cruz na horizontal
        int vertical = tamanho / 2 ; // Define a largura inicial da cruz na vertical
          

            if (horizontal < 0) horizontal = 0; // Garante que o valor não ultrapasse o limite do tabuleiro
                if (horizontal >= TAMANHOMATRIZ) horizontal = TAMANHOMATRIZ - 1; // Garante que o valor não ultrapasse o limite do tabuleiro

            if (vertical < 0) vertical = 0; // Garante que o valor não ultrapasse o limite do tabuleiro
                if (vertical >= TAMANHOMATRIZ) vertical = TAMANHOMATRIZ - 1; // Garante que o valor não ultrapasse o limite do tabuleiro

        for (int i = 0; i <= vertical; i++)
        {
            tabuleiro[linha - i ][coluna] = AREA; // Preenche a linha superior da cruz
            
            for (int j = 0; j <= horizontal; j++)
            {
                tabuleiro[linha][coluna - j - 1] = AREA; // Preenche a linha central da cruz
                tabuleiro[linha][coluna + j + 1] = AREA; // Preenche a linha central da cruz
            }

            tabuleiro[linha + i][coluna] = AREA ; // Preenche a linha inferior da cruz
        }

        } else {
            printf("Erro: A cruz só sera preenchida corretamente se for de tamanho impar.\n");
        }        
    }

             //Função habilidade octaedro 
    void octaedro(int linha, int coluna, int tabuleiro[TAMANHOMATRIZ][TAMANHOMATRIZ]){

        int tamanho = 3; // Define o tamanho do octaedro
    
        // Parte superior do losango
        for (int i = 0; i < tamanho; i++) {
            int inicio = coluna - i;  // Expansão para a esquerda
            int fim = coluna + i;     // Expansão para a direita
            int linhaAtual = linha - (tamanho - 1 - i); // Cresce para cima
    
            // Garante que os valores não ultrapassem os limites do tabuleiro
            if (linhaAtual < 0) continue;;;
            if (inicio < 0) inicio = 0;
            if (fim >= TAMANHOMATRIZ) fim = TAMANHOMATRIZ - 1;
    
            // Preenche a linha atual do losango
            for (int j = inicio; j <= fim; j++) {
                tabuleiro[linhaAtual][j] = AREA;
            }
        }
    
        // Parte inferior do losango
        for (int i =  0; i < tamanho; i++) {
            int inicio = coluna - (tamanho - i - 1);
            int fim = coluna + (tamanho - i - 1);
            int linhaAtual = linha + i;

             // Garante que os valores não ultrapassem os limites do tabuleiro
            if (linhaAtual >= TAMANHOMATRIZ) break;
            if (inicio < 0) inicio = 0;
            if (fim >= TAMANHOMATRIZ) fim = TAMANHOMATRIZ - 1;
    
            for (int j = inicio; j <= fim; j++) {
                tabuleiro[linhaAtual][j] = AREA;
            }
        }
    }
    



    int main(){
        int tabuleiro[TAMANHOMATRIZ][TAMANHOMATRIZ] = {0};  //inicialização do tabuleiro
        
        ColocarNavio(tabuleiro, 3, 0, 3, 'V'); // primeiro navio na vertical
        ColocarNavio(tabuleiro, 0, 1, 3, 'H'); // segundo navio na horizontal
        ColocarNavio(tabuleiro, 2, 4, 3, 'D'); // terceiro navio na diagonal principal(esquerda para direita)
        ColocarNavio(tabuleiro, 0, 9, 15, 'd'); // quarto navio na diagonal inversa(direita para esquerda)

        Cone(4, 2, tabuleiro); //habilidade especial
        octaedro(2, 7, tabuleiro); //habilidade especial
        cruz(8, 6, tabuleiro); //habilidade especial

        imprimirTabuleiro(tabuleiro); // imprime o tabuleiro
        
        return 0;
    }
