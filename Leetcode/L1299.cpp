#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n-1; i++) {
            int maxi = -1;
            for (int j = i+1; j < n; j++) {
                maxi = max(maxi, arr[j]);
            }

            arr[i] = maxi;
        }

        arr[n-1] = -1;
        return arr;
    }
};

class Solution_2 {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n = nums.size();

        int rightMax = -1;
        int temp = 0;
        for (int i = n-1; i >= 0; i--) {
            temp = nums[i];
            nums[i] = rightMax;

            rightMax = max(rightMax, temp);
        }

        return nums;
    }
};

int main() {
    
    return 0;
}