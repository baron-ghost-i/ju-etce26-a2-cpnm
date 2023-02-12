#include <stdio.h>
#include <math.h>

typedef struct matrix
{
	double M[3][4]; //3x4 matrix as it is an augmented matrix
} matrix; //For passing to functions easily

void gauss(matrix, int);
void gauss_pivot(matrix, int);
void jacobi(matrix, int);
matrix gauss_rearrange(matrix, int, int); //helper function for Gauss method and Gauss method with pivoting
matrix jacobi_rearrange(matrix, int); //converts system to diagonally-dominant system

int main()
{
	matrix M1 = {{{1,1,1,6}, {1,1,-1,0}, {1,-1,1,2}}};
	matrix M2 = {{{1,1,1,3}, {2,3,1,6}, {1,-1,-1,-3}}};
	matrix M3 = {{{2,4,2,15}, {2,1,2,-5}, {4,1,-2,0}}};
	int i, j, ch_eq = 4, ch_mt = 4, ch_rpt = 1;
	matrix m;
	while(1)
	{
		//Using x1, x2, x3 instead of x, y, z to implement the generalizations more completely
		printf("\n--------------------------------\n");
		printf("MENU\n");
		printf("--------------------------------\n");
		printf("1. x1+x2+z=6\t2. x1+x2+x3=3  \t3. 2x1+4x2+2x3=15\n");
		printf("   x1+x2-x3=0\t   2x1+3x2+x3=6\t   2x1+x2+2x3=-5\n");
		printf("   x1-x2+x3=2\t   x1-x2-x3=-3 \t   4x1+x2-2x3=0\n");
		printf("Enter the system of equations to solve. To exit, enter 4: ");
		scanf("%d", &ch_eq);
		if(ch_eq==4) break;
		printf("--------------------------------\n");
		printf("1. Gauss Elimination Method\n2. Gauss Elimination with pivoting method\n3. Jacobi's Method\n4. Exit\n");
		printf("--------------------------------\n");
		printf("Enter your choice: ");
		scanf("%d", &ch_mt);
		if(ch_mt==4) break;
		switch(ch_eq)
		{
			case 1:
				m = M1;
				break;
			case 2:
				m = M2;
				break;
			case 3:
				m = M3;
				break;
			default:
				printf("Invalid choice provided, please try again.\n");
				continue;
		}
		switch(ch_mt)
		{
			case 1:
				gauss(m, 3);
				break;
			case 2:
				gauss_pivot(m, 3);
				break;
			case 3:
				if(ch_eq==1) printf("System is divergent.");
				else jacobi(m, 3);
				break;
			default:
				printf("Invalid choice provided, please try again.\n");
				continue;
		}
	}
	return 0;
}

void gauss(matrix m, int n)
{
	int i, j, k;
	double factor, x[n];
	for(i=0;i<n-1;i++)
	{
		for(j=n-1; j>i; j--)
		{
			factor = (m.M[j][i]/m.M[i][i]);
			for(k=0; k<4; k++) m.M[j][k] -= factor*m.M[i][k];
		}
		m = gauss_rearrange(m, i, n);
	} //operations for bring the matrix to upper triangular form
	x[n-1] = m.M[n-1][3]/m.M[n-1][n-1];
	for(i=1;i<n;i++)
	{
		x[n-1-i] = m.M[n-1-i][3];
		for(j=n-1; j>n-1-i; j--) x[n-1-i] -= m.M[n-1-i][j]*x[j];
		x[n-1-i] /= m.M[n-1-i][n-1-i];
	}
	for(i=0;i<n;i++) printf("\nx%d=%lf", i+1, x[i]);
}

void gauss_pivot(matrix m, int n)
{
	int i, j, k;
	double factor, x[n];
	for(i=0; i<n; i++)
	{
		for(j=n-1; j>=0; j--)//similar algorithm as that of Gauss method, but converts to a diagonal matrix
		{
			if(j == i) continue;
			factor = (m.M[j][i]/m.M[i][i]);
			for(k=0; k<4; k++) m.M[j][k] -= factor*m.M[i][k];
		}
		m = gauss_rearrange(m, i, n);
	} //operations for bring the matrix to diagonal form
	x[n-1] = m.M[n-1][3]/m.M[n-1][n-1];
	for(i=0;i<n;i++)
	{
		for(j=n; j>=0; j--) m.M[i][j] /= m.M[i][i];
		x[i] = m.M[i][n];
	} //assigning solutions
	for(i=0;i<n;i++) printf("\nx%d=%lf", i+1, x[i]);
}

void jacobi(matrix m, int n)
{
	int i, j, iter, n_i;
	double s, xk[n], xk1[n];
	m = jacobi_rearrange(m, n); //rearranging to a diagonally dominant matrix when needed
	printf("Enter number of iterations to be carried out: ");
	scanf("%d", &n_i);
	for(i=0;i<n;i++)
	{
		printf("Enter initial assumed value of x%d: ", i+1);
		scanf("%lf", &xk[i]);
	}
	for(iter=1; iter<=n_i; iter++)
	{
		for(i=0; i<n; i++)
		{
			s = 0;
			for(j=0; j<n; j++) if(i!=j) s += m.M[i][j]*xk[j];
			xk1[i] = (m.M[i][3] - s)/m.M[i][i];
		}
		for(i=0; i<n; i++) xk[i] = xk1[i];
	}
	for(i=0; i<n; i++) printf("x%d=%lf\n", i+1, xk[i]);
}

//to ensure that no principal diagonal element remains 0 in Gauss methods
matrix gauss_rearrange(matrix m, int i, int n)
{
	int j, k, l;
	double temp;
	for(j=i+1; j<=n-1-i; j++)
	{
		if(m.M[j][j]==0)
		{
			for(k=j+1;k<3;k++)
			{
				if(m.M[j][k]!=0)
				{
					for(l=0;l<4;l++)
					{
						temp = m.M[k][l];
						m.M[k][l] = m.M[j][l];
						m.M[j][l] = temp;
					}
					break;
				}
			}
		}
	}
	return m;
}

matrix jacobi_rearrange(matrix m, int n)
{
	int i, j, ind;
	double temp, maxm;
	for(i=0; i<n; i++)
	{
		ind = i;
		for(j=0; j<n; j++)
		{
			if(fabs(m.M[i][j]) > fabs(m.M[i][i])) //not using real condition for diagonally dominant matrices as no given system satisfies them wholly
			{
				maxm = m.M[i][j];
				ind = j;
			}
		}
		if(i!=ind)
		{
			for(j=0;j<n+1;j++)
			{
				temp = m.M[i][j];
				m.M[i][j] = m.M[ind][j];
				m.M[ind][j] = temp;
			}
		}
	}
	return m;
}
