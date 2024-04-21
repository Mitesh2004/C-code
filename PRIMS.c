#include <stdio.h>

#define max 100
#define INF 999

int AM[max][max]; // Adjacency matrix
int visited[max];

void prims(int n)
{
    int minCost = 0; // Total minimum cost of the spanning tree
    visited[0] = 1;  // Start with the first vertex

    // Process (n - 1) edges
    for (int count = 0; count < n - 1; count++)
    {
        int min = INF;
        int u, v;

        // Find the minimum edge from the visited vertices to an unvisited vertex
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && AM[i][j] && AM[i][j] < min)
                    {
                        min = AM[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1; // Mark the vertex v as visited
        printf("Edge %d: (%d - %d) cost: %d\n", count + 1, u + 1, v + 1, min);
        minCost += min;
    }

    printf("\nMinimum cost of the spanning tree: %d\n", minCost);
}

int main()
{
    int n;

    printf("Prim's Algorithm for Minimum Spanning Tree\n\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Is there an edge from vertex %d to vertex %d? (Cost or 0 if no edge): ", i + 1, j + 1);
            scanf("%d", &AM[i][j]);
        }
        visited[i] = 0; // Initialize all vertices as unvisited
    }

    prims(n);

    return 0;
}