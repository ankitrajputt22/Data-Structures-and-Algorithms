/*
============================================================
LECTURE: BREADTH-FIRST SEARCH (BFS)
============================================================

This lecture explains the Breadth-First Search (BFS)
traversal technique for graphs, a fundamental algorithm
used to visit nodes in a level-wise fashion.

------------------------------------------------------------
What is BFS?
------------------------------------------------------------

BFS is a graph traversal algorithm that visits all nodes
at the current distance (level) before moving on to nodes
at the next distance level. It is also known as
Level-wise Traversal.

Level 0: Starting node.
Level 1: All immediate neighbors of the starting node.
Level 2: Neighbors of the nodes at Level 1 that haven't
         been visited yet.

------------------------------------------------------------
Initial Configuration
------------------------------------------------------------

To perform BFS, you need:

Queue Data Structure:
A First-In-First-Out (FIFO) structure to store nodes
for processing.

Visited Array:
To keep track of nodes already visited, preventing
infinite loops and redundant processing.

------------------------------------------------------------
BFS Algorithm Steps
------------------------------------------------------------

1. Push the starting node into the queue and mark it
   as visited in the visited array.

2. While the queue is not empty:

   a. Extract the front node from the queue and add it
      to your BFS traversal list.

   b. Iterate through all the unvisited neighbors of
      this node (obtained from the adjacency list).

   c. For each unvisited neighbor, mark it as visited
      and push it into the queue.

------------------------------------------------------------
Time and Space Complexity
------------------------------------------------------------

Time Complexity:
O(V + 2E) for undirected graphs,
where V is number of vertices
and E is number of edges.

Reason:
- Every node enters queue once → O(V)
- Every edge explored twice → O(2E)

Overall → O(V + E)

Space Complexity:
O(3V) ≈ O(V)

Reason:
- Queue → O(V)
- Visited array → O(V)
- BFS result vector → O(V)

------------------------------------------------------------
C++ Implementation Summary (Given in Lecture)
------------------------------------------------------------

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

============================================================
ADDITIONAL IMPORTANT NOTES (Added for Deep Understanding)
============================================================

1. BFS works best for:
   - Shortest path in unweighted graph
   - Level order traversal
   - Detecting bipartite graph
   - Finding connected components

2. Why Mark Visited When Pushing?
   If we mark visited AFTER popping,
   duplicate entries may enter the queue.

3. BFS guarantees shortest path
   (in terms of number of edges)
   in an unweighted graph.

4. If graph is disconnected:
   Use outer loop over all nodes.

============================================================
IMPLEMENTATION BELOW
============================================================
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
int n, m;

/*=========================================================
BFS FUNCTION (Single Component)
=========================================================*/
vector<int> bfsTraversal(int start) {

    queue<int> q;
    vector<int> bfs;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        bfs.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfs;
}

/*=========================================================
MAIN FUNCTION
=========================================================*/
int main() {

    /*
    Input Format:
    n m
    u v (m edges)
    */

    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "\nBFS Traversal (Handling Disconnected Graph):\n";

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {

            components++;

            vector<int> result = bfsTraversal(i);

            cout << "Component " << components << ": ";
            for (int node : result)
                cout << node << " ";
            cout << endl;
        }
    }

    cout << "\nTotal Components = " << components << endl;

    return 0;
}
