#include "tMatrix.h"

tMatrix_zp DFT(tMatrix_zc, int);

int main()
{
    tMatrix_zc A;
    A.rows = 1; A.cols = 4;
    A = allocate_zc(A);
    int n;
    tMatrix_zp ORG;

    printf("\nenter the values for the 4x1 matrix:\n");
    read_mat_zc(A);

    printf("Enter the number of samples: ");
    scanf("%d",&n);
    printf("\n");

    ORG = DFT(A,n);
    print_mat_zp(ORG);

    return 0;
}

tMatrix_zp DFT(tMatrix_zc ORG,int u){
    tMatrix_zp DFT;
    tMatrix_zc Zu; //roots of unity of n
    int r,n,k,t;   //roots counter
    tComplex_p z;

    tComplex_p tempsum;
    tempsum.dMag = 0;
    tempsum.dAng = 0;

    Zu.rows = 1; Zu.cols = u;
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
    for (t=0; t<Zu.cols; t++){
        TWIDDLE.data[t][1] = tConvert_cp(Zu.data[t][1]);
    }

///////////////////////////////////////////////
print_mat_zp(DFT);
printf("\n");
print_mat_zc(Zu);
printf("\n");
system("pause");
///////////////////////////////////////////////

    //actual DFT
    for (k = 0; k < ORG.cols; k++){
        for (n = 0; n < ORG.cols; n++){
            tempsum = tConvert_cp(tAdd(tConvert_pc(tempsum),tMultiply(ORG.data[n][1],tConvert_pc(tComplexPower((TWIDDLE.data[k][1]),n)))));
        }
    DFT.data[k][1] = tempsum;
    }
return DFT;
}
