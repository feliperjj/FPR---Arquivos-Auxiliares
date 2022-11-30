/*

                                    ╔═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╗
                                            𝐓𝐑𝐀𝐁𝐀𝐋𝐇𝐎 5 - 𝐀𝐕2

                                        𝐀𝐥𝐮𝐧𝐚: 𝐕𝐢𝐭𝐨𝐫𝐢𝐚 𝐏𝐢𝐥𝐨𝐭𝐨
                                        𝐃𝐬𝐢𝐜𝐢𝐩𝐥𝐢𝐧𝐚: 𝐅𝐏𝐑
                                        𝐏𝐫𝐨𝐟𝐞𝐬𝐬𝐨𝐫: 𝐋𝐞𝐨𝐧𝐚𝐫𝐝𝐨 𝐕𝐢𝐚𝐧𝐧𝐚
                                    ╚═══*.·:·.☽✧    ✦    ✧☾.·:·.*═══╝

Desenvolver uma função que, dada uma string s, exiba, para cada caracter, o seu número de ocorrências em s.

Notas:
1. A solução deve utilizar o conceito derecursividade. Caso seja apresentada uma única função, esta deverá ser recursiva; se o
problema for resolvido a partir de mais de uma função, pelo menos uma delas deverá ser recursiva;

2. Quando um mesmo caracter aparecer na string por mais de uma vez, apenas uma mensagem deverá ser exibida (ou seja, não deverá apresentar,
por exemplo, 3 vezes a mensagem “E – aparece 3 vezes”.
*/

// Importação de bibliotecas
#include <stdio.h>
#include <string.h>

// Definição de constantes
#define MAX 30

// Protótipo da função
void contaLetras (char palavra[], int i);

// Main
void main(){
    char palavra[MAX];
    printf("\nInsira a palavra: ");
    fflush(stdin);
    gets(palavra);
    contaLetras(palavra,0);
}

// Função de contar as letras recursivamente
void contaLetras(char palavra[], int i){
    int j=0, k, cont=0, aux=0, tamanho=strlen(palavra);
    char letra;
	if (i<tamanho){
        cont=0;
        letra = palavra[i];
        for (j=0;j<tamanho;j++){
            if (letra == palavra[j]){
                cont++;
            }
        }
        for (k=i+1;k<tamanho;k++){
            if (letra == palavra[k]){
                aux++;
            }
        }
        if (aux==0){
            printf("%c ocorre: %d\n", letra, cont);
        }
        // Chamada recursiva adicionando um ao i
        contaLetras(palavra,i+1);
	}
}
