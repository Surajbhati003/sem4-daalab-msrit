/*
A library maintains details of N books where every book is assigned a unique ISBN. Develop a
program in to sort the books based on ISBN using merge sort technique. Determine the time
required to sort. Repeat the experiment for different values of N and plot a graph of the time
taken versus N. Find its time complexity.
*/
// merge sort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void merge(int *a,int low,int mid,int high)
{
    int i,j,k,b[30000];
    i=low;j=mid+1;k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid) b[k++]=a[i++];
    while(j<=high)b[k++]=a[j++];
    for(k=low;k<=high;k++)
        a[k]=b[k];
}

void mergeSort(int *a,int low,int high)
{
    int mid;
    if(low>=high)
        return;
    mid=floor((low+high)/2);
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
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
    mergeSort(arr,0,n-1);
    end=clock();
    printf("sorted is :\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken is: %e\n",totaltime);
}
