#ifndef HCOMPLEX_H_INCLUDED
#define HCOMPLEX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415

typedef struct {
    double dReal,dImag;
} tComplex_c;

typedef struct {
    double dMag,dAng; //angle in radians
} tComplex_p;

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

void print_p(tComplex_p);
tComplex_c tConvert_pc(tComplex_p);
tComplex_p tConvert_cp(tComplex_c);
double tReal(tComplex_p);
double tImag(tComplex_p);

//powers of a complex number
tComplex_p tComplexPower(tComplex_p,int);

//function definitions/////////////////////////////////////////////////
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

void print_p(tComplex_p zp){
    double dM, dA;
    char sign;
    dM = zp.dMag; dA = zp.dAng;
    printf("(%.4lf",dM);
    if(fabs(dA) == 0)
        printf(")");
    else if (dA < 0){
        sign = '-';
        printf(" exp(%cj%.3lf))",sign,fabs(dA)*180/2*PI);
    }
    else if (dA > 0){
        sign = '+';
        printf("exp(%cj%.3lf))",sign,fabs(dA)*180/2*PI);
    }
}

tComplex_c tConvert_pc(tComplex_p zp){
    tComplex_c zc;
    zc.dReal = tReal(zp);
    zc.dImag = tImag(zp);
    return zc;
}

tComplex_p tConvert_cp(tComplex_c zc){
    tComplex_p zp;
    zp.dMag = tMagnitude(zc);
    zp.dAng = tAngle(zc);
    return zp;
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

tComplex_p tComplexPower(tComplex_p pp, int n){
    tComplex_p pd;
    pd.dMag = pow(pp.dMag, n);
    pd.dAng = pp.dAng * n;
    return pd;
}

double tMagnitude(tComplex_c z){
    return (sqrt(pow(z.dReal,2)+pow(z.dImag,2)));
}

double tAngle(tComplex_c z){
    return atan2(z.dImag,z.dReal);
}

double tReal(tComplex_p zp){
    return (zp.dMag*cos(zp.dAng));
}

double tImag(tComplex_p zp){
    return (zp.dMag*sin(zp.dAng));
}

#endif // HCOMPLEX_H_INCLUDED
