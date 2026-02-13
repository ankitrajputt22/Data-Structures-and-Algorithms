#include <bits/stdc++.h>
#include <iostream>
using namespace std;


/*
====================================================
INTRODUCTION TO DYNAMIC PROGRAMMING (DP)
USING FIBONACCI SEQUENCE
====================================================

----------------------------------------------------
WHAT IS DYNAMIC PROGRAMMING?
----------------------------------------------------
Dynamic Programming is an optimization technique
used to solve problems with:

1️⃣ Overlapping Subproblems
2️⃣ Optimal Substructure

Core Mantra:
"Those who cannot remember the past
are condemned to repeat it."

Meaning:
- If a problem recomputes the same subproblems
  again and again, store the result.
- Reuse stored results instead of recomputing.

----------------------------------------------------
WHY FIBONACCI FOR DP?
----------------------------------------------------
Fibonacci is the perfect example because:

fib(n) = fib(n-1) + fib(n-2)

The same values (fib(2), fib(3), fib(4), …)
are computed multiple times in recursion.

----------------------------------------------------
PROGRESSION IN DP (VERY IMPORTANT)
----------------------------------------------------
1️⃣ Recursion (Naive)
2️⃣ Memoization (Top-Down)
3️⃣ Tabulation (Bottom-Up)
4️⃣ Space Optimization

You should ALWAYS think DP in this order.
----------------------------------------------------
*/

/* ==================================================
   1️⃣ RECURSION (NAIVE APPROACH)
================================================== */
/*
----------------------------------------------------
RECURSIVE FIBONACCI
----------------------------------------------------
Logic:
- Directly follows the mathematical definition
- No memory of previous computations

Time Complexity:
O(2^n)  → Exponential

Space Complexity:
O(n) → Recursion stack

Problems:
❌ Very slow
❌ Recomputes same subproblems
----------------------------------------------------
*/
int fibRecursion(int n) {
    if (n <= 1) return n;
    return fibRecursion(n - 1) + fibRecursion(n - 2);
}

/* ==================================================
   2️⃣ MEMOIZATION (TOP-DOWN DP)
================================================== */
/*
----------------------------------------------------
MEMOIZATION (TOP-DOWN APPROACH)
----------------------------------------------------
Idea:
- Store results of recursive calls
- If result already exists, reuse it

Implementation Steps:
1) Create dp array of size n+1 initialized with -1
2) Before recursive call, check dp[n]
3) Store result before returning

Time Complexity:
O(n) → Each state computed once

Space Complexity:
O(n) → DP array
O(n) → Recursion stack
Total = O(n) + O(n)
----------------------------------------------------
*/
int fibMemo(int n, vector<int> &dp) {
    if (n <= 1) return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

/* ==================================================
   3️⃣ TABULATION (BOTTOM-UP DP)
================================================== */
/*
----------------------------------------------------
TABULATION (BOTTOM-UP APPROACH)
----------------------------------------------------
Idea:
- Start from base cases
- Build solution iteratively

Implementation Steps:
1) Create dp array of size n+1
2) Set base cases:
   dp[0] = 0
   dp[1] = 1
3) Fill dp table iteratively

Time Complexity:
O(n)

Space Complexity:
O(n)

Advantage:
✔ No recursion stack
----------------------------------------------------
*/
int fibTabulation(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/* ==================================================
   4️⃣ SPACE OPTIMIZATION
================================================== */
/*
----------------------------------------------------
SPACE OPTIMIZED DP
----------------------------------------------------
Observation:
To compute dp[i], we only need:
- dp[i-1]
- dp[i-2]

So we don't need the entire dp array.

Logic:
prev2 → dp[i-2]
prev  → dp[i-1]
cur   → dp[i]

Update:
cur = prev + prev2
prev2 = prev
prev = cur

Time Complexity:
O(n)

Space Complexity:
O(1)
----------------------------------------------------
*/
int fibSpaceOptimized(int n) {
    if (n <= 1) return n;

    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++) {
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

/*
====================================================
SUMMARY TABLE (VERY IMPORTANT FOR INTERVIEWS)
====================================================

Approach        Strategy      Time        Space
------------------------------------------------
Recursion       Naive         O(2^n)      O(n)
Memoization     Top-Down      O(n)        O(n)+O(n)
Tabulation      Bottom-Up     O(n)        O(n)
Space Optimized Bottom-Up     O(n)        O(1)

----------------------------------------------------
BEST PRACTICE RULES (IMPORTANT NOTES)
----------------------------------------------------
✔ Always try to convert recursion to DP
✔ Memoization removes repeated work
✔ Tabulation removes recursion stack
✔ Space optimization is final polish
✔ NEVER start DP directly — start from recursion

----------------------------------------------------
INTERVIEW TIP
----------------------------------------------------
If asked:
"Explain DP using Fibonacci"

Answer:
"I will first write the recursive solution,
then optimize it using memoization,
convert it to tabulation,
and finally apply space optimization."

====================================================
END OF DP INTRODUCTION
====================================================
*/

int main() {
    int n;
    cin >> n;

    cout << "Recursion: " << fibRecursion(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Memoization: " << fibMemo(n, dp) << endl;

    cout << "Tabulation: " << fibTabulation(n) << endl;

    cout << "Space Optimized: " << fibSpaceOptimized(n) << endl;

    return 0;
}
