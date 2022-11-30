/*
Um quadrado mágico é uma matriz quadrada em que a soma das suas linhas é igual a soma das sua colunas e que também é igual a soma
da diagonal principal e da diagonal secundária. A matriz abaixo é um exemplo de quadrado mágico, pois a somatória, em todos os casos,
é igual a 15.

algoritmo "QuadradoMagico"

var

mat: vetor [1..3, 1..3] de inteiro

i, j, somaPrinc, somaSec, somaLin, somaCol: inteiro

flag: logico

inicio

flag<-verdadeiro

para i de 1 ate 3 faca

   para j de 1 ate 3 faca

      leia(mat[i,j])

   fimpara

fimpara

para i de 1 ate 3 faca

   para j de 1 ate 3 faca

      se (i=j) entao

         somaPrinc<-somaPrinc + mat[i,j]

      fimse

   fimpara

fimpara

para i de 1 ate 3 faca

   para j de 1 ate 3 faca

      se (i+j=4) entao

         somaSec<-somaSec + mat[i,j]

      fimse

   fimpara

fimpara



se (somaPrinc<>somaSec) entao

   flag<-falso

fimse



para i de 1 ate 3 faca

   somaLin<-0

   para j de 1 ate 3 faca

      somaLin<-somaLin + mat[i,j]

   fimpara

   se (somaLin <> somaPrinc) entao

      flag<-falso

   fimse

fimpara



para i de 1 ate 3 faca

   somaCol<-0

   para j de 1 ate 3 faca

      somaCol<-somaCol + mat[j,i]

   fimpara

   se (somaCol<>somaPrinc) entao

      flag<-falso

   fimse

fimpara



se (flag) entao

   escreval("É um quadrado mágico!")

senao

   escreval("Não é um quadrado mágico!")

fimse
fimalgoritmo
*/
