/*
Remover os repetidos:
*/

#include <stdio.h>
#include <string.h>

int main() {
    int i = 0, j = 0;

    char C[1];
    char* vetorA = "AABBCCDDEE";

    int tam = strlen(vetorA);
    char vetorB[tam];

    while (i < tam) {
        C[0] = vetorA[i++];
        if(strstr(vetorB, C) == NULL)
            vetorB[j++] = C[0];
    }

    vetorB[j] = 0;
    printf("%s\n", vetorB);

    return 0;
}
