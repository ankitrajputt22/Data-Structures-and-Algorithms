#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
    LeetCode 13: Roman to Integer

    Problem:
    We are given a Roman numeral string s.
    We have to convert it into an integer.

    Roman symbols:
    I -> 1
    V -> 5
    X -> 10
    L -> 50
    C -> 100
    D -> 500
    M -> 1000

    Special cases:
    IV -> 4
    IX -> 9
    XL -> 40
    XC -> 90
    CD -> 400
    CM -> 900
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Check the Roman string from left to right.
    First check special two-character cases.
    If no special case is found, add single character value.

    Step-by-step algorithm:
    1. Create answer as 0.
    2. Traverse the string using index i.
    3. Check if current and next character form a special case.
    4. If yes, add special value and move i by 2.
    5. Otherwise add value of current character.
    6. Move i by 1.
    7. Return answer.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is simple.
    But it checks all special cases manually.

------------------------------------------------------------*/
int romanToIntBruteForce(string s) {
    int n = s.size();
    int ans = 0;
    int i = 0;

    while (i < n) {
        if (i + 1 < n && s[i] == 'I' && s[i + 1] == 'V') {
            ans = ans + 4;
            i = i + 2;
        } else if (i + 1 < n && s[i] == 'I' && s[i + 1] == 'X') {
            ans = ans + 9;
            i = i + 2;
        } else if (i + 1 < n && s[i] == 'X' && s[i + 1] == 'L') {
            ans = ans + 40;
            i = i + 2;
        } else if (i + 1 < n && s[i] == 'X' && s[i + 1] == 'C') {
            ans = ans + 90;
            i = i + 2;
        } else if (i + 1 < n && s[i] == 'C' && s[i + 1] == 'D') {
            ans = ans + 400;
            i = i + 2;
        } else if (i + 1 < n && s[i] == 'C' && s[i + 1] == 'M') {
            ans = ans + 900;
            i = i + 2;
        } else {
            if (s[i] == 'I') {
                ans = ans + 1;
            } else if (s[i] == 'V') {
                ans = ans + 5;
            } else if (s[i] == 'X') {
                ans = ans + 10;
            } else if (s[i] == 'L') {
                ans = ans + 50;
            } else if (s[i] == 'C') {
                ans = ans + 100;
            } else if (s[i] == 'D') {
                ans = ans + 500;
            } else if (s[i] == 'M') {
                ans = ans + 1000;
            }

            i++;
        }
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Hash Map

    Basic idea:
    Store Roman character values in a map.
    If current value is smaller than next value,
    subtract current value.
    Otherwise add current value.

    Why subtract:
    In Roman numbers, smaller value before larger value
    means subtraction.

    Example:
    IV
    I is before V.
    So value is 5 - 1 = 4.

    Step-by-step algorithm:
    1. Create a hash map for Roman values.
    2. Create answer as 0.
    3. Traverse the string from left to right.
    4. Find value of current character.
    5. Find value of next character if it exists.
    6. If current value is smaller than next value,
       subtract current value.
    7. Otherwise add current value.
    8. Return answer.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is better than brute force.
    It avoids checking all special cases manually.

------------------------------------------------------------*/
int romanToIntBetter(string s) {
    unordered_map<char, int> mp;

    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        int currentValue = mp[s[i]];
        int nextValue = 0;

        if (i + 1 < s.size()) {
            nextValue = mp[s[i + 1]];
        }

        if (currentValue < nextValue) {
            ans = ans - currentValue;
        } else {
            ans = ans + currentValue;
        }
    }

    return ans;
}

/*------------------------------------------------------------

    Helper function:
    This function returns value of Roman character.

------------------------------------------------------------*/
int getRomanValue(char ch) {
    if (ch == 'I') {
        return 1;
    }

    if (ch == 'V') {
        return 5;
    }

    if (ch == 'X') {
        return 10;
    }

    if (ch == 'L') {
        return 50;
    }

    if (ch == 'C') {
        return 100;
    }

    if (ch == 'D') {
        return 500;
    }

    if (ch == 'M') {
        return 1000;
    }

    return 0;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Right to Left Traversal

    Basic idea:
    Traverse from right to left.
    Keep previous value.
    If current value is smaller than previous value,
    subtract it.
    Otherwise add it.

    Step-by-step algorithm:
    1. Create answer as 0.
    2. Create previousValue as 0.
    3. Traverse string from right to left.
    4. Find current character value.
    5. If current value is smaller than previous value,
       subtract it from answer.
    6. Otherwise add it to answer.
    7. Update previousValue.
    8. Return answer.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It does not use hash map.
    It checks each character once.

------------------------------------------------------------*/
int romanToIntOptimal(string s) {
    int ans = 0;
    int previousValue = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        int currentValue = getRomanValue(s[i]);

        if (currentValue < previousValue) {
            ans = ans - currentValue;
        } else {
            ans = ans + currentValue;
        }

        previousValue = currentValue;
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Switch Case

    Basic idea:
    Use switch case to get Roman values.
    Then use same left to right subtraction logic.

    Step-by-step algorithm:
    1. Traverse the string from left to right.
    2. Get current value using switch case.
    3. Get next value using switch case.
    4. If current value is smaller than next value,
       subtract current value.
    5. Otherwise add current value.
    6. Return answer.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is also optimal.
    It is simple and avoids unordered_map.

------------------------------------------------------------*/
int getRomanValueSwitch(char ch) {
    switch (ch) {
        case 'I':
            return 1;

        case 'V':
            return 5;

        case 'X':
            return 10;

        case 'L':
            return 50;

        case 'C':
            return 100;

        case 'D':
            return 500;

        case 'M':
            return 1000;
    }

    return 0;
}

int romanToIntOptimalSwitch(string s) {
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        int currentValue = getRomanValueSwitch(s[i]);
        int nextValue = 0;

        if (i + 1 < s.size()) {
            nextValue = getRomanValueSwitch(s[i + 1]);
        }

        if (currentValue < nextValue) {
            ans = ans - currentValue;
        } else {
            ans = ans + currentValue;
        }
    }

    return ans;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal solution.

------------------------------------------------------------*/
class Solution {
public:
    int romanToInt(string s) {
        return romanToIntOptimal(s);
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
    string s = "MCMXCIV";

    int ans1 = romanToIntBruteForce(s);
    int ans2 = romanToIntBetter(s);
    int ans3 = romanToIntOptimal(s);
    int ans4 = romanToIntOptimalSwitch(s);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Hash Map:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution using Right to Left Traversal:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution using Switch Case:" << endl;
    printAnswer(ans4);

    return 0;
}