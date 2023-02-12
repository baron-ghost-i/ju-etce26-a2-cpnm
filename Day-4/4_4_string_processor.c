#include <stdio.h>
/*Program to take a string from user and count the number of chracters
and words, and reverse it*/
int count_char(char*);
int count_words(char*);
void reverse(char*);

int main()
{
	char str[100];
	int chars, words;
	printf("Enter string:\n");
	gets(str); //using gets() instead of scanf() since scanf() cannot take multi-word string reliably
	puts(str);
	chars = count_char(str);
	words = count_words(str);
	printf("Characters: %d\n", chars);
	printf("Words: %d\n", words);
	reverse(str);
}
//Counting number of characters, including whitespaces
int count_char(char* str)
{
	int i=0,count=0;
	while(str[i]!='\0')
	{
		count++;
		i++;
	}
	return count;
}
//Counting words divided by one whitespace
int count_words(char* str)
{
	int i=0,count=0;
	while(str[i]!='\0')
	{
		if(str[i]==' ')
		{
			count++;
		}
		i++;
	}
	return count+1;
}
//To reverse the string
void reverse(char* str)
{
	int i, len = count_char(str);
	char tmp;
	for(i = 0; i < len/2; i++)
	{
		tmp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = tmp;
	}
	printf("Reversed: ");
	puts(str);
}
