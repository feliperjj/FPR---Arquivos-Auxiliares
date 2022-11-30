#include <stdio.h>
#define TAM 30

char palindromo(char vet1[]){
	int i,j, tamanho;
	char result;
	tamanho=strlen(vet1);
	for (i=0,j=tamanho-1;i<j;i++,j--){
        if (vet1[i]==vet1[j]){          // if (vet1[i] != vet2 [i]){ 
            result='V';                 //     result='F'
        } else {                        //}
            result='F';
        }
	}

    return result;
}

int main(){
	char vet1[TAM], resposta;
	printf("Entre com a palavra: ");
	fflush(stdin);
	gets(vet1);
	resposta=palindromo(vet1);
	printf("Resposta [V/F]: %c",resposta);
}

