#ifndef TMATRIX_H_INCLUDED
#define TMATRIX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structude definition
    typedef struct{
    double **data;
    int rows;
    int cols;
} tMatrix;

//Protototype actual functions that print shit
tMatrix allocate(tMatrix);
void read_mat(tMatrix);
void print_mat(tMatrix);
void tfree(tMatrix);
tMatrix add_mat(tMatrix, tMatrix);
tMatrix sub_mat(tMatrix, tMatrix);
tMatrix product_mat(tMatrix, tMatrix);
//tMatrix quotient_mat(tMatrix);

//augment
tMatrix augment(tMatrix,tMatrix);

//elementry row operations
tMatrix multrow(tMatrix,int,double);
tMatrix addrow(tMatrix,int,int,double);
tMatrix subrow(tMatrix,int,int,double);
tMatrix swaprow(tMatrix,int,int);

//function definitions

tMatrix augment(tMatrix A,tMatrix b){
    //insert sanity check here
    int i,j;
    tMatrix AugA; AugA.cols = A.cols + b.cols; AugA.rows = A.rows;
    AugA = allocate(AugA);
    for (i = 0; i < A.rows; i++){
        for (j = 0; j < A.cols; j++){
            AugA.data[i][j] = A.data[i][j];
        }
    }
    for (i = 0; i < b.rows; i++){
        for (j = A.cols; j < A.cols + b.cols; j++){
            AugA.data[i][j] = b.data[i][j - A.cols];
        }
    }
}

tMatrix addrow(tMatrix m, int n1, int n2, double p){
    int i;

    for(i = 0; i < m.cols; i++){
        m.data[n1][i] += p*m.data[n2][i];
    }
return m;
}

tMatrix add_mat(tMatrix m, tMatrix n){
    if (m.rows != n.rows){
    printf("Error, Matrix size mismatch\n");
    }
    else if (m.cols != n.cols){
    printf("Error, Matrix size mismatch\n");
    }
    else
    {
    int i,j;
    tMatrix c; c.cols = m.cols; c.rows = m.rows;
    c = allocate(c);

        for (i = 0; i < m.rows; i++){
            for(j = 0; j < m.cols; j++){
                c.data[i][j] = m.data[i][j] + n.data[i][j];
        }

    }
return c;
}
}

tMatrix product_mat(tMatrix m1, tMatrix m2){
    tMatrix m3;
    int r,c,p;
    /*
    if (m1.rows != m2.rows){
    printf("Error, Matrix size mismatch\n");
    return m3;
    }
    else if (m1.cols != n.cols){
    printf("Error, Matrix size mismatch\n");
    return m3;
    }
    else
    {
    */
        m3.rows = m1.rows;
        m3.cols = m2.cols;
        m3 = allocate(m3);
        for (r = 0; r < m1.rows; r++){
            for (c = 0; c < m3.cols; c++){
                m3.data[r][c] = 0;
                for (p = 0; p < m1.cols; p++){
                    m3.data[r][c] += m1.data[r][p]*m2.data[p][c];
                }
            }
        }

    //}
return m3;
}

tMatrix sub_mat(tMatrix m, tMatrix n){
    if (m.rows != n.rows){
    printf("Error, Matrix size mismatch\n");
    }
    else if (m.cols != n.cols){
    printf("Error, Matrix size mismatch\n");
    }
    else
    {
    int i,j;
    tMatrix c; c.cols = m.cols; c.rows = m.rows;
    c = allocate(c);

        for (i = 0; i < m.rows; i++){
            for(j = 0; j < m.cols; j++){
                c.data[i][j] = m.data[i][j] - n.data[i][j];
        }

    }
return c;
}
}

tMatrix allocate (tMatrix m){

    double **p; //temporary var
    int i;
    p = (double**) malloc(sizeof(double*) * m.rows);

    for(i = 0; i < m.rows; i++){
        *(p+i) = (double*) malloc(sizeof(double)* m.cols);
    }

    m.data = p;
    return m;
}

void read_mat(tMatrix m){
    int i,j;
    for (i = 0; i < m.rows; i++){
        for(j = 0; j < m.cols; j++){
            scanf("%lf",&m.data[i][j]);
        }
    }
}

void print_mat(tMatrix m){
    int i,j;
    for (i = 0; i < m.rows; i++){
        for(j = 0; j < m.cols; j++){
            printf("%lf\t",m.data[i][j]);
        }
        printf("\n");
    }
}

void tfree(tMatrix m){
    int i;
    for (i = 0; i<m.cols; i++)
        free(m.data[i]);
    free(m.data);
}

#endif // TMATRIX_H_INCLUDED
