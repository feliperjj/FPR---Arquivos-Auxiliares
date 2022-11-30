/*
	FAETERJ-Rio
	FPR - Manh�
	Prova a compor a AV1 (Parte II)
	Data: 11/05/2022
		
	Quest�o 04 [2,5 pontos]:
	Implementar uma fun��o que, dado um arquivo texto A contendo 
	n�meros inteiros,  crie um novo arquivo, B, com os mesmos 
	valores que est�o em A, por�m sem repeti��o de elementos.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//prot�tipos de fun��es
int questao04 (char nomeArq1[], char nomeArq2[]);

//main
void main ()
{
	//declara��o de vari�veis
	char nomeArquivo1[20], nomeArquivo2[20];
	
	//lendo o nome do primeiro arquivo
	printf ("Entre com o nome do primeiro arquivo: ");
	fflush (stdin);
	gets (nomeArquivo1);

	//lendo o nome do segundo arquivo
	printf ("Entre com o nome do segundo arquivo: ");
	fflush (stdin);
	gets (nomeArquivo2);
		
	//chamando a fun��o
	if (questao04 (nomeArquivo1, nomeArquivo2) == TRUE)
	{
		printf ("Arquivo gerado com sucesso!");
	}
	else
	{
		printf ("Erro na abertura dos arquivos!");
	}
}

//implementa��o das fun��es
int questao04 (char nomeArq1[], char nomeArq2[])
{
	FILE *arquivo1, *arquivo2;
	int sair, maior, numero, ultimo = 999;
	arquivo1 = fopen (nomeArq1, "r");
	arquivo2 = fopen (nomeArq2, "w");
	if ((arquivo1 == NULL) || (arquivo2 == NULL)) {
		fclose (arquivo1);
		fclose (arquivo2);
		return FALSE;
	}
	else{
			do{
			rewind (arquivo1);
			maior = 0;
			sair = TRUE;
			while (fscanf (arquivo1, "%d", &numero) != EOF){
				if ((numero < ultimo) && (numero > maior)) {				 
					maior = numero;
					sair = FALSE;
				}
			}
			if (sair == FALSE)
			{
				fprintf (arquivo2, "%d\n", maior);
				ultimo = maior;
			}
		}
		while (sair == FALSE);

		//fechando os arquivos
		fclose (arquivo1);
		fclose (arquivo2);

		return TRUE;
	}
}
