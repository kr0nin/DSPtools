#include <stdio.h>
#define SIZE 10

void bubbleSort(int * const,const int);
int SwapChange;

int main(void)
{
    /*intialize the array*/

    int a[SIZE] = {1,6,2,4,8,3,5,7,0,9};

    int count;

    printf("data in original order : \n");

    for (count = 0; count < 10; count++){
        printf("%d\t",a[count]);
    }

    bubbleSort(a,SIZE);

    printf("\n\ndata in ascending order : \n");

    for (count = 0; count < 10; count++){
        printf("%d\t",a[count]);
    }

    printf("\n");

    system("PAUSE");

    return 0;
}


void bubbleSort(int * const array, const int size){

     void swap (int*,int*);

     int pass;
     int count2;

     for(pass = 0; pass < size - 1; pass++){
              for (count2 = 0; count2<size - (pass+1); count2++){
                  if (array[count2] > array[count2+1])
                     swap(&array[count2], &array[count2+1]);
              }
              if (SwapChange < 1) pass = size;
     }
}

void swap(int *element1, int *element2){
     SwapChange = 0;
     int temp = *element1;
     *element1 = *element2;
     *element2 = temp;
     SwapChange++;
}



