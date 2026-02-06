/*
 * @lc app=leetcode id=2016 lang=cpp
 *
 * [2016] Maximum Difference Between Increasing Elements
 */

// @lc code=start
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
    }
};
// @lc code=end




//Approach (Simple iteration)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minElementi = nums[0];
        int maxDiff = -1;

        for(int j = 1; j < n; j++) {
            if(nums[j] > minElementi) {
                maxDiff = max(maxDiff, nums[j] - minElementi);
            } else {
                minElementi = nums[j];
            }
        }

        return maxDiff;
    }
};