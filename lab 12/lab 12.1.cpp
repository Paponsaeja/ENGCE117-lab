#include <stdio.h>
#include <limits.h>

int* Dijkstra(int* L, int n);

int main() {
    int n = 5, i = 0, j = 0, *d, *g;
    g = new int[n * n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100; g[0 * n + 2] = 80;
    g[0 * n + 3] = 30; g[0 * n + 4] = 10;
    g[1 * n + 2] = 20; g[3 * n + 1] = 20;
    g[3 * n + 2] = 20; g[4 * n + 3] = 10;

    d = Dijkstra(g, n);
    for (i = 0; i < n - 1; i++)
        printf("%d ", d[i]);
    delete[] d;
    delete[] g;
    return 0;
}

int* Dijkstra(int* L, int n) {
    int* dist = new int[n];
    bool* visited = new bool[n];

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[0] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
            if (!visited[v] && L[u * n + v] != -1 && dist[u] != INT_MAX && dist[u] + L[u * n + v] < dist[v])
                dist[v] = dist[u] + L[u * n + v];
    }

    delete[] visited;
    return dist;
}

