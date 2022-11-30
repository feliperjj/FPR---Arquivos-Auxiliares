/*
Questão 03: Fazer uma função recursiva que,
dado um número inteiro N, exiba o mesmo na
base 2 (binária).
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
