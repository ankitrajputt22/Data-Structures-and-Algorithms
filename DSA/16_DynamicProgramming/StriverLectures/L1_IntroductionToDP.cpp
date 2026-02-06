#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* -------------------------------------------------
   1. Simple Recursion (Exponential Time)
   Time: O(2^n), Space: O(n)
------------------------------------------------- */
int fibRecursion(int n) {
    if (n <= 1) return n;
    return fibRecursion(n - 1) + fibRecursion(n - 2);
}

/* -------------------------------------------------
   2. Memoization (Top-Down DP)
   Time: O(n), Space: O(n)
------------------------------------------------- */
int fibMemo(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];

    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}

/* -------------------------------------------------
   3. Tabulation (Bottom-Up DP)
   Time: O(n), Space: O(n)
------------------------------------------------- */
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

/* -------------------------------------------------
   4. Space Optimization
   Time: O(n), Space: O(1)
------------------------------------------------- */
int fibSpaceOptimized(int n) {
    if (n <= 1) return n;

    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

/* -------------------------------------------------
   Main Function
------------------------------------------------- */
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "\nFibonacci using Recursion: "
         << fibRecursion(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Fibonacci using Memoization: "
         << fibMemo(n, dp) << endl;

    cout << "Fibonacci using Tabulation: "
         << fibTabulation(n) << endl;

    cout << "Fibonacci using Space Optimization: "
         << fibSpaceOptimized(n) << endl;

    return 0;
}
