/*
Write program to print all the nodes reachable from a given starting node in a digraph by using
BFS method. Give the trace of this algorithm.
*/
#include <stdio.h>
#include<stdlib.h>

// queue implementation
struct Node
{
    int data;
    struct Node *next;
} *front=NULL, *rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    
    if(t == NULL) // if heap memory is full
        printf("Queue is FUll\n");
    else 
    {
        t->data=x;
        t->next=NULL;
        if(front == NULL)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node* t;
    if(front == NULL)
        printf("Queue is Empty\n");
    else 
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}
int isEmpty()
{
    return front == NULL;
}
// main bfs code
void BFS(int G[][7], int start, int n)
{
    int visited[7] = {0};
    printf("%d ", start);
    visited[start] = 1;
    enqueue(start);
    
    while(!isEmpty()) 
    {
        start = dequeue();
        for(int j = 1; j < n; j++) {
            // if there is an edge, and it is not yet visited
            if(G[start][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

// driver code
int main()
{
    // the first column and first row are not used because it is index 0
    int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
    
    printf("BFS: ");
    BFS(G,5,7);
    
    return 0;
}