#include "tMatrix.h"

//tMatrix_zc Unity(int);

int main()
{
    tMatrix_zc Zc;
    Zc.rows = 2; Zc.cols = 2;
    Zc = allocate_zc(Zc);
    printf("\n\nreading values of Zc\n\n");
    read_mat_zc(Zc);
    printf("\n\nZc is : \n\n");
    print_mat_zc(Zc);
    return 0;
}
