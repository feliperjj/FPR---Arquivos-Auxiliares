#include <stdio.h>
int calculaTamanho (char vet[]){
	int i, cont=0;
	for (i=0;vet[i];i++){
		cont++;
	}
	return cont;	
}

void main(){
	char vet[30];
	int quant;
	printf("Insira um vetor: ");
	fflush(stdin);
	gets(vet);
	quant=calculaTamanho(vet);
	printf("O numero de caracteres no vetor eh: %d",quant);
}
