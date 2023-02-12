#include <stdio.h>

//C Program to check for prime number

int main(){
	int num, i;
	int flag = 0;
	printf("Enter number to be checked: ");
	scanf("%d", &num);
	if (num==1){
		printf("Given number is neither prime, nor composite.\n");
		return 0;
	}

	for (i = 2; i <= num/2; i++){
		if (num%i == 0){
			flag = 1;
			break;
		}
	}
	if (!flag) printf("Given number is prime.\n");
	else printf("Given number is composite.\n");
	return 0;
}
