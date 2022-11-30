#include <stdio.h>
#define TAM 20

void apagarLetra (char str[], char ltr){
    int i, tamanho=strlen(str);
    for (i=0;i<=tamanho;i++){
        if (str[i]==ltr){
            str[i]=' ';
        }
    }
}

int main(){
    char palavra[TAM], letra;
    printf("Insira uma palavra: ");
    gets(palavra);
    printf("Insira a letra que deseja omitir da palavra: ");
    scanf("%c", &letra);
    apagarLetra(palavra,letra);
    printf("A nova palavra gerada foi: %s",palavra);
}
