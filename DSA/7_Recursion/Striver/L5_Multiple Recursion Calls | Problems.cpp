#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//509. Fibonacci Number
class Solution_1 {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int last = fib(n-1);
        int second_last = fib(n-2);

        return last + second_last;
    }
};

class Solution_2 {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution_3 {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int prev = 1;
        int prev2 = 0; 
        for (int i = 2; i <= n; i++) {
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }

        return prev;
    }
};


int main() {
    
    return 0;
}