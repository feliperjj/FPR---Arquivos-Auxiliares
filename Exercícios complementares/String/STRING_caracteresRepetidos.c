/*
Crie uma função que mostra os caracteres de uma string são repetidos.
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
  char texto[100];
  char letras[] = "abcdefghijklmnopqrstuvxzwyABCDEFGHIJKLMNOPQRSTUVXZWY";
  char letrasaux[100];
  int x, y, cont=0;

	printf ("\nEscreva um texto: \n");
	gets (texto);

	for (x=0; x<strlen(letras); x++) {
		for (y=0; y<strlen(texto); y++) {
			if (texto[y] == letras[x]){
                cont++;
                printf ("\nA letra %c contem %d vez(es) na frase\n", texto[y], cont);
			 }
        }
		cont=0;
    }
}
