/*
	FAETERJ-Rio
	FPR - Manh� - 2022/1
	Data: 28/04/2022

	Arquivos

	Exemplo 7: desenvolver uma fun��o que removas todas as ocorr�ncias de um n�mero inteiro em determinado
	arquivo

	vers�o 2: removendo o arquivo tempor�rio.
*/

//importa��o de bibliotecas
#include<stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos das fun��es
int removerArquivo (char nomeArq[], int numero);

//main
void main()
{
	//declara��o de vari�veis
	char nomeArquivo[30];
	int num, retorno;

	//obtendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);

	//lendo o n�mero a ser removido
	printf ("Entre com o numero a ser removido: ");
	scanf ("%d", &num);

	//chamando a fun��o e armazenando o retorno
	retorno = removerArquivo (nomeArquivo, num);

	//testando o retorno da fun��o
	switch (retorno)
	{
		case -1: printf ("Erro na abertura do arquivo!");
		         break;

		case  0: printf ("Elemento nao encontrado no arquivo!");
		         break;

		default: printf ("Foram feitas %d remocoes do valor %d", retorno, num);
	}
}

//implementa��o das fun��es
int removerArquivo (char nomeArq[], int numero)
{
	//declara��o de vari�veis
	FILE *arq, *temp;
	int valor, cont=0;

	//abrindo os arquivos
	arq = fopen (nomeArq, "r");
	temp = fopen ("temp.txt", "w");

	//testando se houve erro na abertura dos arquivos
	//if ((arq == NULL) || (temp == NULL))
	if (!arq || !temp)
	{
		return -1;
	}
	else
	{
		//copiando para temp todos os n�meros diferentes daquele que deseja-se remover
		while (fscanf (arq, "%d", &valor) != EOF)
		{
			//verificando se n�o � o elemento a ser removido
			if (valor != numero)
			{
				fprintf (temp, "%d\n", valor);
			}
			else
			{
				cont++;
			}
		}

		//fechando os arquivos
		fclose (arq);
		fclose (temp);

		//copiando os elementos do arquivo tempor�rio para o original
		copiarArquivo("temp.txt", nomeArq);

		//apagando o arquivo tempor�rio do disco
		remove ("temp.txt");

		return cont;
	}
}

int copiarArquivo (char arqO[], char arqD[])
{
	//declara��o de vari�veis
	FILE *arq1, *arq2;
	char caracter;

	//tentando abrir os dois arquivos
	arq1=fopen(arqO, "r");
	arq2=fopen(arqD, "w");

	//testando se houve erro na abertura do arquivo
	if((arq1==NULL) || (arq2 == NULL))
	{
		fclose (arq1);
		fclose (arq2);

		return FALSE;
	}
	else
	{
		//lendo o conte�do do arquivo de origem
		while (fscanf (arq1, "%c", &caracter) != EOF)
		{
			//escrevendo os valores lidos no arquivo de destino
			fprintf (arq2, "%c", caracter);
		}

		//fechando os arquivos
		fclose (arq1);
		fclose (arq2);

		return TRUE;
	}
}
