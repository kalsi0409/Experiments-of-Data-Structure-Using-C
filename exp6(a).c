#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX];    // Visited array
int n;               // Number of vertices

// DFS function
void dfs(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph and visited array
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        for(int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter %d edges (format: u v):\n", edges);
    for(int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d: ", start);
    dfs(start);
    printf("\n");

    return 0;
}