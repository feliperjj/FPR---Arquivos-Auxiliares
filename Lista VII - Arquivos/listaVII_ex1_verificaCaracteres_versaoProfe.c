/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022

	Lista de Exerc�cios VII (Arquivos)

	Quest�o 01:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de caracteres
	no mesmo.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int contarCaracteres (char nomeArq[]);

//main
void main ()
{
	//declara��o de arquivos
	char nomeArquivo[30];
	int quantidade;

	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);

	//chamando a fun��o
	quantidade = contarCaracteres (nomeArquivo);

	//exibindo o resultado
	switch (quantidade)
	{
		case -1: printf ("\nErro na abertura do arquivo.");
		         break;

		case 0:  printf ("\nArquivo vazio.");
		         break;

		default: printf ("\nHa %d caracteres no arquivo %s.", quantidade, nomeArquivo);
	}
}

//implementa��o das fun��es
int contarCaracteres (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arq;
	int cont = 0;
	char caracter;

	//abrindo o arquivo
	arq = fopen (nomeArq, "r");

	//testando se houve sucesso na abertura ou n�o
	if (arq == NULL)
	{
		return -1;	//sinalizando que n�o foi poss�vel abrir o arquivo
	}
	else
	{
		//lendo os caracteres do arquivo
		while (fscanf (arq, "%c", &caracter) != EOF)
		{
			cont++;
		}

		//fechando o arquivo
		fclose (arq);

		//retornando a quantidade de caracteres
		return cont;
	}
}
