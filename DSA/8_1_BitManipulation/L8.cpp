#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
  public:
    int findXOR(int l, int r) {
        int xorr = 0;
        
        for (int i = l; i <= r; i++) {
            xorr ^= i;
        }
        
        return xorr;
    }
};

class Solution_2 {
  public:
    int xorCalculator1toN(int n) {
        if (n % 4 == 0) return n;
        else if (n % 4 == 1) return 1;
        else if (n % 4 == 2) return n+1;
        else if (n % 4 == 3) return 0;
    }
    int findXOR(int l, int r) {
        int a = xorCalculator1toN(l-1);
        int b = xorCalculator1toN(r);
        int ans = 0;
        
        //a ^ ans = b
        // a ^ ans ^ a = b ^ a
        // ans = b ^ a;
        
        ans = b ^ a;
        return ans;
    }
};

int main() {
    
    return 0;
}