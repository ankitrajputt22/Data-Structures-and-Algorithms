/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
    }
};
// @lc code=end



class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> result;

        for (string word : words) {
            int rows[3] = {0}; 

            for (char ch : word) {
                char lowerChar = tolower(ch);
                if (row1.find(lowerChar) != string::npos) {
                    rows[0] = 1;
                } 
                else if (row2.find(lowerChar) != -1) {
                    rows[1] = 1;
                } 
                else if (row3.find(lowerChar) != string::npos) {
                    rows[2] = 1;
                }
            }

            int sum = rows[0] + rows[1] + rows[2];
            if (sum == 1) {
                result.push_back(word);
            }
        }

        return result;
    }
};
