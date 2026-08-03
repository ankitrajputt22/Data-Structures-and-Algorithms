/*
===============================================================
Lecture: Divide Two Integers without Multiplication, Division, or Modulo
Topic: Bit Manipulation & Arithmetic Logic
Source: L9. Divide Two Integers (takeUforward - Striver)
===============================================================



📌 1️⃣ Structured Summary
Core Objective
To divide two integers (dividend and divisor) without using the standard /, *, or % operators. The result must return the quotient (integer part only).


Step-by-Step Breakdown:
Handle Sign: Determine if the result should be negative. Use absolute values for calculation.

Bitwise Estimation:
Find the largest power of 2 (2^n) such that (divisor × 2^n) ≤ dividend.

Subtract (divisor × 2^n) from dividend and add 2^n to the quotient.

Repeat: Continue until dividend < divisor.

Edge Case:
If dividend = −2^31 and divisor = −1, the result 2^31 overflows. Return 2^31 −1.

📊 2️⃣ Format Selection: Comparison Table

Feature                 Brute Force (Linear)            Optimized (Bitwise)
Logic                   Subtract divisor repeatedly     Subtract divisor shifted by powers of 2
Time Complexity         O(Quotient)                     O(log2(Dividend))
Space Complexity        O(1)                            O(1)
Suitability             Small inputs only               Large 32-bit integer inputs


📐 3️⃣ Text-Based Diagram

Dividend: 22, Divisor: 3

Iteration 1:
3 * 2^0 = 3
3 * 2^1 = 6
3 * 2^2 = 12  <-- Largest power of 2 where (3 * 2^n) <= 22
Next (3 * 2^3 = 24) is > 22.
Action: Dividend = 22 - 12 = 10 | Quotient = 0 + 2^2 = 4

Iteration 2:
3 * 2^0 = 3
3 * 2^1 = 6   <-- Largest power of 2 where (3 * 2^n) <= 10
Action: Dividend = 10 - 6 = 4 | Quotient = 4 + 2^1 = 6

Iteration 3:
3 * 2^0 = 3   <-- Largest power of 2 where (3 * 2^n) <= 4
Action: Dividend = 4 - 3 = 1 | Quotient = 6 + 2^0 = 7

Final Quotient: 7 (Since 1 < 3, stop)


✅ 4️⃣ Fact-Check & Errors

Some older tutorials use abs() directly on integers.
In C++, abs(-2147483648) causes overflow.

Correction:
Always convert inputs to 64-bit integers before taking absolute value.


🧠 5️⃣ Extra Academic Value

Key Formula:
Dividend = (Quotient × Divisor) + Remainder

In bitwise terms:
Quotient = Σ(2^n)

Common Mistakes:
Forgetting the sign
Integer overflow at -2^31 / -1

Quick Revision:
Division = repeated subtraction
Optimized Division = subtraction in jumps of 2^n
Complexity = O(log2 N)
Corner case = INT_MIN

Practice Questions:
1. Why is complexity O(log2 N)?
2. Handle divisor 1 or -1?
3. Implement using <<
4. What happens for 7 / -3?

===============================================================
END OF VERBATIM NOTES
===============================================================
*/


#include <iostream>
#include <climits>
using namespace std;


/*
===============================================================
ADDITIONAL EXPLANATION SECTION (Added for Clarity)
===============================================================

Why Bit Manipulation Works:

Instead of subtracting divisor one-by-one:
22 - 3 - 3 - 3 - 3 - 3 - 3 - 3

We subtract in exponential jumps:
22 - 12 (3 * 4)
10 - 6  (3 * 2)
4  - 3  (3 * 1)

This reduces time complexity drastically.

Why Complexity is O(log N):

Each iteration removes the largest possible power of two.
The number of bits in a number N is log2(N).
Hence complexity becomes O(log N).

Why Use long long?

INT_MIN = -2147483648
abs(INT_MIN) overflows because +2147483648
does not fit in signed 32-bit int.

So we convert to 64-bit first.

===============================================================
*/


class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert to 64-bit and take absolute value safely
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long quotient = 0;

        // Main division logic using bit shifting
        while (n >= d) {

            long long temp = d;
            long long multiple = 1;

            // Keep doubling divisor until it exceeds dividend
            while ((temp << 1) <= n) {
                temp <<= 1;       // temp = temp * 2
                multiple <<= 1;   // multiple = multiple * 2
            }

            n -= temp;
            quotient += multiple;
        }

        // Apply sign
        if (isNegative) {
            quotient = -quotient;
        }

        return (int)quotient;
    }
};


/*
===============================================================
MAIN FUNCTION FOR TESTING & LEARNING
===============================================================
*/

int main() {

    Solution sol;

    cout << "Example 1: 22 / 3 = " << sol.divide(22, 3) << endl;
    cout << "Example 2: 7 / -3 = " << sol.divide(7, -3) << endl;
    cout << "Example 3: -15 / 4 = " << sol.divide(-15, 4) << endl;
    cout << "Example 4: INT_MIN / -1 = " << sol.divide(INT_MIN, -1) << endl;

    return 0;
}


/*
===============================================================
ADDITIONAL PRACTICE WALKTHROUGH
===============================================================

Example: 7 / -3

Step 1: Sign
7 positive
-3 negative
Result negative

Step 2: Work with absolute values
7 / 3

3 * 2^1 = 6
7 - 6 = 1

Quotient = 2

Apply sign → -2

===============================================================
FINAL REVISION SUMMARY
===============================================================

✔ No /, *, %
✔ Uses left shift (<<)
✔ Handles overflow
✔ O(log N)
✔ Safe for 32-bit integer range

===============================================================
*/