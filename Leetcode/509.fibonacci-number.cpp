/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        
    }
};
// @lc code=end



class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int last = fib(n-1);
        int sLast = fib(n-2);

        return last + sLast;
    }
};


class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int prev = 1;
        int prev2 = 0; 
        for (int i = 2; i <= n; i++) {
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};