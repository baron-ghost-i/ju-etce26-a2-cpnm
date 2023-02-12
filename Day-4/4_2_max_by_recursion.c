#include <stdio.h>
//Program to find the biggest number in array using recursive function
int recformax(int*,int);
int main()
{
	int i;
	int arr[10];
	printf("Enter 10 numbers:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
		printf("%d\n",arr[i]);
	}
	int max = recformax(arr,10);
	printf("Biggest Number: %d", max);
	return 0;
}
//Recursive function starts
int recformax(int* a, int len)
{
	int max;
	if(len==1)
	{
		max = *a; //Terminating condition
	}
	else
	{
		if(*(a+len)>recformax(a,len-1)) //Recursive call for checking current indexed value with the previous one
		{
			max = *(a+len);
		}
		else
		{
			max = recformax(a,len-1); //Recursive call; if previous indexed value is less than the current value
		}
	}
	return max;
}
