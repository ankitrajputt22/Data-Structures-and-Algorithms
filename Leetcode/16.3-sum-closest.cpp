#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    LeetCode 16: 3Sum Closest

    Problem:
    We are given an integer array nums.
    We are also given an integer target.

    We have to find three integers in nums
    such that their sum is closest to target.

    Return the sum of those three integers.

    Important:
    There is exactly one solution.
*/

/*------------------------------------------------------------

    Helper function:
    This function returns absolute difference
    between two long long values.

------------------------------------------------------------*/
long long getDifference(long long a, long long b) {
    if (a > b) {
        return a - b;
    }

    return b - a;
}

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Try every possible triplet.
    Find the sum of every triplet.
    Keep the sum which is closest to target.

    Step-by-step algorithm:
    1. Create closestSum.
    2. Run three loops for i, j, and k.
    3. Calculate current sum.
    4. Compare current sum with closestSum.
    5. If current sum is closer to target,
       update closestSum.
    6. After checking all triplets,
       return closestSum.

    Time complexity:
    O(n^3)

    Space complexity:
    O(1)

    Note:
    This solution can give TLE for large input.
    It checks every possible triplet.

------------------------------------------------------------*/
int threeSumClosestBruteForce(vector<int>& nums, int target) {
    int n = nums.size();

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int currentSum = nums[i] + nums[j] + nums[k];

                long long oldDiff = getDifference(closestSum, target);
                long long newDiff = getDifference(currentSum, target);

                if (newDiff < oldDiff) {
                    closestSum = currentSum;
                }
            }
        }
    }

    return closestSum;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Sorting and Binary Search

    Basic idea:
    Sort the array.
    Fix two numbers.
    Use binary search to find the third number
    which can make the sum closest to target.

    Step-by-step algorithm:
    1. Sort the array.
    2. Create closestSum using first three values.
    3. Run a loop for first index i.
    4. Run another loop for second index j.
    5. Find required value:
       target - nums[i] - nums[j].
    6. Use lower_bound to find closest third value.
    7. Check the found position.
    8. Also check previous position.
    9. Update closestSum if a closer sum is found.
    10. Return closestSum.

    Time complexity:
    O(n^2 log n)

    Space complexity:
    O(1)

    Note:
    This is better than brute force.
    It avoids the third loop.
    But binary search is still done for every pair.

------------------------------------------------------------*/
int threeSumClosestBetter(vector<int> nums, int target) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int required = target - nums[i] - nums[j];

            int index = lower_bound(nums.begin() + j + 1, nums.end(), required) - nums.begin();

            if (index < n) {
                int currentSum = nums[i] + nums[j] + nums[index];

                long long oldDiff = getDifference(closestSum, target);
                long long newDiff = getDifference(currentSum, target);

                if (newDiff < oldDiff) {
                    closestSum = currentSum;
                }
            }

            if (index - 1 > j) {
                int currentSum = nums[i] + nums[j] + nums[index - 1];

                long long oldDiff = getDifference(closestSum, target);
                long long newDiff = getDifference(currentSum, target);

                if (newDiff < oldDiff) {
                    closestSum = currentSum;
                }
            }
        }
    }

    return closestSum;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Sorting and Two Pointers

    Basic idea:
    Sort the array.
    Fix one number.
    Use two pointers to find the best pair.

    If current sum is smaller than target,
    move left pointer to increase the sum.

    If current sum is greater than target,
    move right pointer to decrease the sum.

    Step-by-step algorithm:
    1. Sort the array.
    2. Create closestSum using first three values.
    3. Traverse the array with index i.
    4. Put left pointer at i + 1.
    5. Put right pointer at n - 1.
    6. Calculate current sum.
    7. If current sum is closer to target,
       update closestSum.
    8. If current sum equals target,
       return target directly.
    9. If current sum is smaller than target,
       move left pointer.
    10. If current sum is greater than target,
        move right pointer.
    11. Return closestSum.

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    Sorting helps us move pointers wisely.
    It avoids checking all triplets.

------------------------------------------------------------*/
int threeSumClosestOptimal(vector<int> nums, int target) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            long long oldDiff = getDifference(closestSum, target);
            long long newDiff = getDifference(currentSum, target);

            if (newDiff < oldDiff) {
                closestSum = currentSum;
            }

            if (currentSum == target) {
                return target;
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return closestSum;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution with Duplicate Skipping

    Basic idea:
    This is similar to the two pointer approach.
    Here we skip duplicate fixed values.
    This avoids checking the same first value again.

    Step-by-step algorithm:
    1. Sort the array.
    2. Create closestSum using first three values.
    3. Traverse nums with index i.
    4. Skip duplicate nums[i].
    5. Use left and right pointers.
    6. Calculate current sum.
    7. Update closestSum if needed.
    8. If exact target is found, return target.
    9. Move left if sum is smaller.
    10. Move right if sum is larger.
    11. Return closestSum.

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

    Note:
    This is also optimal.
    Duplicate skipping is not required for correctness.
    But it can avoid repeated work.

------------------------------------------------------------*/
int threeSumClosestOptimalSkipDuplicates(vector<int> nums, int target) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            long long oldDiff = getDifference(closestSum, target);
            long long newDiff = getDifference(currentSum, target);

            if (newDiff < oldDiff) {
                closestSum = currentSum;
            }

            if (currentSum == target) {
                return target;
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return closestSum;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal solution.

------------------------------------------------------------*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return threeSumClosestOptimal(nums, target);
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
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int ans1 = threeSumClosestBruteForce(nums, target);
    int ans2 = threeSumClosestBetter(nums, target);
    int ans3 = threeSumClosestOptimal(nums, target);
    int ans4 = threeSumClosestOptimalSkipDuplicates(nums, target);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Binary Search:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution using Two Pointers:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution with Duplicate Skipping:" << endl;
    printAnswer(ans4);

    return 0;
}