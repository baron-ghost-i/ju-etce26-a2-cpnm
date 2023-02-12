#include <stdio.h>
#include <stdlib.h>


int main()
{
	int **mat1, **mat2, **res, i, j, k, r1, c1, r2, c2;
	printf("Enter dimensions of matrix 1: ");
	scanf("%d %d",&r1,&c1);
	printf("%d %d\n", r1, c1);
	printf("Enter the Order of matrix 2: ");
	scanf("%d %d", &r2, &c2);
	printf("%d %d\n", r2, c2);

	if(c1!=r2)
	{
		printf("Invalid order of matrices.\n");
		return 0;
	}

	//creating the pointer equivalents of a two-dimensional matrix
	mat1= (int**) malloc(r1*sizeof(int*));
	for(i=0;i<r1;i++) mat1[i]=(int*)malloc(c1*sizeof(int)); 
	mat2= (int**) malloc(r2*sizeof(int*));
	for(i=0;i<r2;i++) mat2[i]=(int*)malloc(c2*sizeof(int));
	res=(int**)calloc(r1,sizeof(int*));
	for(i=0;i<r1;i++) res[i]=(int*)calloc(c2,sizeof(int));

    //Inputs for the two matrices
    printf("Enter values for matrix 1:\n");
    for(i=0;i<r1;i++)
    {
    	for(j=0;j<c1;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("\nEnter values for matrix 2:\n");
    for(i=0;i<r2;i++)
	{
    	for(j=0;j<c2;j++)
		{
			scanf("%d",&mat2[i][j]);
		}
	}

	printf("\nEntered values for matrix 1: \n");
	for(i=0;i<r1;i++){
	    for(j=0;j<c1;j++) printf("%d ",mat1[i][j]);
	    printf("\n");
	}
	printf("\nEntered values for matrix 2: \n");
	for(i=0;i<r2;i++){
	    for(j=0;j<c2;j++)
	        printf("%d ",mat2[i][j]);
	    printf("\n");
	}       

	//Multiplication
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			res[i][j]=0;
			for(k=0;k<c1;k++) res[i][j]+= mat1[i][k]*mat2[k][j];
		}
    }
   printf("\nProduct: \n");
   for(i=0;i<r1;i++){
       printf("\n");
       for(j=0;j<c2;j++)
            printf("%d\t",res[i][j]);   
   }
   printf("\n");
   return 0;
}
