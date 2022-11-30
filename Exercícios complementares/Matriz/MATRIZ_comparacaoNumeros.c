/*
Mostrar o maior e menor numero de uma matriz gerada aleatoriamente
*/

#include <stdio.h>
#define L 5
#define C 5

//Protótipo das funções
void preencherMatriz (int m[L][C]);
void compararNumeros (int m[L][C]);
void exibirMatriz (int m[L][C]);

int main(){
    int matriz[L][C];
    preencherMatriz(matriz);
    exibirMatriz(matriz);
    compararNumeros(matriz);
}

void preencherMatriz (int m[L][C]){
	int i, j;
	srand (time(NULL));
	for (i=0;i<L;i++) {
		for (j=0;j<C;j++) {
			m[i][j] = rand()%5 + 1;
		}
	}
}

void compararNumeros(int m[L][C]){
    int i, j, maior=0, menor=100;
    for (i=0;i<L;i++){
        for (j=0;j<C;j++){
            if (m[i][j]>maior){
                maior=m[i][j];
            } else {
                if (m[i][j]<menor){
                  menor=m[i][j];
                }

            }

        }
    }
    printf("\n\nO menor numero da matriz eh: %d", menor);
    printf("\n\nO maior numero da matriz eh: %d", maior);
}

void exibirMatriz (int m[L][C]) {
	int i, j;
	for (i=0;i<L;i++) {
		for (j=0;j<C;j++) {
			printf ("%3d ", m[i][j]);
		}
		printf ("\n");
	}
}
