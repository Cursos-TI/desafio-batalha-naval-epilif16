#include <stdio.h>

#define TAMANHO 10 // Tamanho do tabuleiro

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[5][5], int origemLinha, int origemColuna) {
    int tamanhoHabilidade = 5; // Tamanho das matrizes de habilidade

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            int linhaTabuleiro = origemLinha + i - tamanhoHabilidade / 2;
            int colunaTabuleiro = origemColuna + j - tamanhoHabilidade / 2;

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Marca a área afetada pela habilidade
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa o tabuleiro com água (0)

    // Posiciona navios no tabuleiro
    tabuleiro[2][3] = 3; tabuleiro[2][4] = 3; tabuleiro[2][5] = 3; // Navio horizontal
    tabuleiro[5][7] = 3; tabuleiro[6][7] = 3; tabuleiro[7][7] = 3; // Navio vertical

    // Matriz de habilidade Cone
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Matriz de habilidade Cruz
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // Matriz de habilidade Octaedro
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4); // Cone com origem na posição (4, 4)
    aplicarHabilidade(tabuleiro, cruz, 6, 6); // Cruz com origem na posição (6, 6)
    aplicarHabilidade(tabuleiro, octaedro, 8, 8); // Octaedro com origem na posição (8, 8)

    // Imprime o tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("----------------------------------\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // Área afetada pela habilidade
            }
        }
        printf("\n");
    }

    return 0;
}
