/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        
    }
};
// @lc code=end

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        if (x == 0) return 0;

        while (x != 0) {
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0;
            }
            int digit = x % 10;
            ans = (ans * 10) + digit;
            x = x / 10;
        }

        return ans;
    }
};