/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        
    }
};
// @lc code=end


class Solution {
public:
    int strStr(string haystack, string needle) {
        int ind = haystack.find(needle);

        return ind;
    }
};



class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        
        for (int i = 0; i <= m-n; i++) { 
            for (int j = 0; j < n; j++) { 
                if (haystack[i+j] != needle[j]) break;
                
                if (j == n-1)
                    return i;
                
            }
            
        }
        
        return -1;
    }
};

