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
long _fibonacci(int);

int main()
{
    long lResult;  /*value of the number*/
    int nNumber;   /*nth fibonacci number*/
    int nCounter;

    printf("input number to which fibonacci should be displayed\n");
    scanf("%d",&nNumber);

    for(nCounter = 0; nCounter < nNumber; nCounter++)
    {
        lResult = _fibonacci(nCounter);
        printf("\nFibonacci(%d) = %1d",nCounter,lResult);
    }

    return 0;
}

long _fibonacci(int nF)
{
    if(nF==0 || nF==1)
        return (long)nF;
    else
        return _fibonacci(nF-1) + _fibonacci(nF-2);
}
