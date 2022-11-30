/*
	FAETERJ-Rio
	FPR - Manh�
	Prova a compor a AV1 (Parte II)
	Data: 11/05/2022
		
	Quest�o 03 [2,5 pontos]:
	Uma pesquisa foi feita e cada entrevistado informou os seguintes 
	dados: nome, g�nero e idade. Todas as informa��es coletadas 
	foram armazenadas sob a forma de um vetor de structs, cada 
	posi��o armazenando os dados de um entrevistado. Pede-se o 
	desenvolvimento de uma fun��o que, dado um g�nero, retorne a 
	posi��o do entrevistado que atenda aos seguintes requisitos:
	
	a. Deve ser do g�nero especificado como par�metro da fun��o;
	b. Caso mais de um entrevistado seja do g�nero definido, dever� 
	   ser retornada a posi��o do entrevistado mais novo daquele 
	   g�nero;
	c. Por �ltimo, se houver mais de uma pessoa do g�nero escolhido 
	   e com a menor idade, dever� ser retornada a posi��o da que 
	   possuir o nome que vier primeiro em uma ordem crescente 
	   alfab�tica.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de constantes
#define TAM 5

//declara��o de tipos
typedef struct {
	char nome[30];
	char genero;
	int idade;
} TEntrevistado;

//prot�tipos de fun��es
int questao03 (TEntrevistado vetor[], int quant, char genero);

void preencherVetor (TEntrevistado vetor[], int quant);

//main
void main ()
{
	//declara��o de vari�veis
	TEntrevistado pesquisa[TAM];
	char genero;
	int posicao;
	
	//preenchendo o vetor com algumas informa��es para teste
	preencherVetor (pesquisa, TAM);
	
	//perguntando o genero
	printf ("\nEntre com o genero a ser pesquisado no vetor: ");
	fflush (stdin);
	scanf ("%c", &genero);
	genero = toupper (genero);
		
	//chamando a fun��o
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

//implementa��o das fun��es
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
	//1� entrevistado
	strcpy (vetor[0].nome, "JOAO");
	vetor[0].genero = 'M';
	vetor[0].idade = 42;

	//2� entrevistado
	strcpy (vetor[1].nome, "MARIA");
	vetor[1].genero = 'F';
	vetor[1].idade = 33;
	
	//3� entrevistado
	strcpy (vetor[2].nome, "JOSE");
	vetor[2].genero = 'M';
	vetor[2].idade = 35;
	
	//4� entrevistado
	strcpy (vetor[3].nome, "CARLOS");
	vetor[3].genero = 'M';
	vetor[3].idade = 33;
	
	//5� entrevistado
	strcpy (vetor[4].nome, "PEDRO");
	vetor[4].genero = 'M';
	vetor[4].idade = 37;
}*/

void preencherVetor (TEntrevistado vetor[], int quant)
{
	//1� entrevistado
	strcpy (vetor[0].nome, "JOAO");
	vetor[0].genero = 'M';
	vetor[0].idade = 42;

	//2� entrevistado
	strcpy (vetor[1].nome, "MARIA");
	vetor[1].genero = 'F';
	vetor[1].idade = 33;
	
	//3� entrevistado
	strcpy (vetor[2].nome, "JOSE");
	vetor[2].genero = 'M';
	vetor[2].idade = 35;
	
	//4� entrevistado
	strcpy (vetor[3].nome, "ANA");
	vetor[3].genero = 'F';
	vetor[3].idade = 33;
	
	//5� entrevistado
	strcpy (vetor[4].nome, "PEDRO");
	vetor[4].genero = 'M';
	vetor[4].idade = 37;
}
