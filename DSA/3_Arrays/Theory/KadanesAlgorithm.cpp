/*
Kadane's Algorithm - Maximum Subarray Sum
Kadane's Algorithm is a dynamic programming approach to find the maximum sum of a contiguous subarray in an array of integers (including negative numbers).


💡 Intuition
A subarray has contiguous elements.
Brute force → check all subarrays → O(n²) or O(n³).
Kadane’s Algorithm uses a dynamic programming idea:
While scanning the array, decide whether to extend the current subarray or start a new one.



⚙️ Algorithm Steps
Initialize
curr_sum = 0, max_sum = -∞
Traverse each element x in the array
curr_sum = max(x, curr_sum + x)
max_sum = max(max_sum, curr_sum)

Return max_sum



🔹 Core Idea

At every index i, we have two choices:
Extend the previous subarray (curr_sum + arr[i])
Start a new subarray from arr[i]

So we take : curr_sum=max(arr[i],curr_sum+arr[i])
and track : max_sum=max(max_sum,curr_sum)

*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int kadaneAlgorithm(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int current_sum = nums[0];
    int max_sum = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        // Either extend the existing subarray or start new from current element
        current_sum = max(nums[i], current_sum + nums[i]);
        
        // Update global maximum
        max_sum = max(max_sum, current_sum);
    }
    
    return max_sum;
}

int maxSubarraySumCircular(vector<int>& nums) {
    // Kadane for normal array
    int max_normal = kadaneAlgorithm(nums);
    
    // If all numbers are negative
    if (max_normal < 0) return max_normal;
    
    // Kadane for circular array: total_sum - min_subarray_sum
    int total_sum = 0;
    int min_sum = nums[0];
    int current_min = nums[0];
    
    for (int i = 0; i < nums.size(); i++) {
        total_sum += nums[i];
        current_min = min(nums[i], current_min + nums[i]);
        min_sum = min(min_sum, current_min);
    }
    
    int max_circular = total_sum - min_sum;
    return max(max_normal, max_circular);
}


pair<int, pair<int, int>> kadaneWithIndices(vector<int>& nums) {
    if (nums.empty()) return {0, {0, -1}};
    
    int current_sum = nums[0];
    int max_sum = nums[0];
    
    int start = 0, end = 0;
    int temp_start = 0;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > current_sum + nums[i]) {
            // Start new subarray
            current_sum = nums[i];
            temp_start = i;
        } else {
            // Extend existing subarray
            current_sum = current_sum + nums[i];
        }
        
        // Update maximum sum and indices
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }
    
    return {max_sum, {start, end}};
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    auto result = kadaneWithIndices(nums);
    int max_sum = result.first;
    int start = result.second.first;
    int end = result.second.second;
    
    cout << "Maximum subarray sum: " << max_sum << endl;
    cout << "Subarray: [";
    for (int i = start; i <= end; i++) {
        cout << nums[i] << (i < end ? ", " : "");
    }
    cout << "]" << endl;
    
    return 0;
}