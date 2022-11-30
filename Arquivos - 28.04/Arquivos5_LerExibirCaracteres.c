/*
Exemplo 5:
    Ler o conteúdo de um arquivo e exibi-lo na tela, independente do tipo de informação que armazena.
	(neste caso, consideraremos que o arquivo é constituído por diversos caracteres)
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

//Protótipo das funções:
int lerExibir(char nome[]);

void main(){
    char nomeArquivo[30];
    printf("Insira o nome do arquivo: ");
    fflush(stdin);
    gets(nomeArquivo);
    if ( lerExibir(nomeArquivo) == TRUE ){
        printf("\nArquivo gerado com sucesso!!\n");
    } else {
        printf("\nArquivo gerado com erro!! =(\n");
    }
}

int lerExibir(char nome[]){
    char caractere;
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    if (arquivo == NULL){
        return FALSE;
    } else {
        while ( fscanf(arquivo, "%c", &caractere) != EOF ){
            printf("%c\n", caractere);
        }
        fclose(nome);
        return TRUE;
    }
}
