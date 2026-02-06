#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    bool checkValidTri(int a, int b, int c) {
        if (a+b > c && b+c > a && c+a > b) {
            return true;
        }
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        int peri = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && j != k && i != k) {
                        if (checkValidTri(nums[i], nums[j], nums[k])) {
                            peri = max(peri, nums[i] + nums[j] + nums[k]);
                        }
                    }
                }
            }
        }

        return peri == INT_MIN ? 0 : peri;
    }
};

/*
Sorted: [2, 3, 4, 5, 7, 10]
Check from largest:
- 5,7,10: 5+7=12 >10 ✓ (valid triangle)
- If 5,7,10 fails, then 3,5,10 would also fail (3+5=8 <10)

*/

class Solution_2 {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = n - 3; i >= 0; i--) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        return 0;
    }
};

int main() {
    
    return 0;
}