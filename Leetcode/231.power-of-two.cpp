/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
    }
};
// @lc code=end

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        return (n & (n-1)) == 0;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        return ((1 << 30) % n == 0);
    }
};



class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;

        return (n % 2 == 0) && isPowerOfTwo(n / 2);
    }
};

#include<limits.h>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1;
        for (int i = 0; i <= 30; i++) {
            
            // cout <<"ans- " << ans << endl;
            if (ans == n)
            {
                return true;
            }
            if (ans < INT_MAX/2)
                ans = ans * 2;   
            
        }

        return false;
    }
};