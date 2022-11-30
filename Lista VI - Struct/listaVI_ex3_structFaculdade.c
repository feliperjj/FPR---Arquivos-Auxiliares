/*
Questão 03:

Determinada instituição de ensino armazena, sob a forma de vetores (de structs), as seguintes informações:

 Alunos: nome, matrícula;
 Disciplinas do curso: nome, código;
 Inscrições realizadas: matrícula do aluno, código da disciplina, semestre da inscrição (semestre/ano).

Pede-se o desenvolvimento de funções que realizem as seguintes operações:
    i. Exibir, para cada aluno, o total de inscrições já realizadas;

    ii. Dado um semestre, informar para cada disciplina o número de alunos inscritos.
*/

#include <stdio.h>
#include <string.h>
#define NUM_ALUNOS 5
#define NUM_DISCIPLINAS 4
#define NUM_INSCRICOES 10

typedef struct{
    int semestre;
    int ano;
} TSemestre;

typedef struct {
    char nome[30];
    int matricula;
} TAluno;

typedef struct {
    char nome[30];
    char codigo[5];
} TDisciplina;

typedef struct{
    int matricula;
    char codigo[5];
    TSemestre semestre;
} TInscricao;

//Protótipo das funções:

void exibirInscricoesAluno(TAluno aluno[], int quantAlunos, TInscricao inscricoes[], int quantInscricoes);
void exibirInscricoesSemestre(TDisciplina disciplinas[], int quantDisciplinas, TInscricao inscricoes[], int quantInscricoes, TSemestre semestre);

void preencherAlunos(TAluno aluno[]);
void preencherDisciplinas (TDisciplina disciplinas[]);
void preencherInscricoes (TInscricao inscricoes[]);

//Main

void main(){
    TAluno vetAluno[NUM_ALUNOS];
    TDisciplina vetDisciplina[NUM_DISCIPLINAS];
    TInscricao vetInscricao[NUM_INSCRICOES];
    TSemestre semestre;

    //Inicializando os vetores com os valores pré-definidos:

    preencherAlunos (vetAluno);
	preencherDisciplinas (vetDisciplina);
	preencherInscricoes (vetInscricao);

    //Exibir, para cada aluno o total de inscrições:
    exibirInscricoesAluno(vetAluno, NUM_ALUNOS, vetInscricao, NUM_INSCRICOES);

    //Exibir o numero de inscrições nas matérias por semestre
    printf("\nInsira o semestre: ");
    scanf("%d", &semestre.semestre);
    printf("\nInsira o ano: ");
    scanf("%d", &semestre.ano);
    exibirInscricoesSemestre(vetDisciplina, NUM_DISCIPLINAS, vetInscricao, NUM_INSCRICOES, semestre);
}

//Funções

void exibirInscricoesAluno(TAluno aluno[], int quantAlunos, TInscricao inscricoes[], int quantInscricoes){
	//declaração de variáveis
	int i, j, cont;
	printf ("\nNumero de inscricoes por aluno:\n\n");
	printf ("Aluno\t\tInscricoes\n");
	for (i=0;i<quantAlunos;i++) {
		cont = 0;
		// Percorrendo o vetor de inscrições para saber quantas foram feitas em nome do aluno atual (da posição i)
		for (j=0;j<quantInscricoes;j++) {
			if (aluno[i].matricula == inscricoes[j].matricula){
				cont++;
			}
		}
		printf ("%s\t\t%d\n", aluno[i].nome, cont);
	}
}

void exibirInscricoesSemestre(TDisciplina disciplinas[], int quantDisciplinas, TInscricao inscricoes[], int quantInscricoes, TSemestre semestre){
    int i, j, cont;
    printf ("\n\n\nNumero de inscricoes por disciplina no semestre %d/%d:\n\n", semestre.semestre, semestre.ano);
	printf ("Disciplina\t\t\t\t\tInscricoes\n");
    for (i=0;i<quantDisciplinas;i++){
        cont=0;
        for (j=0;j<quantInscricoes;j++){
            if (  (strcmp(disciplinas[i].codigo, inscricoes[j].codigo) ==0 ) &&
                  (inscricoes[j].semestre.semestre == semestre.semestre) &&
                  (inscricoes[j].semestre.ano == semestre.ano)) {
                        cont++;
                  }
        }

        printf ("%s\t\t\t%d\n", disciplinas[i].nome, cont);
    }
}

void preencherAlunos (TAluno alunos[]){
	//aluno 1
	strcpy (alunos[0].nome, "JOAO");
	alunos[0].matricula = 12345;

	//aluno 2
	strcpy (alunos[1].nome, "MARIA");
	alunos[1].matricula = 23456;

	//aluno 3
	strcpy (alunos[2].nome, "ANA");
	alunos[2].matricula = 34567;

	//aluno 4
	strcpy (alunos[3].nome, "PEDRO");
	alunos[3].matricula = 45678;

	//aluno 5
	strcpy (alunos[4].nome, "CLARA");
	alunos[4].matricula = 56789;
}

void preencherDisciplinas (TDisciplina disciplinas[]){
	//disciplina 1
	strcpy (disciplinas[0].nome, "ORGANIZACAO DE COMPUTADORES");
	strcpy (disciplinas[0].codigo, "1ORG");

	//disciplina 2
	strcpy (disciplinas[1].nome, "FUNDAMENTOS DE ALGORITMOS DE COMPUTACAO");
	strcpy (disciplinas[1].codigo, "1FAC");

	//disciplina 3
	strcpy (disciplinas[2].nome, "FUNDAMENTOS DE PROGRAMACAO");
	strcpy (disciplinas[2].codigo, "2FPR");

	//disciplina 4
	strcpy (disciplinas[3].nome, "ESTRUTURAS DE DADOS");
	strcpy (disciplinas[3].codigo, "3ESD");
}

void preencherInscricoes (TInscricao inscricoes[]){
	//inscrição 1
	inscricoes[0].matricula = 12345;
	strcpy (inscricoes[0].codigo, "1FAC");
	inscricoes[0].semestre.semestre = 1;
	inscricoes[0].semestre.ano = 2021;

	//inscrição 2
	inscricoes[1].matricula = 12345;
	strcpy (inscricoes[1].codigo, "1ORG");
	inscricoes[1].semestre.semestre = 1;
	inscricoes[1].semestre.ano = 2021;

	//inscrição 3
	inscricoes[2].matricula = 12345;
	strcpy (inscricoes[2].codigo, "2FPR");
	inscricoes[2].semestre.semestre = 2;
	inscricoes[2].semestre.ano = 2021;

	//inscrição 4
	inscricoes[3].matricula = 12345;
	strcpy (inscricoes[3].codigo, "3ESD");
	inscricoes[3].semestre.semestre = 1;
	inscricoes[3].semestre.ano = 2022;

	//inscrição 5
	inscricoes[4].matricula = 23456;
	strcpy (inscricoes[4].codigo, "1FAC");
	inscricoes[4].semestre.semestre = 2;
	inscricoes[4].semestre.ano = 2021;

	//inscrição 6
	inscricoes[5].matricula = 23456;
	strcpy (inscricoes[5].codigo, "1ORG");
	inscricoes[5].semestre.semestre = 2;
	inscricoes[5].semestre.ano = 2021;

	//inscrição 7
	inscricoes[6].matricula = 23456;
	strcpy (inscricoes[6].codigo, "2FPR");
	inscricoes[6].semestre.semestre = 1;
	inscricoes[6].semestre.ano = 2022;

	//inscrição 8
	inscricoes[7].matricula = 34567;
	strcpy (inscricoes[7].codigo, "1FAC");
	inscricoes[7].semestre.semestre = 2;
	inscricoes[7].semestre.ano = 2021;

	//inscrição 9
	inscricoes[8].matricula = 45678;
	strcpy (inscricoes[8].codigo, "1ORG");
	inscricoes[8].semestre.semestre = 1;
	inscricoes[8].semestre.ano = 2022;

	//inscrição 10
	inscricoes[9].matricula = 56789;
	strcpy (inscricoes[9].codigo, "2FPR");
	inscricoes[9].semestre.semestre = 1;
	inscricoes[9].semestre.ano = 2022;
}

