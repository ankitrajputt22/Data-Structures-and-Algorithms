/*
Approach Strategy
Two-pointer technique with sorted array
Time Complexity: O(n²)
Space Complexity: O(1)

Key Steps
Sort the array (essential for two-pointer efficiency)

Initialize closestSum with large value

Iterate through each element as first number
Two pointers for remaining elements:
l = i+1 (left pointer)
r = n-1 (right pointer)

Calculate current sum and update closestSum if better:
if(abs(target-sum) < abs(target-closestSum))
Adjust pointers based on comparison:
sum > target → r-- (decrease sum)
sum ≤ target → l++ (increase sum)

*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                long long a = abs(sum - target);
                long long b = abs(ans - target);
                if (sum > target) {
                    if (a < b) {
                        ans = sum;
                    }
                    k--;
                    while (j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                } 
                else if (sum < target) {
                    if (a < b) {
                        ans = sum;
                    }
                    j++;
                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                } else {
                    return target;
                }
            }
        }
        return ans;
    }
};


class Solution_2 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int closestSum = 100000;
        
        for(int i = 0; i<n-2; i++) {
            
            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if(abs(target-sum) < abs(target-closestSum)) {
                    closestSum = sum;
                }
                
                if(sum > target)
                    r--;
                else
                    l++;
            }
        }
        return closestSum;
    }
};

int main() {
    
    return 0;
}