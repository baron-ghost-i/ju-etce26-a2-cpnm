#include <stdio.h>

typedef struct
{
	int day;
	int month;
	int year;
} date;

int isleap(int);
int is_valid(date);
int compare(date, date);

int main()
{
	int result, ch = 1;
	date d1, d2;
	while(ch!=2)
	{
		printf("Press 1 to compare dates.\nPress 2 to quit\nEnter choice: ");
		scanf("%d",&ch);
		printf("%d\n",ch);
		switch(ch)
		{
			case 1:
				printf("Enter Date 1: ");
				scanf("%d/%d/%d", &d1.day, &d1.month, &d1.year);
				printf("%d/%d/%d\n",d1.day, d1.month, d1.year);
				printf("Enter Date 2: ");
				scanf("%d/%d/%d", &d2.day, &d2.month, &d2.year);
				printf("%d/%d/%d\n",d2.day, d2.month, d2.year);
				if(!(is_valid(d1) && is_valid(d2))) printf("Invalid dates entered, please try again.\n");
				else
				{
					result = compare(d1, d2);
					if(result < 0) printf("%d/%d/%d comes before %d/%d/%d\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
					else if(result == 0) printf("Dates are equal\n");
					else printf("%d/%d/%d comes before %d/%d/%d\n", d2.day, d2.month, d2.year, d1.day, d1.month, d1.year);
				}
				break;
			case 2:
				break;
			default:
				printf("Invalid choice, try again.\n");
				break;
		}
	}
	return 0;
}

/*
	Return type: int
	Return values:
	d1 > d2: -1
	d1 == d2: 10
	d1 < d2: 1
*/

int compare(date d1, date d2)
{
	int d1_num, d2_num;
	d1_num = d1.day + d1.month*100 + d1.year*10000;
	d2_num = d2.day + 100*d2.month + 10000*d2.year;
	if(d1_num < d2_num) return -1;
	else if(d1_num > d2_num) return 1;
	else return 0;
}

/*
	For the following functions, 0 is returned to denote "False",
	and 1 is returned to denote "True"
*/

int is_valid(date Date)
{
	if(Date.day<=0 || Date.month<=0 || Date.year<=0 || Date.day>31 || Date.month>12) return 0;
	if(Date.month==2)
	{
		if(isleap(Date.year) && Date.day > 29) return 0;
		if(!isleap(Date.year)&& Date.day > 28) return 0;
	}
	if((Date.month==4 || Date.month==6 || Date.month==9 || Date.month==11) && Date.day > 30) return 0;
	//When all invalid cases have been checked for
	return 1;
}

int isleap(int year)
{
	if(year%4 == 0)
	{
		if(year%100==0 && year%400 != 0) return 0;
		else return 1;
	}
	else return 0;
}
