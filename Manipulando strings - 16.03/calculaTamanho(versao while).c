#include <stdio.h>
int calculaTamanho (char vet[]){
	int i;
	while (vet[i]){
		i++;
	}
	return i;	
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
