#include <stdio.h>

#define MAX 100

int AM[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int vertex, int n)
{
    visited[vertex] = 1;
    for (int i = 0; i < n; i++)
    {
        if (AM[vertex][i] && !visited[i])
        {
            dfs(i, n);
        }
    }
    stack[++top] = vertex; // Push to stack after exploring all neighbors
}

void topo(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, n);
        }
    }
    printf("\nTopological sorting: ");
    while (top >= 0)
    {
        printf("\t%d ", stack[top--] + 1); // Print stack elements in reverse order
    }
}

int main()
{
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter Graph : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            AM[i][j] = 0;
            printf("Is there an edge from v %d to v %d (YES-1, NO-0): ", i + 1, j + 1);
            scanf("%d", &AM[i][j]);
        }
    }

    topo(n);

    return 0;
}