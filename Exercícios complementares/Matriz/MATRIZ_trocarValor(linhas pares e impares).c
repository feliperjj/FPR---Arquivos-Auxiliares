/*Fa�a um algoritmo para ler uma matriz 100 x 100 de inteiros. Em seguida, nas linhas �mpares, o algoritmo dever� capturar os valores
pares encontrados e coloc�-los, se existirem, em um vetor (VP) e trocar, na matriz, pelo n�mero 1. Depois, para as linhas pares,
o algoritmo dever� capturar os valores �mpares encontrados e coloc�-los, se existirem, em um vetor (VI) e trocar, na matriz, pelo n�mero 2.
 Ao final imprimir a matriz A e os vetores VP e VI (somente com as posi��es preenchidas).*/

 /*
 algoritmo "Sele��o de linhas pares e �mpares"
var
   A: vetor[1..100, 1..100] de inteiro
   VP, VI: vetor[1..50] de inteiro
   i, j, posPar, posImpar: inteiro
inicio
      posPar<-0
      posImpar<-0
      para i de 1 ate 100 faca
           para j de 1 ate 100 faca
                leia (A[i,j])
           fimpara
      fimpara
      para i de 1 ate 100 faca
           para j de 1 ate 100 faca
                se (i%2<>0) entao
                   se (A[i,j]%2=0) entao
                      posPar<-posPar+1
                      VP[posPar]<-A[i,j]
                      A[i,j]<-1
                   fimse
                senao
                   se (A[i,j]%2<>0) entao
                      posImpar<-posImpar+1
                      VI[posImpar]<-A[i,j]
                      A[i,j]<-2
                   fimse
                fimse
           fimpara
     fimpara
     para i de 1 ate 100 faca
          para j de 1 ate 100 faca
               escreva(A[i,j])
          fimpara
          escreval("")
     fimpara
     escreval("")
     para i de 1 ate posPar faca
          escreva(VP[i])
     fimpara
     escreval("")
     para i de 1 ate PosImpar faca
          escreva(VI[i])
     fimpara
fimalgoritmo
 */
