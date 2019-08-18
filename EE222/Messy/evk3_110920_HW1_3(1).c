#include <stdio.h>
#include <stdlib.h>

int GCD(int x, int y);

int main()
{
int y;
int x;
printf("\nEnter x: ");
scanf("%d", &x);
printf("\nEnter y: ");
scanf("%d", &y);

int result = GCD(x,y);
printf("Greatest Common Denominator: %d\n", result);

return 0;
}

int GCD(int x, int y)
{
int nEnd;

if(y == 0) nEnd = x;
else nEnd = GCD(y,x%y);

return (nEnd);
}
