#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


class Solution {
public:
    double solve(double x, long n) {
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


class Solution {
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


class Solution {
public:
    double solve(double x, long n) {
        if (n == 0) return 1;
        if (n < 0) {
            return solve(1/x, -n);
        }
        if (n % 2 == 0) {
            return solve(x * x, n / 2);
        }

        return x * solve(x * x, (n - 1) / 2);
    }


    double myPow(double x, int n) {
        return solve(x, n);
    }
};


class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) nn = (-1) * nn;
        while(nn) {
            if(nn % 2){
                ans = ans * x;
                nn = nn - 1;
            } else{
                x = x * x;
                nn = nn / 2;
            }
        }
        if(n < 0) ans = (double)(1.0) / (double)(ans);
        return ans; 
    }
};


int main() {
    
    return 0;
}