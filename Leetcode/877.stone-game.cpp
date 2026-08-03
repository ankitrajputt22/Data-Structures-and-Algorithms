/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 *
 * ============================================================================
 * PROBLEM SUMMARY
 * ============================================================================
 *
 * Alice and Bob play a game with an even number of piles.
 *
 * Rules:
 * 1. Each pile contains a positive number of stones.
 * 2. The total number of stones is odd, so a tie is impossible.
 * 3. Alice plays first.
 * 4. On every turn, a player can take either:
 *      - The first pile
 *      - The last pile
 * 5. Both players play optimally.
 *
 * Return true if Alice wins.
 *
 * Example:
 *
 *      piles = [5, 3, 4, 5]
 *
 * Alice can take the first 5.
 * Remaining piles:
 *
 *      [3, 4, 5]
 *
 * Whatever Bob chooses, Alice can collect more stones.
 *
 * Answer:
 *
 *      true
 *
 * ============================================================================
 * IMPORTANT OBSERVATION
 * ============================================================================
 *
 * For this exact problem, Alice always wins.
 *
 * Why?
 *
 * - The number of piles is even.
 * - Alice can choose whether she wants to collect piles from:
 *
 *      Even indexes: 0, 2, 4, ...
 *
 *   or:
 *
 *      Odd indexes: 1, 3, 5, ...
 *
 * - One of these two groups must have a larger total because the complete
 *   number of stones is odd.
 * - Alice can force herself to collect all piles from the group having the
 *   larger sum.
 *
 * Therefore:
 *
 *      return true;
 *
 * However, the standard Optimal Game Strategy DP is also important because
 * it works for more general versions of this problem.
 */


#include <bits/stdc++.h>
using namespace std;


/*
===============================================================================
APPROACH 1: RECURSION + MEMOIZATION
===============================================================================

Standard Optimal Game Strategy

State:

    solve(i, j)

represents the maximum number of stones the current player can guarantee from:

    piles[i ... j]

The current player has two choices:

1. Take piles[i]
2. Take piles[j]

Both players play optimally.

Therefore, after the current player makes a choice, the opponent will make the
move that leaves the minimum possible score for the current player.

That is why min() is used inside both choices.

-------------------------------------------------------------------------------
CASE 1: CURRENT PLAYER TAKES piles[i]
-------------------------------------------------------------------------------

Remaining range:

    [i + 1 ... j]

Now the opponent can take:

1. piles[i + 1]
2. piles[j]

If the opponent takes piles[i + 1], the current player receives:

    solve(i + 2, j)

If the opponent takes piles[j], the current player receives:

    solve(i + 1, j - 1)

The opponent chooses the worse result for the current player:

    min(
        solve(i + 2, j),
        solve(i + 1, j - 1)
    )

Therefore:

    chooseLeft =
        piles[i] +
        min(
            solve(i + 2, j),
            solve(i + 1, j - 1)
        );

-------------------------------------------------------------------------------
CASE 2: CURRENT PLAYER TAKES piles[j]
-------------------------------------------------------------------------------

Remaining range:

    [i ... j - 1]

Now the opponent can take:

1. piles[i]
2. piles[j - 1]

If the opponent takes piles[i], the current player receives:

    solve(i + 1, j - 1)

If the opponent takes piles[j - 1], the current player receives:

    solve(i, j - 2)

Therefore:

    chooseRight =
        piles[j] +
        min(
            solve(i + 1, j - 1),
            solve(i, j - 2)
        );

The current player chooses the better option:

    max(chooseLeft, chooseRight)

-------------------------------------------------------------------------------
RECURRENCE
-------------------------------------------------------------------------------

solve(i, j) = max(

    piles[i] + min(
        solve(i + 2, j),
        solve(i + 1, j - 1)
    ),

    piles[j] + min(
        solve(i + 1, j - 1),
        solve(i, j - 2)
    )
)

-------------------------------------------------------------------------------
BASE CASE
-------------------------------------------------------------------------------

If no piles remain:

    i > j

return:

    0

If only one pile remains:

    i == j

return:

    piles[i]

-------------------------------------------------------------------------------
WHY min()?
-------------------------------------------------------------------------------

When it is our turn:

    We choose the maximum result.

When it is the opponent's turn:

    We assume the opponent plays optimally.

Therefore, the opponent leaves us the minimum possible future score.

Simple idea:

    Your turn     -> Expect the best  -> max()
    Opponent turn -> Expect the worst -> min()

-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

There are O(n^2) different states:

    (i, j)

Each state performs O(1) work.

Time Complexity:

    O(n^2)

-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

Memoization table:

    O(n^2)

Recursion stack:

    O(n)

Overall:

    O(n^2)
*/


class SolutionMemoization {
private:
    vector<vector<int>> memo;

    int solve(const vector<int>& piles, int i, int j) {
        // No piles remain.
        if (i > j) {
            return 0;
        }

        // Only one pile remains.
        if (i == j) {
            return piles[i];
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        /*
         * Take the left pile.
         *
         * The opponent then chooses the move that minimizes our future score.
         */
        int chooseLeft =
            piles[i] +
            min(
                solve(piles, i + 2, j),
                solve(piles, i + 1, j - 1)
            );

        /*
         * Take the right pile.
         *
         * The opponent again chooses the move that minimizes our future score.
         */
        int chooseRight =
            piles[j] +
            min(
                solve(piles, i + 1, j - 1),
                solve(piles, i, j - 2)
            );

        return memo[i][j] = max(chooseLeft, chooseRight);
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = static_cast<int>(piles.size());

        memo.assign(n, vector<int>(n, -1));

        int totalStones = accumulate(
            piles.begin(),
            piles.end(),
            0
        );

        int aliceScore = solve(piles, 0, n - 1);

        /*
         * Since the total number of stones is odd, a tie is impossible.
         *
         * Alice wins when she collects more than half of the total stones.
         */
        return aliceScore > totalStones / 2;
    }
};


/*
===============================================================================
APPROACH 2: TABULATION USING SCORE DIFFERENCE
===============================================================================

Instead of calculating the maximum stones collected by Alice directly, we can
calculate the maximum score difference that the current player can achieve.

State:

    dp[i][j]

represents:

    Maximum score difference the current player can achieve
    over the opponent from piles[i ... j]

Score difference:

    Current player's stones - Opponent's stones

-------------------------------------------------------------------------------
CHOICE 1: TAKE piles[i]
-------------------------------------------------------------------------------

The current player gains:

    piles[i]

After that, the opponent can achieve:

    dp[i + 1][j]

Therefore, the final difference is:

    piles[i] - dp[i + 1][j]

-------------------------------------------------------------------------------
CHOICE 2: TAKE piles[j]
-------------------------------------------------------------------------------

The current player gains:

    piles[j]

After that, the opponent can achieve:

    dp[i][j - 1]

Therefore, the final difference is:

    piles[j] - dp[i][j - 1]

-------------------------------------------------------------------------------
RECURRENCE
-------------------------------------------------------------------------------

dp[i][j] = max(

    piles[i] - dp[i + 1][j],

    piles[j] - dp[i][j - 1]
)

-------------------------------------------------------------------------------
BASE CASE
-------------------------------------------------------------------------------

When only one pile remains:

    dp[i][i] = piles[i]

The current player takes that complete pile.

-------------------------------------------------------------------------------
FINAL ANSWER
-------------------------------------------------------------------------------

If:

    dp[0][n - 1] > 0

then Alice gets more stones than Bob.

-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

    O(n^2)

-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

    O(n^2)
*/


class SolutionTabulation {
public:
    bool stoneGame(vector<int>& piles) {
        int n = static_cast<int>(piles.size());

        vector<vector<int>> dp(
            n,
            vector<int>(n, 0)
        );

        // Base case: only one pile is available.
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        /*
         * Build answers for intervals of increasing length.
         */
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i + length - 1 < n; i++) {
                int j = i + length - 1;

                int chooseLeft =
                    piles[i] - dp[i + 1][j];

                int chooseRight =
                    piles[j] - dp[i][j - 1];

                dp[i][j] = max(chooseLeft, chooseRight);
            }
        }

        return dp[0][n - 1] > 0;
    }
};


/*
===============================================================================
APPROACH 3: SPACE-OPTIMIZED DYNAMIC PROGRAMMING
===============================================================================

The two-dimensional recurrence is:

    dp[i][j] = max(
        piles[i] - dp[i + 1][j],
        piles[j] - dp[i][j - 1]
    )

For every interval, we only need values from intervals of one smaller length.

Therefore, the two-dimensional table can be reduced to one dimension.

Meaning of dp[i] during the calculation:

    Maximum score difference for the current interval starting at i.

Initial state:

    dp[i] = piles[i]

For every interval:

    dp[i] = max(
        piles[i] - dp[i + 1],
        piles[j] - dp[i]
    )

Important:

Before updating dp[i]:

    dp[i]     represents dp[i][j - 1]
    dp[i + 1] represents dp[i + 1][j]

-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

    O(n^2)

-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

    O(n)
*/


class SolutionSpaceOptimized {
public:
    bool stoneGame(vector<int>& piles) {
        int n = static_cast<int>(piles.size());

        /*
         * For an interval containing one pile:
         *
         * dp[i][i] = piles[i]
         */
        vector<int> dp = piles;

        for (int length = 2; length <= n; length++) {
            for (int i = 0; i + length - 1 < n; i++) {
                int j = i + length - 1;

                int chooseLeft =
                    piles[i] - dp[i + 1];

                int chooseRight =
                    piles[j] - dp[i];

                dp[i] = max(chooseLeft, chooseRight);
            }
        }

        return dp[0] > 0;
    }
};


/*
===============================================================================
APPROACH 4: MATHEMATICAL / PARITY STRATEGY
===============================================================================

This is the optimal solution for the exact constraints of LeetCode 877.

The number of piles is even.

Divide the piles according to their original indexes:

    Even-indexed piles:
        piles[0], piles[2], piles[4], ...

    Odd-indexed piles:
        piles[1], piles[3], piles[5], ...

Example:

    piles = [5, 3, 4, 5]
              0  1  2  3

Even-index sum:

    piles[0] + piles[2]
    = 5 + 4
    = 9

Odd-index sum:

    piles[1] + piles[3]
    = 3 + 5
    = 8

Alice can force herself to take all piles from one parity group.

-------------------------------------------------------------------------------
HOW CAN ALICE CHOOSE A PARITY?
-------------------------------------------------------------------------------

Because the number of piles is even:

- The first pile has an even index.
- The last pile has an odd index.

Therefore, on her first turn:

- Taking the first pile commits Alice to even-indexed piles.
- Taking the last pile commits Alice to odd-indexed piles.

After Bob's move, Alice can always continue choosing an end pile belonging to
her selected parity.

-------------------------------------------------------------------------------
WHY MUST ONE PARITY HAVE A LARGER SUM?
-------------------------------------------------------------------------------

The total number of stones is odd.

Let:

    evenSum = Sum of even-indexed piles
    oddSum  = Sum of odd-indexed piles

Then:

    evenSum + oddSum = Odd number

Therefore:

    evenSum != oddSum

One parity group must have a strictly larger sum.

Alice chooses that parity group and collects more than half of all stones.

Therefore, Alice always wins.

-------------------------------------------------------------------------------
TIME COMPLEXITY
-------------------------------------------------------------------------------

    O(1)

We do not even need to calculate the parity sums because the problem guarantees
that Alice has a winning strategy.

-------------------------------------------------------------------------------
SPACE COMPLEXITY
-------------------------------------------------------------------------------

    O(1)

-------------------------------------------------------------------------------
IMPORTANT NOTE
-------------------------------------------------------------------------------

The constant-time answer works because of these exact conditions:

1. The number of piles is even.
2. Every pile contains a positive number of stones.
3. The total number of stones is odd.
4. Players can only take the first or last pile.
5. Alice plays first.

If these conditions change, returning true may no longer be correct.

For example, the constant-time solution may not work directly when:

- The number of piles is odd.
- A tie is allowed.
- Players can take piles from other positions.
- Some piles contain negative values.
- Different move rules are used.

For such variants, use the dynamic programming solution.
*/


// @lc code=start

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

// @lc code=end


/*
===============================================================================
DRY RUN: SCORE-DIFFERENCE DP
===============================================================================

Input:

    piles = [5, 3, 4, 5]

Initial diagonal:

    dp[0][0] = 5
    dp[1][1] = 3
    dp[2][2] = 4
    dp[3][3] = 5

-------------------------------------------------------------------------------
INTERVAL LENGTH = 2
-------------------------------------------------------------------------------

Interval [0, 1]:

    [5, 3]

Take left:

    5 - dp[1][1]
    = 5 - 3
    = 2

Take right:

    3 - dp[0][0]
    = 3 - 5
    = -2

Therefore:

    dp[0][1] = 2

Interval [1, 2]:

    [3, 4]

Take left:

    3 - 4 = -1

Take right:

    4 - 3 = 1

Therefore:

    dp[1][2] = 1

Interval [2, 3]:

    [4, 5]

Take left:

    4 - 5 = -1

Take right:

    5 - 4 = 1

Therefore:

    dp[2][3] = 1

-------------------------------------------------------------------------------
INTERVAL LENGTH = 3
-------------------------------------------------------------------------------

Interval [0, 2]:

    [5, 3, 4]

Take left:

    5 - dp[1][2]
    = 5 - 1
    = 4

Take right:

    4 - dp[0][1]
    = 4 - 2
    = 2

Therefore:

    dp[0][2] = 4

Interval [1, 3]:

    [3, 4, 5]

Take left:

    3 - dp[2][3]
    = 3 - 1
    = 2

Take right:

    5 - dp[1][2]
    = 5 - 1
    = 4

Therefore:

    dp[1][3] = 4

-------------------------------------------------------------------------------
INTERVAL LENGTH = 4
-------------------------------------------------------------------------------

Interval [0, 3]:

    [5, 3, 4, 5]

Take left:

    5 - dp[1][3]
    = 5 - 4
    = 1

Take right:

    5 - dp[0][2]
    = 5 - 4
    = 1

Therefore:

    dp[0][3] = 1

Since:

    dp[0][3] > 0

Alice wins by exactly one stone.

===============================================================================
APPROACH COMPARISON
===============================================================================

Approach                      Time        Space       Main Idea
-------------------------------------------------------------------------------
Recursion + Memoization       O(n^2)      O(n^2)      Maximum guaranteed stones

2D Score-Difference DP        O(n^2)      O(n^2)      Current score - opponent

1D Score-Difference DP        O(n^2)      O(n)        Space-optimized interval DP

Parity Strategy               O(1)        O(1)        Alice always wins

===============================================================================
RECOMMENDED SOLUTION
===============================================================================

For LeetCode 877:

    return true;

For learning Optimal Game Strategy or solving modified versions:

    Use the score-difference dynamic programming approach.

===============================================================================
*/