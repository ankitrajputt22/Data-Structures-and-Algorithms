#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
🌀 LEETCODE 54: SPIRAL MATRIX
===========================================================

PROBLEM:
Given an m x n matrix, return all elements in spiral order.

Example:
Input:
1  2  3
4  5  6
7  8  9

Output:
[1,2,3,6,9,8,7,4,5]

-----------------------------------------------------------
APPROACHES COVERED IN THIS FILE:
-----------------------------------------------------------

1. 🔵 Boundary Traversal (Optimal & Most Common)
2. 🟢 Visited Matrix Simulation
3. 🟡 Direction Array Simulation (Cleaner Simulation)

-----------------------------------------------------------
TIME & SPACE SUMMARY:
-----------------------------------------------------------

| Approach                  | Time       | Space       |
|--------------------------|------------|------------|
| Boundary Traversal       | O(m*n)     | O(1)       |
| Visited Matrix           | O(m*n)     | O(m*n)     |
| Direction Simulation     | O(m*n)     | O(1)       |

===========================================================
*/


/*
===========================================================
🔵 APPROACH 1: BOUNDARY TRAVERSAL (BEST APPROACH)
===========================================================

IDEA:
We maintain 4 boundaries:
- top row
- bottom row
- left column
- right column

We traverse in 4 steps:
1. Left → Right (top row)
2. Top → Bottom (right column)
3. Right → Left (bottom row)
4. Bottom → Top (left column)

After each step, shrink boundary.

IMPORTANT:
Always check conditions before traversing bottom & left
to avoid duplicates.

-----------------------------------------------------------
TIME: O(m*n)
SPACE: O(1)
-----------------------------------------------------------
*/

vector<int> spiralOrder_boundary(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0, left = 0;
    int bottom = n - 1, right = m - 1;

    vector<int> ans;

    while (top <= bottom && left <= right) {

        // Step 1: left → right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Step 2: top → bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Step 3: right → left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Step 4: bottom → top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}



/*
===========================================================
🟢 APPROACH 2: VISITED MATRIX (SIMULATION)
===========================================================

IDEA:
- Use a visited matrix to mark visited cells
- Move in directions:
    → ↓ ← ↑
- If next cell is invalid or visited → turn right

-----------------------------------------------------------
TIME: O(m*n)
SPACE: O(m*n)
-----------------------------------------------------------
*/

vector<int> spiralOrder_visited(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // directions: right, down, left, up
    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {1, 0, -1, 0};

    int r = 0, c = 0, dir = 0;
    vector<int> ans;

    for (int i = 0; i < n * m; i++) {
        ans.push_back(matrix[r][c]);
        visited[r][c] = true;

        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
            r = nr;
            c = nc;
        } else {
            dir = (dir + 1) % 4;
            r += dr[dir];
            c += dc[dir];
        }
    }

    return ans;
}



/*
===========================================================
🟡 APPROACH 3: DIRECTION ARRAY (NO VISITED ARRAY)
===========================================================

IDEA:
- Same as simulation but without visited matrix
- We shrink boundaries instead

-----------------------------------------------------------
TIME: O(m*n)
SPACE: O(1)
-----------------------------------------------------------
*/

vector<int> spiralOrder_direction(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    vector<int> ans;
    int dir = 0;

    while (top <= bottom && left <= right) {
        if (dir == 0) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
        }
        else if (dir == 1) {
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
        }
        else if (dir == 2) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        else if (dir == 3) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }

        dir = (dir + 1) % 4;
    }

    return ans;
}



/*
===========================================================
🚀 DRIVER CODE (TESTING)
===========================================================
*/

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };

    vector<int> ans = spiralOrder_boundary(matrix);

    cout << "Spiral Order: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}