#include <stdio.h>

//C program to print first ten prime numbers

int main(void){
	int i, j, flag = 0, counter = 0;
	i = 2;
	printf("First ten prime numbers:\n");
	while (counter != 10){
		for (j = 2; j <= i/2; j++){
			if (i%j == 0){
				flag = 1;
				break;
			}
		}
		if (!flag){
			printf("%d\n", i);
			counter++;
		}
		flag = 0;
		i++;
	}
	return 0;
}
