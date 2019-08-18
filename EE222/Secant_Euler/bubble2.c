#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void bubblesort(int *const, const int);

int bubble2()
{
    int a [SIZE] = {1,6,2,4,8,9,3,0,5,7};
    int count;

    printf("original order: \n");

    for (count = 0; count < SIZE; count ++){
        printf("%d",a[count]);
    }

    bubblesort(a,SIZE);
    printf("Ascending Order: \n");

    for (count = 0; count < SIZE; count++){
        printf("%d", a[count]);
    }

    printf("\n");

    return 0;
}

void bubblesort(int *const array, const int size){
    void swap(int*,int*);

    int pass;
    int count2;

    for (pass = 0; pass < size - 1; pass++){
        for (count2 = 0; count2 < size -1; count2++){
            if (array[count2] > array[count2+1])
                swap(&array[count2],&array[count2+1]);
        }
    }
}

void swap(int *element1, int *element2){
    int temp = *element1;
    *element1 = *element2;
    *element2 = *element1;
}
