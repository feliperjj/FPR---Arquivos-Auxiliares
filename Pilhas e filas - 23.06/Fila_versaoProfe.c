/*
	FAETERJ-Rio
	Fundamentos de Programa��o  -  2022/1
	Turma: Manh�
	Data: 23/06/2022
	
	Filas din�micas (ou seja, filas por ponteiros)
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
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *p);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista F = NULL, U = NULL;
	int num, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);
			        
			        //chamando a fun��o
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
			case 2: //chamando a fun��o
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
int enfilar (TLista *F, TLista *U, int numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//tentando alocar mem�ria para o novo n�
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na aloca��o de mem�ria
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//armazenando 'numero' no novo n�
		aux->valor = numero;
		
		//como a inser��o � ao final, o campo 'prox' deve apontar para NULL
		aux->prox = NULL;
		
		//verificando se a fila possui elemento
		if (*F != NULL)
		{
			//fazer o "antigo �ltimo" apontar para o novo n�
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
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a fila est� vazia
	if (*F == NULL)
	{
		return FALSE;
	}
	else
	{
		//passo 1: fazer 'aux' apontar para o primeiro n�
		aux = *F;
		
		//passo 2: fazer o F apontar para o pr�ximo elemento (aquele que at� ent�o era o segundo n� da fila)
		*F = (*F)->prox;   //ou  *F = aux->prox;
		
		//passo 3: se F estiver agora apontando para NULL, U tamb�m dever� apontar para NULL
		if (*F == NULL)
		{
			*U = NULL;
		}
		
		//passo 4: salvar o valor sendo removido no par�metro 'numero'
		*numero = aux->valor;
		
		//passo 5: liberar a mem�ria alocada ao n� a ser removido
		free (aux);

		return TRUE;
	}
}

int primeiro (TLista F, int *p)
{
	//verificando se a fila est� vazia
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
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
