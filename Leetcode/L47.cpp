#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_my {
public:
    void solve(unordered_map<int, int> &mp, vector<int> &per, vector<vector<int>> &ans, vector<int>& nums) {
        int n = nums.size();
        if (per.size() == n) {
            ans.push_back(per);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (mp[nums[i]]) {
                per.push_back(nums[i]);
                mp[nums[i]]--;

                solve(mp, per, ans, nums);

                mp[nums[i]]++;
                per.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> per;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        solve(mp, per, ans, nums);

        set<vector<int>> st(ans.begin(), ans.end());
        vector<vector<int>> ans2(st.begin(), st.end());
        
        return ans2;
    }
};


//Approach-1 (Using same concept as Permutation-I but keeping count to avoid duplicates)
//T.C : O(N * N!)
//S.C : O(N)
class Solution_1 {
public:
    int n;
    vector<vector<int>> result;
    void backtrack(vector<int>& temp, unordered_map<int, int>& mp) {

        if (temp.size() == n) { //we got all numbers
            result.push_back(temp);
            return;
        }

        for (auto& [num, count] : mp) {

            if (count == 0)
                continue;
            
            // Do something
            temp.push_back(num);
            mp[num]--;

            // Explore it
            backtrack(temp, mp);

            // Undo it
            temp.pop_back();
            mp[num]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;
        
        // count the occurrence of each number
        for (int& num : nums) {
            mp[num]++;
        }
        
        vector<int> temp;
        backtrack(temp, mp);
        
        return result;
    }
};



//Approach-2 (Using swap technique but avoiding duplicates by using set)
//T.C : O(N * N!) worst case
//S.C : O(N)
class Solution_2 {
public:
    vector<vector<int>> result;
    int n;
    void solve(int idx, vector<int>& nums) {
        if(idx == n) {
            result.push_back(nums);
            return;
        }
        
        unordered_set<int> uniqueSet;
        for(int i = idx; i < n; i++) {
            
            if(uniqueSet.count(nums[i]) > 0) {
                continue;
            }
            
            uniqueSet.insert(nums[i]);
            
            swap(nums[i], nums[idx]);

            solve(idx+1, nums);

            swap(nums[i], nums[idx]);
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        
        return result;
    }
};


int main() {
    
    return 0;
}