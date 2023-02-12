//Q.2. Newton's divided difference

#include <stdio.h>
#include <stdlib.h>

void tabulate(double**, int); //performs interpolation and prints difference table

int main()
{
	int i, n;
	double **xy;
	printf("\nEnter the number of observations:\n");
	scanf("%d", &n);
	xy = (double**)malloc(2*sizeof(double*));
	for(i=0; i<n; i++) xy[i] = (double*)calloc(n, sizeof(double));
	printf("Enter the different values of x:\n");
	for(i=0;i<n;i++) scanf("%lf", &xy[0][i]);
	printf("\nThe corresponding values of y are:\n");
	for(i=0;i<n;i++) scanf("%lf", &xy[1][i]);
	tabulate(xy, n);
	return 0;
}

void tabulate(double** xy, int n)
{
	int i, j;
	double k, prod, result = 0;
	double **table = (double**)malloc(sizeof(double*)*(n+1));
	
	printf("\nEnter the value of 'k' in f(k) you want to evaluate: \n");
    scanf("%lf", &k);
	
	for(i=0; i<=n; i++) table[i] = (double*)calloc(n,sizeof(double)); //each heap represents a column, thus table[i][j] represents jth row and ith column
	for(i=0; i<n; i++)
	{
		table[0][i] = xy[0][i];
		table[1][i] = xy[1][i];
	} //assigning values from xy to difference table
	free(xy); //deallocating xy since it will not be needed anymore
	//creating the difference table
	for(j=2;j<=n;j++)
	{
		for(i=0; i<n+1-j;i++)
		{
			table[j][i] = (table[j-1][i+1] - table[j-1][i])/(table[0][i+j-1] - table[0][i]);
		}
	}
	for(i=0;i<n;i++)
	{
		prod = 1;
		for(j=0;j<i;j++)
		{
			prod *= k - table[0][j];
		}
		result += prod*table[i+1][0];
	}
	printf("\nf(%.0f) = %.0f\n", k, result);
	free(table);
}
