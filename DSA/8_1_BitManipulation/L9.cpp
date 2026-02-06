#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle division by zero
        if (divisor == 0) return INT_MAX;
        
        // Handle special case: INT_MIN / -1
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        // Convert to long long to avoid overflow
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        
        long long sum = 0;
        long long cnt = 0;

        while (sum + ldivisor <= ldividend) {
            cnt++;
            sum += ldivisor;
        }

        // Determine the sign of the result
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            cnt = -cnt;
        }

        // Check for overflow
        if (cnt > INT_MAX) return INT_MAX;
        if (cnt < INT_MIN) return INT_MIN;
        
        return (int)cnt;
    }
};

class Solution_2 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        bool sign = true;
        if ((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0)) sign = false;

        long n = abs(long(dividend));
        long d = abs(long(divisor));

        long quotient = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) { // here cnt+1 => we are checking for the next one
                cnt++;
            }
        
            quotient += 1 << cnt;
            n -= (d << cnt);
        }

        if (quotient == (1 << 31) && sign) return INT_MAX;
        if (quotient == (1 << 31) && !sign) return INT_MIN;

        return sign ? quotient : -quotient;
    }
};

int main() {
    
    return 0;
}