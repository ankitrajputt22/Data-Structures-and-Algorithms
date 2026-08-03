#include <iostream>
#include <vector>
using namespace std;

/*
    LeetCode 3151: Special Array I

    Problem:
    We are given an array nums.

    An array is special if every pair of adjacent elements
    has different parity.

    Parity means:
    1. Even number
    2. Odd number

    So, nums[i] and nums[i + 1] should not both be even.
    Also, they should not both be odd.

    Return true if nums is special.
    Otherwise return false.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Check every adjacent pair.
    If any adjacent pair has same parity,
    the array is not special.

    Step-by-step algorithm:
    1. Traverse the array from index 0 to n - 2.
    2. For every index i, check nums[i] and nums[i + 1].
    3. Find parity using modulo 2.
    4. If both have same parity, return false.
    5. If loop finishes, return true.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is already simple.
    It checks each adjacent pair once.

------------------------------------------------------------*/
bool isArraySpecialBruteForce(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        int firstParity = nums[i] % 2;
        int secondParity = nums[i + 1] % 2;

        if (firstParity == secondParity) {
            return false;
        }
    }

    return true;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Parity Array

    Basic idea:
    Store parity of every number first.
    Then check adjacent parity values.

    Step-by-step algorithm:
    1. Create a parity array.
    2. Store nums[i] % 2 for every element.
    3. Traverse the parity array.
    4. If two adjacent parity values are same,
       return false.
    5. Otherwise return true.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This approach is easy to understand.
    But it uses extra space.
    For this problem, brute force is actually better in space.

------------------------------------------------------------*/
bool isArraySpecialBetter(vector<int>& nums) {
    int n = nums.size();

    vector<int> parity(n);

    for (int i = 0; i < n; i++) {
        parity[i] = nums[i] % 2;
    }

    for (int i = 0; i < n - 1; i++) {
        if (parity[i] == parity[i + 1]) {
            return false;
        }
    }

    return true;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Bit Operation

    Basic idea:
    Use bit operation to check parity.
    Last bit of even number is 0.
    Last bit of odd number is 1.

    Step-by-step algorithm:
    1. Traverse the array from index 0 to n - 2.
    2. Find parity of nums[i] using nums[i] & 1.
    3. Find parity of nums[i + 1] using nums[i + 1] & 1.
    4. If both parity values are same, return false.
    5. If all adjacent pairs are different,
       return true.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It checks each adjacent pair once.
    It does not use extra space.

------------------------------------------------------------*/
bool isArraySpecialOptimal(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        int firstParity = nums[i] & 1;
        int secondParity = nums[i + 1] & 1;

        if (firstParity == secondParity) {
            return false;
        }
    }

    return true;
}

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
    vector<int> nums = {1, 2, 3, 4};

    bool ans1 = isArraySpecialBruteForce(nums);
    bool ans2 = isArraySpecialBetter(nums);
    bool ans3 = isArraySpecialOptimal(nums);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}