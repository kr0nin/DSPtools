/*EK - 09/27/11 - Random file access*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int accntNum;
    char lastName[30];
    char firstName[30];
    double balance;
    } clientData;

int main(){

    int i;

    clientData blank = {0,"","",0.0};

    FILE *cfPtr;

    if((cfPtr = fopen("data.dat","wb")) == NULL){
        printf("Cannot Open File\n");
    }
    else{
        for(i = 0; i<100; i++){
            fwrite(&blank,sizeof(clientData),1,cfPtr);
        }
    fclose(cfPtr);
    }

    return 0;
}
