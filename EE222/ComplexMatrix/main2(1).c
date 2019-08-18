//#include <math.h>
#include "tMatrix.h"
//#define PI = 3.1415

tMatrix_zc Unity(int);

int main()
{
    tMatrix_zc unity_roots;
    int n;

    printf("Enter the number of roots desired : ");
    scanf("%d",&n);
    printf("\n");

    unity_roots = Unity(n);
    print_mat_zc(unity_roots);
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
