/*Gera em dest uma cópia de orig porém eliminando o excesso de espaços em branco, de modo que todas as sequências de espaços em branco consecutivos são convertidas em um único caracter de espaço. Assuma que o vetor dest é grande o suficiente para conter o resultado.
Exemplo: Se inicialmente temos:
    orig = "     Problema       de     Strings  ", no final teremos:
    dest = " Problema de Strings "
*/

void ReduzEspacos(char dest[], char orig[]){
  int i, j;
  char t;
  i = 0;
  j = 0;
  while(orig[i] != '\0'){
    if(orig[i] != ' '){
      t = orig[i];
      i++;
    }
    else {
      t = orig[i];
      while(orig[i] == ' ') i++;
    }
    dest[j] = t;
    j++;
  }
  dest[j] = '\0';
}
