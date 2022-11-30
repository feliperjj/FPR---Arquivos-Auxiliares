/*
	FAETERJ-Rio
	Fundamentos de Programação  -  2022/1
	Turma: Manhã
	Data: 23/06/2022
	
	Pilhas dinâmicas (ou seja, listas por ponteiros)
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;  //ou     typedef *TNo TLista;

//protótipos das funções
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *t);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista P = NULL;
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (empilhar (&P, num) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Desempilhar
			case 2: //chamando a função
			        if (desempilhar (&P, &num) == TRUE) //removendo o elemento que está no topo da pilha
			        {
			        	printf ("\n\tO valor %d foi removido da pilha!", num);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada (pilha vazia)!");
					}
					break;

			//Topo
			case 3: if (topo (P, &num) == TRUE)
			        {
			        	printf ("\n\tTopo da pilha: %d\n", num);
					}
					else
					{
						printf ("\n\tPilha vazia!\n");
					}
					break;
					
			//Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}


//implementação das funções
int empilhar (TLista *P, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//Passo 1: alocar memória para o novo nó
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se a memória foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//Passo 2: armazenar 'numero' no novo nó
		aux->valor = numero;
		
		//Passo 3: fazer o campo 'prox' do novo nó apontar para o "até então" primeiro nó da pilha
		aux->prox = *P;
		
		//Passo 4: fazer '*P' apontar para o novo nó
		*P = aux;
		
		return TRUE;
	}
}

int desempilhar (TLista *P, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a pilha está vazia
	if (*P == NULL)
	{
		return FALSE;
	}
	else
	{
		//passo 1: fazer 'aux' apontar para o primeiro nó
		aux = *P;
		
		//passo 2: fazer o P apontar para o próximo elemento (aquele que até então era o segundo nó da pilha)
		*P = (*P)->prox;   //ou  *P = aux->prox;
		
		//passo 3: salvar o valor sendo removido no parâmetro 'numero'
		*numero = aux->valor;
		
		//passo 4: liberar a memória alocada ao nó a ser removido
		free (aux);

		return TRUE;
	}
}

int topo (TLista P, int *t)
{
	//verificando se a pilha está vazia
	if (P == NULL)
	{
		return FALSE;
	}
	else
	{
		//armazenando em 't' o elemento que está no topo da pilha
		*t = P->valor;
		
		return TRUE;
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}
