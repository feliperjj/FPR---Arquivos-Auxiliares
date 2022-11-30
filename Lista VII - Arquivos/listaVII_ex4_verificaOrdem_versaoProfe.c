/*
	FAETERJ-Rio
	FPR - 2022/1
	Data: 30/04/2022
	
	Lista de Exerc�cios VII (Arquivos)
	
	Quest�o 04:
	Desenvolver uma fun��o que, dado um arquivo texto contendo n�meros, determine se 
	estes encontram-se ordenados crescentemente.
*/

//importa��o de bibliotecas
#include <stdio.h>

//prot�tipos das fun��es
int verificarOrdenacao (char nomeArq[]);

//main
void main ()
{
	//declara��o de arquivos
	char nomeArquivo[30];
	int retorno;
		
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo: ");
	fflush (stdin);
	gets (nomeArquivo);
	
	//chamando a fun��o
	retorno = verificarOrdenacao (nomeArquivo);
	
	//exibindo o resultado
	switch (retorno)
	{
		case -1: printf ("\nErro na abertura do arquivo.");
		         break;
		         
		case 0:  printf ("\nOs elementos do arquivo %s nao estao ordenados crescentemente.", nomeArquivo);
		         break;
		
		case 1:	 printf ("\nOs elementos do arquivo %s estao ordenados crescentemente.", nomeArquivo);
	}
}

//implementa��o das fun��es
int verificarOrdenacao (char nomeArq[])
{
	//declara��o de vari�veis
	FILE *arq;
	float menor, maior;
	
	//abrindo o arquivo
	arq = fopen (nomeArq, "r");
	
	//testando se houve sucesso na abertura ou n�o
	if (arq == NULL)
	{
		return -1;	//sinalizando que n�o foi poss�vel abrir o arquivo
	}
	else
	{
		//lendo o primeiro valor do arquivo
		fscanf (arq, "%f", &menor);
		
		//lendo os demais elementos do arquivo 
		while (fscanf (arq, "%f", &maior) != EOF)
		{			
			//verificando se os dois n�meros est�o desordenados
			if (menor > maior)
			{
				//fechando o arquivo
				fclose (arq);
				
				//retornando 0 para representar que o arquivo n�o est� ordenado crescentemente
				return 0;
			}
			else
			{
				//atualizando o menor para que a pr�xima compara��o seja poss�vel
				menor = maior;				
			}
		}			
		
		//fechando o arquivo
		fclose (arq);
		
		//retornando 1 para representar que o arquivo est� ordenado crescentemente
		return 1;
	}	
}
