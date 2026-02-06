#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int Xor = nums[i] ^ nums[j];

                cnt += __builtin_popcount(Xor);
            }
        }

        return cnt;
    }
};

class Solution_2 {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for (int i = 0; i < 32; i++) {
            int cnt1 = 0;
            for (int num : nums) {
                if ((num >> i) & 1) cnt1++;
            }

            int cnt0 = n - cnt1;

            total += cnt1 * cnt0;
        }

        return total;
    }
};

int main() {
    
    return 0;
}