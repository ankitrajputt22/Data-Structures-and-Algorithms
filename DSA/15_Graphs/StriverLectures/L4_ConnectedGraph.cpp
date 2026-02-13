/*
============================================================
LECTURE: CONNECTED COMPONENTS IN GRAPH
============================================================

This lecture provides a fundamental explanation of Connected
Components in graph data structures and how to handle them
during traversal.

------------------------------------------------------------
What are Connected Components?
------------------------------------------------------------

A graph can exist in multiple disjoint pieces, where there
is no path between nodes of different pieces.

These individual pieces are called components.

A single graph can be made up of one or many such components.
Even a single isolated node is considered a component.

Example:
If you have 10 nodes and only 8 edges that connect them into
four separate groups, these four groups are the "Connected
Components" of that single graph.

------------------------------------------------------------
Handling Components in Algorithms
------------------------------------------------------------

When performing graph traversals (like BFS or DFS), a single
call starting from node 1 will only visit nodes that are
reachable from 1. If the graph has other components, they
will be missed.

------------------------------------------------------------
The "Visited Array" Concept
------------------------------------------------------------

To ensure every node in every component is visited, you must
use a Visited Array.

Initialize a boolean array (e.g., vis[N+1]) to all false.

Iterate through all nodes from 1 to N using a loop.

For each node, check if it has already been visited.

If not visited, call your traversal algorithm (BFS/DFS)
starting from that node.

------------------------------------------------------------
Algorithm Pattern (Pseudo-code)
------------------------------------------------------------

for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
        traversal(i); 
    }
}

By using this loop and a visited array, you guarantee that
even if a graph is broken into multiple disconnected pieces,
every single node will be processed exactly once.

============================================================
ADDITIONAL IMPORTANT NOTES (Added for Deep Understanding)
============================================================

1. In an Undirected Graph:
   Connected Components represent subgraphs where every
   pair of vertices is connected by some path.

2. In Directed Graph:
   The concept changes to:
   - Strongly Connected Components (SCC)
   - Weakly Connected Components

3. Time Complexity:
   Using BFS/DFS with adjacency list:
   O(V + E)

4. Why Visited Array is Important?
   Without visited[], traversal may:
   - Revisit nodes
   - Cause infinite loops
   - Miss disconnected parts

5. Counting Connected Components:
   Simply count how many times traversal() is called.

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
DFS Traversal
=========================================================*/
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

/*=========================================================
BFS Traversal
=========================================================*/
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

/*=========================================================
Main Function
=========================================================*/
int main() {

    /*
    Input Format:
    n m
    u v (m edges)
    */

    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;

    cout << "\nConnected Components (using DFS):\n";

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            cout << "Component " << components << ": ";
            dfs(i);
            cout << endl;
        }
    }

    cout << "\nTotal Connected Components = " << components << endl;

    return 0;
}
