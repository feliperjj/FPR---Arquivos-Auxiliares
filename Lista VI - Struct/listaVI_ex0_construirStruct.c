/*
Considere a existência de um vetor no qual cada posição pode armazenar o nome do aluno, as notas de AV1 e AV2, sua média e a situação
(aprovado, reprovado ou em AVF). Pede-se:

a) A declaração do vetor, assim como de todos os tipos de dados necessários, caso existam;

b) Uma função que leia os dados de todos os alunos da turma;

c) Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como a sua situação;

d) Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba todos os alunos que estão nesta situação.
*/

#include <stdio.h>
#include <string.h>
#define NUM_ALUNOS 3

//Definição de tipos
typedef struct {
	char nome[30];
	float av1, av2, media;
	char situacao[10];
} TAluno;

void main(){
    //Declaração de variáveis
    TAluno turma[NUM_ALUNOS];

    //Preenchendo o vetor com os dados dos alunos
    preenche(turma,NUM_ALUNOS);

    //Calcular média e situação
    calcula(turma,NUM_ALUNOS);

    //Exibir dados de todos os alunos
    exibe(turma,NUM_ALUNOS);
}

void preenche(TAluno turma[], int quant){
    int i;
    for (i=0;i<quant;i++){
        printf ("\nInsira o nome: ");
		fflush (stdin);
		gets (turma[i].nome);

        printf("\nInsira a nota da AV1: ");
        scanf("%f", &turma[i].av1);

        printf("\nInsira a nota da AV2: ");
        scanf("%f",&turma[i].av2);
    }
}

void calcula(TAluno turma[], int quant){
    int i;
    for (i=0;i<quant;i++){
        turma[i].media= (turma[i].av1 + turma[i].av2)/2;
        if (turma[i].media>=6){
            strcpy(turma[i].situacao, "APROVADO");
        } else {
            if (turma[i].media<4){
                strcpy(turma[i].situacao, "REPROVADO");
            } else {
                strcpy(turma[i].situacao, "AVF");
            }
        }
    }
}

void exibe(TAluno turma[],int quant){
    int i;
    for(i=0;i<quant;i++){
        printf ("\n\nNome: %s\n", turma[i].nome);
		printf ("AV1: %.1f  -  AV2: %.1f\n", turma[i].av1, turma[i].av2);
		printf ("Media: %.1f (%s)\n", turma[i].media, turma[i].situacao);
    }
}
