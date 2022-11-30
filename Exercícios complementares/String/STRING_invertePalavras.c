/*
Altera a própria string str de modo que ela fica invertida.
Exemplo: Se inicialmente temos:
    str="PAMELA SILVA", no final teremos:
    "AVLIS ALEMAP" em str.
*/

#include <stdio.h>
#include <string.h>

// Protótipo das funções
void inverteString(char str[]);

void main(){
    char palavra[30];
    printf("Insira a palavra: ");
    fflush(stdin);
    gets(palavra);
    inverteString(palavra);
}

void inverteString(char str[]){
    int i=0, j, k, tamanho;
    char vetAux[30];
    tamanho=strlen(str);
    for (i=0, j=tamanho-1;j>=0;i++,j--){
        vetAux[i]=str[j];
    }
    vetAux[i]='\0';
    printf("\n\nINVERSO:\n\n%s",vetAux);
}
