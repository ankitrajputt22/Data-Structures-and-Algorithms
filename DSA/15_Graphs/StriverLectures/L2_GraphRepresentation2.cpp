#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
===============================================================================
LECTURE NOTES: GRAPH REPRESENTATION IN C++
===============================================================================

Lecture Reference:
https://youtu.be/3oI-34aPMWM

Purpose of this file:
- Understand how a graph is given as input.
- Learn how to store a graph in C++.
- Learn adjacency matrix representation.
- Learn adjacency list representation.
- Understand directed and undirected graph storage.
- Understand weighted graph storage.
- Revise important space and time complexities.

Main topics:
1. Graph input format
2. Number of nodes and edges
3. Adjacency matrix
4. Adjacency list
5. Undirected graph representation
6. Directed graph representation
7. Weighted graph representation
8. Complexity comparison

===============================================================================
1. GRAPH INPUT AND GRAPH STORAGE
===============================================================================

In the previous lecture, we learned:

- What a graph is
- Nodes or vertices
- Edges
- Directed graphs
- Undirected graphs
- Cycles
- Paths
- Degrees
- Edge weights

Now the question is:

    How do we store a graph inside a C++ program?

There are two main parts:

1. Taking the graph as input
2. Storing the graph in a data structure

The graph must be stored properly before graph algorithms such as BFS, DFS,
shortest path, cycle detection, and topological sorting can be applied.

===============================================================================
2. COMMON GRAPH INPUT FORMAT
===============================================================================

Most graph problems first provide two integers:

    n m

Where:

    n = Number of nodes or vertices
    m = Number of edges

Example:

    5 6

This means:

    Number of nodes = 5
    Number of edges = 6

The problem statement also tells us whether the graph is:

- Directed
- Undirected
- Weighted
- Unweighted

After n and m, the next m lines describe the edges.

General format:

    n m

    u1 v1
    u2 v2
    u3 v3
    ...
    um vm

Each line tells us that there is an edge between two nodes.

Example:

    5 6
    1 2
    1 3
    2 4
    3 4
    2 5
    4 5

Here:

    n = 5
    m = 6

The six edges are:

    1 - 2
    1 - 3
    2 - 4
    3 - 4
    2 - 5
    4 - 5

Possible graph:

        1
       / \
      2   3
      |\  |
      | \ |
      5---4

The edge lines can be given in any order.

For example, these both represent the same undirected edge:

    1 2
    2 1

This is because an undirected edge allows movement in both directions.

-------------------------------------------------------------------------------
2.1 READING n AND m
-------------------------------------------------------------------------------

C++ code:

    int n, m;
    cin >> n >> m;

-------------------------------------------------------------------------------
2.2 READING ALL EDGES
-------------------------------------------------------------------------------

Since there are m edges, run a loop m times.

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
    }

For every iteration:

    u = First node of the edge
    v = Second node of the edge

Extra Note:
The number of nodes n stays fixed for one graph.

The number of edges m depends on the connections present in the graph.

Different graphs having the same number of nodes can have different numbers
of edges.

===============================================================================
3. METHODS TO STORE A GRAPH
===============================================================================

Two common graph representations are:

1. Adjacency Matrix
2. Adjacency List

Adjacency Matrix:
- Uses a two-dimensional matrix.
- Easy to check whether an edge exists.
- Uses more memory.

Adjacency List:
- Stores only the actual neighbours of every node.
- Usually uses less memory.
- Commonly used in graph algorithms.

===============================================================================
4. ADJACENCY MATRIX
===============================================================================

An adjacency matrix is a two-dimensional matrix used to store graph edges.

Suppose a graph has n nodes.

For one-based node numbering, we create:

    matrix[n + 1][n + 1]

The extra row and column allow us to use node numbers directly from 1 to n.

For n = 5, the indexes are:

    0, 1, 2, 3, 4, 5

Index 0 is unused.

The useful matrix is:

          1   2   3   4   5
        +---+---+---+---+---+
    1   |   |   |   |   |   |
        +---+---+---+---+---+
    2   |   |   |   |   |   |
        +---+---+---+---+---+
    3   |   |   |   |   |   |
        +---+---+---+---+---+
    4   |   |   |   |   |   |
        +---+---+---+---+---+
    5   |   |   |   |   |   |
        +---+---+---+---+---+

If there is an edge between u and v, we mark:

    adjacencyMatrix[u][v] = 1

If no edge exists, the value remains:

    adjacencyMatrix[u][v] = 0

-------------------------------------------------------------------------------
4.1 UNDIRECTED GRAPH USING ADJACENCY MATRIX
-------------------------------------------------------------------------------

In an undirected graph, an edge between u and v works in both directions.

Therefore, we mark both:

    adjacencyMatrix[u][v] = 1;
    adjacencyMatrix[v][u] = 1;

Example:

For edge:

    1 - 2

Mark:

    adjacencyMatrix[1][2] = 1
    adjacencyMatrix[2][1] = 1

For edge:

    1 - 3

Mark:

    adjacencyMatrix[1][3] = 1
    adjacencyMatrix[3][1] = 1

For edge:

    2 - 4

Mark:

    adjacencyMatrix[2][4] = 1
    adjacencyMatrix[4][2] = 1

The matrix is symmetric for a simple undirected graph.

Example:

    matrix[2][4] = matrix[4][2]

Sample graph:

    5 6
    1 2
    1 3
    2 4
    3 4
    2 5
    4 5

Its adjacency matrix is:

          1  2  3  4  5
       -----------------
    1  |  0  1  1  0  0
    2  |  1  0  0  1  1
    3  |  1  0  0  1  0
    4  |  0  1  1  0  1
    5  |  0  1  0  1  0

Examples:

Is there an edge between 3 and 4?

    matrix[3][4] = 1

Answer:

    Yes

Is there an edge between 4 and 2?

    matrix[4][2] = 1

Answer:

    Yes

Is there an edge between 5 and 3?

    matrix[5][3] = 0

Answer:

    No

-------------------------------------------------------------------------------
4.2 C++ CODE FOR AN UNDIRECTED ADJACENCY MATRIX
-------------------------------------------------------------------------------

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyMatrix(
        n + 1,
        vector<int>(n + 1, 0)
    );

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

Explanation:

    vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1, 0));

This creates an (n + 1) x (n + 1) matrix.

Every value is initially 0.

When an edge is read, the required cells are changed to 1.

-------------------------------------------------------------------------------
4.3 ZERO-BASED INDEXING
-------------------------------------------------------------------------------

If nodes are numbered from:

    0 to n - 1

Then a matrix of size n x n is enough.

Example:

    vector<vector<int>> matrix(n, vector<int>(n, 0));

If nodes are numbered from:

    1 to n

Then use:

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));

Extra Note:
Always inspect the node numbering in the problem statement.

-------------------------------------------------------------------------------
4.4 SPACE COMPLEXITY OF ADJACENCY MATRIX
-------------------------------------------------------------------------------

The matrix contains approximately:

    n x n cells

Therefore:

    Space Complexity = O(n^2)

For one-based indexing, the exact size is:

    (n + 1) x (n + 1)

In complexity analysis:

    O((n + 1)^2) = O(n^2)

This can be expensive when n is large.

Example:

If:

    n = 100000

Then an n x n matrix would need an extremely large amount of memory.

Many cells may remain 0 because most pairs of nodes may not have an edge.

This is why adjacency matrices are usually avoided for large sparse graphs.

Extra Note:
A sparse graph has relatively few edges compared with the maximum possible
number of edges.

-------------------------------------------------------------------------------
4.5 TIME COMPLEXITY OF ADJACENCY MATRIX
-------------------------------------------------------------------------------

Reading and inserting m edges takes:

    O(m)

Each insertion takes constant time:

    matrix[u][v] = 1

Checking whether an edge exists also takes:

    O(1)

Example:

    if (matrix[u][v] == 1) {
        cout << "Edge exists";
    }

Extra Note:
Creating and filling the complete matrix with zeros takes O(n^2) time.

Therefore:

    Matrix creation = O(n^2)
    Reading m edges = O(m)

Total construction can be written as:

    O(n^2 + m)

===============================================================================
5. ADJACENCY LIST
===============================================================================

An adjacency list stores the neighbours of every node.

Instead of storing every possible pair of nodes, it stores only the actual
connections.

For n nodes, we create an array or vector containing n lists.

In C++, each list can be represented using a vector.

For one-based indexing:

    vector<vector<int>> adjacencyList(n + 1);

Every index contains an empty vector.

For n = 5:

    adjacencyList[0] = { }
    adjacencyList[1] = { }
    adjacencyList[2] = { }
    adjacencyList[3] = { }
    adjacencyList[4] = { }
    adjacencyList[5] = { }

Index 0 is unused.

The purpose of adjacencyList[node] is to store all neighbours of that node.

Example:

If node 4 is connected to nodes 2, 3, and 5:

    adjacencyList[4] = {2, 3, 5}

The order of neighbours usually does not matter unless a problem specifically
requires sorted traversal.

===============================================================================
6. UNDIRECTED GRAPH USING ADJACENCY LIST
===============================================================================

For an undirected edge between u and v:

    v is a neighbour of u
    u is a neighbour of v

Therefore, store both:

    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);

Example:

For edge:

    1 - 2

Store:

    adjacencyList[1].push_back(2);
    adjacencyList[2].push_back(1);

After this:

    adjacencyList[1] = {2}
    adjacencyList[2] = {1}

For edge:

    1 - 3

Store:

    adjacencyList[1].push_back(3);
    adjacencyList[3].push_back(1);

Now:

    adjacencyList[1] = {2, 3}
    adjacencyList[3] = {1}

-------------------------------------------------------------------------------
6.1 COMPLETE EXAMPLE
-------------------------------------------------------------------------------

Input:

    5 6
    1 2
    1 3
    2 4
    3 4
    2 5
    4 5

Edges:

    1 - 2
    1 - 3
    2 - 4
    3 - 4
    2 - 5
    4 - 5

Final adjacency list:

    1 -> 2, 3
    2 -> 1, 4, 5
    3 -> 1, 4
    4 -> 2, 3, 5
    5 -> 2, 4

ASCII representation:

    Index       Neighbours

      0   ->    unused
      1   ->    2, 3
      2   ->    1, 4, 5
      3   ->    1, 4
      4   ->    2, 3, 5
      5   ->    2, 4

For node 4:

    adjacencyList[4] = {2, 3, 5}

Therefore, the neighbours of node 4 are:

    2, 3, and 5

-------------------------------------------------------------------------------
6.2 C++ CODE FOR AN UNDIRECTED ADJACENCY LIST
-------------------------------------------------------------------------------

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

Explanation:

    adjacencyList[u].push_back(v);

means:

    Add v to the neighbour list of u.

Similarly:

    adjacencyList[v].push_back(u);

means:

    Add u to the neighbour list of v.

Both lines are needed because the graph is undirected.

===============================================================================
7. SPACE COMPLEXITY OF AN UNDIRECTED ADJACENCY LIST
===============================================================================

Every undirected edge is stored two times.

For edge:

    u - v

We store:

    v inside adjacencyList[u]
    u inside adjacencyList[v]

Therefore, if there are m edges, the total number of stored neighbour entries
is:

    2m

The lecture describes this edge storage as:

    O(2m)

After removing constant factors:

    O(m)

However, we also need an array or vector for n nodes.

Therefore, the complete space complexity is:

    O(n + 2m)

After removing constants:

    O(n + m)

Example:

If there are 6 undirected edges:

    Stored neighbour entries = 2 x 6
                             = 12

This is usually much smaller than O(n^2) for a sparse graph.

Extra Note:
Both forms are commonly written:

    O(n + 2m)
    O(n + m)

They describe the same asymptotic complexity because constants are ignored.

===============================================================================
8. DIRECTED GRAPH USING ADJACENCY LIST
===============================================================================

In a directed graph, an edge:

    u -> v

means that movement is allowed only from u to v.

Therefore:

    v is an outgoing neighbour of u

But u is not automatically an outgoing neighbour of v.

Store only:

    adjacencyList[u].push_back(v);

Do not store:

    adjacencyList[v].push_back(u);

unless the reverse directed edge:

    v -> u

also exists in the input.

-------------------------------------------------------------------------------
8.1 EXAMPLE
-------------------------------------------------------------------------------

Directed edges:

    1 -> 2
    1 -> 3
    3 -> 4

Adjacency list:

    1 -> 2, 3
    2 -> empty
    3 -> 4
    4 -> empty

C++ code:

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adjacencyList[u].push_back(v);
    }

Only one insertion is done for each directed edge.

-------------------------------------------------------------------------------
8.2 SPACE COMPLEXITY OF DIRECTED ADJACENCY LIST
-------------------------------------------------------------------------------

Each directed edge is stored once.

For m directed edges:

    Number of stored edge entries = m

Including the list container for n nodes:

    Space Complexity = O(n + m)

The lecture focuses on edge storage and describes it as:

    O(m)

Extra Note:
When writing complete graph complexity, O(n + m) is more precise because
storage is also needed for all n vertex lists.

===============================================================================
9. ADJACENCY MATRIX FOR A DIRECTED GRAPH
===============================================================================

For a directed edge:

    u -> v

Mark only:

    matrix[u][v] = 1

Do not automatically mark:

    matrix[v][u] = 1

Example:

For:

    1 -> 3

Store:

    matrix[1][3] = 1
    matrix[3][1] = 0

The matrix of a directed graph does not have to be symmetric.

C++ code:

    vector<vector<int>> matrix(
        n + 1,
        vector<int>(n + 1, 0)
    );

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        matrix[u][v] = 1;
    }

===============================================================================
10. WEIGHTED GRAPH
===============================================================================

A weighted graph contains a weight on every edge.

A weight may represent:

- Distance
- Time
- Cost
- Price
- Network delay
- Difficulty
- Any numerical value related to the connection

Example:

    1 ------- 2
         5

The edge between node 1 and node 2 has weight 5.

For a weighted graph, every input edge normally contains three values:

    u v weight

Example:

    5 6
    1 2 2
    1 3 3
    2 4 1
    3 4 4
    2 5 6
    4 5 3

Here:

    Edge 1 - 2 has weight 2
    Edge 1 - 3 has weight 3
    Edge 2 - 4 has weight 1
    Edge 3 - 4 has weight 4
    Edge 2 - 5 has weight 6
    Edge 4 - 5 has weight 3

General weighted input:

    n m

    u1 v1 weight1
    u2 v2 weight2
    ...
    um vm weightm

===============================================================================
11. WEIGHTED GRAPH USING ADJACENCY MATRIX
===============================================================================

For an unweighted graph, we stored:

    matrix[u][v] = 1

For a weighted graph, store the actual weight instead:

    matrix[u][v] = weight

For an undirected weighted graph:

    matrix[u][v] = weight;
    matrix[v][u] = weight;

Example:

For edge:

    1 - 2

with weight:

    5

Store:

    matrix[1][2] = 5
    matrix[2][1] = 5

-------------------------------------------------------------------------------
11.1 C++ CODE
-------------------------------------------------------------------------------

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(
        n + 1,
        vector<int>(n + 1, 0)
    );

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        matrix[u][v] = weight;
        matrix[v][u] = weight;
    }

For a directed weighted graph, store only:

    matrix[u][v] = weight;

Extra Note:
Using 0 to mean "no edge" works only when valid edge weights are never 0.

If zero-weight edges are possible, use another special value such as:

    -1

or:

    A very large value

depending on the problem.

===============================================================================
12. WEIGHTED GRAPH USING ADJACENCY LIST
===============================================================================

In an unweighted adjacency list, we stored only the neighbour:

    adjacencyList[u].push_back(v);

For a weighted graph, we must store:

1. The neighbour
2. The edge weight

Therefore, use:

    pair<int, int>

The pair stores:

    {neighbour, weight}

C++ declaration:

    vector<vector<pair<int, int>>> adjacencyList(n + 1);

For every node, the list contains pairs.

Example:

If node 4 has these weighted edges:

    4 - 2 with weight 1
    4 - 3 with weight 4
    4 - 5 with weight 3

Then:

    adjacencyList[4] = {
        {2, 1},
        {3, 4},
        {5, 3}
    };

Meaning:

    {2, 1} -> Neighbour 2, weight 1
    {3, 4} -> Neighbour 3, weight 4
    {5, 3} -> Neighbour 5, weight 3

-------------------------------------------------------------------------------
12.1 UNDIRECTED WEIGHTED ADJACENCY LIST
-------------------------------------------------------------------------------

For an undirected weighted edge:

    u - v

with weight:

    weight

Store:

    adjacencyList[u].push_back({v, weight});
    adjacencyList[v].push_back({u, weight});

Example:

For:

    1 - 2

with weight:

    5

Store:

    adjacencyList[1].push_back({2, 5});
    adjacencyList[2].push_back({1, 5});

-------------------------------------------------------------------------------
12.2 COMPLETE C++ CODE
-------------------------------------------------------------------------------

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        adjacencyList[u].push_back({v, weight});
        adjacencyList[v].push_back({u, weight});
    }

-------------------------------------------------------------------------------
12.3 DIRECTED WEIGHTED ADJACENCY LIST
-------------------------------------------------------------------------------

For a directed weighted edge:

    u -> v

with weight:

    weight

Store only:

    adjacencyList[u].push_back({v, weight});

Do not store the reverse edge unless it is separately given.

C++ code:

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        adjacencyList[u].push_back({v, weight});
    }

===============================================================================
13. PRINTING AN ADJACENCY LIST
===============================================================================

To print all neighbours:

    for (int node = 1; node <= n; node++) {
        cout << node << " -> ";

        for (int neighbour : adjacencyList[node]) {
            cout << neighbour << " ";
        }

        cout << '\n';
    }

For a weighted adjacency list:

    for (int node = 1; node <= n; node++) {
        cout << node << " -> ";

        for (pair<int, int> edge : adjacencyList[node]) {
            int neighbour = edge.first;
            int weight = edge.second;

            cout << "(" << neighbour << ", " << weight << ") ";
        }

        cout << '\n';
    }

Extra Note:
Range-based loops can also use references to avoid copying:

    for (const pair<int, int>& edge : adjacencyList[node]) {
        int neighbour = edge.first;
        int weight = edge.second;
    }

===============================================================================
14. ADJACENCY MATRIX VS ADJACENCY LIST
===============================================================================

-------------------------------------------------------------------------------
14.1 ADJACENCY MATRIX
-------------------------------------------------------------------------------

Storage:

    matrix[u][v]

Space:

    O(n^2)

Check whether an edge exists:

    O(1)

Visit all neighbours of one node:

    O(n)

Useful when:

- The graph is dense.
- Fast edge existence checking is needed.
- The number of nodes is small.

Problem:

- Uses a large amount of memory.
- Many cells may remain unused.

-------------------------------------------------------------------------------
14.2 ADJACENCY LIST
-------------------------------------------------------------------------------

Storage:

    adjacencyList[u]

Space:

    O(n + m)

Check whether a specific edge exists:

    O(degree of u)

Visit all neighbours of one node:

    O(degree of u)

Useful when:

- The graph is sparse.
- The number of nodes is large.
- We need BFS, DFS, shortest path, or similar algorithms.

Advantage:

- Stores only actual edges.
- Usually uses much less memory.

-------------------------------------------------------------------------------
14.3 COMPARISON TABLE
-------------------------------------------------------------------------------

Feature                 Adjacency Matrix        Adjacency List
-------------------------------------------------------------------------------
Structure               2D matrix              Array of lists/vectors

Space                    O(n^2)                 O(n + m)

Edge check               O(1)                   O(degree of node)

Neighbour traversal      O(n)                   O(degree of node)

Sparse graph             Usually wasteful       Preferred

Dense graph              Can be useful          Also possible

Undirected edge storage  Two matrix cells        Two list entries

Directed edge storage    One matrix cell         One list entry

Weighted graph           Store weight in cell    Store {node, weight}

Common in algorithms     Less common             Very common

===============================================================================
15. IMPORTANT COMPLEXITIES
===============================================================================

Let:

    n = Number of vertices
    m = Number of edges

Adjacency Matrix:

    Space = O(n^2)

    Matrix initialization = O(n^2)

    Reading and inserting edges = O(m)

    Checking one edge = O(1)

    Traversing neighbours of one node = O(n)

Adjacency List for an undirected graph:

    Edge entries = 2m

    Complete space = O(n + 2m)
                   = O(n + m)

    Reading and inserting edges = O(m)

    Traversing neighbours of node u = O(degree(u))

Adjacency List for a directed graph:

    Edge entries = m

    Complete space = O(n + m)

    Reading and inserting edges = O(m)

===============================================================================
16. COMMON MISTAKES
===============================================================================

Mistake 1:
Forgetting to add the reverse edge in an undirected graph.

Wrong:

    adjacencyList[u].push_back(v);

Correct:

    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);

-------------------------------------------------------------------------------

Mistake 2:
Adding the reverse edge in a directed graph.

For:

    u -> v

Correct:

    adjacencyList[u].push_back(v);

Do not automatically add:

    adjacencyList[v].push_back(u);

-------------------------------------------------------------------------------

Mistake 3:
Using size n for a one-based graph.

For nodes:

    1 to n

Use:

    vector<vector<int>> adjacencyList(n + 1);

-------------------------------------------------------------------------------

Mistake 4:
Using n x m for an adjacency matrix.

An adjacency matrix represents node-to-node connections.

Its dimensions are:

    n x n

For one-based indexing:

    (n + 1) x (n + 1)

-------------------------------------------------------------------------------

Mistake 5:
Storing only the neighbour in a weighted graph.

A weighted list must store:

    {neighbour, weight}

-------------------------------------------------------------------------------

Mistake 6:
Confusing the number of nodes with the number of edges.

Remember:

    n = Number of nodes
    m = Number of edges

The next m lines describe the edges.

-------------------------------------------------------------------------------

Mistake 7:
Assuming edge input follows a fixed order.

Edges can usually be given in any order.

Example:

    1 2
    3 4
    2 5

is valid.

===============================================================================
17. QUICK REVISION
===============================================================================

1. A graph problem usually gives n and m first.

2. n is the number of nodes.

3. m is the number of edges.

4. The next m lines describe the edges.

5. An adjacency matrix uses a two-dimensional matrix.

6. For an unweighted matrix:

       matrix[u][v] = 1

7. For an undirected matrix:

       matrix[u][v] = 1
       matrix[v][u] = 1

8. Adjacency matrix space is O(n^2).

9. An adjacency list stores the neighbours of each node.

10. For an undirected adjacency list:

       adjacencyList[u].push_back(v);
       adjacencyList[v].push_back(u);

11. For a directed adjacency list:

       adjacencyList[u].push_back(v);

12. Undirected adjacency-list edge entries are 2m.

13. Directed adjacency-list edge entries are m.

14. Complete adjacency-list space is O(n + m).

15. A weighted adjacency matrix stores the weight instead of 1.

16. A weighted adjacency list stores pairs:

       {neighbour, weight}

17. Adjacency lists are commonly preferred because they use less space for
    sparse graphs.

===============================================================================
18. SOURCE EXAMPLE CLARIFICATION
===============================================================================

The lecture's main listed input uses these six edges:

    1 - 2
    1 - 3
    2 - 4
    3 - 4
    2 - 5
    4 - 5

During one spoken explanation of the matrix, node 3 and node 5 are also
mentioned together.

The adjacency-list explanation again uses node 2 connected to node 5.

For consistency, this file uses the six edges from the main input list:

    1 - 2
    1 - 3
    2 - 4
    3 - 4
    2 - 5
    4 - 5

===============================================================================
END OF LECTURE NOTES
===============================================================================
*/


// ============================================================================
// PRINT AN ADJACENCY MATRIX
// ============================================================================

void printAdjacencyMatrix(const vector<vector<int>>& matrix, int n) {
    cout << "\nAdjacency Matrix:\n\n";

    cout << "    ";

    for (int node = 1; node <= n; node++) {
        cout << node << " ";
    }

    cout << '\n';

    for (int row = 1; row <= n; row++) {
        cout << row << " : ";

        for (int column = 1; column <= n; column++) {
            cout << matrix[row][column] << " ";
        }

        cout << '\n';
    }
}


// ============================================================================
// PRINT AN UNWEIGHTED ADJACENCY LIST
// ============================================================================

void printAdjacencyList(
    const vector<vector<int>>& adjacencyList,
    int n
) {
    cout << "\nAdjacency List:\n\n";

    for (int node = 1; node <= n; node++) {
        cout << node << " -> ";

        for (int neighbour : adjacencyList[node]) {
            cout << neighbour << " ";
        }

        cout << '\n';
    }
}


// ============================================================================
// PRINT A WEIGHTED ADJACENCY LIST
// ============================================================================

void printWeightedAdjacencyList(
    const vector<vector<pair<int, int>>>& adjacencyList,
    int n
) {
    cout << "\nWeighted Adjacency List:\n\n";

    for (int node = 1; node <= n; node++) {
        cout << node << " -> ";

        for (const pair<int, int>& edge : adjacencyList[node]) {
            int neighbour = edge.first;
            int weight = edge.second;

            cout << "(" << neighbour << ", weight = "
                 << weight << ") ";
        }

        cout << '\n';
    }
}


// ============================================================================
// BUILD AN UNDIRECTED UNWEIGHTED GRAPH
// ============================================================================

void buildUndirectedUnweightedGraph() {
    int n, m;

    /*
    Example input:

    5 6
    1 2
    1 3
    2 4
    3 4
    2 5
    4 5
    */

    cin >> n >> m;

    vector<vector<int>> adjacencyMatrix(
        n + 1,
        vector<int>(n + 1, 0)
    );

    vector<vector<int>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Store the edge in the adjacency matrix.
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;

        // Store the edge in the adjacency list.
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    printAdjacencyMatrix(adjacencyMatrix, n);
    printAdjacencyList(adjacencyList, n);
}


// ============================================================================
// BUILD A DIRECTED UNWEIGHTED GRAPH
// ============================================================================

void buildDirectedUnweightedGraph() {
    int n, m;

    /*
    Example input:

    4 3
    1 2
    1 3
    3 4
    */

    cin >> n >> m;

    vector<vector<int>> adjacencyMatrix(
        n + 1,
        vector<int>(n + 1, 0)
    );

    vector<vector<int>> adjacencyList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Directed edge: u -> v
        adjacencyMatrix[u][v] = 1;
        adjacencyList[u].push_back(v);
    }

    printAdjacencyMatrix(adjacencyMatrix, n);
    printAdjacencyList(adjacencyList, n);
}


// ============================================================================
// BUILD AN UNDIRECTED WEIGHTED GRAPH
// ============================================================================

void buildUndirectedWeightedGraph() {
    int n, m;

    /*
    Example input:

    5 6
    1 2 2
    1 3 3
    2 4 1
    3 4 4
    2 5 6
    4 5 3
    */

    cin >> n >> m;

    vector<vector<int>> weightedMatrix(
        n + 1,
        vector<int>(n + 1, 0)
    );

    vector<vector<pair<int, int>>> weightedList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        // Store in the weighted adjacency matrix.
        weightedMatrix[u][v] = weight;
        weightedMatrix[v][u] = weight;

        // Store in the weighted adjacency list.
        weightedList[u].push_back({v, weight});
        weightedList[v].push_back({u, weight});
    }

    printAdjacencyMatrix(weightedMatrix, n);
    printWeightedAdjacencyList(weightedList, n);
}


// ============================================================================
// BUILD A DIRECTED WEIGHTED GRAPH
// ============================================================================

void buildDirectedWeightedGraph() {
    int n, m;

    /*
    Example input:

    4 4
    1 2 5
    1 3 2
    3 2 1
    3 4 7
    */

    cin >> n >> m;

    vector<vector<int>> weightedMatrix(
        n + 1,
        vector<int>(n + 1, 0)
    );

    vector<vector<pair<int, int>>> weightedList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        // Directed weighted edge: u -> v
        weightedMatrix[u][v] = weight;
        weightedList[u].push_back({v, weight});
    }

    printAdjacencyMatrix(weightedMatrix, n);
    printWeightedAdjacencyList(weightedList, n);
}


// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    /*
    Select the type of graph representation to test.

    Enter:

    1 -> Undirected unweighted graph
    2 -> Directed unweighted graph
    3 -> Undirected weighted graph
    4 -> Directed weighted graph

    After selecting the type, enter the graph input.

    Example:

    Input:

    1
    5 6
    1 2
    1 3
    2 4
    3 4
    2 5
    4 5
    */

    int choice;
    cin >> choice;

    if (choice == 1) {
        buildUndirectedUnweightedGraph();
    }
    else if (choice == 2) {
        buildDirectedUnweightedGraph();
    }
    else if (choice == 3) {
        buildUndirectedWeightedGraph();
    }
    else if (choice == 4) {
        buildDirectedWeightedGraph();
    }
    else {
        cout << "Invalid graph type.\n";
    }

    return 0;
}