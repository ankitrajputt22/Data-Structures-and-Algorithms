#include <iostream>
#include <string>
#include <climits>
#include <unordered_set>
using namespace std;

/*
    LeetCode 8: String to Integer (atoi)

    Problem:
    We are given a string s.
    We have to convert it into a 32-bit signed integer.

    Rules:
    1. Ignore leading spaces.
    2. Check optional '+' or '-' sign.
    3. Read digits until a non-digit character comes.
    4. If no digit is found, return 0.
    5. If number goes below INT_MIN, return INT_MIN.
    6. If number goes above INT_MAX, return INT_MAX.

    32-bit integer range:
    INT_MIN = -2147483648
    INT_MAX =  2147483647
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution using String and stoll

    Basic idea:
    Extract the valid number part as a string.
    Convert it using stoll.
    Then check integer range.

    Step-by-step algorithm:
    1. Skip leading spaces.
    2. Check if sign is '+' or '-'.
    3. Store all continuous digits in a string.
    4. If no digit is found, return 0.
    5. Convert digit string into long long.
    6. Apply sign.
    7. If answer is greater than INT_MAX, return INT_MAX.
    8. If answer is less than INT_MIN, return INT_MIN.
    9. Return answer.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This solution is simple.
    It uses extra string space.
    It also depends on built-in conversion.
    If the number is too large, stoll can throw error.

------------------------------------------------------------*/
int myAtoiBruteForce(string s) {
    int n = s.size();
    int i = 0;

    while (i < n && s[i] == ' ') {
        i++;
    }

    int sign = 1;

    if (i < n && s[i] == '-') {
        sign = -1;
        i++;
    } else if (i < n && s[i] == '+') {
        i++;
    }

    string digits = "";

    while (i < n && s[i] >= '0' && s[i] <= '9') {
        digits.push_back(s[i]);
        i++;
    }

    if (digits.size() == 0) {
        return 0;
    }

    long long number = 0;

    try {
        number = stoll(digits);
    } catch (...) {
        if (sign == 1) {
            return INT_MAX;
        } else {
            return INT_MIN;
        }
    }

    number = number * sign;

    if (number > INT_MAX) {
        return INT_MAX;
    }

    if (number < INT_MIN) {
        return INT_MIN;
    }

    return (int)number;
}

/*------------------------------------------------------------

    Helper function:
    This function checks if a character is a digit.
    This follows the unordered_set style solution.

------------------------------------------------------------*/
bool checkDigitUsingSet(char ch) {
    unordered_set<char> st = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    if (st.find(ch) != st.end()) {
        return true;
    }

    return false;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Long Long and Set Check

    Basic idea:
    Parse the string manually.
    Store result in long long.
    Use overflow check before adding a digit.

    Step-by-step algorithm:
    1. Skip leading spaces.
    2. Check optional sign.
    3. Read digits one by one.
    4. Before adding digit, check overflow.
    5. If positive overflow happens, return INT_MAX.
    6. If negative overflow happens, return INT_MIN.
    7. Otherwise add digit to result.
    8. Return result with sign.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is better than brute force.
    It does not store digits in another string.
    It stops safely when overflow is possible.

------------------------------------------------------------*/
int myAtoiBetterUsingSet(string s) {
    int n = s.length();

    int sign = 1;
    long long res = 0;
    int i = 0;

    while (i < n && s[i] == ' ') {
        i++;
    }

    if (i < n && s[i] == '-') {
        sign = -1;
        i++;
    } else if (i < n && s[i] == '+') {
        i++;
    }

    while (i < n && checkDigitUsingSet(s[i])) {
        int digit = s[i] - '0';

        if (sign == 1 && res > (INT_MAX - digit) / 10) {
            return INT_MAX;
        }

        if (sign == -1 && res > ((long long)INT_MAX + 1 - digit) / 10) {
            return INT_MIN;
        }

        res = res * 10 + digit;
        i++;
    }

    return (int)(res * sign);
}

/*------------------------------------------------------------

    Approach 3: Better Solution using Recursion

    Basic idea:
    First skip spaces and handle sign.
    Then use recursion to process digits.
    Each recursive call handles one digit.

    Step-by-step algorithm:
    1. Skip leading spaces.
    2. Check optional sign.
    3. Call helper function from current index.
    4. If index is out of range, stop.
    5. If current character is not digit, stop.
    6. Check overflow before adding current digit.
    7. Add digit to result.
    8. Recursively process next character.
    9. Return final answer.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This follows the recursive idea.
    It is clean for learning.
    But recursion uses call stack space.
    Iterative solution is better for actual submission.

------------------------------------------------------------*/
int helperRecursive(string& s, int i, int n, int sign, long long res) {
    if (i >= n || s[i] < '0' || s[i] > '9') {
        return (int)(res * sign);
    }

    int digit = s[i] - '0';

    if (sign == 1 && res > (INT_MAX - digit) / 10) {
        return INT_MAX;
    }

    if (sign == -1 && res > ((long long)INT_MAX + 1 - digit) / 10) {
        return INT_MIN;
    }

    return helperRecursive(s, i + 1, n, sign, res * 10 + digit);
}

int myAtoiBetterRecursive(string s) {
    int n = s.size();
    int i = 0;
    int sign = 1;

    while (i < n && s[i] == ' ') {
        i++;
    }

    if (i < n && s[i] == '-') {
        sign = -1;
        i++;
    } else if (i < n && s[i] == '+') {
        i++;
    }

    return helperRecursive(s, i, n, sign, 0);
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Iteration

    Basic idea:
    Parse the string in one pass.
    Use integer result.
    Check overflow before it happens.

    Step-by-step algorithm:
    1. Skip leading spaces.
    2. Check optional sign.
    3. Create result as 0.
    4. Traverse digits.
    5. For every digit, check if result can overflow.
    6. If overflow can happen, return limit value.
    7. Add digit to result.
    8. Return result with sign.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It does not use extra string.
    It does not use recursion.
    It handles overflow safely.

------------------------------------------------------------*/
int myAtoiOptimal(string s) {
    int n = s.size();
    int i = 0;

    while (i < n && s[i] == ' ') {
        i++;
    }

    int sign = 1;

    if (i < n && s[i] == '-') {
        sign = -1;
        i++;
    } else if (i < n && s[i] == '+') {
        i++;
    }

    int res = 0;

    while (i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        if (res > INT_MAX / 10) {
            if (sign == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }

        if (res == INT_MAX / 10) {
            if (sign == 1 && digit > 7) {
                return INT_MAX;
            }

            if (sign == -1 && digit > 8) {
                return INT_MIN;
            }
        }

        res = res * 10 + digit;
        i++;
    }

    return res * sign;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal function.

------------------------------------------------------------*/
class Solution {
public:
    int myAtoi(string s) {
        return myAtoiOptimal(s);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints the answer.

------------------------------------------------------------*/
void printAnswer(int ans) {
    cout << ans << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    string s = "   -042";

    int ans1 = myAtoiBruteForce(s);
    int ans2 = myAtoiBetterUsingSet(s);
    int ans3 = myAtoiBetterRecursive(s);
    int ans4 = myAtoiOptimal(s);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Long Long and Set Check:" << endl;
    printAnswer(ans2);

    cout << "Better Solution using Recursion:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans4);

    return 0;
}