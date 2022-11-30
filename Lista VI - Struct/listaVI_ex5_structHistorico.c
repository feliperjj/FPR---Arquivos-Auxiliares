/*
QUEST�O 05:
O hist�rico de um aluno � representado por um vetor de structs onde cada posi��o armazena o c�digo da disciplina cursada, semestre e ano
que a cumpriu e a m�dia final na disciplina. Implementar uma fun��o que exiba o hist�rico do aluno com o seguinte formato:

                                            NomeDisciplina1 (c�digo1) M�diaDisciplina1
                                            NomeDisciplina2 (c�digo2) M�diaDisciplina2
                                                                .
                                                                .
                                                                .

                                            NomeDisciplinaN (c�digoN) M�diaDisciplinaN
                                            Coeficiente de rendimento: CR

Observa��es:

1. Para obter os dados da disciplina, um outro vetor de structs deve ser consultado. Este, por sua vez, armazena para cada disciplina
do curso as seguintes informa��es: c�digo, nome e n�mero de cr�ditos;

2. O coeficiente de rendimento consiste em uma m�dia ponderada de todos os graus atribu�dos �s disciplinas cursadas, onde os
pesos s�o representados pelo n�mero de cr�ditos da disciplina;

3. Todos os dados em negrito apresentados no formato do hist�rico devem ser obtidos a partir dos vetores.
*/

#include <stdio.h>
#include <string.h>
#define QUANT 3
#define NUM 5

typedef struct {
    char codigo[5];
    char nome[30];
    int creditos;
} TDisciplina;

typedef struct {
    int semestre;
    int ano;
} TSemestre;

typedef struct {
    char codigoDisc[5];
    TSemestre semestre;
    float media;
} TCursou;

// Prot�tipo das fun��es

void exibirHistorico(TDisciplina disciplina[], TCursou cursou[], int quantDisciplinas, int quantCursadas);
int buscaDisciplina(TDisciplina disciplina[], int quantDisciplinas, char codigo[5]);
float calculaCR(TCursou cursou[], TDisciplina disciplina[], int quantCursadas, int quantDisciplinas);

void preencherDisciplinas(TDisciplina disciplinas[]);
void preencherAlunos(TCursou cursou[]);

// Main

void main(){
    TDisciplina vetDisciplinas[NUM];
    TCursou vetCursou[QUANT];
    preencherDisciplinas(vetDisciplinas);
    preencherAlunos(vetCursou);
    exibirHistorico(vetDisciplinas, vetCursou, NUM, QUANT);
}

// Fun��es

void preencherAlunos(TCursou cursou[]){

    //Disc 1
    strcpy(cursou[0].codigoDisc,"12345");
    cursou[0].semestre.semestre = 1;
    cursou[0].semestre.ano = 2022;
    cursou[0].media = 10.0;

    //Disc 2
    strcpy(cursou[1].codigoDisc,"76890");
    cursou[1].semestre.semestre = 1;
    cursou[1].semestre.ano = 2022;
    cursou[1].media = 5.0;

    //Disc 3
    strcpy(cursou[2].codigoDisc,"45810");
    cursou[2].semestre.semestre = 1;
    cursou[2].semestre.ano = 2022;
    cursou[2].media = 3.0;
}

void preencherDisciplinas(TDisciplina disciplinas[]){

    // Disciplina 1
    strcpy(disciplinas[0].codigo,"12345");
    strcpy(disciplinas[0].nome,"ALMO�AR");
    disciplinas[0].creditos = 3;

    // Disciplina 2
    strcpy(disciplinas[1].codigo,"23456");
    strcpy(disciplinas[1].nome,"DESCANSAR");
    disciplinas[1].creditos = 4;

    // Disciplina 3
    strcpy(disciplinas[2].codigo,"76890");
    strcpy(disciplinas[2].nome,"JOGAR");
    disciplinas[2].creditos = 2;

    // Disciplina 4
    strcpy(disciplinas[3].codigo,"40967");
    strcpy(disciplinas[3].nome,"BRINCAR");
    disciplinas[3].creditos = 4;

    // Disciplina 5
    strcpy(disciplinas[4].codigo,"45810");
    strcpy(disciplinas[4].nome,"AMAR");
    disciplinas[4].creditos = 1;
}

int buscaDisciplina(TDisciplina disciplina[], int quantDisciplinas, char codigo[5]){
    int i;
    for (i=0;i<quantDisciplinas;i++){
        if ( strcmp( disciplina[i].codigo, codigo ) == 0 ) {
            return 1;
        }
    }

    return -1;
}

void exibirHistorico(TDisciplina disciplina[], TCursou cursou[], int quantDisciplinas, int quantCursadas){
    int i, disc;
    float coeficiente;
    for (i=0;i<quantCursadas;i++){
        disc = buscaDisciplina(disciplina, NUM, cursou[i].codigoDisc);
        printf ("%s (%s)     %.1f\n", disciplina[disc].nome, cursou[i].codigoDisc, cursou[i].media);
    }

    coeficiente=calculaCR(cursou, disciplina, QUANT, NUM);
    printf ("Coeficiente de rendimento: %.1f", coeficiente);
}

float calculaCR(TCursou cursou[], TDisciplina disciplina[], int quantCursadas, int quantDisciplinas){
    int i, disc;
    float denominador = 0, numerador = 0, CR;
    for (i=0;i<quantCursadas;i++){
        disc = buscaDisciplina(disciplina, NUM, cursou[i].codigoDisc);
        denominador += cursou[i].media*disciplina[disc].creditos;
		numerador += disciplina[disc].creditos;
    }

    CR = denominador/numerador;
    return CR;

}
