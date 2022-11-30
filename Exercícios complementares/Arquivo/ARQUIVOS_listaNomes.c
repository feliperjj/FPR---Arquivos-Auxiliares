/*
Escreva um programa que leia uma lista de nomes e idades de um arquivo texto.
Prepare um arquivo para ser lido com nomes e idades. Apresente os dados lidos em forma de tabela na tela.
Use as funções de sua preferência, mas faça pelo menos duas versões do programa usando funções de leitura diferentes.
*/

#include <stdio.h>
void main()
{
    char nome[30], narq[30];
    FILE *arq;
    int idade;
    printf("\nArquivo fonte: ");
    gets(narq);
    /* Tenta abrir o arquivo: */
    if ((arq = fopen(narq, "r")) == NULL)
    {
          printf("\n Erro: Nao e possivel abrir %s!!", narq);
          exit(1);
    }
    printf("\nConteudo de %s:\n", narq);
    while (!feof(arq))
    {
      fgets(nome, 29, arq);
      fscanf(arq,"%d\n",&idade);
      printf("Nome: %s   | Idade: %d\n", nome, idade);
    }
    fclose(arq);
}
