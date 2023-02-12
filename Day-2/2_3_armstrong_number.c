#include <stdio.h>
int main(){
	while(1){
		int n,s=0;
		printf("Enter a number: ");
		scanf("%d",&n);
		int m = n;
		if(n>=100 && n<=999){
			while(n>0){
				s = s + (n%10)*(n%10)*(n%10);
				n = n/10;
			}
			if(m==s) printf("It is an Armstrong number");
			else printf("It is not an Armstrong number");
			break;
		}
		else printf("Invalid number entered. Please enter number between 100 and 999.\n");
	}
	return 0;
}
