#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f (double);
//double df (double);

int euler()
{
    int a = 1;
    int b = 2;
    int nMax;
    double tol = 0.00001;
    int i;
    double xi0 = a;
    double xi1 = b;
    double yi0 = f(a);
    double yi1 = f(b);
    double xi2;
    double yi2;

    //double x0 = 0, y0,dy0,xi,xi1,yi,yi1,dyi,dyi1;
    FILE *cfPtr;

    if((cfPtr = fopen("Eresults.csv","w")) == NULL)
        printf("ERROR!!!\n");
    else{

    printf("enter number of steps =\n");
    scanf("%d", &nMax);

    for (i = 0; i <= nMax; i++){

        //y(i+1) = f(x(i+1));
        //x(i+1) = x(i)-y(i)*(x(i)-x(i-1))/y(i);
        xi2 = xi0-yi0*((xi1-xi0)/(yi1-yi0));
        yi2 = f(xi2);
        //yi1 = f(xi1);
        fprintf(cfPtr,"%d,%.4f,%.4f,%.4f,%.4f\n",i,xi0,xi1,yi0,yi1);

        if (fabs(yi2)<tol){
            break;
            }
        else {
            xi0 = xi1;
            xi1 = xi2;
            yi0 = yi1;
            yi1 = yi2;
            }
        }
        }
    fclose(cfPtr);
return 0;
}

double f(double x)
{
//return (pow(x,2)-3);
//return (pow(x,5)-2);
return (pow(x,3)-3*(pow(x,2))+4*(x)+3);
}
/*
double f1(double x)
{
return
}
}
*/

