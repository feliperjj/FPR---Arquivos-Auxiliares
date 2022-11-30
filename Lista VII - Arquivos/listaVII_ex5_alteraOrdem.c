/*
QUESTÃO 05:
Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição.
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

// Protótipo das funções
int gerarArquivoOrdenado (char nomeArqA[], char nomeArqB[]);

void main(){
	char nomeArquivo1[30];
	char nomeArquivo2[30];
	int retorno;
	printf("Insira o nome do arquivo de inteiros que deseja ler: ");
	fflush(stdin);
	gets(nomeArquivo1);
	printf("Insira o nome do arquivo que deseja criar: ");
	fflush(stdin);
	gets(nomeArquivo2);
	retorno = gerarArquivoOrdenado(nomeArquivo1, nomeArquivo2);
	if (retorno=FALSE){
        printf("\nArq. nao encontrado");
	} else {
        printf("Arq gerado com sucesso");
	}
}

int gerarArquivoOrdenado (char nomeArqA[], char nomeArqB[])
{
	FILE *arquivo1, *arquivo2;
	float maior, numero, ultimo = 99999;
	int sair;
	arquivo1 = fopen (nomeArqA, "r");
	arquivo2 = fopen (nomeArqB, "w");
	if ((arquivo1 == NULL) || (arquivo2 == NULL)) {
		fclose (arquivo1);
		fclose (arquivo2);
		return FALSE;
	} else {
		do {
			rewind (arquivo1);
			maior = -99999;
			sair = TRUE;
            while (fscanf (arquivo1, "%f", &numero) != EOF) {
				if ((numero < ultimo) && (numero > maior))
				{
					maior = numero;
                    sair = FALSE;
				}
			}
			if (sair == FALSE)
			{
				fprintf (arquivo2, "%.1f\n", maior);
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
