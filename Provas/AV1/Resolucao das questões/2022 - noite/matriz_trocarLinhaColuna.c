/*
Desenvolver uma função que, dada uma matriz de
inteiros M10x10, troque de posição os elementos da
linha L com os valores da coluna C. Caso a troca seja
possível, a função deverá retornar a constante TRUE;
caso contrário, FALSE
*/

#include <stdio.h>
#define L 10
#define C 10
#define TRUE 1
#define FALSE 0

//Protótipo das funções
int trocaPosicao(int m[L][C], int t[L][C]);
void preencherMatriz(int m[L][C]);
void exibir (int t[L][C]);

void main(){
    int matriz[L][C];
    int matrizAux[L][C];
    preencherMatriz(matriz);
    printf("\n\n~~~~~~~~MATRIZ ORIGINAL~~~~~~\n\n");
    exibir(matriz);
    trocaPosicao(matriz, matrizAux);
    printf("\n\n~~~~~~~~MATRIZ TROCADA~~~~~~\n\n");
    exibir(matrizAux);
}

void preencherMatriz (int m[L][C]){
	int i, j;
	srand (time(NULL));
	for (i=0;i<L;i++){
		for (j=0;j<C;j++) {
			m[i][j] = rand()%5 + 1;
		}
	}
}

int trocaPosicao(int m[L][C], int t[L][C]){
    int i, j;
    if (L!=C){
        return FALSE;
    } else {
        for (i=0;i<L;i++){
            for (j=0;j<C;j++){
                t[i][j] = m[j][i];
            }
        }
    }
}

void exibir (int t[L][C]){
	int i, j;
	for (i=0;i<L;i++){
		for (j=0;j<C;j++)
		{
			printf ("%3d ", t[i][j]);
		}

		printf ("\n");
	}
}
