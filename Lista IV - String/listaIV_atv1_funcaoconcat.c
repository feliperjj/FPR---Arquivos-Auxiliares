#include <stdio.h>
#define TAM1 5
#define TAM2 10

void concatena(char vet1[], char vet2[], char vet3[]){
	int i=0,j=0;
	while (i<=strlen(vet1)){
        vet3[i]=vet1[i];
        j=i;
        i++;
    }
    i=0;
    while (j<=strlen(vet3)){
        vet3[j]=vet2[i];
        i++;
        j++;
    }
    
    /*De forma mais simples:
	int i, j;
	i=quantCaracteres(string1); (Fun��o que foi feita na aula do dia 16/03, conferir no caderno e na pasta do dia.)
	for (j=0;string2!='\0';j++){
		string1[i]=string2[j];
		i++;
	}
	string1[i]='\0';
	
	EXPLICA��O: O i ir� ter o valor do tamanho da primeira string, indo at� o '\0'. Da� ent�o, o j ir� percorrer a segunda string, do 0 at� o seu final. 
	Nesse ponto, o final da primeira string ir� receber cada caracter da segunda string, indo at� antes do '\0'. Ap�s o for, ser� necess�rio dar fim a string,
	printando o '\0' no ultimo indice.
	 */
}


int main(){
	char vet1[TAM1], vet2[TAM1], vet3[TAM2];
	printf("Entre com o primeiro vetor: ");
	fflush(stdin);
	gets(vet1);
	printf("Entre com o segundo vetor: ");
	fflush(stdin);
	gets(vet2);
	fflush(stdin);
	concatena(vet1,vet2,vet3);
	printf("O resultado concatenado foi: %s",vet3);
}
