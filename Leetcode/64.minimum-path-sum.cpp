#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 64: MINIMUM PATH SUM
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

Given an m x n grid filled with non-negative integers,
find a path from top-left (0,0) to bottom-right (m-1,n-1)
which minimizes the sum.

Allowed moves:
👉 Right
👉 Down

-----------------------------------------------------------
🧠 CORE IDEA
-----------------------------------------------------------

At each cell (i,j):
You can come from:
- Top → (i-1, j)
- Left → (i, j-1)

-----------------------------------------------------------
RECURRENCE:
-----------------------------------------------------------

f(i,j) = grid[i][j] + min(
            f(i-1,j),
            f(i,j-1)
        )

-----------------------------------------------------------
BASE CASE:
-----------------------------------------------------------

f(0,0) = grid[0][0]

===========================================================
*/


/*
===========================================================
🔴 APPROACH 1: RECURSION (BRUTE FORCE)
===========================================================

TIME: O(2^(m+n)) ❌
SPACE: O(m+n)
*/

int solve_rec(int i, int j, vector<vector<int>>& grid) {

    if (i == 0 && j == 0) return grid[0][0];

    if (i < 0 || j < 0) return 1e9; // large value

    int up = solve_rec(i-1, j, grid);
    int left = solve_rec(i, j-1, grid);

    return grid[i][j] + min(up, left);
}



/*
===========================================================
🟠 APPROACH 2: MEMOIZATION (TOP-DOWN DP)
===========================================================

TIME: O(m*n)
SPACE: O(m*n) + recursion stack
*/

int solve_memo(int i, int j,
               vector<vector<int>>& grid,
               vector<vector<int>>& dp) {

    if (i == 0 && j == 0) return grid[0][0];

    if (i < 0 || j < 0) return 1e9;

    if (dp[i][j] != -1) return dp[i][j];

    int up = solve_memo(i-1, j, grid, dp);
    int left = solve_memo(i, j-1, grid, dp);

    return dp[i][j] = grid[i][j] + min(up, left);
}

int minPathSum_memo(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solve_memo(m-1, n-1, grid, dp);
}



/*
===========================================================
🟡 APPROACH 3: TABULATION (BOTTOM-UP DP)
===========================================================

TIME: O(m*n)
SPACE: O(m*n)
*/

int minPathSum_tab(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            }
            else {
                int up = (i > 0) ? dp[i-1][j] : 1e9;
                int left = (j > 0) ? dp[i][j-1] : 1e9;

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }

    return dp[m-1][n-1];
}



/*
===========================================================
🟢 APPROACH 4: SPACE OPTIMIZATION
===========================================================

TIME: O(m*n)
SPACE: O(n)
*/

int minPathSum_optimal(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++) {

        vector<int> curr(n, 0);

        for (int j = 0; j < n; j++) {

            if (i == 0 && j == 0) {
                curr[j] = grid[i][j];
            }
            else {
                int up = (i > 0) ? prev[j] : 1e9;
                int left = (j > 0) ? curr[j-1] : 1e9;

                curr[j] = grid[i][j] + min(up, left);
            }
        }

        prev = curr;
    }

    return prev[n-1];
}



/*
===========================================================
🧠 COMPLEXITY SUMMARY
===========================================================

| Approach       | Time   | Space |
|---------------|--------|-------|
| Recursion     | Exp ❌ |
| Memoization   | O(m*n) |
| Tabulation    | O(m*n) |
| Optimized     | O(m*n) | O(n)  |

===========================================================
*/


/*
===========================================================
🔥 INTERVIEW INSIGHTS
===========================================================

✔ Same pattern as Unique Paths
✔ Only difference:
   → Instead of counting paths → minimize cost

-----------------------------------------------------------
🧠 PATTERN:
-----------------------------------------------------------

👉 Grid DP + Optimization

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    cout << "Recursion: "
         << solve_rec(2,2,grid) << endl;

    cout << "Memoization: "
         << minPathSum_memo(grid) << endl;

    cout << "Tabulation: "
         << minPathSum_tab(grid) << endl;

    cout << "Space Optimized: "
         << minPathSum_optimal(grid) << endl;

    return 0;
}