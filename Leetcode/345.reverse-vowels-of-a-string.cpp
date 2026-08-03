/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        
    }
};
// @lc code=end

//Simply using  Two pointer technique
class Solution {
public:
    bool isVowel(char &ch) {
        return ch =='a' || ch == 'e' ||
               ch =='i' || ch == 'o' ||
               ch == 'u' ||
               ch =='A' || ch == 'E' ||
               ch =='I' || ch == 'O' ||
               ch == 'U';
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;
        
        while(i < j) {
            if(!isVowel(s[i])) i++;
            
            else if(!isVowel(s[j])) j--;
            
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        
        return s;
    }
};



class Solution {
public:
    bool isVowel(char &ch) {
        unordered_set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' };
        return vowels.count(ch) > 0;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;

        while (i < j) {
            if (!isVowel(s[i])) {
                i++;
            } else if(!isVowel(s[j])) {
                j--;
            } else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;

    }
};