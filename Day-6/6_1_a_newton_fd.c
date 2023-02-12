//Q. 1. (a) Newton forward interpolation

#include <stdio.h>
#include <stdlib.h>

double* tabulate(double *, int); //prints and returns the difference table
void forward(double *, double, int); //performs the actual interpolation

int main()
{
	int i, n;
	double x, *table;
	printf("Enter the number of data for function f(x): ");
	scanf("%d", &n);
	double *arr = (double*)malloc(sizeof(double)*2*n); //initial holder
	printf("Enter the data for f(x):\n");
	for(i=0; i<n; i++)
	{
		printf("X%d=", i+1);
		scanf("%lf", arr+i);
		printf("Y%d=", i+1);
		scanf("%lf", arr+n+i);
	}
	printf("Enter x: ");
	scanf("%lf", &x);
	printf("Difference table is:-\n");
	table = tabulate(arr, n);
	forward(table, x, n);
	free(table);
	return 0;
}

double* tabulate(double *p, int n)
{
	int i, j;
	double *table = (double*)calloc(sizeof(double), n*(n+1)); //using a flattened array
	printf("x\ty");
	for(i=0;i<n;i++)
	{
		*(table+i) = *(p+i); //
		*(table+n+i) = *(p+n+i);
	} //
	free(p); //frees up redundant heap
	for(i=1; i<n; i++)
	{
		printf("\t^%dy", i);
	}
	printf("\n");
	for(i=0; i<n-1;i++)
	{
		for(j=0; j<n-1-i; j++)
			*(table+((2+i)*n)+j) = *(table+((1+i)*n)+j+1) - *(table+((1+i)*n)+j);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1-i;j++)
		{
			printf("%.4f\t", *(table+(n*j)+i));
		}
		printf("\n");
	}
	return table;
}

void forward(double *table, double x, int n)
{
	int i, j, k, dr;
	double h = (*(table+1) - *table), nr = 1, result = *(table+n);
	double s;
	for(i=1;i<n;i++)
	{
		s = (x-*table)/h;
		dr=1;
		k=1;
		nr = *(table+(n*(i+1))); //points to the first element of ^ny
		for(j=0; j<i; j++)
		{
			nr *= s;
			dr *= k;
			s -= 1;
			k += 1;
		} 
		result += (nr/dr);
	}
	printf("f(%.0f) = %f", x, result);
}
