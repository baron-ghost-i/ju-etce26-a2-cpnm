#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[50];
	int marks[5];
	int roll;
	float avg;
} student;

void average(student* , int);

int main()
{
	int n, i, j, flag;
	char c;
	printf("How many students? ");
	scanf("%d", &n);
	student* stu = (student*)malloc(n*sizeof(student));
	for(i=0; i<n; i++)
	{
		printf("Enter name of student %d: ",i+1);
		scanf("%c", &c);
		gets((stu+i)->name);
		printf("Enter roll number of student %d: ", i+1);
		scanf("%d", &((stu+i)->roll));
		flag = 1;
		while(flag)
		{
			printf("Enter marks in 5 subjects of student %d: ", i+1);
			scanf("%d %d %d %d %d", &((stu+i)->marks[0]), &((stu+i)->marks[1]), &((stu+i)->marks[2]), &((stu+i)->marks[3]), &((stu+i)->marks[4]));
			(stu+i)->avg = 0;
			for(j=0; j < 5; j++){
				if ((stu+i)->marks[j] <= 100 && (stu+i)->marks[j] >= 0) flag = 0;
				else
				{
					flag = 1;
					printf("Invalid marks entered, try again.\n");
					break;
				}
			}
		}
	}
	average(stu, n);
	return 0;
}

void average(student* stu, int len)
{
	int i, j;
	for(i=0; i<len; i++)
	{
		for(j=0; j<5; j++){
			(stu+i)->avg += (stu+i)->marks[j];
		}
		(stu+i)->avg /= 5;
	}
	for(i=0; i<len; i++)
	{
		printf("\nName: ");
		puts((stu+i)->name);
		printf("Average: %.1f\n", (stu+i)->avg);
	}
}
