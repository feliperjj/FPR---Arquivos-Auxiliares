/*
Questão 02: Desenvolver uma função recursiva que exiba todos os múltiplos do número N, inferiores ou iguais ao valor V.
*/

void calculaMultiplos(int numero, int valor, int i);
void exibirMultiplos(int numero, int valor);

void main(){
	int n, v;
	printf("Insira o valor de N: ");
	scanf("%d",&n);
	printf("Insira o valor de V: ");
	scanf("%d",&v);
	exibirMultiplos(n,v);
}

void calculaMultiplos(int numero, int valor, int i){
	if (i<=valor){
		printf("%d\n",i);
		calculaMultiplos(numero,valor,i+numero);
	} 
}

void exibirMultiplos(int numero, int valor){
	calculaMultiplos(numero, valor, 0);
}
