#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
====================================================
TIME COMPLEXITY & SPACE COMPLEXITY — COMPLETE NOTES
(DSA / INTERVIEWS / COMPETITIVE PROGRAMMING)
====================================================

----------------------------------------------------
WHAT IS TIME COMPLEXITY?
----------------------------------------------------
Time Complexity is NOT the actual time (seconds/minutes)
a program takes to execute.

Why?
• Execution time depends on hardware
  (old PC vs modern server)
• Online judges run code on different machines

Definition:
Time Complexity is the RATE at which the execution
time of an algorithm grows with respect to input size N.

----------------------------------------------------
BIG O NOTATION
----------------------------------------------------
• Represented as O(...)
• Describes the UPPER BOUND (worst case)
• Used in interviews and exams

Examples:
O(1), O(N), O(N^2), O(log N), O(N log N)

----------------------------------------------------
THREE ESSENTIAL RULES FOR ANALYSIS
----------------------------------------------------

1️⃣ ALWAYS CONSIDER THE WORST CASE
----------------------------------
If multiple paths exist (if-else, loops),
analyze the path with maximum operations.

Example:
if (x == 0)   → 1 operation
else          → 100 operations
Worst case = 100 operations

----------------------------------------------------

2️⃣ IGNORE CONSTANTS
----------------------------------
When N is large (e.g., 10^5 or 10^6),
constants become insignificant.

Examples:
O(3N)     → O(N)
O(100)    → O(1)
O(4N^3)   → O(N^3)

----------------------------------------------------

3️⃣ IGNORE LOWER ORDER TERMS
----------------------------------
Higher powers dominate growth.

Examples:
O(N^3 + N^2)   → O(N^3)
O(N^2 + N)     → O(N^2)
O(N + log N)   → O(N)

----------------------------------------------------
PRACTICAL TIME COMPLEXITY EXAMPLES
----------------------------------------------------

----------------------------------------------------
1️⃣ LINEAR LOOP
----------------------------------------------------
Code:
for (int i = 1; i <= N; i++) {
    // constant operations
}

Analysis:
• Loop runs N times
• Each iteration = constant work
• Total = O(3N)

After rules:
O(N)

----------------------------------------------------
2️⃣ NESTED LOOP (N × N)
----------------------------------------------------
Code:
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        // constant work
    }
}

Analysis:
• Outer loop = N
• Inner loop = N
• Total operations = N × N

Time Complexity:
O(N^2)

----------------------------------------------------
3️⃣ DEPENDENT NESTED LOOP
----------------------------------------------------
Code:
for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
        // constant work
    }
}

Analysis:
Total iterations:
1 + 2 + 3 + ... + N

Formula:
Sum of first N natural numbers:
N(N + 1) / 2
= (N^2)/2 + N/2

After ignoring constants & lower terms:
O(N^2)

----------------------------------------------------
SPACE COMPLEXITY
----------------------------------------------------
Space Complexity = Memory used by program

Measured using Big O notation because
actual memory (KB/MB) depends on machine.

----------------------------------------------------
COMPONENTS OF SPACE COMPLEXITY
----------------------------------------------------

1️⃣ INPUT SPACE
• Memory used to store input
• Example: input array of size N → O(N)

2️⃣ AUXILIARY SPACE
• Extra space used by algorithm
• Temporary variables
• Extra arrays
• Recursion stack

Total Space Complexity:
Input Space + Auxiliary Space

----------------------------------------------------
BEST PRACTICE RULE (VERY IMPORTANT)
----------------------------------------------------
❌ Never modify input data unless explicitly told.

Why?
• Input may be needed later
• Bad software engineering practice
• Interviewers dislike input manipulation

✔ Always prefer auxiliary space if needed.

----------------------------------------------------
COMPETITIVE PROGRAMMING CONSTRAINTS
----------------------------------------------------
Most online judges can handle:

≈ 10^8 operations per second

Interpretation:
• 1 second  → 10^8 operations
• 2 seconds → 2 × 10^8 operations
• 5 seconds → 5 × 10^8 operations

Guideline:
If N = 10^5
• O(N^2) ❌ (too slow)
• O(N log N) ✅
• O(N) ✅

----------------------------------------------------
COMPLEXITY NOTATIONS OVERVIEW
----------------------------------------------------

O(...)       → Worst Case (Upper Bound)
Ω(...)       → Best Case (Lower Bound)
Θ(...)       → Average Case

In interviews:
👉 Always mention BIG O (worst case)

====================================================
END OF NOTES
====================================================
*/

/* -------------------------------------------------
   SIMPLE CODE EXAMPLES (FOR CONTEXT)
------------------------------------------------- */

// O(N) Time | O(1) Space
int linearExample(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// O(N^2) Time | O(1) Space
int quadraticExample(int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt++;
        }
    }
    return cnt;
}

int main() {

    int n;
    cin >> n;

    cout << "Linear Example Result: "
         << linearExample(n) << endl;

    cout << "Quadratic Example Result: "
         << quadraticExample(n) << endl;

    return 0;
}
