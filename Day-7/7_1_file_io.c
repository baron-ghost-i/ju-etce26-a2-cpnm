#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	double mean = 0, sd = 0;
	int marks[30];
	FILE *fpout, *fpin = fopen("txt/Input.txt", "r");
	
	for(i=0; i<30; i++)
	{
		fscanf(fpin, "%d\n", &marks[i]);
		mean += marks[i]/30.0;
	}
	fclose(fpin);
	
	for(i=0; i<30; i++) sd += pow((marks[i] - mean), 2); //using a single variable for the operations; this stage is the evaluation of variance
	sd = sqrt(sd/29); //evaluation of the standard deviation for a sample, thus (30-1) has been used
	
	printf("Mean: %lf\nStandard Deviation: %lf\nWriting values to Output.txt (separated by newline)...\n", mean, sd);
	
	fpout = fopen("txt/Output.txt", "w");
	fprintf(fpout, "%lf\n%lf", mean, sd);
	fclose(fpout);
	
	return 0;
}
