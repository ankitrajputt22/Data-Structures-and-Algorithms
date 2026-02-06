/*
 * @lc app=leetcode id=1925 lang=cpp
 *
 * [1925] Count Square Sum Triples
 */

// @lc code=start
class Solution {
public:
    int countTriples(int n) {
        
    }
};
// @lc code=end



class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                   if (a*a + b*b == c*c) {
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
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a+1; b <= n; b++) {
                int cSquare = a*a + b*b;
                int c = sqrt(cSquare);

                if (c*c == cSquare && c <= n) {
                    ans += 2;
                }
            }
        }

        return ans;
    }
};