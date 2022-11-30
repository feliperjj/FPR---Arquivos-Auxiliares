#include <stdio.h>
#include <string.h>

// Protótipo das funções
void inverteString(char str[]);

void main(){
    char palavra[30];
    printf("Insira a palavra: ");
    fflush(stdin);
    gets(palavra);
    inverteString(palavra);
}

void InverteSubString(char str[], int i, int j){
  char tmp;

  while (i < j) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    i++;
    j--;
  }
}

void inverteString(char str[]){
  int i, j;
  i = 0;
  do {
    while(str[i] == ' ') i++;
    j = i;

    while(str[j] != '\0' && str[j] != ' ') j++;

    j = j - 1;
    if(i < j) InverteSubString(str, i, j);

    i = j + 1;
  } while (str[i] != '\0');

  printf("%s", str);
}
