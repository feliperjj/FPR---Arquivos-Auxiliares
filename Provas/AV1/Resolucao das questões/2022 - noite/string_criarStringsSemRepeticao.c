/*
Implementar uma função que, dadas duas strings s1 e
s2, crie uma nova string – s3 – contendo todos os
caracteres de s1 que não estejam em s2.
Nota: em s3, não devem existir caracteres repetido
*/

#include <stdio.h>
#include <string.h>

//Protótipo das funções
void organizaString(char s1[], char s2[], char s3[]);

void main(){
    char palavra1[20], palavra2[20], palavraGerada[40];

    printf("Insira a primeira palavra: ");
    fflush(stdin);
    gets(palavra1);

    printf("Insira a segunda palavra: ");
    fflush(stdin);
    gets(palavra2);

    organizaString(palavra1, palavra2, palavraGerada);
    printf("A palavra gerada foi: %s", palavraGerada);
}

void organizaString(char s1[], char s2[], char s3[]){
    int i, j;
    int resultado, tamanho, tamanho2, res;
    tamanho = strlen(s1);
    tamanho2 = strlen(s2);

    if (tamanho2>tamanho){
        tamanho=tamanho2;
    }

    for (i=0;i<=tamanho;i++){
        if ( s1[i]==s2[i] ){
            s3[i]=' ';
        } else {
            for (j=0;j<=tamanho;j++){
                if ((s3[j]==s2[j]) || (s3[j]==s3[i])){
                    s3[j]=' ';
                } else {
                    s3[i]=s1[i];
                }
            }
        }
    }
}

