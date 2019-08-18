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
char nGrade;
int nA = 0, nB = 0, nC = 0, nD = 0, nF = 0, nI = 0;

printf("\nEnter the grade : ");
scanf("%d, nGrade");

/* loop till pressed */
while ((nGrade = getchar()) != 'N'){
    switch(nGrade){
        case 'A':
        case 'a':
        ++nA;
        break;
        case 'B':
        case 'b':
        ++nB;
        break;
        case 'C':
        case 'c':
        ++nC;
        break;
        case 'D':
        case 'd':
        ++nD;
        break;
        case 'F':
        case 'f':
        ++nF;
        break;
        default:
        ++nI;
        break;
    }
}

printf("\n\nNo of A : %d\n",nA);
printf("\n\nNo of B : %d\n",nB);
printf("\n\nNo of C : %d\n",nC);
printf("\n\nNo of D : %d\n",nD);
printf("\n\nNo of F : %d\n",nF);

    return 0;
}

