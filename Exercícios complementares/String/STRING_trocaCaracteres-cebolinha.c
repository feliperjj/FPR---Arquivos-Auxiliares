/*
Cebolinha é um personagem de história em quadrinhos que quando falava, trocava o "r" pelo "l" (problema conhecido como dislalia).
 Faça um programa que gera uma versão de um texto fornecido com todos "r" e "rr" trocados por "l", exceto no caso em que o "r" ocorre no final
 de uma palavra.
*/

#include <stdio.h>
#include <string.h>

int main(){
  char str[] = "e chega de disputar essa rua com a monica, eu poderei comprar ruas, bairros inteiros";
  char dest[500];
  int i, j, n;
  char c;

  j = 0;
  n = strlen(str);
  for(i = 0; i < n; i++){
    if(str[i] == 'r' && str[i+1] >= 'a' && str[i+1] <= 'z'){
      c = 'l';
      if(str[i+1] == 'r')
        i++;
    }
    else
      c = str[i];

    dest[j] = c;
    j++;
  }
  dest[j] = '\0';

  printf("%s\n", dest);

  return 0;
}
