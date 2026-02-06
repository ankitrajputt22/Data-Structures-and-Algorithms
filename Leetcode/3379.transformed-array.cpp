/*
 * @lc app=leetcode id=3379 lang=cpp
 *
 * [3379] Transformed Array
 */

// @lc code=start
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        
    }
};
// @lc code=end

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                res[i] = nums[i];
            }
            else if (nums[i] > 0) {
                int ind = (i+nums[i]) % n;
                res[i] = nums[ind];
            }
            else {
                int a = i - abs(nums[i]);
                int ind;
                if (a >= 0) {
                    ind = a;
                }
                else if (abs(a) <= n) {
                    ind = (a + n) % n;
                }
                else if (abs(a) > n) {
                    int b = (abs(a) + n-1) / n;
                    ind = (a + abs(b) * n) % n;
                }
             
                res[i] = nums[ind];
            }
        }

        return res;
    }
};

//Approach (Iterate and find)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 0);

        for(int i = 0; i < n; i++) {
            int shift = nums[i]%n; //reducing the large shifts within 0..n-1 range

            int newIdx = (i + shift) % n;

            if(newIdx < 0) {
                newIdx += n;
            }

            result[i] = nums[newIdx];
        }

        return result;

    }
};


