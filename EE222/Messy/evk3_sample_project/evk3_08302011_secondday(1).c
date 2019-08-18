/*-----------------------------------------------------
Name: Erich Kroneberger
NAU id: evk3
Date: August 30, 2011
Name of Program: evk3_08302011_firstday2.c
Assignment and Problem number: Sample File, #1

I hereby declare that I have not helped, or received of solicited help
from any unauthorized material or individual for this homework

initials: ek
-----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



int main()
{
    int nI;
    float fF;
    long lL;
    char cC;
    double dD;
    long double ldLD;
    int nArray[10];

    printf("Size of int = %d\n ",sizeof(nI));
    printf("Size of float = %d\n ",sizeof(fF));
    printf("Size of long = %d\n ",sizeof(lL));
    printf("Size of char = %d\n ",sizeof(cC));
    printf("Size of double = %d\n ",sizeof(dD));
    printf("Size of long double = %d\n ",sizeof(ldLD));
    printf("Size of integer array = %d\n ",sizeof(nArray));

    return 0;
}

