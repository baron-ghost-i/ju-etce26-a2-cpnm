#include<stdio.h>

void squeeze(char*,char);
int main()
{
	char c,str[100];
	printf("Enter string: ");
	gets(str);
	puts(str);
	printf("\nEnter character: ");
	scanf("%c",&c);
	printf("%c\n",c);
	squeeze(str, c);
	printf("%s",str);
	return 0;
}
//Function to squeeze the input string
void squeeze(char* s,char c)
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	{
		if(s[i]!=c)
		{
			s[j]=s[i];
			j++;
		}
	}
	s[j] = '\0';
}
