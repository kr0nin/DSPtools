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



int grade()
{
    int nGrade = 0;
    char cDecision = 'y';

    /* get the grade*/

    while (cDecision == 'y' || cDecision == 'Y')
    {
     printf ("\n Input the grade to be assesed : ");
     scanf ("%d", &nGrade);
     fflush(stdin);

     /* print the result */

     if(nGrade >=90)
         printf("\nThe grade is A");
     else if ((nGrade >=80) && (nGrade < 90))
         printf("\nThe grade is B");
     else if ((nGrade >=70) && (nGrade < 80))
         printf("\nThe grade is C");
     else if ((nGrade >=60) && (nGrade < 70))
         printf("\nThe grade is D");
     else
         printf("\nThegrade is F");

     printf("\nAnother grade? (Y/N): ");
     scanf("%c", &cDecision);
     printf("\n");
    }
    return 0;
}
