#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
public:
    void printArr(vector<int> &v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i != v.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> res;
        map<int, vector<int>> mp;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }

        for (auto &it : mp) {
            cout << it.first << "->";
            printArr(it.second);
            cout << endl;
        }

        bool flip = true;
        for(auto &it : mp) {
            if (flip) {
                reverse(it.second.begin(), it.second.end());
            }
            
            for (int &num : it.second) {
                res.push_back(num);
            }
            
            flip = !flip;
        }

        return res;
    }
};


class Solution_2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans(m*n);
        int row = 0, col = 0;
        for (int i = 0; i < m*n; i++) {
            ans[i] = mat[row][col];

            if ((row + col) % 2 == 0) {
                if (col == n-1) row++;
                else if (row == 0) col++;
                else {
                    row--;
                    col++;
                }
            } else {
                if (row == m-1) col++;
                else if (col == 0) row++;
                else {
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
};


int main() {
    
    return 0;
}