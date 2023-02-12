	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	int binary_to_decimal(int);
	int decimal_to_binary(int); //returns incorrect results past input = 1024 due to size limitation of int in C
	int octal_to_decimal(int);
	int decimal_to_octal(int);
	int main(){
		int input, output;
		int choice = 0;
		while(choice != 7){
			printf("------------------\n");
			printf("Available choices:\n");
			printf("1. Binary to decimal number\n");
			printf("2. Decimal to binary number\n");
			printf("3. Octal to decimal number\n");
			printf("4. Decimal to octal number\n");
			printf("5. Binary to octal number\n");
			printf("6. Octal to binary number\n");
			printf("7. Exit\n");
			printf("Enter number of choice: ");
			scanf("%d", &choice);
			printf("%d\n", choice);
			if(choice >= 1 && choice <= 6){
				printf("Enter number (must be a positive integer) to be converted: ");
				scanf("%d", &input);
				printf("%d\n", input);
			}
			if(input<0){
				printf("Number is not a positive integer, please try again\n");
				continue;
			}
			switch(choice){
				case 1:
					output = binary_to_decimal(input);
					if(output == -1){
						printf("Entered number is not binary, please try again\n");
						break;
					}
					else{
						printf("The decimal representation is: %d\n", output);
						break;
					}
				case 2:
					output = decimal_to_binary(input);
					printf("The binary representation is: %d\n", output);
					break;
				case 3:
					output = octal_to_decimal(input);
					if(output == -1){
						printf("Entered number is not octal, please try again\n");
						break;
					}
					else{
						printf("The decimal representation is: %d\n", output);
						break;
					}
				case 4:
					output = decimal_to_octal(input);
					printf("The octal representation is: %d\n", output);
					break;
				case 5:
					output = decimal_to_octal(binary_to_decimal(input));
					printf("The octal representation is: %d\n", output);
					break;
				case 6:
					output = decimal_to_binary(octal_to_decimal(input));
					printf("The binary representation is: %d\n", output);
					break;
				case 7:
					break;
				default:
					printf("Invalid input provided, please try again.\n");
			}
		}
		return 0;
	}
	/*
	An integer n can be represented in base a, in the form of the summation of (coefficient)*a^k, where k is the dummy variable of summation,
	* and (coefficient) is an appropriate number defined in that base, e.g. 0-1 in binary 0-7 in octal, 0-9 in decimal
	* Thus, conversion of n from a base b, to another base a, primarily involves finding the appropriate
	* coefficient factors for base a, which can be done using the algorithm used in the following functions
	*/

	//For the following functions, n represents the input value provided by user. When -1 is returned, it indicates an error

	int binary_to_decimal(int n){
	int i = 0, output = 0;
		while(n!=0){
			if (!(n%10 >= 0 && n%10 <= 1)) return -1; //to ensure that a user does not input a number having digits other than 0 or 1
			output += (n%10)*pow(2, i);
			n /= 10;
			i++;
		}
		return output;
	}
	int decimal_to_binary(int n){	
		int i = 0, output = 0;
		while(n!=0){
			output += n%2*pow(10, i);
			n /= 2;
			i++;
		}
		return output;
	}
	int octal_to_decimal(int n){
		int i = 0, output = 0;
		while(n!=0){
			if (!(n%10 >= 0 && n%10 <= 7)) return -1; //to ensure that user cannot use the digits 8 and 9 for an octal number
			output += (n%10)*pow(8, i);
			n /= 10;
			i++;
		}
		return output;
	}
	int decimal_to_octal(int n){
		int i = 0, output = 0;
		while(n!=0){
			output += (n%8)*pow(10, i); 
			n /= 8;
			i++;
		}
		return output;
	}

