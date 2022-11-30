/*
QUESTÃO 03:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos).
*/

#include <stdio.h>

// Protótipo das funções:
int verificaLetras(char nome[]);

void main(){
    char nomeArquivo[30];
    int retorno;
    printf("Insira o nome do arquivo que deseja ler: ");
    fflush(stdin);
    gets(nomeArquivo);
    retorno = verificaLetras(nomeArquivo);
    if (retorno == -1)
	{
		printf ("\nErro na abertura do arquivo.");
	}
	else
	{
		printf ("\nForam encontradas %d letras no arquivo %s", retorno, nomeArquivo);
	}
}

int verificaLetras(char nome[]){
    char letra;
    int cont=0;
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    if (nome == NULL){
        return -1;
    } else {
        while ( fscanf (arquivo, "%c", &letra) != EOF ){
        	letra = toupper(letra);
            if ((letra >= 'A') && (letra <= 'Z'))
			{
				cont++;
			}
        }
        fclose(arquivo);
        return cont;
    }
}
