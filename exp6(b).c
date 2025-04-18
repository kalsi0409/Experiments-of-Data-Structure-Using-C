#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX];    // Visited array
int queue[MAX];      // Queue for BFS
int front = -1, rear = -1;
int n;               // Number of vertices

// Enqueue function
void enqueue(int vertex) {
    if(rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if(front == -1)
        front = 0;
    queue[++rear] = vertex;
}

// Dequeue function
int dequeue() {
    if(front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// BFS function
void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while(front <= rear) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for(int i = 0; i < n; i++) {
            if(graph[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS traversal starting from vertex %d: ", start);
    bfs(start);
    printf("\n");

    return 0;
}