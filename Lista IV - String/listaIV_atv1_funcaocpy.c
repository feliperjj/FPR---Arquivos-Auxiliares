#include <stdio.h>
#define TAM 10

void copia(char vet1[], char vet2[]){
	int i;
	//Para melhorar performace, seria melhor colocar a função strlen em uma variável, como por exemplo: 
	/* int tamanho=strlen(string) */
	for (i=0;i<=strlen(vet1);i++){ //se colocar i<strlen(s1),  seria necessário colocar o "\o' no ultimo indice
			vet2[i]= vet1[i];
			//Caso não usasse o strlen, teria que colocar o '\0' no ultimo indice, assim ficaria:
			/* for (i=0;vet2[i]!='\0';i++){
			vet2[i]=vet1[i];
			}
			vet2[i]='\o'; */
	}
}

int main(){
	char vet1[TAM], vet2[TAM];
	printf("Entre com o primeiro vetor: ");
	fflush(stdin);
	gets(vet1);
	printf("Entre com o segundo vetor: ");
	fflush(stdin);
	gets(vet2);
	copia(vet1,vet2);
	printf("O vetor copiado foi: %s",vet1);
}
