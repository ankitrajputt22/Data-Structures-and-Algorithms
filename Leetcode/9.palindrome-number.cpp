#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 9: Palindrome Number

    Problem:
    We are given an integer x.
    We have to check if x is a palindrome number.

    Palindrome number:
    A number is palindrome if it reads the same
    from left to right and right to left.

    Example:
    x = 121
    Reverse of 121 is 121
    So answer is true.

    Example:
    x = -121
    Reverse reading is 121-
    So answer is false.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution using String

    Basic idea:
    Convert the number into a string.
    Reverse the string.
    Compare original string and reversed string.

    Step-by-step algorithm:
    1. Convert x into string.
    2. Store a copy of the string.
    3. Reverse the copied string.
    4. Compare original string and reversed string.
    5. If both are same, return true.
    6. Otherwise return false.

    Time complexity:
    O(d)

    Space complexity:
    O(d)

    Note:
    d is the number of digits.
    This solution is simple.
    But it uses extra string space.

------------------------------------------------------------*/
bool isPalindromeBruteForce(int x) {
    string s = to_string(x);
    string reversedString = s;

    reverse(reversedString.begin(), reversedString.end());

    if (s == reversedString) {
        return true;
    }

    return false;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Digits Array

    Basic idea:
    Store all digits in an array.
    Then compare digits from both ends.

    Step-by-step algorithm:
    1. If x is negative, return false.
    2. Extract digits from x.
    3. Store digits in an array.
    4. Put one pointer at start.
    5. Put one pointer at end.
    6. Compare both digits.
    7. If any pair is different, return false.
    8. Otherwise return true.

    Time complexity:
    O(d)

    Space complexity:
    O(d)

    Note:
    This avoids string conversion.
    But it still uses extra array space.

------------------------------------------------------------*/
bool isPalindromeBetterUsingArray(int x) {
    if (x < 0) {
        return false;
    }

    vector<int> digits;

    if (x == 0) {
        digits.push_back(0);
    }

    while (x > 0) {
        int digit = x % 10;
        digits.push_back(digit);
        x = x / 10;
    }

    int left = 0;
    int right = digits.size() - 1;

    while (left < right) {
        if (digits[left] != digits[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

/*------------------------------------------------------------

    Approach 3: Better Solution by Reversing Full Number

    Basic idea:
    Reverse the full number using math.
    Then compare it with the original number.

    Step-by-step algorithm:
    1. If x is negative, return false.
    2. Store original value of x.
    3. Create reversedNumber as 0.
    4. Extract last digit using x % 10.
    5. Add digit to reversedNumber.
    6. Remove last digit using x / 10.
    7. Repeat until x becomes 0.
    8. Compare original and reversedNumber.
    9. Return true if both are same.

    Time complexity:
    O(d)

    Space complexity:
    O(1)

    Note:
    This is better in space.
    But reversing full number may overflow int.
    So we use long long here.

------------------------------------------------------------*/
bool isPalindromeBetterReverseFull(int x) {
    if (x < 0) {
        return false;
    }

    int original = x;
    long long reversedNumber = 0;

    while (x > 0) {
        int digit = x % 10;
        reversedNumber = reversedNumber * 10 + digit;
        x = x / 10;
    }

    if (original == reversedNumber) {
        return true;
    }

    return false;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution by Reversing Half Number

    Basic idea:
    Reverse only half of the number.
    Then compare first half and reversed second half.

    Why this works:
    For palindrome, first half and second half are same.
    We do not need to reverse the whole number.

    Step-by-step algorithm:
    1. If x is negative, return false.
    2. If x ends with 0 and x is not 0, return false.
    3. Create reversedHalf as 0.
    4. Keep moving last digit of x into reversedHalf.
    5. Stop when x becomes less than or equal to reversedHalf.
    6. For even digit count:
       check x == reversedHalf.
    7. For odd digit count:
       ignore middle digit using reversedHalf / 10.
    8. Return the final result.

    Time complexity:
    O(d / 2)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It does not use string.
    It does not use extra array.
    It also avoids full reverse overflow.

------------------------------------------------------------*/
bool isPalindromeOptimal(int x) {
    if (x < 0) {
        return false;
    }

    if (x != 0 && x % 10 == 0) {
        return false;
    }

    int reversedHalf = 0;

    while (x > reversedHalf) {
        int digit = x % 10;
        reversedHalf = reversedHalf * 10 + digit;
        x = x / 10;
    }

    if (x == reversedHalf || x == reversedHalf / 10) {
        return true;
    }

    return false;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal solution.

------------------------------------------------------------*/
class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindromeOptimal(x);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints boolean answer.

------------------------------------------------------------*/
void printAnswer(bool ans) {
    if (ans == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    int x = 121;

    bool ans1 = isPalindromeBruteForce(x);
    bool ans2 = isPalindromeBetterUsingArray(x);
    bool ans3 = isPalindromeBetterReverseFull(x);
    bool ans4 = isPalindromeOptimal(x);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Digits Array:" << endl;
    printAnswer(ans2);

    cout << "Better Solution by Reversing Full Number:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution by Reversing Half Number:" << endl;
    printAnswer(ans4);

    return 0;
}