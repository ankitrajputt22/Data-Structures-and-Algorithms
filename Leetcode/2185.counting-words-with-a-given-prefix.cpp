/*
 * @lc app=leetcode id=2185 lang=cpp
 *
 * [2185] Counting Words With a Given Prefix
 */

// @lc code=start
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
    }
};
// @lc code=end



class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int cnt = 0;
        for (string &word : words) {
            if (word.substr(0, pref.length()) == pref) {
                cnt++;
            }
        }

        return cnt;
    }
};



class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();

        int count = 0;
        for (auto word : words) {
            if (word.find(pref) == 0) {
                count++;
            }
        }

        return count;
    }
};