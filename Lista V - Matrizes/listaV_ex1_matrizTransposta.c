/*
	FAETERJ-Rio
	FPR - Manh� - 2022/1
	Professor Leonardo Vianna

	Data: 07/04/2022

	Lista de Exerc�cios V (matrizes):

	QUEST�O 01: Fa�a um fun��o que, dada uma matriz M8�5 de reais, gere a
	matriz Mt, sua transposta.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define L 8
#define C 5

//prot�tipos das fun��es
void transposta (int m[L][C], int t[C][L]);
void preencher (int m[L][C]);
void exibir (int m[L][C]);
void exibirTransposta (int t[C][L]);

//main
void main ()
{
	//declara��o de vari�veis
	int matriz[L][C], transp[C][L];

	//preenchendo a matriz com n�meros aleat�rios
	preencher (matriz);

	//exibindo a matriz
	printf ("Exibindo a matriz original:\n\n");
	exibir (matriz);

	//gerando a matriz transposta
	transposta (matriz, transp);

	//exibindo a matriz transposta
	printf ("\n\nExibindo a matriz transposta:\n\n");
	exibirTransposta (transp);

}

//implementa��o das fun��es
void transposta (int m[L][C], int t[C][L])
{
	//declara��o de vari�veis
	int i, j;

	//percorrendo as linhas da matriz transposta
	for (i=0;i<C;i++)
	{
		//percorrendo as colunas da matriz transposta
		for (j=0;j<L;j++)
		{
			t[i][j] = m[j][i];
		}
	}
}

void preencher (int m[L][C])
{
	//declara��o de vari�veis
	int i, j;

	//garantindo que as sequ�ncias aleat�rias s�o diferentes
	srand (time(NULL));

	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			m[i][j] = rand()%100 + 1;
		}
	}
}

void exibir (int m[L][C])
{
	//declara��o de vari�veis
	int i, j;

	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			printf ("%3d ", m[i][j]);
		}

		printf ("\n");
	}
}

void exibirTransposta (int t[C][L])
{
	//declara��o de vari�veis
	int i, j;

	//percorrendo as linhas da matriz
	for (i=0;i<C;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<L;j++)
		{
			printf ("%3d ", t[i][j]);
		}

		printf ("\n");
	}
}
