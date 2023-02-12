#include <stdio.h>
int main(){
	while(1){
	int n1, n2, res;
	char op;
	printf("Calculator for two numbers. To quit, enter 0 twice.\n");
	printf("Enter first number: ");
	scanf("%d", &n1);
	printf("Enter second number: ");
	scanf("%d", &n2);
	fflush(stdin);
	if(n1== 0 && n2 == 0){
		printf("Quitting now.\n");
		return 0;
		}
	printf("Enter operation to be performed (valid operators: '+', '-', '*', '/', '%%'): ");
	scanf("%c", &op);
	switch(op){
		case '+':
			printf("Output: %d\n", n1+n2);
			break;
		case '-':
			printf("Output: %d\n", n1-n2);
			break;
		case '*':
			printf("Output: %d\n", n1*n2);
			break;
		case '/':
			if(n2==0) printf("Cannot divide by zero\n");
			else printf("Output: %d\n", n1/n2);
			break;
		case '%':
			if(n2==0) printf("Cannot divide by zero\n");
			else printf("Output: %d\n", n1%n2);
			break;
		default:
			printf("Invalid Operator\n");
		}
	}
	return 0;
}
