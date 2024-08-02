// binary search
#include<stdio.h>
int binarySearch(int arr[],int low,int high,int key)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
        if(arr[mid]==key)
        {
            return mid;
        }
        else if (arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        
    }
    return -1;
}
void main()
{
    int n,arr[100];
    printf("enter number of elements to insert\n");
    scanf("%d",&n);
    printf("enter the elements in asscending order\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("enter a key to find\n");
    scanf("%d",&key);
    int res=binarySearch(arr,0,n-1,key);
    if(res==0)
        printf("key not found\n");
    else
        printf("key found at position: %d\n",res+1);

}