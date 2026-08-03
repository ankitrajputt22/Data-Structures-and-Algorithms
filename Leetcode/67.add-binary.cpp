#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 67: ADD BINARY
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

Given two binary strings a and b,
return their sum as a binary string.

-----------------------------------------------------------
🧠 EXAMPLE
-----------------------------------------------------------

a = "1010", b = "1011"
Output = "10101"

===========================================================
🔴 APPROACH 1: BASIC SIMULATION (BEST)
===========================================================

👉 Traverse from right to left
👉 Add bits + carry
👉 Store result in reverse

TIME: O(n)
SPACE: O(n)
*/

string addBinary(string a, string b) {

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    string ans = "";

    while (i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        ans += (sum % 2) + '0';  // current bit
        carry = sum / 2;         // carry
    }

    reverse(ans.begin(), ans.end());
    return ans;
}



/*
===========================================================
🟠 APPROACH 2: USING STRING BUILDER (FRONT INSERT)
===========================================================

👉 Instead of reversing, insert at front

TIME: O(n^2) ❌ (slow due to shifting)
*/

string addBinary_front(string a, string b) {

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    string ans = "";

    while (i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        ans = char((sum % 2) + '0') + ans;
        carry = sum / 2;
    }

    return ans;
}



/*
===========================================================
🟡 APPROACH 3: USING STACK
===========================================================

👉 Store bits in stack → then pop

TIME: O(n)
SPACE: O(n)
*/

string addBinary_stack(string a, string b) {

    stack<int> st;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {

        int sum = carry;

        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        st.push(sum % 2);
        carry = sum / 2;
    }

    string ans = "";
    while (!st.empty()) {
        ans += (st.top() + '0');
        st.pop();
    }

    return ans;
}



/*
===========================================================
🔵 APPROACH 4: BITWISE (ADVANCED / NOT COMMON)
===========================================================

👉 Convert binary string → integer
👉 Use bitwise addition

❌ NOT SAFE for large inputs (overflow)
*/

string addBinary_bitwise(string a, string b) {

    long long x = stoll(a, 0, 2);
    long long y = stoll(b, 0, 2);

    while (y != 0) {
        long long carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }

    return bitset<64>(x).to_string();
}



/*
===========================================================
🧠 COMPLEXITY SUMMARY
===========================================================

| Approach       | Time | Space |
|---------------|------|-------|
| Simulation    | O(n) | O(n)  |
| Front insert  | O(n^2) ❌ |
| Stack         | O(n) | O(n)  |
| Bitwise       | O(n) | O(1)  |

===========================================================
*/


/*
===========================================================
🔥 EDGE CASES
===========================================================

1. Different lengths:
   "101" + "1"

2. Carry at end:
   "111" + "1" → "1000"

3. All zeros:
   "0" + "0"

===========================================================
*/


/*
===========================================================
🔥 INTERVIEW INSIGHTS
===========================================================

✔ Always simulate binary addition
✔ Use carry variable
✔ Build result in reverse

-----------------------------------------------------------
🧠 PATTERN:
-----------------------------------------------------------

👉 Same as:
   - Plus One
   - Add Strings

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    string a = "1010";
    string b = "1011";

    cout << "Simulation: " << addBinary(a, b) << endl;
    cout << "Front Insert: " << addBinary_front(a, b) << endl;
    cout << "Stack: " << addBinary_stack(a, b) << endl;

    return 0;
}


class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;

        int carry = 0;
        string ans;
        while (i >= 0 || j >= 0) {
            int sum = carry;

            if (i >= 0) sum += a[i] - '0';
            if (j >= 0) sum += b[j] - '0';

            ans += to_string(sum % 2);
            carry = sum > 1 ? 1 : 0;

            i--;
            j--;
        }

        if (carry) ans += to_string(carry);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};