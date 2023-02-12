#include <stdio.h>
int main(){
	int m1,m2,m3,m4,m5;
	printf("Maximum marks for individual subjects is 100\n");
	while(1){
		printf("Enter marks of 1st subject: ");
		scanf("%d",&m1);
		if(m1>100 || m1<0) printf("Invalid marks entered.\n");
		else break;
	}
	while(1){
		printf("Enter marks of 2nd subject: ");
		scanf("%d",&m2);
		if(m2>100 || m2<0) printf("Invalid marks entered.\n");
		else break;
	}
	while(1){
		printf("Enter marks of 3rd subject: ");
		scanf("%d",&m3);
		if(m3>100 || m3<0) printf("Invalid marks entered.\n");
		else break;
	}
	while(1){
		printf("Enter marks of 4th subject: ");
		scanf("%d",&m4);
		if(m4>100 || m4<0) printf("Invalid marks entered.\n");
		else break;
	}
	while(1){
		printf("Enter marks of 5th subject: ");
		scanf("%d",&m5);
		if(m5>100 || m5<0) printf("Invalid marks entered.\n");
		else break;
	}
	int total = m1+m2+m3+m4+m5;
	float percentage = total/5.0;
	printf("Total marks: %d\nPercentage : %.2f%c",total,percentage,'%');
	return 0;
}
