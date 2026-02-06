/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
    }
};
// @lc code=end

class Solution {
public:

    long long helper(int i, vector<int>& nums, int n, int target, int mn, int mx, bool taken) {
        if (i == n) {
            if (!taken) return 0; // empty subsequence not allowed
            return (mn + mx <= target) ? 1 : 0;
        }

        // Option 1: Do NOT take nums[i]
        long long notTake = helper(i+1, nums, n, target, mn, mx, taken);

        // Option 2: Take nums[i]
        int newMin = taken ? min(mn, nums[i]) : nums[i];
        int newMax = taken ? max(mx, nums[i]) : nums[i];

        long long take = helper(i+1, nums, n, target, newMin, newMax, true);

        return take + notTake;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(0, nums, n, target, 1e9, -1e9, false);
    }
};


class Solution {
public:
    int M = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;
        
        for(int i = 1; i<n; i++) {
            power[i] = (power[i-1] * 2) % M;
        }   

        int l = 0, r = n-1;
        long long ans = 0;

        int max = nums[r], min = nums[l];
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;   
            } 
            else {
                ans = (ans + power[r - l]) % M;
                l++;   
            }
        }

        return ans % M;
    }
};



//Approach-1 (Produce all subsequences, find min and max and check)
//This will give TLE


//Approach-2 (Using Sorting + Two Pointer Approach)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        //1. Sort
        sort(begin(nums), end(nums));
        
        vector<int> power(n);
        power[0] = 1;
        
        for(int i = 1; i<n; i++) {
            power[i] = (power[i-1] * 2) % M;
        }   
        
        //2. l = 0, r = n-1
        int l = 0, r = n-1;
        int result = 0;
        while(l <= r) {
            
            if(nums[l] + nums[r] <= target) {
                int diff = r-l;
                result = (result % M + power[diff]) % M;
                l++;
            } else {
                r--;
            }
            
        }
        
        return result;
    }
};