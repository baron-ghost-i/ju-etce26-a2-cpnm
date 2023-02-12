#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i;
	printf("How many numbers? ");
	scanf("%d", &n);
	printf("%d\n", n);
	int *p = (int*)malloc(n*sizeof(int*));
	for(i=0; i<n; i++)
	{
		scanf("%d", (p+i));
		printf("%d\n", *(p+i));
	}
	for(i=0; i<n; i++)
	{
		printf("%d is located at %p\n", *(p+i), (p+i));
	}
	return 0;
}
