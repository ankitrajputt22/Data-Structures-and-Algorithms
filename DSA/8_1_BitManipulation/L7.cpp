#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        unordered_map<int, int> mp;

        for (auto &num : nums) {
            mp[num]++;
        }   

        for (auto &it : mp) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

class Solution_2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        long long xorr = 0;
        for (auto &num : nums) {
            xorr ^= num;
        }

        int rightmost = (xorr & (xorr - 1)) ^ xorr;
        int b1 = 0, b2 = 0;
        
        for (auto &num : nums) {
            if (num & rightmost) {
                b1 ^= num;
            }
            else {
                b2 ^= num;
            }
        }

        return {b1, b2};
    }   
};


int main() {
    
    return 0;
}