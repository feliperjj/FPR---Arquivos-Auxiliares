/*
Crie uma função que recebe uma string e um caractere, e retorne o número de vezes que esse caractere aparece na string.
*/

#include <stdio.h>
#include <string.h>

//Protótipo
int contaCaractere(char palavra[], char caractere);

void main(){
    char palavra[20];
    char caractere;
    int resultado;
    printf("Insira uma palavra; ");
    fflush(stdin);
    gets(palavra);
    printf("Insira um caractere: ");
    fflush(stdin);
    scanf("%c", &caractere);
    resultado=contaCaractere(palavra, caractere);
    printf("A quantidade de caracteres %c na palava %s eh: %d", caractere, palavra, resultado);
}

int contaCaractere(char palavra[], char caractere){
    int i, cont=0, tamanho;
    tamanho = strlen(palavra);
    for (i=0;i<=tamanho;i++){
        if (palavra[i]==caractere){
            cont++;
        }
    }

    return cont;
}
