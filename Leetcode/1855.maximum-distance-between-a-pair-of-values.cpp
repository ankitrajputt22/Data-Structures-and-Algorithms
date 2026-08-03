#include <bits/stdc++.h>
using namespace std;

/* ============================================================
   PROBLEM: Maximum Distance Between a Pair of Values
   (LeetCode 1855)

   Given:
   - Two non-increasing arrays nums1 and nums2

   Task:
   - Find maximum (j - i) such that:
        i <= j AND nums1[i] <= nums2[j]

   If no valid pair exists → return 0
============================================================ */


/* ============================================================
   APPROACH: Two Pointer Technique

   Algorithm:
   1. Initialize two pointers:
        i = 0 (for nums1)
        j = 0 (for nums2)

   2. Traverse both arrays:
        while (i < n && j < m)

   3. If nums1[i] <= nums2[j]:
        - Valid pair found
        - Update answer: max(ans, j - i)
        - Move j forward (try to increase distance)

   4. Else:
        - Invalid pair (nums1[i] > nums2[j])
        - Move i forward to reduce nums1[i]

        - Ensure constraint i <= j:
            if (j < i) → set j = i

   5. Continue until traversal ends

   6. Return maximum distance

   Time Complexity:
   - O(n + m)
   (each pointer moves at most once)

   Space Complexity:
   - O(1)

   Notes:
   - Arrays are sorted in non-increasing order → key property
   - This avoids brute force O(n^2)
   - Ensures optimal linear scan
   - j pointer always tries to go as far as possible
============================================================ */

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;
        int ans = 0;

        while (i < n && j < m) {

            // Valid pair condition
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++; // expand window
            }
            else {
                i++; // move i to satisfy condition

                // maintain i <= j constraint
                if (j < i) {
                    j = i;
                }
            }
        }

        return ans;
    }
};


/* ============================================================
   MAIN FUNCTION (for testing)

   Example:
   nums1 = {30, 29, 19, 5}
   nums2 = {25, 25, 25, 25, 25}

   Expected Output:
   2
============================================================ */

int main() {
    vector<int> nums1 = {30, 29, 19, 5};
    vector<int> nums2 = {25, 25, 25, 25, 25};

    Solution obj;
    cout << "Maximum Distance: "
         << obj.maxDistance(nums1, nums2) << endl;

    return 0;
}