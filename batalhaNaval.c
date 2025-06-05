#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Declaração do tabuleiro (matriz 10x10)
    int tabuleiro[10][10];

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Vetores que representam os navios (não são estritamente necessários, mas incluídos conforme especificado)
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios (pré-definidas no código)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação de posição do navio horizontal (cabe no tabuleiro)
   if (coluna_horizontal + 3 <= 10) {
        // Verifica se não há sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Posiciona o navio horizontal se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            }
        } else {
            printf("Erro: Sobreposição detectada ao posicionar o navio horizontal.\n");
        }
    } else {
        printf("Erro: O navio horizontal excede os limites do tabuleiro.\n");
    }

    // Validação de posição do navio vertical (cabe no tabuleiro)
    if (linha_vertical + 3 <= 10) {
        // Verifica se não há sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        // Posiciona o navio vertical se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        } else {
            printf("Erro: Sobreposição detectada ao posicionar o navio vertical.\n");
        }
    } else {
        printf("Erro: O navio vertical excede os limites do tabuleiro.\n");
    }

    // Exibição do tabuleiro no console
    printf("TABULEIRO BATALHA NAVAL \n");

    // Imprime cabeçalho de letras (colunas)
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int j = 0; j < 10; j++) {
        // Imprime número da linha (1 a 10), alinhado
        printf("%2d ", j + 1);
        for (int i = 0; i < 10; i++) {
            printf("%d ", tabuleiro[j][i]);
        }
        printf("\n");
    }

    return 0;
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0