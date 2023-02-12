#include<stdio.h>
int fib(int);
int main(){
	int i, n = 0;
	while(n!=-1){
		printf("Enter value of n: "); 
		scanf("%d",&n);
		printf("%d\n",n);
		for(i=1;i<=n;i++){
			printf("%d ",fib(i));
		}
		printf("\n");
	}
	return 0;
}
int fib(int n){
	if (n==1) return 0;
	else if (n==2) return 1;
	else return fib(n-1)+fib(n-2); /*recursion call, since nth term of Fibonacci sequence equals the sum of (n-1)th and (n-2)th terms*/
}

