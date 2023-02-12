#include <stdio.h>

int main(){
	int l, m, lm, P; //Provided by user
	int I, IM, IW; //Internal variables
	while(1){
		printf("Enter percentage of men: ");
		scanf("%d", &m);
		printf("Enter percentage of total literacy: ");
		scanf("%d", &l);
		printf("Enter percentage of literate men: ");
		scanf("%d", &lm);
		printf("Enter total population: ");
		scanf("%d", &P);
		if((l<0||l>100)||(m<0||m>100)||(lm<0||lm>100)||P<0) printf("Invalid input provided, please try again.\n");
		else break;
	}
	IM = ((100-lm)*(P*m/100))/100; //Number of illiterate men
	IW = (P - P*l/100) - IM; //Number of illiterate women
	printf("Total number of illiterate men: %d\n", IM);
	printf("Total number of illiterate women: %d\n", IW);
	return 0;
}
