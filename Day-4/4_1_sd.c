#include <stdio.h>
#include <math.h>
/*Program to calculate standard deviation of a set of 10 numbers*/
float sd(float, int*);
float mean(int*);
int main()
{
	int i, arr[10];
	float m,stan_d;
	printf("Enter 10 numbers: \n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
		printf("%d\n",arr[i]);
	}
	m = mean(arr);
	stan_d = sd(m,arr);
	printf("Standard Deviation: %f",stan_d);
	return 0;
}
//Function for calculating Mean
float mean(int* a)
{
	int i;
	float s=0.0;
	for(i=0;i<10;i++)
	{
		s+=*(a+i);
	}
	return s/10.0;
}
//Function for calculating Standard Deviation
float sd(float mean, int* a)
{
	int i;
	float dev, s=0.0;
	for(i=0;i<10;i++)
	{
		s += pow((*(a+i)-mean),2.0);
	}
	dev = sqrt(s/9);
	return dev;
}
