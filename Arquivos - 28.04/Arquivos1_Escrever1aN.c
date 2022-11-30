/*
    EXEMPLO 01:
    Escrever em um arquivo numeros de 1 a n (aprimorei e coloquei em uma função).
*/

#include <stdio.h>

void main(){
    char nomeArquivo[30];
    int n;
    printf("Insira o valor de N: ");
    scanf("%d", &n);
    printf("Insira o nome do arquivo: ");
    fflush(stdin);
    gets(nomeArquivo);
    manipulaArquivo(nomeArquivo,n);
}

void manipulaArquivo (char nome[], int n){
    int i;
    FILE *arquivo;
    arquivo = fopen (nome, "w");
        if (arquivo != NULL) {
            for (i=1; i<=n; i++) {
                fprintf (arquivo, "%d\n", i);
            }

            printf("Arquivo gerado com sucesso");

            fclose(arquivo);
        }
        else {
            printf("Erro na abertura do arquivo");
        }
}

