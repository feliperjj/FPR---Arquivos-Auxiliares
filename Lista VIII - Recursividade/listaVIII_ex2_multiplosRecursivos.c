/*
Quest�o 02: Desenvolver uma fun��o recursiva que exiba todos os m�ltiplos do n�mero N, inferiores ou iguais ao valor V.
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
		if(i%numero==0){
			printf("%d\n",i);
		}
		calculaMultiplos(numero,valor,i+1);
	} 
}

void exibirMultiplos(int numero, int valor){
	calculaMultiplos(numero, valor, 0);
}
