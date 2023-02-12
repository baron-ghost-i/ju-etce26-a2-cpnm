//Q. 3. Lagrange interpolation

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, n;
	double x, prod, *xis, *fis, result = 0;
	printf("Enter n: ");
	scanf("%d", &n);
	xis = (double*)malloc(n*sizeof(double));
	fis = (double*)malloc(n*sizeof(double));
	printf("Enter the value of x to be found: ");
	scanf("%lf", &x);
	printf("Enter the values of xi's and fi's:\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf %lf", &xis[i], &fis[i]);
	}
	for(i=0; i<n; i++)
	{
		prod = fis[i];
		for(j=0; j<n; j++)
		{
			if(i!=j) prod *= (x - xis[j])/(xis[i] - xis[j]);
		}
		result += prod;
	}
	printf("x = %lf\n", x);
	printf("Sum = %lf", result);
	return 0;
}
