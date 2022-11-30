#include <stdio.h>
#define LIM 500
#define NLETRAS 27

int main(){
  char texto[LIM];
  int freq[NLETRAS];
  int i;
  char c;
  printf("Insira um texto: ");
  fflush(stdin);
  /* Lê uma linha de texto */
  gets(texto);

  /* Inicializa com 0 o vetor de contadores */
  for(i = 0; i < NLETRAS; i++)
    freq[i] = 0;

  /* Percorre a string, contando a frequência das letras */
  i = 0;
  while(texto[i] != '\0'){
    c = texto[i];
    /* Identifica letras minúsculas */
    if(c >= 'a' && c <= 'z')
      freq[c-'a']++;
    /* Identifica letras maiúsculas */
    else if(c >= 'A' && c <= 'Z')
      freq[c-'A']++;
    i++;
  }

  /* Imprime a frequência das letras com contagem não nula */
  for(i = 0; i < NLETRAS; i++){
    if(freq[i] > 0)
      printf("letra: %c, freq: %d\n", 'a'+i, freq[i]);
  }
}
