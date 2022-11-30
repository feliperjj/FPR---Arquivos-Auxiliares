/*
Dadas duas listas encadeadas L1 e L2, ambas do tipo TLista, ordenadas crescentemente e sem repeti��o de elementos,
criar uma terceira lista L3, contendo todos os elementos de L1 e L2.

OBS: Como as duas originais, a nova lista deve ter seus elementos ordenados crescentemente, e sem repeti��o de valores.
*/


//Importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Defini��o de constantes
#define TRUE 1
#define FALSE 0

//Defini��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//Prot�tipos das fun��es
int inserirAleatorio (TLista *L, int num);
int inserir (TLista *L, int numero);
void criaLista (TLista L1, TLista L2, TLista *L3);
void ordena(TLista *L);
void exibir (TLista L);
int menu ();
TLista buscar (TLista L, int numero);

//Fun��o principal
void main(){
    TLista L1 = NULL;
    TLista L2 = NULL;
    TLista L3 = NULL;
    int option, num;
    do{
		option = menu ();
		switch (option) {
			//Inser��o na primeira lista
			case 1: printf ("\nEntre com a quantidade maxima de elementos: ");
			        scanf ("%d", &num);

			        //chamando a fun��o
			        if (inserirAleatorio (&L1, num) == TRUE){
			        	printf ("\nInsercao realizada com sucesso!");
					}
					else{
						printf ("\nERRO: insercao nao realizada!");
					}
					break;
            //Inser��o na segunda lista
            case 2: printf ("\nEntre com a quantidade maxima de elementos: ");
			        scanf ("%d", &num);

			        //chamando a fun��o
			        if (inserirAleatorio (&L2, num) == TRUE){
			        	printf ("\nInsercao realizada com sucesso!");
					}
					else{
						printf ("\nERRO: insercao nao realizada!");
					}
					break;
            //Cria��o e exibi��o da L3
            case 3: criaLista (L1, L2, &L3);
                    ordena(&L3);
                    exibir(L3);
            break;

            //Exibi��o da L1
            case 4: printf("\nElementos da lista: \n");
                    exibir(L1);
            break;

             //Exibi��o da L2
            case 5: printf("\nElementos da lista: \n");
                    exibir(L2);
            break;

            //Sa�da
			case 6: printf ("\n\nPrograma finalizado!");
            break;

            default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
    } while (option != 6);
}

//Fun��o para inserir n�meros aleat�rios nas listas L1 e L2
int inserirAleatorio (TLista *L, int num){
	//Declara��o de vari�veis
	TLista aux;
	int i;
	srand(time(NULL));
	//Verificando se o valor j� existe na lista
	if (L == NULL){
		return FALSE;
	}
	else{
        for (i=num;i>0;i--){
            //Passo 1: alocar mem�ria para o novo n�
            aux = (TLista) malloc (sizeof(TNo));
            //Verificando se a mem�ria foi alocada
            if (aux == NULL){
                return FALSE;
            }
            else{
                //Passo 2: armazenar o valor aleat�rio de 0 a 30 no novo n�
                aux->valor = rand() % 30;
                //Passo 3: fazer o campo 'prox' do novo n� apontar para o "at� ent�o" primeiro n� da lista
                aux->prox = *L;
                //Passo 4: fazer '*L' apontar para o novo n�
                *L = aux;
            }
        }
	}
	return TRUE;
}

//Fun��o de inser��o com busca para inserir os n�meros de L1 e L2 em L3
int inserir (TLista *L, int numero){
	//Declara��o de vari�veis
	TLista aux;
	//Verificando se o valor j� existe na lista
	if (buscar (*L, numero) != NULL){
		return FALSE;
	}
	else {
		//Passo 1: alocar mem�ria para o novo n�
		aux = (TLista) malloc (sizeof(TNo));
		//Verificando se a mem�ria foi alocada
		if (aux == NULL){
			return FALSE;
		}
		else{
			//Passo 2: armazenar 'numero' no novo n�
			aux->valor = numero;
			//Passo 3: fazer o campo 'prox' do novo n� apontar para o "at� ent�o" primeiro n� da lista
			aux->prox = *L;
			//Passo 4: fazer '*L' apontar para o novo n�
			*L = aux;
			return TRUE;
		}
	}
}

//Fun��o para a cria��o de L3
void criaLista (TLista L1, TLista L2, TLista *L3){
    //Declara��o de vari�veis
	TLista aux;
	TLista aux2;
	//Verificando se a lista est� vazia
	if ((L1 == NULL) ||(L2 == NULL) ){
		printf ("Lista vazia!\n");
	}
	else{
    //Se a lista n�o estiver vazia:
        //Auxiliares iniciam na cabe�a da lista
		aux = L1;
		aux2 = L2;
		//Enquanto nenhuma das listas chegarem ao fim:
        while ( (aux != NULL) && (aux2 != NULL) ){
            //Copiar os valores de L1 e L2 em L3, independente da ordem, mas preservando o conceito de n�o ter repeti��o.
            inserir(&*L3, aux->valor);
            inserir(&*L3, aux2->valor);
            aux=aux->prox;
            aux2=aux2->prox;
        }
    }
}

//Fun��o de busca
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

//Fun��o de exibi��o
void exibir(TLista L){
    if( L != NULL ){
        printf("%d ", L->valor);
        exibir(L->prox);
    }
}

//Fun��o de ordena��o da L3, para coloc�-la em ordem crescente
void ordena(TLista *L) {
     //Defini��o das vari�veis
     TLista atual, seguinte, temporario;
     //Aloca��o de mem�ria tempor�ria para manipula��o dos ponteiros posteriormente
     temporario = (TLista) malloc (sizeof(TNo));
     // 'atual' iniciando na cabe�a da lista L
     atual = *L;
     //Enquanto a lista L n�o chegar ao fim
     while( atual != NULL) {
            //O ponteiro 'seguinte' recebe a pr�xima caixinha da lista L, na qual ser� importante para posteriormente comparar o n�mero atual com o pr�ximo
            seguinte = atual->prox;
            while (seguinte != NULL) {
                    //Compara o valor atual com o pr�ximo
                   if (atual->valor > seguinte->valor){
                         *temporario = *atual ; // copia valor de 'atual' em 'temporario'.
                         *atual =  *seguinte; // copia valor de 'seguinte' em 'atual'.
                         atual->prox = temporario->prox; // altera ponteiro do pr�ximo de 'atual' para que ele continue sendo o mesmo que era antes da copia
                         temporario->prox = seguinte->prox; // copia o valor do ponteiro do proximo 'seguinte'
                         *seguinte = *temporario; // copia valor de temporario em 'seguinte'.
                          seguinte->prox = temporario->prox; // altera ponteiro do pr�ximo de 'atual' para que ele continue sendo o mesmo que era antes da copia
                        printf("\nseguinte %d \n", seguinte->valor);
                        printf("\atual %d \n", atual->valor);
                   }
                   seguinte = seguinte->prox;
            }
      atual = atual->prox;
    }
    //Liberando mem�ria alocada temporariamente
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

