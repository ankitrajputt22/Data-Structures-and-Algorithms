#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
===============================================================================
LECTURE NOTES: INTRODUCTION TO GRAPH
===============================================================================

Lecture Title:
G-1. Introduction to Graph | Types | Different Conventions Used

Lecture Reference:
https://youtu.be/M3_pLsDdeuU

Purpose of this file:
- Learn the basic terms used in graphs.
- Revise the lecture quickly before exams or interviews.
- Keep the lecture content in a clean and readable C++ file.

Main topics:
1. What is a graph?
2. Nodes or vertices
3. Edges
4. Undirected graphs
5. Directed graphs
6. Cycles
7. Directed Acyclic Graphs (DAGs)
8. Paths
9. Degree of a node
10. In-degree and out-degree
11. Edge weights

===============================================================================
1. WHAT IS A GRAPH?
===============================================================================

A graph is a structure made using:

1. Nodes, also called vertices
2. Edges that connect the nodes

A graph does not need to look like a circle or a closed shape.
Any structure containing nodes and edges can be called a graph.

Example:

    1 ----- 2 ----- 3
            |
            4

This is a graph even though it is not a closed structure.

A binary tree can also be viewed as a graph because it has nodes and edges.

Example of a binary tree:

          1
         / \
        2   3
       / \
      4   5

This structure is a tree, but it also satisfies the basic conditions of a graph.

Extra Note:
A tree is a special type of graph.
It is connected and does not contain a cycle.

This fact is useful for understanding the relationship between trees and graphs.

===============================================================================
2. NODES OR VERTICES
===============================================================================

The circular objects shown in a graph are called nodes or vertices.

Both words are commonly used.

Example:

    (1)      (2)      (3)

Here, 1, 2, and 3 represent three nodes.

Nodes are usually numbered so that we can identify them.

There is no compulsory order for numbering the nodes.
The numbering can be chosen in any order.

If a graph has five nodes, we can write:

    Number of vertices = 5

The number of vertices is commonly represented by V.

    V = 5

Extra Note:
Some problems number vertices from 0 to V - 1.

Example:

    0, 1, 2, 3, 4

Other problems number vertices from 1 to V.

Example:

    1, 2, 3, 4, 5

Always check the problem statement before writing code.

===============================================================================
3. EDGES
===============================================================================

A line joining two nodes is called an edge.

Example:

    1 ----- 4

The line between node 1 and node 4 is an edge.

Edges show:

- Which nodes are connected
- How movement is allowed in the graph

The meaning of an edge depends on whether the graph is:

1. Undirected
2. Directed

===============================================================================
4. UNDIRECTED GRAPH
===============================================================================

An undirected graph has edges without arrows.

Example:

    1 ----- 4

The edge can be travelled in both directions:

    1 to 4
    4 to 1

Therefore, an undirected edge between u and v represents both connections:

    u to v
    v to u

The edge is bidirectional.

A larger example:

        1 ----- 2
        |       |
        |       |
        4 ----- 3

Every edge can be used in either direction.

Important terms:

- Node
- Vertex
- Edge
- Undirected edge
- Undirected graph

Extra Note:
In C++, an undirected edge is normally inserted in both adjacency lists.

For an edge between u and v:

    adjacency[u].push_back(v);
    adjacency[v].push_back(u);

This stores both possible directions of movement.

Example:

If there is an edge between 1 and 4:

    adjacency[1].push_back(4);
    adjacency[4].push_back(1);

===============================================================================
5. DIRECTED GRAPH
===============================================================================

A directed graph has edges with arrows.

Such an edge is called a directed edge.

Example:

    1 -----> 4

This means:

    We can move from 1 to 4.
    We cannot automatically move from 4 to 1.

A directed graph is a graph in which all edges are directed.

It is possible to have two separate directed edges between the same pair of
nodes.

Example:

    1 -----> 4
    1 <----- 4

This graph contains:

    One edge from 1 to 4
    One edge from 4 to 1

Together, these two directed edges allow movement in both directions.

However, they are still treated as two separate directed edges.

The two main graph types introduced in the lecture are:

1. Undirected graph
2. Directed graph

Extra Note:
For a directed edge u -> v, C++ normally stores only v inside adjacency[u].

    adjacency[u].push_back(v);

We do not add u inside adjacency[v] unless the reverse edge v -> u also exists.

Example:

For the edge:

    1 -> 4

We store:

    adjacency[1].push_back(4);

We do not automatically store:

    adjacency[4].push_back(1);

===============================================================================
6. CYCLES IN A GRAPH
===============================================================================

A cycle is formed when we:

1. Start from a node
2. Follow a sequence of edges
3. Return to the same starting node

Simple definition:

    Start from a node and come back to that node.

Example:

    1 ----- 2
    |       |
    |       |
    4 ----- 3

One cycle is:

    1 -> 2 -> 3 -> 4 -> 1

We started at node 1 and returned to node 1.

A graph can contain more than one cycle.

The word "graph" alone does not mean that the drawing must be closed.

The term "cyclic" specifically tells us that the graph contains a cycle.

-------------------------------------------------------------------------------
6.1 UNDIRECTED CYCLIC GRAPH
-------------------------------------------------------------------------------

If an undirected graph contains at least one cycle, it is called an
undirected cyclic graph.

Example:

    1 ----- 2
     \     /
       3

The following route forms a cycle:

    1 -> 2 -> 3 -> 1

We start from node 1 and return to node 1.

-------------------------------------------------------------------------------
6.2 UNDIRECTED ACYCLIC GRAPH
-------------------------------------------------------------------------------

If an undirected graph contains no cycle, it is called an undirected acyclic
graph.

Example:

    1 ----- 2 ----- 3
            |
            4

There is no valid route that starts from a node and returns to the same node
without incorrectly using the same edge immediately in reverse.

Extra Note:
A connected undirected graph with no cycle is called a tree.

Example:

        1
       / \
      2   3
     /
    4

A collection of disconnected trees is called a forest.

Example:

    1 ----- 2       4 ----- 5
            |
            3

-------------------------------------------------------------------------------
6.3 DIRECTED CYCLIC GRAPH
-------------------------------------------------------------------------------

A directed graph is cyclic when the arrows allow us to start from a node and
return to the same node.

Example:

    1 -----> 2
    ^        |
    |        v
    4 <----- 3

The directed route is:

    1 -> 2 -> 3 -> 4 -> 1

Every arrow is followed in its correct direction.

Therefore, this graph contains a directed cycle.

-------------------------------------------------------------------------------
6.4 DIRECTED ACYCLIC GRAPH
-------------------------------------------------------------------------------

A directed graph that does not contain any directed cycle is called a
Directed Acyclic Graph.

Its common short form is:

    DAG

DAG means:

    D = Directed
    A = Acyclic
    G = Graph

Example:

    1 -----> 2 -----> 4
     \               ^
      -----> 3 -------|

There is no directed path that returns to its starting node.

Therefore, the graph is acyclic.

If we add a suitable directed edge that creates a route back to an earlier
node, the graph becomes a directed cyclic graph.

Extra Note:
DAGs are important in topics such as:

- Topological sorting
- Task scheduling
- Course prerequisites
- Build systems
- Dependency graphs

Simple example:

Suppose task A must finish before task B.

    A -----> B

If B must finish before C:

    A -----> B -----> C

This is a DAG because there is no way to return to an earlier task.

===============================================================================
7. PATH IN A GRAPH
===============================================================================

A path contains a sequence of nodes where each next node is reachable from the
previous node.

For every pair of adjacent nodes written in the path, an edge must exist
between them.

Consider this graph:

    1 ----- 2 ----- 3 ----- 4
                  /
                 5

A valid path is:

    1 -> 2 -> 3 -> 5

Why is it valid?

- There is an edge between 1 and 2.
- There is an edge between 2 and 3.
- There is an edge between 3 and 5.

An invalid sequence is:

    1 -> 3 -> 5

It is invalid because there is no direct edge between 1 and 3.

We cannot jump from one node to another without an edge.

According to the convention used in this lecture, a node should not appear
more than once in a path.

Therefore, this is not treated as a path in the lecture:

    1 -> 2 -> 3 -> 2 -> 1

Node 2 and node 1 appear again.

Extra Note:
Some graph theory books use more detailed words.

Walk:
Vertices and edges may repeat.

Example:

    1 -> 2 -> 3 -> 2 -> 1

Trail:
Edges do not repeat, but a vertex may repeat.

Simple Path:
Vertices do not repeat.

The lecture uses the word "path" in the sense of a simple path.

For coding problems, always follow the definition given in the problem
statement.

===============================================================================
8. DEGREE IN AN UNDIRECTED GRAPH
===============================================================================

For an undirected graph, the degree of a node is the number of edges attached
to that node.

Example:

          2
         / \
        1---3---4
             \
              5

Suppose node 3 is connected to nodes 1, 2, 4, and 5.

Then:

    degree(3) = 4

Every edge touching a node contributes 1 to its degree.

In the lecture example, the degrees were:

    degree(1) = 2
    degree(2) = 2
    degree(3) = 3
    degree(4) = 2
    degree(5) = 3

The total degree was:

    2 + 2 + 3 + 2 + 3 = 12

The graph had 6 edges.

    2 * number of edges
    = 2 * 6
    = 12

Therefore:

    Sum of degrees of all vertices = 2 * Number of edges

Using symbols:

    Sum of all degrees = 2E

Here:

    E = Number of edges

Why does this formula work?

Every undirected edge touches exactly two vertices.

Therefore, every edge contributes 2 to the total degree count.

ASCII view:

    u -------- v

This one edge adds:

    +1 to degree(u)
    +1 to degree(v)

Total contribution of one edge:

    1 + 1 = 2

Extra Note:
This result is often called the Handshaking Lemma.

It is useful for checking whether calculated degrees are correct.

Example:

Suppose the degrees are:

    2, 3, 2, 1

Total degree:

    2 + 3 + 2 + 1 = 8

Therefore:

    2E = 8
    E = 4

The graph should contain 4 edges.

===============================================================================
9. IN-DEGREE AND OUT-DEGREE IN A DIRECTED GRAPH
===============================================================================

For directed graphs, degree is divided into two parts:

1. In-degree
2. Out-degree

-------------------------------------------------------------------------------
9.1 IN-DEGREE
-------------------------------------------------------------------------------

The in-degree of a node is the number of directed edges entering that node.

Example:

    1 -----> 3 <----- 2

Two edges enter node 3.

Therefore:

    in-degree(3) = 2

-------------------------------------------------------------------------------
9.2 OUT-DEGREE
-------------------------------------------------------------------------------

The out-degree of a node is the number of directed edges leaving that node.

Example:

    3 -----> 4

One edge leaves node 3.

Therefore:

    out-degree(3) = 1

Combined example:

    1 -----> 3 <----- 2
             |
             v
             4

For node 3:

    in-degree(3)  = 2
    out-degree(3) = 1

Extra Note:
For every directed graph:

    Sum of all in-degrees = E

and:

    Sum of all out-degrees = E

Each directed edge leaves one node and enters one node.

Therefore, every directed edge contributes:

    1 to the total out-degree
    1 to the total in-degree

Example:

    1 -----> 2
    1 -----> 3
    2 -----> 3

Number of edges:

    E = 3

In-degrees:

    in-degree(1) = 0
    in-degree(2) = 1
    in-degree(3) = 2

Total in-degree:

    0 + 1 + 2 = 3 = E

Out-degrees:

    out-degree(1) = 2
    out-degree(2) = 1
    out-degree(3) = 0

Total out-degree:

    2 + 1 + 0 = 3 = E

===============================================================================
10. EDGE WEIGHTS
===============================================================================

An edge may contain a value called its weight.

Example:

    1 ----- 2
        5

The edge between node 1 and node 2 has weight 5.

A weight may represent different things depending on the problem.

Examples:

- Distance between two places
- Time needed to travel
- Cost of travelling
- Network delay
- Number of steps
- Any other value attached to a connection

Example of a weighted graph:

          4
    1 -------- 2
    |          |
  7 |          | 3
    |          |
    3 -------- 4
          2

Here:

    weight(1, 2) = 4
    weight(1, 3) = 7
    weight(2, 4) = 3
    weight(3, 4) = 2

Different edges can have different weights.

If a graph problem does not provide edge weights, we generally assume every
edge has unit weight.

    Unit weight = 1

For example:

    1 ----- 2 ----- 3

If no weights are written, we treat the edges as:

    weight(1, 2) = 1
    weight(2, 3) = 1

Extra Note:
In an unweighted graph, the shortest path usually means the path containing
the minimum number of edges.

This is because every edge has an assumed cost of 1.

Example:

Path 1:

    1 -> 2 -> 5

Number of edges = 2

Path 2:

    1 -> 3 -> 4 -> 5

Number of edges = 3

Path 1 is shorter because it uses fewer edges.

===============================================================================
11. QUICK REVISION TABLE
===============================================================================

Term                    Meaning
-------------------------------------------------------------------------------
Graph                   A collection of vertices and edges.

Vertex / Node           A point in the graph.

Edge                    A connection between two vertices.

Undirected edge         Can be travelled in both directions.

Directed edge           Can be travelled only in the arrow's direction.

Cycle                    A route that starts and ends at the same vertex.

Cyclic graph            A graph containing at least one cycle.

Acyclic graph           A graph containing no cycle.

DAG                     Directed Acyclic Graph.

Path                    A reachable sequence of connected vertices.

Degree                   Number of edges attached to an undirected vertex.

In-degree               Number of directed edges entering a vertex.

Out-degree              Number of directed edges leaving a vertex.

Edge weight             A value or cost assigned to an edge.

Unit weight             Weight 1, assumed when no weight is given.

Important formulas:

For an undirected graph:

    Sum of all vertex degrees = 2E

For a directed graph:

    Sum of all in-degrees = E

    Sum of all out-degrees = E

===============================================================================
12. BEGINNER-FRIENDLY C++ IDEAS
===============================================================================

The following examples show how the concepts from the lecture can appear in
C++ programs.

These examples are not complete graph algorithms.

They only demonstrate how graphs can be stored.

-------------------------------------------------------------------------------
12.1 STORE AN UNDIRECTED GRAPH
-------------------------------------------------------------------------------

    int vertices = 5;

    vector<vector<int>> adjacency(vertices + 1);

    int u = 1;
    int v = 4;

    adjacency[u].push_back(v);
    adjacency[v].push_back(u);

Because the graph is undirected, both directions are stored.

For the edge:

    1 ----- 4

We store:

    1 -> 4
    4 -> 1

-------------------------------------------------------------------------------
12.2 STORE A DIRECTED GRAPH
-------------------------------------------------------------------------------

For a directed edge:

    u -----> v

We write:

    adjacency[u].push_back(v);

Only u -> v is stored.

The reverse edge is not added automatically.

Example:

For:

    1 -----> 4

We write:

    adjacency[1].push_back(4);

-------------------------------------------------------------------------------
12.3 STORE A WEIGHTED EDGE
-------------------------------------------------------------------------------

A weighted graph can be stored using pairs.

    vector<vector<pair<int, int>>> weightedGraph(vertices + 1);

Suppose there is an edge from u to v with weight 7.

    int weight = 7;

    weightedGraph[u].push_back({v, weight});

The pair stores:

    {neighbour, edge weight}

Example:

    weightedGraph[1].push_back({4, 7});

This represents:

    1 -----> 4
       weight 7

For an undirected weighted graph, store both directions:

    weightedGraph[u].push_back({v, weight});
    weightedGraph[v].push_back({u, weight});

Extra Note:
Graph representation is normally studied in more detail after the introduction
to graphs.

The examples here only connect the lecture terms with C++ syntax.

===============================================================================
13. FINAL REVISION POINTS
===============================================================================

1. A graph is made of vertices and edges.

2. The number of vertices is commonly written as V.

3. Undirected edges allow movement in both directions.

4. Directed edges allow movement only in the arrow's direction.

5. A graph does not need to form a closed shape.

6. A cycle starts and ends at the same node.

7. An undirected graph containing a cycle is an undirected cyclic graph.

8. A directed graph containing a cycle is a directed cyclic graph.

9. A directed graph with no cycle is called a DAG.

10. Consecutive vertices in a path must be connected by edges.

11. In the lecture's path convention, a vertex is not repeated.

12. In an undirected graph, degree is the number of attached edges.

13. The sum of all degrees in an undirected graph is 2E.

14. Directed graphs use in-degree and out-degree.

15. The sum of all in-degrees in a directed graph is E.

16. The sum of all out-degrees in a directed graph is E.

17. Edge weights represent costs or values on edges.

18. If weights are not given, unit weight 1 is usually assumed.

===============================================================================
END OF LECTURE NOTES
===============================================================================
*/


// ============================================================================
// SMALL COMPILABLE DEMONSTRATION
// ============================================================================

int main() {
    const int vertices = 5;

    /*
    Sample undirected graph:

        1 ----- 2
        |       |
        |       |
        5 ----- 3
         \     /
           4

    Edges:
        1 - 2
        1 - 5
        2 - 3
        3 - 4
        3 - 5
        4 - 5
    */

    vector<vector<int>> graph(vertices + 1);

    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 5},
        {2, 3},
        {3, 4},
        {3, 5},
        {4, 5}
    };

    // Add every undirected edge in both directions.
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int totalDegree = 0;

    cout << "Degrees in the sample undirected graph:\n";

    for (int node = 1; node <= vertices; node++) {
        int degree = static_cast<int>(graph[node].size());

        totalDegree += degree;

        cout << "degree(" << node << ") = " << degree << '\n';
    }

    cout << '\n';

    cout << "Total degree = " << totalDegree << '\n';

    cout << "2 * number of edges = "
         << 2 * edges.size()
         << '\n';

    return 0;
}