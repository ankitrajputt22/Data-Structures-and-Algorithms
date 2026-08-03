/*
 * LeetCode 50 - Pow(x, n)
 *
 * Implement x^n
 *
 * Approaches included in this file:
 * 1. Brute Force
 * 2. Recursive Binary Exponentiation
 * 3. Iterative Binary Exponentiation (Optimal)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -------------------------------
    // 1. Brute Force
    // Multiply x, n times
    // Time: O(n)
    // -------------------------------
    double bruteForce(double x, int n) {

        long long nn = abs((long long)n);
        double ans = 1;

        for(int i = 0; i < nn; i++) {
            ans *= x;
        }

        // handle negative power
        return n < 0 ? 1/ans : ans;
    }


    // -------------------------------
    // 2. Recursive Binary Exponentiation
    // Divide power by half each time
    // Time: O(log n)
    // -------------------------------
    double solve(double x, long n) {

        // base case
        if (n == 0) return 1;

        // handle negative power
        if (n < 0) {
            return solve(1/x, -n);
        }

        // compute half power
        double res = solve(x, n/2);

        // if n is odd multiply extra x
        if (n & 1)
            return x * res * res;
        else
            return res * res;
    }

    double recursivePow(double x, int n) {
        return solve(x, n);
    }


    // -------------------------------
    // 3. Iterative Binary Exponentiation
    // Most optimal solution
    // Time: O(log n)
    // Space: O(1)
    // -------------------------------
    double iterativePow(double x, int n) {

        double ans = 1.0;

        // use long long to avoid overflow
        long long nn = n;

        // convert negative exponent
        if (nn < 0) nn = -nn;

        while (nn) {

            // if exponent is odd
            if (nn & 1) {
                ans *= x;
                nn -= 1;
            }

            // square the base
            x = x * x;

            // halve the exponent
            nn /= 2;
        }

        // if original exponent was negative
        return n < 0 ? 1/ans : ans;
    }


    // LeetCode function (uses optimal approach)
    double myPow(double x, int n) {
        return iterativePow(x, n);
    }
};


// Example driver code
int main() {

    Solution obj;

    double x = 2.0;
    int n = 10;

    cout << "Brute Force: " << obj.bruteForce(x, n) << endl;
    cout << "Recursive: " << obj.recursivePow(x, n) << endl;
    cout << "Iterative (Optimal): " << obj.iterativePow(x, n) << endl;

    return 0;
}

/*
Key Idea:
Use Binary Exponentiation

Example:
2^10

2^10 = (2^5)^2
2^5  = 2 * (2^2)^2

Time Complexity:
Brute Force  -> O(n)
Binary Power -> O(log n)

Space Complexity:
Recursive -> O(log n)
Iterative -> O(1)
*/