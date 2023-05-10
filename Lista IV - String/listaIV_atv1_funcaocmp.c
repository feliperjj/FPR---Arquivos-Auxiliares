##include <stdio.h>
#include <string.h>

void divisores(char nomeArq[], char nomeArq2[]) {
    FILE *arquivoOrig;
    FILE *arquivoNovo;
    int numero, i;
    int processados[10];
    int numerosJaApareceu = 0;

    arquivoOrig = fopen(nomeArq, "r");

    if (arquivoOrig == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArq);
        return;
    }

    arquivoNovo = fopen(nomeArq2, "w");

    if (arquivoNovo == NULL) {
        printf("Erro ao criar o arquivo %s.\n", nomeArq2);
        fclose(arquivoOrig);
        return;
    }

    while (fscanf(arquivoOrig, "%d", &numero) != EOF) {
        int encontrado = 0;

        for (i = 0; i < numerosJaApareceu; i++) {
            if (processados[i] == numero) {
                encontrado = 1;
                break;
            }
        }

        if (encontrado) {
            continue;
        }

        fprintf(arquivoNovo, "Divisores de %d: ", numero);

        for (i = 1; i <= numero; i++) {
            if (numero % i == 0) {
                fprintf(arquivoNovo, "%d ", i);
            }
        }

        fprintf(arquivoNovo, "\n");

        processados[numerosJaApareceu] = numero;
        numerosJaApareceu++;
    }

    fclose(arquivoOrig);
    fclose(arquivoNovo);
}

int main() {
    char nomeArqOriginal[20], nomeArqNovo[20];

    strcpy(nomeArqOriginal, "teste.txt");
    strcpy(nomeArqNovo, "novo.txt");

    divisores(nomeArqOriginal, nomeArqNovo);

    printf("O arquivo %s foi gerado com sucesso!\n", nomeArqNovo);

    return 0;
}
 <stdio.h>
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
