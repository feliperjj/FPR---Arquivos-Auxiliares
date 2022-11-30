/*
	FAETERJ-Rio
	FPR - Manh� - 2022/1
	Data: 28/04/2022

	Arquivos

	Exemplo 5: ler o conte�do de um arquivo e exibi-lo na tela, independente do tipo de informa��o que armazena.

	(neste caso, consideraremos que o arquivo � constitu�do por diversos caracteres)
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int leituraArquivo (char nomeArq[]);

//main
void main()
{
	//declara��o de vari�veis
	char nomeArquivo[30];

	//lendo o nome do arquivo cujos dados ser�o lidos
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);

	//chamando a fun��o
	if (leituraArquivo (nomeArquivo) == TRUE)
	{
		printf("Arquivo lido com sucesso!");
	}
	else
	{
		printf("Erro na abertura do arquivo!");
	}
}

//implementa��o das fun��es
int leituraArquivo (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arq;
	char caracter;

	//tentativa de abrir o arquivo para leitura
	arq = fopen (nomeArq, "r");

	//verificando se houve erro na abertura do arquivo
	if (arq == NULL)
	{
		return FALSE;
	}
	else
	{
		//lendo os caracteres do arquivo at� se chegar ao seu final
		while (fscanf (arq, "%c", &caracter) != EOF)
		{
			//exibindo na tela os caracteres lidos
			printf("%c", caracter);
		}

		//fechando o arquivo
		fclose(arq);

		return TRUE;
	}
}
