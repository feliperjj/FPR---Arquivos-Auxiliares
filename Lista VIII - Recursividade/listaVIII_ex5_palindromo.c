/*
Questão 05:
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.
*/

#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int palindromo(char s[]);
int palindromoAux(char s[], int inicio, int fim);

void main(){
	char palavra[30];
	
	printf("Entre com uma string: ");
	fflush(stdin);
	gets(palavra);
	
	if (palindromo(palavra) == TRUE){
		printf("\n A string %s eh um palindromo!", palavra);
	} else {
		printf("\n A palavra %s nao eh um palindromo!", palavra);
	}
}

int palindromo(char s[]){
	return palindromoAux(s, 0, strlen(s)-1);
}

int palindromoAux(char s[], int inicio, int fim){
	if (inicio<fim){
		if (s[inicio] != s[fim]){
			return FALSE;
		} else {
			return palindromoAux(s, inicio+1, fim-1);
		}
	} else {
		return TRUE;
	}
}
