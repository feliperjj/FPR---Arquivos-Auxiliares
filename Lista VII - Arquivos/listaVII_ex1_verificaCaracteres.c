/*
QUESTÃO 01:
Desenvolver uma função que, dado um arquivo texto, verifique o número de caracteres no mesmo.
*/

#include <stdio.h>

// Protótipo das funções:
int verificaCaractere(char nome[]);

void main(){
    char nomeArquivo[30];
    int resultado;
    printf("Insira o nome do arquivo que deseja saber quantos caracteres possui: ");
    fflush(stdin);
    gets(nomeArquivo);
    resultado = verificaCaractere(nomeArquivo);
    switch (resultado){
		case -1: printf ("\nErro na abertura do arquivo.");
		         break;

		case 0:  printf ("\nArquivo vazio.");
		         break;

		default: printf ("\nHa %d caracteres no arquivo %s.", resultado, nomeArquivo);
	}
}

int verificaCaractere(char nome[]){
    char caracteres;
    int cont=0;
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    if (arquivo == NULL){
        return -1;
    } else {
        while( fscanf(arquivo, "%c", &caracteres) != EOF ){
            cont++;
        }
        fclose(arquivo);
        return cont;
    }
}
