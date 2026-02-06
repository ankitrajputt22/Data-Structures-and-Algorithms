#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 { // Note : If you want to travel diaginally from left side, you can use the key map as (i+j) instead of (i-j)
public:
    void printArr(vector<int> &v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i != v.size() - 1) cout << ", ";
        }
        cout << "]";
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(); 
        int n = mat[0].size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i-j].push_back(mat[i][j]);
            }
        }

        for (auto &it : mp) {
            cout << it.first << "->";
            printArr(it.second);
            cout << endl;
        }

        for (auto &it : mp) {
            sort(it.second.begin(), it.second.end());
        }

        cout << endl << "sorted : " << endl;
        for (auto &it : mp) {
            cout << it.first << "->";
            printArr(it.second);
            cout << endl;
        }

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return mat;
    }
};

int main() {
    
    return 0;
}