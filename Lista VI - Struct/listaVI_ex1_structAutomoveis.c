/*
	Quest�o 01:
	Uma loja de autom�veis mant�m os carros � venda sob a forma de um vetor de structs
	contendo as seguintes informa��es, para cada ve�culo: placa, modelo, marca, cor,
	quilometragem, ano modelo/fabrica��o (deve ser um struct), valor e tipo (usado ou 0 km,
	conforme o valor do campo quilometragem).

	Pede-se a declara��o de uma vari�vel que represente o estoque de ve�culos da loja,
	incluindo todas as declara��es de tipos que possam ser necess�rias.

	Al�m disso, implementar as seguintes fun��es:
		i.	Exibir todos os carros do modelo m, ano de fabrica��o entre a1 e a2 (inclusive),
		    com valor n�o superior a x reais;
		ii.	Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
		iii.Retirar do estoque um determinado ve�culo, dada a sua placa.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de constantes
#define NUM_CARROS 5

//defini��o de tipos
typedef enum {ZERO, USADO} TipoCarro;
typedef enum {FALSE, TRUE} TLogico;

typedef struct {
	int fabricacao;
	int modelo;
} TAno;

typedef struct {
	char placa[10];
	char modelo[20];
	char marca[20];
	char cor[20];
	float quilometragem;
	TAno ano;
	float valor;
	TipoCarro tipo;
} TCarro;

//prot�tipos das fun��es
void exibirCarrosFiltros (TCarro ag[], int quantidade, char m[], int a1, int a2, float x);
void reajustarCarros0km (TCarro ag[], int quantidade, float taxa);  //pelo enunciado, nem precisaria da taxa, por ser fixa em 2.5%
TLogico removerVeiculos (TCarro ag[], int *quantidade, char placa[]);

void preencherVetor (TCarro ag[]);
void exibirDadosCarro (TCarro carro);
void exibirTodosCarros (TCarro ag[], int quantidade);

//main
void main ()
{
	//declara��o de vari�veis
	TCarro agencia[NUM_CARROS];
	int quantCarros = NUM_CARROS;
	char modeloSolicitado[10], placaSolicitada[10];
	int anoSolicitadoInicio, anoSolicitadoFim, valorMax;

	//preenchendo o vetor para que as demais fun��es possam ser testadas
	preencherVetor (agencia);

	//exibindo os carros que atenderem aos filtros definidos
	printf("-----------BUSCA DE CARROS POR REQUISTOS-----------\n");
	printf("Modelo: ");
	fflush(stdin);
	gets(modeloSolicitado);

	printf("\nAno [inicial]: ");
	scanf("%d", &anoSolicitadoInicio);

	printf("\nAno [final]: ");
	scanf("%d", &anoSolicitadoFim);

	printf("\nValor maximo: ");
	scanf("%f", &valorMax);

	exibirCarrosFiltros (agencia, quantCarros, modeloSolicitado, anoSolicitadoInicio, anoSolicitadoFim, valorMax);

	printf("-----------RECALCULANDO VALORES DE CARROS ZERO-----------\n");
    reajustarCarros0km(agencia, quantCarros, 2.5);

    printf("--------------EXIBINDO CARROS APOS REAJUSTE--------------\n");
    exibirTodosCarros(agencia, quantCarros);

    printf("----------------REMOVENDO CARRO DO ESTOQUE---------------\n");
    printf("Placa: ");
    fflush(stdin);
    gets(placaSolicitada);

    if (removerVeiculos(agencia, &quantCarros, placaSolicitada) == TRUE){
        printf ("\n\tCarro removido com sucesso!\n");
		exibirTodosCarros (agencia, quantCarros);
	} else {
        printf("\nPlaca n�o localizada!\n");
	}

}

// ----FUN��ES-----

// Preenche o vetor de carros com dados pr�-definidos, auxiliando o processo de teste das fun��es solicitadas
void preencherVetor (TCarro ag[])
{
	//1� carro
	strcpy (ag[0].placa, "ABC 1234");
	strcpy (ag[0].modelo, "HB20");
	strcpy (ag[0].marca, "HYUNDAI");
	strcpy (ag[0].cor, "PRATA");
	ag[0].quilometragem = 20000;
	ag[0].ano.modelo = 2016;
	ag[0].ano.fabricacao = 2015;
	ag[0].valor = 25000;
	ag[0].tipo = USADO;

	//2� carro
	strcpy (ag[1].placa, "BCD 2345");
	strcpy (ag[1].modelo, "CIVIC");
	strcpy (ag[1].marca, "HONDA");
	strcpy (ag[1].cor, "BRANCA");
	ag[1].quilometragem = 0;
	ag[1].ano.modelo = 2022;
	ag[1].ano.fabricacao = 2022;
	ag[1].valor = 90000;
	ag[1].tipo = ZERO;

	//3� carro
	strcpy (ag[2].placa, "CDE 3456");
	strcpy (ag[2].modelo, "HB20");
	strcpy (ag[2].marca, "HYUNDAI");
	strcpy (ag[2].cor, "PRETA");
	ag[2].quilometragem = 45000;
	ag[2].ano.modelo = 2017;
	ag[2].ano.fabricacao = 2017;
	ag[2].valor = 35000;
	ag[2].tipo = USADO;

	//4� carro
	strcpy (ag[3].placa, "EFG 4567");
	strcpy (ag[3].modelo, "HB20");
	strcpy (ag[3].marca, "HYUNDAI");
	strcpy (ag[3].cor, "AZUL");
	ag[3].quilometragem = 58000;
	ag[3].ano.modelo = 2019;
	ag[3].ano.fabricacao = 2018;
	ag[3].valor = 40000;
	ag[3].tipo = USADO;

	//5� carro
	strcpy (ag[4].placa, "FGH 5678");
	strcpy (ag[4].modelo, "ECOSPORT");
	strcpy (ag[4].marca, "FORD");
	strcpy (ag[4].cor, "VERDE");
	ag[4].quilometragem = 0;
	ag[4].ano.modelo = 2022;
	ag[4].ano.fabricacao = 2022;
	ag[4].valor = 85000;
	ag[4].tipo = ZERO;
}

// Exibir todos os carros do modelo m, ano de fabrica��o entre a1 e a2 (inclusive), com valor n�o superior a x reais
void exibirCarrosFiltros (TCarro ag[], int quantidade, char m[], int a1, int a2, float x)
{
	int i, cont = 0;
	for (i=0;i<quantidade;i++)
	{
		//verificando se o carro da posi��o 'i' atende aos filtros especificados
		if ((strcmp (ag[i].modelo, m) == 0) &&								  //filtro modelo
		    (ag[i].ano.fabricacao >= a1) && ((ag[i].ano.fabricacao <= a2)) && //filtro ano de fabrica��o
			(ag[i].valor <= x))												  //filtro valor
		{
			//todos os filtros atendidos
			exibirDadosCarro (ag[i]);

			//atualizando a quantidade de carros que atenderam aos filtros
			cont++;
		}
	}

	//verificando se nenhum carro atendeu aos filtros especificados
	if (cont == 0)
	{
		printf ("\nNenhum carro atendeu aos filtros definidos!\n\n");
	}
}

// Exibir todos os dados do carro passado por par�metro
void exibirDadosCarro (TCarro carro)
{
	printf ("\nPlaca: %s\n", carro.placa);
	printf ("Modelo/Marca: %s/%s\n", carro.modelo, carro.marca);
	printf ("Cor: %s\n", carro.cor);
	printf ("km: %.2f\n", carro.quilometragem);
	printf ("Ano: %d/%d\n", carro.ano.fabricacao, carro.ano.modelo);
	printf ("Valor: R$ %.2f\n", carro.valor);
	printf ("Tipo: ");
	printf (carro.tipo==USADO?"Usado\n\n":"Zero\n\n");
}

// Exibindo todos os carros da ag�ncia
void exibirTodosCarros (TCarro ag[], int quantidade)
{
	int i, cont=0;
	for (i=0;i<quantidade;i++)
	{
		exibirDadosCarro (ag[i]);
	}
}

void reajustarCarros0km(TCarro ag[], int quantidade, float taxa){
    int i;
    for (i=0;i<quantidade;i++){
        if (ag[i].tipo==ZERO){
            ag[i].valor = ag[i].valor + (ag[i].valor*taxa/100);
        }
    }
}

TLogico removerVeiculos(TCarro ag[], int *quantidade, char placa[]){
    int i, j;
    // Percorrendo o vetor TCarro
    for (i=0;i<*quantidade;i++){
        // Verificando se o carro possui a placa especificada
        if ( strcmp(ag[i].placa, placa) == 0 ){
            // Deslocar � esquerda os carros que est�o al�m da posi��o 'i'
            for (j=i;j<*quantidade;j++){
                ag[j]=ag[j+1];
            }
            (*quantidade)--;
            return TRUE;
        }
    }
    return FALSE;
}
