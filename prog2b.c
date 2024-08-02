//To find the binary equivalent of a given decimal number.
#include<stdio.h>
// done using recursion
int binaryEq(int x)
{
    if(x>1)
    {
        binaryEq(x/2);
    }
    printf("%d",x%2);
}
void main()
{
    int x;
    printf("enter number in decimal\n");
    scanf("%d",&x);
    binaryEq(x);
}
