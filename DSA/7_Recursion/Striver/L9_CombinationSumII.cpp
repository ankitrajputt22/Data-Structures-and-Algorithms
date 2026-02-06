#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


// give tle
class Solution {
public:
    void helper(int ind, vector<int>& candidates, int target, int s, set<vector<int>> &res, vector<int> &com) {
        if (s > target) return;
        if (s == target) {
            res.insert(com);
            return;
        }
        if (ind >= candidates.size()) return;

        // take
        com.push_back(candidates[ind]);
        helper(ind + 1, candidates, target, s + candidates[ind], res, com);

        // not take
        com.pop_back();
        helper(ind + 1, candidates, target, s, res, com);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());   

        set<vector<int>> res;
        vector<int> com;

        helper(0, candidates, target, 0, res, com);

        vector<vector<int>> res2(res.begin(), res.end());
        return res2;
    }
};



class Solution2 {
public:
    // helper function to find combinations while ignoring the duplicates one
    void helper(vector<int>& cand, int tar, int ind, vector<vector<int>> &res, vector<int> &com) { 
        if (tar == 0) {
            res.push_back(com);
            return;
        }
        if (tar < 0 || ind >= cand.size()) {
            return;
        }

        for (int pick = ind; pick < cand.size(); pick++) {
            if (pick > ind && cand[pick] == cand[pick-1]) {
                continue;
            }
            if (cand[pick] > tar) {
                break;
            }

            com.push_back(cand[pick]);
            helper(cand, tar-cand[pick], pick+1, res, com);
            com.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<int> com;
        vector<vector<int>> res;

        helper(candidates, target, 0, res, com);

        return res;
    }
};


class Solution3 {
public:
    void combinations(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(ds);  
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;

            if (arr[i] > target) break; 

            ds.push_back(arr[i]);  
            combinations(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  
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