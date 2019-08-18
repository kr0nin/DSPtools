/*--------------------------------------------------------------------
Name: Justin Cummings
NAU id: jmc535
Date: September 27, 2011
Name of Program: jmc535_111209_Final_HW_Main.c
Assigment and Problem number: Final Homework
I herby declare that I have not helpped, or received or solicited help
from
any unauthorized material or individual for this homework.
Initials: JMC
----------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "hComplex.h"
#include "tMatrix.h"
#include <string.h>
#include <math.h>

//-------prototypes-------------------------------------
tMatrix extract_input();
int check_N(int);
tMatrix modify_input(int,tMatrix);
tMatrix_zc DFT_data(int, tMatrix);
tMatrix_zc Unity(int);
void export_results();


int main(int argc, const char * argv[])
{
 //FILE *opt;
 tMatrix xn;
//------------------Step One------------------------------
 xn = extract_input();
 printf("IN FUNCTION MAIN\n"); //keeping track of where i am program wise when viewing output
 printf("Your extracted values in tMatrix form are:\n");
 print_mat(xn); //making sure matrix passed from function properly
//------------------Step Two------------------------------ 
 int N = 0;
 int N_true = 0;
 printf("Please input the value of N: ");
 scanf("%d",&N);
 N_true = check_N(N);
 if(N_true == 0)
 {
  exit(0);
 }
 else //else do nothing at all
 {
 }
//------------------Step Three----------------------------
 tMatrix xnmod;
 xnmod = modify_input(N,xn);
 printf("IN FUNCTION MAIN\n");
 print_mat(xnmod); //making sure matrix passed from function properly
//------------------Step Four-----------------------------
 tMatrix_zc xk; 
 xk = DFT_data(N,xnmod);
 
 return 0;
}

tMatrix extract_input()
{
 printf("IN FUNCTION EXTRACT_INPUT\n");
 FILE *ipt;
 ipt = fopen("/Users/justincummings/Documents/NAU/Fall2011/EE222/Final_Homework/DFTinput.csv", "r");
 if (ipt == NULL)
 {
  printf("ERROR accessing file!\n");
  exit(1);
 }
 else
 {
  printf("\tfile open\n"); //personal verification
//-------------------File To String-----------------------
  char string1[36]; //contstant string size, pointer wouldnt work will come back later
  fgets(string1,36,ipt); //finally have a string i can tokenize
  fclose(ipt);
  printf("\tfile closed\n");
  printf("\tYour file converted to a string is = %s\n",string1); //verify the string visually
  //printf("%c\n",string1[4]);
  char string2[36];
  strcpy(string2,string1);
//-------------------End File To String--------------------

//---------------------Tokenizer----------------------------
  char *tokens;
  int count = 0;
  int max_tok = 0;

  tokens = strtok(string1,",");
  while(tokens != NULL)
  {
   count++;
   //printf("%s\n",tokens);
   if(strlen(tokens)>max_tok)
       max_tok = (int)strlen(tokens);
   else
   {
    max_tok = max_tok;
   }
    tokens = strtok(NULL,",");
  }
  printf("\tThere are %d tokens\n",count); //visual verification of number of tokens
  printf("\tThe max token size is %d\n",max_tok); //visual verification of size/length of tokens
  //printf("%s\n",string1); //reviewing the destroyed tokenized string
  //printf("%s\n",string2); //making sure string 2 was not destroyed as well

//-----------------End Tokenizer-----------------------------
//-----------------Write Tokens to Matrix--------------------
  tMatrix xn;
  xn.rows = count;
  xn.cols = 1;
  xn = allocate(xn);

  tokens = strtok(string2,",");
  int i=0;
  while(tokens != NULL)
  {
   xn.data[i][0] = atoi(tokens); //converts string to int and writes to data to matrix
   tokens = strtok(NULL,",");
   i++;
  }
//---------------End Write Tokens to Matrix--------------------
  //print_mat(xn); //verify matrix visually
  return xn;
 }
}

int check_N(int N)
{
 printf("IN FUNCTION CHECK_N\n");
 int max_itration = 1000;
 int temp = 0;   
 int N_true = 0;
 int k = 0;
 
 for(k = 0; k < max_itration; k++) //checks if N is a power of 2 by
 {                                 //brute force trying 2^k as k goes
  temp = pow(2,k);                 //from 0 to 1000
  if(temp == N)
  {
   N_true = 1;
   break;
  }
 }
    
 if(k == max_itration)
     N_true = 0;
    
 if(N_true == 1)
 {
  printf("\t2^%d = %d\n", k,N);
  printf("\tN is a power of 2, continuing program :)\n");
  return N_true;
 }
 else
 {
  printf("\tERROR, N is not a power of 2. Program terminated!!\n");
  return N_true;
 } 
}

tMatrix modify_input(int N, tMatrix xn)
{
 printf("IN FUNCTION MODIFY_INPUT\n");
 tMatrix xnmod;
 int m = xn.rows;
 int max_itration = 1000;
 int i;
 int temp = 0;
//-------check to see if multiple ------------------------ 
 for(i = 0; i < max_itration; i++)
 {
  temp = i * N;
  if (temp == m)
  {
   break;
  }
 }
//---------if multiple write exisiting xn to xnmod------------    
 if(temp == m)
 {
  printf("\tm is a multiple of N.\n");
  for(i = 0; i < xn.rows; i++)
  {
   xnmod.data[i][0] = xn.data[i][0];
  }
  return xnmod;   
 }
//-------------if not multiple write xn to xnmod from 0 to xn.rows-1 -----  
 else
 {
  int l;
  l = fmod(m,N);
  //printf("\t%d\n",l); visual check of l
  
  xnmod.cols = xn.cols;
  xnmod.rows = (m + N - l);   
  //printf("\t%d\n",xnmod.rows); visual check of new rows
  
  xnmod = allocate(xnmod);
  
  for (i = 0; i < xn.rows; i++)
  {
   xnmod.data[i][0] = xn.data[i][0];
  }
//--------------then write 0 to xnmod from xn.rows to xnmod.rows-1 -----------
  for(i = xn.rows; i < xnmod.rows; i++)
  {
   xnmod.data[i][0] = 0; 
  }
  //print_mat(xnmod); verification of new tMatrix   
  return xnmod;
 }
}

tMatrix_zc DFT_data(int N, tMatrix xnmod)
{
 tMatrix_zc unity_roots;
 unity_roots = Unity(N);
 tMatrix_zc xk;
 xk.rows = xnmod.rows;
 xk.cols = 1;
 xk = allocate_zc(xk);
 //xk = zero_zp(xk);
 int n;
 int k,c;

//------------Convert xnmod to complex------------------------------------
 tComplex_c z;
 tMatrix_zc xnmod_c;
 tComplex_c temp_xk;
 temp_xk.dImag = 0;
 temp_xk.dReal = 0;
 xnmod_c.rows = xnmod.rows;
 xnmod_c.cols = 1;
 xnmod_c = allocate_zc(xnmod_c);
 
 for(n = 0; n < xnmod.rows; n++)
 {
  z.dImag = 0;
  z.dReal = xnmod.data[n][0];
  xnmod_c.data[n][0] = z;
 }
 printf("IN FUNCTION DFT_DATA\n");
 print_mat_zc(xnmod_c);//confirmation of new complex matrix   
//-------------DFT Start Below------------------------------------------------
 c=0;
 for(k = 0; k < xnmod_c.rows ;k++)
 {
  for(n = 0; n < N ;n++) // CURRENT PROBLEMS BELOW CHANGE XN.MOD to COMPLEX---FIXED;
  {
   xk.data[k][0] = tAdd(temp_xk,temp_xk);
   temp_xk = (tMultiply((xnmod_c.data[n+c][0]),tConvert_pc(polar_pow(tConvert_cp(unity_roots.data[n][0]),n))));
  } 
  c+=4;
  printf("xk.data[%d][%d] = ",k,0);
  print_c(xk.data[k][0]);
  printf("\n");
 }
 //printf("IN FUNCTION DFT_DATA\n");
 //print_mat_zc(xk);
 return xk;
}

tMatrix_zc Unity(int N)
{
 unsigned int temp1 = 0;
 unsigned int temp2 = 0;
 int sign1;
 int sign2;
 int k;
    
 tComplex_c temp_c1;
    
 tComplex_p z;
    
 tMatrix_zc Zu;
 Zu.rows = N; Zu.cols = 1;
 Zu = allocate_zc(Zu);
    
 for (k = 0; k < N; k++)
 {
  z.dMag = 1;
  z.dAng = 2*PI*k/N;
  temp_c1 = tConvert_pc(z);
        
  sign1 = temp_c1.dImag > 0? 1: -1;
  temp1 = temp_c1.dImag*pow(10,4)*sign1;
  temp_c1.dImag = (((double)temp1)/pow(10,4)*sign1);
    
  sign2 = temp_c1.dReal > 0? 1: -1;
  temp2 = temp_c1.dReal*pow(10,4)*sign2;
  temp_c1.dReal = (((double)temp2)/pow(10,4)*sign2);
        
  Zu.data[k][0] = temp_c1;
 }
 printf("IN FUCNTION UNITY:\n");
 print_mat_zc(Zu);
 return Zu;
}