/*
Given ‘N’ items with their weight and value. Also, a bag is given whose capacity is ‘W’. Write
a C program based on dynamic programming design technique to find the subset of items that
fit into the bag and earn maximum profit. Give the trace of this algorithm. Find its time
complexity.
*/
#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int p[5]={0,1,2,5,6};
    int wt[5]={0,2,3,4,5};
    int m=8,n=4;
    int k[5][9];
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=m;w++)
        {
            if(i==0||w==0)
                k[i][w]=0;
            else if(wt[i]<=w)
                k[i][w]=max(p[i]+k[i-1][w-wt[i]],k[i-1][w]);
            else
                k[i][w]=k[i-1][w];
        }
    }
    printf("%d\n",k[n][m]);
}