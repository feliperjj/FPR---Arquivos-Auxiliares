/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna
	
	Arquivos
	
	- Exemplo de uso da fun��o 'fread'  (lendo todos os carros do arquivo de uma �nica vez)
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de constantes
#define TAM 5

#define TRUE 1
#define FALSE 0

//defini��o de tipos
typedef enum {ZERO, USADO} tipoCarro;

typedef struct {			//representa os anos de modelo e fabrica��o do carro
	int anoModelo;
	int anoFabricacao;
} TAno;

typedef struct {			//representa um carro e todas as suas informa��es
	char placa[10];
	char modelo[20];
	char marca[20];
	char cor[20];
	float km;
	TAno ano;
	float valor;
	tipoCarro tipo;	
} TCarro;

//prot�tipos das fun��es
int carregar (TCarro ag[], int tamanho, char nomeArq[]);
void exibirDadosCarro (TCarro carro);
void exibirTodosCarros (TCarro ag[], int quantidade);

//main
void main ()
{
	//declara��o de vari�veis
	TCarro agencia[TAM];	
		
	//tentando carregar para o vetor de structs os dados do arquivo 'carros.bin'
	if (carregar (agencia, TAM, "carros.bin") == TRUE)
	{
		printf ("\nDados carregados com sucesso!\n\nDados dos carros carregados para o vetor de struct:\n\n");
		
		exibirTodosCarros (agencia, TAM);
	}
	else
	{
		printf ("\nFalha ao acessar o arquivo!");
	}
}

//implementa��o das fun��es

int carregar (TCarro ag[], int tamanho, char nomeArq[])
{
	//declara��o de vari�veis
	int i;
	FILE *arq;		//declara��o do arquivo
	
	//abrindo o arquivo para leitura (arquivo bin�rio)
	arq = fopen (nomeArq, "rb");
	
	//verificando se houve erro na abertura do arquivo
	if (arq == NULL)
	{
		return FALSE;
	}
	else
	{
		//lendo todos os dados do arquivo para o vetor de structs, de uma �nica vez
		fread (ag, sizeof(TCarro), TAM, arq);
	
		//fechando o arquivo
		fclose (arq);
		
		return TRUE;
	}
}

void exibirDadosCarro (TCarro carro)
{
	printf ("\nPlaca: %s\n", carro.placa);
	printf ("Modelo/Marca: %s/%s\n", carro.modelo, carro.marca);
	printf ("Cor: %s\n", carro.cor);
	printf ("km: %.2f\n", carro.km);
	printf ("Ano: %d/%d\n", carro.ano.anoFabricacao, carro.ano.anoModelo);
	printf ("Valor: R$ %.2f\n", carro.valor);
	printf ("Tipo: ");
	printf (carro.tipo==USADO?"Usado\n\n":"Zero\n\n");	
}

void exibirTodosCarros (TCarro ag[], int quantidade)
{
	//declara��o de vari�veis
	int i, cont=0;
	
	//percorrendo o vetor que representa a ag�ncia de carros
	for (i=0;i<quantidade;i++)
	{
		exibirDadosCarro (ag[i]);
	}
}


