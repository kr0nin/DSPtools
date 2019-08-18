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

/* A PROGRAM TO ADD TWO NUMBERS*/

int main()
{
    int nInteger1,nInteger2;
    int nSum;

    printf("Enter first integer \n");
    scanf("%d",&nInteger1);

    printf("Enter second integer \n");
    scanf("%d",&nInteger2);

    nSum = nInteger1 + nInteger2;
    printf("Sum of %d and %d is %d",nInteger1,nInteger2,nSum);

    return 0;
}
