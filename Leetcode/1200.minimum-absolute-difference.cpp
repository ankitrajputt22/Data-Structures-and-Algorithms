/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
    }
};
// @lc code=end


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        for (int i = 0; i < n-1; i++) {
            int diff = arr[i+1] - arr[i];
            minDiff = min(diff, minDiff);
        }

        for (int i = 0; i < n-1; i++) {
            if (arr[i+1] - arr[i] == minDiff) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};




//Approach (Sort and find and collect)
//T.C : O(nlogn) 
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> result;
        int n = arr.size();
        
        int minDiff = INT_MAX;
        for(int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i-1];
            minDiff = min(diff, minDiff);
        }
        
        for(int i = 1; i<n; i++) {
            int diff = arr[i]-arr[i-1];
            
            if(diff == minDiff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }
        
        
        return result;
        
    }
};


