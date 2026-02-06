/*
 * @lc app=leetcode id=3423 lang=cpp
 *
 * [3423] Maximum Difference Between Adjacent Elements in a Circular Array
 */

// @lc code=start
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
    }
};
// @lc code=end



class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();

        int ans = abs(nums[0] - nums[n-1]);
        for (int i = 0; i < n-1; i++) {
            int diff = abs(nums[i+1] - nums[i]);

            ans = max(ans, diff);
        }

        return ans;
    }
};