/*
 Depois de ler as 5 strings, leia mais uma string e
verifique se ela est� no vetor. Caso esteja, indique o
�ndice no vetor.
*/
#include <stdio.h>
void main(){
char strings[5][100], s[100];
int i, j;
for (i=0; i < 5; i++)
{
printf ("Digite uma string: ");
scanf ("%s", strings[i]);
}
printf("String para localizar: ");
scanf ("%s", s);
for (i=0; i < 5; i++)
{
for (j=0; (strings[i][j] != '\0') && (strings[i][j] == s[j]); j++);
if ((strings[i][j] == '\0') && (s[j] == '\0'))
printf("string encontrada na posicao %d\n", i);
}
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char vet[5][21]; /*espa�o para 5 strings de 21 caracteres cada*/
	int i;           /*contador*/

	/* pe�o ao usu�rio para fornecer os 5 strings */
/*	for (i=0; i<5; i++) {
		printf("Entre string n�mero %d: ",i);
		gets(vet[i]);
	}

	/* escrevo na tela os 5 strings */
/*	for (i=0; i<5; i++)
		printf("Seu string: %s\n",vet[i]);
}

E se quis�ssemos inicializar nossa matriz logo de in�cio?

#include <stdio.h>

int main() {
	char vet[5][21] = {"meu primeiro string",
				"segund�o da lista",
				"terceiro",
				"to quase l�...",
				"o �ltimo!"};
	int i;

	/* imprimo o vetor */
/*	for (i=0; i<5; i++) {
		printf("vet[%d] =  %s\n",i,vet[i]);
	}
}
*/
