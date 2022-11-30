/*
	FPR - Professor Leonardo Vianna
	Turma: Manh�
	Data: 06/04/2022
	
	Lista de Exerc�cios IV (strings)
	
	Quest�o 03:
	Desenvolver uma fun��o que, dada uma string s, crie uma substring que 
	inicie na posi��o p de s e contenha n caracteres.
	
	Observa��es: 
		i. se p e/ou n forem inv�lidos, a substring ser� vazia; 
		ii) se s n�o possuir n caracteres al�m de p, a substring a ser 
		criada come�ar� em p e terminar� no final de s.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//prot�tipos das fun��es
void substring (char s[], int p, int n, char sub[]);

//main
void main ()
{
	//declara��o de vari�veis
	char string[30], sub[30];

	//inicializando
	strcpy (string, "FUNDAMENTOS DE PROGRAMACAO");
	
	//exemplos de chamadas
	substring (string, 4, 10, sub);
	printf ("Chamada 1 - sub: %s\n\n", sub);

	substring (string, -4, 8, sub);
	printf ("Chamada 2 - sub: %s\n\n", sub);

	substring (string, 8, 40, sub);
	printf ("Chamada 3 - sub: %s\n\n", sub);

	substring (string, 20, 10, sub);
	printf ("Chamada 4 - sub: %s\n\n", sub);
}

//implementa��o das fun��es
void substring (char s[], int p, int n, char sub[])
{
	//declara��o de vari�veis
	int i, j, tamanho = strlen(s);
	
	//testando se 'p' ou 'n' s�o inv�lidos
	if ((p<0) || (p>=tamanho) || (n<=0) || (n>tamanho))
	{
		//retornar substring vazia
		strcpy (sub, "");   //ou:   sub[0] = '\0';
	}
	else
	{
		for (i=p,j=0;(j<n)&&(i<tamanho);i++,j++)
		{
			sub[j] = s[i];
		}
	
		sub[j] = '\0';
	}
}
