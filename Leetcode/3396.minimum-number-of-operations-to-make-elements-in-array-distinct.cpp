/*
 * @lc app=leetcode id=3396 lang=cpp
 *
 * [3396] Minimum Number of Operations to Make Elements in Array Distinct
 */

// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
    }
};
// @lc code=end


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        int operations = 0;
        int i;
        for (i = 0; i < n-2; i += 3) {
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++) {
                mp[nums[j]]++;
                
                if (mp[nums[j]] > 1) {
                    operations++;
                    break;
                }   
            }
        }

        for (int k = i; k < n; k++) {
            if (k+1 < n && nums[k] == nums[k+1]) {
                operations++;
            }
        }

        return operations;
    }
};


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int i = n-1;
        for (i = n-1; i >= 0; i--) {
            mp[nums[i]]++;

            if (mp[nums[i]] > 1) {
                break;
            }
        }

        int ans = (i+1 + 2)/3;
        return ans;
    }
};


//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int n;
    bool check(vector<int>& nums, int start) {
        unordered_set<int> st;
        for (int j = start; j < n; j++) {
            if (st.count(nums[j])) {
                return false;
            }
            st.insert(nums[j]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        n = nums.size();
        int ops = 0;
        for (int i = 0; i < n; i += 3) {
            if (check(nums, i) == true) {
                return ops;
            }
            ops++;
        }
        return ops;
    }
};


//Approach-2 (Using reverse loop)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        for(int i = n-1; i >= 0; i--) {
            if(st.count(nums[i])) {
                return ceil((i+1)/3.0);
            }
            st.insert(nums[i]);
        }

        return 0;
    }
};

