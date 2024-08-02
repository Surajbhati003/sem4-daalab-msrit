/* Given an array of elements ‘n’, search for an element in this array. Indicate the number of
comparisons for varying values of n. The element to be searched can be the first element, last
element, element other than first and last. Assume the number of elements ‘n’, derive a formula
to indicate the number of comparisons done.
Use the following search techniques
1. Linear Search
2. Binary search
*/
#include<stdio.h>
int linearSearch(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i+1;
            break;
        }
    }
     return 0;
    
}
void main()
{
    int n,arr[100];
    printf("enter number of elements to insert\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("enter a key to find\n");
    scanf("%d",&key);
    int res=linearSearch(arr,n,key);
    if(res==0)
        printf("key not found\n");
    else
        printf("key found at position: %d\n",res);

}