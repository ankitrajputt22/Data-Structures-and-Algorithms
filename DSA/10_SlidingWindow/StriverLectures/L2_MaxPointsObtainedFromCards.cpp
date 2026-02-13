#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
===========================================================
LeetCode 1423 - Maximum Points You Can Obtain from Cards
===========================================================

PROBLEM SUMMARY:
You are given an integer array cardPoints and an integer k.
You can take exactly k cards from either the beginning or the end.
Return the maximum score you can obtain.

-----------------------------------------------------------
KEY OBSERVATION:
If we take k cards from the ends,
it is equivalent to removing (n - k) contiguous cards from the middle.

-----------------------------------------------------------
APPROACH 1 — Brute Force (Try all combinations)
-----------------------------------------------------------
Idea:
Pick x cards from left and (k - x) from right.
Try all x from 0 to k.

Time Complexity:  O(k^2)
Space Complexity: O(1)

Not optimal for large k.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int pickS = k;
        int maxS = INT_MIN;

        while (pickS >= 0) {
            int sum = 0;

            // pick from left
            for (int i = 0; i < pickS; i++)
                sum += cardPoints[i];

            // pick from right
            for (int i = n - 1; i > n - 1 - (k - pickS); i--)
                sum += cardPoints[i];

            maxS = max(sum, maxS);
            pickS--;
        }

        return maxS;
    }
};


/*
-----------------------------------------------------------
APPROACH 2 — Prefix Sum Optimization
-----------------------------------------------------------
Idea:
Precompute prefix sums.
Use prefix to compute left and right sums in O(1).

Time Complexity:  O(n + k)
Space Complexity: O(1)  (in-place prefix)

Still slightly more complex than needed.
*/

class Solution2 {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // Build prefix sum array (in-place)
        for (int i = 1; i < n; i++)
            cardPoints[i] += cardPoints[i - 1];

        // Case: take all k from right
        int maxS = cardPoints[n - 1];
        if (n - k - 1 >= 0)
            maxS -= cardPoints[n - k - 1];

        int pickS = k;

        while (pickS > 0) {
            int sum = 0;

            // left part
            sum += cardPoints[pickS - 1];

            // right part
            sum += cardPoints[n - 1] - 
                   cardPoints[n - 1 - (k - pickS)];

            maxS = max(maxS, sum);
            pickS--;
        }

        return maxS;
    }
};


/*
-----------------------------------------------------------
APPROACH 3 — Sliding Window (Optimal & Cleanest)
-----------------------------------------------------------
Idea:
1. First take first k elements.
2. Gradually remove one element from left
   and add one element from right.
3. Maintain maximum sum.

Time Complexity:  O(k)
Space Complexity: O(1)

Best solution.
*/

class Solution3 {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();

        // initial window: first k elements
        int maxSum = 0;
        for (int i = 0; i < k; i++)
            maxSum += a[i];

        int s = maxSum;
        int i = k - 1;
        int j = n;

        // shift window
        while (i >= 0) {
            s -= a[i];   // remove from left
            i--;

            j--;
            s += a[j];   // add from right

            maxSum = max(maxSum, s);
        }

        return maxSum;
    }
};


/*
-----------------------------------------------------------
BONUS — Most Optimal Conceptual Method (Sliding Window on Middle)
-----------------------------------------------------------

Instead of selecting k cards from ends,
we remove (n - k) contiguous cards from the middle.

Total Sum - Minimum Subarray of size (n - k)

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution4 {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        int total = accumulate(a.begin(), a.end(), 0);

        if (k == n) return total;

        int windowSize = n - k;
        int curr = 0;

        // initial window
        for (int i = 0; i < windowSize; i++)
            curr += a[i];

        int minSub = curr;

        for (int i = windowSize; i < n; i++) {
            curr += a[i] - a[i - windowSize];
            minSub = min(minSub, curr);
        }

        return total - minSub;
    }
};


/*
===========================================================
FINAL SUMMARY
===========================================================

Solution1 → Brute Force (O(k^2))
Solution2 → Prefix Sum (O(n + k))
Solution3 → Sliding Window (O(k))  ✔ Recommended
Solution4 → Remove Middle Window (O(n))  ✔ Most Elegant

For interviews:
Mention Solution4 concept.
Implement Solution3 for clean code.
===========================================================
*/


// Optional Main Function for Testing

int main() {
    vector<int> cards = {1,2,3,4,5,6,1};
    int k = 3;

    Solution3 obj;
    cout << obj.maxScore(cards, k) << endl;  // Expected Output: 12

    return 0;
}
