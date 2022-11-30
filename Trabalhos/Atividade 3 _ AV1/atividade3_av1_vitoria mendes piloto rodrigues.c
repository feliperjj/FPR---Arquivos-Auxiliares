/*

                                    ╔═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╗
                                            𝐓𝐑𝐀𝐁𝐀𝐋𝐇𝐎 3 - 𝐀𝐕𝟏

                                        𝐀𝐥𝐮𝐧𝐚: 𝐕𝐢𝐭𝐨𝐫𝐢𝐚 𝐏𝐢𝐥𝐨𝐭𝐨
                                        𝐃𝐬𝐢𝐜𝐢𝐩𝐥𝐢𝐧𝐚: 𝐅𝐏𝐑
                                        𝐏𝐫𝐨𝐟𝐞𝐬𝐬𝐨𝐫: 𝐋𝐞𝐨𝐧𝐚𝐫𝐝𝐨 𝐕𝐢𝐚𝐧𝐧𝐚
                                    ╚═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╝

𝐐𝐔𝐄𝐒𝐓𝐀𝐎:
Considere um vetor que, em cada posição, armazene os seguintes dados de um curso de graduação:
    Nome (por exemplo, Medicina, Engenharia, Direito, ...),
    Área (Humanas, Exatas, ...),
    Cidade na qual funciona e
    Quantidade de alunos matriculados no curso.

Desenvolver uma função que, dado um vetor nesses moldes, um código inteiro cod e uma string str, retorne a quantidade de alunos
associados aos parâmetros.

Se o código for igual a 1, str representará um curso e, portanto, a função deverá retornar a quantidade de alunos matriculados no curso
str, destacando que o mesmo curso pode encontrar-se em mais de uma posição do vetor (em cidades diferentes, por exemplo).

Por outro lado, se o código for 2, str representará uma área e, portanto, deverá ser retornado o total de alunos matriculados em cursos
daquela área.
*/

// Importação de bibliotecas
#include <stdio.h>
#include <string.h>

// Declaração de constantes
#define NUM_CURSOS 10

// Declaração de tipos
typedef struct{
    char nome[30];
    char area[15];
    char cidade[30];
    int quantAlunos;
} TCurso;

// Protótipo das funções
void preencherVetor (TCurso cr[]);
void maiusculo(char s1[], char s2[]);
void listaCursos (TCurso curso[], int quantidade);
void listaAreas (TCurso curso[], int quantidade);
int calculaQuantCurso (TCurso curso[], char str[], int quantidade);
int calculaQuantArea (TCurso curso[], char str[], int quantidade);
void exibeQuantCidade (TCurso curso[], int quantidade, char str[]);

// Main
void main(){
    TCurso cursos[NUM_CURSOS];
    int quantCursos = NUM_CURSOS;
    int codigo, quantidadeAlunos;
    char str[30], strAux[30];
    preencherVetor(cursos);
    printf("\n---- PROGRAMA BUSCA NUMERO DE ALUNOS POR CURSO/AREA ----\n\n");
    printf("-------- INSIRA O CODIGO PARA BUSCA [1 - CURSO | 2 - AREA]: ");
    scanf("%d",&codigo);
    if (codigo == 1){
        printf("\n\n-------- OPCOES DE CURSO A ESCOLHER: --------\n\n");
        listaCursos(cursos, quantCursos);
        printf("\n\n-------- INSIRA O NOME DO CURSO: ");
        fflush(stdin);
        gets(str);
        maiusculo(str,strAux);
        quantidadeAlunos = calculaQuantCurso (cursos, strAux, quantCursos);
        printf("\n\n-------- QUANTIDADE DE ALUNOS: %d\n", quantidadeAlunos);
        exibeQuantCidade (cursos, quantCursos, strAux);
    } else {
        printf("\n\n-------- OPCOES DE AREAS A ESCOLHER: --------\n\n");
        listaAreas(cursos, quantCursos);
        printf("\n\n-------- INSIRA O NOME DA AREA: ");
        fflush(stdin);
        gets(str);
        maiusculo(str,strAux);
        quantidadeAlunos = calculaQuantArea (cursos, strAux, quantCursos);
        printf("\n\n-------- QUANTIDADE DE ALUNOS: %d\n", quantidadeAlunos);
    }
}

// Preenchendo o vetor
void preencherVetor (TCurso cr[]){
    // 1° Curso:
    strcpy (cr[0].nome, "DIREITO");
    strcpy (cr[0].area, "HUMANAS");
    strcpy (cr[0].cidade, "RIO DE JANEIRO");
    cr[0].quantAlunos = 50;

    // 2° Curso:
    strcpy (cr[1].nome, "CIENCIAS BIOLOGICAS");
    strcpy (cr[1].area, "BIOLOGICAS");
    strcpy (cr[1].cidade, "RIO DE JANEIRO");
    cr[1].quantAlunos = 100;

    // 3° Curso:
    strcpy (cr[2].nome, "CIENCIAS DA COMPUTACAO");
    strcpy (cr[2].area, "EXATAS");
    strcpy (cr[2].cidade, "RIO DE JANEIRO");
    cr[2].quantAlunos = 100;

    // 4° Curso:
    strcpy (cr[3].nome, "PEDAGOGIA");
    strcpy (cr[3].area, "HUMANAS");
    strcpy (cr[3].cidade, "SAO PAULO");
    cr[3].quantAlunos = 100;

    // 5° Curso:
    strcpy (cr[4].nome, "DIREITO");
    strcpy (cr[4].area, "HUMANAS");
    strcpy (cr[4].cidade, "GOIANIA");
    cr[4].quantAlunos = 100;

    // 6° Curso:
    strcpy (cr[5].nome, "ARTES");
    strcpy (cr[5].area, "ARTISTICAS");
    strcpy (cr[5].cidade, "FORTALEZA");
    cr[5].quantAlunos = 1000;

    // 7° Curso:
    strcpy (cr[6].nome, "ENGENHARIA ELETRICA");
    strcpy (cr[6].area, "EXATAS");
    strcpy (cr[6].cidade, "PORTO ALEGRE");
    cr[6].quantAlunos = 100;

    // 8° Curso:
    strcpy (cr[7].nome, "ENGENHARIA MECANICA");
    strcpy (cr[7].area, "EXATAS");
    strcpy (cr[7].cidade, "RIO DE JANEIRO");
    cr[7].quantAlunos = 100;

    // 9° Curso:
    strcpy (cr[8].nome, "MEDICINA");
    strcpy (cr[8].area, "BIOLOGICAS");
    strcpy (cr[8].cidade, "RIO DE JANEIRO");
    cr[8].quantAlunos = 100;

    // 10° Curso:
    strcpy (cr[9].nome, "QUIMICA");
    strcpy (cr[9].area, "BIOLOGICAS");
    strcpy (cr[9].cidade, "MANAUS");
    cr[9].quantAlunos = 100;
}

// Listar opções na tela para facilitar a escolha do usuário e a busca
void listaCursos (TCurso curso[], int quantidade){
    int i;
    for (i=0;i<quantidade;i++){
        printf("1 - %s\n", curso[i].nome);
    }
}

void listaAreas (TCurso curso[], int quantidade){
     printf("2 - EXATAS\n");
     printf("2 - HUMANAS\n");
     printf("2 - ARTISTICAS\n");
     printf("2 - LINGUAGENS\n");
}

// Função calcular quantidade de alunos por curso:
int calculaQuantCurso (TCurso curso[], char str[], int quantidade){
    int i, count=0;
    for (i=0;i<quantidade;i++){
        if ( strcmp(curso[i].nome, str) == 0 ){
            count= count + curso[i].quantAlunos;
        }
    }

    return count;
}

// Função calcular quantidade de alunos por área
int calculaQuantArea (TCurso curso[], char str[], int quantidade){
    int i, count=0;
    for (i=0;i<quantidade;i++){
        if ( strcmp(curso[i].area, str) == 0 ){
            count= count + curso[i].quantAlunos;
        }
    }

    return count;
}

// Função exibir a quantidade de alunos em cada cidade:
void exibeQuantCidade (TCurso curso[], int quantidade, char str[]){
    int i, contSP=0, contRJ=0, contMN=0, contPA=0, contFO=0, contGO=0;
    for (i=0;i<quantidade;i++){
        if ( strcmp(curso[i].nome, str) == 0 ){
            if ( strcmp(curso[i].cidade, "SAO PAULO") == 0){
            contSP = contSP + curso[i].quantAlunos;
        } else {
            if (strcmp(curso[i].cidade, "RIO DE JANEIRO") == 0){
                contRJ = contRJ + curso[i].quantAlunos;
            } else {
                if (strcmp(curso[i].cidade, "MANAUS") == 0){
                    contMN = contMN + curso[i].quantAlunos;
                } else {
                    if (strcmp(curso[i].cidade, "PORTO ALEGRE") == 0){
                        contPA = contPA + curso[i].quantAlunos;
                    } else {
                        if (strcmp(curso[i].cidade, "FORTALEZA") == 0){
                            contFO = contFO + curso[i].quantAlunos;
                        } else {
                            contGO = contGO + curso[i].quantAlunos;
                        }
                    }
                }
            }
        }
        }
        }
        printf("\n\n-------- QUANTIDADE DE ALUNOS EM SAO PAULO: %d", contSP);
        printf("\n\n-------- QUANTIDADE DE ALUNOS NO RIO DE JANEIRO: %d", contRJ);
        printf("\n\n-------- QUANTIDADE DE ALUNOS EM FORTALEZA: %d", contFO);
        printf("\n\n-------- QUANTIDADE DE ALUNOS EM MANAUS: %d", contMN);
        printf("\n\n-------- QUANTIDADE DE ALUNOS EM PORTO ALEGRE: %d", contPA);
        printf("\n\n-------- QUANTIDADE DE ALUNOS EM GOIANIA: %d\n", contGO);

}

// Convertendo o que a pessoa digitou para maíusculo para poder comparar corretamente:
void maiusculo(char s1[], char s2[]){
    int i = 0;
    while(s1[i] != '\0'){
        s2[i] = toupper(s1[i]);
        i++;
    }
    s2[i] = '\0'; // Caractere que indica o fim da string
}
