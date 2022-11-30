/*
QUESTÃO 02:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.
*/

#include <stdio.h>

// Protótipo das funções:
int verificaCaracteres(char nome[], char caracter);

void main(){
    char nomeArquivo[30];
    char caracter;
    int retorno;
    printf("Insira o nome do arquivo que deseja ler: ");
    fflush(stdin);
    gets(nomeArquivo);
    printf("Insira o caracter que deseja contar a ocorrencia no arquivo: ");
    fflush(stdin);
    scanf("%c", &caracter);
    retorno = verificaCaracteres(nomeArquivo, caracter);
    if (retorno == -1){
		printf ("\nErro na abertura do arquivo.");
	} else {
		printf ("\nForam encontradas %d ocorrencias do caracter %c no arquivo %s.", retorno, caracter, nomeArquivo);
	}
}

int verificaCaracteres(char nomeArq[], char ch){
    FILE *arquivo;
	int cont = 0;
	char caractere;
	arquivo = fopen (nomeArq, "r");
	if (arquivo == NULL) {
		return -1;
	} else {
		while (fscanf (arquivo, "%c", &caractere) != EOF) {
			if (caractere == ch) {
				cont++;
			}
		}
		fclose (arquivo);
		return cont;
	}
}
