#include <stdio.h>

int main(){
	int num, temp, flag = 1, rev_num = 0; //'flag' will be used in the event a number is encountered with a 0 in it
	while(1){
		printf("Enter a number: ");
		scanf("%d", &num);
		temp = num;
		if(num==0) break;
		if (num<0){
			printf("Number cannot be negative, please try again\n");
			continue;
		}
		while(temp!=0){
			if (temp%10==0){
				printf("Number must not contain 0\n");
				flag = 0;
				break;
			}
			rev_num = (rev_num*10 + temp%10);
			temp /= 10;
		}
		if(flag){
			if(rev_num==num) printf("Entered number is a palindrome\n");
			else printf("Entered number is not a palindrome\n");
		} //preventing this block from executing in the event a number with 0 is encountered
		flag = 1;
		rev_num = 0;//to continue with next iteration
	}
	return 0;
}
