/*
Quest�o 04: Pede-se a implementa��o de uma
fun��o recursiva que exiba os n primeiros
termos de uma PG (Progress�o Geom�trica),
onde a1 � o seu primeiro termo e q a raz�o.

Observa��o: uma PG consiste em uma
sequ�ncia de valores, iniciadas pelo valor a1. Os
demais elementos s�o definidos como o
anterior multiplicado pela raz�o.
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
