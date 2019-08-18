#ifndef HCOMPLEX_H_INCLUDED
#define HCOMPLEX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Structure for cartesian form
typedef struct {
    double dReal,dImag;
} tComplex_c;

//Prototype functions
void print_c(tComplex_c);
tComplex_c tAdd(tComplex_c,tComplex_c);
tComplex_c tSub(tComplex_c,tComplex_c);
tComplex_c tInverse(tComplex_c);
tComplex_c tMultiply(tComplex_c,tComplex_c);
tComplex_c tConvert_c(double);
double tMagnitude(tComplex_c);
double tAngle(tComplex_c);
tComplex_c tConjugate(tComplex_c);

//function definitions
void print_c(tComplex_c c){
    double dR, dI;
    char sign;

    dR = c.dReal; dI = c.dImag;

    printf("(%3.2lf",dR);
    if(fabs(dI) == 0)
        printf(")");
    else if (dI < 0){
        sign = '-';
        printf("%cj%3.2lf)",sign,fabs(dI));
    }
    else if (dI > 0){
        sign = '+';
        printf("%cj%3.2lf)",sign,fabs(dI));
    }
}

tComplex_c tAdd(tComplex_c z1,tComplex_c z2){
    tComplex_c result;

    result.dReal = z1.dReal + z2.dReal;
    result.dImag = z1.dImag + z2.dImag;

    return result;
}

tComplex_c tSub(tComplex_c z1,tComplex_c z2){
    tComplex_c result;

    result.dReal = z1.dReal - z2.dReal;
    result.dImag = z1.dImag - z2.dImag;

    return result;

}

tComplex_c tConjugate(tComplex_c z){

    tComplex_c result;
    result.dImag = -z.dImag;
    result.dReal = z.dReal;

    return result;
}

tComplex_c tMultiply(tComplex_c z1,tComplex_c z2){
    tComplex_c z3;
    z3.dReal = z1.dReal*z2.dReal - z1.dImag*z2.dImag;
    z3.dImag = z1.dReal*z2.dImag + z1.dImag*z2.dReal;

    return z3;
}

tComplex_c tInverse(tComplex_c z){
    tComplex_c zi;

    zi.dReal = z.dReal/pow(tMagnitude(z),2);
    zi.dImag = -z.dImag/pow(tMagnitude(z),2);
    return zi;
}

tComplex_c tConvert_c(double x){
    tComplex_c z;
    z.dReal = x;
    z.dImag = 0;
    return z;
}

double tMagnitude(tComplex_c z){

    return (sqrt(pow(z.dReal,2)+pow(z.dImag,2)));

}
double tAngle(tComplex_c z){

    return atan2(z.dImag,z.dReal);
}


#endif // HCOMPLEX_H_INCLUDED







