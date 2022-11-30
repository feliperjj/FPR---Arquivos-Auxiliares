/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022

	Lista de Exerc�cios VII (Arquivos)

	Quest�o 02:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de vezes que
	um determinado caracter aparece no arquivo.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int ocorrenciasCaracter (char nomeArq[], char ch);

//main
void main ()
{
	//declara��o de arquivos
	char nomeArquivo[30];
	int quantidade;
	char caracter;

	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);

	//lendo o caracter a ser buscado
	printf ("Entre com o caracter a ser buscado: ");
	fflush (stdin);
	scanf ("%c", &caracter);

	//chamando a fun��o
	quantidade = ocorrenciasCaracter (nomeArquivo, caracter);

	//exibindo o resultado
	if (quantidade == -1)
	{
		printf ("\nErro na abertura do arquivo.");
	}
	else
	{
		printf ("\nForam encontradas %d ocorrencias do caracter %c no arquivo %s.", quantidade, caracter, nomeArquivo);
	}
}

//implementa��o das fun��es
int ocorrenciasCaracter (char nomeArq[], char ch)
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
			//verificando se o caracter lido � aquele sendo buscado
			if (caracter == ch)
			{
				cont++;
			}
		}

		//fechando o arquivo
		fclose (arq);

		//retornando a quantidade de caracteres
		return cont;
	}
}
