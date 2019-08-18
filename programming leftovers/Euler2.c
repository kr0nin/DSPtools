#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMSAMP 49
#define NUM_E  2.71828183

#define INIT_VOLTAGE 3.30           // Initial voltage (volts)
#define RESISTANCE   330            // Resistance (ohms)
#define CAPACITANCE  0.0000001      // Capacitance (farads)
#define DELTA_T      0.000001       // Time interval (seconds)

#define OUTPUT_FILE  "out.dat"      // Name for output file

double _circuitFunc (double);

int main()
{
    double NUM_e = 2.71828183;
    double C = 0.0000001;     //0.1microF
    double R = 330;           //330 ohms
    //int a = 1;                //initial x
    int b = 2;                //final x
    double tol = 0.0001;      //Dr.V declared this tolerance
    int i;                    //apparently i=0 to i=n-1 is important
    int n;                    //number of steps
    double h = (b-a)/n;       //

    double xi0 = a;
    double yi0 = f(a);
    double xi1 = b;
    double yi1 = f(b);
    double xi2;
    double yi2;

    FILE *cfPtr;

    if((cfPtr = fopen("Euler_Results.csv","w")) == NULL)
        printf("ERROR!!!\n");
    else{

    for (n = 0; n <= 500; n++)
    for( n_idx = 0; n_idx < NUMSAMP; n_idx++ )
    {

        xi2 = xi0-yi0*((xi1-xi0)/(yi1-yi0));
        yi2 = f(xi2);
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

double _circuitFunc(double x)
{   return V0 * pow(NUM_e, (-(d_time_)/(R * C)));
}


double rcFunction(double);

int main(int argc, char *argv[])
{
    printf("RC circuit model running...\n");

    double d_voltage[NUMSAMP];
    double d_time[NUMSAMP];

    FILE *p_out;                    // output file

    int n_idx;

    for( n_idx = 0; n_idx < NUMSAMP; n_idx++ )
    {   d_time[n_idx] = (double)(n_idx * DELTA_T);
        d_voltage[n_idx] = rcFunction(d_time[n_idx]);
        printf("%12.8f\t%12.8f\n", d_time[n_idx], d_voltage[n_idx]);
        }

    if( (p_out = fopen(OUTPUT_FILE, "w")) != NULL )
    {   for ( n_idx = 0; n_idx < NUMSAMP; n_idx++ )
            fprintf(p_out, "%12.8f, %12.8f\n", d_time[n_idx], d_voltage[n_idx]);
        fprintf(p_out, "\n");
        fclose(p_out);
        }
    else
        printf("%s could not be opened. Exiting...\n", OUTPUT_FILE);
    printf("...done.\n");
    return 0;
}

double rcFunction(double d_time_)
{   return INIT_VOLTAGE * pow(NUM_E, (-(d_time_)/(RESISTANCE * CAPACITANCE)));
    }
