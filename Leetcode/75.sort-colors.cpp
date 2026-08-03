/*
 * LeetCode 75 - Sort Colors
 *
 * ALGORITHM (Dutch National Flag - Optimal):
 *
 * 1. Initialize pointers:
 *    low = 0, mid = 0, high = n-1
 *
 * 2. While (mid <= high):
 *
 *    CASE 1: nums[mid] == 0
 *        swap(nums[low], nums[mid])
 *        low++, mid++
 *
 *    CASE 2: nums[mid] == 1
 *        mid++
 *
 *    CASE 3: nums[mid] == 2
 *        swap(nums[mid], nums[high])
 *        high--
 *        (do NOT move mid)
 *
 * 3. End when mid > high
 *
 * Time: O(n)
 * Space: O(1)
 *
 * Other Approaches:
 * - Brute Force: sort()
 * - Counting Sort
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ---------------------------------
    // 1. Brute Force
    // Use built-in sort
    // Time: O(n log n)
    // ---------------------------------
    void bruteForce(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }


    // ---------------------------------
    // 2. Counting Sort
    // Count 0s,1s,2s and overwrite
    // Time: O(n)
    // ---------------------------------
    void countingSort(vector<int>& nums) {

        int c0 = 0, c1 = 0, c2 = 0;

        for(int x : nums) {
            if(x == 0) c0++;
            else if(x == 1) c1++;
            else c2++;
        }

        int i = 0;

        while(c0--) nums[i++] = 0;
        while(c1--) nums[i++] = 1;
        while(c2--) nums[i++] = 2;
    }


    // ---------------------------------
    // 3. Dutch National Flag (Optimal)
    // 3 pointer approach
    // Time: O(n)
    // ---------------------------------
    void dutchFlag(vector<int>& nums) {

        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }


    // LeetCode function (optimal)
    void sortColors(vector<int>& nums) {
        dutchFlag(nums);
    }
};


// Helper function
void print(vector<int>& nums) {
    for(int x : nums) cout << x << " ";
    cout << endl;
}


// Driver code
int main() {

    Solution obj;

    vector<int> nums1 = {2,0,2,1,1,0};
    vector<int> nums2 = nums1;
    vector<int> nums3 = nums1;

    obj.bruteForce(nums1);
    obj.countingSort(nums2);
    obj.dutchFlag(nums3);

    cout << "Brute Force: ";
    print(nums1);

    cout << "Counting Sort: ";
    print(nums2);

    cout << "Dutch Flag (Optimal): ";
    print(nums3);

    return 0;
}