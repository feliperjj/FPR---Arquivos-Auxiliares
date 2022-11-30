/*
	FAETERJ-Rio
	FPR - Manhã
	Prova a compor a AV2
	Data: 06/07/2022
	
	Questão 02 [2,5 pontos]:
	Implementar uma função que utilize recursividade que, dado um vetor com quant inteiros, exiba, para cada 
	elemento do conjunto, a quantidade de elementos do vetor que são maiores do que ele, como ilustrado no 
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

//importação de bibliotecas
#include <stdio.h>

//protótipos de funções
void questao02 (int vetor[], int tamanho);

void exibirVetor (int vetor[], int tamanho);

//main
void main ()
{
	//declaração de variáveis
	int vet[8] = {8,6,2,1,8,5,2,4};
		
	//exibindo o vetor
	exibirVetor (vet, 8);
	
	//chamando a função
	questao02 (vet, 8);	
}

//implementação das funções
void questao02 (int vetor[], int tamanho)
{
	
}

void exibirVetor (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	//percorrendo as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		printf ("%3d ", vetor[i]);
	}
}
