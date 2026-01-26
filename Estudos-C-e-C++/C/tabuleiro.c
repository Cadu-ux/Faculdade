#include <stdio.h>

#define LINHAS 6
#define COLUNAS 7

void exibirTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    printf("\n");
    
    // 1. Números das colunas (Guia para o jogador)
    // O espaçamento deve alinhar com o centro das caixas abaixo
    printf("   1   2   3   4   5   6   7\n");
    
    // 2. Borda superior
    printf(" +---+---+---+---+---+---+---+\n");

    // 3. Loop para desenhar cada linha da matriz
    for (int i = 0; i < LINHAS; i++) {
        
        printf(" |"); // Parede lateral esquerda do tabuleiro

        for (int j = 0; j < COLUNAS; j++) {
            // Desenha a peça (ou espaço) e a parede da direita
            // %c será substituído pelo caractere na matriz ('X', 'O' ou ' ')
            printf(" %c |", tabuleiro[i][j]);
        }
        
        printf("\n"); // Pula para a próxima linha visual

        // 4. Linha divisória entre as linhas do tabuleiro
        printf(" +---+---+---+---+---+---+---+\n");
    }
    printf("\n");
}

// --- MOCKUP PARA TESTE (Pode apagar depois) ---
int main() {
    // Criando um tabuleiro fictício só para você ver o visual
    char tabuleiro[LINHAS][COLUNAS];

    // Preenchendo com espaços vazios
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = ' '; 
        }
    }

    // Colocando algumas peças de teste para ver o alinhamento
    tabuleiro[5][0] = 'X'; // Canto inferior esquerdo
    tabuleiro[5][1] = 'O';
    tabuleiro[4][0] = 'X'; // Em cima da primeira peça
    tabuleiro[5][6] = 'O'; // Canto inferior direito

    // Chama a função visual
    exibirTabuleiro(tabuleiro);

    return 0;
}