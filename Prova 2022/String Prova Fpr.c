#include <stdio.h>
#define TAM 30
//Dadas duas strings s1 e s2, implementar uma função
//que verifique se todos os caracteres de s1 estão em s2.
//Dependendo do resultado, os seguintes valores
//deverão ser retornados:
//0: nem todos os caracteres de s1 estão em s2;
//1: todos os caracteres de s1 estão em s2, porém
//não na mesma frequência;
//2: todos os caracteres de s1 estão em s2, na
//mesma frequência.
char compara(char *s1[], char *s2[]){
	int i,j,cont,cont2,freq1,freq2;
	char c;

	
	for(i=0;s1[i]!='\0';i++){
		c = s1[i];
		cont = 0;
		cont2= 0;
		for(j=0;s1[j]!='\0';j++){
		
		if(s1[j]==c){
			
				cont++;
		}	
	
	
	}
		for(j=0;s2[j]!='\0';j++){
			
				if(s2[j]==c){
				
				cont2++;
		}	
			
		}
	
	// Verifica se o caractere está em s2
        if (freq2 == 0) {
            return 0;
        }
        
        // Verifica se a frequência do caractere é diferente em s1 e s2
        if (freq1 != freq2) {
            return 1;
        }
    }
    
    return 2;
}


int main() {
    char s1[TAM], s2[TAM];
    int result;

    printf("Digite a primeira string: ");
    scanf("%s", s1);
    printf("Digite a segunda string: ");
    scanf("%s", s2);

    result = compara(s1, s2);

    if (result == 0) {
        printf("Nem todos os caracteres de s1 estao em s2\n");
    } else if (result == 1) {
        printf("Todos os caracteres de s1 estao em s2, porem nao na mesma frequencia\n");
    } else {
        printf("Todos os caracteres de s1 estao em s2, na mesma frequencia\n");
    }

    return 0;
}

