/*QUESTÃO 05: Implementar uma função que, dada uma matriz
M10×8, gere um vetor V de tamanho 8, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.*/

#include <stdio.h>
#define L 10
#define C 8

void main(){
    int vet[C];
    int matriz[L][C];
    preencherMatriz(matriz);
    exibeMatriz(matriz);
    povoaVetor(vet,matriz);
    exibeVetor(vet,C);

}

void preencherMatriz(int m[L][C]){
    //declaração de variáveis
	int i, j;
	//garantindo que as sequências aleatórias são diferentes
	srand (time(NULL));
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++){
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++){
			m[i][j] = rand()%5 + 1;
		}
	}
}

void exibeMatriz (int m[L][C]){
	int i, j;
	printf ("\n");
	for (i=0;i<L;i++){
		for (j=0;j<C;j++){
			printf ("%3d ", m[i][j]);
		}
		printf ("\n");
	}
}


void povoaVetor (int vet[], int matriz[L][C]){
    int i, j, soma;
    for (i=0; i<C; i++ ){
        soma=0;
        for (j=0; j<L; j++){
            soma=soma+matriz[j][i];
            vet[i]=soma;
        }
    }
}

void exibeVetor (int vet[], int tam){
    int i;
    printf("\nO vetor eh:");
    for (i=0;i<tam;i++){
        printf("%3d ", vet[i]);
    }
}
