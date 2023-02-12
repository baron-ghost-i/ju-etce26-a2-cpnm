#include <stdio.h>
	#include <math.h>

	int isArmstrong(int);

	int main(){
		int i, u, l, count = 0; //upper and lower limits of range
		while(1){
			printf("To exit, enter 0 and 0.\n");
			printf("Enter lower limit: ");
			scanf("%d", &l);
			printf("%d\n", l);
			printf("Enter upper limit: ");
			scanf("%d", &u);
			printf("%d\n", u);
			if(u==0&&l==0) break;
			for(i = l; i <= u; i++){
				if(isArmstrong(i)){
					printf("%d ", i);
					count++;
				}
			}
			printf("\nNumber of Armstrong numbers in given range: %d\n", count);
			count = 0;
		}
		return 0;
	}

	int isArmstrong(int n){
		int nod = 0;
		int m = n;
		int s = 0,p = n;
		while(m>0){
			m /= 10;
			nod++;
		}
		while(p>0){
			s += pow(p%10,nod);
			p /= 10;
		}
		if(s == n) return 1;
		else return 0;
	}

