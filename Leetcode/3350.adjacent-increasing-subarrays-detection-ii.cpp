/*
 * @lc app=leetcode id=3350 lang=cpp
 *
 * [3350] Adjacent Increasing Subarrays Detection II
 */

// @lc code=start
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
    }
};
// @lc code=end


class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int currR = 1; // stores the curr increasing subarray length
        int prevR = 0; // stores the prev increasing subarray length

        int k = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                currR++;
            } else {
                prevR = currR;
                currR = 1;
            }

            k = max(k, max(currR / 2, min(currR, prevR)));
        }

        return k;
    }
};



//Approach (Using same concept as we did for Adjacent Increasing Subarrays Detection I)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        int maxResult = 0;

        for (int i = 1; i < n; i++) {
            if (nums [i] > nums[i-1]) {
                currRun++;
            } else { // increasing order breaks here
                prevRun = currRun;
                currRun = 1;
            }

            maxResult = max(maxResult, currRun/2);
            maxResult = max(maxResult, min(prevRun, currRun));
        }

        return maxResult;
    }
};
