#include "tMatrix.h"

tMatrix_zc Unity(int);
tMatrix_zp DFT(tMatrix_zc, tMatrix_zc);

int main()
{
    tMatrix_zc A; //int v; //not sure if necessary
    A.rows = 4; A.cols = 1;
    A = allocate_zc(A);
    tMatrix_zc rtofU; tMatrix_zp XofK;
    printf("\nenter the values for the 4x1 matrix:\n");
    read_mat_zc(A);
    int n;

/*
    printf("Enter number of variables in time domain: ");
    scanf("%d",&v);
    A.rows = v; A.cols = v;
    A = allocate(A);
    printf("\nenter the linear coffecients of the equations:\n");
    read_mat(A);
*/

    printf("Enter the number of samples: ");
    scanf("%d",&n);
    printf("\n");
    rtofU = Unity(n);
    //print_mat_zc(rtofU);
    XofK = DFT(A,rtofU);
    print_mat_zp(XofK);

    return 0;
}

tMatrix_zc Unity(int n){
    tMatrix_zc Zu;
    int k;
    tComplex_p z;
    Zu.rows = n; Zu.cols = 1;
    Zu = allocate_zc(Zu);

    for (k = 0; k < n; k++){
        z.dMag = 1;
        z.dAng = 2*PI*k/n;
        Zu.data[k][0] = tConvert_pc(z);
    }
    return Zu;
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
    for (t=0; t<unitmat.cols - 1; t++){
        twimat.data[t][1] = tConvert_cp(unitmat.data[t][1]);
    }

    //cart to polar for orgmat
    for (g=0; g<unitmat.cols - 1; g++){
        pogmat.data[g][1] = tConvert_cp(orgmat.data[g][1]);
    }

    //actual DFT
    for (k = 0; k < orgmat.cols - 1; k++){
        for (n = 0; n < orgmat.cols - 1; n++){
            tempsum = tConvert_cp(tAdd(tConvert_pc(tempsum),tMultiply(orgmat.data[n][1],tConvert_pc(tComplexPower(twimat.data[k][1],n*k)))));
        }
    dftmat.data[k][1] = tempsum;
    }
    print_mat_zp(dftmat);
return dftmat;

}
