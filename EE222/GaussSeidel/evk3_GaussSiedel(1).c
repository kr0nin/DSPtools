/*---------------------------------------------------------------------
Gauss-Seidel Elimination
-----------------------------------------------------------------------
Erich Kroneberger
evk3@nau.edu
November 10, 2011
---------------------------------------------------------------------*/
#include "tMatrix.h"

tMatrix GaussSeidel(tMatrix, tMatrix);
int max;

int main()
{
    tMatrix A,b,x0;
    int n;

    printf("Enter number of variables: ");
    scanf("%d",&n);
    printf("\nenter number of iterations: ");
    scanf("%d",&max);

    A.rows = n; A.cols = n;
    b.rows = n; b.cols = 1;
    x0.rows = n; x0.cols = 1;
    A = allocate(A); b = allocate(b); x0 = allocate (x0);

    printf("\nenter the linear coffecients of the equations:\n");
    read_mat(A);
    printf("\nEnter the right hand coeffecients:\n");
    read_mat(b);
    printf("\nEnter the initial estimate:\n");
    read_mat(x0);

    printf("\n\nA is :\n");
    print_mat(A);
    printf("\n\nb is :\n");
    print_mat(b);
    printf("\n\nx is :\n");
    print_mat(x0);
    printf("\n\n Results from Gauss Seidel: ");
    print_mat(GaussSeidel(augment(A,b)),x0);

    return 0;
}

tMatrix GaussSeidel(tMatrix Ab, tMatrix x0){
    tMatrix oldE, newE, newM, oldM, tempM, tempE;
    int n = Ab.rows;
    int c = 0, i = 0, j = 0, k = 0;
    double temp;

	//estimation matrix
	oldE.rows = x0.rows; oldE.cols = x0.cols; oldE = x0;
	newE.rows = x0.rows; newE.cols = x0.cols;
	newE = allocate(newE);

	//solution matrix
	newM.rows = Ab.rows; newM.cols = Ab.cols;
	newM = allocate(newM);
	oldM.rows = Ab.rows; oldM.cols = Ab.cols;
	oldM = Ab;

	//setup variables
    for()
	newE = multiply(oldE,oldM);

    for(c = 0; c < max-1; c++){
	for(j = 0; j < n; j++){
		next.data[i][j] = b -;
	}

	for(k = j-1; k = 0; k++){

	}
	if()
	else()
    }

    printf("\n\nNo solution obtained after %d iterations.",max);
    exit(1);

}
    return newE;
}
