#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    ============================================================
    3689. Maximum Total Subarray Value I
    ============================================================

    PROBLEM:
    --------
    You are given:

        nums = integer array of length n
        k    = number of subarrays we must choose

    We need to choose exactly k non-empty subarrays.

    Important:
        - Subarrays may overlap.
        - The exact same subarray can be chosen multiple times.

    Value of one subarray nums[l..r]:

        max(nums[l..r]) - min(nums[l..r])

    Total value:

        sum of values of all chosen k subarrays

    Goal:
        Return the maximum possible total value.

    ------------------------------------------------------------
    KEY OBSERVATION
    ------------------------------------------------------------

    Since the same subarray can be chosen multiple times,
    we only need to find the maximum value of any one subarray.

    Then we can choose that same best subarray k times.

    So:

        answer = k * maximum_subarray_value

    Now the question becomes:

        What is the maximum value of any subarray?

    For any subarray:

        value = max(subarray) - min(subarray)

    The largest possible difference in the whole array is:

        global maximum - global minimum

    A subarray containing both global maximum and global minimum
    will have this value.

    Therefore:

        maximum_subarray_value = max(nums) - min(nums)

    Final answer:

        k * (max(nums) - min(nums))

    ============================================================
    */



    /*
    ============================================================
    SOLUTION 1 : BRUTE FORCE
    ============================================================

    IDEA:
    -----
    Try every possible subarray nums[l..r].

    For each subarray:
        - Scan from l to r.
        - Find minimum element.
        - Find maximum element.
        - Calculate max - min.
        - Keep the best value.

    Since the same subarray can be selected again and again,
    final answer is:

        bestSubarrayValue * k

    ------------------------------------------------------------
    ALGORITHM
    ------------------------------------------------------------

    1. Initialize bestValue = 0.

    2. For every starting index l:
           For every ending index r:
               Find min and max from nums[l..r]
               value = max - min
               bestValue = max(bestValue, value)

    3. Return bestValue * k.

    ------------------------------------------------------------
    TIME COMPLEXITY
    ------------------------------------------------------------

    There are O(n²) subarrays.

    For every subarray, we scan up to O(n) elements.

    Total:
        O(n³)

    ------------------------------------------------------------
    SPACE COMPLEXITY
    ------------------------------------------------------------

    O(1)

    ============================================================
    */
    long long maxTotalValueBrute(vector<int> nums, int k) {

        int n = nums.size();

        long long bestValue = 0;

        for (int l = 0; l < n; l++) {

            for (int r = l; r < n; r++) {

                int minimumValue = INT_MAX;
                int maximumValue = INT_MIN;

                for (int i = l; i <= r; i++) {
                    minimumValue = min(minimumValue, nums[i]);
                    maximumValue = max(maximumValue, nums[i]);
                }

                long long currentValue =
                    maximumValue - minimumValue;

                bestValue =
                    max(bestValue, currentValue);
            }
        }

        return bestValue * k;
    }



    /*
    ============================================================
    SOLUTION 2 : BETTER APPROACH
    ============================================================

    IDEA:
    -----
    Avoid scanning every subarray again and again.

    Fix the starting index l.

    Then expand the ending index r from l to n-1.

    While expanding:
        - Maintain current minimum.
        - Maintain current maximum.

    This gives value of nums[l..r] in O(1).

    ------------------------------------------------------------
    EXAMPLE
    ------------------------------------------------------------

    nums = [4, 2, 5, 1]

    Fix l = 0:

        r = 0 -> [4]
            min = 4, max = 4, value = 0

        r = 1 -> [4,2]
            min = 2, max = 4, value = 2

        r = 2 -> [4,2,5]
            min = 2, max = 5, value = 3

        r = 3 -> [4,2,5,1]
            min = 1, max = 5, value = 4

    ------------------------------------------------------------
    ALGORITHM
    ------------------------------------------------------------

    1. Initialize bestValue = 0.

    2. For every l:
           currentMin = nums[l]
           currentMax = nums[l]

           For every r from l to n-1:
               update currentMin
               update currentMax
               bestValue = max(bestValue,
                               currentMax - currentMin)

    3. Return bestValue * k.

    ------------------------------------------------------------
    TIME COMPLEXITY
    ------------------------------------------------------------

    O(n²)

    ------------------------------------------------------------
    SPACE COMPLEXITY
    ------------------------------------------------------------

    O(1)

    ============================================================
    */
    long long maxTotalValueBetter(vector<int> nums, int k) {

        int n = nums.size();

        long long bestValue = 0;

        for (int l = 0; l < n; l++) {

            int currentMin = nums[l];
            int currentMax = nums[l];

            for (int r = l; r < n; r++) {

                currentMin =
                    min(currentMin, nums[r]);

                currentMax =
                    max(currentMax, nums[r]);

                long long currentValue =
                    currentMax - currentMin;

                bestValue =
                    max(bestValue, currentValue);
            }
        }

        return bestValue * k;
    }



    /*
    ============================================================
    SOLUTION 3 : OPTIMAL
    ============================================================

    KEY OBSERVATION:
    ----------------

    The value of any subarray is:

        max(subarray) - min(subarray)

    The largest possible value cannot be greater than:

        global maximum of nums - global minimum of nums

    Why?

        Any subarray maximum <= global maximum

        Any subarray minimum >= global minimum

    Therefore:

        max(subarray) - min(subarray)
        <= global maximum - global minimum

    Also, we can always choose a subarray that contains both
    the global maximum and global minimum.

    That subarray will have value:

        global maximum - global minimum

    Since same subarray can be chosen multiple times:

        answer = k * (global maximum - global minimum)

    ------------------------------------------------------------
    ALGORITHM
    ------------------------------------------------------------

    1. Find minimum element in nums.
    2. Find maximum element in nums.
    3. Difference = maximum - minimum.
    4. Return difference * k.

    ------------------------------------------------------------
    TIME COMPLEXITY
    ------------------------------------------------------------

    O(n)

    ------------------------------------------------------------
    SPACE COMPLEXITY
    ------------------------------------------------------------

    O(1)

    ============================================================
    */
    long long maxTotalValue(vector<int>& nums, int k) {

        int minimumValue = nums[0];
        int maximumValue = nums[0];

        for (int num : nums) {
            minimumValue = min(minimumValue, num);
            maximumValue = max(maximumValue, num);
        }

        long long difference =
            1LL * maximumValue - minimumValue;

        return difference * k;
    }
};



/*
============================================================
DRY RUN
============================================================

nums = [4, 2, 5, 1]
k = 3

Step 1:
    Find global minimum and maximum.

    minimum = 1
    maximum = 5

Step 2:
    Best possible subarray value:

        maximum - minimum
        = 5 - 1
        = 4

Step 3:
    Since same subarray can be chosen multiple times,
    choose best-value subarray 3 times.

    answer = 4 * 3
           = 12

Output:
    12

============================================================
ANOTHER DRY RUN
============================================================

nums = [1, 3, 2]
k = 2

minimum = 1
maximum = 3

best subarray value = 3 - 1 = 2

answer = 2 * 2 = 4

Output:
    4

============================================================
INTUITION
============================================================

We are not forced to choose different subarrays.

So after finding the best possible subarray once,
we can repeat it k times.

The best possible subarray value is simply the largest
difference between any two values in nums.

That is:

    max(nums) - min(nums)

============================================================
COMPLEXITY SUMMARY
============================================================

Brute Force:
    Time  : O(n³)
    Space : O(1)

Better:
    Time  : O(n²)
    Space : O(1)

Optimal:
    Time  : O(n)
    Space : O(1)

LeetCode Accepted Function:
    maxTotalValue()

============================================================
*/