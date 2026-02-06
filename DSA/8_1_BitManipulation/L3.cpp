#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            int bit1 = (start>>i) & 1;
            int bit2 = (goal>>i) & 1;

            if (bit1 != bit2) cnt++;
        }

        return cnt;
    }
};

class Solution_2 {
public:
    int minBitFlips(int start, int goal) {
        int Xor = start ^ goal;

        int setB = __builtin_popcount(Xor);

        return setB;
    }
};

class Solution_3 {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int cnt = 0;

        for (int i = 0; i < 32; i++) {
            if (1 & (n >> i)) cnt++;
        }

        return cnt;
    }
};


int main() {
    
    return 0;
}