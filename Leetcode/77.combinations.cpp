/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
    }
};
// @lc code=end


class Solution {
public:
    void combinations(vector<int> &arr, int ind, vector<int> &com, vector<vector<int>> &res, int k) {
        if (ind == arr.size()) {
            if (com.size() == k) {
                res.push_back(com);
            } 
            return;
        }

        com.push_back(arr[ind]);
        combinations(arr, ind+1, com, res, k);

        com.pop_back();
        combinations(arr, ind+1, com, res, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        vector<int> com;
        vector<vector<int>> res;
        combinations(arr, 0, com, res, k);

        return res;
    }
};


//Khandani Approach of backtracking (Using for loop)
class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int start, int n, int k, vector<int>& temp) {
        if(k == 0) {
            result.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(i+1, n, k-1, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        
        solve(1, n, k, temp);
        
        return result;
    }
};


//Khandani Backtracking Approach (without for loop)
class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int start, int n, int k, vector<int>& temp) {
        if(k == 0) {
            result.push_back(temp);
            return;
        }
        
        if(start > n)
            return;
        
        temp.push_back(start);
        solve(start+1, n, k-1, temp);
        temp.pop_back();
        solve(start+1, n, k, temp);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        
        solve(1, n, k, temp);
        
        return result;
    }
};