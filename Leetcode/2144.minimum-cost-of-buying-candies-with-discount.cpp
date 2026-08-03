#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    ============================================================
    PROBLEM: 2144. Minimum Cost of Buying Candies With Discount
    ============================================================

    You are given an array candies where candies[i] represents
    the cost of the ith candy.

    OFFER:
    For every 3 candies purchased, the cheapest candy among
    those 3 candies becomes FREE.

    GOAL:
    Minimize the total amount of money spent.

    ------------------------------------------------------------
    KEY OBSERVATION
    ------------------------------------------------------------
    To maximize the discount, we should try to make the FREE
    candy as expensive as possible.

    Therefore, we should group expensive candies together.

    Example:
    candies = [6,5,7,9,2,2]

    Sort descending:
    [9,7,6,5,2,2]

    Groups:
    (9,7,6) -> 6 is free
    (5,2,2) -> 2 is free

    Cost = 9 + 7 + 5 + 2 = 23
    ============================================================
    */



    /*
    ============================================================
    SOLUTION 1 : BRUTE FORCE (Educational Approach)
    ============================================================

    IDEA:
    -----
    Try to form groups after sorting in descending order.

    Once sorted:
    Every third candy becomes free.

    We explicitly process candies in groups of three.

    ALGORITHM:
    ----------
    1. Sort in descending order.
    2. Traverse in chunks of size 3.
    3. Add first and second candy cost.
    4. Skip third candy (free).

    TIME COMPLEXITY:
    ----------------
    Sorting : O(n log n)
    Traversal : O(n)

    Total : O(n log n)

    SPACE COMPLEXITY:
    -----------------
    O(1) extra (ignoring sorting space)
    ============================================================
    */
    int minimumCostBrute(vector<int> candies) {

        sort(candies.begin(), candies.end(), greater<int>());

        int cost = 0;

        for (int i = 0; i < (int)candies.size(); i += 3) {

            cost += candies[i];

            if (i + 1 < candies.size())
                cost += candies[i + 1];

            // i+2 candy is free
        }

        return cost;
    }



    /*
    ============================================================
    SOLUTION 2 : BETTER APPROACH
    ============================================================

    IDEA:
    -----
    After sorting in descending order, every third candy
    contributes nothing to the answer.

    Instead of processing groups explicitly, simply:

    - Add all candies except indices:
      2, 5, 8, 11, ...

    because these positions correspond to the cheapest candy
    inside every group of three.

    ALGORITHM:
    ----------
    1. Sort descending.
    2. Traverse all indices.
    3. Skip every index where (i % 3 == 2).

    TIME COMPLEXITY:
    ----------------
    O(n log n)

    SPACE COMPLEXITY:
    -----------------
    O(1)
    ============================================================
    */
    int minimumCostBetter(vector<int> candies) {

        sort(candies.begin(), candies.end(), greater<int>());

        int cost = 0;

        for (int i = 0; i < (int)candies.size(); i++) {

            if (i % 3 == 2)
                continue;   // free candy

            cost += candies[i];
        }

        return cost;
    }



    /*
    ============================================================
    SOLUTION 3 : OPTIMAL
    ============================================================

    IMPORTANT CONSTRAINT:
    ---------------------
    1 <= candies[i] <= 100

    Since candy cost is bounded by 100, we can avoid sorting
    using a frequency array (Counting Sort idea).

    IDEA:
    -----
    Process costs from 100 down to 1 exactly as if the array
    were sorted in descending order.

    Maintain position count in the virtual sorted sequence.

    Positions:
        0 -> pay
        1 -> pay
        2 -> free
        3 -> pay
        4 -> pay
        5 -> free
        ...

    Therefore:
        position % 3 == 2  => free candy

    ALGORITHM:
    ----------
    1. Build frequency array of size 101.
    2. Traverse cost from 100 down to 1.
    3. For every occurrence:
          if position % 3 != 2
               add cost
          else
               free
          position++

    TIME COMPLEXITY:
    ----------------
    O(n + 100)

    SPACE COMPLEXITY:
    -----------------
    O(100) = O(1)

    This is optimal because we avoid comparison sorting.
    ============================================================
    */
    int minimumCost(vector<int>& candies) {

        vector<int> freq(101, 0);

        for (int cost : candies)
            freq[cost]++;

        int answer = 0;
        int position = 0;

        for (int cost = 100; cost >= 1; cost--) {

            while (freq[cost]--) {

                if (position % 3 != 2)
                    answer += cost;

                position++;
            }
        }

        return answer;
    }
};


/*
============================================================
DRY RUN

candies = [6,5,7,9,2,2]

Sorted descending:
[9,7,6,5,2,2]

Index : 0 1 2 3 4 5
Value : 9 7 6 5 2 2

Pay  -> 9
Pay  -> 7
Free -> 6

Pay  -> 5
Pay  -> 2
Free -> 2

Answer = 9 + 7 + 5 + 2 = 23

============================================================

INTERVIEW TAKEAWAY
============================================================

Brute:
    Sort descending and process groups of 3.

Better:
    Sort descending and skip every 3rd candy.

Optimal:
    Use counting sort because candy cost is bounded
    (1 <= candies[i] <= 100).

Complexities:

Brute  : O(n log n)
Better : O(n log n)
Optimal: O(n + 100)

LeetCode accepted optimal solution:
    minimumCost()

============================================================
*/