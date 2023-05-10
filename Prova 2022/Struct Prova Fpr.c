#include <stdio.h>
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