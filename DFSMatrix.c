#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int visited[MAX];
int graph[MAX][MAX];
int n;

void DFS(int i) {
    visited[i] = 1;
    printf("%d ", i);
    for (int j = 0; j < n; j++) {
        if (graph[i][j] == 1 && !visited[j])
            DFS(j);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }

    printf("DFS Traversal starting from vertex 0: ");
    DFS(0);

    return 0;
}
