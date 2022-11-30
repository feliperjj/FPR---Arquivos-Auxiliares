/*
	FPR - Professor Leonardo Vianna
	Turma: Manh�
	Data: 07/04/2022

	Lista de Exerc�cios V (Matrizes):

	QUEST�O 02:
	Desenvolver uma fun��o que, dada uma matriz M15�20, determine se um n�mero X se encontra na linha L da matriz.

	vers�o 1: percorre toda a matriz, quando deveria percorrer apenas a linha desejada (solu��o ineficiente)
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define L 10
#define C 20

//prot�tipos das fun��es
int numOcorrenciasLinha (int m[L][C], int numero, int linha);

void preencherMatriz (int m[L][C]);
void exibirMatriz (int m[L][C]);

//main
void main ()
{
	//declara��o de vari�veis
	int matriz[L][C], valor, quantidade, linha;

	//preenchendo a matriz com n�meros aleat�rios
	preencherMatriz (matriz);

	//exibindo a matriz
	printf ("Exibindo a matriz:\n\n");
	exibirMatriz (matriz);

	//lendo o valor a ser buscado
	printf ("\n\nEntre com o valor a ser buscado: ");
	scanf ("%d", &valor);

	//lendo a linha a ser percorrida
	printf ("\n\nEntre com a linha da matriz a ser percorrida: ");
	scanf ("%d", &linha);

	//chamando a fun��o
	quantidade = numOcorrencias (matriz, valor, linha);

	//exibindo o resultado
	printf ("\n\nForam encontradas %d ocorrencias no numero %d na linha %d da matriz!", quantidade, valor, linha);
}

//implementa��o das fun��es
void preencherMatriz (int m[L][C])
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
			m[i][j] = rand()%20 + 1;   //inserindo valores de 1 a 20 na matriz
		}
	}
}

void exibirMatriz (int m[L][C])
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

int numOcorrencias (int m[L][C], int numero, int linha)
{
	//declara��o de vari�veis
	int i, j, cont=0;

	//transformando do intervalo de 1..L para 0..(L-1)
	linha--;

	//percorrendo as linhas da matriz
	for (i=0; i<L; i++)
	{
		//percorrendo as colunas da matriz
		for (j=0; j<C; j++)
		{
			//verificando se trata-se da linha desejada
			if (i == linha)
			{
				//verificando se o valor foi encontrado
				if (m[linha][j]==numero)
				{
					cont++;	//atualizando o n�mero de ocorr�ncias
				}
			}
		}
	}

	//retornando a quantidade de ocorr�ncias
	return cont;
}
