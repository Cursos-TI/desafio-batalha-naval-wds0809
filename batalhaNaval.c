#include <stdio.h>
#include <stdlib.h>

#define LINHA 10
#define COLUNA 10
#define CONE_LINHAS 3
#define CONE_COLUNAS 5
#define CRUZ_LINHAS 5
#define CRUZ_COLUNAS 5
#define OCTAEDRO_LINHAS 5
#define OCTAEDRO_COLUNAS 5

// Função para aplicar cone (3x5) no tabuleiro
void aplicar_cone(int tabuleiro[LINHA][COLUNA], int origem_linha, int origem_coluna) {
    int centro = CONE_COLUNAS / 2;
    for (int i = 0; i < CONE_LINHAS; i++) {
        for (int j = 0; j < CONE_COLUNAS; j++) {
            // Preenche o cone: a cada linha, expande 1 para cada lado a partir do centro
            if (j >= centro - i && j <= centro + i) {
                int linha_tab = origem_linha + i;
                int coluna_tab = origem_coluna + j;
                if (linha_tab >= 0 && linha_tab < LINHA && coluna_tab >= 0 && coluna_tab < COLUNA) {
                    if (tabuleiro[linha_tab][coluna_tab] == 0) {
                        tabuleiro[linha_tab][coluna_tab] = 1;
                    }
                }
            }
        }
    }
}

// Função para aplicar cruz (5x5) no tabuleiro
void aplicar_cruz(int tabuleiro[LINHA][COLUNA], int origem_linha, int origem_coluna) {
    int centro = CRUZ_LINHAS / 2;
    for (int i = 0; i < CRUZ_LINHAS; i++) {
        for (int j = 0; j < CRUZ_COLUNAS; j++) {
            int linha_tab = origem_linha + i;
            int coluna_tab = origem_coluna + j;
            if (linha_tab >= 0 && linha_tab < LINHA && coluna_tab >= 0 && coluna_tab < COLUNA) {
                // Preenche a cruz (linha central ou coluna central)
                if ((i == centro || j == centro) && tabuleiro[linha_tab][coluna_tab] == 0) {
                    tabuleiro[linha_tab][coluna_tab] = 3;
                }
            }
        }
    }
}

// Função para aplicar octaedro (losango 5x5) no tabuleiro
void aplicar_octaedro(int tabuleiro[LINHA][COLUNA], int origem_linha, int origem_coluna) {
    int centro = OCTAEDRO_LINHAS / 2;
    for (int i = 0; i < OCTAEDRO_LINHAS; i++) {
        for (int j = 0; j < OCTAEDRO_COLUNAS; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                int linha_tab = origem_linha + i;
                int coluna_tab = origem_coluna + j;
                if (linha_tab >= 0 && linha_tab < LINHA && coluna_tab >= 0 && coluna_tab < COLUNA) {
                    if (tabuleiro[linha_tab][coluna_tab] == 0) {
                        tabuleiro[linha_tab][coluna_tab] = 2;
                    }
                }
            }
        }
    }
}

int main() {
    // Declaração e inicialização do tabuleiro 10x10 com água (0)
    int tabuleiro[LINHA][COLUNA];
    for (int linha = 0; linha < LINHA; linha++) {
        for (int coluna = 0; coluna < COLUNA; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Aplica o cone na posição (0,2)
    aplicar_cone(tabuleiro, 0, 2);

    // Aplica a cruz na posição (4, 5) (ajuste se quiser em outro local)
    aplicar_cruz(tabuleiro, 4, 5);

    // Aplica o octaedro na posição (5,0)
    aplicar_octaedro(tabuleiro, 5, 0);

    // Exibição do tabuleiro com cabeçalho de letras e números
    printf("TABULEIRO BATALHA NAVAL\n");
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d ", linha + 1);
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}

