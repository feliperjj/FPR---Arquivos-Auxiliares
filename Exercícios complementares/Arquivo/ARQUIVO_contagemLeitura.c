/*
Tem-se um arquivo txt contendo o seguinte conteúdo "maria joao joao maria maria". O usuário ao digitar um nome (maria ou joão) o programa retorna um inteiro com a quantidade de vezes que esse nome aparece no arquivo.
Entrada: Maria
Saída: 3
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("arquivo.txt", "r");
    if (file == NULL)
    {   printf("Erro na abertura do arquivo");
        return(-1);
    }
    char palavra[8] = "joao";
    char     frase[80];
    unsigned total     = 0;
    while (fscanf(file, "%s", frase) == 1)
        total += (strcmp(palavra, frase) == 0);
    printf("O número de vezes e %d", total);
    fclose(file);
}
