#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 63: UNIQUE PATHS II (WITH OBSTACLES)
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

You are given an m x n grid.

- 0 → free cell
- 1 → obstacle

You can move:
👉 Right or Down

Goal:
👉 Count number of unique paths from (0,0) to (m-1,n-1)

-----------------------------------------------------------
🧠 KEY DIFFERENCE FROM UNIQUE PATHS I
-----------------------------------------------------------

❗ If cell has obstacle → cannot go there

===========================================================
🔴 APPROACH 1: RECURSION
===========================================================

TIME: O(2^(m+n)) ❌

-----------------------------------------------------------
RECURRENCE:
-----------------------------------------------------------

f(i,j) = 0 (if obstacle)
f(i,j) = f(i-1,j) + f(i,j-1)

===========================================================
*/

int solve_rec(int i, int j, vector<vector<int>>& grid) {

    // Out of bounds
    if (i < 0 || j < 0) return 0;

    // Obstacle
    if (grid[i][j] == 1) return 0;

    // Base case
    if (i == 0 && j == 0) return 1;

    return solve_rec(i-1, j, grid)
         + solve_rec(i, j-1, grid);
}



/*
===========================================================
🟠 APPROACH 2: MEMOIZATION
===========================================================

TIME: O(m*n)
SPACE: O(m*n)
*/

int solve_memo(int i, int j,
               vector<vector<int>>& grid,
               vector<vector<int>>& dp) {

    if (i < 0 || j < 0) return 0;
    if (grid[i][j] == 1) return 0;

    if (i == 0 && j == 0) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] =
        solve_memo(i-1, j, grid, dp) +
        solve_memo(i, j-1, grid, dp);
}

int uniquePathsWithObstacles_memo(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solve_memo(m-1, n-1, grid, dp);
}



/*
===========================================================
🟡 APPROACH 3: TABULATION (BEST STANDARD)
===========================================================

TIME: O(m*n)
SPACE: O(m*n)

-----------------------------------------------------------
IMPORTANT:
-----------------------------------------------------------

- If obstacle → dp[i][j] = 0
- Else → dp[i][j] = top + left

===========================================================
*/

int uniquePathsWithObstacles_tab(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Start position
    if (grid[0][0] == 1) return 0;

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {
                dp[i][j] = 0;
            }
            else {
                if (i > 0) dp[i][j] += dp[i-1][j];
                if (j > 0) dp[i][j] += dp[i][j-1];
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

int uniquePathsWithObstacles_optimal(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector<int> dp(n, 0);

    dp[0] = (grid[0][0] == 0);

    for (int i = 0; i < m; i++) {

        vector<int> curr(n, 0);

        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {
                curr[j] = 0;
            }
            else {
                if (j > 0)
                    curr[j] = curr[j-1];

                if (i > 0)
                    curr[j] += dp[j];
            }
        }

        dp = curr;
    }

    return dp[n-1];
}



/*
===========================================================
🧠 COMPLEXITY SUMMARY
===========================================================

| Approach     | Time   | Space |
|-------------|--------|-------|
| Recursion   | Exponential ❌ |
| Memoization | O(m*n) |
| Tabulation  | O(m*n) |
| Optimized   | O(m*n) | O(n) |

===========================================================
*/


/*
===========================================================
🔥 INTERVIEW INSIGHTS
===========================================================

✔ Always check obstacle first
✔ If starting cell blocked → answer = 0
✔ No math formula possible (due to obstacles)

-----------------------------------------------------------
🧠 PATTERN:
-----------------------------------------------------------

👉 Grid DP + Obstacles

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    cout << "Recursion: "
         << solve_rec(2,2,grid) << endl;

    cout << "Memoization: "
         << uniquePathsWithObstacles_memo(grid) << endl;

    cout << "Tabulation: "
         << uniquePathsWithObstacles_tab(grid) << endl;

    cout << "Space Optimized: "
         << uniquePathsWithObstacles_optimal(grid) << endl;

    return 0;
}