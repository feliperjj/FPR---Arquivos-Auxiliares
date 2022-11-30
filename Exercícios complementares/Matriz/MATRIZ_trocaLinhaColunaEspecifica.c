/*
MATRIZ: TROCAR LINHAS ESPECÍFICAS
Exemplo: ESCREVER UM ALGORITMO QUE LE UMA MATRIZ 10 X 10 E A ESCREVA E TROQUE A SEGUIR A LINHA 2 PELA LINHA 8.
TROQUE A COLUNA 4 PELA COLUNA 10.

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
    int i, j, k, l;
    if (L!=C){
        return FALSE;
    } else {
        for (i=0;i<L;i++){
            if (i==8){
               for (k=0;k<C;k++){
                  t[2][k] = m[i][k];
               }
            } else {
                t[i][j] = m[i][j];
            }
            for (j=0;j<C;j++){
                if (j==9){
                    for (l=0;l<L;l++){
                        t[l][9] = m[l][4];
                    }
                } else {
                    t[i][j] = m[i][j];
                }
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
