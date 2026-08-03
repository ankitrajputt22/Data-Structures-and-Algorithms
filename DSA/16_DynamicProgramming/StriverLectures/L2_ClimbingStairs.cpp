#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: CLIMBING STAIRS (DYNAMIC PROGRAMMING)
===========================================================

-----------------------------------------------------------
🔹 THE PROBLEM: COUNT WAYS TO REACH THE Nth STAIR
-----------------------------------------------------------

You are given N stairs. Initially, you are at the 0th stair.
Each time, you can climb either 1 step or 2 steps.

Your task is to return the number of distinct ways to reach
the Nth stair.

-----------------------------------------------------------
🔹 SHORTCUT TEMPLATE FOR WRITING DP RECURRENCES
-----------------------------------------------------------

This is a general 3-step strategy for solving DP problems:

1. Represent the problem in terms of index:
   Even if it's not an array, visualize states as indices.
   Example: stairs → index (0 to N)

2. Do all possible "stuffs" on that index:
   Based on problem rules:
   → From any stair, you can jump:
     - 1 step
     - 2 steps

3. Combine results based on goal:
   - Count total ways → SUM
   - Find minimum → MIN()
   - Find maximum → MAX()

-----------------------------------------------------------
🔹 FORMULATING THE RECURRENCE
-----------------------------------------------------------

Let f(n) = number of ways to reach nth stair

To reach nth stair:
- You came from (n-1)th stair (1 step)
- Or from (n-2)th stair (2 steps)

So:

    f(n) = f(n-1) + f(n-2)

-----------------------------------------------------------
🔹 BASE CASES
-----------------------------------------------------------

f(0) = 1   → One way (stay at start)
f(1) = 1   → Only one way (0 → 1)

-----------------------------------------------------------
🔹 RELATION TO FIBONACCI
-----------------------------------------------------------

This is exactly Fibonacci:

F(n) = F(n-1) + F(n-2)

So Climbing Stairs is basically:
👉 Fibonacci with shifted base cases

-----------------------------------------------------------
🔹 OPTIMIZATION TECHNIQUES
-----------------------------------------------------------

1. Memoization (Top-Down)
2. Tabulation (Bottom-Up)
3. Space Optimization

-----------------------------------------------------------
🔹 NOTE ON LARGE INPUTS
-----------------------------------------------------------

If N is extremely large (e.g., 10^18),
O(N) solutions will fail.

Use:
👉 Matrix Exponentiation (O(log N))

===========================================================
🧠 ADDITIONAL NOTES (IMPORTANT FOR INTERVIEWS)
===========================================================

✔ This is the MOST BASIC DP problem
✔ Helps build intuition for:
   - Fibonacci DP
   - Staircase problems
   - 1D DP patterns

✔ Pattern:
   "Count ways → sum of previous states"

✔ Variations:
   - Climb with 1,2,3 steps
   - Min cost climbing stairs
   - Frog jump problems

===========================================================
*/


/*
===========================================================
🔴 APPROACH 1: RECURSION (BRUTE FORCE)
===========================================================

IDEA:
Directly apply recurrence relation

PROBLEM:
Overlapping subproblems → exponential time

TIME: O(2^n)
SPACE: O(n) recursion stack
*/

int climbStairs_rec(int n) {
    if (n <= 1) return 1;
    return climbStairs_rec(n - 1) + climbStairs_rec(n - 2);
}



/*
===========================================================
🟠 APPROACH 2: MEMOIZATION (TOP-DOWN DP)
===========================================================

IDEA:
Store already computed results

TIME: O(n)
SPACE: O(n) + recursion stack
*/

int solveMemo(int n, vector<int>& dp) {
    if (n <= 1) return 1;

    if (dp[n] != -1) return dp[n];

    return dp[n] = solveMemo(n - 1, dp) + solveMemo(n - 2, dp);
}

int climbStairs_memo(int n) {
    vector<int> dp(n + 1, -1);
    return solveMemo(n, dp);
}



/*
===========================================================
🟡 APPROACH 3: TABULATION (BOTTOM-UP DP)
===========================================================

IDEA:
Build solution from base cases

TIME: O(n)
SPACE: O(n)
*/

int climbStairs_tab(int n) {
    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}



/*
===========================================================
🟢 APPROACH 4: SPACE OPTIMIZATION (BEST)
===========================================================

IDEA:
Only last two values are needed

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
🔵 APPROACH 5: MATRIX EXPONENTIATION (ADVANCED)
===========================================================

IDEA:
Fibonacci can be computed in O(log n)

TIME: O(log n)
SPACE: O(1)
*/

class Matrix {
public:
    long long a, b, c, d;
};

Matrix multiply(Matrix m1, Matrix m2) {
    Matrix res;
    res.a = m1.a * m2.a + m1.b * m2.c;
    res.b = m1.a * m2.b + m1.b * m2.d;
    res.c = m1.c * m2.a + m1.d * m2.c;
    res.d = m1.c * m2.b + m1.d * m2.d;
    return res;
}

Matrix power(Matrix base, int n) {
    Matrix result = {1, 0, 0, 1}; // identity

    while (n) {
        if (n % 2) result = multiply(result, base);
        base = multiply(base, base);
        n /= 2;
    }
    return result;
}

int climbStairs_matrix(int n) {
    if (n <= 1) return 1;

    Matrix base = {1, 1, 1, 0};
    Matrix res = power(base, n - 1);

    return res.a;
}



/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    int n = 5;

    cout << "Climbing Stairs for n = " << n << endl;

    cout << "Recursion: " << climbStairs_rec(n) << endl;
    cout << "Memoization: " << climbStairs_memo(n) << endl;
    cout << "Tabulation: " << climbStairs_tab(n) << endl;
    cout << "Space Optimized: " << climbStairs_optimal(n) << endl;
    cout << "Matrix Exponentiation: " << climbStairs_matrix(n) << endl;

    return 0;
}