#include <bits/stdc++.h>
using namespace std;

/*
====================================================
LEETCODE 31 - NEXT PERMUTATION
====================================================

Goal:
Rearrange numbers into next lexicographically greater permutation.

If not possible (descending order), rearrange into smallest permutation.

We will show:
1. Brute Force Approach (Conceptual)
2. STL Approach
3. Optimal O(n) Approach (Interview Expected)

====================================================
*/


class Solution {
public:

    /*
    ====================================================
    1️⃣ BRUTE FORCE APPROACH (Not Recommended)
    ====================================================

    Idea:
    - Generate all permutations
    - Sort them
    - Find current permutation
    - Return next one

    Time Complexity: O(n! * n)
    Space Complexity: O(n!)

    ❌ Not usable in interview
    ❌ Not efficient

    We are not implementing because it's impractical.
    */




    /*
    ====================================================
    2️⃣ STL APPROACH (Using C++ Built-in Function)
    ====================================================

    C++ provides:
        next_permutation(begin, end)

    It automatically:
        - Finds next permutation
        - If not possible, converts to smallest permutation

    Time Complexity: O(n)
    Space Complexity: O(1)

    ⚠️ Good shortcut but interviewer may ask to implement manually.
    */

    void nextPermutationSTL(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }




    /*
    ====================================================
    3️⃣ OPTIMAL APPROACH (INTERVIEW IMPORTANT)
    ====================================================

    Steps:

    STEP 1:
    Traverse from right and find first index 'i'
    such that nums[i] < nums[i+1]

    That index is called PIVOT.

    Example:
    1 2 3 6 5 4
          ↑
        pivot = 3

    STEP 2:
    From right side, find first element greater than nums[i]

    STEP 3:
    Swap both elements

    STEP 4:
    Reverse the part after index i

    Why reverse?
    Because right side is always in descending order.

    Time Complexity: O(n)
    Space Complexity: O(1)
    */

    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int pivot = -1;

        // STEP 1: Find Pivot (first decreasing element from right)
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // STEP 2: If pivot exists, find element just greater than pivot
        if(pivot != -1) {
            for(int i = n - 1; i > pivot; i--) {
                if(nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }

        // STEP 3: Reverse elements after pivot
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};



/*
====================================================
🔎 DRY RUN EXAMPLE

Input: 1 2 3 6 5 4

Step 1: Find pivot
6 > 5 > 4 → descending
3 < 6 → pivot = index 2

Step 2: Find next greater than 3 → 4

Swap:
1 2 4 6 5 3

Step 3: Reverse after pivot:
1 2 4 3 5 6

Final Answer ✔
====================================================
*/



/*
====================================================
EDGE CASES
====================================================

1) Already largest permutation:
   3 2 1
   → Reverse → 1 2 3

2) Single element:
   1 → same

3) Duplicates:
   1 1 5 → 1 5 1

====================================================
*/



/*
====================================================
TIME & SPACE COMPLEXITY
====================================================

Optimal Solution:
Time Complexity:  O(n)
Space Complexity: O(1)

====================================================
*/



int main() {

    Solution sol;

    vector<int> nums = {1, 2, 3};

    sol.nextPermutation(nums);

    cout << "Next Permutation: ";
    for(int num : nums)
        cout << num << " ";

    return 0;
}