/*
    EXEMPLO 01:
    Escrever em um arquivo numeros de 1 a n (aprimorei e coloquei em uma função).
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

void divisores(char nomeArq[], char nomeArq2[]) {
    FILE *arquivoOrig;
    FILE *arquivoNovo;
    int numero, i;
    int processados[10];
    int numerosJaAparece=0;
    int encontrado;
    

    arquivoOrig = fopen(nomeArq, "r");
	
    if (arquivoOrig == NULL) {
        printf("Erro ao abrir o arquivo %s.", nomeArq);
        return;
    }
		arquivoNovo = fopen(nomeArq2, "w");
    

    if (arquivoNovo == NULL) {
        printf("Erro ao criar o arquivo %s.", nomeArq2);
        fclose(arquivoOrig);
        return;
    }
    
  	
	

    while (fscanf(arquivoOrig, "%d", &numero) != EOF) {
        fprintf(arquivoNovo, "Divisores  %d: ", numero);
        	for(i=0;i<numerosJaAparece;i++){
    		
    		if(processados[i] == numero){
    			numerosJaAparece++;
    				
			}else if(numerosJaAparece<2){
				
				
				 for (i = 1; i <= numero; i++) {
            if ((numero % i == 0) && (numero != i-1)) {
                fprintf(arquivoNovo, "%d ", i);
            }
        }

        fprintf(arquivoNovo, "\n");
    }				
				
				
			}
    		

       

    fclose(arquivoOrig);
    fclose(arquivoNovo);
}
}

int main() {
    char nomeArqOriginal[20], nomeArqNovo[20];

    strcpy(nomeArqOriginal, "teste.txt");
    strcpy(nomeArqNovo, "novo.txt");

    divisores(nomeArqOriginal, nomeArqNovo);

    printf("O arquivo %s foi gerado com sucesso!\n", nomeArqNovo);

    return 0;
}


#include <stdio.h>

void main(){
    char nomeArquivo[30];
    int n;
    printf("Insira o valor de N: ");
    scanf("%d", &n);
    printf("Insira o nome do arquivo: ");
    fflush(stdin);
    gets(nomeArquivo);
    manipulaArquivo(nomeArquivo,n);
}

void manipulaArquivo (char nome[], int n){
    int i;
    FILE *arquivo;
    arquivo = fopen (nome, "w");
        if (arquivo != NULL) {
            for (i=1; i<=n; i++) {
                fprintf (arquivo, "%d\n", i);
            }

            printf("Arquivo gerado com sucesso");

            fclose(arquivo);
        }
        else {
            printf("Erro na abertura do arquivo");
        }
}

