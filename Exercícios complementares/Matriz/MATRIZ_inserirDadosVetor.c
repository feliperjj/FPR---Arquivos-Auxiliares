/*
INSERIR MULTIPLOS DE 7 DE UM VETOR EM UMA MATRIZ
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int pos=0, i, j, mat[10][5], vet[50];
	for (i=0;i<10;i++){
		for (j=0;j<5;j++){
			scanf("%d", &mat[i][j]); //mat[i][j]=random()%100;
			if (mat[i][j]%7==0) {
				vet[pos]=mat[i][j];
				pos++;
			}
		}
	}
	for (i=0;i<pos;i++)
		printf("%d ", vet[i]);
	return 0;
}
