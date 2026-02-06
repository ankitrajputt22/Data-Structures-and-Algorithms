#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


//78. Subsets
// Power Set Algorithm
class Solution_1 { 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;

        vector<vector<int>> ans;

        for(int num = 0; num < subsets; num++) {
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};


// Recursive way to print subsets
class Solution_2 {
public:
    void solve(int ind, vector<int> &subset, vector<vector<int>> &ans, vector<int> &nums) {
        int n = nums.size();
        if (ind == n) {   
            for (auto &it : subset) {
                cout << it << " ";
            }         
            cout << endl;
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[ind]);
        solve(ind+1, subset, ans, nums);
        subset.pop_back();
        solve(ind+1, subset, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(0, subset, ans, nums);
        
        for (auto &subset : ans) {
            cout << "[ ";
            for (auto &val : subset) {
                cout << val << " ";
            }
            cout << "]";
            cout << endl;
        }

        return ans;
    }
};

vector<string> AllPossibleStrings(string s) {
    int n = s.length();
    vector<string> ans;

    for (int num = 0; num < (1 << n); num++) {
        string sub = "";
        for (int i = 0; i < n; i++) {
            if (num & (1 << i)) {
                sub += s[i];
            }
        }
        if (sub.length() > 0) {
            ans.push_back(sub);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    
    return 0;
}