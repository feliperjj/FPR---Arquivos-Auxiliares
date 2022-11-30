/*
	FAETERJ-Rio
	FPR - Manh�
	Prova a compor a AV2
	Data: 06/07/2022
	
	Quest�o 02 [2,5 pontos]:
	Implementar uma fun��o que utilize recursividade que, dado um vetor com quant inteiros, exiba, para cada 
	elemento do conjunto, a quantidade de elementos do vetor que s�o maiores do que ele, como ilustrado no 
	exemplo a seguir:

								8	6	2	1	8	5	2	4
								0	1	2	3	4	5	6	7
								
										8 - 0 valores maiores
										6 - 2 valores maiores
										2 - 5 valores maiores
										1 - 7 valores maiores
										8 - 0 valores maiores
										5 - 3 valores maiores
										2 - 5 valores maiores
										4 - 4 valores maiores
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos de fun��es
void questao02 (int vetor[], int tamanho);

void exibirVetor (int vetor[], int tamanho);

//main
void main ()
{
	//declara��o de vari�veis
	int vet[8] = {8,6,2,1,8,5,2,4};
		
	//exibindo o vetor
	exibirVetor (vet, 8);
	
	//chamando a fun��o
	questao02 (vet, 8);	
}

//implementa��o das fun��es
void questao02 (int vetor[], int tamanho)
{
	
}

void exibirVetor (int vetor[], int tamanho)
{
	//declara��o de vari�veis
	int i;
	
	//percorrendo as posi��es do vetor
	for (i=0;i<tamanho;i++)
	{
		printf ("%3d ", vetor[i]);
	}
}
