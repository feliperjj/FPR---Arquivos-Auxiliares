/*
SOMAR MATRIZES
*/

#define M 4
#define N 3

int main()
{
 int a[M][N] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
 int b[M][N] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };

 int c[M][N]; // c não precisa ser inicializada neste momento...

 // calculando o valor de cada célula da matriz c
 for (int i = 0; i < M; i++)
 for (int j = 0; j < N; j++)
 c[i][j] = a[i][j] + b[i][j];

 // imprimindo matriz c
 for (int i = 0; i < M; i++) {
 for (int j = 0; j < N; j++)
 printf("%d ", c[i][j]);
 printf("\n");
}
}

