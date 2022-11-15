#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct gnode
{
    int info;
    struct gnode *next;
} NODE;

void addEdge(NODE *V[MAX], int src, int dest)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->info = dest;
    newNode->next = V[src];
    V[src] = newNode;
}

void createGraph(NODE *V[MAX], int n)
{
    int src, dest;
    while (1)
    {
        scanf("%d%d", &src, &dest);
        if (src < 0 || dest < 0 || src > n || dest > n)
            break;
        addEdge(V, src, dest);
    }
}
void dfs(NODE *V[MAX], int n, int visted[MAX], int src)
{
    visted[src] = 1;
    printf("%d", src);
    NODE *p = V[src];
    while (p != NULL)
    {
        if (visted[p->info] == 0)
            dfs(V, n, visted, p->info);
        p = p->next;
    }
}

void dfsArr(int adj[MAX][MAX], int n, int src, int visited[MAX])
{
    visited[src] = 1;
    printf("%d\n", src);
    for (int i = 0; i < n; i++)
    {
        if (adj[src][i] && visited[i] == 0)
        {
            dfs(adj, n, visited, i);
        }
    }
}

void bfs(NODE *V[MAX], int n, int visited[MAX], int src)
{
    int q[n];
    int front = 0, rear = -1;
    q[++rear] = src;
    visited[src] = 1;
    int v;
    while (front <= rear)
    {
        v = q[front++];
        printf("%d\n", v);
        NODE *p = V[v];
        while (p != NULL)
        {
            if (visited[p->info] == 0)
            {
                q[++rear] = p->info;
                visited[p->info] = 1;
            }
            p = p->next;
        }
    }
}

void bfsArr(int adj[MAX][MAX], int visited[MAX], int src, int n)
{
    int q[n];
    int front = 0, rear = -1;
    q[++rear] = src;
    visited[src] = 1;
    int v;
    while (front <= rear)
    {
        v = q[front++];
        printf("%d\n", v);
        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] && visited[i] == 0)
            {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    NODE *V[MAX];
    int visited[MAX] = {0};
    int n;
    scanf("%d", &n);
    createGraph(V, n);
    int src = 1;
    dfs(V, n, visited, src);
    return 0;
}