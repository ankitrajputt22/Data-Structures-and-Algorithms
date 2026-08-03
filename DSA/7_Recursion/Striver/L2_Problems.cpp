#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: BASIC RECURSION + INTRO TO BACKTRACKING
===========================================================

-----------------------------------------------------------
🔹 CORE RECURSION CONCEPTS
-----------------------------------------------------------

1. BASE CASE:
The condition that stops recursion.
Without it → infinite recursion → crash.

2. RECURSIVE CALL:
Function calling itself with updated parameters.

3. STACK SPACE:
Each function call is stored in memory until it finishes.
If there are N calls → space complexity = O(N)

-----------------------------------------------------------
🧠 ADDITIONAL INSIGHT:
-----------------------------------------------------------

✔ Think recursion as:
   "Go deep → then come back (backtracking)"

✔ Execution happens in TWO PHASES:
   1. Going DOWN (recursive calls)
   2. Coming UP (backtracking)

✔ Important:
   - Code before recursive call → executes while going DOWN
   - Code after recursive call → executes while coming UP

===========================================================
*/


/*
===========================================================
🔴 PROBLEM 1: PRINT NAME N TIMES
===========================================================

Logic:
- Use counter i
- Print name until i > N

Base Case:
if (i > N) return

Time: O(N)
Space: O(N)
*/

void printName(int i, int n) {
    if (i > n) return;

    cout << "Striver" << endl;
    printName(i + 1, n);
}



/*
===========================================================
🟠 PROBLEM 2: PRINT 1 TO N
===========================================================

Base Case:
if (i > N) return

Flow:
1 → 2 → 3 → ... → N
*/

void print1toN(int i, int n) {
    if (i > n) return;

    cout << i << " ";
    print1toN(i + 1, n);
}



/*
===========================================================
🟡 PROBLEM 3: PRINT N TO 1
===========================================================

Start from N

Base Case:
if (i < 1) return
*/

void printNto1(int i, int n) {
    if (i < 1) return;

    cout << i << " ";
    printNto1(i - 1, n);
}



/*
===========================================================
🟢 PROBLEM 4: PRINT 1 TO N USING BACKTRACKING
===========================================================

IMPORTANT CONCEPT 🚨

Constraint:
Cannot use i + 1 to directly print 1 → N

IDEA:
- First go till base case
- Then print during BACKTRACKING

CALL FLOW:
f(3) → f(2) → f(1) → f(0)
Then prints:
1 → 2 → 3

Key:
Print AFTER recursive call
*/

void print1toN_backtrack(int i, int n) {
    if (i < 1) return;

    print1toN_backtrack(i - 1, n); // go down
    cout << i << " ";              // print while coming up
}



/*
===========================================================
🔵 PROBLEM 5: PRINT N TO 1 USING BACKTRACKING
===========================================================

CHALLENGE SOLUTION 🚀

Constraint:
Cannot use i - 1 directly for printing

IDEA:
Start from i = 1 and go up
Print AFTER recursion to reverse order

CALL FLOW:
f(1) → f(2) → f(3) → f(4)

Then prints:
4 → 3 → 2 → 1
*/

void printNto1_backtrack(int i, int n) {
    if (i > n) return;

    printNto1_backtrack(i + 1, n); // go down
    cout << i << " ";              // backtracking prints reverse
}



/*
===========================================================
🧠 RECURSION FLOW VISUALIZATION
===========================================================

Example: printNto1_backtrack(1,3)

CALL STACK (DOWN):
1 → 2 → 3 → 4 (base case)

BACKTRACK (UP):
print 3
print 2
print 1

OUTPUT: 3 2 1

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    int n = 3;

    cout << "Print Name N times:\n";
    printName(1, n);

    cout << "\nPrint 1 to N:\n";
    print1toN(1, n);

    cout << "\n\nPrint N to 1:\n";
    printNto1(n, n);

    cout << "\n\nPrint 1 to N (Backtracking):\n";
    print1toN_backtrack(n, n);

    cout << "\n\nPrint N to 1 (Backtracking):\n";
    printNto1_backtrack(1, n);

    cout << endl;

    return 0;
}