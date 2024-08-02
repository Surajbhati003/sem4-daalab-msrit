/*
Consider a list of ‘n’ files numbered using ID’s. Write a program to sort files based on its ID
using Quick sort. Determine the time required to sort the files. Plot a graph of number of IDs
versus time taken. Find its time complexity.
*/
// quick sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void swap(int *p, int *q)
{
    int temp = *p;
    *p=*q;
    *q = temp;
    printf("Swapped %d and %d \n",*p,*q);
}
int partition(int numb[],int left, int right)
{
    printf("Enters partition\n");
    int i,j, pivot;
    printf("l= %d and r= %d\n",left,right);
    pivot = numb[left];
    printf("pivot%d\n",pivot);
    i=left;
    j= right+1;
    printf("i= %d and j = %d\n",i,j);
    while(i<j)
    { 
        i=i+1;
        while(numb[i]<pivot && i<right)
            {
                i=i+1;
                printf("i=%d\n",i);
            }
        printf("Exitted i\n");
        j=j-1;
        while(numb[j]>pivot && j>left)
            {
                j=j-1;
                printf("j=%d\n",j);
            }
        swap(&numb[i],&numb[j]);
    }
    swap(&numb[i],&numb[j]);
    swap(&numb[left],&numb[j]);
    printf("Partition ends\n");
    return j;
}
void quickSort(int numb[], int left, int right)
{ 
    printf("Enters quickSort\n");
    if(left < right)
    {
        int p = partition(numb, left, right);
        printf("returns p%d\n",p);
        quickSort(numb, left, p-1);
        quickSort(numb, p+1, right);
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
    quickSort(arr,0,n-1);
    end=clock();
    printf("sorted is :\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken is: %e\n",totaltime);
}
