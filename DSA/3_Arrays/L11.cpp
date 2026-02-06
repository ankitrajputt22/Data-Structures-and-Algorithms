#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


class Solution_1 { // Brute force
public:
    void solve(unordered_map<int, int> &mp, vector<int> &per, vector<vector<int>> &ans, vector<int>& nums) {
        int n = nums.size();
        if (per.size() == n) {
            ans.push_back(per);
            return;
        }

        unordered_set<int> used;  
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] && used.find(nums[i]) == used.end()) {
                used.insert(nums[i]);
                
                per.push_back(nums[i]);
                mp[nums[i]]--;

                solve(mp, per, ans, nums);

                mp[nums[i]]++;
                per.pop_back();
            }
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> per;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        solve(mp, per, ans, nums);

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == nums) {
                if (i == ans.size() - 1) {
                    nums = ans[0];
                }
                else {
                    nums = ans[i+1];
                }
                break;
            }
        }
    }
};

class Solution_2 {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;  // ind = breakInd
        int n = nums.size();
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
    }
};

int main() {
    vector<int> v = {1, 2, 3};
    do {
        for (int x : v) cout << x << " ";
        cout << "\n";
    } while(next_permutation(v.begin(), v.end()));
    
    // next_permutation(v.begin(), v.end()) = false → was last permutation, rearranged to first
    for (int x : v) {
        cout << x << " ";
    }
    newline2;
}