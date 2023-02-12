#include <stdio.h>

//Program to add digits of integer number

int main(){
	int number; //Valid for number < 2147483647
	int rem = 0;
	printf("Enter number whose digits are to be added: ");
	scanf("%d", &number);
	while (number != 0){
		rem = rem + number%10;
		number = number/10; /*valid, as dividing integer by nonzero integer leads to integer division,
							which is the desired operation*/
	}
	printf("Sum of the digits: %d\n", rem);
	return 0;
}
