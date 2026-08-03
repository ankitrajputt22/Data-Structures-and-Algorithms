#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 70: CLIMBING STAIRS
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

You are climbing a staircase with n steps.

At each step, you can climb:
👉 1 step OR 2 steps

Goal:
👉 Find number of distinct ways to reach the top

-----------------------------------------------------------
🧠 EXAMPLE
-----------------------------------------------------------

n = 3

Ways:
1+1+1
1+2
2+1

Answer = 3

===========================================================
🧠 CORE IDEA (VERY IMPORTANT)
===========================================================

To reach step n:
👉 You can come from:
   - step (n-1)
   - step (n-2)

-----------------------------------------------------------
RECURRENCE:
-----------------------------------------------------------

f(n) = f(n-1) + f(n-2)

-----------------------------------------------------------
BASE CASE:
-----------------------------------------------------------

f(0) = 1
f(1) = 1

===========================================================
🔴 APPROACH 1: RECURSION (BRUTE FORCE)
===========================================================

TIME: O(2^n) ❌
SPACE: O(n)
*/

int climb_rec(int n) {
    if (n <= 1) return 1;
    return climb_rec(n-1) + climb_rec(n-2);
}



/*
===========================================================
🟠 APPROACH 2: MEMOIZATION (TOP-DOWN DP)
===========================================================

TIME: O(n)
SPACE: O(n)
*/

int climb_memo(int n, vector<int>& dp) {
    if (n <= 1) return 1;

    if (dp[n] != -1) return dp[n];

    return dp[n] = climb_memo(n-1, dp) +
                   climb_memo(n-2, dp);
}

int climbStairs_memo(int n) {
    vector<int> dp(n+1, -1);
    return climb_memo(n, dp);
}



/*
===========================================================
🟡 APPROACH 3: TABULATION (BOTTOM-UP DP)
===========================================================

TIME: O(n)
SPACE: O(n)
*/

int climbStairs_tab(int n) {

    vector<int> dp(n+1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}



/*
===========================================================
🟢 APPROACH 4: SPACE OPTIMIZATION (BEST)
===========================================================

Only last two values needed

TIME: O(n)
SPACE: O(1)
*/

int climbStairs_optimal(int n) {

    if (n <= 1) return 1;

    int prev2 = 1; // f(0)
    int prev1 = 1; // f(1)

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}



/*
===========================================================
🔵 APPROACH 5: MATHEMATICAL (FIBONACCI FORMULA)
===========================================================

Using Binet's Formula

TIME: O(log n) or O(1)
*/

int climbStairs_math(int n) {

    double sqrt5 = sqrt(5);
    double phi = (1 + sqrt5) / 2;
    double psi = (1 - sqrt5) / 2;

    return (int)((pow(phi, n+1) - pow(psi, n+1)) / sqrt5);
}



/*
===========================================================
🧠 COMPLEXITY SUMMARY
===========================================================

| Approach        | Time   | Space |
|----------------|--------|-------|
| Recursion      | O(2^n) ❌ |
| Memoization    | O(n)   | O(n) |
| Tabulation     | O(n)   | O(n) |
| Optimized      | O(n)   | O(1) |
| Math           | O(1)   | O(1) |

===========================================================
*/


/*
===========================================================
🔥 INTERVIEW INSIGHTS
===========================================================

✔ This is Fibonacci pattern
✔ Always optimize to O(1) space
✔ Mention DP + math both

-----------------------------------------------------------
🧠 PATTERN:
-----------------------------------------------------------

👉 1D DP + recurrence

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    int n = 5;

    cout << "Recursion: " << climb_rec(n) << endl;
    cout << "Memoization: " << climbStairs_memo(n) << endl;
    cout << "Tabulation: " << climbStairs_tab(n) << endl;
    cout << "Optimized: " << climbStairs_optimal(n) << endl;
    cout << "Math: " << climbStairs_math(n) << endl;

    return 0;
}