/*-----------------------------------------------------
Name: Erich Kroneberger
NAU id: evk3
Date: September 6, 2011
Name of Program: fibonacci numbers
Assignment and Problem number: Sample File, #1

I hereby declare that I have not helped, or received of solicited help
from any unauthorized material or individual for this homework

initials: ek
-----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*prototype*/
long double _fact(long double);

int main()
{
    long lResult;  /*value of the number*/
    long lNumber;   /*nth factorial number*/
    int nCounter;

    printf("input number to which factorial should be displayed\n");
    scanf("%ld",&lNumber);

    for(nCounter = 0; nCounter <= lNumber; nCounter++)
    {
        lResult = _fact(nCounter);
        printf("\nFact(%d) = %1d",nCounter,lResult);
    }

    return 0;
}

long _fact(long nF)
{
    if(nF==0)
        return 1;
    else
        return (long) nF * _fact(nF-1);
}
