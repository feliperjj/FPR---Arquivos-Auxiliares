/*

                                    ╔═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╗
                                            𝐓𝐑𝐀𝐁𝐀𝐋𝐇𝐎 𝟏 - 𝐀𝐕𝟏

                                        𝐀𝐥𝐮𝐧𝐚: 𝐕𝐢𝐭𝐨𝐫𝐢𝐚 𝐏𝐢𝐥𝐨𝐭𝐨
                                        𝐃𝐬𝐢𝐜𝐢𝐩𝐥𝐢𝐧𝐚: 𝐅𝐏𝐑
                                        𝐏𝐫𝐨𝐟𝐞𝐬𝐬𝐨𝐫: 𝐋𝐞𝐨𝐧𝐚𝐫𝐝𝐨 𝐕𝐢𝐚𝐧𝐧𝐚
                                    ╚═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╝

𝐐𝐔𝐄𝐒𝐓𝐀𝐎:
    𝘋𝘢𝘥𝘢 𝘶𝘮𝘢 𝘮𝘢𝘵𝘳𝘪𝘻 𝘔𝘓𝘐𝘕𝘏𝘈𝘹𝘊𝘖𝘓𝘜𝘕𝘈, 𝘰𝘯𝘥𝘦 𝘓𝘐𝘕𝘏𝘈 𝘦 𝘊𝘖𝘓𝘜𝘕𝘈 𝘴𝘢𝘰 𝘤𝘰𝘯𝘴𝘵𝘢𝘯𝘵𝘦𝘴, 𝘥𝘦𝘴𝘦𝘯𝘷𝘰𝘭𝘷𝘦𝘳 𝘶𝘮𝘢 𝘧𝘶𝘯𝘤𝘢𝘰 𝘲𝘶𝘦 𝘥𝘦𝘵𝘦𝘳𝘮𝘪𝘯𝘦 𝘴𝘦 𝘴𝘦𝘶𝘴 𝘦𝘭𝘦𝘮𝘦𝘯𝘵𝘰𝘴 𝘦𝘴𝘵𝘢𝘰
    𝘰𝘳𝘥𝘦𝘯𝘢𝘥𝘰𝘴 𝘤𝘳𝘦𝘴𝘤𝘦𝘯𝘵𝘦𝘮𝘦𝘯𝘵𝘦.

    𝘈 𝘮𝘢𝘵𝘳𝘪𝘻 𝘴𝘦𝘳𝘢 𝘤𝘰𝘯𝘴𝘪𝘥𝘦𝘳𝘢𝘥𝘢 𝘰𝘳𝘥𝘦𝘯𝘢𝘥𝘢 𝘴𝘦 𝘵𝘰𝘥𝘢𝘴 𝘢𝘴 𝘴𝘶𝘢𝘴 𝘭𝘪𝘯𝘩𝘢𝘴 𝘦𝘴𝘵𝘪𝘷𝘦𝘳𝘦𝘮 𝘰𝘳𝘥𝘦𝘯𝘢𝘥𝘢𝘴 𝘦, 𝘢𝘭𝘦𝘮 𝘥𝘪𝘴𝘴𝘰, 𝘰 𝘱𝘳𝘪𝘮𝘦𝘪𝘳𝘰 𝘦𝘭𝘦𝘮𝘦𝘯𝘵𝘰 𝘥𝘦 𝘶𝘮𝘢 𝘭𝘪𝘯𝘩𝘢
    𝘓 𝘧𝘰𝘳 𝘮𝘢𝘪𝘰𝘳 𝘰𝘶 𝘪𝘨𝘶𝘢𝘭 𝘢𝘰 𝘶𝘭𝘵𝘪𝘮𝘰 𝘥𝘢 𝘭𝘪𝘯𝘩𝘢 𝘓-1.
*/

#include <stdio.h>
#define LINHA 4
#define COLUNA 4

//𝐏𝐫𝐨𝐭𝐨𝐭𝐢𝐩𝐨 𝐝𝐚𝐬 𝐟𝐮𝐧𝐜𝐨𝐞𝐬
void preencher (int m[LINHA][COLUNA]); //Necessário somente para teste de verificaOrdenação = false
void exibir (int m[LINHA][COLUNA]);
int verificaOrdenacao (int m[LINHA][COLUNA]);

// 𝐌𝐚𝐢𝐧
void main(){
    // 𝐃𝐄𝐂𝐋𝐀𝐑𝐀𝐂𝐀𝐎 𝐃𝐄 𝐕𝐀𝐑𝐈𝐀𝐕𝐄𝐈𝐒 𝐏𝐀𝐑𝐀 𝐌𝐀𝐓𝐑𝐈𝐙 𝐎𝐑𝐃𝐄𝐍𝐀𝐃𝐀 = 𝐓𝐑𝐔𝐄:
    int M[LINHA][COLUNA] = {{1, 2, 3, 4},
                            {4, 5, 7, 8},
                            {8, 12, 13, 16},
                            {16, 18, 20, 21}}
                           ;


    int retorno;

    // 𝐃𝐄𝐂𝐋𝐀𝐑𝐀𝐂𝐀𝐎 𝐃𝐄 𝐕𝐀𝐑𝐈𝐀𝐕𝐄𝐈𝐒 𝐏𝐀𝐑𝐀 𝐌𝐀𝐓𝐑𝐈𝐙 𝐍𝐀𝐎 𝐎𝐑𝐃𝐄𝐍𝐀𝐃𝐀:
    /*int M[LINHA][COLUNA];
    preencher(M);*/

    printf("-------- EXIBINDO A MATRIZ: --------\n\n");
    exibir(M);

    retorno = verificaOrdenacao(M); //Chamando a função para verificar ordenação

    // Exibindo o resultado da função
    if (retorno == 1){
        printf("\n\n-------- MATRIZ ORDENADA!! --------\n\n");
    } else {
        printf("\n\n-------- NAO ORDENADAA!! --------\n\n");
    }
}

// 𝐏𝐫𝐞𝐞𝐧𝐜𝐡𝐞𝐫
void preencher (int m[LINHA][COLUNA]){
	int i, j;
	srand (time(NULL));
	for (i=0;i<LINHA;i++)
	{
		for (j=0;j<COLUNA;j++){
			m[i][j] = rand()%10 + 1;
		}
	}
}

// 𝐄𝐱𝐢𝐛𝐢𝐫
void exibir (int m[LINHA][COLUNA]){
	int i, j;
	for (i=0;i<LINHA;i++){
		for (j=0;j<COLUNA;j++){
			printf ("%3d ", m[i][j]);
		}
		printf ("\n");
	}
}

// 𝐕𝐞𝐫𝐢𝐟𝐢𝐜𝐚𝐧𝐝𝐨 𝐨𝐫𝐝𝐞𝐧𝐚𝐜𝐚𝐨
int verificaOrdenacao(int m[LINHA][COLUNA]){
    int i,j, aux;
    for (i=0;i<LINHA;i++){
        for (j=0;j<COLUNA;j++){
            if (m[i][j] > m[i][j+1]){
                return 0;
            }
    }

    if (m[i][COLUNA] <= m[i+1][COLUNA]){
        return 1;
    } else {
        return 0;
    }
}
}
