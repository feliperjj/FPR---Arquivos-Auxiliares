/*
	FAETERJ-Rio
	Fundamentos de Programa��o  -  2022/1
	Turma: Manh�
	Data: 23/06/2022
	
	Pilhas din�micas (ou seja, listas por ponteiros)
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//defini��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;  //ou     typedef *TNo TLista;

//prot�tipos das fun��es
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *t);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista P = NULL;
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
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
			case 2: //chamando a fun��o
			        if (desempilhar (&P, &num) == TRUE) //removendo o elemento que est� no topo da pilha
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
					
			//Sa�da
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}


//implementa��o das fun��es
int empilhar (TLista *P, int numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//Passo 1: alocar mem�ria para o novo n�
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se a mem�ria foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//Passo 2: armazenar 'numero' no novo n�
		aux->valor = numero;
		
		//Passo 3: fazer o campo 'prox' do novo n� apontar para o "at� ent�o" primeiro n� da pilha
		aux->prox = *P;
		
		//Passo 4: fazer '*P' apontar para o novo n�
		*P = aux;
		
		return TRUE;
	}
}

int desempilhar (TLista *P, int *numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a pilha est� vazia
	if (*P == NULL)
	{
		return FALSE;
	}
	else
	{
		//passo 1: fazer 'aux' apontar para o primeiro n�
		aux = *P;
		
		//passo 2: fazer o P apontar para o pr�ximo elemento (aquele que at� ent�o era o segundo n� da pilha)
		*P = (*P)->prox;   //ou  *P = aux->prox;
		
		//passo 3: salvar o valor sendo removido no par�metro 'numero'
		*numero = aux->valor;
		
		//passo 4: liberar a mem�ria alocada ao n� a ser removido
		free (aux);

		return TRUE;
	}
}

int topo (TLista P, int *t)
{
	//verificando se a pilha est� vazia
	if (P == NULL)
	{
		return FALSE;
	}
	else
	{
		//armazenando em 't' o elemento que est� no topo da pilha
		*t = P->valor;
		
		return TRUE;
	}
}

int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
