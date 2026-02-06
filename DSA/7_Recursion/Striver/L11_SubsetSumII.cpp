#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

int main() {
    newline2;

    

    newline2;
    return 0;
}


// Brute force
class Solution {
public:
    void subsets(vector<int> &nums, int i, vector<int> sub, set<vector<int>> &res) {
        if (i >= nums.size()) {
            // sort(sub.begin(), sub.end());
            res.insert(sub);
            return;
        }

        sub.push_back(nums[i]);
        subsets(nums, i+1, sub, res);

        sub.pop_back();
        subsets(nums, i+1, sub, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> res;
        vector<int> sub;

        subsets(nums, 0, sub, res);
        vector<vector<int>> ans(res.begin(), res.end());

        return ans;
    }
};



// optimal solution
class Solution {
public:
    void find_subsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        ans.push_back(ds);

        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;

            ds.push_back(nums[i]);
            find_subsets(i + 1, nums, ds, ans);

            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());

        find_subsets(0, nums, ds, ans);
        
        return ans;
    }
};