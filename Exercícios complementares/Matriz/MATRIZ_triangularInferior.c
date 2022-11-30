/*
SÃO AQUELAS QUE POSSUEM OS NUMEROS ACIMA DA DIAGONAL PRINCIPAL TODOS NULOS
algoritmo "Matriz triangular inferior"
var
   A: vetor[1..8,1..8] de inteiro
   i, j: inteiro
inicio
      para i de 1 ate 8 faca
           para j de 1 ate 8 faca
                leia (A[i,j])
           fimpara
      fimpara
      para i de 1 ate 8 faca
           para j de 1 ate 8 faca
                se (i<j) entao
                   A[i,j]<-0
                fimse
           fimpara
      fimpara
      para i de 1 ate 8 faca
           para j de 1 ate 8 faca
                escreva(A[i,j])
           fimpara
           escreval("")
      fimpara
fimalgoritmo*/
