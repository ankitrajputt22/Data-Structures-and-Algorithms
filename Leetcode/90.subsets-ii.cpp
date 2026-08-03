#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
=========================================================
LeetCode 90 : Subsets II
=========================================================

Goal:
Return all subsets WITHOUT duplicates.

Main challenge:
Input array may contain duplicates.

=========================================================
*/



/*
=========================================================
Approach 1 : Brute Force (Set + Subsets)
=========================================================

Idea:
1. Generate all subsets (like normal subsets)
2. Store them in a set to remove duplicates

Time Complexity : O(2^n * log N)
Space Complexity : O(2^n)

---------------------------------------------------------
Intuition:
Generate everything, then remove duplicates
=========================================================
*/

class Solution1 {
public:

    void helper(int ind,
                vector<int>& nums,
                vector<int>& subset,
                set<vector<int>>& res)
    {
        if (ind == nums.size()) {
            res.insert(subset);
            return;
        }

        // Take
        subset.push_back(nums[ind]);
        helper(ind + 1, nums, subset, res);

        // Not take
        subset.pop_back();
        helper(ind + 1, nums, subset, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        set<vector<int>> res;
        vector<int> subset;

        helper(0, nums, subset, res);

        return vector<vector<int>>(res.begin(), res.end());
    }
};




/*
=========================================================
Approach 2 : Backtracking (Optimal)
=========================================================

Idea:
1. Sort array
2. Use backtracking
3. Skip duplicates using condition:

   if(i > start && nums[i] == nums[i-1])
       continue;

Time Complexity : O(2^n)
Space Complexity : O(n)

---------------------------------------------------------
Intuition:
Avoid generating duplicate subsets
instead of removing them later
=========================================================
*/

class Solution2 {
public:

    void solve(int start,
               vector<int>& nums,
               vector<int>& subset,
               vector<vector<int>>& ans)
    {
        // Add current subset
        ans.push_back(subset);

        for (int i = start; i < nums.size(); i++) {

            /*
            Skip duplicates at same level
            */
            if (i > start && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);

            solve(i + 1, nums, subset, ans);

            subset.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

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

int main()
{
    vector<int> nums = {1,2,2};

    Solution2 obj;

    vector<vector<int>> res = obj.subsetsWithDup(nums);

    cout << "Subsets:\n";

    for (auto &vec : res) {
        cout << "[ ";
        for (auto x : vec)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}