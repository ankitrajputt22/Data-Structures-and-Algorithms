#include <stdio.h>

#define MAX 10

void BFS(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n = 5;
    int graph[MAX][MAX] = {0};

    /* Graph Construction (Adjacency Matrix)
       0 -- 1
       |    |
       2    3
            |
            4
    */
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[3][4] = graph[4][3] = 1;

    BFS(graph, n, 0);

    return 0;
}
