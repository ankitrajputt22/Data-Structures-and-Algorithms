/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
    }
};
// @lc code=end

/*
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

*/


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        int currMax = 0, maxS = INT_MIN;
        int currMin = 0, minS = INT_MAX;

        for (int x : nums) {
            total += x;

            currMax = max(x, currMax + x);
            maxS = max(maxS, currMax);

            currMin = min(x, currMin + x);
            minS = min(minS, currMin);
        }

        if (total == minS) {
            return maxS;
        }

        // circular sum = total - minS
        return max(maxS, total - minS);
    }
};


/*
Brute Force Solution

Rotate the array one element at a time, and
Apply Kadane’s algorithm on each rotated version.
*/
#include <bits/stdc++.h>
using namespace std;

// Standard Kadane's algorithm
int kadane(vector<int> arr) {
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int x : arr) {
        currSum = max(x, currSum + x);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

// Rotate array left by 1 position
void rotateArray(vector<int>& arr) {
    int first = arr[0];
    for (int i = 0; i < arr.size() - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = first;
}

// Brute force circular subarray sum
int maxSubarraySumCircular_Brute(vector<int> nums) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        // Apply Kadane on current rotation
        int currentMax = kadane(nums);
        maxSum = max(maxSum, currentMax);

        // Rotate array by 1 for next iteration
        rotateArray(nums);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {5, -3, 5};
    cout << "Maximum Circular Subarray Sum (Brute Force): "
         << maxSubarraySumCircular_Brute(nums);
}







//Approach-1 (Using Kadane's Algo) - O(N)
class Solution {
public:
    
    int kadanesMax(vector<int>& nums, int n) {
        int sum     = nums[0];
        int maxSum  = nums[0];
        
        for(int i = 1; i<n; i++) {
            sum     = max(sum + nums[i], nums[i]);
            maxSum  = max(maxSum, sum);
        }
        
        return maxSum;
    }
    
    int kadanesMin(vector<int>& nums, int n) {
        int sum     = nums[0];
        int minSum  = nums[0];
        
        for(int i = 1; i<n; i++) {
            sum     = min(sum + nums[i], nums[i]);
            minSum  = min(minSum, sum);
        }
        
        return minSum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);
        
        int minSum = kadanesMin(nums, n);
        
        int maxSum = kadanesMax(nums, n);
        
        int circSum = SUM - minSum;
        
        if(maxSum > 0) {
            return max(maxSum, circSum);
        }
        
        return maxSum;
    }
};


//Approach-2 (Writing everything in one loop) - O(N)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n   = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);
        
        int k_sum_min = nums[0];
        int min_sum   = nums[0];
        
        int k_sum_max = nums[0];
        int max_sum   = nums[0];
        
        for(int i = 1; i<nums.size(); i++) {
            
            min_sum   = min(nums[i]+min_sum, nums[i]);
            k_sum_min = min(k_sum_min, min_sum);
            
            max_sum = max(nums[i]+max_sum, nums[i]);
            k_sum_max = max(k_sum_max, max_sum);
         
        }
        
        int circular_sum = SUM - k_sum_min;
        
        if(k_sum_max > 0) {
            return max(k_sum_max, circular_sum);
        }
        
        return k_sum_max;
        
    }
};