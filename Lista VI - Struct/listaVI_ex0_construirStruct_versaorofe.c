/*
	FPR - Professor Leonardo Vianna
	Turma: Manh�
	Data: 14/04/2022

	Structs

	Exemplo: fazer um programa que armazene em um vetor de structs as informa��es (nome, av1, av2, media, situa��o)
	dos alunos de determinada turma.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de constantes
#define NUM_ALUNOS 5

//defini��o de tipos
typedef struct {
	char nome[30];
	float av1, av2, media;
	char situacao[10];
} TAluno;

//prot�tipos das fun��es
void leituraDadosAlunos (TAluno turma[], int quantidade);
void calcularMediaSituacao (TAluno turma[], int quantidade);
void exibirDadosAlunos (TAluno turma[], int quantidade);

//main
void main ()
{
	//declara��o de vari�veis
	TAluno turma[NUM_ALUNOS];

	//preenchendo o vetor com os dados dos alunos
	leituraDadosAlunos (turma, NUM_ALUNOS);

	//calculando a m�dia e a situa��o de cada aluno
	calcularMediaSituacao (turma, NUM_ALUNOS);

	//exibindo os dados de todos os alunos
	exibirDadosAlunos (turma, NUM_ALUNOS);
}

//implementa��o das fun��es
void leituraDadosAlunos (TAluno turma[], int quantidade)
{
	//declara��o de vari�veis
	int i;

	//percorrendo o vetor
	for (i=0;i<quantidade;i++)
	{
		//lendo o nome do aluno
		printf ("Nome: ");
		fflush (stdin);
		gets (turma[i].nome);

		//lendo o valor da av1 do aluno
		printf ("\nAV1: ");
		scanf ("%f", &turma[i].av1);

		//lendo o valor da av2 do aluno
		printf ("\nAV2: ");
		scanf ("%f", &turma[i].av2);
	}
}

void calcularMediaSituacao (TAluno turma[], int quantidade)
{
	//declara��o de vari�veis
	int i;

	//percorrendo o vetor
	for (i=0;i<quantidade;i++)
	{
		//calculando a m�dia do aluno atual
		turma[i].media = (turma[i].av1 + turma[i].av2)/2;

		//determinando a situa��o do aluno
		if (turma[i].media >= 6)
		{
			strcpy (turma[i].situacao, "APROVADO");
		}
		else
		{
			if (turma[i].media < 4)
			{
				strcpy (turma[i].situacao, "REPROVADO");
			}
			else
			{
				strcpy (turma[i].situacao, "AVF");
			}
		}
	}
}

void exibirDadosAlunos (TAluno turma[], int quantidade)
{
	//declara��o de vari�veis
	int i;

	//percorrendo o vetor
	for (i=0;i<quantidade;i++)
	{
		printf ("\n\nNome: %s\n", turma[i].nome);
		printf ("AV1: %.1f  -  AV2: %.1f\n", turma[i].av1, turma[i].av2);
		printf ("Media: %.1f (%s)\n", turma[i].media, turma[i].situacao);
	}
}

