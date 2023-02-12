#include <stdio.h>

//C program to evaluate maximum of three numbers

int main(){
	float a, b, c;
	printf("Enter first number: ");
	scanf("%f", &a);
	printf("Enter second number: ");
	scanf("%f", &b);
	printf("Enter third number: ");
	scanf("%f", &c);
	if (a >= b && a >= c) printf("Largest number is %f", a);
	else if (b >= c && b >= a) printf("Largest number is %f", b);
	else printf("Largest number is %f", c);
	return 0;
}
