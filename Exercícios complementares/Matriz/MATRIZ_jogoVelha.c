/*
Criando um tabuleiro de Jogo da Velha
Crie um tabuleiro de jogo da velha, usando uma matrizes de caracteres (char) 3x3, onde o
usuário pede o número da linha (1 até 3) e o da coluna (1 até 3). A cada vez que o usuário
entrar com esses dados, colocar um 'X' ou 'O' no local selecionado.

ERRO TOTAL!!!
*/

#include <stdio.h>
#define L 3
#define C 3

// Protótipo das funções
void inicializarMatriz(char m[L][C]);
void preencherMatriz(char m[L][C], int linha, int coluna, char jogada);
void exibirMatriz(char m[L][C]);

void main(){
    char matriz[L][C];
    char jogada;
    int i, linha, coluna;
    inicializarMatriz(matriz);
    for (i=0;i<=6;i++){
        printf("Insira a linha desejada: ");
        scanf("%d", &linha);
        printf("Insira a coluna desejada: ");
        scanf("%d", &coluna);
        printf("Insira a sua jogada [X/O]: ");
        fflush(stdin);
        scanf("%c", jogada);
        preencherMatriz(matriz, linha, coluna, jogada);
        exibirMatriz(matriz);
    }
}

void preencherMatriz(char m[L][C], int linha, int coluna, char jogada){
    int i, j;
    for (i=0;i<L;i++){
        for (j=0;j<C;j++){
            if (m[i]==linha && m[j]==coluna){
                m[i][j]=jogada;
            }
        }
    }
}

void exibirMatriz (char m[L][C]) {
	int i, j;
	printf ("\n");
	for (i=0;i<L;i++) {
		for (j=0;j<C;j++) {
			printf ("%3d ", m[i][j]);
		}
		printf ("\n");
	}
}

void inicializarMatriz(char m[L][C]){
    int i, j;
	for (i=0;i<L;i++) {
		for (j=0;j<C;j++) {
			m[i][j]=' ';
		}
	}
}
