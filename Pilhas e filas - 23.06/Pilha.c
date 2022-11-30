
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
	int num1, op;
	
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usu�rio
		op = menu ();
		
		//verificando a op��o escolhida
		switch (op)
		{
			//Inser��o
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        if (empilhar (&P, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remo��o
			case 2:
			        //chamando a fun��o
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
		
		//Passo 4: fazer '*L' apontar para o novo n�
		*P = aux;
		
		return TRUE;
	}
}

int desempilhar (TLista *L, int *numero)
{
	//declara��o de vari�veis
	TLista aux1;
	int cont = 0;
	
	//Verificando se a pilha est� vazia
	if (*P==NULL){
		return FALSE;
	} else {
		//verificando se o primeiro elemento � o n�mero a ser removido
		//passo 1: fazer 'aux1' apontar para o primeiro n�
		aux1 = *P;
		
		//passo 2: fazer o L apontar para o pr�ximo elemento (aquele que at� ent�o era o segundo n� da lista)
		*P = (*P)->prox;   //ou  *L = aux1->prox;
		
		//passo 3: salvar o valor que foi removidono parametro numero
		*numero = aux->valor;
		
		//passo 4: liberar a mem�ria alocada ao n� a ser removido
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
