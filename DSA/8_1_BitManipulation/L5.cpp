

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto it : mp) {
            if (it.second == 1) return it.first;
        }

        return 0;
    }
};

class Solution_2 {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto it : mp) {
            if (it.second == 1) return it.first;
        }

        return 0;
    }
};

int main() {
    
    return 0;
}