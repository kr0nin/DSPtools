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
    int nSum = 0;
    int nNumber = 0;
    int nMax;

    printf("Enter the maximum number to sum to : ");
    scanf("%d", &nMax);
    printf("\n\n");

    for (nNumber = nMax; nNumber >=0; --nNumber)
         {
             nSum += nNumber;

             printf("Sum to %d is %d \n", nNumber, nSum);
         }

    return 0;
}
