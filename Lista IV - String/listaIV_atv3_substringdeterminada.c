#include <stdio.h>
#define TAM 50

void criaNova (char strPrim[], char strSub[], int pos, int num){
    int tamanho=strlen(strPrim), i, j;
    if (pos>tamanho || pos<0){
        for (i=0;i<tamanho;i++){
            strSub[i]=' ';
        }
        strSub[i]='\0';
    } else {
        if (pos>tamanho || pos<0){
            for (i=0;i<tamanho;i++){
            strSub[i]=' ';
            }
            strSub[i]='\0';
        } else {
            for (i=0,j=pos;i<=num;i++,j++){
            strSub[i]=strPrim[j];
            }
            strSub[i-1]='\0';
        }
    }
}

int main(){
    int p,n,i;
    char stringPrimaria[TAM], subString[TAM],resultado;
    printf("Insira a palavra: ");
    fflush(stdin);
    gets(stringPrimaria);
    printf("\nInsira a posicao que deseja iniciar a nova string: ");
    scanf("%d",&p);
    printf("\nInsira a quantidade de caracteres que deseja: ");
    scanf("%d",&n);
    //resultado=confere(p,n);
    //if (resultado==true){
    criaNova(stringPrimaria,subString,p,n);
    printf("\nA substring gerada: %s",subString);
    //}

}
