##include <stdio.h>
#include <string.h>

void divisores(char nomeArq[], char nomeArq2[]) {
    FILE *arquivoOrig;
    FILE *arquivoNovo;
    int numero, i;

    arquivoOrig = fopen(nomeArq, "r");

    if (arquivoOrig == NULL) {
        printf("Erro ao abrir o arquivo %s.", nomeArq);
        return;
    }

    arquivoNovo = fopen(nomeArq2, "w");

    if (arquivoNovo == NULL) {
        printf("Erro ao criar o arquivo %s.", nomeArq2);
        fclose(arquivoOrig);
        return;
    }

    while (fscanf(arquivoOrig, "%d", &numero) != EOF) {
        fprintf(arquivoNovo, "Divisores de %d: ", numero);

        for (i = 1; i <= numero; i++) {
            if (numero % i == 0) {
                fprintf(arquivoNovo, "%d ", i);
            }
        }

        fprintf(arquivoNovo, "\n");
    }

    fclose(arquivoOrig);
    fclose(arquivoNovo);
}

int main() {
    char nomeArqOriginal[20], nomeArqNovo[20];

    strcpy(nomeArqOriginal, "teste.txt");
    strcpy(nomeArqNovo, "novo.txt");

    divisores(nomeArqOriginal, nomeArqNovo);

    printf("O arquivo %s foi gerado com sucesso!\n", nomeArqNovo);

    return 0;
}
 <stdio.h>
#include <string.h>

#define MAX 100

struct Pessoa {
    char nome[50];
    char genero;
    int idade;
};

int ordenado(struct Pessoa v[], int n) {
    int i;

    for (i = 0; i < n-1; i++) {
        if (v[i].idade > v[i+1].idade) {
            return 0; // vetor não está ordenado
        }
        if (v[i].idade == v[i+1].idade && strcmp(v[i].nome, v[i+1].nome) > 0) {
            return 0; // vetor não está ordenado
        }
    }

    return 1; // vetor está ordenado
}

int main() {
    struct Pessoa v[MAX] = {{"Ana", 'F', 25}, {"Bruno", 'M', 20}, {"Carla", 'F', 30}};
    int n = 3;

    if (ordenado(v, n)) {
        printf("O vetor está ordenado\n");
    } else {
        printf("O vetor não está ordenado\n");
    }

    return 0;
}