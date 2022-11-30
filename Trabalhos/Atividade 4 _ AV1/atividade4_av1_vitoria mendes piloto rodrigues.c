/*

                                    ╔═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╗
                                            𝐓𝐑𝐀𝐁𝐀𝐋𝐇𝐎 4 - 𝐀𝐕𝟏

                                        𝐀𝐥𝐮𝐧𝐚: 𝐕𝐢𝐭𝐨𝐫𝐢𝐚 𝐏𝐢𝐥𝐨𝐭𝐨
                                        𝐃𝐬𝐢𝐜𝐢𝐩𝐥𝐢𝐧𝐚: 𝐅𝐏𝐑
                                        𝐏𝐫𝐨𝐟𝐞𝐬𝐬𝐨𝐫: 𝐋𝐞𝐨𝐧𝐚𝐫𝐝𝐨 𝐕𝐢𝐚𝐧𝐧𝐚
                                    ╚═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╝
𝐐𝐔𝐄𝐒𝐓𝐀𝐎:
Dado um arquivo texto e dois inteiros posA e  posB, desenvolver uma função que remova do arquivo o bloco de caracteres delimitados pelas
posições posA e posB.

Notas:
1. Suponha que o valor de posA é menor ou igual ao de posB;
2. Considere que o primeiro caracter do arquivo encontra-se na posição 0;
3. Se não existir a posição posA no arquivo, o seu conteúdo será preservado;
4. Se não existir a posição posB no arquivo, serão removidos todos os caracteres da posição posA ao final do arquivo.
*/

// Importação de bibliotecas
#include <stdio.h>

// Definição de constantes
#define TRUE 1
#define FALSE 0
#define TAM 30

// Protótipo das funções
int removerBloco (char nomeArq[], int posA, int posB);

void main(){
    char nomeArquivo[TAM];
    int posA, posB, retorno;
    printf("-------- PROGRAMA REMOVE BLOCOS DE PLAVRAS DE UM ARQUIVO ---------\n\n");
    printf("Insira o nome do arquivo: ");
    fflush(stdin);
	gets(nomeArquivo);
	printf("Insira o primeiro intervalo da posicao [0 para posicao inicial]: ");
	scanf("%d", &posA);
	printf("Insira o segundo intervalo da posicao: ");
	scanf("%d", &posB);
	retorno = removerBloco(nomeArquivo, posA, posB);
	if (retorno=FALSE){
        printf("\nArquivo nao encontrado");
	} else {
        printf("Arquivo gerado com sucesso");
	}
}

int removerBloco (char nomeArq[], int posA, int posB){
    int i=0;
    char texto[TAM];
    FILE *arquivo;
    FILE *temp;
    arquivo = fopen(nomeArq, "r");
    temp = fopen("temporario.txt", "w");
    if (arquivo == NULL){
        return -1;
    } else {
        while ( fscanf (arquivo, "%s", &texto) != EOF ){
            if(i<posA || i>posB){
				fprintf(temp, "%s\n", texto);
			}
			i++;
            }
        }
        fclose(arquivo);
        fclose(temp);
        copiarArquivos("temporario.txt", nomeArq);
        remove("temporario.txt");
        return i;
    }

int copiarArquivos(char nomeA[], char nomeB[]){
    char texto[30];
    FILE *arquivo1;
    FILE *arquivo2;
    arquivo1 = fopen(nomeA, "r");
    arquivo2 = fopen(nomeB, "w");
    if (arquivo1 == NULL){
        return FALSE;
    } else {
         while ( fscanf(arquivo1, "%s", &texto) != EOF ){
            fprintf(arquivo2, "%s\n", texto);
        }
        fclose(arquivo1);
        fclose(arquivo2);
        return TRUE;
    }
}


