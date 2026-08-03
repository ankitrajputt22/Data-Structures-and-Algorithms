/*
============================================================
MEDIAN OF TWO SORTED ARRAYS (BINARY SEARCH APPROACH)
============================================================

------------------------------------------------------------
LECTURE NOTES (VERBATIM — TIMESTAMPS REMOVED)
------------------------------------------------------------

This video explains the most optimal way to find the Median 
of two Sorted Arrays of Different Sizes using a Binary Search approach.

The Problem and Intuition
You are given two sorted arrays, arr1 (size N1) and arr2 (size N2). 
You need to find the median of the combined sorted version of these arrays.

Even Total Elements: The median is the average of the two middle elements.
Odd Total Elements: The median is the single middle element.

The Binary Search Strategy
Instead of merging the arrays (which takes O(N1+N2) time), 
we use binary search to find the correct partition between the two arrays.

1. Goal: Balanced Left Half
The total number of elements in the left half of the merged array should be:
leftHalfSize = (N1 + N2 + 1) / 2.

We pick x elements from arr1.
Consequently, we must pick leftHalfSize - x elements from arr2.

2. Identifying a Valid Symmetry
Let:
L1 = Last element in the left half of arr1.
R1 = First element in the right half of arr1.
L2 = Last element in the left half of arr2.
R2 = First element in the right half of arr2.

A partition is valid if:
L1 <= R2
L2 <= R1.

3. Applying Binary Search
We perform binary search on the shorter array (let's say arr1) 
to determine how many elements to pick for the left half:

If L1 > R2, we picked too many elements from arr1, 
so we move our high pointer to the left.

If L2 > R1, we picked too few elements from arr1, 
so we move our low pointer to the right.

Handling Odd/Even Scenarios
Once a valid partition is found:

If Total Elements are Odd:
Median = max(L1, L2).

If Total Elements are Even:
Median = (max(L1, L2) + min(R1, R2)) / 2.0.

Complexity Analysis
Time Complexity: O(log(min(N1, N2))) because we always perform binary 
search on the smaller array to optimize the search space.

Space Complexity: O(1) as we only use a few integer variables.

Note on implementation:
Always handle edge cases where L1, L2 might be -infinity or 
R1, R2 might be +infinity (when no elements are picked from an 
array or all are picked).


------------------------------------------------------------
ADDITIONAL EXPLANATIONS (FOR DEEP UNDERSTANDING)
------------------------------------------------------------

KEY IDEA
--------
Instead of merging arrays, we try to "cut" both arrays such that:

Left side contains half of total elements
Every element on left <= every element on right

This simulates the median position without merging.

WHY BINARY SEARCH?
------------------
If we pick a partition in array1, array2's partition is forced.
So we only search in one array → logarithmic time.

WHY SEARCH SMALLER ARRAY?
-------------------------
To avoid invalid partitions and guarantee O(log(min(n1,n2))).

EDGE CASE HANDLING
------------------
If no element taken from left side:
    left max = -infinity

If all elements taken:
    right min = +infinity

This allows comparison logic to work smoothly.

------------------------------------------------------------
WORKED EXAMPLE
------------------------------------------------------------

nums1 = [1, 3]
nums2 = [2]

Merged = [1,2,3]
Median = 2

Correct partition:
Left  = [1,2]
Right = [3]

------------------------------------------------------------
ANOTHER EXAMPLE
------------------------------------------------------------

nums1 = [1,2]
nums2 = [3,4]

Merged = [1,2,3,4]
Median = (2 + 3)/2 = 2.5

------------------------------------------------------------
ALGORITHM STEPS
------------------------------------------------------------

1. Ensure nums1 is smaller array
2. Binary search partition index in nums1
3. Compute partition index in nums2
4. Check partition validity
5. If valid → compute median
6. Else adjust binary search

------------------------------------------------------------
IMPLEMENTATION
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0, high = n1;

        int leftHalfSize = (n1 + n2 + 1) / 2;

        while (low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = leftHalfSize - cut1;

            int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int R1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int R2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Correct partition found
            if (L1 <= R2 && L2 <= R1) {

                // Odd total length
                if ((n1 + n2) % 2 == 1)
                    return max(L1, L2);

                // Even total length
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }
            else if (L1 > R2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }

        return 0.0; // Should never happen for valid input
    }
};


/*
------------------------------------------------------------
DRIVER CODE (TESTING)
------------------------------------------------------------
*/

int main() {

    Solution obj;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << "Median = " 
         << obj.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

/*
============================================================
END OF FILE
============================================================
*/
