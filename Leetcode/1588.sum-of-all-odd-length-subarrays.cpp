/*
===============================================================================
LeetCode 1588 - Sum of All Odd Length Subarrays
===============================================================================

Problem:
Given an array of positive integers arr, return the sum of all possible
odd-length subarrays.

Example:
Input:  arr = [1,4,2,5,3]
Output: 58

-------------------------------------------------------------------------------
APPROACH 1: BRUTE FORCE (Generate all subarrays)
-------------------------------------------------------------------------------

IDEA:
1. Generate every possible subarray using two loops.
2. Check if its length is odd.
3. If odd, calculate its sum using another loop.
4. Add it to answer.

TIME COMPLEXITY:
- Generating subarrays -> O(n^2)
- Calculating sum for each -> O(n)
- Total -> O(n^3)

SPACE COMPLEXITY:
- O(1)

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

        // Generate all subarrays
        for(int start = 0; start < n; start++) {

            for(int end = start; end < n; end++) {

                int length = end - start + 1;

                // Check if subarray length is odd
                if(length % 2 == 1) {

                    int currentSum = 0;

                    // Calculate subarray sum
                    for(int k = start; k <= end; k++) {
                        currentSum += arr[k];
                    }

                    totalSum += currentSum;
                }
            }
        }

        return totalSum;
    }
};



/*
===============================================================================
APPROACH 2: BETTER SOLUTION (Prefix Sum)
===============================================================================

IDEA:
1. Use prefix sum to calculate subarray sum in O(1).
2. Generate all odd-length subarrays.
3. Instead of looping to calculate sum every time:
       subarraySum = prefix[end + 1] - prefix[start]

WHY BETTER?
- Removes the inner summation loop.
- Subarray sum becomes constant time.

TIME COMPLEXITY:
- Prefix creation -> O(n)
- Enumerating subarrays -> O(n^2)
- Total -> O(n^2)

SPACE COMPLEXITY:
- O(n)

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int n = arr.size();

        // Prefix sum array
        vector<int> prefix(n + 1, 0);

        // Build prefix sum
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        int totalSum = 0;

        // Generate all subarrays
        for(int start = 0; start < n; start++) {

            for(int end = start; end < n; end++) {

                int length = end - start + 1;

                // Consider only odd length subarrays
                if(length % 2 == 1) {

                    // O(1) subarray sum
                    int subarraySum = prefix[end + 1] - prefix[start];

                    totalSum += subarraySum;
                }
            }
        }

        return totalSum;
    }
};




/*
===============================================================================
APPROACH 3: OPTIMAL MATHEMATICAL SOLUTION
===============================================================================

MOST IMPORTANT OBSERVATION:
Instead of generating subarrays,
calculate contribution of each element directly.

-------------------------------------------------------------------------------
HOW MANY ODD-LENGTH SUBARRAYS INCLUDE arr[i] ?
-------------------------------------------------------------------------------

For index i:

1. Number of choices on left side:
       (i + 1)

2. Number of choices on right side:
       (n - i)

3. Total subarrays containing arr[i]:
       (i + 1) * (n - i)

Among these,
half are odd length and half are even length.

Number of odd subarrays:
       ((totalSubarrays + 1) / 2)

Contribution:
       arr[i] * oddCount

-------------------------------------------------------------------------------
FORMULA:
-------------------------------------------------------------------------------

totalSubarrays = (i + 1) * (n - i)

oddCount = (totalSubarrays + 1) / 2

answer += arr[i] * oddCount

-------------------------------------------------------------------------------
WHY (total + 1)/2 ?
-------------------------------------------------------------------------------

If totalSubarrays is odd:
    odd count is one more than even count.

Example:
total = 5
odd = 3
even = 2

(5 + 1)/2 = 3

-------------------------------------------------------------------------------
TIME COMPLEXITY:
- O(n)

SPACE COMPLEXITY:
- O(1)

THIS IS THE BEST SOLUTION.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int n = arr.size();

        int answer = 0;

        for(int i = 0; i < n; i++) {

            // Total subarrays containing arr[i]
            int totalSubarrays = (i + 1) * (n - i);

            // Odd length subarrays containing arr[i]
            int oddCount = (totalSubarrays + 1) / 2;

            // Contribution of current element
            answer += arr[i] * oddCount;
        }

        return answer;
    }
};