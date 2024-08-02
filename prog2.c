/*
2.Write programs for each of the following and indicate the time complexity for varying values of n.
Indicate the parameter ‘n’ and the basic operations.
a. To find the sum of all the elements of the array. (Plot the graph)
b. To find the binary equivalent of a given decimal number.
c. Read a matrix and print those elements of the matrix that are even.
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int arrSum(int *arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
void main()
{
    int i,n,k,r;
    int *arr;
    clock_t start,end;
    double totaltime;
    printf("enter size of array\n");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    for(k=0;k<n;k++)
    {
        arr[k]=rand()%100;
    }
    // printing elements of random array of size n
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);

    start=clock();
    int sum=arrSum(arr,n);
    end=clock();
    printf("\nsum is:%d\n",sum);
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken is: %e\n",totaltime);

}