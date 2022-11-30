#include <stdio.h>
//Definicao de constantes 
#define TRUE 1
#define FALSE 0

//Defini��o de tipos
typedef struct No{
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

void main(){
	TLista Lista = NULL;
}

int inserir(TLista *L, int numero){
	//declara��o de variaveis
	TLista aux;
	//Passo 1: alocar memoria para novo no -- criar um novo item na lista
	aux= (TLista) malloc (sizeof(TNo));
	//verificando se a memoria foi alocada
	if (aux == NULL){
		return FALSE;
	} else {
		//Passo 2: armazenar numero no nnovo n�
		aux->valor=numero;
		//Passo 3: fazer o campo 'prox' do novo n� apontar para o at� ent�o primeiro elemento
		aux->prox=*L;
		//passo 4: fazer l apontar para aux
		*L=aux;
		return TRUE;
	}
}

int remover(TLista *L, int numero){
	
}

int alterar(TLista L, int numeroIni, int numeroAlt){
	TLista aux;
	int cont=0;
	aux = L;
	while (aux!=NULL){
		if (aux->valor == numeroIni){
			aux->valor = numeroAlt;
			cont++;
		}
		aux=aux->prox;
	}
	//retornando a quantidade de altera��es realizadas
	return cont;
}

int buscar(TLista L, int numero){
	TLista aux;
	aux = L;
	while (aux!=NULL){
		if (aux->valor == numero ){
			return TRUE;
		} 
		aux=aux->prox;
	}
	//Elemento n�o existe
	return FALSE; 
}

void exibir(TLista L){
	TLista aux;
	printf("Elementos da lista: ");
	//verificar se a lista est� vazia
	if (L==NULL){
		printf("\nLista vazia.");
	}
	// fazer com que aux aponte para o primeiro n�
	aux = L;
	while (aux != NULL){ //CASO COLOCAR while (aux->prox != NULL) VC PARA UMA INTERA��O ANTES
		printf("%d",aux->valor);
		aux=aux->prox;		
	}
}
