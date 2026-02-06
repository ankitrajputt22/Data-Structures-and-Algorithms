/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
    }
};
// @lc code=end

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] == nums[j] && abs(j-i) <= k) {
                    return true;
                }
            }
        }

        return false;
    }
};


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> mp; // stores el and its index for checking purpose

        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end() && abs(mp[nums[i]] - i) <= k) {
                return true;
            }

            mp[nums[i]] = i;
        }

        return false;
    }
};


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_set<int> st;
        
        int i = 0, j = 0;
        
        while (j < n) {
            
            if (abs(i - j) > k) { 
                st.erase(nums[i]);
                i++; 
            }
            
            if (st.find(nums[j]) != st.end()) {
                return true;
            }
            
            st.insert(nums[j]);
            j++;
            
        }
        
        return false;
    }
};



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                seen.erase(nums[i - k - 1]);
            }

            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }

            seen.insert(nums[i]);
        }

        return false;        
    }
};