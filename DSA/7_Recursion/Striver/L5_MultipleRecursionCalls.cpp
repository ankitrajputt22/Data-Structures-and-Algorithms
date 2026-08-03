#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: MULTIPLE RECURSION CALLS
===========================================================

-----------------------------------------------------------
🔹 WHAT ARE MULTIPLE RECURSION CALLS?
-----------------------------------------------------------

Previously:
✔ Functions called themselves ONCE

Now:
✔ A function can call itself MULTIPLE times

Example:
return f(n-1) + f(n-2)

-----------------------------------------------------------
🧠 IMPORTANT:
-----------------------------------------------------------

These calls DO NOT happen simultaneously.

Execution is:
1. First recursive call completes fully
2. Then second recursive call starts

===========================================================
🔴 FIBONACCI SEQUENCE
===========================================================

Sequence:
0, 1, 1, 2, 3, 5, 8...

Formula:
f(n) = f(n-1) + f(n-2)

-----------------------------------------------------------
BASE CASE:
-----------------------------------------------------------

if (n <= 1) return n

===========================================================
🔴 NAIVE RECURSION (MULTIPLE CALLS)
===========================================================

This is the pure form of multiple recursion

TIME: O(2^n) ❌ (very slow)
SPACE: O(n)

WHY SLOW?
👉 Recomputes same subproblems again & again
*/

int fib_recursive(int n) {
    if (n <= 1) return n;

    return fib_recursive(n - 1) + fib_recursive(n - 2);
}



/*
===========================================================
🧠 RECURSION TREE (VERY IMPORTANT)
===========================================================

Example: fib(4)

                4
             /     \
           3         2
         /   \     /   \
        2     1   1     0
      /   \
     1     0

-----------------------------------------------------------
OBSERVATION:
-----------------------------------------------------------

fib(2) is calculated multiple times ❌

This is called:
👉 OVERLAPPING SUBPROBLEMS

===========================================================
*/


/*
===========================================================
🟠 OPTIMIZATION: MEMOIZATION (DP)
===========================================================

IDEA:
Store already computed results

TIME: O(n) ✅
SPACE: O(n)
*/

int fib_memo(int n, vector<int>& dp) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
}

int fibonacci_memo(int n) {
    vector<int> dp(n + 1, -1);
    return fib_memo(n, dp);
}



/*
===========================================================
🟡 TABULATION (BOTTOM-UP DP)
===========================================================

Build from base cases

TIME: O(n)
SPACE: O(n)
*/

int fibonacci_tab(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}



/*
===========================================================
🟢 SPACE OPTIMIZATION (BEST)
===========================================================

Only last two values needed

TIME: O(n)
SPACE: O(1)
*/

int fibonacci_optimal(int n) {
    if (n <= 1) return n;

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}



/*
===========================================================
🧠 COMPLEXITY ANALYSIS
===========================================================

Naive Recursion:
TIME: O(2^n)
SPACE: O(n)

DP (Memo/Tab):
TIME: O(n)
SPACE: O(n)

Optimal:
TIME: O(n)
SPACE: O(1)

===========================================================
*/


/*
===========================================================
🔥 KEY TAKEAWAYS
===========================================================

✔ Multiple recursion → branching tree
✔ Leads to exponential complexity
✔ Use DP to optimize

-----------------------------------------------------------
🧠 INTERVIEW INSIGHT:
-----------------------------------------------------------

Whenever you see:
f(n) depends on multiple previous states

👉 Think:
1. Recursion
2. Memoization
3. Tabulation
4. Space optimization

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    int n = 6;

    cout << "Fibonacci of " << n << endl;

    cout << "Naive Recursion: " << fib_recursive(n) << endl;
    cout << "Memoization: " << fibonacci_memo(n) << endl;
    cout << "Tabulation: " << fibonacci_tab(n) << endl;
    cout << "Space Optimized: " << fibonacci_optimal(n) << endl;

    return 0;
}