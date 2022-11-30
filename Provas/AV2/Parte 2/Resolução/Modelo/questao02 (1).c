/*
	FAETERJ-Rio
	FPR - Manhã
	Prova a compor a AV2
	Data: 07/07/2022
	
	Questão 02 [2,5 pontos]:
	Implementar uma função que, dada uma lista L1, crie uma lista L2 
	(ambas do tipo TLista) consistindo em uma sublista de L1, 
	começando na posição p (considerar que o primeiro nó está na 
	posição 0) e contendo n elementos.

	Observações: 
		- Se a posição p não existir em L1, L2 será uma lista vazia;
		- Se o valor de n for inválido, L2 será uma lista vazia;
		- Caso não existam n nós a partir da posição p, L2 conterá 
		  os nós de L1 da posição p ao final.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de tipos
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos de funções
void questao02 (TLista L1, int p, int n, TLista *L2);

int inserir (TLista *L, int numero);
void exibir (TLista L);

//main
void main ()
{
	//declaração de variáveis
	TLista lista1 = NULL, lista2 = NULL;;
		
	//inserindo elementos na lista 1
	inserir (&lista1, 3);
	inserir (&lista1, 6);
	inserir (&lista1, 1);
	inserir (&lista1, 0);
	inserir (&lista1, 2);
	inserir (&lista1, 8);
	inserir (&lista1, 1);
	inserir (&lista1, 4);
	inserir (&lista1, 5);
	inserir (&lista1, 9);
	
	//exibindo a Lista 1
	printf ("Lista 1:\n");
	exibir (lista1);
	
	//chamando a função
	
	//TESTE 1
	questao02 (lista1, -5, 4, &lista2);

	//TESTE 2
	//questao02 (lista1, 3, 11, &lista2);

	//TESTE 3
	//questao02 (lista1, 2, 4, &lista2);
	
	//exibindo a Lista 2
	printf ("\n\nLista 2:\n");
	exibir (lista2);	
}

//implementação das funções
void questao02 (TLista L1, int p, int n, TLista *L2)
{
	
}

int inserir (TLista *L, int numero)
{
	//declaração de variáveis;
	TLista aux;
	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//2º passo: armazenar 'numero' na memória recém-alocada
		aux->valor = numero;
		
		//3º passo: mandar o campo 'prox' do novo nó apontar para o 
		//"até então" primeiro elemento	da lista
		aux->prox = *L;
		
		//4º passo: fazer com que L aponte para o novo nó da lista		
		*L = aux;
		
		return TRUE;
	}	
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux = L;
	
	//testando se a lista está vazia
	if (L == NULL)
	{
		printf ("\nLista vazia!");
	}
	else
	{
		//percorrendo a lista até o seu final
		while (aux != NULL)
		{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//atualizando o 'aux' para apontar para o próximo nó
			aux = aux->prox;
		}
	}
}
