/*
Quest�o 03: Fazer uma fun��o recursiva que,
dado um n�mero inteiro N, exiba o mesmo na
base 2 (bin�ria).
*/

#include <stdio.h>

void exibeBinarios(int n);

void main(){
	int n;
	printf("Insira o valor de N: ");
	scanf("%d",&n);
	exibeBinarios(n);
}

void exibeBinarios(int n){
	if (n>0){
		exibeBinarios(n/2);
		printf("%d", n%2);
	}
}
