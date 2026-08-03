#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    LeetCode 1: Two Sum

    Problem:
    We are given an array nums and an integer target.
    We have to return indices of two numbers.
    The sum of those two numbers should be equal to target.

    Note:
    There is exactly one answer.
    We cannot use the same element twice.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Check every possible pair.
    If the sum of any pair is equal to target,
    return their indices.

    Step-by-step algorithm:
    1. Run a loop from index 0 to n - 1.
    2. Run another loop from index i + 1 to n - 1.
    3. Check if nums[i] + nums[j] is equal to target.
    4. If yes, return i and j.
    5. If no pair is found, return empty vector.

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

    Note:
    This solution can be slow for large input.
    It checks all possible pairs.

------------------------------------------------------------*/
vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {};
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Sorting and Two Pointers

    Basic idea:
    Store value with original index.
    Sort the array.
    Use two pointers to find the target sum.

    Step-by-step algorithm:
    1. Create a vector of pairs.
    2. Store each number with its original index.
    3. Sort the vector by number.
    4. Put one pointer at start.
    5. Put one pointer at end.
    6. Find the sum of both pointer values.
    7. If sum is equal to target, return original indices.
    8. If sum is smaller, move left pointer forward.
    9. If sum is greater, move right pointer backward.
    10. If no answer is found, return empty vector.

    Time complexity:
    O(n log n)

    Space complexity:
    O(n)

    Note:
    We need to store original indices.
    Sorting changes the position of elements.

------------------------------------------------------------*/
vector<int> twoSumBetter(vector<int>& nums, int target) {
    vector<pair<int, int>> arr;

    for (int i = 0; i < nums.size(); i++) {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left].first + arr[right].first;

        if (sum == target) {
            return {arr[left].second, arr[right].second};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {};
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Hash Map

    Basic idea:
    For every number, find its required partner.
    Store previous numbers in a hash map.

    Step-by-step algorithm:
    1. Create an unordered_map.
    2. Traverse the array from left to right.
    3. For every nums[i], find need = target - nums[i].
    4. Check if need is already present in map.
    5. If yes, return index of need and i.
    6. If no, store nums[i] with its index.
    7. If no answer is found, return empty vector.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is the best approach.
    It finds the answer in one pass.

------------------------------------------------------------*/
vector<int> twoSumOptimal(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];

        if (mp.find(need) != mp.end()) {
            return {mp[need], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

/*------------------------------------------------------------

    Helper function:
    This function prints the answer indices.

------------------------------------------------------------*/
void printAnswer(vector<int>& ans) {
    if (ans.size() == 0) {
        cout << "No answer found" << endl;
        return;
    }

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans1 = twoSumBruteForce(nums, target);
    vector<int> ans2 = twoSumBetter(nums, target);
    vector<int> ans3 = twoSumOptimal(nums, target);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}