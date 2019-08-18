#ifndef TMATRIX_H_INCLUDED
#define TMATRIX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*structure definition*/
typedef struct {
    double **data;
    int rows;
    int cols;
} tMatrix;

/*prototype*/
tMatrix allocate(tMatrix);
void read_mat(tMatrix);
void print_mat(tMatrix);
void tfree(tMatrix);
tMatrix multiply(tMatrix,tMatrix);
tMatrix addition(tMatrix,tMatrix);
tMatrix subtraction(tMatrix,tMatrix);

/*Augment*/
tMatrix augment(tMatrix,tMatrix);
/*elementary row operations*/
/* r <- r*d */
tMatrix multrow(tMatrix,int ,double );
/* r1 <- r1 + r2*d */
tMatrix addrow(tMatrix, int, int, double );
/*r1 <- r1 - r2*d */
tMatrix subrow(tMatrix,int,int,double);
/* r1 <-> r2*/
tMatrix swaprow(tMatrix,int,int);


/*function definitions*/
tMatrix allocate(tMatrix m){
    double **p;
    int i;
    p = (double**) calloc(sizeof(double*),m.rows);
    for(i = 0; i < m.rows; i++){
        *(p+i) = (double*) calloc(sizeof(double),m.cols);
    }

    m.data = p;
    return m;
}

void read_mat(tMatrix m){
    int i,j;
    for (i = 0; i < m.rows; i++){
        for (j = 0; j < m.cols; j++){
            scanf("%lf",&m.data[i][j]);
        }
    }
}

void print_mat(tMatrix m){
    int i,j;
    for (i = 0; i < m.rows; i++){
        for (j = 0; j < m.cols; j++){
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
tMatrix addition(tMatrix m1,tMatrix m2){
    tMatrix m3;
    int i,j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols)){
        printf("Error! Invalid Dimensions!");
        exit(1);
    }
    m3.rows = m1.rows; m3.cols = m1.cols;
    m3 = allocate(m3);
    for(i=0; i<m1.rows; i++){
        for(j = 0; j < m1.cols; j++){
            m3.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }
    return m3;
}

tMatrix subtraction(tMatrix m1,tMatrix m2){
    tMatrix m3;
    int i,j;
    if ((m1.rows != m2.rows) || (m1.cols != m2.cols)){
        printf("Error! Invalid Dimensions!");
        exit(1);
    }
    m3.rows = m1.rows; m3.cols = m1.cols;
    m3 = allocate(m3);
    for(i=0; i<m1.rows; i++){
        for(j = 0; j < m1.cols; j++){
            m3.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    }
    return m3;
}
tMatrix multiply(tMatrix m1,tMatrix m2){
    tMatrix m3;
    int r,c,p;
    if (m1.cols != m2.rows){
        printf("ERROR! ERROR! ERROR!");
        return m3;
    }
    else{
        m3.rows = m1.rows;
        m3.cols = m2.cols;
        m3 = allocate(m3);
        for (r = 0; r < m3.rows; r++){
            for (c = 0; c < m3.cols; c++){
                m3.data[r][c]=0;
                for (p = 0; p < m1.cols; p++)
                    m3.data[r][c] += m1.data[r][p]*m2.data[p][c];
            }
        }

    }
    return m3;
}

tMatrix augment(tMatrix A,tMatrix b){
    int i,j;
    tMatrix AugA;
    if(A.rows != b.rows){
        printf("ERROR\n\n");
        exit(1);
    }

    AugA.rows = A.rows;
    AugA.cols = A.cols + b.cols;
    AugA = allocate(AugA);

    for(i = 0; i < A.rows; i++){
        for(j = 0; j < A.cols; j++){
            AugA.data[i][j] = A.data[i][j];
        }
    }
    for(i = 0; i < b.rows; i++){
        for(j = A.cols; j < A.cols+b.cols; j++){
            AugA.data[i][j] = b.data[i][j-A.cols];
        }
    }
    return AugA;
}

tMatrix addrow(tMatrix m,int n1,int n2,double p){
    int i;

    for(i = 0; i < m.cols; i++){
        m.data[n1][i] += p*m.data[n2][i];
    }
    return m;
}

tMatrix subrow(tMatrix m,int n1,int n2,double p){
    int i;

    for(i = 0; i < m.cols; i++){
        m.data[n1][i] -= p*m.data[n2][i];
    }
    return m;

}

tMatrix swaprow(tMatrix m,int n1,int n2){
    double *temp;
    temp = m.data[n1];
    m.data[n1] = m.data[n2];
    m.data[n2] = temp;

    return m;

}

tMatrix multrow(tMatrix m,int r,double d){
    int i;
    for (i = 0; i<m.cols; i++){
        m.data[r][i] *= d;
    }

    return m;

}



#endif // TMATRIX_H_INCLUDED
