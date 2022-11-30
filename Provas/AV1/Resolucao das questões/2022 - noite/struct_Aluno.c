/*
Considere a exist�ncia do tipo TAluno contendo as
seguintes informa��es sobre um aluno: nome, nota na
AV1, nota na AV2, m�dia e situa��o.
Dado, portanto, um vetor do tipo TAluno, contendo
quant posi��es, fazer uma fun��o que verifique se o
vetor est� ordenado, conforme os seguintes crit�rios:
1. As m�dias devem estar ordenadas de forma
decrescente;
2. No caso de m�dias iguais, os respectivos nomes
dos alunos devem estar ordenados
crescentemente.
Caso o vetor esteja ordenado conforme regras citadas
acima, a fun��o dever� retornar a constante TRUE;
caso contr�rio, FALSE.
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define QUANT 4

typedef struct{
    char nome[30];
    float av1, av2, media;
    char situacao[10];
} TAluno;

// Prot�tipo das fun��es
int verificaOrdem( TAluno turma[] );
void exibir( TAluno turma[] );
void preenche( TAluno turma[] );

void main(){
    TAluno turma[QUANT];
    int retorno;
    preenche(turma);
    printf("\n---------EXIBINDO O VETOR----------");
    exibir(turma);
    retorno = verificaOrdem(turma);
    printf("\n---------EXIBINDO RESULTADO DA VERIFICACAO----------\n");
    if (retorno == TRUE){
        printf("\n\nO vetor esta organizado corretamente.\n\n ");
    } else {
        printf("\n\nO vetor nao esta organizado corretamente.\n\n ");
    }
}

void preenche(TAluno turma[]){
    //1� Aluno
	strcpy (turma[0].nome, "Vitoria");
	strcpy (turma[0].situacao, "APROVADO");
	turma[0].av1 = 8.0;
	turma[0].av2 = 7.0;
	turma[0].media = 7.5;

	//2� Aluno
	strcpy (turma[1].nome, "Marcos");
	strcpy (turma[1].situacao, "REPROVADO");
	turma[1].av1 = 3.0;
	turma[1].av2 = 6.0;
	turma[1].media = 4.5;

	//3� Aluno
	strcpy (turma[2].nome, "Maria");
	strcpy (turma[2].situacao, "Aprovado");
	turma[2].av1 = 7.0;
	turma[2].av2 = 8.0;
	turma[2].media = 7.5;

	//4� Aluno
	strcpy (turma[3].nome, "Kaua");
	strcpy (turma[3].situacao, "Aprovado");
	turma[3].av1 = 6.0;
	turma[3].av2 = 6.0;
	turma[3].media = 6.0;


}

void exibir(TAluno turma[]){
    int i;
    for(i=0;i<QUANT;i++){
        printf ("\n\nNome: %s\n", turma[i].nome);
		printf ("AV1: %.1f  -  AV2: %.1f\n", turma[i].av1, turma[i].av2);
		printf ("Media: %.1f (%s)\n", turma[i].media, turma[i].situacao);
    }
}


int verificaOrdem( TAluno turma[] ){
    int i, verifica;
    for (i=0;i<=QUANT;i++){
        if(turma[i].media>turma[i+1].media){
            verifica = TRUE;
        } else {
            if (turma[i].media==turma[i+1].media){
                if ( strcmp(turma[i].nome,turma[i+1].nome) < 0 ){
                    verifica = TRUE;
                }
            } else {
                verifica = FALSE;
            }
        }
    }

    return verifica;
}

