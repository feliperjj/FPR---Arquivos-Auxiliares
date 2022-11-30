//Percorrer só uma linha ou coluna da matriz 
#include <stdio.h>
#define C 10
#define L 10
int numOcrrenciasLinha (int n[L][C], int numero, int linha){
	int j, cont=0;
	for (j=0;j<C;j++){
		if (n[linha][j] == numero){
			cont++;
		}
	}
	return cont;
}
