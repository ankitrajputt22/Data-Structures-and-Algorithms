#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

/*
🧭 Range Minimum Query (RMQ)

You’re given an array arr[0..n-1] and multiple queries of the form:
“Find the minimum element in the subarray arr[i..j].”

*/

int rangeMinBrute(vector<int>& arr, int L, int R) {
    int mn = INT_MAX;
    for (int i = L; i <= R; i++)
        mn = min(mn, arr[i]);
    return mn;
}


class RangeMinQueryMatrix {
    vector<vector<int>> minTable;
    int n;

public:
    RangeMinQueryMatrix(vector<int>& arr) {
        n = arr.size();
        minTable.assign(n, vector<int>(n, INT_MAX));

        // Build the DP table
        for (int i = 0; i < n; i++) {
            minTable[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                minTable[i][j] = min(minTable[i][j - 1], arr[j]);
            }
        }
    }

    int query(int L, int R) {
        if (L < 0 || R >= n || L > R) return INT_MAX;
        return minTable[L][R];
    }

    void printMatrix() {
        cout << "\nRange Minimum Table (minTable[i][j]):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= j)
                    cout << setw(4) << minTable[i][j];
                else
                    cout << setw(4) << "-";
            }
            cout << "\n";
        }
    }
};

int main() {
    vector<int> arr = {2, 5, 1, 4, 9, 3};
    RangeMinQueryMatrix rmq(arr);

    rmq.printMatrix();

    cout << "\nQuery (1, 4): " << rmq.query(1, 4); // expected 1
    cout << "\nQuery (2, 5): " << rmq.query(2, 5); // expected 1
    cout << "\nQuery (3, 5): " << rmq.query(3, 5); // expected 3
}



