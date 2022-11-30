#include <stdio.h>
#define TAM 30
/*A intenção era inverter a palavra e depois conferir se os vetores são iguais, ou seja, se possuem os mesmos algarismos.
Exemplo:
Tenet = vet1
Tenet= vet2 (após chamar a função e copiar o valor do vet1 inverso)
Como, um é o contrário do outro, o índice do vet1[i] será igual ao do vet2[i]
Caso não fosse:
Vitoria = vet1
airotiv = vet2
a e v são diferentes, então cairia no else e ele iria terminar o programa com F */

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

