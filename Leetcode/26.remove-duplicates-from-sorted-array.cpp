/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
    }
};
// @lc code=end

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();

        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(arr[i]);
        }

        int ind = 0;
        for (auto it : st) {
            arr[ind] = it;
            ind++;
        }
        return ind;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        
        int i = 0;
        for (int j = 1; j < n; j++){
            if (arr[i] != arr[j]) {
                i++;
                arr[i] = arr[j];
            } 
        }
        return i + 1;
    }
};