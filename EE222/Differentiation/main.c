//EK 09/29/11 Erich Kroneberger -- attempt of a differentiation example program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
//global variables
int dI;
int dMaxit;
int dTol;
double lXinit;
*/

//prototype
double f(double);
double df(double);

int main()
{
    double x0 = 0, i,y0,dy0,xi,xi1,yi,yi1,dyi,dyi1;

    FILE *cfPtr;
    if((cfPtr = fopen("results.csv","w")) == NULL)
        printf("ERROR!!!\n");
    else{

    y0 = f(x0);
    dy0 = df(x0);

    xi = x0;
    yi = y0;
    dyi = dy0;

    for (i=0; i < 10; i++)
        {
            fprintf(cfPtr,"%d%.4f%.4f\n",i,xi,yi,dyi);
            xi1 = xi -yi/dyi;
            yi1 = f(xi1);
            if (abs(yi1)<=0)
                break;
            dyi1 = df(xi1);
            xi = xi1;
            yi = yi1;
            dyi = dyi1;
        }
    }
        fclose(cfPtr);
    return 0;
}

double f(double x)
{
    return (pow(x,2)+3*x+2);
    //((lXinit)(lXinit))+(3(lXinit))+2;
}

double df(double x)
{
    return (2*x+3);
}
