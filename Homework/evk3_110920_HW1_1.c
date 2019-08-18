#include <stdio.h>
#include <stdlib.h>

int difference(int);

int main()
{
printf("\nEnter n: ");
int n;
scanf("%d", &n);

int final = difference(n);
printf("Final: %d\n", final);

return 0;
}

int difference(int n)
{
int call;

if(n == 0) call = 1;
else if(n == 1) call = 2;
else call = difference(n-1)*difference(n-2);

return call;
}

