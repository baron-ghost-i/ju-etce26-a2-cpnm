#include <stdio.h>
#include <math.h>

void area(double *, double *, double *);
int main()
{
	double a, b, c;
	printf("Enter length of side 1: ");
	scanf("%lf", &a);
	printf("%.2f\n", a);
	printf("Enter length of side 2: ");
	scanf("%lf", &b);
	printf("%.2f\n",b);
	printf("Enter length of side 3: ");
	scanf("%lf", &c);
	printf("%.2f\n", c);
	area(&a, &b, &c);
	return 0;
}
void area(double *a, double *b, double *c)
{
	double s = ((*a)+(*b)+(*c))/2.0;
	double area = sqrt(s*(s-(*a))*(s-(*b))*(s-(*c)));
	printf("The area is: %.10f", area);
}
