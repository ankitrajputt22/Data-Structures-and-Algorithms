/*
 * @lc app=leetcode id=3461 lang=cpp
 *
 * [3461] Check If Digits Are Equal in String After Operations I
 */

// @lc code=start
class Solution {
public:
    bool hasSameDigits(string s) {
        
    }
};
// @lc code=end



//Approach (simple traverse and check)
//T.C : O(n^2)
//S.C : O(1)

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();

        while (n > 2) {
            for (int i = 0; i < n-1; i++) {
                int d1 = s[i] - '0';
                int d2 = s[i+1] - '0';

                int sum = d1 + d2;
                
                s[i] = (sum % 10) + '0';
            }

            n--;
        }

        return s[0] == s[1];
    }
};