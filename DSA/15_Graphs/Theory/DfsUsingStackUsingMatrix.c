#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int V;

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void DFS(int start) {
    int i;
    push(start);

    while (!isEmpty()) {
        int v = pop();

        if (!visited[v]) {
            visited[v] = 1;
            printf("%d ", v);

            // Push adjacent vertices
            for (i = V - 1; i >= 0; i--) {
                if (adj[v][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
}


void dfs(int start) {
    push(start);

    while (!isEmpty()) {
        int v = pop();

        if (!visited[v]) {
            visited[v] = 1;

            printf("%d ", v);

            // push neighbours of v
            for (int i = V-1; i >= 0; i--) {
                if (adj[v][i] == 1 && visited[i] == 0) {
                    push(i);
                }
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal (Stack): ");
    DFS(start);

    return 0;
}
