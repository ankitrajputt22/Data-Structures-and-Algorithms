#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: INTRODUCTION TO RECURSION
===========================================================

-----------------------------------------------------------
🔹 WHAT IS RECURSION?
-----------------------------------------------------------

Recursion is when a function calls itself until a specified
condition is met.

In simple words:
👉 A function solving a problem by calling itself
   on a smaller version of the same problem.

-----------------------------------------------------------
🔹 INFINITE RECURSION
-----------------------------------------------------------

If no stopping condition is provided, the function will keep
calling itself forever (or until memory runs out).

This leads to:
👉 Program crash

-----------------------------------------------------------
🔹 STACK OVERFLOW
-----------------------------------------------------------

Each function call uses stack memory.

Since recursive calls are not completed immediately,
they keep stacking up.

When stack memory limit is exceeded:
👉 Stack Overflow / Segmentation Fault occurs

-----------------------------------------------------------
🔹 THE BASE CASE
-----------------------------------------------------------

To stop recursion, we define a BASE CONDITION.

This is where:
👉 Function stops calling itself
👉 Starts returning back

Example:
if (count == 3) return;

-----------------------------------------------------------
🔹 MECHANISM OF RECURSION
-----------------------------------------------------------

1. Function calls itself
2. Calls keep stacking (going DOWN)
3. Base case is reached
4. Function starts returning (going UP)

-----------------------------------------------------------
🔹 BACKTRACKING
-----------------------------------------------------------

After base case:
👉 All waiting function calls complete execution
👉 They return in reverse order

This process is called BACKTRACKING

-----------------------------------------------------------
🔹 MEMORY MANAGEMENT: STACK SPACE
-----------------------------------------------------------

Stack Space stores:
👉 All function calls that are not yet finished

A function is "waiting" if:
👉 It has called another function
👉 And is waiting for it to return

-----------------------------------------------------------
🔹 RECURSION TREE
-----------------------------------------------------------

A Recursion Tree is a diagram showing:
- Function calls (downward)
- Returns (upward)

It helps:
✔ Understand flow
✔ Count calls
✔ Analyze complexity

-----------------------------------------------------------
🔹 SUMMARY
-----------------------------------------------------------

Recursion  → Function calls itself  
Base Case  → Stops recursion  
Stack      → Stores function calls  
Tree       → Visualizes recursion  

===========================================================
🧠 ADDITIONAL NOTES (IMPORTANT)
===========================================================

✔ Every recursion has 2 parts:
   1. Base Case
   2. Recursive Case

✔ General Structure:

function() {
    if (base condition) return;
    do something;
    function(smaller problem);
}

✔ Types of Recursion:
- Linear Recursion
- Binary Recursion
- Tail Recursion
- Backtracking

===========================================================
*/


/*
===========================================================
🔴 EXAMPLE 1: PRINT 1 TO N (BASIC RECURSION)
===========================================================
*/

void print1toN(int n) {
    if (n == 0) return;   // base case

    print1toN(n - 1);     // recursive call
    cout << n << " ";     // work after recursion (backtracking)
}


/*
===========================================================
🟠 EXAMPLE 2: PRINT N TO 1
===========================================================
*/

void printNto1(int n) {
    if (n == 0) return;

    cout << n << " ";     // work before recursion
    printNto1(n - 1);
}


/*
===========================================================
🟡 EXAMPLE 3: FACTORIAL
===========================================================

n! = n * (n-1)!

Recursion Tree Insight:
5 → 4 → 3 → 2 → 1
*/

int factorial(int n) {
    if (n == 0 || n == 1) return 1;

    return n * factorial(n - 1);
}


/*
===========================================================
🟢 EXAMPLE 4: FIBONACCI (BINARY RECURSION)
===========================================================

f(n) = f(n-1) + f(n-2)

⚠️ Expensive (overlapping subproblems)
*/

int fibonacci(int n) {
    if (n <= 1) return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}


/*
===========================================================
🔵 EXAMPLE 5: RECURSION TREE VISUALIZATION (CONCEPT)
===========================================================

For fibonacci(4):

          4
       /     \
      3       2
    /   \    / \
   2     1  1   0
  / \
 1   0

Shows:
✔ Depth
✔ Number of calls
✔ Overlapping subproblems
*/


/*
===========================================================
🟣 EXAMPLE 6: DEMONSTRATING STACK BEHAVIOR
===========================================================
*/

void stackDemo(int n) {
    if (n == 0) return;

    cout << "Entering: " << n << endl;
    stackDemo(n - 1);
    cout << "Exiting: " << n << endl;
}

/*
OUTPUT for n=3:

Entering: 3
Entering: 2
Entering: 1
Exiting: 1
Exiting: 2
Exiting: 3

👉 Shows BACKTRACKING clearly
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    int n = 5;

    cout << "Print 1 to N:\n";
    print1toN(n);
    cout << "\n\n";

    cout << "Print N to 1:\n";
    printNto1(n);
    cout << "\n\n";

    cout << "Factorial of " << n << ": ";
    cout << factorial(n) << endl;

    cout << "Fibonacci of " << n << ": ";
    cout << fibonacci(n) << endl;

    cout << "\nStack Demo:\n";
    stackDemo(3);

    return 0;
}