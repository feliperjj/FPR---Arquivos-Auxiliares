/*
Considere uma loja que mantém em uma matriz o total vendido por cada funcionário pelos diversos meses do ano. Ou seja, uma matriz de 12 linhas (uma por mês)
e 10 colunas (10 funcionários). Pede-se o desenvolvimento de uma função para cada item abaixo:

a. Calcular o total vendido durante o ano;

b. Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês;

c. Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano;

d. Determinar o mês com maior índice de vendas;

e. Determinar o funcionário que menos vendeu durante o ano.
*/

#include <stdio.h>
#define MES 3
#define FUNC 2

void main(){
    int totalVendido[MES][FUNC];
    int totalAnual, totalMensal, totalFuncionario, mes, funcionario;

    povoaMatriz(totalVendido);

    totalAnual=calculaAnual(totalVendido);
    exibeAnual(totalAnual);

    printf("\nInsira um mes para saber o total vendido: ");
    scanf("%d",&mes);

    totalMensal=calculaMes(totalVendido,mes);
    exibeMes(totalMensal);

    printf("\nInsira um funcionario para saber o total vendido por ele: ");
    scanf("%d",&funcionario);

    totalFuncionario=calculaFuncionario(totalVendido,funcionario);
    exibeFuncionario(totalFuncionario,funcionario);

    mesMaisVendas(totalVendido);

    menosVendas(totalVendido);
}

void povoaMatriz(int matriz[MES][FUNC]){
    int i, j;
    for (i=0;i<MES;i++){
        for (j=0;j<FUNC;j++){
            printf("\nInsira o valor vendido pelo funcionario [%d] no mes [%d]: ", j,i);
            scanf("%d",&matriz[i][j]);
        }
    }
}

int calculaAnual(int matriz[MES][FUNC]){
    int i, j;
    int total=0;
    for (i=0;i<MES;i++){
        for (j=0;j<FUNC;j++){
            total=total+matriz[i][j];
        }
    }

    return total;
}

void exibeAnual(int totalAnual){
    printf("\n...............................\n");
    printf("\nTotal anual: %d\n", totalAnual);
    printf("\n...............................\n");
}

int calculaMes(int matriz[MES][FUNC], int mes){
    int i,j;
    int total;
    for (i=0;i<mes;i++){
        total=0;
        for (j=0;j<FUNC;j++){
            if (i=mes){
                total=total+matriz[i][j];
            }
        }
    }
    return total;
}

void exibeMes (int totalMensal, int mes){
    printf("\n...............................\n");
    printf("\nTotal do mes %d: %d\n", mes,totalMensal);
    printf("\n...............................\n");
}

int calculaFuncionario(int matriz[MES][FUNC], int funcionario){
    int i,j;
    int total=0;
    for (i=0;i<funcionario;i++){
        for (j=0;j<MES;j++){
            if (i=funcionario){
                total=total+matriz[i][j];
            }
        }
    }
    return total;
}

void exibeFuncionario (int totalFuncionario, int funcionario){
    printf("\n...............................\n");
    printf("\nTotal vendido pelo funcionario %d: %d\n", funcionario,totalFuncionario);
    printf("\n...............................\n");
}

void mesMaisVendas(int matriz[MES][FUNC]){
    int i, j;
    int maior=0, totalMes, maiorMes;
    for (i=0;i<MES;i++){
        totalMes=0;
        for (j=0;j<FUNC;j++){
            totalMes=totalMes+matriz[i][j];
            if (totalMes>maior){
                maior=totalMes;
                maiorMes=i;
            }
        }
    }

    printf("\nO mes com mais vendas foi: %d\n",maiorMes);
    printf("\n...............................\n");
}

void menosVendas(int matriz[MES][FUNC]){
    int i,j;
    int menor=999, totalMes, menorFunc;
    for (i=0;i<MES;i++){
        totalMes=0;
        for (j=0;j<FUNC;j++){
            totalMes=totalMes+matriz[i][j];
            if (totalMes<menor){
                menor=totalMes;
                menorFunc=i;
            }
        }
    }

    printf("\nO funcionário com menos vendas foi: %d\n",menorFunc);
    printf("\n...............................\n");
}
