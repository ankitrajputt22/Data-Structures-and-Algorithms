#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: FROG JUMP (DYNAMIC PROGRAMMING)
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

A frog is at stair 0 and wants to reach stair N-1.

At each step, it can jump:
👉 1 step OR 2 steps

Energy cost:
|height[i] - height[j]|

Goal:
👉 Minimize total energy

===========================================================
🔴 STEP 1: RECURSION (BRUTE FORCE)
===========================================================

-----------------------------------------------------------
🧠 IDEA:
-----------------------------------------------------------

f(i) = minimum energy to reach stair i

-----------------------------------------------------------
RECURRENCE:
-----------------------------------------------------------

f(i) = min(
    f(i-1) + |h[i] - h[i-1]|,
    f(i-2) + |h[i] - h[i-2]|
)

-----------------------------------------------------------
BASE CASE:
-----------------------------------------------------------

f(0) = 0

===========================================================
*/

int frogJump_rec(int i, vector<int>& h) {
    if (i == 0) return 0;

    int left = frogJump_rec(i - 1, h) + abs(h[i] - h[i - 1]);

    int right = INT_MAX;
    if (i > 1) {
        right = frogJump_rec(i - 2, h) + abs(h[i] - h[i - 2]);
    }

    return min(left, right);
}



/*
===========================================================
🟠 STEP 2: MEMOIZATION (TOP-DOWN DP)
===========================================================

Store computed values to avoid recomputation

TIME: O(N)
SPACE: O(N) + recursion stack
*/

int frogJump_memo(int i, vector<int>& h, vector<int>& dp) {
    if (i == 0) return 0;

    if (dp[i] != -1) return dp[i];

    int left = frogJump_memo(i - 1, h, dp) +
               abs(h[i] - h[i - 1]);

    int right = INT_MAX;
    if (i > 1) {
        right = frogJump_memo(i - 2, h, dp) +
                abs(h[i] - h[i - 2]);
    }

    return dp[i] = min(left, right);
}



/*
===========================================================
🟡 STEP 3: TABULATION (BOTTOM-UP DP)
===========================================================

Build solution iteratively

TIME: O(N)
SPACE: O(N)
*/

int frogJump_tab(vector<int>& h) {
    int n = h.size();
    vector<int> dp(n);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int left = dp[i - 1] + abs(h[i] - h[i - 1]);

        int right = INT_MAX;
        if (i > 1) {
            right = dp[i - 2] + abs(h[i] - h[i - 2]);
        }

        dp[i] = min(left, right);
    }

    return dp[n - 1];
}



/*
===========================================================
🟢 STEP 4: SPACE OPTIMIZATION (BEST)
===========================================================

Only last two states needed

TIME: O(N)
SPACE: O(1)
*/

int frogJump_optimal(vector<int>& h) {
    int n = h.size();

    int prev = 0;   // dp[i-1]
    int prev2 = 0;  // dp[i-2]

    for (int i = 1; i < n; i++) {

        int left = prev + abs(h[i] - h[i - 1]);

        int right = INT_MAX;
        if (i > 1) {
            right = prev2 + abs(h[i] - h[i - 2]);
        }

        int curr = min(left, right);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}



/*
===========================================================
🔵 FOLLOW-UP: FROG JUMP WITH K STEPS
===========================================================

Now frog can jump up to K steps

-----------------------------------------------------------
RECURRENCE:
-----------------------------------------------------------

f(i) = min over j = 1 → k:
    f(i-j) + |h[i] - h[i-j]|

TIME: O(N*K)
SPACE: O(N)
*/

int frogJump_k(vector<int>& h, int k) {
    int n = h.size();
    vector<int> dp(n, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {

        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i],
                            dp[i - j] +
                            abs(h[i] - h[i - j]));
            }
        }
    }

    return dp[n - 1];
}



/*
===========================================================
🧠 COMPLEXITY SUMMARY
===========================================================

| Approach        | Time  | Space |
|----------------|-------|-------|
| Recursion      | O(2^N)| O(N)  |
| Memoization    | O(N)  | O(N)  |
| Tabulation     | O(N)  | O(N)  |
| Optimized      | O(N)  | O(1)  |
| K jumps        | O(N*K)| O(N)  |

===========================================================
*/


/*
===========================================================
🔥 KEY TAKEAWAYS
===========================================================

✔ Think in terms of index
✔ Write recurrence first
✔ Convert recursion → DP
✔ Optimize space if possible

-----------------------------------------------------------
🧠 INTERVIEW INSIGHT:
-----------------------------------------------------------

If problem says:
👉 "min cost to reach end"

Think:
👉 DP with transitions

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<int> heights = {10, 20, 30, 10};

    int n = heights.size();

    cout << "Recursion: "
         << frogJump_rec(n - 1, heights) << endl;

    vector<int> dp(n, -1);
    cout << "Memoization: "
         << frogJump_memo(n - 1, heights, dp) << endl;

    cout << "Tabulation: "
         << frogJump_tab(heights) << endl;

    cout << "Space Optimized: "
         << frogJump_optimal(heights) << endl;

    cout << "K Jump (k=3): "
         << frogJump_k(heights, 3) << endl;

    return 0;
}