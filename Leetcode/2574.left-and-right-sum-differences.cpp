#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    ============================================================
    2574. Left and Right Sum Differences
    ============================================================

    PROBLEM:
    --------
    You are given an integer array nums.

    For each index i:

        leftSum[i]  = sum of all elements strictly to the left
                      of index i

        rightSum[i] = sum of all elements strictly to the right
                      of index i

    We need to create an answer array such that:

        answer[i] = abs(leftSum[i] - rightSum[i])

    Return the answer array.

    ------------------------------------------------------------
    EXAMPLE
    ------------------------------------------------------------

    nums = [10,4,8,3]

    Index 0:
        leftSum  = 0
        rightSum = 4+8+3 = 15
        answer[0] = |0-15| = 15

    Index 1:
        leftSum  = 10
        rightSum = 8+3 = 11
        answer[1] = |10-11| = 1

    Index 2:
        leftSum  = 10+4 = 14
        rightSum = 3
        answer[2] = |14-3| = 11

    Index 3:
        leftSum  = 10+4+8 = 22
        rightSum = 0
        answer[3] = |22-0| = 22

    Result:
        [15,1,11,22]

    ============================================================
    */



    /*
    ============================================================
    SOLUTION 1 : BRUTE FORCE
    ============================================================

    IDEA:
    -----
    For every index:

        1. Calculate left sum by traversing all elements
           before the current index.

        2. Calculate right sum by traversing all elements
           after the current index.

        3. Store absolute difference.

    ALGORITHM:
    ----------
    For each index i:

        leftSum = sum(nums[0...i-1])

        rightSum = sum(nums[i+1...n-1])

        answer[i] = abs(leftSum - rightSum)

    TIME COMPLEXITY:
    ----------------
    Outer loop : O(n)

    For each index:
        Left traversal  : O(n)
        Right traversal : O(n)

    Total:
        O(n²)

    SPACE COMPLEXITY:
    -----------------
    O(n) for answer array

    ============================================================
    */
    vector<int> leftRigthDifferenceBrute(vector<int> nums) {

        int n = nums.size();

        vector<int> answer(n);

        for (int i = 0; i < n; i++) {

            int leftSum = 0;
            int rightSum = 0;

            for (int j = 0; j < i; j++)
                leftSum += nums[j];

            for (int j = i + 1; j < n; j++)
                rightSum += nums[j];

            answer[i] = abs(leftSum - rightSum);
        }

        return answer;
    }



    /*
    ============================================================
    SOLUTION 2 : BETTER APPROACH
    ============================================================

    IDEA:
    -----
    Precompute:

        prefixSum[i]
            = sum from index 0 to i

        suffixSum[i]
            = sum from index i to n-1

    Then:

        leftSum
            = prefixSum[i-1]

        rightSum
            = suffixSum[i+1]

    Both become O(1) lookups.

    ALGORITHM:
    ----------
    1. Build prefix array.
    2. Build suffix array.
    3. For every index:
           left  = prefix[i-1]
           right = suffix[i+1]
           answer[i] = abs(left-right)

    TIME COMPLEXITY:
    ----------------
    Prefix Construction : O(n)

    Suffix Construction : O(n)

    Answer Construction : O(n)

    Total : O(n)

    SPACE COMPLEXITY:
    -----------------
    Prefix array : O(n)

    Suffix array : O(n)

    Answer array : O(n)

    Total : O(n)

    ============================================================
    */
    vector<int> leftRigthDifferenceBetter(vector<int> nums) {

        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> answer(n);

        prefix[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        suffix[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] + nums[i];

        for (int i = 0; i < n; i++) {

            int leftSum = (i == 0) ? 0 : prefix[i - 1];

            int rightSum = (i == n - 1) ? 0 : suffix[i + 1];

            answer[i] = abs(leftSum - rightSum);
        }

        return answer;
    }



    /*
    ============================================================
    SOLUTION 3 : OPTIMAL
    ============================================================

    KEY OBSERVATION:
    ----------------

    We don't actually need a suffix array.

    Let:

        totalSum = sum of entire array

    While traversing:

        leftSum  = sum of elements processed so far

        rightSum = totalSum - leftSum - nums[i]

    Because:

        totalSum
            =
        left part
        + current element
        + right part

    Therefore:

        rightSum
            =
        totalSum - leftSum - nums[i]

    This allows us to compute both sums in O(1)
    using only two variables.

    ------------------------------------------------------------
    ALGORITHM
    ------------------------------------------------------------

    Step 1:
        Calculate totalSum.

    Step 2:
        leftSum = 0

    Step 3:
        For every index i:

            rightSum =
                totalSum - leftSum - nums[i]

            answer[i] =
                abs(leftSum - rightSum)

            leftSum += nums[i]

    ------------------------------------------------------------
    TIME COMPLEXITY
    ------------------------------------------------------------

    First pass (total sum)  : O(n)

    Second pass (answer)    : O(n)

    Total:
        O(n)

    ------------------------------------------------------------
    SPACE COMPLEXITY
    ------------------------------------------------------------

    Extra variables:
        totalSum
        leftSum
        rightSum

    O(1) extra space

    (excluding output array)

    ============================================================
    */
    vector<int> leftRigthDifference(vector<int>& nums) {

        int n = nums.size();

        vector<int> answer(n);

        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        int leftSum = 0;

        for (int i = 0; i < n; i++) {

            int rightSum =
                totalSum - leftSum - nums[i];

            answer[i] =
                abs(leftSum - rightSum);

            leftSum += nums[i];
        }

        return answer;
    }
};



/*
============================================================
DRY RUN
============================================================

nums = [10,4,8,3]

Step 1:
    totalSum = 25

------------------------------------------------------------

i = 0

leftSum = 0

rightSum
= 25 - 0 - 10
= 15

answer[0]
= |0 - 15|
= 15

leftSum += 10

leftSum = 10

------------------------------------------------------------

i = 1

rightSum
= 25 - 10 - 4
= 11

answer[1]
= |10 - 11|
= 1

leftSum = 14

------------------------------------------------------------

i = 2

rightSum
= 25 - 14 - 8
= 3

answer[2]
= |14 - 3|
= 11

leftSum = 22

------------------------------------------------------------

i = 3

rightSum
= 25 - 22 - 3
= 0

answer[3]
= |22 - 0|
= 22

Result:

[15,1,11,22]

============================================================
INTUITION
============================================================

At every index:

    Total Sum
        =
    Left Sum
    + Current Element
    + Right Sum

Rearranging:

    Right Sum
        =
    Total Sum
    - Left Sum
    - Current Element

Thus one running variable (leftSum)
and one precomputed value (totalSum)
are enough.

============================================================
COMPLEXITY SUMMARY
============================================================

Brute Force:
    Time  : O(n²)
    Space : O(n)

Better (Prefix + Suffix):
    Time  : O(n)
    Space : O(n)

Optimal:
    Time  : O(n)
    Space : O(1) extra

LeetCode Accepted Solution:
    leftRigthDifference()

============================================================
*/