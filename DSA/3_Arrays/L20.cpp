/*


Approach Overview
Two-pointer technique after sorting
Time Complexity: O(n²)
Space Complexity: O(1) (excluding output)

Key Steps----
Sort the array first (prerequisite for two-pointer)

Iterate through each element as the first number nums[i]
Skip duplicates: if (i > 0 && nums[i] == nums[i-1]) continue

Use two pointers for remaining elements:
j = i+1 (left pointer)
k = n-1 (right pointer)

Calculate sum = nums[i] + nums[j] + nums[k]

Adjust pointers based on sum:
Sum > 0: Decrement k-- (reduce sum)
Sum < 0: Increment j++ (increase sum)
Sum == 0: Found valid triplet

Handle duplicates after finding triplet:
while (j < k && nums[j] == nums[j-1]) j++
while (j < k && nums[k] == nums[k+1]) k--


*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_Brute {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
       

        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> a = {nums[i], nums[j], nums[k]};

                        sort(a.begin(), a.end());

                        // if (st.find(a) == st.end()) {
                        //     res.push_back(a);
                        //     st.insert(a);
                        // }   
                        st.insert(a);
                    }
                }
            }
        }

        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};

class Solution_Better {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            set<int> hashset;
            for (int j = i+1; j < n; j++) {
                int third = -(nums[i] + nums[j]);

                if (hashset.find(third) != hashset.end()) {
                    vector<int> a = {nums[i], nums[j], third};
                    sort(a.begin(), a.end());
                    st.insert(a);
                }

                hashset.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

class Solution_Optimal {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    vector<int> a = {nums[i], nums[j], nums[k]};
                    ans.push_back(a);

                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}