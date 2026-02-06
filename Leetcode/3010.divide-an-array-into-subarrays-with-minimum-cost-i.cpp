/*
 * @lc app=leetcode id=3010 lang=cpp
 *
 * [3010] Divide an Array Into Subarrays With Minimum Cost I
 */

// @lc code=start
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
    }
};
// @lc code=end

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];
        int min = INT_MAX;
        int secMin = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] < min) {
                secMin = min;
                min = nums[i];
            }
            else if (nums[i] < secMin) {
                secMin = nums[i];
            }
        }

        ans += min;
        ans += secMin;
        return ans;
    }
};



//Approach (Just find minimums)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int firstMin  = nums[0];
        int secondMin = INT_MAX;
        int thirdMin  = INT_MAX;

        for(int i = 1; i < n; i++) {
            if(nums[i] < secondMin) {
                thirdMin  = secondMin;
                secondMin = nums[i];
            } else if(nums[i] < thirdMin) {
                thirdMin = nums[i];
            }
        }

        return firstMin + secondMin + thirdMin;
    }
};
