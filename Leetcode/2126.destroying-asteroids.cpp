#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    ============================================================
    2126. Destroying Asteroids
    ============================================================

    PROBLEM:
    --------
    You are given:

        mass = Initial mass of the planet.
        asteroids[i] = Mass of ith asteroid.

    RULE:
    -----
    If current_mass >= asteroid_mass:
        - Planet destroys the asteroid.
        - Planet gains asteroid_mass.

    Else:
        - Planet gets destroyed.
        - Answer = false.

    Return true if all asteroids can be destroyed,
    otherwise return false.

    ------------------------------------------------------------
    IMPORTANT OBSERVATION
    ------------------------------------------------------------

    To maximize our chances of survival, we should always
    destroy the smallest available asteroid first.

    Why?

    Suppose:

        current mass = 10
        asteroids = [3, 15]

    If we try 15 first:
        10 < 15 -> fail

    If we destroy 3 first:
        new mass = 13
        still cannot destroy 15

    Another example:

        current mass = 10
        asteroids = [2, 8]

    Destroy 2 first:
        mass = 12
        destroy 8
        mass = 20

    Thus processing smaller asteroids first is always
    the safest strategy.

    Therefore:
        Sort asteroids in ascending order.
    ============================================================
    */



    /*
    ============================================================
    SOLUTION 1 : BRUTE FORCE
    ============================================================

    IDEA:
    -----
    Repeatedly find the smallest asteroid that can currently
    be destroyed.

    Every iteration:
        - Search entire array.
        - Pick smallest destroyable asteroid.
        - Mark it visited.
        - Increase mass.

    This simulates the greedy idea without sorting.

    ALGORITHM:
    ----------
    While asteroids remain:
        Find minimum asteroid whose:
            asteroid <= current_mass

        If none exists:
            return false

        Destroy it
        Update mass

    TIME COMPLEXITY:
    ----------------
    O(n²)

    For every asteroid we may scan the entire array.

    SPACE COMPLEXITY:
    -----------------
    O(n) for visited array
    ============================================================
    */
    bool asteroidsDestroyedBrute(long long mass,
                                 vector<int> asteroids) {

        int n = asteroids.size();

        vector<bool> visited(n, false);

        for (int destroyed = 0; destroyed < n; destroyed++) {

            int idx = -1;
            int smallest = INT_MAX;

            for (int i = 0; i < n; i++) {

                if (!visited[i] &&
                    asteroids[i] <= mass &&
                    asteroids[i] < smallest) {

                    smallest = asteroids[i];
                    idx = i;
                }
            }

            if (idx == -1)
                return false;

            mass += asteroids[idx];
            visited[idx] = true;
        }

        return true;
    }



    /*
    ============================================================
    SOLUTION 2 : BETTER APPROACH (Sorting + Greedy)
    ============================================================

    IDEA:
    -----
    Sort all asteroids in ascending order.

    Then process from smallest to largest.

    If current asteroid can be destroyed:
        mass += asteroid

    Otherwise:
        return false

    WHY DOES THIS WORK?
    -------------------
    The smallest asteroid is always the easiest to destroy.

    Destroying smaller asteroids first increases our mass
    as early as possible, maximizing future opportunities.

    GREEDY PROOF:
    -------------
    If an asteroid cannot be destroyed after processing all
    smaller asteroids first, then no other ordering could
    have increased our mass more before reaching it.

    Hence sorted order is optimal.

    ALGORITHM:
    ----------
    1. Sort ascending.
    2. Traverse array.
    3. If mass < asteroid:
           return false
       Else:
           mass += asteroid
    4. Return true.

    TIME COMPLEXITY:
    ----------------
    Sorting  : O(n log n)
    Traversal: O(n)

    Total    : O(n log n)

    SPACE COMPLEXITY:
    -----------------
    O(1)
    ============================================================
    */
    bool asteroidsDestroyedBetter(long long mass,
                                  vector<int> asteroids) {

        sort(asteroids.begin(), asteroids.end());

        for (int asteroid : asteroids) {

            if (mass < asteroid)
                return false;

            mass += asteroid;
        }

        return true;
    }



    /*
    ============================================================
    SOLUTION 3 : OPTIMAL
    ============================================================

    CONSTRAINT:
    -----------
    1 <= asteroids[i] <= 100000

    Since asteroid masses are bounded, we can use a frequency
    array (Counting Sort idea) instead of comparison sorting.

    This removes O(n log n) sorting cost.

    IDEA:
    -----
    Count frequency of every asteroid mass.

    Then simulate sorted order by iterating from
    smallest mass to largest mass.

    For every occurrence:
        if current mass < asteroid:
             return false

        mass += asteroid

    ALGORITHM:
    ----------
    1. Build frequency array.
    2. Traverse mass values in increasing order.
    3. Process each occurrence.
    4. Return true if all processed.

    TIME COMPLEXITY:
    ----------------
    O(n + MAX_VALUE)

    MAX_VALUE = 100000

    Therefore:

        O(n + 100000)

    SPACE COMPLEXITY:
    -----------------
    O(100000)

    ------------------------------------------------------------
    NOTE:
    ------------------------------------------------------------
    On LeetCode most accepted solutions use sorting because
    O(n log n) is already fast enough.

    Theoretical optimal based on constraints:
        Counting Sort + Greedy

    Practical interview optimal:
        Sort + Greedy
    ============================================================
    */
    bool asteroidsDestroyed(long long mass,
                            vector<int>& asteroids) {

        const int MAX_ASTEROID = 100000;

        vector<int> freq(MAX_ASTEROID + 1, 0);

        for (int asteroid : asteroids)
            freq[asteroid]++;

        for (int value = 1; value <= MAX_ASTEROID; value++) {

            while (freq[value]--) {

                if (mass < value)
                    return false;

                mass += value;
            }
        }

        return true;
    }
};



/*
============================================================
DRY RUN
============================================================

mass = 10

asteroids = [3,9,19,5,21]

Sorted:

[3,5,9,19,21]

Step 1:
    mass = 10
    destroy 3
    mass = 13

Step 2:
    destroy 5
    mass = 18

Step 3:
    destroy 9
    mass = 27

Step 4:
    destroy 19
    mass = 46

Step 5:
    destroy 21
    mass = 67

Answer = true

============================================================
ANOTHER EXAMPLE
============================================================

mass = 5

asteroids = [4,9,23]

Sorted:

[4,9,23]

Destroy 4:
    mass = 9

Destroy 9:
    mass = 18

Cannot destroy 23:
    18 < 23

Answer = false

============================================================
GREEDY INTUITION
============================================================

Always destroy the smallest asteroid available.

Reason:
    Smaller asteroids are easiest to absorb.

Every asteroid absorbed increases mass.

The earlier we gain mass, the better our chances of
destroying larger asteroids later.

Thus sorting in ascending order is the optimal strategy.

============================================================
COMPLEXITY SUMMARY
============================================================

Brute Force:
    Time  : O(n²)
    Space : O(n)

Better (Sorting + Greedy):
    Time  : O(n log n)
    Space : O(1)

Optimal (Counting Sort + Greedy):
    Time  : O(n + 100000)
    Space : O(100000)

LeetCode Interview Optimal:
    Sort + Greedy

LeetCode Function:
    asteroidsDestroyed()

============================================================
*/