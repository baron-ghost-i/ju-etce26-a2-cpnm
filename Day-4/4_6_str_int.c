#include <stdio.h>
#include <math.h>

int str_to_int(char);
char int_to_str(int);
int len(char*);
 //Menu-driven program to convert integer to string and vice-versa
int main()
{
	int innum, outnum, stringlength, flag = 1, ch = 1; // I/O control variables
	int i, j; //counter variables
	char c, instr[100], outstr[100]; // I/O control characters and strings
	int nod, p, d; //for mathematical operations while converting int to string
	while(ch)
	{
		printf("To convert from string to integer, press 1.\nTo convert from integer to string, press 2.\nTo exit, press 0.\n");
		printf("Enter choice: ");
		scanf("%d", &ch);
		printf("%d\n", ch);
		scanf("%c", &c);
		switch(ch)
		{
			case 1:
				printf("Enter string: ");
				gets(instr);
				puts(instr);
				stringlength = len(instr);
				outnum = 0; //to ensure that two iterations of the principal loop do not interfere
				for(i = 0; i<stringlength; i++)
				{
					j = str_to_int(instr[i]);
					if(j!=-1) outnum = outnum*10 + j;
					else
					{
						printf("Invalid character detected, terminating execution.\n");
						flag = 0;
						break;
					}
				}
				if(flag) printf("Number: %d\n", outnum);
				else flag = 1;
				break;
			case 2:
				printf("Enter number: ");
				scanf("%d", &innum);
				printf("%d\n", innum);
				nod = log10(innum); //number of digits of innum, minus one
				i = nod;
				if(innum == 0) //since the following code cannot account for input number being 0
				{
					printf("String: 0\n");
					break;
				}
				while(innum != 0)
				{
					d = innum%10; //accessing digits of the number
					innum /= 10;
					c = int_to_str(d);
					printf("\n- %c\n", c);
					if(c != 'e')
					{
						outstr[i] = c;
						i--; //since the last digit is accessed first
					}
					else
					{
						printf("Invalid character detected, terminating execution.\n");
						break;
						flag = 0;
					}
				}
				if(flag)
				{
					printf("String: ");
					puts(outstr);
				}
				else flag = 1;
				i = 0; //since i takes the value of -1 after last iteration of the while loop
				while(outstr[i] != '\0')
				{
					outstr[i] = '\0'; //to reset the string before next iteration of menu loop
					i++;
				}
				break;
			case 0:
				break;
			default:
				printf("Invalid choice provided.\n");
		}
	}
	return 0;
}

//accessing length of input string
int len(char* str)
{
	int i = 0, len = 0;
	while(*(str+i) != '\0')
	{
		len++;
		i++;
	}
	return len;
}

//Following functions behave as enumerations
int str_to_int(char a)
{
	switch(a)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return -1; //Invalid character handler
	}
}

char int_to_str(int i)
{
	switch(i)
	{
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		default: return 'e'; //Invalid digit handler
	}
}
