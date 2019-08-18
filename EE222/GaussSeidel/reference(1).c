#include "tMatrix.h"
tMatrix GaussElimination(tMatrix);
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
    printf("\n\n Results from Gauss Elimination: ");
    print_mat(GaussElimination(augment(A,b)));

    return 0;
}

tMatrix GaussElimination(tMatrix A){
    tMatrix x;
    int n = A.rows;
    int i = 0, j= 0;
    double temp;

    x.rows = A.rows; x.cols = 1;
    x = allocate(x);

    for(j=0; j<n; j++){
        i = j;
        while(A.data[i][j] == 0)
            i++;
        A = swaprow(A,j,i);

        temp = 1/A.data[j][j];
        A = multrow(A,j,temp);
        for (i = j+1; i < n; i++){
            A = subrow(A,i,j,A.data[i][j]);
        }
    }

    /*reverse substitution*/
    if(A.data[n-1][n-1] == 0){
        printf("no unique solution");
        exit(1);
    }

    x.data[n-1][0] = A.data[n-1][n]/A.data[n-1][n-1];
    for (i=n-2; i>=0; --i){
        x.data[i][0]=A.data[i][n]/A.data[i][i];
        for(j=i+1; j<n; j++){
            x.data[i][0] -= (A.data[i][j]*x.data[j][0])/A.data[i][i];
        }
    }

    return x;

}
