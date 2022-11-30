/*
Faça um programa em C que lê 5 frases de, no máximo, 50 caracteres cada uma e armazene-as em um arquivo.
Mas, antes de gravar cada frase no arquivo, é necessário converter todas as suas letras para maiúsculas.
Os nome do arquivo será fornecido, via teclado, pelo usuário. A função que converte maiuscula para minúscula é o toupper().
A seguir, feche o arquivo e reabra para leitura exibindo todas as frases convertidas. Como cada texto pode ter tamanho diferente,
será necessário gravar antes de cada frase o tamanho do texto a ser lido. logo serão necessários dois comandos de gravação e leitura
(um para o numero inteiro que indica a quantidade de caracteres da frase e outro para a frase com o tamanho lido)
*/

#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   FILE *farq;
   int i,j;
   char texto[50];
   char maiusc[50];
   char nomearq[20];
   int num;
   char c;
    printf("\n\nDigite o nome do arquivo a ser criado: ");
    scanf("%s", &nomearq);
    scanf("%c",&c);
    farq = fopen(nomearq, "w");
    if (farq == NULL) {
         fprintf(stderr,"fopen() failed in file %s at line # %d", __FILE__,__LINE__);
         exit(EXIT_FAILURE);
    }

    for (i=0; i < 2; i++){
      printf("\n\nDigite uma frase com 49 caracteres máximo: ");
      gets(texto);
      fflush(stdin);
       j=0;
        while ( texto[j] != '\0' && j < 49){
        maiusc[j] = toupper(texto[j]);  // converte os caracteres para maiúscula
        j++;
      }
        maiusc[j]='\0';

        fwrite(&num, sizeof(int), 1, farq); //Grava o tamanho do texto

        fwrite(maiusc, sizeof(char), num, farq); //Grava o texto
    }

   fclose(farq);
   farq = fopen(nomearq, "r");
    if (farq == NULL) {
         fprintf(stderr,"fopen() failed in file %s at line # %d", __FILE__,__LINE__);
         exit(EXIT_FAILURE);
    }

    fread(&num, sizeof(int),1,farq); // lê o tamanho do texto
    fread(texto, sizeof(char),num, farq); // lê o texto gravado
   while (!feof (farq) ) {
      printf("\n\nTexto Lido: %s", texto);
      memset(texto,'\0',50);
      fread(&num, sizeof(int),1,farq);     // lê o tamanho do texto
      fread(texto, sizeof(char),num, farq); // lê o texto gravado

    }
    fclose(farq);
}
