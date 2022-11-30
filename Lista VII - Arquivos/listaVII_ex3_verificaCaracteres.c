/*
QUEST�O 03:
Desenvolver uma fun��o que, dado um arquivo
texto, verifique o n�mero de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e s�mbolos).
*/

#include <stdio.h>

// Prot�tipo das fun��es:
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
