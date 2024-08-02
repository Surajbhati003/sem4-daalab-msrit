// bubble sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubbleSort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
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
    bubbleSort(arr,n);
    end=clock();
    printf("sorted is :\n");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    totaltime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time taken is: %e\n",totaltime);
}