/*-----------------------------------------------------
Name: Erich Kroneberger
NAU id: evk3
Date: September 13, 2011
Name of Program: Catalan Number
Assignment and Problem number: Sample File, #1 <==WAT?

I hereby declare that I have not helped, or received of solicited help
from any unauthorized material or individual for this homework, but i
did start with a template from bblearn from dr.V by the way..

initials: ek
-----------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int _nCatalan;

int main()
{
    int *_nCat;
    int nMax,i;

    /*initializing the array*/
    printf("Number of iterations = ");
    scanf("%d",&nMax);

    _nCat = (int*) malloc((nMax+1)*sizeof(int));

    for (i = 0; i < nMax; i++){
        _nCat[i+1] = _nCatalan(i);
    }

    for (i = 1; i< nMax; i++){
        printf("\nCatalan (%d) = %d",i,nCat[i-1]);
    }

    return 0;
}

int _nCatalan(int n){
    if (n == 0)
        return 1;
    else
        return (2*(2*n+1)/n+2)*_nCatalan(n-1);
}
