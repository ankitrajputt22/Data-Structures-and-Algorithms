/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        
    }
};
// @lc code=end


/*

🚀 Approach
Iterate over the string in steps of 2k. For each step:

Determine the start index i.
Calculate the end index for reversal: min(i + k, s.length()).
Reverse the substring from index i to the calculated end using the built-in reverse() function.
Continue this process until we've covered the entire string.
Return the modified string.


This approach works efficiently because it:
- Skips unnecessary characters (every alternate k-segment).
- Only touches the characters that need reversing.

*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();

        int i = 0;
        while (i < n) {
            int j = min(i + k, n);

            reverse(s.begin() + i, s.begin() + j);

            i += 2 * k;
        }

        return s;
    }
};