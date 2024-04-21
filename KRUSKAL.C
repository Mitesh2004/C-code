#include <stdio.h>
//#include <stdlib.h>

#define max 10
#define INF 999

int parent[max];

int find(int i)
{
    return (parent[i]) ? find(parent[i]) : i;
    /*while (parent[i])
        i = parent[i];
    return i;*/
}

void unionSet(int i, int j)
{
    parent[j] = i;
}

int main()
{
    int n, next_N = 1, mincost = 0;
    int AM[max][max];

    printf("Kruskal's algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("Is there an edge from v%d to v%d? (0 for no edge): ", i, j);
            scanf("%d", &AM[i][j]);
            if (AM[i][j] == 0)
            {
                AM[i][j] = INF;
            }
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (next_N < n)
    {
        int min = INF, a, b;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (AM[i][j] < min)
                {
                    min = AM[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if (u != v)
        {
            printf("%d edge (%d,%d) = %d\n", next_N++, a, b, min);
            mincost += min;
            unionSet(u, v);
        }

        AM[a][b] = AM[b][a] = INF; // Mark the edge as visited
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}