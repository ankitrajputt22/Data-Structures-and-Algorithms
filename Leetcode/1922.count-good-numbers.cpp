/*
 * @lc app=leetcode id=1922 lang=cpp
 *
 * [1922] Count Good Numbers
 */

// @lc code=start
class Solution {
public:
    int countGoodNumbers(long long n) {
        
    }
};
// @lc code=end

class Solution {
public:
    static const long long M = 1000000007;

    long long pow(long long x, long long n) {
        long long ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans = (ans * x) % M;
            }
            x = (x * x) % M;
            n >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long part1 = pow(5, (n + 1) / 2);
        long long part2 = pow(4, n / 2);
        return (part1 * part2) % M;
    }
};




//Approach (Using Maths)
//T.C : O(log(n))
//S.C : O(1) but note that we use O(log(n)) system stack space of recursion
class Solution {
public:
    const int M = 1e9+7;
    int findPower(long long a, long long b) {
        if(b == 0) {
            return 1;
        }   

        long long half = findPower(a, b/2);
        long long result = (half * half) % M;

        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        return (long long)findPower(5, (n+1)/2) * findPower(4, n/2) % M;
    }
};