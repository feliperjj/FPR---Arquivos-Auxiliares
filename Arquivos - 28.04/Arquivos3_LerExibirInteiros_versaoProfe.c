/*
	FAETERJ-Rio
	FPR - Manh� - 2022/1
	Data: 27/04/2022

	Arquivos

	Exemplo 4: considerando um arquivo contendo n�meros inteiros, desenvolver uma fun��o que leia o
	conte�do deste arquivo e o exiba na tela.
*/

//importa��o de bibliotecas
#include<stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int leituraArquivo(char nomeArq[]);

//main
void main()
{
	//declara��o de vari�veis
	char nomeArq[30];

	//lendo o nome do arquivo cujos dados ser�o lidos
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArq);

	//chamando a fun��o
	if (leituraArquivo (nomeArq) == TRUE)
	{
		printf("\nArquivo lido com sucesso!");
	}
	else
	{
		printf("\nErro na abertura do arquivo!");
	}
}

//implementa��o das fun��es
int leituraArquivo (char nomeArq[])
/*ATEN��O: as fun��es que manipulam arquivo receber�o por par�metro a string que representa o nome do arquivo; e
n�o uma vari�vel FILE*
*/
{
	//declara��o de vari�veis
	FILE *arq;
	int numero;

	//tentativa de abrir o arquivo para leitura
	arq = fopen (nomeArq, "r");

	//verificando se houve erro na abertura do arquivo
	if (arq == NULL)
	{
		return FALSE;
	}
	else
	{
		//lendo os n�meros do arquivo at� se chegar ao seu final
		while (fscanf (arq, "%d", &numero) != EOF) //EOF = end of file
		{
			//exibindo na tela os valores lidos
			printf ("%d\n", numero);
		}

		//fechando o arquivo
		fclose(arq);

		return TRUE;
	}
}
