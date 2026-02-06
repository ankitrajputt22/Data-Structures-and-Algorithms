/*
 * @lc app=leetcode id=2119 lang=cpp
 *
 * [2119] A Number After a Double Reversal
 */

// @lc code=start
class Solution {
public:
    bool isSameAfterReversals(int num) {
        
    }
};
// @lc code=end


bool isSameAfterReversals(int num) {
    return num == 0 || num % 10;
}

class Solution {
public:
    int reverseNum(int n) {
        int reversed = 0;

        while (n > 0) {
            int d = n % 10;
            reversed = reversed * 10 + d;

            n = n/10;
        }

        return reversed;
    }
    bool isSameAfterReversals(int num) {
        int rev1 = reverseNum(num);
        int rev2 = reverseNum(rev1);

        return rev2 == num;
    }
};

