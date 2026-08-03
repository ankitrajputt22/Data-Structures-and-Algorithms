/*
    LeetCode 2553. Separate the Digits in an Array

    ---------------------------------------------------------
    Problem:
    Given an array of positive integers nums,
    return an array containing all digits of every number
    in the same order.

    Example:
    nums = [13,25,83,77]

    Output:
    [1,3,2,5,8,3,7,7]
    ---------------------------------------------------------

    =========================================================
    APPROACH 1 : Brute Force using String Conversion
    =========================================================

    Algorithm:
    ----------
    1. Traverse every number in nums.
    2. Convert the number into a string.
    3. Traverse each character of the string.
    4. Convert character back to digit and push into answer.

    Time Complexity:
    O(T)
    where T = total number of digits in all numbers.

    Space Complexity:
    O(T) for answer array.

    Notes:
    ------
    - Very easy to understand.
    - Uses extra string conversion.
    - Clean and beginner friendly.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution_BruteForce {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for (int num : nums) {

            // Convert number to string
            string s = to_string(num);

            // Extract every character
            for (char ch : s) {

                // Convert char digit to integer digit
                ans.push_back(ch - '0');
            }
        }

        return ans;
    }
};


/*
    =========================================================
    APPROACH 2 : Using Mathematical Digit Extraction
    =========================================================

    Algorithm:
    ----------
    1. Traverse every number.
    2. Extract digits using modulus (%) and division (/).
       Example:
       123 ->
       3 = 123 % 10
       2 = 12 % 10
       1 = 1 % 10

    3. Digits come in reverse order.
       Store them temporarily.
    4. Reverse temporary digits and append to answer.

    Time Complexity:
    O(T)

    Space Complexity:
    O(T)

    Notes:
    ------
    - Avoids string conversion.
    - Uses pure mathematics.
    - Slightly more efficient in low-level environments.
*/

class Solution_Math {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for (int num : nums) {

            vector<int> temp;

            // Extract digits in reverse order
            while (num > 0) {

                temp.push_back(num % 10);
                num /= 10;
            }

            // Reverse to maintain original order
            reverse(temp.begin(), temp.end());

            // Add to final answer
            for (int digit : temp) {
                ans.push_back(digit);
            }
        }

        return ans;
    }
};


/*
    =========================================================
    APPROACH 3 : Optimal In-Place Style Mathematical Method
    =========================================================

    Algorithm:
    ----------
    1. Use recursion to directly insert digits
       in correct order.
    2. Divide number until single digit remains.
    3. Push digits during recursion backtracking.

    Example:
    123

    helper(123)
        helper(12)
            helper(1)
            push 2
        push 3

    Result = [1,2,3]

    Time Complexity:
    O(T)

    Space Complexity:
    O(T) due to recursion stack.

    Notes:
    ------
    - Elegant mathematical solution.
    - No string conversion.
    - No reversing required.
    - Maintains order naturally.
*/

class Solution_Optimal {
public:

    void helper(int num, vector<int>& ans) {

        // Base case
        if (num < 10) {
            ans.push_back(num);
            return;
        }

        // Process left part first
        helper(num / 10, ans);

        // Push current last digit
        ans.push_back(num % 10);
    }

    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for (int num : nums) {
            helper(num, ans);
        }

        return ans;
    }
};


/*
    =========================================================
    MAIN FUNCTION
    =========================================================
*/

int main() {

    vector<int> nums = {13, 25, 83, 77};

    /*
        You can test any solution class here:
        1. Solution_BruteForce
        2. Solution_Math
        3. Solution_Optimal
    */

    Solution_Optimal obj;

    vector<int> result = obj.separateDigits(nums);

    cout << "Separated Digits: ";

    for (int digit : result) {
        cout << digit << " ";
    }

    cout << endl;

    return 0;
}