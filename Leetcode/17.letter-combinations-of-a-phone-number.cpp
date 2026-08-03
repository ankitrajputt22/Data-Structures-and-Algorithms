/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
    }
};
// @lc code=end

class Solution {
public:
    vector<string> phone = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void combinations(int ind, string &digits, string comb, vector<string> &res) {
        // base case
        if (ind == digits.length()) {
            res.push_back(comb);
            return;
        }

        // stand at a particular ind and find the dig and iterate over the string in phone[dig]
        int dig = digits[ind] - '0';
        for (int i = 0; i < phone[dig].length(); i++) {
            // take
            comb += phone[dig][i];
            combinations(ind+1, digits, comb, res);

            // remove
            comb.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        int n = digits.length();

        vector<string> res;
        string comb;
        combinations(0, digits, comb, res);

        return res;
    }
};



class Solution {
public:
    vector<string> result;
    
    void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp) {
        
        if(idx >= digits.length()) {
            result.push_back(temp);
            return;
        }
        
        
        char ch = digits[idx];
        string str = mp[ch];
        
        for(int i = 0; i<str.length(); i++) {
            
            //Do
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
            
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        unordered_map<char, string> mp;
        
        mp['2'] =  "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string temp = "";
        
        solve(0, digits, temp, mp);
        
        return result;
    }
};