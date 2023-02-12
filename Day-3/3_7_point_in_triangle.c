#include <stdio.h>
#include <math.h>

struct Point{
	double x;
	double y;
};

double dist(struct Point, struct Point);
double area(struct Point, struct Point, struct Point);
int inside_triangle(struct Point, struct Point, struct Point, struct Point);

int main(){
	int i, result, flag = 1;
	struct Point A, B, C, D;
	double x[4], y[4];
	while(flag){
		printf("----------------------------------------------------------------------------------------------\n");
		printf("Program to check whether a point is inside a triangle or not. To exit, enter 0 for all points.\n");
		for(i = 0; i < 3; i++){
			printf("Enter x-coordinate of vertex %d of triangle: ", (i+1));
			scanf("%lf", &x[i]);
			printf("Enter y-coordinate of vertex %d of triangle: ", (i+1));
			scanf("%lf", &y[i]);
		}
		printf("Enter x-coordinate of point to be checked: ");
		scanf("%lf", &x[3]);
		printf("Enter y-coordinate of point to be checked: ");
		scanf("%lf", &y[3]);
		flag = 0;
		for(i=0; i < 4; i++){
			if(x[i] != 0 || y[i] != 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0) return 0;
		A.x = x[0], A.y = y[0], B.x = x[1], B.y = y[1];
		C.x = x[2], C.y = y[2], D.x = x[3], D.y = y[3];
		result = inside_triangle(A, B, C, D);
		if (result == 1) printf("Point lies inside given triangle.\n");
		else if(result == 2) printf("Point lies on the given triangle.\n");
		else printf("Point lies outside given triangle.\n");
	}
	return 0;
}

double dist(struct Point A, struct Point B){
	double dist_squared = pow(A.x-B.x, 2) + pow(A.y-B.y, 2);
	return sqrt(dist_squared);
}

double area(struct Point A, struct Point B, struct Point C){
	double AB = dist(A, B);
	double BC = dist(B, C);
	double AC = dist(A, C);
	double s = (AB + BC + AC)/2;
	double area = sqrt(s*(s-AB)*(s-BC)*(s-AC));
	return area;
}

int inside_triangle(struct Point A, struct Point B, struct Point C, struct Point P){
	double ar = area(A, B, C);
	double ar1 = area(A, B, P);
	double ar2 = area(A, C, P);
	double ar3 = area(B, C, P);
	if(ar1==0 || ar2==0 || ar3 == 0) return 2;
	else if ((ar-ar1-ar2-ar3) < pow(10, -6) ) return 1; //to neglect error caused by representation of floating point numbers
	else return 0;
}
