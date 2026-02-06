/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        
    }
};
// @lc code=end

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }

        long long reverse_num = 0;
        int num = x;

        while (x != 0){
            int digit = x % 10;
            reverse_num = reverse_num * 10 + digit;
            x = x / 10;
        }
        return num == reverse_num;
    }
};