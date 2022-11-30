/*
	FAETERJ-Rio
	FPR - Manh�
	Prova a compor a AV1 (Parte I)
	Data: 05/05/2022
	
	Quest�o 02 [2,5 pontos]:
	Implementar uma fun��o que, dada uma string s, determine a 
	quantidade de caracteres distintos em s.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//prot�tipos de fun��es
int questao02 (char s[]);

//main
void main ()
{
	//declara��o de vari�veis
	char string[20];
	int quant;
	
	//lendo a string
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (string);
	
	//chamando a fun��o
	quant = questao02 (string);
	
	//exibindo o resultado
	printf ("\nA string %s possui %d caracteres distintos.", string, quant);
}

//implementa��o das fun��es
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
