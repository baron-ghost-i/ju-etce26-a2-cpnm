#include <stdio.h>

	float fact(int);

	int main(){
		int i, n = 0;
		while(1){
			printf("Enter value of n: ");
			scanf("%d",&n);
			printf("%d\n",n);
			if(n==-1) break;
			printf("%d! = %.0f", n, fact(n));
			printf("\n");
		}
		return 0;
	}
	
	float fact(int n){
		if(n>=0){
			if (n==0) return 1;
			else return n*fact(n-1); //recursion call, since n! = n*(n-1)!
		}
	}
