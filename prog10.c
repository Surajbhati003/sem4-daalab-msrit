/*
Given a weighted connected graph of N cities, write a program to find shortest paths from a
given city to all other cities using Dijkstra's algorithm. Give the trace of this algorithm. Find its
time complexity.
*/
#include<stdlib.h>
#include<stdio.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int **Graph, int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    // Creating cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];
    
    for (i = 0; i < n; i++) 
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    
    while (count < n - 1)
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) 
            {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;

        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) 
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    // Printing the distance
    for (i = 0; i < n; i++)
        if (i != start)
        {
            printf("\nDistance from source to %d: %d", i, distance[i]);
        }
}
int main() 
{
    int **Graph, i, j, n, u;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    Graph = (int**) malloc((n*n)*sizeof(int) );
    printf("Enter the adjacency matrix :-\n");
    for(i=0;i<n;i++)
    {
        Graph[i]=(int *)malloc(n * sizeof(int));
    }
    //read
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d",&Graph[i][j]);
    u = 0;
    Dijkstra(Graph, n, u);
    return 0;
}