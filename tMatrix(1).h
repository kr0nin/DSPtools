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

/*Augment*/
tMatrix augment(tMatrix,tMatrix);

/*elementary row operations*/
/* r <- r*d */
tMatrix multrow(tMatrix m,int r,double d);
/* r1 <- r1 + r2*d */
tMatrix addrow(tMatrix m,int r1,int r2,double d);
/*r1 <- r1 - r2*d */
tMatrix subrow(tMatrix m,int r1,int r2,double d);
/* r1 <-> r2*/
tMatrix swaprow(tMatrix m,int r1,int r2);


/*function definitions*/
tMatrix allocate(tMatrix m){
    double **p;
    int i;
    p = (double**) malloc(sizeof(double*) * m.rows);
    for(i = 0; i < m.rows; i++){
        *(p+i) = (double*) malloc(sizeof(double)*m.cols);
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









#endif // TMATRIX_H_INCLUDED
