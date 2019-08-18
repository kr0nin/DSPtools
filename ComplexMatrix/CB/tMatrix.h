#ifndef TMATRIX_H_INCLUDED
#define TMATRIX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hComplex.h"

/*structure definition*/
typedef struct {
    double **data;
    int rows;
    int cols;
} tMatrix;

typedef struct {
    tComplex_p **data;
    int rows;
    int cols;
} tMatrix_zp;

typedef struct {
    tComplex_c **data;
    int rows;
    int cols;
} tMatrix_zc;

//normal matrix operations
tMatrix allocate(tMatrix);
void read_mat(tMatrix);
void print_mat(tMatrix);
void tfree(tMatrix);
tMatrix multiply(tMatrix,tMatrix);
tMatrix addition(tMatrix,tMatrix);
tMatrix subtraction(tMatrix,tMatrix);

//complex cartesian operations
tMatrix_zc allocate_zc(tMatrix_zc);
void read_mat_zc(tMatrix_zc);
void print_mat_zc(tMatrix_zc);
void tfree_zc(tMatrix_zc);

//complex polar operations
tMatrix_zp allocate_zp(tMatrix_zp);
void read_mat_zp(tMatrix_zp);
void print_mat_zp(tMatrix_zp);
void tfree_zp(tMatrix_zp);

//conversion
tMatrix_zc tMatCon_pc(tMatrix_zp);
tMatrix_zp tMatCon_cp(tMatrix_zc);

/*elementary row operations*/
tMatrix multrow(tMatrix,int ,double ); //r <- r*d
tMatrix addrow(tMatrix, int, int, double ); //r1 <- r1 + r2*d
tMatrix subrow(tMatrix,int,int,double); //r1 <- r1 - r2*d
tMatrix swaprow(tMatrix,int,int); //r1 <-> r2
tMatrix extract_row(tMatrix,int);
tMatrix augment(tMatrix,tMatrix); //Augment

/*Gauss Algorithms*/
tMatrix GaussElimination(tMatrix);
tMatrix GaussSiedel_LU(tMatrix,tMatrix,tMatrix,int,float);


/////////////////////////////////////////////////////////////////////////////////////////////
/*function definitions*/

tMatrix_zc tMatCon_pc(tMatrix_zp zp){
    int t;
    tMatrix_zc zc;
    zc.rows = zp.rows; zc.cols = zp.cols;
    zc = allocate_zc(zc);

    for (t=0; t<zp.cols-1; t++){
        zc.data[t][1] = tConvert_pc(zp.data[t][1]);
    }
return zc;
}

tMatrix_zp tMatCon_zp(tMatrix_zc zc){
    int t;
    tMatrix_zp zp;
    zp.rows = zc.rows; zp.cols = zc.cols;
    zp = allocate_zp(zp);

    for (t=0; t<zc.cols-1; t++){
        zp.data[t][1] = tConvert_cp(zc.data[t][1]);
    }
return zp;
}


tMatrix_zp allocate_zp(tMatrix_zp zp){
    tComplex_p **p;
    int i;
    p = (tComplex_p**) calloc(sizeof(tComplex_p*),zp.rows);
    for(i = 0; i < zp.rows; i++){
        *(p+i) = (tComplex_p*) calloc(sizeof(tComplex_p),zp.cols);
    }

    zp.data = p;
    return zp;
}

void read_mat_zp(tMatrix_zp zp){
    int i,j;
    tComplex_p z;
    for (i = 0; i < zp.rows; i++){
        for (j = 0; j < zp.cols; j++){
            printf("\n(%d,%d) : \nMagnitude :",i,j);
            scanf("%lf",&z.dMag);
            printf("\nAngle :");
            scanf("%lf",&z.dAng);
            zp.data[i][j] = z;
        }
    }
}

void print_mat_zp(tMatrix_zp zp){
    int i,j;
    for (i = 0; i < zp.rows; i++){
        for (j = 0; j < zp.cols; j++){
            print_p(zp.data[i][j]);
            printf ("\t");
        }
        printf("\n");
    }

}
void tfree_zp(tMatrix_zp zp){
    int i;
    for (i = 0; i<zp.cols; i++)
        free(zp.data[i]);
    free(zp.data);
}

///////////////////////////////////////////////////////////////////////

tMatrix_zc allocate_zc(tMatrix_zc zc){
    tComplex_c **p;
    int i;
    p = (tComplex_c**) calloc(sizeof(tComplex_c*),zc.rows);
    for(i = 0; i < zc.rows; i++){
        *(p+i) = (tComplex_c*) calloc(sizeof(tComplex_c),zc.cols);
    }

    zc.data = p;
    return zc;
}

void read_mat_zc(tMatrix_zc zc){
    int i,j;
    tComplex_c z;
    for (i = 0; i < zc.rows; i++){
        for (j = 0; j < zc.cols; j++){
            printf("\n(%d,%d) : \nReal Part :",i,j);
            scanf("%lf",&z.dReal);
            printf("\nImaginary Part :");
            scanf("%lf",&z.dImag);
            zc.data[i][j] = z;
        }
    }
}

void print_mat_zc(tMatrix_zc zc){
    int i,j;
    for (i = 0; i < zc.rows; i++){
        for (j = 0; j < zc.cols; j++){
            print_c(zc.data[i][j]);
            printf ("\t");
        }
        printf("\n");
    }

}
void tfree_zc(tMatrix_zc zc){
    int i;
    for (i = 0; i<zc.cols; i++)
        free(zc.data[i]);
    free(zc.data);
}

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

tMatrix extract_row(tMatrix m,int n){
    tMatrix row_m;
    int i = 0;

    row_m.rows = 1; row_m.cols = m.cols;
    row_m = allocate(row_m);

    for(i = 0; i < m.cols; i++){
        row_m.data[0][i] = m.data[n][i];
    }

    return row_m;

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

tMatrix GaussSiedel_LU(tMatrix A,tMatrix b,tMatrix Xp,int N,float e){

    tMatrix L,U,Xn,temp;
    temp = augment(A,b);
    int i,j = 0;
    float k = 0,l;
    Xn.rows = A.rows; Xn.cols = 1; Xn = allocate(Xn);
    /*Make Main Diagonal as 1*/
    for(i = 0; i< temp.rows; i++){
        j = i;
        while (A.data[i][i] == 0){
            temp = swaprow(temp,i,++j);
        }
        k =1/A.data[i][i];
        temp = multrow(temp,i,k);
    }
    /*get back the new A and b*/
    for (i = 0; i < A.rows; i++){
        for(j = 0; j < A.cols; j++){
            A.data[i][j] = temp.data[i][j];
        }
        b.data[i][0] = temp.data[i][A.cols];
    }

    /*find L and U*/
    L.rows = A.rows; L.cols = A.cols; U.rows = A.rows; U.cols = A.cols;
    L = allocate(L); U = allocate(U);

    for (i = 0; i < A.rows; i++){
        for(j = 0; j < A.cols; j++){
            if (i>j)
                L.data[i][j] = A.data[i][j];
            else if (i<j)
                U.data[i][j] = A.data[i][j];
        }
    }

    /*algorithm using L and U*/
    for (i = 0; i < N; i++){
        for(j = 0; j < A.rows; j++){
            Xn.data[j][0] = (1/A.data[j][j])*(b.data[j][0] - multiply(extract_row(L,j),Xn).data[0][0] - multiply(extract_row(U,j),Xp).data[0][0]);
        }

        k = fabs((Xn.data[0][0] - Xp.data[0][0])/Xn.data[0][0]);
        for(j = 1; j < Xn.rows; j++){
            l = fabs((Xn.data[j][0] - Xp.data[j][0])/Xn.data[j][0]);
            if (l > k)
                k = l;
        }

        if (k < e)
            break;
        for(i = 0; i < Xn.rows; i++){
            Xp.data[i][0] = Xn.data[i][0];
        }
    }
    return Xn;
}

#endif // TMATRIX_H_INCLUDED
