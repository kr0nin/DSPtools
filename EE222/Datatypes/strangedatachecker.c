#include <stdio.h>
#include <stdlib.h>

int main(){

    int account;
    char name[30];
    double balance;

    FILE *cfPtr;

    if (cfPtr = fopen("clients.dat","w") == NULL){
        printf("File could not be opened\n");
        }
    else{
        printf("Enter Account Info, Name, and Balance\n");
        printf("Enter EOF to end input\n");
        printf("?");
        scanf("%d%s%lf",&account,name,&balance);

        /* write to the file*/
        while (!feof(stdin)){
            fprintf(cfPtr,"%d %s %.2f\n",account, name, balance);
            printf("?");
            scanf("%d%s%lf",&account,name,&balance);
            }
        fclose(cfPtr);
        }
    return 0;
}
