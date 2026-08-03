#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

/*
========================================
Function: matrixRepresentationUndirected
========================================

Purpose:
This function creates and prints the adjacency matrix of an
unweighted undirected graph.

Algorithm:
1. Read the number of nodes n and edges m.
2. Create a 2D matrix of size (n+1) x (n+1) initialized with 0.
3. For every edge (u, v):
   - Mark adjacencyMatrix[u][v] = 1
   - Mark adjacencyMatrix[v][u] = 1
   because the graph is undirected.
4. Print the matrix from 1 to n.

Notes:
- Indexing is 1-based, so size is taken as n+1.
- If there is an edge between u and v, matrix[u][v] = 1.
- Since the graph is undirected, the matrix is symmetric.
- Space Complexity: O(n^2)
- Time Complexity:
  - Building matrix: O(m)
  - Printing matrix: O(n^2)
- Best used when:
  - the graph is dense
  - edge existence query is needed in O(1)
*/
void matrixRepresentationUndirected() {
    int n, m;
    cin >> n >> m;

    // initialize with 0s
    vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1, 0)); 

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

    // optional: print adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
======================================
Function: matrixRepresentationDirected
======================================

Purpose:
This function creates and prints the adjacency matrix of an
unweighted directed graph.

Algorithm:
1. Read the number of nodes n and edges m.
2. Create a 2D matrix of size (n+1) x (n+1) initialized with 0.
3. For every directed edge (u, v):
   - Mark adjacencyMatrix[u][v] = 1
4. Print the matrix from 1 to n.

Notes:
- Indexing is 1-based.
- In a directed graph, edge u -> v does not imply v -> u.
- Therefore only one cell is marked.
- Matrix may not be symmetric.
- Space Complexity: O(n^2)
- Time Complexity:
  - Building matrix: O(m)
  - Printing matrix: O(n^2)
- Useful when:
  - checking whether a directed edge exists quickly
  - graph is dense
*/
void matrixRepresentationDirected() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyMatrix[u][v] = 1;   // only one direction
    }

    // optional: print matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
====================================
Function: listRepresentationUndirected
====================================

Purpose:
This function creates and prints the adjacency list of an
unweighted undirected graph.

Algorithm:
1. Read the number of nodes n and edges m.
2. Create a vector of lists of size n+1.
3. For every edge (u, v):
   - Add v to adjacencyList[u]
   - Add u to adjacencyList[v]
4. Print each node and its neighbors.

Notes:
- Indexing is 1-based.
- Since the graph is undirected, each edge is stored twice.
- More memory efficient than adjacency matrix for sparse graphs.
- Space Complexity: O(n + 2m) which is O(n + m)
- Time Complexity:
  - Building list: O(m)
  - Printing list: O(n + m)
- Best used when:
  - graph is sparse
  - traversals like BFS/DFS are required
*/
void listRepresentationUndirected() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // both directions
    }

    // optional: print list
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int v : adjacencyList[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

/*
==================================
Function: listRepresentationDirected
==================================

Purpose:
This function creates and prints the adjacency list of an
unweighted directed graph.

Algorithm:
1. Read the number of nodes n and edges m.
2. Create a vector of lists of size n+1.
3. For every directed edge (u, v):
   - Add v to adjacencyList[u]
4. Print each node and all outgoing neighbors.

Notes:
- Indexing is 1-based.
- Only outgoing edges from u are stored in adjacencyList[u].
- Space efficient for sparse directed graphs.
- Space Complexity: O(n + m)
- Time Complexity:
  - Building list: O(m)
  - Printing list: O(n + m)
- Useful for:
  - graph traversal
  - topological sort
  - shortest path in sparse graphs
*/
void listRepresentationDirected() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v); // one direction
    }

    // optional: print list
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int v : adjacencyList[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

/*
==================================
Function: weightedMatrixUndirected
==================================

Purpose:
This function creates and prints the adjacency matrix of a
weighted undirected graph.

Algorithm:
1. Read n and m.
2. Create a matrix of size (n+1) x (n+1) initialized with 0.
3. For each edge (u, v, w):
   - Set adjacencyMatrix[u][v] = w
   - Set adjacencyMatrix[v][u] = w
4. Print the matrix.

Notes:
- Indexing is 1-based.
- Value 0 means no edge exists.
- If an edge exists, the matrix stores the weight.
- Since the graph is undirected, matrix remains symmetric.
- Space Complexity: O(n^2)
- Time Complexity:
  - Building matrix: O(m)
  - Printing matrix: O(n^2)
- Caution:
  - If a graph can have weight 0, then using 0 for "no edge"
    may create ambiguity. In such cases, use a large value like INF.
*/
void weightedMatrixUndirected() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacencyMatrix[u][v] = w;
        adjacencyMatrix[v][u] = w;
    }

    // print matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
================================
Function: weightedMatrixDirected
================================

Purpose:
This function creates and prints the adjacency matrix of a
weighted directed graph.

Algorithm:
1. Read n and m.
2. Create a matrix of size (n+1) x (n+1) initialized with 0.
3. For each directed edge (u, v, w):
   - Set adjacencyMatrix[u][v] = w
4. Print the matrix.

Notes:
- Indexing is 1-based.
- Only one direction is updated for each edge.
- 0 means no edge is present.
- Matrix is generally not symmetric.
- Space Complexity: O(n^2)
- Time Complexity:
  - Building matrix: O(m)
  - Printing matrix: O(n^2)
- Useful when:
  - direct access to edge weight is needed in O(1)
  - graph is dense
*/
void weightedMatrixDirected() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacencyMatrix[u][v] = w;   // one direction
    }

    // print matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
================================
Function: weightedListUndirected
================================

Purpose:
This function creates and prints the adjacency list of a
weighted undirected graph.

Algorithm:
1. Read n and m.
2. Create a vector of lists where each list stores pairs (neighbor, weight).
3. For every edge (u, v, w):
   - Add (v, w) to adjacencyList[u]
   - Add (u, w) to adjacencyList[v]
4. Print each node and its list of (neighbor, weight) pairs.

Notes:
- Indexing is 1-based.
- Since the graph is undirected, each edge is stored twice.
- Very common representation for weighted sparse graphs.
- Space Complexity: O(n + 2m) which is O(n + m)
- Time Complexity:
  - Building list: O(m)
  - Printing list: O(n + m)
- Best used in algorithms like:
  - Dijkstra
  - Prim's algorithm
  - BFS/DFS style traversals in weighted graphs
*/
void weightedListUndirected() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacencyList[u].push_back({v, w});
        adjacencyList[v].push_back({u, w});
    }

    // print list
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (auto [v, w] : adjacencyList[i]) {
            cout << "(" << v << ", " << w << ") ";
        }
        cout << "\n";
    }
}

/*
==============================
Function: weightedListDirected
==============================

Purpose:
This function creates and prints the adjacency list of a
weighted directed graph.

Algorithm:
1. Read n and m.
2. Create a vector of lists where each list stores pairs (neighbor, weight).
3. For every directed edge (u, v, w):
   - Add (v, w) to adjacencyList[u]
4. Print each node and its outgoing weighted edges.

Notes:
- Indexing is 1-based.
- Each node stores only outgoing edges.
- This is one of the most efficient representations for sparse weighted directed graphs.
- Space Complexity: O(n + m)
- Time Complexity:
  - Building list: O(m)
  - Printing list: O(n + m)
- Commonly used in:
  - Dijkstra
  - Bellman-Ford input preparation
  - shortest path and graph traversal problems
*/
void weightedListDirected() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacencyList[u].push_back({v, w});
    }

    // print list
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (auto [v, w] : adjacencyList[i]) {
            cout << "(" << v << ", " << w << ") ";
        }
        cout << "\n";
    }
}

int main() {
    newline2;

    /*
    You can call any one function here depending on the graph type
    you want to test.

    Example:
    matrixRepresentationUndirected();
    matrixRepresentationDirected();
    listRepresentationUndirected();
    listRepresentationDirected();
    weightedMatrixUndirected();
    weightedMatrixDirected();
    weightedListUndirected();
    weightedListDirected();
    */

    newline2;
    return 0;
}