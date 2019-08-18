#include "hComplex.h"

int main()
{
    tComplex_c c1,c2,c3,c4;
    c1.dReal = 5;
    c1.dImag = 6;
    c2.dReal = 5;
    c2.dImag = -6;
    //c3.dReal = 4;
    //c3.dImag = -7;

    c3 = tAdd(c1,c2);
    print_c(c3);
    printf("\n\n");

    c4 = tSub(c1,c2);
    print_c(c4);
    printf("\n\n");


    print_c(c1);
    printf("\n\n");

    c1.dReal = 5;
    c1.dImag = -6;
    print_c(c1);
    printf("\n\n");

    c1.dReal = 5;
    c1.dImag = 0;
    print_c(c1);
    printf("\n\n");

    return 0;
}
