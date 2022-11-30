/*
	FAETERJ-Rio
	FPR - Manh� - 2022/1
	Data: 27/04/2022

	Arquivos

	Exemplo 1: desenvolver um programa que escreva em um arquivo os n�meros de 1 a N.
*/

//importa��o de bibliotecas
#include<stdio.h>

//main
void main()
{
	//declara��o de vari�veis
	FILE *arq;				//Passo 1: declarar uma vari�vel do tipo FILE*
	char nomeArq[30];		//string contendo o nome do arquivo
	int i, n;

	//lendo o valor de N
	printf ("Entre com o valor de N: ");
	scanf ("%d", &n);

	//lendo o nome do arquivo a ser gerado
	printf ("Entre com o nome do arquivo a ser gerado: ");
	fflush (stdin);
	gets (nomeArq);

	//Passo 2: abrindo o arquivo para escrita
	arq = fopen (nomeArq, "w");					//Tipos de abertura:
												//		w - write (escrita): se existir conte�do no arquivo, o mesmo ser� apagado
												//		r - read (leitura): se n�o existir arquivo, a fun��o retornar� NULL
												//		a - append: acrescenta informa��es ao final do arquivo, preservando o conte�do anterior

	//testando se houve erro na abertura do arquivo
	if (arq != NULL)    //ou apenas:   if (arq)
	{
		//variando os n�meros de 1 a N
		for (i=1; i<=n; i++)
		{
			//escrevendo cada 'i' no arquivo
			fprintf (arq, "%d\n", i);			//Passo 3: manipulando o arquivo
		}

		printf("Arquivo gerado com sucesso");

		//Passo 4: fechando o arquivo
		fclose(arq);
	}
	else
	{
		printf("Erro na abertura do arquivo");
	}
}
