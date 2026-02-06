



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_Brute {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    for (int l = k+1; l < n; l++) {  
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        
                        if (sum == target) {
                            vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                            sort(quad.begin(), quad.end());
                            st.insert(quad);
                        }
                    }
                }
            }
        }
        
        return vector<vector<int>>(st.begin(), st.end());
    }
};

/*

Approach Strategy
Hashset-based solution for finding quadruplets
Time Complexity: O(n³)
Space Complexity: O(n) + O(unique quadruplets)

Key Steps
Sort the array first (helps with duplicate handling)
Triple nested loops:
i: First element (0 to n-1)
j: Second element (i+1 to n-1)
k: Third element (j+1 to n-1)

Use hashset to store seen elements for fourth number
Calculate: fourth = target - (nums[i] + nums[j] + nums[k])
Check if fourth exists in hashset
Store valid quadruplets in set (auto-duplicate removal)

*/

class Solution_Better {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort first to handle duplicates better
        set<vector<int>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<long long> hashset; // Use long long for storage
                for (int k = j + 1; k < n; k++) {
                    // Calculate using long long to prevent overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long fourth = (long long)target - sum;
                    
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> quad = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(quad.begin(), quad.end());
                        st.insert(quad);
                    }
                    hashset.insert(nums[k]); // Insert current element
                }
            }
        }
        
        return vector<vector<int>>(st.begin(), st.end());
    }
};


class Solution_Optimal {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                int k = j+1;
                int l = n-1;

                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum > target) {
                        l--;
                    } 
                    else if (sum < target) {
                        k++;
                    } 
                    else {
                        vector<int> t = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(t);
                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k-1]) {
                            k++;
                        } 
                        while (k < l && nums[l] == nums[l+1]) {
                            l--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}