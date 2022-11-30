/*
        EXEMPLO 06:
        Copiar um arquivo para outro
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

// Protótipo das funções
int copiarArquivos(char nomeA[], char nomeB[]);

void main(){
    char nomeArquivoCopy[30];
    char nomeArquivoPaste[30];
    printf("Insira o nome do arquivo que deseja copiar: ");
    fflush(stdin);
    gets(nomeArquivoCopy);
    printf("Insira o nome do novo arquivo que deseja criar: ");
    fflush(stdin);
    gets(nomeArquivoPaste);
    if ( copiarArquivos(nomeArquivoCopy, nomeArquivoPaste) == TRUE ){
        printf("----------- ARQUIVO GERADO COM SUCESSO =) -----------");
    } else {
        printf("----------- ARQUIVO NÃO GERADO COM SUCESSO =( -----------");
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
