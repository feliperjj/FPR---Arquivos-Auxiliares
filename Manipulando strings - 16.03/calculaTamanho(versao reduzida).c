#include <stdio.h>
int calculaTamanho (char vet[]){
	int i;
	for (i=0;vet[i];i++); //Reduzimos tirando o contador, pois ele estav recebendo sempe o mesmo valor de i
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
