
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
	int num1, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (empilhar (&P, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remoção
			case 2:
			        //chamando a função
			        quant = desempilhar (&P, &num1);
			        
					if (quant > 0)
			        {
			        	printf ("\n\tO valor %d foi removido!", num1);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			default: printf ("\n\nOpcao invalida! Tente novamente.");
			
			// Topo
			case 3: if (topo(P,&num)==TRUE){
					printf("O numero %d eh o topo da fila", num1);
			} else{
				printf("FILA NAO EXISTE", num1);
			}
			break;
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
		
		//Passo 4: fazer '*L' apontar para o novo nó
		*P = aux;
		
		return TRUE;
	}
}

int desempilhar (TLista *L, int *numero)
{
	//declaração de variáveis
	TLista aux1;
	int cont = 0;
	
	//Verificando se a pilha está vazia
	if (*P==NULL){
		return FALSE;
	} else {
		//verificando se o primeiro elemento é o número a ser removido
		//passo 1: fazer 'aux1' apontar para o primeiro nó
		aux1 = *P;
		
		//passo 2: fazer o L apontar para o próximo elemento (aquele que até então era o segundo nó da lista)
		*P = (*P)->prox;   //ou  *L = aux1->prox;
		
		//passo 3: salvar o valor que foi removidono parametro numero
		*numero = aux->valor;
		
		//passo 4: liberar a memória alocada ao nó a ser removido
		free (aux1);
		
		return TRUE;
	}
	
}

int topo(TLista P, *topo){
	if (P==NULL){
		return FALSE;
	} else {
		*t=P->valor;
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
