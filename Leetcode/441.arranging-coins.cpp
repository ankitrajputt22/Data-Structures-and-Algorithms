/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        
    }
};
// @lc code=end



/*
Explanation:

For each row, you check if you have enough coins to complete it.

Subtract until you can’t complete the next row.

Time: O(k) ≈ O(√n) in practice but can be up to O(n)
Space: O(1)

*/
int arrangeCoins(int n) {
    int row = 0;
    while (n >= row + 1) {
        row++;
        n -= row;
    }
    return row;
}



/*
Explanation:
You search for the largest k such that the triangular number ≤ n.
Return right since it will be the last valid full row.
Time: O(log n)
Space: O(1)

*/
int arrangeCoins(int n) {
    long long left = 0, right = n, mid, curr;
    while (left <= right) {
        mid = left + (right - left) / 2;
        curr = mid * (mid + 1) / 2;
        if (curr == n) return mid;
        if (curr < n)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}



/*
Explanation:

We directly compute the largest integer k that fits the inequality.

Time: O(1)
Space: O(1)

*/
#include <cmath>

int arrangeCoins(int n) {
    return (int)((sqrt(8.0 * n + 1) - 1) / 2);
}
