/*
    EXEMPLO 01:
    Escrever em um arquivo numeros de 1 a n (aprimorei e coloquei em uma função).
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

void main(){
    char nomeArquivo[30];
    int n, resultado;
    printf("Insira o valor de N: ");
    scanf("%d", &n);
    printf("Insira o nome do arquivo: ");
    fflush(stdin);
    gets(nomeArquivo);
    resultado = manipulaArquivo(nomeArquivo,n);
    if (resultado == TRUE){
        printf("Arquivo gerado com sucesso");
    } else {
        printf("Erro na abertura do arquivo");
    }
}

int manipulaArquivo (char nome[], int n){
    int i;
    FILE *arquivo;
    arquivo = fopen (nome, "w");
        if (arquivo != NULL) {
            for (i=1; i<=n; i++) {
                fprintf (arquivo, "%d\n", i);
            }
            fclose(arquivo);
            return TRUE;
        }
        else {
            return FALSE;
        }
}

