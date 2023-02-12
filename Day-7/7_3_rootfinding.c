#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) x*x*x - 4*x - 9
#define Df(x) 3*x*x - 4 //one can use numerical differentiation, but that'll be unnecessarily cumbersome as we are using a known polynomial function
#define null '0'

double bisection(double, double, double); //Bisection method
double rf(double, double, double); //Regula Falsi method
double nr(double, double, double); //Newton-Raphson method
void show_root(int, double, double, double); //helper function

int main()
{
	int ch = 0;
	double upper, lower, tolerance, root;
	while(ch!=4)
	{
		printf("--------------------------------\n");
		printf("MENU\n--------------------------------\n");
		printf("1. Bisection Method\n");
		printf("2. Regula Falsi Method\n");
		printf("3. Newton-Raphson Method\n");
		printf("4. Exit\n");
		printf("--------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		if(ch==1 || ch==2 || ch==3)
		{
			printf("Enter lower bound of interval to be searched: ");
			scanf("%lf", &lower);
			printf("Enter upper bound of interval to be searched: ");
			scanf("%lf", &upper);
			printf("Enter tolerance limit for the root: ");
			scanf("%lf", &tolerance);
			if (lower >= upper)
			{
				printf("Invalid interval provided, please try again.\n");
				continue;
			}
			if(tolerance > upper-lower) tolerance = upper-lower;
			show_root(ch, upper, lower, tolerance);
		}
		else if(ch==4) continue;
		else printf("Invalid choice provided.\n");
	}
	printf("\nExiting now.\n");
	return 0;
}

void show_root(int choice, double upper, double lower, double tolerance)
{
	double root;
	if(fabs(f(lower))<pow(10,-10)) root = lower;
	else if(fabs(f(upper))<pow(10,-10)) root = upper;
	else
	{
		switch(choice)
		{
			case 1:
				printf("Using Bisection method for finding root...\n");
				root = bisection(lower, upper, tolerance);
				break;
			case 2:
				printf("Using Regula Falsi method for finding root...\n");
				root = rf(lower, upper, tolerance);
				break;
			case 3:
				printf("Using Newton-Raphson method for finding root...\n");
				root = nr(lower, upper, tolerance);
				break;
		}
	}
	if (root==null) printf("No root found in this interval.\n");
	else printf("x^3-4x-9=0 => x=%lf\n", root);
}

double bisection(double l, double u, double e)
{
	double x;
	double fx, fu = f(u), fl = f(l);
	if (fl*fu > 0) return null;
	while(u-l >= e)
	{
		x = (u+l)/2;
		fx = f(x);
		if(fu*fx < 0) l = x;
		else if(fl*fx < 0) u = x;
		else if(fx == 0) break;
		else return null;
		fu = f(u);
		fl = f(l);
	}
	return x;
}

double rf(double l, double u, double e)
{
	double fl = f(l), fu = f(u);
	double x = (l*fu - u*fl)/(fu-fl), fx = f(x);
	if (fl*fu > 0) return null;
	while(fabs(fx) >= e)
	{
		x = (l*fu - u*fl)/(fu-fl);
		fx = f(x);
		if(fx*fl < 0) u = x;
		else if(fx*fu < 0) l = x;
		else return null;
		fl = f(l);
		fu = f(u);
	}
	return x;
}

double nr(double l, double u, double e)
{
	double x = (l+u)/2;
	double fx =f(x), dfx = Df(x);
	while(fabs(fx)>=e)
	{
		x = x - fx/dfx;
		fx = f(x);
		dfx = Df(x);
	}
	return x;
}
