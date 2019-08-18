/*--------------------------------------------------------------------
Name: Erich Kroneberger
NAU id: evk3
Date: November 10, 2011
----------------------------------------------------------------------*/
#include "tMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

tMatrix GaussJordan(tMatrix);

int main()
{
    tMatrix A,b;
    int n;

    printf("Enter number of variables: ");
    scanf("%d",&n);

	A.rows = n; A.cols = n;
	b.rows = n; b.cols = 1;
	A = allocate(A); b = allocate(b);

    printf("\nenter the linear coffecients of the equations:\n");
    	read_mat(A);
    printf("\nEnter the right hand coeffecients:\n");
    	read_mat(b);

    printf("\n\nA is :\n");
    	print_mat(A);
    printf("\n\nb is :\n");
    	print_mat(b);

    printf("\n\nAugmented Matrix:\n");
    	print_mat(augment(A,b));
    	tMatrix x;
    	x = augment(A,b);

    printf("\n\nResults from Gauss-Jordan Elimination: \n");
    print_mat(GaussJordan(x));

    return 0;
}

tMatrix GaussJordan(tMatrix A)
{
    tMatrix x;
    int i = 0, j= 0;
    double temp;

    x.rows = A.rows; x.cols = 1;
    x = allocate(x);

    for(j=0; j<A.rows; j++)
    {
        i = j;
        while(A.data[i][j] == 0)

        {

            if(i<A.rows-1)
                i++;
            else if (i == A.rows-1)
		break;

        }

	if(A.data[i][j]==0)
        	break;

	A = swaprow(A,j,i);
	temp = 1/A.data[j][j];
        A = multrow(A,j,temp);

	for (i = j+1; i < A.rows; i++)
		A = subrow(A,i,j,A.data[i][j]);
}


for(j=0; j<A.rows-1; j++)
	for(i=j+1; i<(A.cols-1);i++)
        	A = subrow(A,j,i,A.data[j][i]);

for(i = 0; i < x.rows;i++)
	x.data[i][0] = A.data[i][A.rows];

return A;


}
