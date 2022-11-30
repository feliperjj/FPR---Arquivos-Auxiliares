/*
Dadas duas listas encadeadas L1 e L2, ambas do tipo TLista, ordenadas crescentemente e sem repetição de elementos,
criar uma terceira lista L3, contendo todos os elementos de L1 e L2.

OBS: Como as duas originais, a nova lista deve ter seus elementos ordenados crescentemente, e sem repetição de valores.
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

typedef TNo* TLista;

//protótipos das funções
int inserir (TLista *L, int numero);
void exibir (TLista L1, TLista L2);
int menu ();
TLista buscar (TLista L, int numero);

void main(){
    TLista L1 = NULL;
    TLista L2 = NULL;
    int option, num;
    do{
		option = menu ();
		switch (option) {
			//Inserção na primeira lista
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);

			        //chamando a função
			        if (inserir (&L1, num) == TRUE){
			        	printf ("\nInsercao realizada com sucesso!");
					}
					else{
						printf ("\nERRO: insercao nao realizada!");
					}
					break;
            //Inserção na segunda lista
            case 2: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);

			        //chamando a função
			        if (inserir (&L2, num) == TRUE){
			        	printf ("\nInsercao realizada com sucesso!");
					}
					else{
						printf ("\nERRO: insercao nao realizada!");
					}
					break;
            //Exibição da L3
            case 3: exibir (L1,L2);
            break;

            //Saída
            //Saída
			case 4: printf ("\n\nPrograma finalizado!");
            break;

            default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
    } while (option != 4);
}

int inserir (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux;

	//verificando se o valor já existe na lista
	if (buscar (*L, numero) != NULL)
	{
		return FALSE;
	}
	else
	{
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

			//Passo 3: fazer o campo 'prox' do novo nó apontar para o "até então" primeiro nó da lista
			aux->prox = *L;

			//Passo 4: fazer '*L' apontar para o novo nó
			*L = aux;

			return TRUE;
		}
	}
}

void exibir (TLista L1, TLista L2){
	TLista aux;
	TLista aux2;
	if ((L1 == NULL) ||(L2 == NULL)){
		printf ("Lista vazia!\n");
	}
	else{
		printf ("Elementos da lista: ");
		aux = L1;
		aux2 = L2;
		while (aux != NULL){
            if (buscar(L1, aux->valor) != NULL){
                printf ("%d ", aux->valor);
                aux = aux->prox;
            } else {
                aux = aux->prox;
            }
		}
		while (aux2 != NULL){
            if ( (buscar(L2, aux2->valor) != NULL) && ((buscar(L1, aux2->valor) == NULL))){
                printf ("%d ", aux2->valor);
                aux2 = aux2->prox;
            } else {
                aux2 = aux2->prox;
            }
		}
		printf ("\n");
	}
}

TLista buscar (TLista L, int numero){
	TLista aux;
	aux = L;
	while (aux != NULL){
		if (aux->valor == numero){
			return aux;
		}
		aux = aux->prox;
	}
	return NULL;
}

int menu (){
	int opcao;
	printf ("\n\nMenu de Operacoes:\n\n");
	printf ("(1) Inserir na primeira lista\n");
	printf ("(2) Inserir na segunda lista\n");
	printf ("(3) Exibir uniao\n");
	printf ("(4) Sair\n\n");
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	return opcao;
}
