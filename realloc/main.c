#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int i;

    ptr = (int*) malloc(5*sizeof(int));

    if(ptr != NULL){
        *ptr = 1;
        //*(ptr+1) = 2;
        ++ptr = 2;
        ptr[2] = 8;
        ptr[3] = 10;
        ptr[4] = 16;

        /*realloc*/
        ptr = realloc(ptr, 7*sizeof(int));
        ptr[5] = 34;
        ptr[6] = 56;

        for(i = 0; i < 7; i++){
        printf("\nprt[%d] = %d",i,ptr[i]);
        realloc (ptr,0);
        }
    }
    else{
    printf("oh god, stop this hellish program");
    }

return 0;
}
