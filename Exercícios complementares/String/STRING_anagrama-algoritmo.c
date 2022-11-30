/*
algoritmo "Testa anagrama"
var
   A, B, C: vetor [1..5] de caracter
   i, j, total: inteiro
inicio
      total <- 0
      para i de 1 ate 5 faca
           leia (A[i])
      fimpara
      para i de 1 ate 5 faca
           leia (B[i])
           C[i] <- B[i]
      fimpara
      para i de 1 ate 5 faca
           para j de 1 ate 5 faca
                se (A[i]=C[j]) entao
                   C[j] <- "@"
                   total <- total + 1
                   interrompa
                fimse
           fimpara
      fimpara
      se (total=5) entao
         escreval ("São anagramas.")
      senao
         escreval ("Não são anagramas.")
      fimse
fimalgoritmo
*/


/*
algoritmo "Testa anagrama"
var
   A, B: vetor [1..5] de caracter
   i, j, total: inteiro
   aux: caracter
inicio
      total <- 0
      para i de 1 ate 5 faca
           leia (A[i])
      fimpara
      para i de 1 ate 5 faca
           leia (B[i])
      fimpara
      para j de 1 ate 4 passo 1 faca
            para i de 1 ate 4 passo 1 faca
                 se (A[i] < A[i+1]) entao
                   aux <- A[i]
                    A[i] <- A[i+1]
                    A[i+1] <- aux
                 fimse
            fimpara
      fimpara
      para j de 1 ate 4 passo 1 faca
            para i de 1 ate 4 passo 1 faca
                 se (B[i] < B[i+1]) entao
                   aux <- B[i]
                    B[i] <- B[i+1]
                    B[i+1] <- aux
                 fimse
            fimpara
      fimpara
      para i de 1 ate 5 faca
           se (A[i] = B[i]) entao
              total <- total + 1
           fimse
      fimpara
      se (total = 5) entao
         escreval ("São anagramas.")
      senao
         escreval ("Não são anagramas.")
      fimse
fimalgoritmo
*/
