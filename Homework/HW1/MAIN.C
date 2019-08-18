#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

int nSide1;
int nSide2;
float nHype;

printf("\nEnter side 1: ");
scanf("%d", &nSide1);
//nSide1 = 3;

printf("\nEnter side 2: ");
scanf("%d", &nSide2);
//nSide2 = 4;

nHype = nSide1*nSide1+nSide2*nSide2;

printf("\nThe Hypotenuse is = %f\n", sqrt(nHype));

return 0;
}
