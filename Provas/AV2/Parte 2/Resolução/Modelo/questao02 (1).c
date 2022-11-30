/*
	FAETERJ-Rio
	FPR - Manh�
	Prova a compor a AV2
	Data: 07/07/2022
	
	Quest�o 02 [2,5 pontos]:
	Implementar uma fun��o que, dada uma lista L1, crie uma lista L2 
	(ambas do tipo TLista) consistindo em uma sublista de L1, 
	come�ando na posi��o p (considerar que o primeiro n� est� na 
	posi��o 0) e contendo n elementos.

	Observa��es: 
		- Se a posi��o p n�o existir em L1, L2 ser� uma lista vazia;
		- Se o valor de n for inv�lido, L2 ser� uma lista vazia;
		- Caso n�o existam n n�s a partir da posi��o p, L2 conter� 
		  os n�s de L1 da posi��o p ao final.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de tipos
#define TRUE 1
#define FALSE 0

//defini��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//prot�tipos de fun��es
void questao02 (TLista L1, int p, int n, TLista *L2);

int inserir (TLista *L, int numero);
void exibir (TLista L);

//main
void main ()
{
	//declara��o de vari�veis
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
	
	//chamando a fun��o
	
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

//implementa��o das fun��es
void questao02 (TLista L1, int p, int n, TLista *L2)
{
	
}

int inserir (TLista *L, int numero)
{
	//declara��o de vari�veis;
	TLista aux;
	
	//1� passo: alocar mem�ria para o novo n�	
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na aloca��o de mem�ria
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//2� passo: armazenar 'numero' na mem�ria rec�m-alocada
		aux->valor = numero;
		
		//3� passo: mandar o campo 'prox' do novo n� apontar para o 
		//"at� ent�o" primeiro elemento	da lista
		aux->prox = *L;
		
		//4� passo: fazer com que L aponte para o novo n� da lista		
		*L = aux;
		
		return TRUE;
	}	
}

void exibir (TLista L)
{
	//declara��o de vari�veis
	TLista aux = L;
	
	//testando se a lista est� vazia
	if (L == NULL)
	{
		printf ("\nLista vazia!");
	}
	else
	{
		//percorrendo a lista at� o seu final
		while (aux != NULL)
		{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//atualizando o 'aux' para apontar para o pr�ximo n�
			aux = aux->prox;
		}
	}
}
