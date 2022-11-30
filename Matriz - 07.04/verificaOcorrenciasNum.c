//Percorrer a matriz completa para verificar o num de ocorrencias de um número
#include <stdio.h>
#define C 10
#define L 10
int numOcorrencias(int n[L][C], int numero){
	int i,j,cont=0;
	for (i=0;i<L;i++){
		for (j=0;j<C;j++){
			if (n[i][j]==numero){
				cont++;
			}
		}
	}
return cont;
}
