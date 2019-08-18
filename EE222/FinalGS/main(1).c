#include "tMatrix.h"
tMatrix GaussElimination(tMatrix);
tMatrix GaussSiedel_LU(tMatrix,tMatrix,tMatrix,int,float);

int main()
{
    tMatrix A,b,x,X0;
    int n;
    
    printf("Enter the number of variables : ");
    scanf("%d",&n);
    A.rows = n; A.cols = n;
    A = allocate(A); b.rows = n; b.cols = 1;
    b = allocate(b); X0.rows = n; X0.cols = 1;
    X0 = allocate(X0);
    
    printf("Enter the values for A: \n");
    read_mat(A);
    printf("\nEnter the values for b: \n");
    read_mat(b);
    printf("\nEnter the values for X0: \n");
    read_mat(X0);
    
    
    
    x = GaussSiedel_LU(A,b,X0,100,.00001);
    printf("\nThe solution is: \n x = ");
    print_mat(x);
    return 0;
}

tMatrix GaussElimination(tMatrix A){
    tMatrix x;
    int n = A.rows;
    int i = 0, j= 0;
    double temp;
    
    x.rows = A.rows; x.cols = 1;
    x = allocate(x);
    
    for(j=0; j<n; j++){
        i = j;
        while(A.data[i][j] == 0)
            i++;
        A = swaprow(A,j,i);
        
        temp = 1/A.data[j][j];
        A = multrow(A,j,temp);
        for (i = j+1; i < n; i++){
            A = subrow(A,i,j,A.data[i][j]);
        }
    }
    
    /*reverse substitution*/
    if(A.data[n-1][n-1] == 0){
        printf("no unique solution");
        exit(1);
    }
    
    x.data[n-1][0] = A.data[n-1][n]/A.data[n-1][n-1];
    for (i=n-2; i>=0; --i){
        x.data[i][0]=A.data[i][n]/A.data[i][i];
        for(j=i+1; j<n; j++){
            x.data[i][0] -= (A.data[i][j]*x.data[j][0])/A.data[i][i];
        }
    }
    
    return x;
    
}

tMatrix GaussSiedel_LU(tMatrix A,tMatrix b,tMatrix Xp,int N,float e){
    
    tMatrix L,U,Xn,temp;
    temp = augment(A,b);
    FILE *cfData;
    
    int i,j = 0,f;
    float k = 0,l;
    
    if ((cfData = fopen("iterations.csv","w")) == NULL){
        printf("Error opening data file");
        f = 0;
    }
    else
        f = 1;
    
    Xn.rows = A.rows; Xn.cols = 1; Xn = allocate(Xn);
    /*Make Main Diagonal as 1*/
    for(i = 0; i< temp.rows; i++){
        j = i;
        while (A.data[i][i] == 0){
            temp = swaprow(temp,i,++j);
        }
        k =1/A.data[i][i];
        temp = multrow(temp,i,k);
    }
    /*get back the new A and b*/
    for (i = 0; i < A.rows; i++){
        for(j = 0; j < A.cols; j++){
            A.data[i][j] = temp.data[i][j];
        }
        b.data[i][0] = temp.data[i][A.cols];
    }
    
    /*find L and U*/
    L.rows = A.rows; L.cols = A.cols; U.rows = A.rows; U.cols = A.cols;
    L = allocate(L); U = allocate(U);
    
    for (i = 0; i < A.rows; i++){
        for(j = 0; j < A.cols; j++){
            if (i>j)
                L.data[i][j] = A.data[i][j];
            else if (i<j)
                U.data[i][j] = A.data[i][j];
        }
    }
    
    /*algorithm using L and U*/
    for (i = 0; i < N; i++){
        
        printf("Iteration No. %d - \n x = ",i);
        print_mat(Xp);
        printf("\n");
        
        if (f == 1){
            for(j = 0; j < Xn.rows; j++){
                fprintf(cfData,"%.4lf",Xp.data[j][0]);
                if (j != Xn.rows - 1)
                    fprintf(cfData,",");
            }
            fprintf(cfData,"\n");
        }
       
        for(j = 0; j < A.rows; j++){
            Xn.data[j][0] = (1/A.data[j][j])*(b.data[j][0] - multiply(extract_row(L,j),Xn).data[0][0] - multiply(extract_row(U,j),Xp).data[0][0]);
        }
     

        
        
        k = fabs((Xn.data[0][0] - Xp.data[0][0])/Xn.data[0][0]);
        for(j = 1; j < Xn.rows; j++){
            l = fabs((Xn.data[j][0] - Xp.data[j][0])/Xn.data[j][0]);
            if (l > k)
                k = l;
        }
        
        if (k < e)
            break;
        for(j = 0; j < Xn.rows; j++){
            Xp.data[j][0] = Xn.data[j][0];
        }
    }
    printf("Iteration No. %d - \n x = ",i+1);
    print_mat(Xn);
    printf("\n");
    fclose(cfData);
    return Xn;
}















