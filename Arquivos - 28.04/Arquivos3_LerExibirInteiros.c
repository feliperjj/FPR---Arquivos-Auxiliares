/*
	Exemplo 4:
	Considerando um arquivo contendo números inteiros, desenvolver uma função que leia o
	conteúdo deste arquivo e o exiba na tela do console.
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

//protótipos das funções
int lerArquivo(char nome[]);

void main(){
    char nomeArquivo[30];
    printf("Insira o nome do arquivo: ");
    fflush(stdin);
    gets(nomeArquivo);
    if (lerArquivo (nomeArquivo) == TRUE) {
		printf("\nArquivo lido com sucesso!");
	} else {
		printf("\nErro na abertura do arquivo!");
	}
}

int lerArquivo(char nome[]){
    int numero;
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    if (arquivo == NULL){
        return FALSE;
    } else {
        while ( fscanf (arquivo, "%d" , &numero) != EOF ){ //EOF = End Of File
            printf("%d\n", numero);
        }
        fclose(nome);
        return TRUE;
    }
}
