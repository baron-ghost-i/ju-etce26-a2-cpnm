#include <stdio.h>
// Program for operations on two matrices
void sum(int[][3], int[][3], int, int);
void diff(int[][3], int[][3], int, int);
void mult(int[][3], int[][3], int, int);
int main()
{
	int m1[3][3], m2[3][3];
	int i, j;
	//Taking inputs for both matrices
	printf("Enter values for matrix 1:\n");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%d", &m1[i][j]);
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", m1[i][j]);
		}
		printf("\n");
	}
	
	printf("Enter values for matrix 2:\n");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%d", &m2[i][j]);
		}	
	}

	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("%d\t", 
			m2[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	sum(m1,m2,3,3);
	printf("\n");
	diff(m1,m2,3,3);
	printf("\n");
	mult(m1,m2,3,3);
	return 0;
}
//Adding matrices element by element
void sum(int m1[][3], int m2[][3], int row, int col)
{
	int i, j;
	printf("Sum:\n");
	for(i = 0; i<row;i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("%d\t", m1[i][j]+m2[i][j]);
		}
		printf("\n");
	}
}
//Subtracting the second matrix from the first
void diff(int m1[][3], int m2[][3], int row, int col)
{
	int i, j;
	printf("Difference:\n");
	for(i = 0; i<row;i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("%d\t", m1[i][j]-m2[i][j]);
		}
		printf("\n");
	}
}
//Multiplying two matrices
void mult(int m1[][3], int m2[][3], int row, int col)
{
	int i,j,k,mult[row][col];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			mult[i][j]=0;
			for(k=0;k<col;k++)
			{
				/*In matrix multiplication kth row of the first matrix
				is multiplied with kth column of second matrix*/
				mult[i][j] += m1[i][k]*m2[k][j]; 
			}
		}
	}
	printf("Product:\n");
	for(i = 0; i<row;i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("%d\t", mult[i][j]);
		}
		printf("\n");
	}
}
