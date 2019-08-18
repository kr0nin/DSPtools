//
//
//
//
//
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tMatrix.h"

tMatrix GaussJordan(tMatrix);

int main()
{
    tMatrix A,b;
    int n;

    printf("Enter number of variables: ");
    scanf("%d",&n);

    A.rows = n; A.cols = n; b.rows = n; b.cols = 1;
    A = allocate(A); b = allocate(b);

    printf("\nenter the linear coffecients of the equations:\n");
    read_mat(A);
    printf("\nEnter the right hand coeffecients:\n");
    read_mat(b);

    printf("\n\nA is :\n");
    print_mat(A);
    printf("\n\nb is :\n");
    print_mat(b);

//
//
//
//

    printf("\n\n Results from Gauss-Jordan Elimination: \n");
    print_mat(GaussJordan(augment(A,b)));

    return 0;
}

tMatrix GaussJordan(tMatrix A){

    tMatrix x;
    int i = 0, j = 0;
    double temp;

    x.rows = A.rows; x.cols = 1;
    x = allocate(x);

    for(j=0; j<A.rows-1; j++){

        i = j;
        while(A.data[i][j] == 0){
		i++;
		if(i == A.rows - 1)
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

    return (augment(A,x));
}
