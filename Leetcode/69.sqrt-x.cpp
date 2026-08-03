#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 69: SQRT(x)
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

Given a non-negative integer x,
👉 return the integer square root of x

i.e. floor(sqrt(x))

-----------------------------------------------------------
🧠 EXAMPLE
-----------------------------------------------------------

x = 8
sqrt(8) = 2.828...
Answer = 2

===========================================================
🔴 APPROACH 1: LINEAR SEARCH (BRUTE FORCE)
===========================================================

👉 Try all numbers from 1 → x

TIME: O(x) ❌
*/

int mySqrt_linear(int x) {

    int ans = 0;

    for (long long i = 1; i <= x; i++) {
        if (i * i <= x) ans = i;
        else break;
    }

    return ans;
}



/*
===========================================================
🟠 APPROACH 2: BINARY SEARCH (BEST)
===========================================================

👉 Search in range [1, x]

-----------------------------------------------------------
🧠 IDEA:
-----------------------------------------------------------

If mid * mid <= x → move right
Else → move left

-----------------------------------------------------------
⚠️ IMPORTANT:
-----------------------------------------------------------

Use long long to avoid overflow

TIME: O(log x)
*/

int mySqrt_binary(int x) {

    if (x == 0 || x == 1) return x;

    int low = 1, high = x;
    int ans = 0;

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        if (mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}



/*
===========================================================
🟡 APPROACH 3: USING DIVISION (SAFE FROM OVERFLOW)
===========================================================

Instead of mid*mid <= x
👉 use mid <= x/mid

TIME: O(log x)
*/

int mySqrt_safe(int x) {

    if (x == 0 || x == 1) return x;

    int low = 1, high = x;
    int ans = 0;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (mid <= x / mid) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}



/*
===========================================================
🟢 APPROACH 4: NEWTON METHOD (ADVANCED)
===========================================================

Formula:
x = (x + n/x) / 2

Fast convergence

TIME: O(log n)
*/

int mySqrt_newton(int x) {

    if (x == 0) return 0;

    double r = x;

    while (r * r > x) {
        r = (r + x / r) / 2;
    }

    return (int)r;
}



/*
===========================================================
🔵 APPROACH 5: USING BUILT-IN (NOT INTERVIEW)
===========================================================

int sqrt(x)

TIME: O(1)
*/

int mySqrt_builtin(int x) {
    return sqrt(x);
}



/*
===========================================================
🧠 COMPLEXITY SUMMARY
===========================================================

| Approach        | Time      | Space |
|----------------|----------|-------|
| Linear         | O(x) ❌   |
| Binary Search  | O(log x) ✅ |
| Safe Division  | O(log x) ✅ |
| Newton Method  | O(log x) 🚀 |
| Built-in       | O(1)     |

===========================================================
*/


/*
===========================================================
🔥 EDGE CASES
===========================================================

1. x = 0 → 0
2. x = 1 → 1
3. Large x → overflow risk

===========================================================
*/


/*
===========================================================
🔥 INTERVIEW INSIGHTS
===========================================================

✔ Always prefer Binary Search
✔ Avoid overflow using:
   → long long
   OR
   → x / mid

-----------------------------------------------------------
🧠 PATTERN:
-----------------------------------------------------------

👉 Binary Search on Answer

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    int x = 8;

    cout << "Linear: " << mySqrt_linear(x) << endl;
    cout << "Binary: " << mySqrt_binary(x) << endl;
    cout << "Safe Binary: " << mySqrt_safe(x) << endl;
    cout << "Newton: " << mySqrt_newton(x) << endl;
    cout << "Built-in: " << mySqrt_builtin(x) << endl;

    return 0;
}