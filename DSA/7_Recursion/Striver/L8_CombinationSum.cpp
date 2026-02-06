#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";



class Solution {
public:
    void helper(vector<int>& cand, int tar, int ind, vector<vector<int>> &res, vector<int> &com) {
        if (ind == cand.size()) {
            if (tar == 0) {
                res.push_back(com);
            }

            return;
        }

        if (cand[ind] <= tar) {
            com.push_back(cand[ind]);
            helper(cand, tar-cand[ind], ind, res, com);
            com.pop_back();
        }
    
        helper(cand, tar, ind+1, res, com);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> com;

        helper(candidates, target, 0, res, com);

        return res;
    }
};


class Solution2 {
public:
    void combinations(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            combinations(ind, target - arr[ind], arr, ds, ans);
            ds.pop_back();
        }

        combinations(ind + 1, target, arr, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        combinations(0, target, candidates, ds, ans);
        return ans;
    }
};

int main() {
    newline2;

    

    newline2;
    return 0;
}