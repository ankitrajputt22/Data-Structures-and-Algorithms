#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto it : mp) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return -1;
    }   
};

class Solution_2 {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (nums[i] & (1 << bit)) {
                    cnt++;
                }
            }

            if (cnt % 3 == 1) {
                ans = ans | (1 << bit);
            }
        }

        return ans;
    }
};

class Solution_3 {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i += 3) {
            if (nums[i] != nums[i-1]) {
                return nums[i-1];
            }
        }

        return nums[n-1];
    }
};

/*
ones: holds bits that have appeared once (or 4, 7, ... times)
twos: holds bits that have appeared twice (or 5, 8, ... times)

ones = (ones ^ nums[i]) & ~twos:
XOR with nums[i] adds the number to ones if not already there, or removes it if already present.
The & ~twos ensures that if a bit is already in twos (meaning it has appeared twice), it is not added to ones.

twos = (twos ^ nums[i]) & ~ones:
Similarly, XOR with nums[i] adds to twos if not already there, or removes it if already present.
The & ~ones ensures that if a bit is now in ones (meaning it has just been added), it is not added to twos.
*/


class Solution_4 {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int twos = 0;

        for (int i = 0; i < n; i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }

        return ones;
        
    }
};

class Solution_5 { // to understand it again
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threes = 0;
        
        for (int x : nums) {
            // First update threes (bits that appear three times)
            threes = twos & x;
            
            // Then update twos and ones, removing bits that are in threes
            twos = (twos | (ones & x)) & ~threes;
            ones = (ones | x) & ~threes & ~twos;
        }
        
        return ones;
    }
};

int main() {
    
    return 0;
}