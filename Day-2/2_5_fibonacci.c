#include <stdio.h>

int main(){
	int i, n, n1 = 0, n2 = 1, n3 = n1+n2;	
	printf("Program to display first 'n' terms of Fibonacci sequence.\n");
	while(1){
		printf("Enter n: ");
		scanf("%d", &n);
		if (n == -1) break;
		else if (n < -1) printf("Invalid input provided, please try again.\n");
		else{
			printf("First %d term(s) of the Fibonacci sequence are: ", n);
			for(i = 0; i < n; i++){
				printf("%d ", n1);
				n1 = n2;
				n2 = n3;
				n3 = n1 + n2;
		}
		printf("\n");
		n1 = 0, n2 = 1, n3 = 1;
		}
	}
	
	return 0;
}
