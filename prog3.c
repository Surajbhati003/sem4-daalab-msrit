/*
The goods packages in a supermarket are assigned an integer label. Write programs to sort the
set of goods packages based on label identifier using Bubble Sort and Selection Sort and
determine the time required to sort. Plot to compare the time graph. Find its time complexity.
*/
//selection sort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void selectionSort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int mini=i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[mini])
            {
                mini=j;
            }
        }
        int temp=arr[mini];
            arr[mini]=arr[i];
            arr[i]=temp;
    }
    
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
    selectionSort(arr,n);
    end=clock();
    printf("sorted is :\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken is: %e\n",totaltime);
}