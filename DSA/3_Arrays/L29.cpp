#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_Brute {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxP = INT_MIN;
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                maxP = max(maxP, prod);
            }
        }

        return maxP;
    }
};

class Solution_2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxP = INT_MIN;
        int pre = 1, suff = 1;
        for (int i = 0; i < n; i++) {
            if (suff == 0) suff = 1;
            if (pre == 0) pre = 1;

            pre *= nums[i];
            suff *= nums[n-i-1];

            maxP = max(maxP, max(pre, suff));
        }

        return maxP;
    }
};

int main() {
    
    return 0;
}