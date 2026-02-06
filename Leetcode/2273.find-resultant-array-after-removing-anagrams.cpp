/*
 * @lc app=leetcode id=2273 lang=cpp
 *
 * [2273] Find Resultant Array After Removing Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
    }
};
// @lc code=end

//Approach (simple traverse and check)
//T.C : O(n*m)
//S.C : O(1)
class Solution {
public:
    bool checkAnagram(string &s1, string& s2) {
        int arr[26] = {0};

        for(char &ch : s1) {
            arr[ch-'a']++;
        }

        for(char &ch : s2) {
            arr[ch-'a']--;
        }
        
        for(int i = 0; i < 26; i++) {
            if(arr[i] != 0)
                return false;
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> result;

        result.push_back(words[0]);

        for(int i = 1; i < n; i++) {
            if(!checkAnagram(words[i], result.back())) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};



class Solution {
public:
    bool isAnagrams(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        return freq1 == freq2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (!isAnagrams(words[i-1], words[i])) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
