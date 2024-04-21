#include <stdio.h>
#include <limits.h>

#define max 100

int AM[max][max];
int distance[max];
int visited[max];
int n;

void dijkstra(int start)
{
    int i, j, min_dist, next_node;

    // Initialize distance and visited arrays
    for (i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[start] = 0;

    // Find shortest path for all vertices
    for (i = 0; i < n - 1; i++)
    {
        min_dist = INT_MAX;
        next_node = -1;

        // Choose the vertex with the minimum distance
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && distance[j] < min_dist)
            {
                min_dist = distance[j];
                next_node = j;
            }
        }

        // Mark the selected vertex as visited
        visited[next_node] = 1;

        // Update distance value of adjacent vertices
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && AM[next_node][j] &&
                distance[next_node] != INT_MAX &&
                distance[next_node] + AM[next_node][j] < distance[j])
            {
                distance[j] = distance[next_node] + AM[next_node][j];
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &AM[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Shortest distances from the starting vertex:\n");
    for (i = 0; i < n; i++)
    {
        printf("Vertex %d: %d\n", i, distance[i]);
    }

    return 0;
}