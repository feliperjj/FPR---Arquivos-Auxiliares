/*Gera em dest uma c�pia de orig por�m eliminando o excesso de espa�os em branco, de modo que todas as sequ�ncias de espa�os em branco consecutivos s�o convertidas em um �nico caracter de espa�o. Assuma que o vetor dest � grande o suficiente para conter o resultado.
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
