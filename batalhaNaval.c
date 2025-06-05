#include <stdio.h>

// Função para verificar se é possível posicionar um navio sem sobreposição
int pode_posicionar(int tabuleiro[10][10], int posicoes[3][2]) {
    for (int i = 0; i < 3; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        if (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
            return 0; // Fora dos limites
        }
        if (tabuleiro[linha][coluna] != 0) {
            return 0; // Sobreposição
        }
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionar_navio(int tabuleiro[10][10], int posicoes[3][2]) {
    for (int i = 0; i < 3; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        tabuleiro[linha][coluna] = 3;
    }
}

int main() {
    // Declaração e inicialização do tabuleiro 10x10 com água (0)
    int tabuleiro[10][10];
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Definição das posições dos quatro navios (tamanho 3)
    // Navio 1: Horizontal (linha 2, colunas 4-6)
    int navio1[3][2] = {{2,4}, {2,5}, {2,6}};
    // Navio 2: Vertical (linhas 5-7, coluna 7)
    int navio2[3][2] = {{5,7}, {6,7}, {7,7}};
    // Navio 3: Diagonal principal (linha=coluna, posições 0,1,2)
    int navio3[3][2] = {{0,0}, {1,1}, {2,2}};
    // Navio 4: Diagonal secundária (linha=0, coluna=9; linha=1, coluna=8; linha=2, coluna=7)
    int navio4[3][2] = {{0,9}, {1,8}, {2,7}};

    // Posicionamento dos navios com validação
    if (pode_posicionar(tabuleiro, navio1)) {
        posicionar_navio(tabuleiro, navio1);
    } else {
        printf("Erro ao posicionar navio 1 (horizontal).\n");
    }

    if (pode_posicionar(tabuleiro, navio2)) {
        posicionar_navio(tabuleiro, navio2);
    } else {
        printf("Erro ao posicionar navio 2 (vertical).\n");
    }

    if (pode_posicionar(tabuleiro, navio3)) {
        posicionar_navio(tabuleiro, navio3);
    } else {
        printf("Erro ao posicionar navio 3 (diagonal principal).\n");
    }

    if (pode_posicionar(tabuleiro, navio4)) {
        posicionar_navio(tabuleiro, navio4);
    } else {
        printf("Erro ao posicionar navio 4 (diagonal secundária).\n");
    }

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

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
