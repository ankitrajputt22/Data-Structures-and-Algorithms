#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
====================================================
TIME COMPLEXITY & SPACE COMPLEXITY — COMPLETE NOTES
====================================================

-----------------------------------
WHAT IS TIME COMPLEXITY?
-----------------------------------
Time Complexity measures how the execution time of an
algorithm grows as input size (n) increases.

• It does NOT measure time in seconds
• It counts number of operations
• Expressed using Big-O notation
• Focuses on worst-case scenario

-----------------------------------
COMMON TIME COMPLEXITIES
-----------------------------------
O(1)       → Constant Time
O(log n)   → Logarithmic Time
O(n)       → Linear Time
O(n log n) → Linearithmic Time
O(n²)      → Quadratic Time
O(2ⁿ)      → Exponential Time

-----------------------------------
RULES TO CALCULATE TIME COMPLEXITY
-----------------------------------
1) Ignore constants
   O(5n) → O(n)

2) Ignore lower-order terms
   O(n² + n) → O(n²)

3) Single loop → O(n)

4) Nested loops → multiply
   O(n * n) → O(n²)

5) Sequential loops → add
   O(n + n) → O(n)

-----------------------------------
WHAT IS SPACE COMPLEXITY?
-----------------------------------
Space Complexity measures extra memory used
by an algorithm (excluding input size).

Includes:
• Variables
• Arrays
• Dynamic memory
• Recursion stack

-----------------------------------
COMMON SPACE COMPLEXITIES
-----------------------------------
O(1)   → Constant extra space
O(n)   → Extra array / recursion stack
O(n²)  → 2D arrays

-----------------------------------
IMPORTANT INTERVIEW POINTS
-----------------------------------
• Always state worst-case complexity
• Time complexity first, then space
• Recursion always uses stack space
====================================================
*/

/* -------------------------------------------------
   O(1) TIME | O(1) SPACE
------------------------------------------------- */
int constantTimeExample(int arr[]) {
    return arr[0];
}

/* -------------------------------------------------
   O(n) TIME | O(1) SPACE
------------------------------------------------- */
int linearTimeExample(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

/* -------------------------------------------------
   O(n²) TIME | O(1) SPACE
------------------------------------------------- */
void quadraticTimeExample(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/* -------------------------------------------------
   O(n) TIME | O(n) SPACE
------------------------------------------------- */
int linearSpaceExample(int n) {
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = i;
    }
    return temp[n - 1];
}

/* -------------------------------------------------
   O(2^n) TIME | O(n) SPACE
------------------------------------------------- */
int recursiveFibonacci(int n) {
    if (n <= 1) return n;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

/* -------------------------------------------------
   MAIN FUNCTION
------------------------------------------------- */
int main() {

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    cout << "O(1) Time Result: ";
    cout << constantTimeExample(arr) << endl;

    cout << "O(n) Time Result: ";
    cout << linearTimeExample(arr, n) << endl;

    cout << "O(n^2) Time Pattern:\n";
    quadraticTimeExample(3);

    cout << "O(n) Space Result: ";
    cout << linearSpaceExample(n) << endl;

    cout << "O(2^n) Recursive Fibonacci Result: ";
    cout << recursiveFibonacci(n) << endl;

    return 0;
}
