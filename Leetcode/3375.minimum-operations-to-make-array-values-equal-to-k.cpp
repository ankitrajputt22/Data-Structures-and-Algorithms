#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
    LeetCode 3375: Minimum Operations to Make Array Values Equal to K

    Problem:
    We are given an integer array nums.
    We are also given an integer k.

    In one operation:
    1. Choose an integer h.
    2. h is valid if all nums[i] greater than h are equal.
    3. For every nums[i] greater than h, set nums[i] = h.

    We have to make all array values equal to k.

    Return the minimum number of operations.
    If it is impossible, return -1.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Simulate the operations.
    Each time reduce the current largest value.
    Reduce it to the next largest value or to k.

    Step-by-step algorithm:
    1. First check if any value is less than k.
    2. If yes, return -1.
    3. Create operations as 0.
    4. Find the maximum value in nums.
    5. If maximum value is already k, stop.
    6. Find the next largest value smaller than maximum.
    7. If no such value exists, use k.
    8. Change all maximum values to that next value.
    9. Increase operations.
    10. Repeat until all values become k.
    11. Return operations.

    Time complexity:
    O(n * d)

    Space complexity:
    O(1)

    Note:
    n is the size of nums.
    d is the number of different values greater than k.
    This solution is simple.
    But it repeatedly scans the array.

------------------------------------------------------------*/
int minOperationsBruteForce(vector<int> nums, int k) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] < k) {
            return -1;
        }
    }

    int operations = 0;

    while (true) {
        int maxValue = k;

        for (int i = 0; i < n; i++) {
            maxValue = max(maxValue, nums[i]);
        }

        if (maxValue == k) {
            break;
        }

        int nextValue = k;

        for (int i = 0; i < n; i++) {
            if (nums[i] < maxValue && nums[i] > nextValue) {
                nextValue = nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxValue) {
                nums[i] = nextValue;
            }
        }

        operations++;
    }

    return operations;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Sorting

    Basic idea:
    If any value is less than k, answer is impossible.
    Otherwise, count distinct values greater than k.

    Step-by-step algorithm:
    1. Sort the array.
    2. Traverse every value.
    3. If any value is less than k, return -1.
    4. Count distinct values which are greater than k.
    5. Return that count.

    Time complexity:
    O(n log n)

    Space complexity:
    O(1)

    Note:
    Sorting puts equal values together.
    Each different value greater than k needs one operation.

------------------------------------------------------------*/
int minOperationsBetter(vector<int> nums, int k) {
    sort(nums.begin(), nums.end());

    int operations = 0;
    int previous = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < k) {
            return -1;
        }

        if (nums[i] > k && nums[i] != previous) {
            operations++;
        }

        previous = nums[i];
    }

    return operations;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Hash Set

    Basic idea:
    We only need the number of distinct values greater than k.
    If any value is less than k, it is impossible.

    Step-by-step algorithm:
    1. Create an unordered_set.
    2. Traverse every number in nums.
    3. If current number is less than k, return -1.
    4. If current number is greater than k,
       insert it into the set.
    5. Return size of the set.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is the best approach.
    Each distinct value greater than k needs one operation.
    Values equal to k need no operation.
    Values less than k can never become k.

------------------------------------------------------------*/
int minOperationsOptimal(vector<int>& nums, int k) {
    unordered_set<int> uniqueValues;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < k) {
            return -1;
        }

        if (nums[i] > k) {
            uniqueValues.insert(nums[i]);
        }
    }

    return uniqueValues.size();
}

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
    vector<int> nums = {5, 2, 5, 4, 5};
    int k = 2;

    int ans1 = minOperationsBruteForce(nums, k);
    int ans2 = minOperationsBetter(nums, k);
    int ans3 = minOperationsOptimal(nums, k);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}