#include <stdio.h>

	void add(int, int);
	void subtract(int, int);
	void multiply(int, int);
	void divide(float, float);
	void modulus(int, int);
	
	int main(){
		while(1){
			int n1, n2, res;
			char op;
			printf("Calculator for two numbers. To quit, enter 0 twice.\n");
			printf("Enter first number: ");
			scanf("%d", &n1);
			printf("%d\n", n1);
			scanf("%c", &op);
			printf("Enter second number: ");
			scanf("%d", &n2);
			printf("%d\n", n2);
			scanf("%c", &op);
			if(n1== 0 && n2 == 0){
				printf("Quitting now.\n");
				return 0;
			}
			printf("Enter operation to be performed (valid operators: '+', '-', '*', '/', '%c'): ", '%');
			scanf("%c", &op);
			printf("%c\n", op);
			switch(op){
				case '+':
					add(n1, n2);
					break;
				case '-':
					subtract(n1, n2);
					break;
				case '*':
					multiply(n1, n2);
					break;
				case '/':
					divide(n1,n2);
					break;
				case '%':
					modulus(n1,n2);
					break;
				default:
					printf("Invalid Operator\n");
			}
		}
		return 0;
	}

	void add(int n1,int n2){
		printf("Output is: %d\n",n1+n2);
	}

	void subtract(int n1,int n2){
		printf("Output is: %d\n",n1-n2);
	}

	void multiply(int n1,int n2){
		printf("Output is: %d\n",n1*n2);
	}

	void divide(float n1,float n2){
		if(n2==0) printf("Cannot divide by zero\n");
		else printf("Output is: %.2f\n",n1/n2);
	}

	void modulus(int n1,int n2){
		if(n2==0) printf("Cannot divide by zero\n");
		else printf("Output is: %d\n",n1%n2);
	}
