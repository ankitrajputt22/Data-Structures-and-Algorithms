/*
 * @lc app=leetcode id=3583 lang=cpp
 *
 * [3583] Count Special Triplets
 */

// @lc code=start
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        
    }
};
// @lc code=end

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (nums[i] == nums[j] * 2 &&nums[k] == nums[j] * 2) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};





class Solution {
public:
    int M = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        for (int i = 1; i < n-1; i++) {
            int x = nums[i];
            int ok1 = 0, ok2 = 0;
            int cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] == 2*x) {
                    ok1 = 1;
                    cnt1++;
                }
            }

            for (int k = i+1; k < n; k++) {
                if (nums[k] == 2*x) {
                    ok2 = 1;
                    cnt2++;
                }
            }

            if (ok1 && ok2) {
                ans = (ans + cnt1 * cnt2) % M;
            }
        }

        return ans % M;
    }
};




//Approach-1 (Using map : 2 Pass Solution)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mp_left;
        unordered_map<int, int> mp_right;

        int result = 0;

        for(int &num : nums) {
            mp_right[num]++;
        }

        for(int &num : nums) {
            mp_right[num]--;

            int left  = mp_left[num*2];
            int right = mp_right[num*2];

            result = (result + (1LL * left * right)) % M;

            mp_left[num]++;
        }

        return result;
    }
};



//Approach-2 (Using map :  Pass Solution)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> valid_i;
        unordered_map<int, int> valid_j;

        int result = 0;

        for(int &num : nums) {
            
            if(num%2 == 0) { //if it's valid k, we got our triplet
                result = (result + valid_j[num/2]) % M;
            }

            //If it's valid j or not
            valid_j[num] = (valid_j[num] + valid_i[num*2]) % M;

            valid_i[num]++;
        }

        return result;
    }
};