#include <stdio.h>
int main (){
	int n1 [5][5];
	int i, j;
	for (i=0; i<5 ; i++) {
		n1[i][0]=i;
	}
	
	for (i=0; i<5 ; i++) {
		for (j=0; j<5 ; j++){
			if (i<j){
				n1[i][j]=0;
			}
			else {
				n1[i][j]=n1[i][j-1]+n1[i-1][j-1];
			}
		}
	}
}

