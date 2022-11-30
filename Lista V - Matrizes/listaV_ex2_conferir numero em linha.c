/*
	FPR - Professor Leonardo Vianna
	Turma: Manhã
	Data: 07/04/2022

	Lista de Exercícios V (Matrizes):

	QUESTÃO 02:
	Desenvolver uma função que, dada uma matriz M15×20, determine se um número X se encontra na linha L da matriz.

	versão 1: percorre toda a matriz, quando deveria percorrer apenas a linha desejada (solução ineficiente)
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 10
#define C 20

//protótipos das funções
int numOcorrenciasLinha (int m[L][C], int numero, int linha);

void preencherMatriz (int m[L][C]);
void exibirMatriz (int m[L][C]);

//main
void main ()
{
	//declaração de variáveis
	int matriz[L][C], valor, quantidade, linha;

	//preenchendo a matriz com números aleatórios
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

	//chamando a função
	quantidade = numOcorrencias (matriz, valor, linha);

	//exibindo o resultado
	printf ("\n\nForam encontradas %d ocorrencias no numero %d na linha %d da matriz!", quantidade, valor, linha);
}

//implementação das funções
void preencherMatriz (int m[L][C])
{
	//declaração de variáveis
	int i, j;

	//garantindo que as sequências aleatórias são diferentes
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
	//declaração de variáveis
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
	//declaração de variáveis
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
					cont++;	//atualizando o número de ocorrências
				}
			}
		}
	}

	//retornando a quantidade de ocorrências
	return cont;
}
