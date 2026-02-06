/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
    }
};
// @lc code=end

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int i = 0; i <= n-k; i++) {
            int diff = nums[i+k-1] - nums[i];
            minDiff = min(diff, minDiff);
        }

        return minDiff;
    }
};


//Approach (Using sorting and two pointers)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int minDiff = INT_MAX;

        int i = 0;
        int j = i+k-1;
        while(j < n) {
            int minElement = nums[i];
            int maxElement = nums[j];

            minDiff = min(minDiff, maxElement - minElement);
            i++;
            j++;
        }

        return minDiff;
    }
};