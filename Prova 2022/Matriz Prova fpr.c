
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