#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 66: PLUS ONE
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

You are given a large integer represented as an array of digits.

Each element contains a single digit.

Goal:
👉 Add 1 to the number and return the resulting array.

-----------------------------------------------------------
🧠 EXAMPLE
-----------------------------------------------------------

Input:  [1,2,3]
Output: [1,2,4]

Input:  [9,9,9]
Output: [1,0,0,0]

===========================================================
🔴 APPROACH 1: SIMULATION (RIGHT TO LEFT)
===========================================================

IDEA:
👉 Start from last digit and simulate addition

-----------------------------------------------------------
STEPS:
-----------------------------------------------------------

1. Traverse from end
2. If digit < 9 → increment and return
3. If digit == 9 → make it 0 and carry forward

TIME: O(n)
SPACE: O(1)

===========================================================
*/

vector<int> plusOne(vector<int>& digits) {

    int n = digits.size();

    for (int i = n - 1; i >= 0; i--) {

        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }

        // If 9 → becomes 0
        digits[i] = 0;
    }

    // If all digits were 9
    digits.insert(digits.begin(), 1);

    return digits;
}



/*
===========================================================
🟠 APPROACH 2: USING CARRY VARIABLE
===========================================================

IDEA:
👉 Simulate manual addition with carry

TIME: O(n)
SPACE: O(1)
*/

vector<int> plusOne_carry(vector<int>& digits) {

    int n = digits.size();
    int carry = 1;

    for (int i = n - 1; i >= 0; i--) {

        int sum = digits[i] + carry;

        digits[i] = sum % 10;
        carry = sum / 10;

        if (carry == 0) return digits;
    }

    if (carry) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}



/*
===========================================================
🟡 APPROACH 3: STRING CONVERSION (NOT RECOMMENDED)
===========================================================

IDEA:
👉 Convert to string → number → add 1 → convert back

❌ Problem:
- Overflow for large numbers

Used only for understanding

===========================================================
*/

vector<int> plusOne_string(vector<int>& digits) {

    string num = "";

    for (int d : digits) num += (d + '0');

    // Convert to large number (not safe)
    long long val = stoll(num);
    val += 1;

    string res = to_string(val);

    vector<int> ans;
    for (char c : res) ans.push_back(c - '0');

    return ans;
}



/*
===========================================================
🧠 COMPLEXITY ANALYSIS
===========================================================

| Approach       | Time | Space |
|---------------|------|-------|
| Simulation    | O(n) | O(1)  |
| Carry method  | O(n) | O(1)  |
| String method | O(n) | O(n)  |

===========================================================
*/


/*
===========================================================
🔥 EDGE CASES (VERY IMPORTANT)
===========================================================

1. All 9s:
   [9,9,9] → [1,0,0,0]

2. Single digit:
   [9] → [1,0]

3. No carry:
   [1,2,3] → [1,2,4]

===========================================================
*/


/*
===========================================================
🔥 INTERVIEW INSIGHTS
===========================================================

✔ Always start from last digit
✔ Handle carry properly
✔ Avoid string method (overflow risk)

-----------------------------------------------------------
🧠 PATTERN:
-----------------------------------------------------------

👉 Array simulation of arithmetic

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<int> digits = {9, 9, 9};

    vector<int> result = plusOne(digits);

    cout << "Result: ";
    for (int x : result) cout << x << " ";

    cout << endl;

    return 0;
}