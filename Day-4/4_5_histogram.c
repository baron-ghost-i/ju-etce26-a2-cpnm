#include <stdio.h>
//Program to count the number of occrurances of a alphabet in a word
void hist(char*, char, char);
int main()
{
	int i=0,j,k;
	char str[100];
	printf("Enter string: ");
	gets(str);
	puts(str);
	for(j=65, k=97;j<=90 && k<=122;j++,k++) //j is for checking capital letters and k is for small letters
	{
		char t = j;
		char u = k;
		hist(str, t, u);
	}
	return 0;
}
void hist(char* str, char t, char u)
{
	int count=0,i=0;
	//Traversing through the string and checking every alphabet
	while(str[i]!='\0')
	{
		if(str[i]==t || str[i]==u)
		{
			count++;
		}
		i++;
	}
	if(count!=0)
	{
		printf("%c: %d\n",u,count);
	}
}
