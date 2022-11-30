/*
Questão 02:
Determinada zona eleitoral possui N eleitores inscritos que poderão votar, uma única vez, em um dos C candidatos para o único cargo a ser
definido. Pede-se:

a. A declaração de todo(s) o(s) tipo(s) de dados necessário(s) para o armazenamento dos números dos candidatos, assim como a quantidade de votos
brancos, nulos e votos para cada candidato;

b. Uma função que leia o voto de cada eleitor, considerando que o processo terminará quando os N eleitores votarem ou quando o número -1 for digitado
como voto;

c. Uma função que exiba:
    i. O total de votos para cada candidato, assim com a quantidade de votos brancos (código 0) e de nulos (código sem candidato associado);

    ii. A quantidade de abstenções (eleitores que não votaram);

    iii. O número do candidato vencedor (caso tenha mais de 50% dos votos válidos) ou dos que irão para o segundo turno (os dois mais votados).

Notas:
a) o número do candidato deve conter dois algarismos apenas;

b) podem considerar que não haverá mais de um candidato com a mesma quantidade de votos.
*/

#include <stdio.h>
#define NUM_ELEITORES 5
#define NUM_CANDIDATOS 5

// Definição dos tipos

typedef struct {
    int numero;
    int quantidadeVotos;
} TCandidato;

typedef struct {
    TCandidato vetCand[NUM_CANDIDATOS];
    int totalVotos;
    int brancos;
    int nulos;
} TVotacao;

// Protótipo das funções

void lerVoto(TVotacao *eleicao, int numEleitores);
int buscar(TCandidato candidatos[], int tamanho, int numeroCandidato);
void preencherVetorCandidatos(TCandidato candidatos[], int tamanho);
void inicializarVotacao(TVotacao *eleicao);
void exibirResultadoVotacao(TVotacao eleicao);
void candidatosMaisVotados (TCandidato candidatos[], int tamanho, int *primeiro, int *segundo);

void main(){
    TVotacao vetEleicao;
    // Inicializar votação, incluindo preencher os candidatos
    inicializarVotacao(&vetEleicao);
    //Lendo os votos dos eleitores
    lerVoto(&vetEleicao, NUM_ELEITORES);
    //Exibindo o resultado da eleição
    exibirResultadoVotacao(vetEleicao);
}

void preencherVetorCandidatos(TCandidato candidato[], int tamanho){
  	//declaração de variáveis
	int i, numero;

	//varrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//lendo o número de cada candidato
		do
		{
			printf ("\nEntre com o numero do candidato %d: ", i+1);
			scanf ("%d", &numero);

			//verificando se o número digitado é inválido (pois deve ter dois algarismos)
			if ((numero < 10) || (numero > 99))
			{
				printf ("\n\nErro: o numero do candidato deve estar no intervalo de 10 a 99\nTente novamente.\n\n");
			}

		} while ((numero < 10) || (numero > 99));

		candidato[i].numero = numero;
		candidato[i].quantidadeVotos = 0;
	}
}

void inicializarVotacao(TVotacao *eleicao){
    // Inicializando com 0 os votos
    (*eleicao).brancos=0;
    (*eleicao).nulos=0;
    (*eleicao).totalVotos=0;
    // Preenchendo os candidatos
    preencherVetorCandidatos((*eleicao).vetCand, NUM_CANDIDATOS);
}

int buscar(TCandidato candidatos[], int tamanho, int numeroCandidato){
    int i=0;
    for (i=0;i<tamanho;i++){
        if (candidatos[i].numero == numeroCandidato){
            return i;
        }
    }

    return -1;
}

void lerVoto(TVotacao *eleicao, int quantidade){
    int numero, retorno;
    printf("\n-----------------VOTACAO-----------------\n");
    do {
        printf("\nInsira o numero do candidato: ");
        scanf("%d", &numero);
        // Buscar se o numero digitado foi valido e contar o voto.
        if (numero != -1){
            (*eleicao).totalVotos++;
            if (numero==0){
                (*eleicao).brancos++;
            } else {
                retorno = buscar((*eleicao).vetCand, NUM_CANDIDATOS, numero);
                if (retorno>=0){
                    (*eleicao).vetCand[retorno].quantidadeVotos++;
                } else {
                    (*eleicao).nulos++;
                }
            }
        }
    } while (((*eleicao).totalVotos < quantidade) && (numero != -1));

}

void exibirResultadoVotacao(TVotacao eleicao){
    int i, primeiro, segundo, votosValidos;
    float percentualPrimeiro;
    printf("\n-----------------TOTAL DE VOTOS-----------------\n");
    printf("\nCandidatos\t\t\t\tVotos\n");
    for (i=0;i<NUM_CANDIDATOS;i++){
        printf("%d\t\t\t\t\t%d\n", eleicao.vetCand[i].numero,  eleicao.vetCand[i].quantidadeVotos);
    }
    printf("\nVotos brancos: %d\n", eleicao.brancos);
    printf("\nVotos nulos: %d\n", eleicao.nulos);
    printf("\nAbstencoes: %d\n", NUM_ELEITORES-eleicao.totalVotos);
    printf("\n-----------------RESULTADO VOTACAO----------------\n");
    candidatosMaisVotados(eleicao.vetCand, NUM_CANDIDATOS, &primeiro, &segundo);
    votosValidos=eleicao.totalVotos-eleicao.brancos-eleicao.nulos;
    percentualPrimeiro=(float)eleicao.vetCand[primeiro].quantidadeVotos/votosValidos;
    if (percentualPrimeiro>0.5){
        printf ("\nVencedor da Eleicao: candidato %d!!!\n", eleicao.vetCand[primeiro].numero);
    } else {
        printf ("\nCandidatos que concorrerao no segundo turno: %d e %d.\n", eleicao.vetCand[primeiro].numero, eleicao.vetCand[segundo].numero);
    }
}

// Determinando os dois mais votados:
void candidatosMaisVotados (TCandidato candidatos[], int tamanho, int *primeiro, int *segundo){
    int i, maisVotos1, maisVotos2;
    //Inicializando o mais votado como o candidato da posição 0 do vetor
    *primeiro=0;
    maisVotos1 = candidatos[0].quantidadeVotos;
    for (i=0;i<tamanho;i++){
        if (candidatos[i].quantidadeVotos>maisVotos1){
            maisVotos2=maisVotos1;
            *segundo = *primeiro;

            maisVotos1 = candidatos[i].quantidadeVotos;
            *primeiro= i;
            } else {
                if (candidatos[i].quantidadeVotos > maisVotos2){
                    maisVotos2=candidatos[i].quantidadeVotos;
                    *segundo=i;
                }
            }
        }
    }

