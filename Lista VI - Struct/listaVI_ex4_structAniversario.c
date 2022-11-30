/*
QUESTÃO 04:
Suponha a existência de um vetor de tamanho TAM, cada posição armazenando o nome da pessoa e a sua data de aniversário (representada por um struct
do tipo TData, contendo os campos dia e mes). Pede-se o desenvolvimento das seguintes funções:

 Determinar a quantidade de pessoas que fazem aniversário no mês M;

 Exibir os nomes de todas pessoas que fazem aniversário entre as datas d1 e d2, ambas do tipo TData.

OBS: ESSA MINHA SOLUÇÃO APRESENTA UM PEQUENO ERRO DE LÓGICA NA PARTE DA DATA
*/

#include <stdio.h>
#define NUM_PESSOAS 5

typedef struct{
    int dia;
    int mes;
} TData;

typedef struct{
    char nome[30];
    TData aniversario;
} TPessoa;

// Protótipo das funções

int contAniversarioMes(TPessoa pessoas[], int quantPessoas, int mes);
void contAniversarioData(TPessoa pessoas[], int quantPessoas, int dataInicio, int dataFim, int mesInicio, int mesFim);

void preencherPessoas(TPessoa pessoas[]);

// Main

void main(){
    TPessoa vetPessoas[NUM_PESSOAS];
    int mes, contMes, diaInt, mesInt, diaFim, mesFim;

    preencherPessoas(vetPessoas);

    // Determinar o mês que deseja buscar:
    printf("\n---------------ENTRADAS-------------------\n");
    printf("\nInsira o mes que deseja buscar a quantidade de aniversariantes: ");
    scanf("%d", &mes);
    printf("\nInsira o dia do inicio do intervalo: ");
    scanf("%d", &diaInt);
    printf("\nInsira o mes do inicio do intervalo: ");
    scanf("%d", &mesInt);
    printf("\nInsira o dia do fim do intervalo: ");
    scanf("%d", &diaFim);
    printf("\nInsira o mes do fim do intervalo: ");
    scanf("%d", &mesFim);

    printf("\n-----------------SAIDAS---------------------\n");
    contMes=contAniversarioMes(vetPessoas, NUM_PESSOAS, mes);
    printf("\nA quantidade de pessoas que fazem aniversario no mes %d: %d", mes, contMes);
    printf("\n\nAniversariantes no intervalo de %d/%d ---- %d/%d: \n\n", diaInt, mesInt, diaFim, mesFim);
    contAniversarioData(vetPessoas, NUM_PESSOAS, diaInt, diaFim, mesInt, mesFim);
}

// Funções

void preencherPessoas(TPessoa pessoas[]){

    // Pessoa 1
    strcpy(pessoas[0].nome, "MARIA");
    pessoas[0].aniversario.dia = 02;
    pessoas[0].aniversario.mes = 12;

    // Pessoa 2
    strcpy(pessoas[1].nome, "JOANA");
    pessoas[1].aniversario.dia = 12;
    pessoas[1].aniversario.mes = 04;

    // Pessoa 3
    strcpy(pessoas[2].nome, "CLEBER");
    pessoas[2].aniversario.dia = 24;
    pessoas[2].aniversario.mes = 10;

    // Pessoa 4
    strcpy(pessoas[3].nome, "CELSO");
    pessoas[3].aniversario.dia = 27;
    pessoas[3].aniversario.mes = 12;

    // Pessoa 5
    strcpy(pessoas[4].nome, "NOAH");
    pessoas[4].aniversario.dia = 25;
    pessoas[4].aniversario.mes = 04;

}

int contAniversarioMes(TPessoa pessoas[], int quantPessoas, int mes){
    int i, cont=0;
    for (i=0;i<quantPessoas;i++){
        if (pessoas[i].aniversario.mes == mes){
            cont++;
        }
    }

    return cont;
}

void contAniversarioData(TPessoa pessoas[], int quantPessoas, int dataInicio, int dataFim, int mesInicio, int mesFim){
    int i;
    for (i=0;i<quantPessoas;i++){
        if ( (pessoas[i].aniversario.dia >= dataInicio) &&
             (pessoas[i].aniversario.dia <= dataFim) &&
             (pessoas[i].aniversario.mes >= mesInicio) &&
             (pessoas[i].aniversario.mes <= mesFim) ) {

                printf("NOME: %s\t\t\t\tDATA:%d/%d\n\n", pessoas[i].nome,pessoas[i].aniversario.dia,pessoas[i].aniversario.mes);
             }
    }
}
