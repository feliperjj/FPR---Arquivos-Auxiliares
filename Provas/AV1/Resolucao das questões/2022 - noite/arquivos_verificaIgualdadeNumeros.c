/*
Pede-se uma função que, dados dois arquivos textos,
contendo números inteiros, determine se possuem os
mesmos valores, independente do número de
ocorrências de cada número nos arquivos
*/

#include<stdio.h>
#define TRUE 1
#define FALSE 2

//Protótipo das funções:
int verificaOcorrencia(char nome1[], char nome2[]);

void main(){
    char nome1[30];
    char nome2[30];
    int retorno, retorno2;
    printf("Insira o nome do primeiro arquivo: ");
    fflush(stdin);
    gets(nome1);

    printf("Insira o nome do segundo arquivo: ");
    fflush(stdin);
    gets(nome2);

    retorno = verificaOcorrencia(nome1,nome2);
    retorno2 = verificaOcorrencia(nome2, nome1);

    if ((retorno==TRUE) || (retorno2==TRUE)){
        printf("Arquivos iguais!!!");
    } else{
        printf("Arquivos nao iguais!!!");
    }
}

int verificaOcorrencia(char nome1[], char nome2[]){
    FILE *arquivo1;
    FILE *arquivo2;
    int numero1,numero2, retorno;
    arquivo1 = fopen(nome1,"r");
    arquivo2 = fopen(nome2,"r");
    if ( (arquivo1==NULL) || (arquivo2==NULL) ){
        fclose (arquivo1);
        fclose (arquivo2);
        return FALSE;
    } else {
        do{
            fscanf(arquivo2,"%d",&numero2);
            while( fscanf(arquivo1,"%d", &numero1) != EOF ){
                if (numero2 == numero1){
                    retorno= TRUE;
                } else {
                    retorno= FALSE;
                }
            }
        } while(!feof(arquivo2));
         fclose (arquivo1);
		 fclose (arquivo2);
		 return retorno;
    }
}

