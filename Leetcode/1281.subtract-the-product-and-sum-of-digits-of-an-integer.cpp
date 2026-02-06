/*
 * @lc app=leetcode id=1281 lang=cpp
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        
    }
};
// @lc code=end

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        
        while (n != 0){
            int digit = n % 10;
            prod = (prod * digit);
            sum = sum + digit ;
            n = n/10;
        }

        int ans = prod - sum;
        return ans;
    }
};