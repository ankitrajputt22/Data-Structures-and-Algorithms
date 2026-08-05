#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

/*
    LeetCode 18: 4Sum

    Problem:
    We are given an integer array nums.
    We are also given an integer target.

    We have to return all unique quadruplets:
    nums[a], nums[b], nums[c], nums[d]

    Conditions:
    1. a, b, c, and d should be different.
    2. nums[a] + nums[b] + nums[c] + nums[d] == target.
    3. Duplicate quadruplets should not be included.

    Example:
    nums = [1, 0, -1, 0, -2, 2]
    target = 0

    Answer:
    [-2, -1, 1, 2]
    [-2, 0, 0, 2]
    [-1, 0, 0, 1]
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Check every possible quadruplet.
    If its sum is equal to target, store it.
    Sort each quadruplet before storing to avoid duplicates.

    Step-by-step algorithm:
    1. Create a set to store unique quadruplets.
    2. Run four loops for i, j, k, and l.
    3. Calculate sum of nums[i], nums[j], nums[k], nums[l].
    4. If sum is equal to target, create a quadruplet.
    5. Sort the quadruplet.
    6. Insert it into set.
    7. Convert set into answer vector.
    8. Return answer.

    Time complexity:
    O(n^4 * log q)

    Space complexity:
    O(q)

    Note:
    q is the number of unique quadruplets.
    This solution can give TLE for large input.
    It checks every possible quadruplet.

------------------------------------------------------------*/
vector<vector<int>> fourSumBruteForce(vector<int>& nums, int target) {
    int n = nums.size();

    set<vector<int>> uniqueQuadruplets;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long sum = 0;

                    sum = sum + nums[i];
                    sum = sum + nums[j];
                    sum = sum + nums[k];
                    sum = sum + nums[l];

                    if (sum == target) {
                        vector<int> quadruplet = {nums[i], nums[j], nums[k], nums[l]};

                        sort(quadruplet.begin(), quadruplet.end());

                        uniqueQuadruplets.insert(quadruplet);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans;

    for (auto quadruplet : uniqueQuadruplets) {
        ans.push_back(quadruplet);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Hash Set

    Basic idea:
    Fix first two numbers.
    Then use a hash set to find the other two numbers.
    Use set of quadruplets to avoid duplicates.

    Step-by-step algorithm:
    1. Create a set to store unique quadruplets.
    2. Run a loop for first index i.
    3. Run a loop for second index j.
    4. Create an empty hash set.
    5. Run a loop for third index k.
    6. Find needed fourth value.
    7. If needed value is present in hash set,
       we found one quadruplet.
    8. Sort the quadruplet.
    9. Insert it into set.
    10. Insert nums[k] into hash set.
    11. Convert set into answer vector.
    12. Return answer.

    Time complexity:
    O(n^3 * log q)

    Space complexity:
    O(n + q)

    Note:
    This is better than brute force.
    It removes one loop using hash set.
    But it still uses set to remove duplicates.

------------------------------------------------------------*/
vector<vector<int>> fourSumBetterHashSet(vector<int>& nums, int target) {
    int n = nums.size();

    set<vector<int>> uniqueQuadruplets;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            unordered_set<long long> seen;

            for (int k = j + 1; k < n; k++) {
                long long need = (long long)target - nums[i] - nums[j] - nums[k];

                if (seen.find(need) != seen.end()) {
                    vector<int> quadruplet = {nums[i], nums[j], nums[k], (int)need};

                    sort(quadruplet.begin(), quadruplet.end());

                    uniqueQuadruplets.insert(quadruplet);
                }

                seen.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> ans;

    for (auto quadruplet : uniqueQuadruplets) {
        ans.push_back(quadruplet);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 3: Better Solution using Sorting and Three Loops

    Basic idea:
    Sort the array.
    Fix first three numbers.
    Then use binary search to find the fourth number.

    Step-by-step algorithm:
    1. Sort nums.
    2. Create a set to store unique quadruplets.
    3. Run three loops for i, j, and k.
    4. Find needed fourth value.
    5. Use binary search after index k.
    6. If needed value exists, store quadruplet.
    7. Insert quadruplet into set.
    8. Convert set into answer vector.
    9. Return answer.

    Time complexity:
    O(n^3 log n)

    Space complexity:
    O(q)

    Note:
    This is better than brute force.
    Sorting helps us use binary search.
    But optimal two pointer approach is better.

------------------------------------------------------------*/
vector<vector<int>> fourSumBetterBinarySearch(vector<int> nums, int target) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    set<vector<int>> uniqueQuadruplets;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                long long need = (long long)target - nums[i] - nums[j] - nums[k];

                if (binary_search(nums.begin() + k + 1, nums.end(), need)) {
                    vector<int> quadruplet = {nums[i], nums[j], nums[k], (int)need};

                    uniqueQuadruplets.insert(quadruplet);
                }
            }
        }
    }

    vector<vector<int>> ans;

    for (auto quadruplet : uniqueQuadruplets) {
        ans.push_back(quadruplet);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Sorting and Two Pointers

    Basic idea:
    Sort the array.
    Fix first two numbers.
    Then use two pointers to find the other two numbers.

    Step-by-step algorithm:
    1. Sort nums.
    2. Run a loop for first index i.
    3. Skip duplicate nums[i].
    4. Run a loop for second index j.
    5. Skip duplicate nums[j].
    6. Put left pointer at j + 1.
    7. Put right pointer at n - 1.
    8. Calculate sum of four numbers.
    9. If sum equals target, store quadruplet.
    10. Skip duplicate left and right values.
    11. If sum is smaller, move left forward.
    12. If sum is larger, move right backward.
    13. Return answer.

    Time complexity:
    O(n^3)

    Space complexity:
    O(1)

    Note:
    This is the best common approach.
    Sorting helps us avoid duplicate quadruplets.
    Output space is not counted.

------------------------------------------------------------*/
vector<vector<int>> fourSumOptimal(vector<int> nums, int target) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = 0;

                sum = sum + nums[i];
                sum = sum + nums[j];
                sum = sum + nums[left];
                sum = sum + nums[right];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return ans;
}

/*------------------------------------------------------------

    Helper function for kSum approach

------------------------------------------------------------*/
void kSumHelper(vector<int>& nums, int start, int k, long long target, vector<int>& current, vector<vector<int>>& ans) {
    int n = nums.size();

    if (k == 2) {
        int left = start;
        int right = n - 1;

        while (left < right) {
            long long sum = (long long)nums[left] + nums[right];

            if (sum == target) {
                current.push_back(nums[left]);
                current.push_back(nums[right]);

                ans.push_back(current);

                current.pop_back();
                current.pop_back();

                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }

                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return;
    }

    for (int i = start; i <= n - k; i++) {
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }

        current.push_back(nums[i]);

        kSumHelper(nums, i + 1, k - 1, target - nums[i], current, ans);

        current.pop_back();
    }
}

/*------------------------------------------------------------

    Approach 5: Optimal Solution using kSum Recursion

    Basic idea:
    4Sum can be seen as a general kSum problem.
    We reduce 4Sum to 3Sum.
    Then reduce 3Sum to 2Sum.
    2Sum is solved using two pointers.

    Step-by-step algorithm:
    1. Sort nums.
    2. Start kSum recursion with k = 4.
    3. Pick one number at a time.
    4. Skip duplicate picked numbers.
    5. Reduce target by picked number.
    6. Reduce k by 1.
    7. When k becomes 2, use two pointers.
    8. Store all valid quadruplets.
    9. Return answer.

    Time complexity:
    O(n^3)

    Space complexity:
    O(k)

    Note:
    This is also optimal.
    It is useful when we want a general solution.
    For only 4Sum, direct two pointer code is easier.

------------------------------------------------------------*/
vector<vector<int>> fourSumOptimalKSum(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> current;

    kSumHelper(nums, 0, 4, target, current, ans);

    return ans;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal two pointer solution.

------------------------------------------------------------*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return fourSumOptimal(nums, target);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints all quadruplets.

------------------------------------------------------------*/
void printQuadruplets(vector<vector<int>>& quadruplets) {
    cout << "[";

    for (int i = 0; i < quadruplets.size(); i++) {
        cout << "[";

        for (int j = 0; j < quadruplets[i].size(); j++) {
            cout << quadruplets[i][j];

            if (j != quadruplets[i].size() - 1) {
                cout << ", ";
            }
        }

        cout << "]";

        if (i != quadruplets.size() - 1) {
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
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<int> nums1 = nums;
    vector<int> nums2 = nums;
    vector<int> nums3 = nums;
    vector<int> nums4 = nums;
    vector<int> nums5 = nums;

    vector<vector<int>> ans1 = fourSumBruteForce(nums1, target);
    vector<vector<int>> ans2 = fourSumBetterHashSet(nums2, target);
    vector<vector<int>> ans3 = fourSumBetterBinarySearch(nums3, target);
    vector<vector<int>> ans4 = fourSumOptimal(nums4, target);
    vector<vector<int>> ans5 = fourSumOptimalKSum(nums5, target);

    cout << "Brute Force Solution:" << endl;
    printQuadruplets(ans1);

    cout << "Better Solution using Hash Set:" << endl;
    printQuadruplets(ans2);

    cout << "Better Solution using Binary Search:" << endl;
    printQuadruplets(ans3);

    cout << "Optimal Solution using Sorting and Two Pointers:" << endl;
    printQuadruplets(ans4);

    cout << "Optimal Solution using kSum Recursion:" << endl;
    printQuadruplets(ans5);

    return 0;
}