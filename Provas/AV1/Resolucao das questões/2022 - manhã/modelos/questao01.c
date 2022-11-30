/*
	FAETERJ-Rio
	FPR - Manh�
	Prova a compor a AV1 (Parte I)
	Data: 05/05/2022
	
	Quest�o 01 [2,5 pontos]:
	Desenvolver uma fun��o que receba duas matrizes de inteiros, ambas 
	de ordem 10, com as seguintes caracter�sticas:
		a.	M1: matriz contendo n�meros inteiros quaisquer;
		b.	M2: matriz contendo apenas os valores 0 ou 1. 

	Desenvolver uma fun��o que a partir destas matrizes gere a 
	matriz M3, tamb�m de ordem 10, cujos elementos s�o definidos da 
	seguinte forma:

			M2ij = 0	==>		M3ij = M1ij
			M2ij = 1 	==>		M3ij = soma dos elementos da linha 
								i com os da coluna j da matriz.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define ORDEM 10

//prot�tipos de fun��es
void questao01 (int m1[ORDEM][ORDEM], int m2[ORDEM][ORDEM], int m3[ORDEM][ORDEM]);

void preencherMatriz (int m[ORDEM][ORDEM], int limite);
void exibirMatriz (int m[ORDEM][ORDEM]);

//main
void main ()
{
	//declara��o de vari�veis
	int matriz1[ORDEM][ORDEM], matriz2[ORDEM][ORDEM], matriz3[ORDEM][ORDEM];
		
	//preenchendo a primeira matriz com n�meros aleat�rios com 
	//n�meros de 0 a 5
	preencherMatriz (matriz1, 5);

	//preenchendo a segunda matriz aleatoriamente com 0s e 1s
	preencherMatriz (matriz2, 1);
	
	//exibindo a primeira matriz
	exibirMatriz (matriz1);

	//exibindo a segunda matriz
	exibirMatriz (matriz2);

	//chamando a fun��o
	questao01 (matriz1, matriz2, matriz3);
	
	//exibindo a terceira matriz, rec�m-gerada
	exibirMatriz (matriz3);

}

//implementa��o das fun��es

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
	//declara��o de vari�veis
	int i, j;

	//garantindo que as sequ�ncias aleat�rias s�o diferentes
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
	//declara��o de vari�veis
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


