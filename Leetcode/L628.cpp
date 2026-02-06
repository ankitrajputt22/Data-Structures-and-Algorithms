#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int maxP = INT_MIN;

        int a = nums[n-1] * nums[n-2] * nums[n-3];
        int b = nums[0] * nums[1] * nums[2];
        int c = nums[0] * nums[1] * nums[n-1];
        int d = nums[0] * nums[n-1] * nums[n-2];
    

        return max(max(a, b), max(c, d));
    }
};


class Solution_2 {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2) {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3) {
                max3 = x;
            }

            if (x < min1) {
                min2 = min1;
                min1 = x;
            } 
            else if (x < min2) {
                min2 = x;
            }
        }

        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};

int main() {
    
    return 0;
}