#include <stdio.h>

//Program to swap four numbers cyclically

void swap(int *); //swapper function

int main()
{
	int arr[4], ch = 1;
	/*Mapping:
	a -> arr[0]
	b -> arr[1]
	c -> arr[2]
	d -> arr[3]*/
	
	printf("Enter a, b, c and d respectively: ");
	scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
	printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
	while(ch%2) //since ch%2 == 1 for ch == 1, ch%2 == 0 for ch == 0
	{
		swap(arr);
		printf("Press 1 to cyclic swap\nPress 2 to quit\nEnter choice: ");
		scanf("%d", &ch);
		printf("%d\n", ch);
		if(ch!=1 && ch!=2)
		{
			printf("Invalid choice entered.\n");
			ch = 1;
			continue;
		}
	}
	return 0;
}

void swap(int *arr)
{
	int i, temp;
	printf("Value before swapping:\na = %d\nb = %d\nc = %d\nd = %d\n", *arr, *(arr+1), *(arr+2), *(arr+3));
	temp = *(arr+3);
	for(i=2;i>=0;i--)
	{
		*(arr+i+1) = *(arr+i);
	}
	*arr = temp;
	printf("Value after swapping:\na = %d\nb = %d\nc = %d\nd = %d\n", *arr, *(arr+1), *(arr+2), *(arr+3));
}
