#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_Brute {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long power = n;

        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        for (long long i = 1; i <= power; i++) {
            ans *= x;
        }
        
        return ans;
    }
};


class Solution_Recursive {
public:
    double solve(double x, long n) {
        /*
        if (n == 0) return 1;
        if (n < 0) {
            return solve(1/x, -n);
        }
        if (n % 2 == 0) {
            return solve(x * x, n / 2);
        }

        return x * solve(x * x, (n - 1) / 2);
        
        */
        if (n == 0) return 1;
        if (n < 0) {
            return solve(1 / x, -n);
        }

        double res = solve(x, n/2);
        if (n & 1) {
            return x * res * res;
        } else {
            return res * res;
        }
    }

    double myPow(double x, int n) {
        return solve(x, n);
    }
};
class Solution_Iterative {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -nn;

        while (nn) {
            if (nn & 1) {
                ans = ans * x;
                nn -= 1;
            }
            
            x = x*x;
            nn /= 2;
        }

        return n < 0 ? 1 / ans : ans;
    }
};

int main() {
    
    return 0;
}