/*-----------------------------------------------------
Name: Erich Kroneberger
NAU id: evk3
Date: September 6, 2011
Name of Program: Arrays
Assignment and Problem number: Sample File, #1 <==WAT?

I hereby declare that I have not helped, or received of solicited help
from any unauthorized material or individual for this homework

initials: ek
-----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int *_n;
   int n_i,n_j;
   int n_sum=0;
   float f_average;

   /*intitialize the array*/
   for (n_i = 0; n_i<10; n_i++){
        printf("value for n[%d]",n_i);
        scanf("%d",&_n[n_i]);
   }

   /*sum and display array*/

   //printf("%s%13s\n","Element","Value");
   printf("Number of Elememts in Array = ");
   scanf("%d",&n_j);

   _n = (int*) malloc(n_j*sizeof(int));


   for(n_i = 0; n_i<n_j; n_i++){
        printf("%7d%13d\n",n_i,_n[n_i]);
        n_sum += _n[n_i];
   }

   f_average = (float) n_sum/(sizeof(_n)/sizeof(int));
   printf("\n\nSum = %d; Average = %f\n",n_sum,f_average);

   return 0;
}
