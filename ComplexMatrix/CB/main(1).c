#include "tMatrix.h"

tMatrix_zp DFT(tMatrix_zc, int);

int main()
{
    tMatrix_zc A;
    A.rows = 4; A.cols = 1;
    A = allocate_zc(A);
    int n,m;
    tMatrix_zp ORG;

    printf("\nenter the values for the 4x1 matrix:\n");
    read_mat_zc(A);

    printf("Enter the number of samples: ");
    scanf("%d",&n);
    printf("\n");

/////////////////
print_mat_zc(A);
printf("\n");
//print_mat_zc(Zu);
//printf("\n");
//system("pause");
/////////////////

    ORG = DFT(A,n);

    //for (m=o;m<ORG.rows;m++){
    //    if (ORG.data[m][])
    //
    //}

    print_mat_zp(ORG);

    return 0;
}

tMatrix_zp DFT(tMatrix_zc ORG,int u){
    int r,n,k,t;    // counters
    tMatrix_zp DFT; //final matrix
    tMatrix_zc Zu;  //roots of unity of n
    tComplex_p z;   //data inside Zu (unity roots in Matrix)

    Zu.rows = u; Zu.cols = 1;
    Zu = allocate_zc(Zu);

    tMatrix_zp TWIDDLE;
    TWIDDLE.cols = ORG.cols;
    TWIDDLE.rows = ORG.rows;
    TWIDDLE = allocate_zp(TWIDDLE);

    //n roots unity
    for (r = 0; r < u; r++){
        z.dMag = 1;
        z.dAng = 2*PI*r/u;
        Zu.data[r][0] = tConvert_pc(z);
    }

    //cart to polar for twiddle
    for (t=0; t<Zu.rows; t++){
        TWIDDLE.data[t][0] = tConvert_cp(Zu.data[t][0]);
    }

//ZERO OUT DFTMATRIX HERE

    DFT.rows = 4;DFT.cols = 1;
    DFT = allocate_zp(DFT);
    //for (d = 0; d < ; d++){
    //    DFT.data[d][0] = 0;
    //}

///////////////////////////////////////////////
//print_mat_zp(DFT);
//printf("\n");
printf("Roots of unity");
print_mat_zc(Zu);
printf("\n");
printf("Twiddle factor:");
print_mat_zp(TWIDDLE);
printf("\n");
printf("empty DFT");
print_mat_zp(DFT);
printf("\n");
//system("pause");
///////////////////////////////////////////////

    //actual DFT
    for (k = 0; k < 4; k++){
        for (n = 0; n < 4; n++){
            DFT.data[k][0] = tConvert_cp(tAdd(tConvert_pc(DFT.data[k][0]),tMultiply(ORG.data[n][0],tConvert_pc(tComplexPower((TWIDDLE.data[k][0]),n)))));
        }
    //DFT.data[k][0] = tempsum;
    }
return DFT;
}
