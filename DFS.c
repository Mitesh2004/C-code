#include <stdio.h>

#define max 10

int AM[max][max]; // Adjacency Matrix
int n;            // Number of nodes in the graph

void R_DFS(int start_N)
{
    static int visited[max] = {0}; // Visited array to keep track of visited nodes

    visited[start_N] = 1;
    printf("\tv%d", start_N + 1); // Print the node being visited

    for (int next_N = 0; next_N < n; next_N++)
    {
        if (AM[start_N][next_N] == 1 && visited[next_N] == 0)
        {
            R_DFS(next_N); // Recursively visit the adjacent node
        }
    }
}

int main()
{
    printf("Enter the number of nodes in the graph: ");
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

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\t%d", AM[i][j]);
        }
        printf("\n");
    }

    printf("\nGraph Traversal Using DFS:\n");
    R_DFS(0); // Start DFS traversal from node 0

    printf("\n");

    return 0;
}