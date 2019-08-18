#include "tMatrix.h"

tMatrix_zc Unity(int);
tMatrix_zp DFT(tMatrix_zc, int);

int main()
{
    tMatrix_zc A;
    A.rows = 1; A.cols = 4;
    A = allocate_zc(A);

    tMatrix_zc rtofU; tMatrix_zp XofK;

    printf("\nenter the values for the 4x1 matrix:\n");
    read_mat_zc(A);
    int n;

    printf("Enter the number of samples: ");
    scanf("%d",&n);
    printf("\n");
    rtofU = Unity(n);

    XofK = DFT(A,rtofU);
    print_mat_zp(XofK);

    return 0;
}

tMatrix_zc DFT(tMatrix_zc ORG,int n){
    tMatrix_zp DFT;
    tMatrix_zc Zu; //roots of unity of n
    int r,n,k,t; //roots counter
    tComplex_p z;

    tComplex_p tempsum;
    tempsum.dMag = 0;
    tempsum.dAng = 0;

    Zu.rows = 1; Zu.cols = n;
    Zu = allocate_zc(Zu);

    TWIDDLE.cols = ORG.cols;
    TWIDDLE.rows = ORG.rows;
    TWIDDLE = allocate_zp(TWIDDLE);

    for (r = 0; r < n; r++){
        z.dMag = 1;
        z.dAng = 2*PI*r/n;
        Zu.data[r][0] = tConvert_pc(z);
    }

    //cart to polar for twiddle
    for (t=0; t<Zu.cols; t++){
        TWIDDLE.data[t][1] = tConvert_cp(Zu.data[t][1]);
    }

    //actual DFT
    for (k = 0; k < ORG.cols; k++){
        for (n = 0; n < ORG.cols; n++){
            tempsum = tConvert_cp(tAdd(tConvert_pc(tempsum),tMultiply(ORG.data[n][1],tConvert_pc(tComplexPower((TWIDDLE.data[k][1]),n)))));
        }
    DFT.data[k][1] = tempsum;
    }
return DFT;
}

tMatrix_zp DFT(tMatrix_zc orgmat, tMatrix_zc unitmat){
    tMatrix_zp dftmat,twimat,pogmat;
    dftmat.cols = orgmat.cols; twimat.cols = orgmat.cols; pogmat.cols = orgmat.cols;
    dftmat.rows = orgmat.rows; twimat.rows = orgmat.rows; pogmat.rows = orgmat.rows;
    dftmat = allocate_zp(dftmat);
    twimat = allocate_zp(twimat);
    int n,g,t,k = 0;
    tComplex_p tempsum;
    tempsum.dMag = 0;
    tempsum.dAng = 0;

    //cart to polar for twiddle
    for (t=0; t<unitmat.cols; t++){
        twimat.data[t][1] = tConvert_cp(unitmat.data[t][1]);
    }

    //cart to polar for orgmat
    for (g=0; g<unitmat.cols; g++){
        pogmat.data[g][1] = tConvert_cp(orgmat.data[g][1]);
    }

    //actual DFT
    for (k = 0; k < orgmat.cols - 1; k++){
        for (n = 0; n < orgmat.cols - 1; n++){
            tempsum = tConvert_cp(tAdd(tConvert_pc(tempsum),tMultiply(orgmat.data[n][1],tConvert_pc(tComplexPower(twimat.data[k][1],n*k)))));
        }
    dftmat.data[k][1] = tempsum;
    }
    //print_mat_zp(dftmat);
return dftmat;

}

