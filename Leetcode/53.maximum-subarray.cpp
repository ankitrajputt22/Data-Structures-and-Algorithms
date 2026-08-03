/*
 * LeetCode 53 - Maximum Subarray
 *
 * Find the contiguous subarray with the largest sum.
 *
 * Approaches in this file:
 * 1. Brute Force
 * 2. Prefix Sum (Better)
 * 3. Kadane's Algorithm (Optimal)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ---------------------------------
    // 1. Brute Force
    // Check all subarrays
    // Time: O(n^3)
    // ---------------------------------
    int bruteForce(vector<int>& nums) {

        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                int sum = 0;

                for(int k = i; k <= j; k++) {
                    sum += nums[k];
                }

                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }


    // ---------------------------------
    // 2. Better Approach
    // Remove inner loop
    // Time: O(n^2)
    // ---------------------------------
    int better(vector<int>& nums) {

        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {

            int sum = 0;

            for(int j = i; j < n; j++) {
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }


    // ---------------------------------
    // 3. Kadane's Algorithm (Optimal)
    // Keep track of current sum
    // Time: O(n)
    // ---------------------------------
    int kadane(vector<int>& nums) {

        int sum = 0;
        int maxi = INT_MIN;

        for(int num : nums) {

            sum += num;

            maxi = max(maxi, sum);

            // if sum becomes negative reset it
            if(sum < 0)
                sum = 0;
        }

        return maxi;
    }


    // LeetCode function (uses optimal)
    int maxSubArray(vector<int>& nums) {
        return kadane(nums);
    }
};


// Example driver code
int main() {

    Solution obj;

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << "Brute Force: " << obj.bruteForce(nums) << endl;
    cout << "Better Approach: " << obj.better(nums) << endl;
    cout << "Kadane (Optimal): " << obj.kadane(nums) << endl;

    return 0;
}

/*
Key Idea (Kadane):

If current sum becomes negative,
discard it and start a new subarray.

Example:
[-2,1,-3,4,-1,2,1,-5,4]

Maximum Subarray = [4,-1,2,1]
Sum = 6

Complexity:
Brute Force -> O(n^3)
Better      -> O(n^2)
Kadane      -> O(n)
*/