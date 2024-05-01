#include <stdio.h>
#include <limits.h>

#define max 100

int AM[max][max]; // Adjacency Matrix
int n;

void printShortestPaths()
{
    // Print the shortest path matrix
    printf("\nThe shortest path matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (AM[i][j] == INT_MAX)
            {
                printf("\t%s", "INF");
            }
            else
            {
                printf("\t%d", AM[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall()
{
    int i, j, k;

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (AM[i][k] != INT_MAX && AM[k][j] != INT_MAX && AM[i][k] + AM[k][j] < AM[i][j])
                {
                    AM[i][j] = AM[i][k] + AM[k][j];
                }
            }
        }
    }

    printShortestPaths();
}

int main()
{
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use '0' for no direct edge, enter weight otherwise):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Edge from vertex %d to vertex %d: ", i + 1, j + 1);
            scanf("%d", &AM[i][j]);
            if (AM[i][j] == 0 && i != j)
            {
                AM[i][j] = INT_MAX; // Set no direct path to INF
            }
        }
    }

    floydWarshall();

    return 0;
}