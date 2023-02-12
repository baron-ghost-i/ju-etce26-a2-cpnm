#include <stdio.h>

//Interactive C program

int main(){
	float l, b, h, vol;
	printf("Program to calculate the volume of a cuboid\n");
	printf("Enter length: ");
	scanf("%f", &l);
	printf("Enter breadth: ");
	scanf("%f", &b);
	printf("Enter height: ");
	scanf("%f", &h);
	vol = l*b*h;
	printf("Volume of the cuboid is %.2f units", vol); //accurate upto 2 decimal places
	return 0;
}
