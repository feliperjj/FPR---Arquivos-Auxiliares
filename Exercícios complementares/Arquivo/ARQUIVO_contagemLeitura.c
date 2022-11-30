/*
Tem-se um arquivo txt contendo o seguinte conte�do "maria joao joao maria maria". O usu�rio ao digitar um nome (maria ou jo�o) o programa retorna um inteiro com a quantidade de vezes que esse nome aparece no arquivo.
Entrada: Maria
Sa�da: 3
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
    printf("O n�mero de vezes e %d", total);
    fclose(file);
}
