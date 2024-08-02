// c. Read a matrix and print those elements of the matrix that are even.
#include<stdio.h>
#include<stdlib.h>
void evenPrint(int **arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j]%2==0)
            {
                printf("%d\t",arr[i][j]);
            }
        }
        
    }
    
}
void main()
{
    int n;
    int **arr;
    printf("enter size of array\n");
    scanf("%d",&n);
    arr= (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        arr[i]=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    evenPrint(arr,n);
    


}