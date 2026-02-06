/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        
    }
};
// @lc code=end

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";

        string ans = "";
        int neg = 0;

        if (num < 0) {
            neg = 1;
            num = abs(num);
        }

        while (num != 0) {
            int rem = num % 7;
            ans += (rem + '0');
            num /= 7;
        }
        
        if (neg) ans.push_back('-');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

