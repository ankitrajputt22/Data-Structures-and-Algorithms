#include <iostream>
#include <vector>

using namespace std;

/*
=========================================================
LeetCode 78 : Subsets
=========================================================

Goal:
Generate all possible subsets (power set)

Total subsets = 2^n

Example:
nums = [1,2,3]

Output:
[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]

=========================================================
*/



/*
=========================================================
Approach 1 : Recursion (Take / Not Take)
=========================================================

Idea:
For every element, we have 2 choices:
1. Include it
2. Exclude it

This forms a binary tree → 2^n subsets

Time Complexity : O(2^n)
Space Complexity : O(n)

---------------------------------------------------------
Intuition:
Classic subset generation using recursion
=========================================================
*/

class Solution1 {
public:

    void helper(int ind,
                vector<int>& nums,
                vector<int>& subset,
                vector<vector<int>>& ans)
    {
        int n = nums.size();

        // Base case
        if (ind >= n) {
            ans.push_back(subset);
            return;
        }

        // Take element
        subset.push_back(nums[ind]);
        helper(ind + 1, nums, subset, ans);

        // Not take element
        subset.pop_back();
        helper(ind + 1, nums, subset, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> subset;

        helper(0, nums, subset, ans);

        return ans;
    }
};




/*
=========================================================
Approach 2 : Power Set (Bit Manipulation)
=========================================================

Idea:
Each number from 0 → (2^n - 1) represents a subset.

Binary representation tells which elements to include.

Example:
nums = [1,2,3]

0 → 000 → []
1 → 001 → [1]
2 → 010 → [2]
3 → 011 → [1,2]

Time Complexity : O(2^n * n)
Space Complexity : O(1)

---------------------------------------------------------
Intuition:
Each bit represents inclusion/exclusion of element
=========================================================
*/

class Solution2 {
public:

    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();
        int total = 1 << n;

        vector<vector<int>> ans;

        for (int num = 0; num < total; num++) {

            vector<int> subset;

            for (int i = 0; i < n; i++) {

                if (num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};




/*
=========================================================
Approach 3 : Backtracking (For Loop)
=========================================================

Idea:
Start from index and build subsets gradually.

Steps:
1. Add current subset to answer
2. Loop through remaining elements
3. Add element → recurse → backtrack

Time Complexity : O(2^n)
Space Complexity : O(n)

---------------------------------------------------------
Intuition:
Build subsets incrementally instead of binary choices
=========================================================
*/

class Solution3 {
public:

    void solve(int start,
               vector<int>& nums,
               vector<int>& subset,
               vector<vector<int>>& ans)
    {
        // Add current subset
        ans.push_back(subset);

        for (int i = start; i < nums.size(); i++) {

            subset.push_back(nums[i]);

            solve(i + 1, nums, subset, ans);

            subset.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> subset;

        solve(0, nums, subset, ans);

        return ans;
    }
};



/*
=========================================================
Driver Code
=========================================================
*/

int main() {

    vector<int> nums = {1,2,3};

    Solution3 obj;

    vector<vector<int>> res = obj.subsets(nums);

    cout << "Subsets:\n";

    for (auto &vec : res) {
        cout << "[ ";
        for (auto x : vec)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}



class Solution {
public:
    void helper(int ind, vector<int>& nums, vector<int> &subset, vector<vector<int>> &ans) {
        int n = nums.size();
        if (ind >= n) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[ind]);
        helper(ind + 1, nums, subset, ans);

        subset.pop_back();
        helper(ind + 1, nums, subset, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subset;
        helper(0, nums, subset, ans);

        return ans;
    }
};


// Power Set algorithm 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;

        vector<vector<int>> ans;
        for (int num = 0; num < subsets; num++) {
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};


