/*
A university is looking for engineering graduates, they need to sort the candidate‘s resume
based on their ranking. Write a C program to sort the resumes by using heap sort. Determine
the time required to sort the elements. Plot a graph of the number of elements versus time
taken. Specify the time efficiency class of this algorithm.
*/
// Heap Sort in C

#include<stdio.h>

void insert(int a[],int n)
{
    int i=n,temp;
    temp=a[i];
    while(i>1 && temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}

int delete(int a[],int n)
{
    int i,j,x,temp,val;
    val=a[1];
    x=a[n];
    a[1]=a[n];
    a[n]=val;
    i=1;j=i*2;
    while(j<=n-1)
    {
        if(j<n-1 && a[j+1]>a[j])
            j=j+1;
        if(a[i]<a[j])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    return val;
}

void main()
{
    int a[]={0, 14, 15, 5, 20, 30, 8, 40};
    int i;
    for(i=2;i<=7;i++)
        insert(a,i);

    for(i=7;i>1;i--)
        delete(a,i);

    for(i=1;i<=7;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}