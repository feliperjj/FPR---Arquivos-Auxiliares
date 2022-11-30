
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
			        if (enfilar (&F, &U, num1) == TRUE)
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


//implementação das funções
int empilhar (TLista *P, TLista *U, int numero)
{
	TLista aux;
	// tentando alocar memoria para novo no
	aux=(TLista)malloc(sizeof(TNo));
	//verificando se houve erro na alocação de memoria
	if (aux==NULL){
		return FALSE;
	} else {
		//armazenando numero no novo no
		aux->valor=numero;
		//como a inserção é no final, o aux deve apontar para null.
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
	//declaração de variáveis
	TLista aux1;
	int cont = 0;
	
	//Verificando se a fila está vazia
	if (*P==NULL){
		return FALSE;
	} else {
		//verificando se o primeiro elemento é o número a ser removido
		//passo 1: fazer 'aux1' apontar para o primeiro nó
		aux1 = *F;
		
		//passo 2: fazer o F apontar para o próximo elemento (aquele que até então era o segundo nó da fila)
		*F = (*F)->prox;   //ou  *L = aux1->prox;
		
		//passo 3: se f estiver apontando para null, u também deverá apontar
		if (*F == NULL){
			*U = NULL;
		}
		
		//passo 4: salvar o valor que foi removidono parametro numero
		*numero = aux->valor;
		
		//passo 5: liberar a memória alocada ao nó a ser removido
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
