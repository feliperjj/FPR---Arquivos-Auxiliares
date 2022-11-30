
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
			        if (enfilar (&F, &U, num1) == TRUE)
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
			        quant = desenfilar (&F, &U, &num1);
			        
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
			case 3: if (primeiro(F,&num)==TRUE){
					printf("O numero %d eh o primeiro da fila", num1);
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
int empilhar (TLista *P, TLista *U, int numero)
{
	TLista aux;
	// tentando alocar memoria para novo no
	aux=(TLista)malloc(sizeof(TNo));
	//verificando se houve erro na aloca��o de memoria
	if (aux==NULL){
		return FALSE;
	} else {
		//armazenando numero no novo no
		aux->valor=numero;
		//como a inser��o � no final, o aux deve apontar para null.
		aux->prox=NULL;
		// verificando se a fila possui elementos 
		if (*F != NULL){
			//fazer o antigo ultimo apontar para o novo
			(*U)->prox =aux;
		} else {
			*F=aux;
		}
		
		//atualizando o ponteiro U
		*U = aux;
		return TRUE;
	}
}

int desenfilar (TLista *L, TLista *U, int *numero)
{
	//declara��o de vari�veis
	TLista aux1;
	int cont = 0;
	
	//Verificando se a fila est� vazia
	if (*P==NULL){
		return FALSE;
	} else {
		//verificando se o primeiro elemento � o n�mero a ser removido
		//passo 1: fazer 'aux1' apontar para o primeiro n�
		aux1 = *F;
		
		//passo 2: fazer o F apontar para o pr�ximo elemento (aquele que at� ent�o era o segundo n� da fila)
		*F = (*F)->prox;   //ou  *L = aux1->prox;
		
		//passo 3: se f estiver apontando para null, u tamb�m dever� apontar
		if (*F == NULL){
			*U = NULL;
		}
		
		//passo 4: salvar o valor que foi removidono parametro numero
		*numero = aux->valor;
		
		//passo 5: liberar a mem�ria alocada ao n� a ser removido
		free (aux1);
		
		return TRUE;
	}
	
}

int topo(TLista F, *p){
	if (F==NULL){
		return FALSE;
	} else {
		*p=F->valor;
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
