#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

/*
    LeetCode 7: Reverse Integer

    Problem:
    We are given a signed 32-bit integer x.
    We have to reverse its digits.

    Important:
    If the reversed number goes outside
    the 32-bit integer range, return 0.

    32-bit integer range:
    INT_MIN = -2147483648
    INT_MAX =  2147483647
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution using String

    Basic idea:
    Convert the number into a string.
    Reverse the string digits.
    Convert it back into a number.

    Step-by-step algorithm:
    1. Check if x is negative.
    2. Convert x into string.
    3. Remove the minus sign if x is negative.
    4. Reverse the string.
    5. Convert reversed string into long long.
    6. Add negative sign again if needed.
    7. Check 32-bit integer range.
    8. Return the answer.

    Time complexity:
    O(d)

    Space complexity:
    O(d)

    Note:
    d is the number of digits.
    This solution is simple.
    It uses extra string space.

------------------------------------------------------------*/
int reverseBruteForce(int x) {
    string s = to_string(x);
    bool isNegative = false;

    if (s[0] == '-') {
        isNegative = true;
        s.erase(s.begin());
    }

    reverse(s.begin(), s.end());

    long long ans = 0;

    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - '0');
    }

    if (isNegative == true) {
        ans = -ans;
    }

    if (ans < INT_MIN || ans > INT_MAX) {
        return 0;
    }

    return (int)ans;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Long Long

    Basic idea:
    Reverse the number digit by digit.
    Store the answer in long long.
    Check overflow at the end.

    Step-by-step algorithm:
    1. Create ans as 0.
    2. Run a loop while x is not 0.
    3. Take the last digit using x % 10.
    4. Add digit to ans using ans = ans * 10 + digit.
    5. Remove last digit from x using x / 10.
    6. After the loop, check 32-bit integer range.
    7. If out of range, return 0.
    8. Otherwise return ans.

    Time complexity:
    O(d)

    Space complexity:
    O(1)

    Note:
    This is better than string approach.
    It does not use extra string space.
    But it still uses long long to avoid overflow.

------------------------------------------------------------*/
int reverseBetter(int x) {
    long long ans = 0;

    while (x != 0) {
        int digit = x % 10;
        ans = ans * 10 + digit;
        x = x / 10;
    }

    if (ans < INT_MIN || ans > INT_MAX) {
        return 0;
    }

    return (int)ans;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution

    Basic idea:
    Reverse the number digit by digit.
    Check overflow before it happens.
    Do not use long long.

    Step-by-step algorithm:
    1. Create ans as 0.
    2. Run a loop while x is not 0.
    3. Take the last digit using x % 10.
    4. Check if ans * 10 + digit can overflow.
    5. If overflow is possible, return 0.
    6. Add digit to ans.
    7. Remove last digit from x.
    8. Return ans.

    Time complexity:
    O(d)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It does not use string.
    It does not use long long.
    It handles overflow safely.

------------------------------------------------------------*/
int reverseOptimal(int x) {
    int ans = 0;

    while (x != 0) {
        int digit = x % 10;

        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
            return 0;
        }

        if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8)) {
            return 0;
        }

        ans = ans * 10 + digit;
        x = x / 10;
    }

    return ans;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    int x = 123;

    int ans1 = reverseBruteForce(x);
    int ans2 = reverseBetter(x);
    int ans3 = reverseOptimal(x);

    cout << "Brute Force Solution:" << endl;
    cout << ans1 << endl;

    cout << "Better Solution:" << endl;
    cout << ans2 << endl;

    cout << "Optimal Solution:" << endl;
    cout << ans3 << endl;

    return 0;
}