/*QUESTÃO 04: Fazer uma função que, dada uma matriz M6×6,
determine se ela é simétrica.*/

#include <stdio.h>
#define L 3
#define C 3

void main(){
//     PARA SER SIMETRICA::
    /*int matrizOriginal[L][C] = { {2, 5, 11},
                                 {5, 4, 17},
                                 {11, 17, 6}};*/
    // PARA NÃO SER SIMÉTRCA::
    int matrizOriginal[L][C];
    int matrizTransposta[L][C];
    int conferidor;
    preencher(matrizOriginal);
    printf ("\n\nExibindo a matriz original:\n\n");
    exibir(matrizOriginal);
    transposta(matrizOriginal, matrizTransposta);
    printf ("\n\nExibindo a matriz transposta:\n\n");
	exibirTransposta(matrizTransposta);
	conferidor=confereSimetria(matrizOriginal,matrizTransposta);

}

void preencher (int m[L][C])
{
	//declaração de variáveis
	int i, j;

	//garantindo que as sequências aleatórias são diferentes
	srand (time(NULL));

	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			m[i][j] = rand()%100 + 1;
		}
	}
}

void exibir (int m[L][C]){
	int i, j;
	for (i=0;i<L;i++){
		for (j=0;j<C;j++){
			printf ("%3d ", m[i][j]);
		}
		printf ("\n");
	}
}

void transposta (int m[L][C], int t[C][L]){
	int i, j;
	for (i=0;i<C;i++){
		for (j=0;j<L;j++){
			t[i][j] = m[j][i];
		}
	}
}

void exibirTransposta (int t[C][L]){
	int i, j;
	for (i=0;i<C;i++){
		for (j=0;j<L;j++){
			printf ("%3d ", t[i][j]);
		}
		printf ("\n");
	}
}

int confereSimetria (int m[L][C], int n[L][C]){
    int i, j;
    for (i=0; i<L; i++){
        for (j=i+1; j<C; j++){
            if (m[i][j]!=n[i][j]){
                printf("\n\nMatrizes nao simetricas");
                return 0;
            } else {
                printf("\n\nMatrizes simetricas");
                return 1;
            }
        }
    }
}
