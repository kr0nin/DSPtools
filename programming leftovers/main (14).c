#include <stdio.h>
#include <stdlib.h>
#include "tMatrix.h"

int main()
{
    tMatrix A,b,c;
    int i,n;

    printf("Enter number of variables: ");
    scanf("%d",&n);

    A.rows = n; A.cols = n; b.rows = n; b.cols = n;

    A = allocate(A); b = allocate(b);

    printf("Enter the linear coefficents of the equations:\n");
    read_mat(A);
    printf("\nEnter the right hand coefficents:\n");
    read_mat(b);
    printf("\n\nA is :\n");
    print_mat(A);
    printf("\n\nb is :\n");
    print_mat(b);

    c = add_mat(A,b);
    printf("\n\nc is :\n");
    print_mat(c);



    return 0;
}
