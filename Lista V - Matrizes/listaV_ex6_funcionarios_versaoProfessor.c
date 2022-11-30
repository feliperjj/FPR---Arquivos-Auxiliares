/*
	FPR - Professor Leonardo Vianna
	Turma: Manh�
	Data: 14/04/2022

	Lista de Exerc�cios V (Matrizes)

	QUEST�O 06:
	Considere uma loja que mant�m em uma matriz o total vendido por cada funcion�rio pelos diversos meses do ano.
	Ou seja, uma matriz de 12 linhas (uma por m�s) e 10 colunas (10 funcion�rios). Pede-se o desenvolvimento de uma
	fun��o para cada item abaixo:

	a.	Calcular o total vendido durante o ano;
	b.	Dado um m�s fornecido pelo usu�rio, determinar o total vendido nesse m�s;
	c.	Dado um funcion�rio fornecido pelo usu�rio, determinar o total vendido por ele durante o ano;
	d.	Determinar o m�s com maior �ndice de vendas;
	e.	Determinar o funcion�rio que menos vendeu durante o ano.
*/

//importa��o de bibliotecas
#include <stdio.h>

//defini��o de constantes
#define L 12
#define C 10

//prot�tipos das fun��es
float totalVendidoAno (float m[L][C]);
float totalVendidoMes (float m[L][C], int mes);
float totalVendidoFuncionario (float m[L][C], int funcionario);
int   mesMaiorIndiceVendas (float m[L][C]);
int   funcionarioMenorIndiceVendas (float m[L][C]);

void preencherMatriz (float m[L][C]);
void exibirMatriz (float m[L][C]);

//main
void main ()
{
	//declara��o de vari�veis
	float matriz[L][C];
	float total;
	int mes, funcionario;

	//preenchendo a matriz com n�meros aleat�rios
	preencherMatriz (matriz);

	//exibindo a matriz
	printf ("Exibindo a matriz:\n\n");
	exibirMatriz (matriz);

	//calculando o total vendido no ano
	total = totalVendidoAno (matriz);
	printf ("\n\nTotal vendido no ano: R$ %.2f\n", total);

	//lendo o m�s desejado
	printf ("\nEntre com o mes desejado: ");
	scanf ("%d", &mes);

	//Calculando o total vendido no m�s especificado
	total = totalVendidoMes (matriz, mes);
	printf ("\n\nTotal vendido no mes %d: R$ %.2f\n", mes, total);

	//lendo o funcion�rio desejado
	printf ("\nEntre com o numero do funcionario: ");
	scanf ("%d", &funcionario);

	//Calculando o total vendido pelo funcion�rio especificado
	total = totalVendidoFuncionario (matriz, funcionario);
	printf ("\n\nTotal vendido pelo funcionario %d: R$ %.2f\n", funcionario, total);

	//determinando o m�s com maior �ndice de vendas
	mes = mesMaiorIndiceVendas (matriz);
	printf ("\n\nMes com maior indice de vendas: %d\n", mes);

	//determinando o funcion�rio com menor �ndice de vendas
	funcionario = funcionarioMenorIndiceVendas (matriz);
	printf ("\n\nFuncionario com menor indice de vendas: %d\n", funcionario);
}

//implementa��o das fun��es
void preencherMatriz (float m[L][C])
{
	//declara��o de vari�veis
	int i, j;

	//garantindo que as sequ�ncias aleat�rias s�o diferentes
	srand (time(NULL));

	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			m[i][j] = rand()%1000 + 1;
		}
	}
}

void exibirMatriz (float m[L][C])
{
	//declara��o de vari�veis
	int i, j;

	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			printf ("%.2f\t", m[i][j]);
		}

		printf ("\n");
	}
}

//Calcular o total vendido durante o ano.
float totalVendidoAno (float m[L][C])
{
	//declara��o de vari�veis
	int i, j;
	float soma = 0;

	//percorrendo as linhas
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas
		for (j=0;j<C;j++)
		{
			//acumulando o somat�rio
			soma += m[i][j];
		}
	}

	//retornando a soma
	return soma;
}

//Dado um m�s fornecido pelo usu�rio, determinar o total vendido nesse m�s.
float totalVendidoMes (float m[L][C], int mes)
{
	//declara��o de vari�veis
	int j;
	float soma = 0;

	//transformando o m�s do intervalo de 1..12 para 0..11
	mes--;

	//percorrendo as colunas da matriz, na linha representada pelo m�s
	for (j=0;j<C;j++)
	{
		soma += m[mes][j];
	}

	//retornando a soma
	return soma;
}

//Dado um funcion�rio fornecido pelo usu�rio, determinar o total vendido por ele durante o ano.
float totalVendidoFuncionario (float m[L][C], int funcionario)
{
	//declara��o de vari�veis
	int i;
	float soma = 0;

	//transformando o funcion�rio do intervalo de 1..10 para 0..9
	funcionario--;

	//percorrendo as linhas da matriz, na coluna representada pelo funcion�rio
	for (i=0;i<L;i++)
	{
		soma += m[i][funcionario];
	}

	//retornando a soma
	return soma;
}

//Determinar o m�s com maior �ndice de vendas.
int   mesMaiorIndiceVendas (float m[L][C])
{
	//declara��o de vari�veis
	float maior, total;
	int mesMaior, mes;

	//inicializando 'maior' com o total vendido no primeiro m�s (janeiro)
	maior = totalVendidoMes (m, 1);
	mesMaior = 1;

	//calculando o total vendido nos demais meses e comparando com 'maior'
	for (mes=2;mes<=L;mes++)
	{
		//calculando o total vendido em 'mes'
		total = totalVendidoMes (m, mes);

		//verificando se h� necessidade de atualizar 'maior'
		if (total > maior)
		{
			maior = total;
			mesMaior = mes;
		}
	}

	//retornando o resultado
	return mesMaior;
}

//Determinar o funcion�rio que menos vendeu durante o ano.
int   funcionarioMenorIndiceVendas (float m[L][C])
{
	//declara��o de vari�veis
	float menor, total;
	int funcionarioMenor, funcionario;

	//inicializando 'menor' com o total vendido pelo primeiro funcion�rio
	menor = totalVendidoFuncionario (m, 1);
	funcionarioMenor = 1;

	//calculando o total vendido pelos demais funcion�rios e comparando com 'menor'
	for (funcionario=2;funcionario<=C;funcionario++)
	{
		//calculando o total vendido pelo 'funcionario'
		total = totalVendidoFuncionario (m, funcionario);

		//verificando se h� necessidade de atualizar 'menor'
		if (total < menor)
		{
			menor = total;
			funcionarioMenor = funcionario;
		}
	}

	//retornando o resultado
	return funcionarioMenor;
}
