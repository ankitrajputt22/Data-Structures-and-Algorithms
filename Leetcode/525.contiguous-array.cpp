/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
    }
};
// @lc code=end


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int maxSubSize = 0;
        for (int i = 0; i < n; i++) {
            int count1 = 0;
            int count0 = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == 1) count1++;
                else count0++;

                if (count0 == count1) {
                    maxSubSize = max(maxSubSize, count1 + count0);
                }   
            }            
        }

        return maxSubSize;
    }
};


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int maxL = 0;
        unordered_map<int, int> mp; // prefixSum with index
        int preS = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }

            preS += nums[i];
            if (mp.find(preS) != mp.end()) {
                int ind = mp[preS];
                maxL = max(maxL, i - ind);
            }
            else {
                mp[preS] = i;
            }
        }

        return maxL;
    }
};



//Using the same pattern code
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        unordered_map<int, int> mp;
        int currSum = 0;
        int maxL = 0;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
           
            currSum += (nums[i] == 1) ? 1 : -1;
            
            if(mp.find(currSum) != mp.end()) {
                maxL = max(maxL, i-mp[currSum]);
            } else
                mp[currSum] = i;
        }
        
        return maxL;
    }
};
