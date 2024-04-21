#include <stdio.h>
int main()
{
    int n, i, j;

    printf("\nHow many nodes in graph: ");
    scanf("%d", &n);

    int AM[n][n];//AM=Adjacency Matrix

    printf("\nEnter the graph connection:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            AM[i][j] = 0;
            printf("Connection between V %d and V %d? (yes-1, No-0): ", i + 1, j + 1);
            scanf("%d", &AM[i][j]);
            
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("\t%d", AM[i][j]);
        }
        printf("\n");
    }

    return 0;
}