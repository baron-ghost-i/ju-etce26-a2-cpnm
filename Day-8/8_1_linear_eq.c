#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//For passing the matrix to functions easily
typedef struct{
	double **M;
	int n; //corresponds to number of equations
} matrix;

//For easier access; optional
#define mat (m.M)
#define mat_ (m->M)

/*
	Gauss method for solving a set of linear equations
	Parameters:
	- (matrix) m: The coefficient matrix
*/
void gauss(matrix);

/*
	Gauss Pivoting method (Gauss-Jordan method) for solving a set of linear equations
	Parameters:
	- (matrix) m: The coefficient matrix
*/
void gauss_pivot(matrix);


/*
	Jacobi method for solving a set of linear equations
	Parameters:
	- (matrix) m: The coefficient matrix
	- (int) maxit: Maximum number of iterations to be performed
*/
void jacobi(matrix, int);

//helper functions
void print_eq(matrix); //prints equations
int rowmax(double[], int); //locates maxima of a row
int fnz(double*, int); //locates first nonzero element of a row
void swap(double*, double*, int); //swaps two rows
void rearrange(matrix*, int); //rearranges the matrix, with parameter "flag" indicating the method used

int main(){
	int ch, i, j, maxit;
	matrix m;
	
	while(1){
		printf("\n--------------------------------\nMENU\n");
		printf("--------------------------------\n");
		printf("1. Gauss Elimination Method\n2. Gauss Elimination with pivoting method\n3. Jacobi's Method\n4. Exit\n");
		printf("--------------------------------\nEnter your choice: ");
		scanf("%d", &ch);
		if(ch==4) exit(0);
		
		printf("Enter number of equations: ");
		scanf("%d", &m.n);
		
		mat = (double**)malloc(m.n*sizeof(double*)); //mat is replaced with m.M by the preprocessor through the directive #define
		for(i=0; i<m.n; i++) mat[i] = (double*)calloc(m.n+1, sizeof(double)); //initializing empty matrix
		
		printf("COEFFICIENT MATRIX M:\n---------------------\n");
		for(i=0; i<m.n; i++)
			for(j=0; j<m.n+1; j++){
				printf("Enter M[%d][%d]: ", i+1, j+1);
				scanf("%lf", &mat[i][j]);
			}
		printf("EQUATIONS:\n");
		print_eq(m);
		
		switch(ch){
			case 1:
				gauss(m);
				break;
			case 2:
				gauss_pivot(m);
				break;
			case 3:
				printf("Enter maximum number of iterations: ");
				scanf("%d", &maxit);
				jacobi(m, maxit);
				break;
			default:
				printf("Invalid choice.\n");
		}
	}
	return 0;
}

void gauss(matrix m){
	int i, j, k, n = m.n;
	double factor, s;
	
	for(i=0; i<n; i++){
		rearrange(&m, 0);
		for(j=i+1; j<n; j++){
			factor = mat[j][i]/mat[i][i];
			for(k=0; k<n+1; k++)
				mat[j][k] -= mat[i][k]*factor;
		}
	}
	
	/*
		Solving the equations formed after rearrangement yield the following results:
		x(n-1) = y(n-1)/mat[n-1][n-1]
		x(n-2) = (y(n-2) - mat[n-2][n-1]*x(n-1))/mat[n-2][n-2]
		...
		x(i) = (y(i) - ( mat[i][i+1]*x(i+1) + mat[i][i+2]*x(i+2) + ... + mat[i][n-1]*x(n-1) ))/mat[i][i]
		where y(i) == mat[i][n]
		In the following loop, y(i) will be overwritten by x(i) successively, thus mat[j][n] == x(j)
	*/
	
	for(i=n-1; i>0; i--){
		s=0;
		for(j=i+1; j<n; j++)
			s += mat[i][j]*mat[j][n];
		mat[i][n] = (mat[i][n] - s)/mat[i][i]; //overwrites y(i) with x(i)
	} //solving all equations within this loop
	for(i=0; i<n; i++)
		printf("x%d = %lf\n", i+1, mat[i][n]);
}

void gauss_pivot(matrix m){
	int i, j, k, n = m.n;
	double factor, s;

	for(i=0; i<n; i++){
		rearrange(&m, 0);
		for(j=0; j<n; j++){
			if(i==j) continue; //to avoid subtracting a row from itself
			factor = mat[j][i]/mat[i][i];
			for(k=0; k<n+1; k++)
				mat[j][k] -= mat[i][k]*factor;
		}
	}
	
	/*
		Solving the equations formed after rearrangement yield the following results:
		x(n-1) = y(n-1)/mat[n-1][n-1]
		x(n-2) = y(n-2)/mat[n-2][n-2]
		...
		x(i) = y(i)/mat[i][i]
		where y(i) == mat[i][n]
	*/
	
	for(i=0; i<n; i++)
		mat[i][n] /= mat[i][i];
	for(i=0; i<n; i++)
		printf("x%d = %lf\n", i+1, mat[i][n]);
}

void jacobi(matrix m, int maxit){
	int i, j, n = m.n, iter = 0;
	double* x = (double*)malloc(n*sizeof(double));
	double* x1 = (double*)malloc(n*sizeof(double));
	
	rearrange(&m, 1);
	
	printf("Enter initial guesses:\n");
	for(i=0; i<n; i++){
		printf("x%d=", i+1);
		scanf("%lf", &x[i]);
	}
	
	while(iter < maxit){
		for(i=0; i<n; i++){
			x1[i] = mat[i][n];
			for(j=0; j<n; j++)
				if(i!=j)
					x1[i] -= mat[i][j]*x[j];
			x1[i] /= mat[i][i];
		}
		for(i=0; i<n; i++)
			x[i] = x1[i];
		iter++;
	}
	
	for(i=0; i<n; i++)
		printf("x%d = %lf\n", i+1, x1[i]);
}

void rearrange(matrix* m, int flag){
	int i, j, k, temp, n = m->n;
	
	switch(flag){
		//Gauss & Gauss-Jordan
		case 0:
			for(i=0; i<n; i++){
				temp = fnz(mat_[i], n);
				if(temp!=i)
					swap(mat_[i], mat_[temp], n);
			}
			break;
			
		//Jacobi	
		case 1:
			for(i=0; i<n; i++){
				temp = rowmax(mat_[i], n);
				if(temp!=i)
					swap(mat_[i], mat_[temp], n);
			}
			break;
		default:
			printf("Internal error\n");
	}
}

void print_eq(matrix m){
	int i, j, n = m.n;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%+lfx%d ", mat[i][j], j+1);
		}
		printf("= %lf\n", mat[i][n]);
	}
}

int fnz(double *row, int n){
	int i, nz = 0;
	for(i=0; i<n; i++){
		if(row[i] != 0){
			nz = i;
			break;
		}
	}
	return nz;
}

int rowmax(double row[], int n){
	int i, max = 0;
	for(i=0; i<n; i++)
		if(row[i] > row[max])
			max = i;
	return max;
}

void swap(double* a, double* b, int n){
	int i;
	double temp[n];
	for(i=0; i<=n; i++){
		temp[i] = a[i];
		a[i] = b[i];
		b[i] = temp[i];
	}
}
