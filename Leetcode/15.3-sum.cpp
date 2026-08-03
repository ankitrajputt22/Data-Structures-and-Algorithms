#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

/*
    LeetCode 15: 3Sum

    Problem:
    We are given an integer array nums.

    We have to return all unique triplets:
    nums[i], nums[j], nums[k]

    Conditions:
    1. i, j, and k should be different.
    2. nums[i] + nums[j] + nums[k] == 0.
    3. Duplicate triplets should not be included.

    Example:
    nums = [-1, 0, 1, 2, -1, -4]

    Answer:
    [-1, -1, 2]
    [-1, 0, 1]
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Check every possible triplet.
    If sum is 0, store it.
    Sort each triplet before storing to avoid duplicates.

    Step-by-step algorithm:
    1. Create a set to store unique triplets.
    2. Run three loops for i, j, and k.
    3. Check if nums[i] + nums[j] + nums[k] is 0.
    4. If yes, create a triplet.
    5. Sort the triplet.
    6. Insert it into the set.
    7. Convert set into answer vector.
    8. Return answer.

    Time complexity:
    O(n^3 * log n)

    Space complexity:
    O(number of unique triplets)

    Note:
    This solution can give TLE for large input.
    It checks all possible triplets.

------------------------------------------------------------*/
vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
    int n = nums.size();

    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());

                    uniqueTriplets.insert(triplet);
                }
            }
        }
    }

    vector<vector<int>> ans;

    for (auto triplet : uniqueTriplets) {
        ans.push_back(triplet);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Hash Set

    Basic idea:
    Fix one number.
    Then use hash set to find two other numbers.
    Use set of triplets to avoid duplicates.

    Step-by-step algorithm:
    1. Create a set to store unique triplets.
    2. Traverse nums with index i.
    3. Create an empty hash set.
    4. Traverse nums with index j from i + 1.
    5. Find third number as -(nums[i] + nums[j]).
    6. If third number exists in hash set,
       we found a valid triplet.
    7. Sort the triplet.
    8. Insert it into the set.
    9. Insert nums[j] into hash set.
    10. Convert set into answer vector.
    11. Return answer.

    Time complexity:
    O(n^2 * log t)

    Space complexity:
    O(n + t)

    Note:
    t is the number of unique triplets.
    This is better than brute force.
    It avoids the third loop.

------------------------------------------------------------*/
vector<vector<int>> threeSumBetter(vector<int>& nums) {
    int n = nums.size();

    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {
        unordered_set<int> seen;

        for (int j = i + 1; j < n; j++) {
            int third = -(nums[i] + nums[j]);

            if (seen.find(third) != seen.end()) {
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end());

                uniqueTriplets.insert(triplet);
            }

            seen.insert(nums[j]);
        }
    }

    vector<vector<int>> ans;

    for (auto triplet : uniqueTriplets) {
        ans.push_back(triplet);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Sorting and Two Pointers

    Basic idea:
    Sort the array.
    Fix one number.
    Then use two pointers to find the other two numbers.

    Step-by-step algorithm:
    1. Sort nums.
    2. Traverse nums with index i.
    3. Skip duplicate nums[i].
    4. Put left pointer at i + 1.
    5. Put right pointer at n - 1.
    6. Find sum of nums[i], nums[left], and nums[right].
    7. If sum is 0, store triplet.
    8. Skip duplicate left values.
    9. Skip duplicate right values.
    10. If sum is smaller than 0, move left.
    11. If sum is greater than 0, move right.
    12. Return answer.

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

    Note:
    This is the best common approach.
    Sorting helps us remove duplicates easily.
    Output space is not counted in space complexity.

------------------------------------------------------------*/
vector<vector<int>> threeSumOptimal(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});

                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }

                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Required Sum

    Basic idea:
    This is also a two pointer solution.
    It is similar to the given solution.

    Instead of checking total sum directly,
    we fix nums[i] and find required sum:
    required = -nums[i]

    Then we find two numbers whose sum is required.

    Step-by-step algorithm:
    1. Sort nums.
    2. Traverse nums with index i.
    3. Skip duplicate nums[i].
    4. Find required value as -nums[i].
    5. Put j at i + 1.
    6. Put k at n - 1.
    7. If nums[j] is duplicate, skip it.
    8. If nums[k] is duplicate, skip it.
    9. Find pair sum nums[j] + nums[k].
    10. If pair sum is required, store triplet.
    11. If pair sum is smaller, move j.
    12. If pair sum is larger, move k.
    13. Return answer.

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

    Note:
    This approach follows the same idea as the given code.
    It skips duplicate j and k values before checking the sum.

------------------------------------------------------------*/
vector<vector<int>> threeSumOptimalRequiredSum(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int required = -nums[i];

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                j++;
                continue;
            }

            if (k < n - 1 && nums[k] == nums[k + 1]) {
                k--;
                continue;
            }

            int sum = nums[j] + nums[k];

            if (sum == required) {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
            } else if (sum < required) {
                j++;
            } else {
                k--;
            }
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSumOptimal(nums);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints all triplets.

------------------------------------------------------------*/
void printTriplets(vector<vector<int>>& triplets) {
    cout << "[";

    for (int i = 0; i < triplets.size(); i++) {
        cout << "[";

        for (int j = 0; j < triplets[i].size(); j++) {
            cout << triplets[i][j];

            if (j != triplets[i].size() - 1) {
                cout << ", ";
            }
        }

        cout << "]";

        if (i != triplets.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<int> nums1 = nums;
    vector<int> nums2 = nums;
    vector<int> nums3 = nums;
    vector<int> nums4 = nums;

    vector<vector<int>> ans1 = threeSumBruteForce(nums1);
    vector<vector<int>> ans2 = threeSumBetter(nums2);
    vector<vector<int>> ans3 = threeSumOptimal(nums3);
    vector<vector<int>> ans4 = threeSumOptimalRequiredSum(nums4);

    cout << "Brute Force Solution:" << endl;
    printTriplets(ans1);

    cout << "Better Solution using Hash Set:" << endl;
    printTriplets(ans2);

    cout << "Optimal Solution using Sorting and Two Pointers:" << endl;
    printTriplets(ans3);

    cout << "Optimal Solution using Required Sum:" << endl;
    printTriplets(ans4);

    return 0;
}