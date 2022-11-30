/*
Dadas duas listas encadeadas L1 e L2, ambas do tipo TLista, ordenadas crescentemente e sem repetição de elementos,
criar uma terceira lista L3, contendo todos os elementos de L1 e L2.

OBS: Como as duas originais, a nova lista deve ter seus elementos ordenados crescentemente, e sem repetição de valores.
*/


//Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Definição de constantes
#define TRUE 1
#define FALSE 0

//Definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//Protótipos das funções
int inserirAleatorio (TLista *L, int num);
int inserir (TLista *L, int numero);
void criaLista (TLista L1, TLista L2, TLista *L3);
void ordena(TLista *L);
void exibir (TLista L);
int menu ();
TLista buscar (TLista L, int numero);

//Função principal
void main(){
    TLista L1 = NULL;
    TLista L2 = NULL;
    TLista L3 = NULL;
    int option, num;
    do{
		option = menu ();
		switch (option) {
			//Inserção na primeira lista
			case 1: printf ("\nEntre com a quantidade maxima de elementos: ");
			        scanf ("%d", &num);

			        //chamando a função
			        if (inserirAleatorio (&L1, num) == TRUE){
			        	printf ("\nInsercao realizada com sucesso!");
					}
					else{
						printf ("\nERRO: insercao nao realizada!");
					}
					break;
            //Inserção na segunda lista
            case 2: printf ("\nEntre com a quantidade maxima de elementos: ");
			        scanf ("%d", &num);

			        //chamando a função
			        if (inserirAleatorio (&L2, num) == TRUE){
			        	printf ("\nInsercao realizada com sucesso!");
					}
					else{
						printf ("\nERRO: insercao nao realizada!");
					}
					break;
            //Criação e exibição da L3
            case 3: criaLista (L1, L2, &L3);
                    ordena(&L3);
                    exibir(L3);
            break;

            //Exibição da L1
            case 4: printf("\nElementos da lista: \n");
                    exibir(L1);
            break;

             //Exibição da L2
            case 5: printf("\nElementos da lista: \n");
                    exibir(L2);
            break;

            //Saída
			case 6: printf ("\n\nPrograma finalizado!");
            break;

            default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
    } while (option != 6);
}

//Função para inserir números aleatórios nas listas L1 e L2
int inserirAleatorio (TLista *L, int num){
	//Declaração de variáveis
	TLista aux;
	int i;
	srand(time(NULL));
	//Verificando se o valor já existe na lista
	if (L == NULL){
		return FALSE;
	}
	else{
        for (i=num;i>0;i--){
            //Passo 1: alocar memória para o novo nó
            aux = (TLista) malloc (sizeof(TNo));
            //Verificando se a memória foi alocada
            if (aux == NULL){
                return FALSE;
            }
            else{
                //Passo 2: armazenar o valor aleatório de 0 a 30 no novo nó
                aux->valor = rand() % 30;
                //Passo 3: fazer o campo 'prox' do novo nó apontar para o "até então" primeiro nó da lista
                aux->prox = *L;
                //Passo 4: fazer '*L' apontar para o novo nó
                *L = aux;
            }
        }
	}
	return TRUE;
}

//Função de inserção com busca para inserir os números de L1 e L2 em L3
int inserir (TLista *L, int numero){
	//Declaração de variáveis
	TLista aux;
	//Verificando se o valor já existe na lista
	if (buscar (*L, numero) != NULL){
		return FALSE;
	}
	else {
		//Passo 1: alocar memória para o novo nó
		aux = (TLista) malloc (sizeof(TNo));
		//Verificando se a memória foi alocada
		if (aux == NULL){
			return FALSE;
		}
		else{
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

//Função para a criação de L3
void criaLista (TLista L1, TLista L2, TLista *L3){
    //Declaração de variáveis
	TLista aux;
	TLista aux2;
	//Verificando se a lista está vazia
	if ((L1 == NULL) ||(L2 == NULL) ){
		printf ("Lista vazia!\n");
	}
	else{
    //Se a lista não estiver vazia:
        //Auxiliares iniciam na cabeça da lista
		aux = L1;
		aux2 = L2;
		//Enquanto nenhuma das listas chegarem ao fim:
        while ( (aux != NULL) && (aux2 != NULL) ){
            //Copiar os valores de L1 e L2 em L3, independente da ordem, mas preservando o conceito de não ter repetição.
            inserir(&*L3, aux->valor);
            inserir(&*L3, aux2->valor);
            aux=aux->prox;
            aux2=aux2->prox;
        }
    }
}

//Função de busca
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

//Função de exibição
void exibir(TLista L){
    if( L != NULL ){
        printf("%d ", L->valor);
        exibir(L->prox);
    }
}

//Função de ordenação da L3, para colocá-la em ordem crescente
void ordena(TLista *L) {
     //Definição das variáveis
     TLista atual, seguinte, temporario;
     //Alocação de memória temporária para manipulação dos ponteiros posteriormente
     temporario = (TLista) malloc (sizeof(TNo));
     // 'atual' iniciando na cabeça da lista L
     atual = *L;
     //Enquanto a lista L não chegar ao fim
     while( atual != NULL) {
            //O ponteiro 'seguinte' recebe a próxima caixinha da lista L, na qual será importante para posteriormente comparar o número atual com o próximo
            seguinte = atual->prox;
            while (seguinte != NULL) {
                    //Compara o valor atual com o próximo
                   if (atual->valor > seguinte->valor){
                         *temporario = *atual ; // copia valor de 'atual' em 'temporario'.
                         *atual =  *seguinte; // copia valor de 'seguinte' em 'atual'.
                         atual->prox = temporario->prox; // altera ponteiro do próximo de 'atual' para que ele continue sendo o mesmo que era antes da copia
                         temporario->prox = seguinte->prox; // copia o valor do ponteiro do proximo 'seguinte'
                         *seguinte = *temporario; // copia valor de temporario em 'seguinte'.
                          seguinte->prox = temporario->prox; // altera ponteiro do próximo de 'atual' para que ele continue sendo o mesmo que era antes da copia
                        printf("\nseguinte %d \n", seguinte->valor);
                        printf("\atual %d \n", atual->valor);
                   }
                   seguinte = seguinte->prox;
            }
      atual = atual->prox;
    }
    //Liberando memória alocada temporariamente
    free(temporario);
}

int menu (){
	int opcao;
	printf ("\n\nMenu de Operacoes:\n\n");
	printf ("(1) Inserir na primeira lista\n");
	printf ("(2) Inserir na segunda lista\n");
	printf ("(3) Exibir uniao\n");
	printf ("(4) Exibir primeira lista\n");
	printf ("(5) Exibir segunda lista\n");
	printf ("(6) Sair\n\n");
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	return opcao;
}

