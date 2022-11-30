/*
Questão 04: Pede-se a implementação de uma
função recursiva que exiba os n primeiros
termos de uma PG (Progressão Geométrica),
onde a1 é o seu primeiro termo e q a razão.

Observação: uma PG consiste em uma
sequência de valores, iniciadas pelo valor a1. Os
demais elementos são definidos como o
anterior multiplicado pela razão.
*/

#include <stdio.h>
void calculaPG(int numero, int razao, int quantidade, int i);
void exibirPG(int numero, int razao, int quantidade);

void main(){
	int a1, q, n;
	printf("Insira o valor do primerio termo: ");
	scanf("%d",&a1);
	printf("Insira o valor da razao: ");
	scanf("%d",&q);
	printf("Insira a quantidade de valores que deseja na PG: ");
	scanf("%d",&n);
	exibirPG(a1, q, n);
}

void calculaPG(int numero, int razao, int quantidade, int i){
	if (i<=quantidade){
		printf("%d ", numero);
		calculaPG(numero*razao, razao, quantidade, i+1);
	}
}

void exibirPG(int numero, int razao, int quantidade){
	calculaPG(numero, razao, quantidade, 1);
}
