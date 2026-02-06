#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> temp = matrix;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        temp[i][k] = 0;  //row
                    }
                    for (int k = 0; k < m; k++) {
                        temp[k][j] = 0;  //column
                    }
                }
            }
        }

        matrix = temp;
    }
};


class Solution_2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_set<int> row;  // vector<int> row(m, 0);
        unordered_set<int> col;  // vector<int> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);  // row[i] = 1;
                    col.insert(j);  // col[j] = 1;
                }
            }
        }
        /*
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        */

        for (auto r : row) {
            for (int k = 0; k < n; k++) {
                matrix[r][k] = 0;
            }
        }

        for (auto c : col) {
            for (int k = 0; k < m; k++) {
                matrix[k][c] = 0;
            }
        }
    }
};


class Solution_3 {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int col0 = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    
                    if (j == 0) {
                        col0 = 0;
                    } else {
                        mat[0][j] = 0;
                    }
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
        
        if (mat[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                mat[0][j] = 0;
            }
        }
        
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                mat[i][0] = 0;
            }
        }
    }
};

//Binary matrix solution
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    int col0 = 1; // Marker for the first column (0 means set to zero later)

    // Step 1: Traverse the matrix and mark the first row and first column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // Mark the i-th row (use first column)
                matrix[i][0] = 0;
                // Mark the j-th column (use first row)
                if (j != 0) {
                    matrix[0][j] = 0;
                } else {
                    col0 = 0; // Mark the first column separately
                }
            }
        }
    }

    // Step 2: Traverse from (1,1) to (n-1, m-1) and set zeros based on markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // If the row or column is marked, set to zero
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // Step 3: Handle the first row
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 4: Handle the first column
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}


int main() {
    
    return 0;
}