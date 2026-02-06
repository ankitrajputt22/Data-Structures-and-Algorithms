#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int Xor = 0;
        for (auto it : mp) {
            if (it.second == 2) {
                Xor ^= it.first;
            }
        }

        return Xor;
    }
};

class Solution_2 {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> m;
        int xorr = 0;

        for (int num : nums) {
            if (m[num]) xorr ^= num;
            m[num]++;
        }

        return xorr;
    }
};



int main() {
    
    return 0;
}