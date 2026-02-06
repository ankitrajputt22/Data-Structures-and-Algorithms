#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// BFS traversal function
vector<int> bfsTraversal(int start, vector<vector<int>> &adj, int V) {
    vector<bool> visited(V, false);
    vector<int> bfsOrder;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsOrder.push_back(node);

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return bfsOrder;
}

int main() {
    cout << "\n";

    int V = 5; // number of vertices
    vector<vector<int>> adj(V);

    // Creating an undirected graph
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(1);
    adj[4].push_back(2);

    int startNode = 0;
    vector<int> result = bfsTraversal(startNode, adj, V);

    cout << "BFS Traversal starting from node " << startNode << ": ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << "\n\n";

    return 0;
}
