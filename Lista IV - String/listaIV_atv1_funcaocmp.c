#include <stdio.h>
#define TAM 10

int comparaString(char vet1[], char vet2[]){
	int i;
	i=0;
	while ( (vet1[i]!='\0') && (vet2[i]!='\0') && (vet1[i]==vet2[i]) ) { /* for (i=0;(vet1[i]!='\0') && (vet2[i]!='\0') && (vet1[i]==vet2[i]);i++) */
		i++;
	}
	
	/*if ( (vet1[i]=='\0') && (vet2[i]=='\0') ){
		return 0;
	} else {
		if (vet1[i]>vet2[i]){
			return 1;
		} else {
			return -1;
		}
	}*/
	
	return vet1[i]-vet2[i];
	
}


int main(){
	char vet1[TAM], vet2[TAM], resultado=0;
	printf("Entre com o primeiro vetor: ");
	fflush(stdin);
	gets(vet1);
	printf("Entre com o segundo vetor: ");
	fflush(stdin);
	gets(vet2);
	fflush(stdin);
	resultado=comparaString(vet1,vet2);
	printf("O resultado da comparacao foi: %d\n", resultado);
	
	if (resultado>0){
		printf("A primeira palavra em ordem alfabetica eh: %s", vet2);
	} else {
		if (resultado<0){
			printf("A primeira palavra em ordem alfabetica eh: %s", vet1);
		} else {
				printf("Ambos são iguais");
		}
	}
}
