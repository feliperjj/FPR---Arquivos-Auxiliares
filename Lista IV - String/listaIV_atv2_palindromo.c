#include <stdio.h>
#define TAM 30
/*A inten��o era inverter a palavra e depois conferir se os vetores s�o iguais, ou seja, se possuem os mesmos algarismos.
Exemplo:
Tenet = vet1
Tenet= vet2 (ap�s chamar a fun��o e copiar o valor do vet1 inverso)
Como, um � o contr�rio do outro, o �ndice do vet1[i] ser� igual ao do vet2[i]
Caso n�o fosse:
Vitoria = vet1
airotiv = vet2
a e v s�o diferentes, ent�o cairia no else e ele iria terminar o programa com F */

char palindromo(char vet1[], char vet2[]){
	int i,j, tamanho;
	char result;
	tamanho=strlen(vet1);
	for (i=0,j=tamanho-1;j>=0;j--,i++){
        vet2[i]=vet1[j];
	}
	vet2[i]='\0';

    for (i=0;i<=tamanho;i++){
        if (vet1[i] == vet2[i]){
            result='V';
        } else {
            result='F';
        }
    }
    return result;
}

int main(){
	char vet1[TAM], vet2[TAM], resposta;
	printf("Entre com a palavra: ");
	fflush(stdin);
	gets(vet1);
	resposta=palindromo(vet1, vet2);
	printf("Resposta [V/F]: %c",resposta);
}

