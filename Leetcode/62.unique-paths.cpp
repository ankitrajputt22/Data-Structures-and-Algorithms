#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 62: UNIQUE PATHS
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

A robot is at top-left corner (0,0) of an m x n grid.

It can move:
👉 Right OR Down

Goal:
👉 Count number of unique paths to reach (m-1, n-1)

-----------------------------------------------------------
🧠 KEY OBSERVATION
-----------------------------------------------------------

At any cell (i,j):
👉 You can come from:
   - Top (i-1, j)
   - Left (i, j-1)

-----------------------------------------------------------
RECURRENCE:
-----------------------------------------------------------

f(i,j) = f(i-1,j) + f(i,j-1)

-----------------------------------------------------------
BASE CASE:
-----------------------------------------------------------

f(0,0) = 1

===========================================================
*/


/*
===========================================================
🔴 APPROACH 1: RECURSION (BRUTE FORCE)
===========================================================

TIME: O(2^(m+n))
SPACE: O(m+n)

Very slow → not used in interviews
*/

int solve_rec(int i, int j) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;

    return solve_rec(i-1, j) + solve_rec(i, j-1);
}



/*
===========================================================
🟠 APPROACH 2: MEMOIZATION (TOP-DOWN DP)
===========================================================

TIME: O(m*n)
SPACE: O(m*n) + recursion stack
*/

int solve_memo(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = solve_memo(i-1, j, dp)
                   + solve_memo(i, j-1, dp);
}

int uniquePaths_memo(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve_memo(m-1, n-1, dp);
}



/*
===========================================================
🟡 APPROACH 3: TABULATION (BOTTOM-UP DP)
===========================================================

TIME: O(m*n)
SPACE: O(m*n)
*/

int uniquePaths_tab(int m, int n) {

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Base cases
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}



/*
===========================================================
🟢 APPROACH 4: SPACE OPTIMIZATION
===========================================================

Instead of full 2D dp → use 1D array

TIME: O(m*n)
SPACE: O(n)
*/

int uniquePaths_optimal(int m, int n) {

    vector<int> dp(n, 1);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j-1];
        }
    }

    return dp[n-1];
}



/*
===========================================================
🔵 APPROACH 5: MATHEMATICAL (COMBINATORICS)
===========================================================

Total moves = (m-1) down + (n-1) right

Total steps = (m+n-2)

Choose positions for (m-1) downs:

Answer = C(m+n-2, m-1)

TIME: O(min(m,n))
SPACE: O(1)

BEST APPROACH (INTERVIEW BONUS ⭐)
*/

int uniquePaths_math(int m, int n) {

    int N = m + n - 2;
    int r = min(m-1, n-1);

    double res = 1;

    for (int i = 1; i <= r; i++) {
        res = res * (N - r + i) / i;
    }

    return (int)res;
}



/*
===========================================================
🧠 COMPLEXITY SUMMARY
===========================================================

| Approach       | Time        | Space     |
|---------------|------------|----------|
| Recursion     | O(2^(m+n)) | O(m+n)   |
| Memoization   | O(m*n)     | O(m*n)   |
| Tabulation    | O(m*n)     | O(m*n)   |
| Optimized     | O(m*n)     | O(n)     |
| Math          | O(n)       | O(1)     |

===========================================================
*/


/*
===========================================================
🔥 INTERVIEW INSIGHTS
===========================================================

✔ Always start with recursion → derive DP
✔ Mention space optimization
✔ If interviewer asks optimal → give math solution

-----------------------------------------------------------
🧠 PATTERN:
-----------------------------------------------------------

👉 Grid DP
👉 Count paths
👉 Move constraints (right/down)

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    int m = 3, n = 7;

    cout << "Recursion: " << solve_rec(m-1, n-1) << endl;
    cout << "Memoization: " << uniquePaths_memo(m, n) << endl;
    cout << "Tabulation: " << uniquePaths_tab(m, n) << endl;
    cout << "Space Optimized: " << uniquePaths_optimal(m, n) << endl;
    cout << "Mathematical: " << uniquePaths_math(m, n) << endl;

    return 0;
}