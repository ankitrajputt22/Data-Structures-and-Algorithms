/*
============================================================
MEDIAN OF TWO SORTED ARRAYS
BRUTE FORCE + BETTER (SPACE OPTIMIZED) APPROACHES
============================================================

------------------------------------------------------------
LECTURE NOTES (VERBATIM — TIMESTAMPS REMOVED)
------------------------------------------------------------

This video explores the Brute Force and Better approaches for 
finding the Median of two Sorted Arrays of Different Sizes, 
focusing on optimizing space while maintaining linear time complexity.

The Problem
Given two sorted arrays, arr1 and arr2, find the median of the 
combined sorted array.

If total size (N) is even:
Median = average of the two middle elements (at indices N/2 - 1 and N/2).

If total size (N) is odd:
Median = the middle element (at index N/2).

1. Brute Force Approach
This method involves merging the two sorted arrays into a single sorted array.

Logic:
Use the merge step from Merge Sort. Compare elements from both arrays one by one 
and add the smaller one to a new array (arr3) until all elements are merged.

Complexity:
Time: O(N1 + N2) because every element is visited once.
Space: O(N1 + N2) to store the combined elements in arr3.

Limitation:
High space consumption leads to partial acceptance or memory limits in 
competitive environments.

2. Better Approach (Space Optimized)
Instead of storing all elements, we only track the specific middle elements 
needed for the median calculation.

Logic:
1. Determine the target indices: idx1 = N/2 - 1 and idx2 = N/2.
2. Use two pointers (i and j) to simulate the merge process.
3. Maintain a count variable (index tracker). Whenever the count matches 
   idx1 or idx2, store that value in a variable (el1 or el2).
4. Stop once both target elements are found.

Complexity:
Time: O(N1 + N2) – still linear.
Space: O(1) because we only use a few variables to track indices and store 
the two target elements.

Pseudo-code for Better Approach

int i = 0, j = 0, count = 0;
int el1 = -1, el2 = -1;
int idx1 = n / 2 - 1, idx2 = n / 2;

while (i < n1 && j < n2) {
    if (a1[i] < a2[j]) {
        if (count == idx1) el1 = a1[i];
        if (count == idx2) el2 = a1[i];
        i++;
    } else {
        if (count == idx1) el1 = a2[j];
        if (count == idx2) el2 = a2[j];
        j++;
    }
    count++;
}
// Follow-up for remaining elements in either array...

Key Improvement:
We achieved O(1) space, though the time complexity remains linear.
For large inputs, an O(log(min(N1, N2))) approach (Binary Search) 
is required for full acceptance.


------------------------------------------------------------
ADDITIONAL EXPLANATIONS (FOR LEARNING)
------------------------------------------------------------

WHAT IS MEDIAN?
---------------
Middle value of sorted data.

Odd length → single middle element
Even length → average of two middle elements

WHY ARRAYS ARE SORTED?
----------------------
Because they are sorted, we can simulate merging without actually sorting.

WHY BRUTE FORCE IS BAD?
-----------------------
Extra memory proportional to total elements.

WHY BETTER APPROACH WORKS?
--------------------------
We don't need full merged array.
We only need 1 or 2 middle elements.

So we simulate merge until reaching those indices.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

arr1 = [1,3]
arr2 = [2]

Merged order → 1 2 3
Median = 2

------------------------------------------------------------
ANOTHER EXAMPLE
------------------------------------------------------------

arr1 = [1,2]
arr2 = [3,4]

Merged order → 1 2 3 4
Median = (2+3)/2 = 2.5

------------------------------------------------------------
IMPLEMENTATION SECTION
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;


/*
============================================================
BRUTE FORCE APPROACH
Merge arrays completely then compute median
============================================================
*/
double findMedianBrute(vector<int>& a, vector<int>& b) {

    vector<int> merged;
    int i = 0, j = 0;

    // Merge step of merge sort
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            merged.push_back(a[i++]);
        else
            merged.push_back(b[j++]);
    }

    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);

    int n = merged.size();

    if (n % 2 == 1)
        return merged[n / 2];

    return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
}


/*
============================================================
BETTER APPROACH (SPACE OPTIMIZED)
Simulate merge but only track middle elements
============================================================
*/
double findMedianBetter(vector<int>& a, vector<int>& b) {

    int n1 = a.size();
    int n2 = b.size();
    int n = n1 + n2;

    int idx1 = (n - 1) / 2;
    int idx2 = n / 2;

    int i = 0, j = 0, count = 0;
    int el1 = -1, el2 = -1;

    while (i < n1 && j < n2) {

        int val;
        if (a[i] < b[j]) val = a[i++];
        else val = b[j++];

        if (count == idx1) el1 = val;
        if (count == idx2) el2 = val;

        count++;
    }

    while (i < n1) {
        if (count == idx1) el1 = a[i];
        if (count == idx2) el2 = a[i];
        i++; count++;
    }

    while (j < n2) {
        if (count == idx1) el1 = b[j];
        if (count == idx2) el2 = b[j];
        j++; count++;
    }

    if (n % 2 == 1) return el2;
    return (el1 + el2) / 2.0;
}


/*
============================================================
DRIVER CODE
============================================================
*/
int main() {

    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {3, 4};

    cout << "Brute Median = "
         << findMedianBrute(arr1, arr2) << endl;

    cout << "Better Median = "
         << findMedianBetter(arr1, arr2) << endl;

    return 0;
}


/*
============================================================
COMPLEXITY SUMMARY
============================================================

Brute Force
Time  : O(N1 + N2)
Space : O(N1 + N2)

Better Approach
Time  : O(N1 + N2)
Space : O(1)

Optimal Binary Search Approach
Time  : O(log(min(N1, N2)))
Space : O(1)

============================================================
END OF FILE
============================================================
*/
