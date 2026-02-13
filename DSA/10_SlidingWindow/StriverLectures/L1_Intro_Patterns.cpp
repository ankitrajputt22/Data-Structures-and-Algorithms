/*
============================================================
LECTURE: SLIDING WINDOW & TWO POINTERS
============================================================

This lecture serves as a fundamental introduction to
Sliding Window and 2 Pointers, identifying four key
problem patterns and providing templates to solve them
effectively.

============================================================
THE FOUR PROBLEM PATTERNS
============================================================

------------------------------------------------------------
1. CONSTANT WINDOW
------------------------------------------------------------

Goal:
Find maximum/minimum sum or metric of exactly K consecutive elements.

Technique:
• Calculate result for first K elements (0 to K-1).
• Slide window by:
    - Adding next element
    - Removing first element of previous window

Complexity:
Time  -> O(N)
Space -> O(1)

------------------------------------------------------------
2. LONGEST SUBARRAY / SUBSTRING WITH CONDITION
------------------------------------------------------------

Most common interview pattern.

Brute Force:
Generate all subarrays → O(N²)

Better (Sliding Window):
Use two pointers L and R.

• Expand R
• Update condition (e.g., sum)
• If condition violated → shrink L
• Update answer

Complexity:
O(2N) ≈ O(N)

Optimal:
Replace while loop with if (when possible)
Keeps strictly O(N)

------------------------------------------------------------
3. NUMBER OF SUBARRAYS WITH CONDITION
------------------------------------------------------------

Often uses Pattern 2 logic.

Example:
To find subarrays where sum == K:

count(sum <= K) - count(sum <= K-1)

------------------------------------------------------------
4. SHORTEST / MINIMUM WINDOW
------------------------------------------------------------

Technique:
• Expand R until condition met
• Then shrink L as much as possible
• Track minimum length

For shortest problems:
While loop is mandatory.

============================================================
CORE TEMPLATE (PATTERN 2 BETTER SOLUTION)
============================================================

int l = 0, r = 0, maxLen = 0, sum = 0;
while (r < n) {
    sum += arr[r];
    while (sum > k) {
        sum -= arr[l];
        l++;
    }
    if (sum <= k) {
        maxLen = max(maxLen, r - l + 1);
    }
    r++;
}

Key Takeaway:
For "Longest" problems → sometimes use if instead of while.
For "Shortest" or "All Subarrays" → while loop required.

============================================================
ADDITIONAL IMPORTANT NOTES (Added for Understanding)
============================================================

1. Sliding Window works best for:
   • Contiguous subarrays/substrings
   • Positive integers (for sum-based problems)

2. If negative numbers present:
   Sliding window may not work properly.

3. Two pointer types:
   • Same direction (sliding window)
   • Opposite direction (like 2-sum sorted array)

============================================================
IMPLEMENTATION EXAMPLES
============================================================
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*=========================================================
PATTERN 1: CONSTANT WINDOW
Max Sum of Subarray of Size K
=========================================================*/
int maxSumK(vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < k; i++)
        sum += arr[i];

    int maxSum = sum;

    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

/*=========================================================
PATTERN 2: LONGEST SUBARRAY WITH SUM <= K
=========================================================*/
int longestSubarraySumK(vector<int>& arr, int k) {

    int n = arr.size();
    int l = 0, r = 0;
    int sum = 0, maxLen = 0;

    while (r < n) {

        sum += arr[r];

        while (sum > k) {
            sum -= arr[l];
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
}

/*=========================================================
PATTERN 3: COUNT SUBARRAYS WITH SUM <= K
Helper function
=========================================================*/
int countSubarraysAtMostK(vector<int>& arr, int k) {

    int l = 0, sum = 0;
    int count = 0;

    for (int r = 0; r < arr.size(); r++) {

        sum += arr[r];

        while (sum > k) {
            sum -= arr[l];
            l++;
        }

        count += (r - l + 1);
    }

    return count;
}

/*=========================================================
PATTERN 4: SHORTEST SUBARRAY WITH SUM >= K
=========================================================*/
int shortestSubarraySumK(vector<int>& arr, int k) {

    int n = arr.size();
    int l = 0, sum = 0;
    int minLen = INT_MAX;

    for (int r = 0; r < n; r++) {

        sum += arr[r];

        while (sum >= k) {
            minLen = min(minLen, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }

    return (minLen == INT_MAX) ? -1 : minLen;
}

/*=========================================================
MAIN FUNCTION
=========================================================*/
int main() {

    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 7;

    cout << "Pattern 1 - Max Sum of Size K: "
         << maxSumK(arr, 3) << endl;

    cout << "Pattern 2 - Longest Subarray <= K: "
         << longestSubarraySumK(arr, k) << endl;

    cout << "Pattern 3 - Count Subarrays Sum == K: "
         << countSubarraysAtMostK(arr, k) -
            countSubarraysAtMostK(arr, k - 1)
         << endl;

    cout << "Pattern 4 - Shortest Subarray >= K: "
         << shortestSubarraySumK(arr, k) << endl;

    return 0;
}
