/* lower_bound in C++ STL
1. Basic Usage (Ascending Order)
2. Using lower_bound with Custom Comparator (Descending Order)
3. Finding Insertion Position in a Sorted Array

Short Notes
Requires sorted input (undefined behavior if unsorted).
Works with random-access iterators (vector, array, deque).
For set/map, use their built-in lower_bound (faster).

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

// 1. Basic lower_bound (ascending order)
void example_ascending() {
    vector<int> v = {1, 3, 5, 7, 9};
    auto it = lower_bound(v.begin(), v.end(), 4);
    
    cout << "Ascending example:\n";
    if (it != v.end()) {
        cout << "First element >= 4: " << *it;
    } else {
        cout << "Not found";
    }
    newline2;
}

// 2. lower_bound with custom comparator (descending order)
void example_descending() {
    vector<int> v = {9, 7, 5, 3, 1};
    auto it = lower_bound(v.begin(), v.end(), 4, greater<int>());
    
    cout << "Descending example:\n";
    if (it != v.end()) {
        cout << "First element <= 4: " << *it;
    } else {
        cout << "Not found";
    }
    newline2;
}

// 3. Finding insertion position
void example_insertion() {
    vector<int> v = {10, 20, 30, 40, 50};
    auto it = lower_bound(v.begin(), v.end(), 25);
    
    cout << "Insertion example:\n";
    cout << "Insert 25 at index: " << (it - v.begin());
    newline2;
}

bool comp(int a, int b) {
    return a > b;  // Sort in descending order
}


vector<int> rowAndMaximumOnes_Optimal(vector<vector<int>>& mat) {
    int maxOnes = 0;
    int row = 0;
        
    for (int i = 0; i < mat.size(); i++) {
        // Method 1: If rows are SORTED (use lower_bound)
        auto it = lower_bound(mat[i].begin(), mat[i].end(), 1);
        int cntOnes = mat[i].end() - it;
            
        // Method 2: If rows are UNSORTED (use count)
        // int cntOnes = count(mat[i].begin(), mat[i].end(), 1);
            
        if (cntOnes > maxOnes) {
            maxOnes = cntOnes;
            row = i;
        } else if (cntOnes == maxOnes && i < row) {
            row = i;  // Tiebreaker
        }
    }
    return {row, maxOnes};
}



vector<int> rowAndMaximumOnes_Brute(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    int row = -1;
    int maxOnes = -1;
    for (int i = 0; i < m; i++) {
        int cntOnes = 0;
        for (int j = 0; j < n; j++) {
            cntOnes += mat[i][j];
        }
        
        if (cntOnes > maxOnes) {
            maxOnes = cntOnes;
            row = i;
        }
    }

    return {row, maxOnes};
}


int main() {
    newline1;

    example_ascending();
    example_descending();
    example_insertion();
    return 0;
}