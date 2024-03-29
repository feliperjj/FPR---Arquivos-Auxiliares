Considerando a existência de um arquivo A contendo números inteiros positivos, um por linha, pede-se a
implementação de uma função que crie um segundo arquivo, B, com as seguintes características:
▪ Para cada valor de A, escrever em B uma linha com todos os seus divisores;
▪ Para cada elemento do primeiro arquivo, apenas uma linha de divisores deve ser inserida em B.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 3
#define C 4

void trocar(int m[L][C], int c1, int c2) {
    int i, temp;

    if (c1 >= C || c2 >= C) {
        printf("Colunas inválidas.\n");
        return;
    }

    for (i = 0; i < L; i++) {
        temp = m[i][c1];
        m[i][c1] = m[i][c2];
        m[i][c2] = temp;
    }
     // Inverte a ordem na coluna c1
    for (int i = 0; i < L/2; i++) {
        int temp = M[i][c1];
        M[i][c1] = M[L-1-i][c1];
        M[L-1-i][c1] = temp;
    }

    printf("Colunas %d e %d trocadas com sucesso.\n", c1, c2);
}

void preencher(int M[L][C]) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            M[i][j] = rand() % 10;
        }
    }
}

void exibir(int M[L][C]) {
    int i, j;

    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            printf("%3d ", M[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int matriz[L][C];
    int c1, c2;

    preencher(matriz);
    printf("Matriz original:\n");
    exibir(matriz);

    printf("Digite as colunas que deseja trocar: ");
    scanf("%d %d", &c1, &c2);

    trocar(matriz, c1, c2);

    printf("Matriz após a troca:\n");
    exibir(matriz);

    return 0;
}
