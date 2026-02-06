#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int V;

// DFS function
void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < V; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j;
    int component_count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for (i = 0; i < V; i++) {
        visited[i] = 0;
    }

    printf("\nConnected Components:\n");

    for (i = 0; i < V; i++) {
        if (visited[i] == 0) {
            component_count++;
            printf("Component %d: ", component_count);
            DFS(i);
            printf("\n");
        }
    }

    printf("\nTotal Connected Components = %d\n", component_count);

    return 0;
}
