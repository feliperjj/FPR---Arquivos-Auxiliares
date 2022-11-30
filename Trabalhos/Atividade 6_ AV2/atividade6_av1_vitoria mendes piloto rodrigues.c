/*

                                    ╔═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╗
                                            𝐓𝐑𝐀𝐁𝐀𝐋𝐇𝐎 6 - 𝐀𝐕2

                                        𝐀𝐥𝐮𝐧𝐚: 𝐕𝐢𝐭𝐨𝐫𝐢𝐚 𝐏𝐢𝐥𝐨𝐭𝐨
                                        𝐃𝐬𝐢𝐜𝐢𝐩𝐥𝐢𝐧𝐚: 𝐅𝐏𝐑
                                        𝐏𝐫𝐨𝐟𝐞𝐬𝐬𝐨𝐫: 𝐋𝐞𝐨𝐧𝐚𝐫𝐝𝐨 𝐕𝐢𝐚𝐧𝐧𝐚
                                    ╚═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╝
𝐐𝐔𝐄𝐒𝐓𝐀𝐎:
Desenvolver uma função que, dada uma lista encadeada L do tipo TLista e dois números inteiros A e B, retorne o número de elementos de L que encontram-se
no intervalo [A, B].
*/

#include <stdio.h>
//Definicao de constantes
#define TRUE 1
#define FALSE 0

//Definição de tipos
typedef struct No{
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

int inserir (TLista *L, int numero);
void exibir (TLista L);
int contarElementos (TLista L, int numero1, int numero2);

void main(){
    TLista L = NULL;
    char continua='S';
    int num, busca1, busca2, quant;
     printf("\n-------- PROGRAMA CONTA ELEMENTOS DE UMA LISTA EM UM INTERVALO ---------");
    while (continua == 'S' || continua == 's'){
        printf("\n\nINSIRA O NUMERO QUE DESEJA INSERIR:\t");
        scanf("%d",&num);
        inserir(&L,num);
        printf("\nDESEJA CONTINUAR INSERINDO NUMEROS NA LISTA? [S/N]: ");
        fflush(stdin);
        scanf("%c",&continua);
    }

    printf("\n\nINSIRA O NUMERO DO PRIMEIRO VALOR DO INTERVALO:\t");
    scanf("%d",&busca1);
    printf("\nINSIRA O NUMERO DO ULTIMO VALOR DO INTERVALO:\t");
    scanf("%d",&busca2);

    exibir(L);

    quant=contarElementos(L,busca1,busca2);
    printf("\n\nNUMERO DE ELEMENTOS DA LISTA NO INTERVALO DE %d ATE %d: %d\n", busca1, busca2, quant);
}

int inserir (TLista *L, int numero){
	TLista aux;
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

void exibir (TLista L){
	TLista aux;
	if (L == NULL){
		printf ("Lista esta vazia!\n");
	}
	else{
		printf ("\nElementos da lista: ");
		aux = L;
		while (aux != NULL){
			printf ("%d ", aux->valor);
			aux = aux->prox;
		}
	}
}

int contarElementos(TLista L, int numero1, int numero2){
	int cont=0, contAux=0;
	TLista aux;
	aux = L;
	while (aux!=NULL){
        if (cont == numero1){
            while(cont != numero2){
                contAux++;
                cont++;
                aux=aux->prox;
            }
        } else {
            cont++;
            aux=aux->prox;
        }
	}
	return contAux;
}

