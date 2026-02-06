/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
    }
};
// @lc code=end




class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
            if (mp[num] > 1) {
                return num;
            }
        }

        return -1;
    }   
};

/*

Why this works :-
The repeated number appears n times
Distance between two occurrences ≤ 2
No hash map needed

*/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) {
                return nums[i];
            }
        }
        return nums[n - 1];  // fallback
    }
};
