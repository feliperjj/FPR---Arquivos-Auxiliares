/*
QUESTÃO 04:
Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.
*/

#include <stdio.h>

// Protótipo das funções 
int verificaOrdem (char nome[]);

void main(){
	char nomeArquivo[30];
	int retorno;
	printf("Insira o nome do arquivo de inteiros que deseja ler: ");
	fflush(stdin);
	gets(nomeArquivo);
	retorno = verificaOrdem(nomeArquivo);
	switch (retorno)
	{
		case -1: printf ("\nErro na abertura do arquivo.");
		         break;
		         
		case 0:  printf ("\nOs elementos do arquivo %s nao estao ordenados crescentemente.", nomeArquivo);
		         break;
		
		case 1:	 printf ("\nOs elementos do arquivo %s estao ordenados crescentemente.", nomeArquivo);
	}
}

int verificaOrdem (char nome[]){
	FILE *arquivo;
	float maior, menor;
	arquivo = fopen(nome, "r");
	if (arquivo == NULL){
		fclose(arquivo);
		return -1;
	} else {
		fscanf (arquivo, "%f", &menor); //Lendo o primeiro valor do arquivo;
		while  (fscanf(arquivo, "%f", &maior) != EOF ){
			if (menor>maior){
				return 0;
			} else {
				menor=maior;
			}
		}
		fclose (arquivo);
		return 1;
	}
}
