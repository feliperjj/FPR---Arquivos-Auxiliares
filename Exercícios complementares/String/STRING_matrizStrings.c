/*
 Depois de ler as 5 strings, leia mais uma string e
verifique se ela está no vetor. Caso esteja, indique o
índice no vetor.
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
	char vet[5][21]; /*espaço para 5 strings de 21 caracteres cada*/
	int i;           /*contador*/

	/* peço ao usuário para fornecer os 5 strings */
/*	for (i=0; i<5; i++) {
		printf("Entre string número %d: ",i);
		gets(vet[i]);
	}

	/* escrevo na tela os 5 strings */
/*	for (i=0; i<5; i++)
		printf("Seu string: %s\n",vet[i]);
}

E se quiséssemos inicializar nossa matriz logo de início?

#include <stdio.h>

int main() {
	char vet[5][21] = {"meu primeiro string",
				"segundão da lista",
				"terceiro",
				"to quase lá...",
				"o último!"};
	int i;

	/* imprimo o vetor */
/*	for (i=0; i<5; i++) {
		printf("vet[%d] =  %s\n",i,vet[i]);
	}
}
*/
