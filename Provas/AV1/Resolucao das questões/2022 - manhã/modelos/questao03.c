/*
	FAETERJ-Rio
	FPR - Manhã
	Prova a compor a AV1 (Parte II)
	Data: 11/05/2022
		
	Questão 03 [2,5 pontos]:
	Uma pesquisa foi feita e cada entrevistado informou os seguintes 
	dados: nome, gênero e idade. Todas as informações coletadas 
	foram armazenadas sob a forma de um vetor de structs, cada 
	posição armazenando os dados de um entrevistado. Pede-se o 
	desenvolvimento de uma função que, dado um gênero, retorne a 
	posição do entrevistado que atenda aos seguintes requisitos:
	
	a. Deve ser do gênero especificado como parâmetro da função;
	b. Caso mais de um entrevistado seja do gênero definido, deverá 
	   ser retornada a posição do entrevistado mais novo daquele 
	   gênero;
	c. Por último, se houver mais de uma pessoa do gênero escolhido 
	   e com a menor idade, deverá ser retornada a posição da que 
	   possuir o nome que vier primeiro em uma ordem crescente 
	   alfabética.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 5

//declaração de tipos
typedef struct {
	char nome[30];
	char genero;
	int idade;
} TEntrevistado;

//protótipos de funções
int questao03 (TEntrevistado vetor[], int quant, char genero);

void preencherVetor (TEntrevistado vetor[], int quant);

//main
void main ()
{
	//declaração de variáveis
	TEntrevistado pesquisa[TAM];
	char genero;
	int posicao;
	
	//preenchendo o vetor com algumas informações para teste
	preencherVetor (pesquisa, TAM);
	
	//perguntando o genero
	printf ("\nEntre com o genero a ser pesquisado no vetor: ");
	fflush (stdin);
	scanf ("%c", &genero);
	genero = toupper (genero);
		
	//chamando a função
	posicao = questao03 (pesquisa, TAM, genero);
	if (posicao >= 0)
	{
		printf ("\nPosicao retornada: %d", posicao);
	}
	else
	{
		printf ("\nNao foi encontrado entrevistado que atendesse aos filtros.");
	}
}

//implementação das funções
int questao03 (TEntrevistado vetor[], int quant, char genero)
{
	int i, posicao, menor=999, posM;
	for (i=0;i<quant;i++){
		if (vetor[i].genero==genero){
			if (vetor[i].idade < menor){
				menor = vetor[i].idade;
				posicao = i;
				posM = posicao; 
			} else {
				if (vetor[i].idade==menor){
					if ( strcmp(vetor[i].nome,vetor[posM].nome) < 0 ){
						posicao = i;
					}
				}
			}
		}
	}
	
	return posicao;
}

/*void preencherVetor (TEntrevistado vetor[], int quant)
{
	//1º entrevistado
	strcpy (vetor[0].nome, "JOAO");
	vetor[0].genero = 'M';
	vetor[0].idade = 42;

	//2º entrevistado
	strcpy (vetor[1].nome, "MARIA");
	vetor[1].genero = 'F';
	vetor[1].idade = 33;
	
	//3º entrevistado
	strcpy (vetor[2].nome, "JOSE");
	vetor[2].genero = 'M';
	vetor[2].idade = 35;
	
	//4º entrevistado
	strcpy (vetor[3].nome, "CARLOS");
	vetor[3].genero = 'M';
	vetor[3].idade = 33;
	
	//5º entrevistado
	strcpy (vetor[4].nome, "PEDRO");
	vetor[4].genero = 'M';
	vetor[4].idade = 37;
}*/

void preencherVetor (TEntrevistado vetor[], int quant)
{
	//1º entrevistado
	strcpy (vetor[0].nome, "JOAO");
	vetor[0].genero = 'M';
	vetor[0].idade = 42;

	//2º entrevistado
	strcpy (vetor[1].nome, "MARIA");
	vetor[1].genero = 'F';
	vetor[1].idade = 33;
	
	//3º entrevistado
	strcpy (vetor[2].nome, "JOSE");
	vetor[2].genero = 'M';
	vetor[2].idade = 35;
	
	//4º entrevistado
	strcpy (vetor[3].nome, "ANA");
	vetor[3].genero = 'F';
	vetor[3].idade = 33;
	
	//5º entrevistado
	strcpy (vetor[4].nome, "PEDRO");
	vetor[4].genero = 'M';
	vetor[4].idade = 37;
}
