#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//Approach-1 (Swapping elements in nums)
class Solution_1 {
public:
    vector<vector<int>> result;
    int n;
    
    void solve(int idx, vector<int>& nums) {

        if(idx == n) {
            result.push_back(nums);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            
            solve(idx+1, nums);
            
            swap(nums[i], nums[idx]);
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        
        return result;
    }
};



//Approach-2 (A very general Backtracking pattern which can help solve subsets, Subsets II, Permutations, Permutations II,  Combination Sum, Combination Sum II as well.
class Solution_2 {
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

int main() {
    
    return 0;
}