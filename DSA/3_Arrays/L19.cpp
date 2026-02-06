#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_Brute {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int threshold = n / 3;
        
        for (int i = 0; i < n; i++) {
            int current = nums[i];
            
            // Skip if already processed this element
            if (!ans.empty() && ans[0] == current) continue;
            if (ans.size() > 1 && ans[1] == current) continue;
            
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == current) {
                    count++;
                }
            }
            
            if (count > threshold) {
                ans.push_back(current);
                if (ans.size() == 2) break; // At most 2 majority elements
            }
        }
        
        return ans;
    }
};

class Solution_1 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        int count = 1;
        int threshold = n / 3;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) {
                count++;
            } else {
                if (count > threshold) {
                    ans.push_back(nums[i-1]);
                }
                count = 1;
            }
        }
        
        // Check the last element
        if (count > threshold) {
            ans.push_back(nums[n-1]);
        }
        
        return ans;
    }
};

class Solution_My1 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<int> ans;
        for (int i = 0; i < n; i++) {
            int el = nums[i];
            int freq = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == el) {
                    freq++;
                } else {
                    break;
                }
            }

            if (freq > n/3) ans.insert(el);
        }

        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};

class Solution_Better {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int threshold = n / 3;
        
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            
            if (mp[nums[i]] > threshold) {
                st.insert(nums[i]);
            }
        }
        
        return vector<int>(st.begin(), st.end());
    }
};

class Solution_Optimal {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        vector<int> ans;
        
        int el1 = INT_MIN, el2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                cnt1++;
                el1 = nums[i];
            } 
            else if (cnt2 == 0 && nums[i] != el1) {
                cnt2++;
                el2 = nums[i];
            } 
            else if (nums[i] == el1) {
                cnt1++;
            }
            else if (nums[i] == el2) {
                cnt2++;
            } 
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) {
                cnt1++;
            } 
            if (nums[i] == el2) {
                cnt2++;
            }
        }

        if (cnt1 > threshold) {
            ans.push_back(el1);
        } 
        if (cnt2 > threshold) {
            ans.push_back(el2);
        }

        return ans;
    }
};

int main() {
    
    return 0;
}