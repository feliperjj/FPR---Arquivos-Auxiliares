/*
	FPR - Professor Leonardo Vianna
	Turma: Manh�
	Data: 06/04/2022
	
	Lista de Exerc�cios IV (strings)
	
	Quest�o 04:
	Implementar uma fun��o que remova todas as ocorr�ncias de determinado 
	caracter em uma string.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//prot�tipos das fun��es
void removerCaracteres (char s[], char ch);

//main
void main ()
{
	//declara��o de vari�veis
	char string[30];

	//inicializando
	strcpy (string, "FUNDAMENTOS DE PROGRAMACAO");
	
	//exemplo de chamada
	removerCaracteres (string, 'O');
	printf ("String apos a remocao da letra O: %s", string);
}

//implementa��o das fun��es
void removerCaracteres (char s[], char ch)
{
	//declara��o de vari�veis
	char aux[50];
	int i, j = 0;
	
	//copiando para 'aux' todos os caracteres diferentes de 'ch'
	for (i=0;i<strlen(s);i++)
	{
		//verificando se o caracter deve ser copiado para 'aux'
		if (s[i] != ch)
		{
			aux[j] = s[i];
			j++;
		}
	}
	
	//finalizando a string 'aux' com '\0'
	aux[j] = '\0';
	
	//copiando 'aux' para 's'
	strcpy (s, aux);
}
