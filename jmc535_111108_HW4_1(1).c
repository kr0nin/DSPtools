/*--------------------------------------------------------------------
Name: Justin Cummings
NAU id: jmc535
Date: November 08, 2011
Name of Program: jmc535_111108_HW4_1.c
Assigment and Problem number:
I herby declare that I have not helpped, or received or solicited help
from
any unauthorized material or individual for this homework.
Initials: JMC
----------------------------------------------------------------------*/
#include "tMatrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

tMatrix GaussJordanElimination(tMatrix);
int main()
{
    tMatrix A,b;
    int n;

    printf("Enter number of variables: ");
    scanf("%d",&n);

    A.rows = n; A.cols = n;
    b.rows = n; b.cols = 1;

    A = allocate(A);
    b = allocate(b);

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
    printf("\n\nResults from Gauss Elimination:\n");
    print_mat(GaussJordanElimination(x));

    return 0;
}

tMatrix GaussJordanElimination(tMatrix A)
{
    tMatrix x;
    int i = 0, j= 0;
    double temp;

    x.rows = A.rows;
    x.cols = 1;
    x = allocate(x);

    for(j=0; j<A.rows; j++)
    {
        //printf("\nI = %d\n",j);
        //printf("Original Matrix:\n");
        //print_mat(A);

        i = j;
        while(A.data[i][j] == 0)
        {
            if(i<A.rows-1)
                i++;
            else if (i == A.rows-1)
            {
             break;
            }

        }
        if(A.data[i][j]==0)
            break;
        A = swaprow(A,j,i);

        temp = 1/A.data[j][j];
        A = multrow(A,j,temp);

        for (i = j+1; i < A.rows; i++)
        {
            A = subrow(A,i,j,A.data[i][j]);
        }
        //printf("\nModified Matrix:\n");
        //print_mat(A);
    }
for(j=0; j<A.rows-1; j++)
    {
        //printf("\nJ = %d\n",j);
        //printf("Original Matrix 2:\n");
        //print_mat(A);

        for(i=j+1; i<(A.cols-1);i++)
        {
         //printf("I = %d, J = %d\n", i, j);
         A = subrow(A,j,i,A.data[j][i]);
         //printf("Modified Matrix 2:\n");
         //print_mat(A);
        }
    }
for(i = 0; i < x.rows;i++)
 {
  x.data[i][0] = A.data[i][A.rows];
 }
 return (augment(A,x));
}


/* old from just gauss eliminiation
//reverse substitution
    if(A.data[A.rows-1][A.rows-1] == 0)
    {
        printf("no unique solution\n");
        exit(1);
    }
    else
    {
     x.data[A.rows-1][0] = A.data[A.rows-1][A.rows]/A.data[A.rows-1][A.rows-1];
     for (i=A.rows-2; i>=0; --i)
     {
         x.data[i][0]=A.data[i][A.rows]/A.data[i][i];

         for(j=i+1; j<A.rows; j++)
         {
             x.data[i][0] -= (A.data[i][j]*x.data[j][0])/A.data[i][i];
         }
     }

    return x;
    }
*/
