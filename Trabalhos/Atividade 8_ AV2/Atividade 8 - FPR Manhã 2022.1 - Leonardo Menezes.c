#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

int inserir (TLista *L, int num);
void exibir (TLista L);
int juntar(TLista L1, TLista L2, TLista *L3);

void main ()
{
	TLista L = NULL;
	TLista L2 = NULL;
	TLista L3 = NULL;
	int num1, num2;

	printf("Qual o numero maximo da Lista 1? ");
	scanf("%d", &num1);

	inserir(&L, num1)==TRUE ? printf("\nMemoria Alocada com sucesso! \n") : printf("\nERRO: Memoria em falta! \n");
	exibir(L);
	printf("\n");

	printf("Qual o numero maximo da Lista 2? ");
	scanf("%d", &num2);
	inserir(&L2, num2)==TRUE ? printf("\nMemoria Alocada com sucesso! \n") : printf("\nERRO: Memoria em falta! \n");

	exibir(L2);
	printf("\n");

	//Chamada da funcao para fundir as listas "L1" e "L2"
	if(juntar(L, L2, &L3)==TRUE)
	{
		printf("\n --- LISTA NOVA --- \n");
		exibir(L3);
	}
	else
	{
		printf("ERRO: Alguma das listas esta vazia!");
	}
}

int inserir (TLista *L, int num)
{
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
                //Passo 2: armazenar 'numero' no novo nó
                aux->valor = rand() % 10;
                //Passo 3: fazer o campo 'prox' do novo nó apontar para o "até então" primeiro nó da lista
                aux->prox = *L;
                //Passo 4: fazer '*L' apontar para o novo nó
                *L = aux;
            }
        }
	}
	return TRUE;
}

int juntar(TLista L1, TLista L2, TLista *L3)
{
	TLista aux1, aux2, aux3, percorrer;
	aux1=L1;
	aux2=L2;
	if(aux1==NULL||aux2==NULL)
	{
		//caso alguma das listas esteja vazia, retorna falso
		return FALSE;
	}
	else
	{
		//Insercao do primeiro valor de "L3"
		if(aux1->valor < aux2->valor)
		{
			aux3 = (TLista) malloc (sizeof(TNo));
			aux3->valor = aux1->valor;

			*L3 = aux3;

			aux3->prox= NULL;

			aux1=aux1->prox;
		}
		else
		{
			if(aux1->valor > aux2->valor)
			{
				aux3 = (TLista) malloc (sizeof(TNo));
				aux3->valor = aux2->valor;

				*L3 = aux3;

				aux3->prox= NULL;

				aux2=aux2->prox;
			}
			else
			{
				//verificacao de valores repetidos
				aux3 = (TLista) malloc (sizeof(TNo));
				aux3->valor = aux1->valor;

				*L3 = aux3;

				aux3->prox = NULL;

				aux1=aux1->prox;
				aux2=aux2->prox;
			}
		}
		//Insercao do resto
		while(aux1!=NULL&&aux2!=NULL)
		{
			if(aux1->valor < aux2->valor)
			{
				aux3 = (TLista) malloc (sizeof(TNo));
				aux3->valor = aux1->valor;

				//percorrer segue para o final da lista
				percorrer= *L3;
				while(percorrer->prox!=NULL)
				{
					percorrer=percorrer->prox;
				}
				percorrer->prox = aux3;
				aux3->prox=NULL;

				aux1=aux1->prox;
				//caso a lista 1 tenha terminado, insere o resto da lista 2
				if(aux1==NULL)
				{
					while(aux2!=NULL)
					{

						aux3 = (TLista) malloc (sizeof(TNo));
						aux3->valor = aux2->valor;

						//percorrer continua da ultima posicao da onde parou fora do while
						percorrer=percorrer->prox;
						percorrer->prox = aux3;

						aux3->prox=NULL;
						aux2=aux2->prox;
					}
				}
			}
			else
			{
				if(aux1->valor > aux2->valor)
				{
					aux3 = (TLista) malloc (sizeof(TNo));
					aux3->valor = aux2->valor;

					//percorrer segue para o final da lista
					percorrer= *L3;
					while(percorrer->prox!=NULL)
					{
						percorrer=percorrer->prox;
					}
					percorrer->prox = aux3;

					aux3->prox=NULL;

					aux2=aux2->prox;
					//caso a lista 2 tenha terminado, insere o resto da lista 1
					if(aux2==NULL)
					{
						while(aux1!=NULL)
						{
							aux3 = (TLista) malloc (sizeof(TNo));
							aux3->valor = aux1->valor;

							//percorrer continua da ultima posicao da onde parou fora do while
							percorrer=percorrer->prox;
							percorrer->prox = aux3;

							aux3->prox=NULL;
							aux1=aux1->prox;
						}
					}
				}
				//verificacao de numero repetido
				else
				{
					aux3 = (TLista) malloc (sizeof(TNo));
					aux3->valor = aux1->valor;

					//percorrer segue para o final da lista
					percorrer= *L3;
					while(percorrer->prox!=NULL)
					{
						percorrer=percorrer->prox;
					}
					percorrer->prox = aux3;

					aux3->prox=NULL;

					aux1=aux1->prox;
					aux2=aux2->prox;

					//caso alguma das listas tenha finalizado, verifica qual das ainda possui valores
					if(aux1==NULL||aux2==NULL)
					{
						//caso a lista 1 tenha terminado, insere o resto da lista 2
						while(aux2!=NULL)
						{
							aux3 = (TLista) malloc (sizeof(TNo));
							aux3->valor = aux2->valor;

							//percorrer continua da ultima posicao da onde parou fora do while
							percorrer=percorrer->prox;
							percorrer->prox = aux3;

							aux3->prox=NULL;
							aux2=aux2->prox;
						}
						//caso a lista 2 tenha terminado, insere o resto da lista 1
						while(aux1!=NULL)
						{
							aux3 = (TLista) malloc (sizeof(TNo));
							aux3->valor = aux1->valor;

							//percorrer continua da ultima posicao da onde parou fora do while
							percorrer=percorrer->prox;
							percorrer->prox = aux3;

							aux3->prox=NULL;
							aux1=aux1->prox;
						}
					}
				}
			}
		}
	}
	return TRUE;
}

void exibir (TLista L)
{
	TLista aux;

	if (L == NULL)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Elementos da lista: ");

		aux = L;

		while (aux != NULL)
		{
			printf ("%d ", aux->valor);

			aux = aux->prox;
		}

		printf ("\n");
	}
}



