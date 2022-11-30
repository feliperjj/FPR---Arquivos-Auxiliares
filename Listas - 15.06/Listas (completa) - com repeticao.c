/*
	FAETERJ-Rio
	Fundamentos de Programa��o  -  2022/1
	Turma: Manh�
	Data: 22/06/2022
	
	Listas din�micas (ou seja, listas por ponteiros)
	
	[implementa��o completa]
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

typedef TNo* TLista;  //ou     typedef *TNo TLista;

//prot�tipos das fun��es
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int numeroIni, int numeroAlt);
int buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista L = NULL;
	int num1, num2, op, quant;
	
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
			        if (inserir (&L, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remo��o
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        quant = remover (&L, num1);
			        
					if (quant > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Altera��o
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a fun��o
			        quant = alterar (L, num1, num2);
			        
			        if (quant > 0)
			        {
			        	printf ("\n\t%d alteracoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a fun��o
			        if (buscar (L, num1) == TRUE)
			        {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					else
					{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Sa�da
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 6);
}


//implementa��o das fun��es
int inserir (TLista *L, int numero)
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
		
		//Passo 3: fazer o campo 'prox' do novo n� apontar para o "at� ent�o" primeiro n� da lista
		aux->prox = *L;
		
		//Passo 4: fazer '*L' apontar para o novo n�
		*L = aux;
		
		return TRUE;
	}
}

int remover (TLista *L, int numero)
{
	//declara��o de vari�veis
	TLista aux1, aux2;
	int cont = 0;
	
	//verificando se o primeiro elemento � o n�mero a ser removido
	while ((*L != NULL) && ((*L)->valor == numero))
	{
		//passo 1: fazer 'aux1' apontar para o primeiro n�
		aux1 = *L;
		
		//passo 2: fazer o L apontar para o pr�ximo elemento (aquele que at� ent�o era o segundo n� da lista)
		*L = (*L)->prox;   //ou  *L = aux1->prox;
		
		//passo 3: liberar a mem�ria alocada ao n� a ser removido
		free (aux1);
		
		//atualizando a quantidade de remo��es realizadas
		cont++;
	}
	
	//verificando se a lista ainda existe
	if (*L != NULL)
	{
		//fazendo 'aux1' e 'aux2' apontarem para os dois primeiros n�s
		aux2 = *L;
		aux1 = (*L)->prox;    //ou  aux1 = aux2->prox;
		
		//varrendo a lista at� o seu final
		while (aux1 != NULL)
		{	
			//verificando se 'aux1' est� apontando para o n�mero a ser removido
			if (aux1->valor == numero)
			{
				//fazer com que o n� anterior ao que est� sendo removido aponte para o pr�ximo n� daquele sendo removido
				aux2->prox = aux1->prox;
				
				//liberar a mem�ria alocada ao n� a ser removido
				free (aux1);
				
				//atualizando a quantidade de remo��es realizadas
				cont++;
				
				//atualizar 'aux1' de forma que aponte para o pr�ximo de 'aux2'
				aux1 = aux2->prox;
			}
			else
			{
				//andar com os ponteiros 'aux1' e 'aux2'
				aux2 = aux1;		 //ou aux2 = aux2->prox; 
				aux1 = aux1->prox;   //ou aux1 = aux2->prox;
			}
		}
	}
	
	//retornando a quantidade de remo��es realizadas
	return cont;
}

int alterar (TLista L, int numeroIni, int numeroAlt)
{
	//declara��o de vari�veis
	TLista aux;
	int cont = 0;
	
	//fazer com que 'aux' aponte para o primeiro n� da lista
	aux = L;
		
	while (aux != NULL) //while (aux)
	{
		//verificando se 'aux' esty� apontando para o valor a ser alterado
		if (aux->valor == numeroIni)
		{
			aux->valor = numeroAlt;
			cont++;
		}
						
		//atualizar o 'aux', de forma que aponte para o pr�ximo n�
		aux = aux->prox;
	}
	
	//retornando a quantidade de altera��es realizadas
	return cont;
}

int buscar (TLista L, int numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//fazer com que 'aux' aponte para o primeiro n� da lista
	aux = L;
		
	while (aux != NULL) //while (aux)
	{
		//verificando se o valor apontado por 'aux' � o n�mero sendo buscado
		if (aux->valor == numero)
		{
			return TRUE;			
		}
						
		//atualizar o 'aux', de forma que aponte para o pr�ximo n�
		aux = aux->prox;
	}
	
	//elemento n�o existe na lista
	return FALSE;
}

void exibir (TLista L)
{
	//declara��o de vari�veis
	TLista aux;
	
	//verificando se a lista est� vazia
	if (L == NULL)   //if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Elementos da lista: ");
		
		//fazer com que 'aux' aponte para o primeiro n� da lista
		aux = L;
		
		while (aux != NULL) //while (aux)
		{
			//exibindo cada elemento da lista
			printf ("%d ", aux->valor);
			
			//atualizar o 'aux', de forma que aponte para o pr�ximo n�
			aux = aux->prox;
		}
		
		printf ("\n");	
	}
}

int menu ()
{
	//declara��o de vari�veis
	int opcao;
	
	//exibindo o meu ao usu�rio
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a op��o do usu�rio
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a op��o escolhida
	return opcao;
}
