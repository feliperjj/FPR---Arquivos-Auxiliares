/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 03:
	Desenvolver uma fun��o que, dado um arquivo texto, verifique o n�mero de letras 
	existentes no mesmo (entendendo que no arquivo podem existir letras, algarismos 
	e s�mbolos).
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int quantidadeLetras (char nomeArq[]);

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
	quantidade = quantidadeLetras (nomeArquivo);
	
	//exibindo o resultado
	if (quantidade == -1)
	{
		printf ("\nErro na abertura do arquivo.");
	}
	else
	{
		printf ("\nForam encontradas %d letras no arquivo %s.", quantidade, nomeArquivo);
	}
}

//implementa��o das fun��es
int quantidadeLetras (char nomeArq[])
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
			//jogando o caracter lido para mai�sculo
			caracter = toupper (caracter);
			
			//verificando se o caracter lido � uma letra
			if ((caracter >= 'A') && (caracter <= 'Z'))
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
