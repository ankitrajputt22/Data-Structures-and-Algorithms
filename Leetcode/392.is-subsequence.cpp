/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
    }
};
// @lc code=end

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
            }

            j++;
        }

        return (i == m);
    }
};