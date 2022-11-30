/*
	FAETERJ-Rio
	FPR - Manhã
	Prova a compor a AV1 (Parte I)
	Data: 05/05/2022
	
	Questão 02 [2,5 pontos]:
	Implementar uma função que, dada uma string s, determine a 
	quantidade de caracteres distintos em s.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos de funções
int questao02 (char s[]);

//main
void main ()
{
	//declaração de variáveis
	char string[20];
	int quant;
	
	//lendo a string
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (string);
	
	//chamando a função
	quant = questao02 (string);
	
	//exibindo o resultado
	printf ("\nA string %s possui %d caracteres distintos.", string, quant);
}

//implementação das funções
int questao02 (char s[])
{
	int i, j, tamanho, contDiferente=0, contIguais=0, vetAux[20];
	tamanho=strlen(s);
	for (i=1,j=tamanho-1;i<=tamanho;j--,i++){
		if (s[i]==s[j]){
			vetAux[i]=s[i];
			contIguais++;
		} else {
			if (s[i]==vetAux[i]){
				contIguais++;
			} else {
				contDiferente++;
			}
		}
	}
	return contDiferente;
}
