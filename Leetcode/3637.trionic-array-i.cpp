/*
 * @lc app=leetcode id=3637 lang=cpp
 *
 * [3637] Trionic Array I
 */

// @lc code=start
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        
    }
};
// @lc code=end

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n == 3) return false;

        int p = -1, q = -1;
        int i = 0;
        while (i+1 < n && nums[i+1] > nums[i]) {
            i++;
        }
        p = i;
        if (p == 0 || p >= n-2) return false;

        while (i+1 < n && nums[i+1] < nums[i]) {
            i++;
        }
        q = i;
        if (q >= n-1 || p == q) return false;

        // what if i == n-1 then ???
        for (; i < n-1; i++) {
            if (nums[i+1] <= nums[i]) {
                return false;
            }
        }

        return true;
    }
};



//Approach (Simply simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        int i = 0;

        //Increasing
        while(i+1 < n && nums[i] < nums[i+1])
            i++;

        if(i == 0 || i == n-1)
            return false;
        
        //Decreasing
        while(i+1 < n && nums[i] > nums[i+1])
            i++;
        
        if(i == n-1)
            return false;
        
        //Increasing
        while(i+1 < n && nums[i] < nums[i+1])
            i++;
        

        return i == n-1;
    }
};