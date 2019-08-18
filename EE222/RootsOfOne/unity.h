/*

roots of unity

tMatrix_zc Unity(int n)
input : n
    1) declare a complex matrix of dimension 1Xn (Zu)
    2) for i=0,i<n,i++
        z(polar form)
        zp.mag = 1
        zp.ang = (2pik/n)
        zu.data[0][k] = Convert_pc(2p)

    note**  1 = e^(j2pi)
            1^(1/n) = e^(j(2pi/n)*k), k=0.....n-1

    3) return zu(output)
        zu :tMatrix_zc
        zp :tComplex_p

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tMatrix.h"
#define pi = 3.14159

int n;
tMatrix_zc RootsOfUnity(int n);

int main(){
    tMatrix unity_roots;
    int n;

    printf("Enter the number of roots desired : ");
    scanf("%d",&n);
    printf("\n");

    unity_roots = Unity(n);

    return (0)

}

tMatrix_zc RootsOfUnity(n){
    tMatrix_zc Zu;
    int k;
    tComplex_p z;

    Zu.rows = n; Zu.cols = 1;
    Zu = allocate_zc(Zu);

    for (k = 0, k<n, k++){
        z.dMag = 1;
        z.dAng = 2*pi*k/n;
        Zu.data[k][0] = tConvert_pc(z)
    }

    return (zu);
}
