// warshall algorithm

#include<stdio.h>
#include<stdlib.h>

void warshall(int **graph,int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(graph[i][j]|| graph[i][k]&&graph[k][j])
                    graph[i][j]=1;
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
    warshall(graph,n);
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