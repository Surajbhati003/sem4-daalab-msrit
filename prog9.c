/*
Consider an electrical layout where ‘n’ houses are connected by electrical wires. Design a
program using Kruskal’s Algorithm to output a connection with minimum cost. Trace the
algorithm. Find its time complexity.
*/
#include <stdio.h>
#include<stdlib.h>
#define MAX 30

typedef struct edge
{
    int u, v, w;
} edge;

typedef struct edge_list 
{
    edge data[MAX];
    int n;
} edge_list;

edge_list elist;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2, int n);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo(int **graph,int numVert)
{
    int belongs[numVert], i, j, cno1, cno2;
    elist.n = 0;
    int n = numVert;
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++) 
        {
            if (graph[i][j] != 0) 
            {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = graph[i][j];
                elist.n++;
            }
        }
    sort();
    for (i = 0; i < n; i++)
        belongs[i] = i;
        spanlist.n = 0;
    for (i = 0; i < elist.n; i++) 
    {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);
        if (cno1 != cno2) 
        {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            applyUnion(belongs, cno1, cno2,n);
        }
    }
}

int find(int belongs[], int vertexno) 
{
    return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2, int n) 
{
    int i;
    for (i = 0; i < n; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}

// Sorting algo
void sort() 
{
    int i, j;
    edge temp;
    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)
            if (elist.data[j].w > elist.data[j + 1].w)  
            {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}
// Printing the result
void print() 
{
    int i, cost = 0;
    for (i = 0; i < spanlist.n; i++) 
    {
        printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }
    printf("\nSpanning tree cost: %d", cost);
}

int main() 
{
    int i, j, numVert;
    int **graph;
    printf("Enter the number of vertices : ");
    scanf("%d",&numVert);
    graph = (int**) malloc((numVert*numVert)*sizeof(int) );
    printf("Enter the adjacency matrix :-\n");
    for(i=0;i<numVert;i++)
    {
        graph[i]=(int *)malloc(numVert * sizeof(int));
    }
    //read
    for (i=0; i<numVert; i++)
        for (j=0; j<numVert; j++)
            scanf("%d",&graph[i][j]);
    kruskalAlgo(graph,numVert);
    print();
}