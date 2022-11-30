/*
	FAETERJ-Rio
	Fundamentos de Programação  -  2022/1
	Turma: Manhã
	Data: 23/06/2022
	
	Filas dinâmicas (ou seja, filas por ponteiros)
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
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *p);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista F = NULL, U = NULL;
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (enfilar (&F, &U, num) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Desenfilar
			case 2: //chamando a função
			        if (desenfilar (&F, &U, &num) == TRUE) //removendo o primeiro elemento da fila
			        {
			        	printf ("\n\tO valor %d foi removido da fila!", num);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada (fila vazia)!");
					}
					break;

			//Primeiro
			case 3: if (primeiro (F, &num) == TRUE)
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d\n", num);
					}
					else
					{
						printf ("\n\tFila vazia!\n");
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
int enfilar (TLista *F, TLista *U, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//tentando alocar memória para o novo nó
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//armazenando 'numero' no novo nó
		aux->valor = numero;
		
		//como a inserção é ao final, o campo 'prox' deve apontar para NULL
		aux->prox = NULL;
		
		//verificando se a fila possui elemento
		if (*F != NULL)
		{
			//fazer o "antigo último" apontar para o novo nó
			(*U)->prox = aux;
		}
		else
		{
			*F = aux;
		}
		
		//atualizando o ponteiro U
		*U = aux;
		
		return TRUE;
	}
}

int desenfilar (TLista *F, TLista *U, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a fila está vazia
	if (*F == NULL)
	{
		return FALSE;
	}
	else
	{
		//passo 1: fazer 'aux' apontar para o primeiro nó
		aux = *F;
		
		//passo 2: fazer o F apontar para o próximo elemento (aquele que até então era o segundo nó da fila)
		*F = (*F)->prox;   //ou  *F = aux->prox;
		
		//passo 3: se F estiver agora apontando para NULL, U também deverá apontar para NULL
		if (*F == NULL)
		{
			*U = NULL;
		}
		
		//passo 4: salvar o valor sendo removido no parâmetro 'numero'
		*numero = aux->valor;
		
		//passo 5: liberar a memória alocada ao nó a ser removido
		free (aux);

		return TRUE;
	}
}

int primeiro (TLista F, int *p)
{
	//verificando se a fila está vazia
	if (F == NULL)
	{
		return FALSE;
	}
	else
	{
		//armazenando em 'p' o primeiro elemento da fila
		*p = F->valor;
		
		return TRUE;
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}
