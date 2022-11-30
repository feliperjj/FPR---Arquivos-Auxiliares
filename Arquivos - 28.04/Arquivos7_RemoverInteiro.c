/*
    Exemplo 7:
    Desenvolver uma fun��o que removas todas as ocorr�ncias de um n�mero inteiro em determinado
	arquivo
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

// Prot�ripo das fun��es
int removeOcorrencia(char nome[], int numero);
int copiarArquivos(char nomeA[], char nomeB[]);

void main(){
    char nomeArquivo[30];
    int num, resultado;
    printf("Insira o nome do arquivo que deseja extrair as ocorrencias: ");
    fflush(stdin);
    gets(nomeArquivo);
    printf("Insira o numero inteiro que deseja remover do arquivo: ");
    scanf("%d", &num);
    resultado = removeOcorrencia(nomeArquivo, num);
    switch (resultado){
        case -1: printf ("Erro na abertura do arquivo!");
		         break;

		case  0: printf ("Elemento nao encontrado no arquivo!");
		         break;

		default: printf ("Foram feitas %d remocoes do valor %d", resultado, num);
    }
}

int removeOcorrencia(char nome[], int numero){
    int valor, cont=0;
    FILE *arquivo;
    FILE *temp;
    arquivo = fopen(nome, "r");
    temp = fopen("temp.txt", "w");
    if (arquivo == NULL){
        return -1;
    } else {
        while ( fscanf(arquivo, "%d", &valor) != EOF ){
            if (valor != numero){
                    fprintf(temp, "%d\n", valor);
            } else {
                cont++;
            }
        }
        fclose(arquivo);
        fclose(temp);
        copiarArquivos("temp.txt", nome);
        return cont;
    }
}

int copiarArquivos(char nomeA[], char nomeB[]){
    char caractere;
    FILE *arquivo1;
    FILE *arquivo2;
    arquivo1 = fopen(nomeA, "r");
    arquivo2 = fopen(nomeB, "w");
    if (arquivo1 == NULL){
        return FALSE;
    } else {
         while ( fscanf(arquivo1, "%c", &caractere) != EOF ){
            fprintf(arquivo2, "%c", caractere);
        }
        fclose(arquivo1);
        fclose(arquivo2);
        return TRUE;
    }
}
