/*
============================================================
LECTURE: DEPTH-FIRST SEARCH (DFS)
============================================================

This lecture explains the Depth-First Search (DFS) graph
traversal technique, illustrating how it visits nodes as
deeply as possible before backtracking.

------------------------------------------------------------
What is DFS?
------------------------------------------------------------

DFS is a graph traversal algorithm that follows a path
from the starting node as far as it can go into the depth
of the graph. Once it reaches a node with no unvisited
neighbors, it backtracks to the previous node and explores
other available paths.

Key Difference from BFS:
While BFS visits nodes level by level, DFS focuses on
going deep into one branch before exploring others.

Core Mechanism:
It is naturally implemented using recursion
(which internally uses a stack).

------------------------------------------------------------
The DFS Algorithm
------------------------------------------------------------

Preparation:
Create a Visited Array (e.g., vis[N+1]) initialized to false.

Initial Call:
Start DFS recursion from a given node.

Recursive Step:

1. Mark current node as visited.
2. Add current node to DFS result list.
3. Traverse all neighbors using adjacency list.
4. For each unvisited neighbor, recursively call DFS.

Backtracking:
When all neighbors of a node are visited,
the function returns to its caller.

------------------------------------------------------------
Complexity Analysis
------------------------------------------------------------

Time Complexity:
O(V + 2E) for undirected graphs
- Each node visited once → O(V)
- Each edge explored twice → O(2E)

Overall → O(V + E)

Space Complexity:
O(V)
- Visited array → O(V)
- Result vector → O(V)
- Recursion stack (worst case) → O(V)

------------------------------------------------------------
C++ Code Structure (Given in Lecture)
------------------------------------------------------------

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis, ls);
        }
    }
}

Note:
DFS order can vary depending on adjacency list order.

============================================================
ADDITIONAL IMPORTANT NOTES (Added for Deep Understanding)
============================================================

1. DFS uses implicit stack (recursion).
   It can also be implemented using explicit stack.

2. Applications of DFS:
   - Detect cycle
   - Topological sort
   - Strongly Connected Components
   - Path existence check
   - Flood fill / Islands problem

3. DFS does NOT guarantee shortest path.

4. For disconnected graph:
   Use outer loop from 1 to N.

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
DFS FUNCTION (Recursive)
=========================================================*/
void dfs(int node, vector<int> &result) {

    visited[node] = true;
    result.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, result);
        }
    }
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

    cout << "\nDFS Traversal (Handling Disconnected Graph):\n";

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {

            components++;

            vector<int> result;
            dfs(i, result);

            cout << "Component " << components << ": ";
            for (int node : result)
                cout << node << " ";
            cout << endl;
        }
    }

    cout << "\nTotal Components = " << components << endl;

    return 0;
}
