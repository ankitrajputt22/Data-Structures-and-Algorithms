/*
===============================================================================
EXPERIMENT – 7
GRAPH IMPLEMENTATION
===============================================================================
Includes:
1. Represent Graph Using Adjacency Matrix
2. BFS Traversal
3. Minimum Spanning Tree (Prim’s Algorithm)
4. Shortest Path Algorithm (Dijkstra’s)
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 9999


/*===============================================================================
SECTION 1 : GRAPH REPRESENTATION (ADJACENCY MATRIX)
===============================================================================*/

/*---------------- ALGORITHM ----------------
CREATE_GRAPH():
1. Take number of vertices n
2. Read n x n adjacency matrix
3. graph[i][j] = 1 if edge exists, else 0
---------------------------------------------*/

int graph[MAX][MAX];
int vertices = 5;  // Auto example

void createGraphAuto() {
    int sample[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            graph[i][j] = sample[i][j];

    printf("Graph (Adjacency Matrix) Created Successfully.\n");
}


/*===============================================================================
SECTION 2 : BREADTH FIRST SEARCH (BFS)
===============================================================================*/

/*---------------- ALGORITHM ----------------
BFS(start):
1. Mark start node visited, enqueue it
2. While queue not empty:
   a) Dequeue node
   b) Visit all unvisited neighbors and enqueue them
---------------------------------------------*/

void BFS(int start) {
    int visited[MAX] = {0}, queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front != rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < vertices; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}


/*===============================================================================
SECTION 3 : MINIMUM SPANNING TREE (PRIM’S ALGORITHM)
===============================================================================*/

/*---------------- ALGORITHM ----------------
PRIM_MST():
1. Select first vertex
2. Repeat until n-1 edges selected:
   a) Find cheapest edge from selected set → unselected vertex
   b) Include this vertex in selected set
3. Accumulate total cost
---------------------------------------------*/

void primMST() {
    int selected[MAX] = {0};
    int edgeCount = 0, totalCost = 0;

    selected[0] = 1; // Start at vertex 0

    printf("\nEdges in MST (Prim’s Algorithm):\n");

    while (edgeCount < vertices - 1) {
        int min = INF, x = 0, y = 0;

        for (int i = 0; i < vertices; i++) {
            if (selected[i]) {
                for (int j = 0; j < vertices; j++) {
                    if (!selected[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        totalCost += graph[x][y];
        selected[y] = 1;
        edgeCount++;
    }

    printf("Total Cost of MST = %d\n", totalCost);
}


/*===============================================================================
SECTION 4 : SHORTEST PATH (DIJKSTRA'S ALGORITHM)
===============================================================================*/

/*---------------- ALGORITHM ----------------
DIJKSTRA(start):
1. Initialize all distances = INF except start = 0
2. Repeat:
   a) Pick unvisited vertex with smallest distance
   b) Update distances of its neighbors
3. Print final shortest distances
---------------------------------------------*/

void dijkstra(int start) {
    int dist[MAX], visited[MAX] = {0};
    int cost[MAX][MAX];

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            cost[i][j] = (graph[i][j] == 0) ? INF : graph[i][j];

    for (int i = 0; i < vertices; i++)
        dist[i] = cost[start][i];

    dist[start] = 0;
    visited[start] = 1;

    for (int count = 1; count < vertices - 1; count++) {
        int minDist = INF, nextNode = 0;

        for (int i = 0; i < vertices; i++)
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                nextNode = i;
            }

        visited[nextNode] = 1;

        for (int i = 0; i < vertices; i++)
            if (!visited[i] && minDist + cost[nextNode][i] < dist[i])
                dist[i] = minDist + cost[nextNode][i];
    }

    printf("\nShortest Distances from Node %d:\n", start);
    for (int i = 0; i < vertices; i++)
        printf("To %d = %d\n", i, dist[i]);
}


/*===============================================================================
MAIN FUNCTION — AUTO DEMO OF ALL GRAPH OPERATIONS
===============================================================================*/
int main() {

    printf("\n==============================\n");
    printf("     GRAPH CREATION (Auto)\n");
    printf("==============================\n");
    createGraphAuto();


    printf("\n==============================\n");
    printf("         BFS TRAVERSAL\n");
    printf("==============================\n");
    BFS(0);


    printf("\n==============================\n");
    printf(" MINIMUM SPANNING TREE (PRIM)\n");
    printf("==============================\n");
    primMST();


    printf("\n==============================\n");
    printf("   SHORTEST PATH (DIJKSTRA)\n");
    printf("==============================\n");
    dijkstra(0);

    return 0;
}
