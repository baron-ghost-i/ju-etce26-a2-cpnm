#include <stdio.h>

double trapezoid(double*, double*, int);
double simpson(double*, double*, int);

int main()
{
	int i;
	double a[9]={40, 45.25,48.51,51.25,54.35,59.48,61.50,64.3,68.7};
	double t[9]={0,5,10,15,20,25,30,35,40};
	double v_t[9], v_s[9];
	
	for(i=0; i<9; i++)
	{
		v_t[i] = trapezoid(a,t,i);
		v_s[i] = simpson(a,t,i);
	}
	
	printf("Using Trapezoidal rule\nVelocity at t = %.0lf s: %lf\n", t[8], v_t[8]);
	printf("Position at t = %.0lf s: %lf\n", t[8], trapezoid(v_t ,t, 8));
	printf("\nUsing Simpson's rule\nVelocity at t = %.0lf s: %lf\n", t[8], v_s[8]);
	printf("Position at t = %.0lf s: %lf\n", t[8], simpson(v_t ,t, 8));
	
	return 0;
}

//int(y dx) = (h/2)(y0 + 2(y1+y2+...+y(n-1)) + yn) using trapezoidal rule
double trapezoid(double* arr, double* t, int i)
{
	int j;
	double res,s=0, h = t[1] - t[0];
	
	for(j=1 ;j<i; j++) s += arr[j];
	res=(h/2.0)*(arr[0]+arr[i]+2*s);
	
	return res;		
}

//int(y dx) = (h/3)(y0 + 4(y1+y3+...) + 2(y2+y4+...) + yn) using Simpson's (1/3)rd rule
double simpson(double* arr, double* t, int i)
{	
	double res,s=0,h = t[1]-t[0];
	
	for(int j = 1;j<i;j++)
	{
		if(j%2) s += 4*arr[j]; //equivalent to: if(j%2!=0) s+= 4*arr[j]
		else s += 2*arr[j];
	}
	res=(h/3.0)*(arr[0]+arr[i]+s);
	
	return res;		
}
