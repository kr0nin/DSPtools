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
