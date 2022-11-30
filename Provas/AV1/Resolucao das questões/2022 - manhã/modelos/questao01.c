/*
	FAETERJ-Rio
	FPR - Manhã
	Prova a compor a AV1 (Parte I)
	Data: 05/05/2022
	
	Questão 01 [2,5 pontos]:
	Desenvolver uma função que receba duas matrizes de inteiros, ambas 
	de ordem 10, com as seguintes características:
		a.	M1: matriz contendo números inteiros quaisquer;
		b.	M2: matriz contendo apenas os valores 0 ou 1. 

	Desenvolver uma função que a partir destas matrizes gere a 
	matriz M3, também de ordem 10, cujos elementos são definidos da 
	seguinte forma:

			M2ij = 0	==>		M3ij = M1ij
			M2ij = 1 	==>		M3ij = soma dos elementos da linha 
								i com os da coluna j da matriz.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define ORDEM 10

//protótipos de funções
void questao01 (int m1[ORDEM][ORDEM], int m2[ORDEM][ORDEM], int m3[ORDEM][ORDEM]);

void preencherMatriz (int m[ORDEM][ORDEM], int limite);
void exibirMatriz (int m[ORDEM][ORDEM]);

//main
void main ()
{
	//declaração de variáveis
	int matriz1[ORDEM][ORDEM], matriz2[ORDEM][ORDEM], matriz3[ORDEM][ORDEM];
		
	//preenchendo a primeira matriz com números aleatórios com 
	//números de 0 a 5
	preencherMatriz (matriz1, 5);

	//preenchendo a segunda matriz aleatoriamente com 0s e 1s
	preencherMatriz (matriz2, 1);
	
	//exibindo a primeira matriz
	exibirMatriz (matriz1);

	//exibindo a segunda matriz
	exibirMatriz (matriz2);

	//chamando a função
	questao01 (matriz1, matriz2, matriz3);
	
	//exibindo a terceira matriz, recém-gerada
	exibirMatriz (matriz3);

}

//implementação das funções

void questao01 (int m1[ORDEM][ORDEM], int m2[ORDEM][ORDEM], int m3[ORDEM][ORDEM])
{
	int i,j, soma;
	for (i=0;i<ORDEM;i++){
		soma=0;
		for (j=0;j<ORDEM;j++){
			if (m2[i][j]==0){
				m3[i][j]=m1[i][j];
			} else {
				if (m2[i][j]==1){
					soma=soma+m1[j][i]+m1[i][j];
					m3[i][j]=soma;
				}
			}
		}
	}
}

void preencherMatriz (int m[ORDEM][ORDEM], int limite)
{
	//declaração de variáveis
	int i, j;

	//garantindo que as sequências aleatórias são diferentes
	srand (time(NULL));
	
	//percorrendo as linhas da matriz
	for (i=0;i<ORDEM;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<ORDEM;j++)
		{
			m[i][j] = rand()%(limite + 1);
		}
	}
}

void exibirMatriz (int m[ORDEM][ORDEM])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo as linhas da matriz
	for (i=0;i<ORDEM;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<ORDEM;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		
		printf ("\n");
	}
	
	printf ("\n\n");
}


