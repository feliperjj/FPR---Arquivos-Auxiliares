/*
Criar uma função que transforme todos os caracteres em maiusculos
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main(){
    char stringo[20];
    printf("Insira uma palavra: ");
    fflush(stdin);
    gets(stringo);
    printf("\nPalavra original: %s", stringo);
    modificaPalavra(stringo);
    printf("\nPalavra modificada: %s", stringo);
}

void modificaPalavra(char palavra[]){
    int i, tamanho;
    tamanho= strlen(palavra);
    for (i=0;i<=tamanho;i++){
        palavra[i]=toupper(palavra[i]);
    }
}
