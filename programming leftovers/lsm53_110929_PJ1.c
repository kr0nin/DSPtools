/****************************************************************
Name: Levi McCracken

NAU id: lsm53

Date: 11-09-29

Name of Program: PJ1

Assignment and Problem number: PJ1

I hereby declare that I have not helped, or received
or solicited help from any unauthorized material or
individual for this homework.
Initials: lsm
****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define in_v 3.30
#define samples 50

int main()
{
    // send "alive" message to stdout
    printf("PJ1 running...\n");

    // define variables
    double fresistance = 330;
    double ffarad = 0.0000001 ;
    double fdeltat = 0.000001;

    double nn = 0;
    int ntracker;

    // need file to write data to for plotting in matlab
    FILE *pout_file;

    // write x- and y-values to a csv-formatted file for plotting in matlab
    if ( (pout_file = fopen("out.dat", "w")) != NULL)
    {
        //for( ntracker = 0; ntracker <= samples; ntracker++)
        //{
        for (ntracker = 0; ntracker < samples; ntracker++){
            nn = nn + fdeltat;
            double fresult = in_v * exp(-(nn)/(fresistance*ffarad));
            //double fSecond = 1-(nn/());

            fprintf(pout_file, "%f,%f\n",nn,fresult);
        //}
        }
        fclose(pout_file);
    }
    else
    {
    	printf("out.dat could not be opened");
    }

    // normal exit
    return 0;
}
