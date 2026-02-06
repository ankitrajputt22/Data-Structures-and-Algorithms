#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

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

    

    newline2;
    return 0;
}