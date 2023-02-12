#include <stdio.h>
	#include <stdlib.h>
	void pattern1(int);
	void pattern2(int);
	void pattern3(int);
	void pattern4(int);
	int main()
	{
	  int n, ch=0;
	  while(ch!=5){
		printf("Available choices: \n");
		printf("1. Pattern 1\n");
		printf("2. Pattern 2\n");
		printf("3. Pattern 3\n");
		printf("4. Pattern 4\n");
		printf("5. To Exit\n");
		printf("Enter number of your choice: ");
		scanf("%d",&ch);
		printf("%d",ch);
		if(ch!=5){
			printf("\nEnter value of n: ");
			scanf("%d",&n);
			printf("%d\n", n);
		}
		switch(ch){
			case 1:
				pattern1(n);
        			break;
			case 2:
				pattern2(n);
        			break;
			case 3:
        			pattern3(n);
        			break;
			case 4:
        			pattern4(n);
        			break;
      			case 5:
        			exit(1);
      			default:
        			printf("Invalid input!\n");
    			}
  		}
  		return 0;
	}
	
	void pattern1(int n){
  		int i,j;
  		for(i = 1;i<=n;i++){
			for(j = 1;j<=i;j++){
				printf("%d ",j);
			}
			printf("\n");
		}
	}
	void pattern2(int n){
		int i,j,k;
  		for(i=1;i<=n;i++){
    			for(j = 1;j<=n-i;j++){
      				printf(" ");
    			}
    			for(k = 1;k<=i;k++){
				printf("%d",k);
    			}
    			printf("\n");
  		}
	}
	void pattern3(int n){
		int i,j,k,l;
		for(i=1;i<=n;i++){
			for(j = 1;j<=n-i;j++){
				printf(" ");
			}
			for(k = 1;k<=i;k++){
				printf("%d",k);
			}
			for(l=i-1;l>=1;l--){
				printf("%d",l);
			}
			printf("\n");
		}
	}
	void pattern4(int n){
		int i, j;
		for(i=1;i<=n/2+1;i++){
			for(j=(n-i+1);j>=(i-1);j--){
				printf("%d", j);
			}
			printf("\n");
		}
	}

