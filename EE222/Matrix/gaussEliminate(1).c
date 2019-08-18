tMatrix GaussElimination(tMatrix A){
    tMatrix x;

    int n = A.rows;
    int i = 0;
    int j = 0;

    x.rows = A.rows;
    x.cols = 1;
    x = allocate(x);

    for (j=0; j<n; j++){
        i = j;
        while (A.data[i][j] == 0)
            i++;
        A = swaprow(A,j,i);

        temp = 1/A.data[j][j];
        A = multrow(A,j,temp);
        for (i=j+1; i<n; i++){
            A = subrow(A,i,j,A.data[i][j]);
        }
    }

    if(A.data[n-1][n-1] == 0){
        printf("no unique solution");
        exit(1);
    }

    x.data[n-1][0] = A.data[n-1][n]/A.data[n-1][n-1];
    for (i=n-2; i>=0; --1){
        x.data[i][0]=A.data[i][n]/A.data[i][n-1];
        for (j=i+1; j<n; j++){
            x.data[i][0] -= (A.data[i][j]*x.data[j][0])
        }
    }
}
