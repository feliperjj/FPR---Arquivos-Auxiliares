/*
Desenvolver uma fun��o que, dada uma lista
encadeada L do tipo TLista, exiba os seus
elementos �de tr�s para frente�; ou seja, o
elemento apontado por L ser� o �ltimo a ser
exibido.
Nota: por ser uma atividade que avalia a
manipula��o de listas encadeadas, nenhuma outra
estrutura de dados (como vetores, por exemplo)
pode ser utilizada nesta solu��o.
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

typedef TNo* TLista;

//prot�tipos das fun��es
int inserir (TLista *L, int numero);
void exibir (TLista L);

void main(){
    TLista L = NULL;
    int option, num;
    do{
		option = menu ();
		switch (option) {
			//Inser��o
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num);

			        //chamando a fun��o
			        if (inserir (&L, num) == TRUE){
			        	printf ("\nInsercao realizada com sucesso!");
					}
					else{
						printf ("\nERRO: insercao nao realizada!");
					}
					break;
            //Exibir
            case 2: exibir (L);
            break;
            //Sa�da
            case 3: printf ("\n\nPrograma finalizado!");
            break;

            default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
    } while (option != 3);
}

int inserir (TLista *L, int numero) {
	TLista aux;
	if (aux == NULL){
		return FALSE;
	}
	else{
		aux = (TLista) malloc (sizeof(TNo));
		if (aux == NULL){
			return FALSE;
		}
		else{
			aux->valor = numero;
			aux->prox = *L;
			*L = aux;
			return TRUE;
		}
	}
}

void exibir(TLista L){
    if( L != NULL ){
        exibir(L->prox);
        printf("%d\t", L->valor);
    } else {
        printf("\nElementos da lista exibidos ao contrario: \n");
    }
}


int menu ()
{
	int opcao;
	printf ("\n\nMenu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Exibir\n");
	printf ("(3) Sair\n\n");
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	return opcao;
}
