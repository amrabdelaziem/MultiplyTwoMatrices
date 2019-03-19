#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int r1, c1, r2, c2,size1,size2;
void enterData(double **m1, double **m2);
void multiplyMatrices(double **m1, double **m2, double **mult);
void display(double **mult, double **m1,double **m2,double *csr1,int *csr2,int *csr3);
int NonezeroCount(double **mult);

int m2m()
{

	int i, j;
	printf("Enter rows and column for first matrix: ");
	scanf("%d %d", &r1, &c1);

	printf("Enter rows and column for second matrix: ");
	scanf("%d %d", &r2, &c2);
	double **m1 = (double **) malloc(r1 * c1 * sizeof(double *));
	for(i=0;i<r1*c1;i++)
		m1[i]= (double *) malloc(c1 * sizeof(double ));
	double **m2 = (double **) malloc(r2 * c2 * sizeof(double *));
	for(i=0;i<r2*c2;i++)
		m2[i]= (double *) malloc(c2 * sizeof(double ));
	double **mult = (double **) malloc(c1 * r2* sizeof(double *));
	for(i=0;i<r1;i++)
		mult[i]= (double *) malloc(c2 * sizeof(double ));



	// If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again.
	// Function to take matrices data
	// if(m1!=NULL && m2!=NULL)
    enterData((double **)m1, (double **)m2);

        // Function to multiply two matrices.
	multiplyMatrices((double **)m1, (double **)m2, (double **)mult);
	size1=NonezeroCount(mult);
	double *ar1 =(double *) malloc(sizeof(double));
	int *ar2 =(int *) malloc(sizeof(int));
	int *ar3 =(int *) malloc(sizeof(int));

	// printf("\n%f\n",NonezeroCount(mult));
        // Function to display resultant matrix after multiplication.
	display((double **)mult,(double **) m1,(double **) m2,(double *) ar1,(int *) ar2,(int *) ar3);
	// NonezeroCount in array
	printf("Number of NoneZeors in First Matrix are: %d\n",NonezeroCount((double **)m1));
	printf("Number of NoneZeors in Second Matrix are: %d\n",NonezeroCount((double **)m2));
	printf("Number of NoneZeors in Output Matrix are: %d\n",NonezeroCount((double **)mult));
	for(i=0;i<r1;i++)
		free(m1[i]);
	for(i=0;i<r2;i++)
		free(m2[i]);
	for(i=0;i<r1;i++)
		free(mult[i]);
	free(ar1);
	free(ar2);
	free(ar3);
	free(m1);
	free(m2);
	free(mult);
	return 0;
}

void enterData(double **m1, double **m2)
{
	int i, j;
    // printf("\nEnter elements of matrix 1:\n");
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c1; j++)
		{
			// printf("Enter elements a%f%f: ", i + 1, j + 1);
			// scanf("%f", &m1[i][j]);
			m1[i][j] = rand() %10 ;
        }
	}

	// printf("\nEnter elements of matrix 2:\n");
	for(i = 0; i < r2; i++)
	{
		for(j = 0; j < c2; j++)
		{
			// printf("Enter elements b%f%f: ", i + 1, j + 1);
			// scanf("%f", &m2[i][j]);
			m2[i][j] = rand() %10;
        }
	}
}

void multiplyMatrices(double **m1, double **m2, double **mult)
{
	int i, j, k;

	// Initializing elements of matrix mult to 0.
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c2; j++)
		{
			mult[i][j] = 0;
		}
	}

	// Multiplying matrix m1 and m2 and storing in array mult.
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c2; j++)
		{
			for(k=0; k<c1; k++)
			{
				mult[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}

int NonezeroCount(double **mult)
{
    int i,j,k,count=0;
    for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c1; j++)
		{
            if(mult[i][j]>0)
            {
                count++;
            }
        }

	}
	return count;
}

void display(double **mult, double **m1,double **m2,double *csr1,int *csr2,int *csr3)
{
    int i, j;
    printf("First Matrix:\n");
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c1; j++)
		{
			printf("%f\t", m1[i][j]);
        }
        printf("\n");
    }
    printf("Second Matrix:\n");
	for(i = 0; i < r2; i++)
	{
		for(j = 0; j < c2; j++)
		{
			printf("%f\t", m2[i][j]);
        }
        printf("\n");
    }
	printf("Output Matrix:\n");
	for(i = 0; i < r1; i++)
	{
		for(j = 0; j < c2; j++)
		{
			printf("%f\t", mult[i][j]);
        }
        printf("\n");
	}
	
 }


int main(int argc, char** argv) {

    int x =m2m();
    return (EXIT_SUCCESS);
}
