/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
    }
};
// @lc code=end


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string sb = "";

        for (char c : s) {
            if (c != '-') {
                sb += toupper(c);
            }
        }
        reverse(sb.begin(), sb.end());

        int n = sb.length();

        string res = "";
        for (int i = 0; i < n; i += k) {
            
            if (i + k < n) {
                res += sb.substr(i, k);
            }

            else {
                res += sb.substr(i);
            }

            if (i + k < n) {
                res += "-";
            }

            /*
            
            res += sb.substr(i, min(k, (int)sb.length() - i));
            if (i + k < sb.length()) {
                res += "-";
            }

            */
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
