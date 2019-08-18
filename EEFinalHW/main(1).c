////////////////////////////////////////////////////
//DFT in C
//by
//Erich Vaughn Kroneberger
//evk3@nau.edu
//for
//EE222 NAU Fall 2011
////////////////////////////////////////////////////

#include "tMatrix.h"
#include "hComplex.h"
#include <string.h>

//prototype
tMatrix extract_input();
void check_N(int);
tMatrix modify_input(int, tMatrix);
tMatrix_zc DFT_data(int, tMatrix_zc);
//ExtraCredit
//5.)Xkmag,Xkangle -> DFTmagnitude.csv,DFTangle.csv
void export_results(tMatrix_zc);

int main(){
 tMatrix xn;
 xn = extract_input();
 int N = 0;

 printf("Please input the value of N: ");
 scanf("%d",&N);
 tMatrix xnmod;
 xnmod = modify_input(N,xn);
 print_mat(xnmod);

 tMatrix_zc xk;
 xk = DFT_data(N,tMtoComplex(xnmod));

 print_mat_zc(xk);

export_results(xk);

return 0;
}

tMatrix extract_input(){

 tMatrix xn;
 char string1[36];
 char string2[36];
 FILE *csv0pt;
 csv0pt = fopen("DFTinput.csv", "r");
 if (csv0pt == NULL)
  {
    printf("Unable to read input file\n");
    exit(1);
  }
  else  //copy file to string
  {
    printf("\topened file DFTinput.csv\n");
    //char string1[36];
    fgets(string1,36,csv0pt);
    fclose(csv0pt);
    printf("\tclosed file DFTinput.csv\n");
    //char string2[36];
    strcpy(string2,string1);
  }
  //string to tokenizer
  char *tokens;
  int tCount = 0;
  int tokenMax = 0;

  tokens = strtok(string1,",");
  while(tokens != NULL)
  {
   tCount++;
   if(strlen(tokens)>tokenMax)
       tokenMax = (int)strlen(tokens);
   else
   {
    tokenMax = tokenMax;
   }
    tokens = strtok(NULL,",");
  }
  //tokenizer to array (matrix)
  xn.rows = tCount;
  xn.cols = 1;
  xn = allocate(xn);

  tokens = strtok(string2,",");
  int i=0;
  while(tokens != NULL)
  {
   xn.data[i][0] = atoi(tokens);
   tokens = strtok(NULL,",");
   i++;
  }

return xn;
}

void check_N(int N){
 int max = 1000;
 int tmp = 0;
 int N_true = 0;
 int k = 0;
 for(k = 0; k < max; k++)
 {
     tmp=pow(2,k);
     if(tmp == N)
        {
            N_true = 1;
            break;
        }
 }
 if(k==max)
    N_true = 0;
 if(N_true==1)
 {
     printf("\t2^%d = %d\n", k,N);
     printf("\tN is a power of 2\n");
 }
 else
 {
     printf("\tERROR, N is not a power of 2 (check_N failure)\n");
     exit(0);//CHECK THIS LATER
 }
}

tMatrix modify_input(int N, tMatrix xn){
    tMatrix xnmod;
    int m = xn.rows;
    int i,l;
    l = fmod(m,N);
    xnmod.cols = xn.cols;
    xnmod.rows = (m+N-l);
    xnmod = allocate(xnmod);
  for (i =0; i <xnmod.rows; i++){
    if (i<xn.rows)
    xnmod.data[i][0] = xn.data[i][0];
    else
    xnmod.data[i][0] = 0;
  }
  return xnmod;
}

tMatrix_zc DFT_data(int N, tMatrix_zc ORG){
    int wait,chunk = 0;
    int r,n,k;    // counters
    tMatrix_zc DFT; //final matrix
    tMatrix_zc Zu;  //roots of unity of n
    tComplex_p z;   //data inside Zu (unity roots in Matrix)
    tComplex_c twiddle;

    Zu.rows = N; Zu.cols = 1;
    Zu = allocate_zc(Zu);

    //n roots unity
    for (r = 0; r < N; r++){
        z.dMag = 1;
        z.dAng = 2*PI*r/N;
        Zu.data[r][0] = tConvert_pc(z);
    }

    //check roots of unity
    printf("Roots of unity:\n");
    print_mat_zc(Zu);
    printf("\nok?");
    scanf("%d",&wait);

    DFT.rows = ORG.rows;DFT.cols = 1;
    DFT = allocate_zc(DFT);

    //actual DFT
    for (k = 0; k < ORG.rows; k++){
        for (n = 0; n < N; n++){
            chunk = floor(k/N);
            twiddle = tConvert_pc(tComplexPower(tConvert_cp(Zu.data[k-(N*chunk)][0]),n));
            DFT.data[k][0] = tAdd(DFT.data[k][0],tMultiply(ORG.data[n+(N*chunk)][0],twiddle));
                /*/check DFT
                printf("DFT:\n");
                print_mat_zc(DFT);
                printf("\nok?");
                printf("\nchunk:%d\nk:%d\nn%d\n",chunk,k,n);
                scanf("%d",&wait);*/
        }
    }
return DFT;

}

void export_results(tMatrix_zc xk){
    int i,j,k;
    tMatrix_zp xkp;
    xkp = tMatCon_cp(xk);
    FILE *cfPtr;
    tComplex_p pholder;

    print_mat_zp(xkp);

tMatrix Xkmag, Xkangle;
Xkmag.rows = xk.rows; Xkangle.rows = xk.rows;
Xkmag.cols = xk.cols; Xkangle.cols = xk.cols;
Xkmag = allocate(Xkmag); Xkangle = allocate(Xkangle);

for (k= 0; k< Xkmag.rows; k++){
    pholder = xkp.data[k][0];
    Xkmag.data[k][0] = pholder.dMag;
    Xkangle.data[k][0] = pholder.dAng;
}

    //DFTmagnitude.csv
        if((cfPtr = fopen("DFTmagnitude.csv","w+")) == NULL)
        printf("error - unable to output to file (Magnitude)\n");
        else{
            for (i=0; i<xk.rows;i++){
                fprintf(cfPtr,"%lf,",(Xkmag.data[i][0]));
            }
            fclose(cfPtr);
            }

    //DFTangle.csv
        if((cfPtr = fopen("DFTangle.csv","w+")) == NULL)
        printf("error - unable to output to file (Angle)\n");
        else{
            for (j=0; j<xk.rows;j++){
                fprintf(cfPtr,"%lf,",(Xkangle.data[j][0]));
            }
            fclose(cfPtr);
            }
}
