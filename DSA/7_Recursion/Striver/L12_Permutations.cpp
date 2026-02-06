#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <unordered_set>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

int main() {
    newline2;

    

    newline2;
    return 0;
}


class Solution {
public:
    void solve(vector<int> &per, vector<vector<int>> &ans, vector<int>& nums, unordered_set<int> st) {
        int n = nums.size();

        if (per.size() == n) {
            ans.push_back(per);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) == st.end()) {
                per.push_back(nums[i]);
                st.insert(nums[i]);

                solve(per, ans, nums, st);

                st.erase(nums[i]);
                per.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> per;
        vector<vector<int>> ans;
        unordered_set<int> st;
        solve(per, ans, nums, st);

        return ans;
    }
};


class Solution {
public: 
    // here ds is a particular permutation
    void permutations(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(ds.begin(), ds.end(), nums[i]) == ds.end()) {
                ds.push_back(nums[i]);

                permutations(nums, ds, ans);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;

        vector<vector<int>> ans;
        permutations(nums, ds, ans);

        return ans;
    }
};


class Solution {
private:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];

        for (int i = 0; i < nums.size(); i++) 
            freq[i] = 0;

        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};
