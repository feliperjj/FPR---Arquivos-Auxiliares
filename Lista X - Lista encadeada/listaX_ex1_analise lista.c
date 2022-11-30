/*
QUESTÃO 01:
Considere uma lista encadeada com a seguinte configuração na memória principal, onde L,
aux1 e aux2 são do tipo TLista:

L 10 5 11 2 4
     |    |
    aux1 aux2

a. O que os seguintes elementos armazenam?
    i. L
    Resposta: ponteiro para o primeiro elemento da lista, que é o 10.
    ii. aux1->prox->
    Respota: a caixinha do 11 e o 11 prox
    iii. aux1->valor
    Resposta: o valor 5
    iv. aux2->prox->prox
    Resposta: null.

b. Qual o resultado (explique com detalhes) da execução dos comandos a seguir
(considerando que os mesmos não são executados em sequência)?
    i. aux2 = aux1->prox;
    Resposta: recebe o 11.
    ii. free (aux2->prox);
    Respota: apaga o 4
    iii. aux1->prox = aux2->prox;
    Respota: troca 4 e 11 de lugar.
    iv. L->prox = NULL;
    Resposta: anula a lista
*/

