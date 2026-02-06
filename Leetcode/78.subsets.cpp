/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
    }
};
// @lc code=end



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


