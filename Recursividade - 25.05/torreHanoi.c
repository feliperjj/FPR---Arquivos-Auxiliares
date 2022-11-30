 hanoi(int n, char O, char D, char aux);

void main(){
	int n=3;
	printf("Hanoi de %d discos\n", n);
	Hanoi(n,'A','C','B');
}

void Hanoi(int n, char O, char D, char aux){
	if (n>0){
		Hanoi (n-1, O, aux, D);
		printf ("%c -> %c\n", O, D);	
		Hanoi (n-1, aux, D, O);
	}
}
