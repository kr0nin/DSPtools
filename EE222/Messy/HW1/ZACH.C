#include <stdio.h>
#include <stdlib.h>

int difference(int);

int zach()
{
printf("\nEnter n: ");
int n = 3;
//scanf("%d\n", &n);
int final = difference(n);
printf("Final: %d\n", final);

//printf("% d\n", difference(n));
return 0;
}

int difference(int n)
{
int ret;
printf("%d\n", n);
if(n == 0) ret = 0;
else if(n == 1) ret = 1;
else ret = difference(n-1) + difference(n-2);
//printf("%d\n", ret);
return ret;
}

