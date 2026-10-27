#include <stdio.h>

#define MAX 20
#define INF 10000000

int n, cost[MAX][MAX];

void dijkstra(int src, int dest) {
    int dist[MAX], prev[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n; count++) {
        int min = INF;
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (cost[u][v] > 0 &&
                !visited[v] &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                prev[v] = u;
            }
        }
    }

    if (dist[dest] == INF) {
        printf("No path from %d to %d\n", src, dest);
        return;
    }

    printf("Shortest distance from %d to %d = %d\n",
           src, dest, dist[dest]);

    int path[MAX], len = 0;

    for (int v = dest; v != -1; v = prev[v])
        path[len++] = v;

    printf("Path: ");

    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);

        if (i > 0)
            printf(" -> ");
    }

    printf("\n");
}

int main(void) {
    int src, dest;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter cost matrix (0 = no edge):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] < 0) {
                printf("Dijkstra's algorithm requires non-negative weights.\n");
                return 1;
            }
        }
    }

    printf("Enter start node and end node (0 to %d): ", n - 1);
    scanf("%d %d", &src, &dest);

    if (src < 0 || src >= n || dest < 0 || dest >= n) {
        printf("Invalid source or destination.\n");
        return 1;
    }

    dijkstra(src, dest);
    return 0;
}