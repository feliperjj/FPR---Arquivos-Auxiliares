/*
Crie um programa C que:

(a) crie/abra um arquivo texto de nome "arq.txt",

(b) permita que o usuario entre com diversos caracteres nesse arquivo, até que o usuario entre com o caractere ’0’ (fim da entrada de dados),

(c) Feche o arquivo e abra novamente o arq.txt, e

(d) lendo-o caractere por caractere, e escrevendo na tela (printf) todos os caracteres armazenados.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *farq;
    char car;


farq = fopen("arq.txt", "w");
if (farq == NULL) {
 fprintf(stderr,"\nfopen() failed in file %s at line # %d", __FILE__,__LINE__);
 exit(EXIT_FAILURE);
}
printf("\nEntre com um caracter qualquer ou 0 para terminar:");
car = getchar();
fflush(stdin); // limpa o caracter enter do teclado
while (car != '0')
{
   fputc(car,farq);
   printf("\nEntre com um caracter qualquer ou 0 para terminar:");
   car = getchar();
   fflush(stdin); // limpa o caracter enter do teclado
}
fclose(farq);
farq = fopen("arq.txt", "r");
if (farq == NULL)
{
   fprintf(stderr,"\nfopen() failed in file %s at line # %d", __FILE__,__LINE__);
   exit(EXIT_FAILURE);
}
printf("\n\nVou ler e mostrar o texto gravado....\n\n");
car=fgetc(farq);
while (car!=EOF)
{
   printf("%c",car);
   car =fgetc(farq);
}

fclose(farq);

}
