/*
Consider a network of ‘n’ cities which is represented as a Graph.
a. Write a program to find the transitive closure of such a network using Warshall’s algorithm.
b. Write a program to find the shortest paths between all cities using Floyd’s algorithm.
Give the trace of both algorithms. Find its time complexity.
*/


#include<stdio.h>
#include<stdlib.h>

void floyd(int **graph,int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(graph[i][j]>graph[i][k]+graph[k][j])
                    graph[i][j]=graph[i][k]+graph[k][j];
            }
        }
    }
}

int main(void)
{
    int n,i,j;
    printf("enter number of vertices");
    scanf("%d",&n);
    int **graph=(int**)malloc(n*sizeof(int*));
    
    for(i=0;i<n;i++)
    {
        graph[i]=(int*)malloc(n*sizeof(int));
    }

    printf("enter the edges\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("[%d][%d]:",i,j);
            scanf("%d",&graph[i][j]);
        }
    }
    printf("original graph\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    floyd(graph,n);
    printf("the shortest path matrix is:\n");
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}