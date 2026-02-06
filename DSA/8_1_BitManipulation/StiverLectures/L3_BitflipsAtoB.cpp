#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";



class Solution {
public:
    int minBitFlips(int start, int goal) {
        int Xor = start ^ goal;

        int setB = __builtin_popcount(Xor);

        return setB;
    }
};


class SolutionBrute {
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


class Solution3 {
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

class Solution4 {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int cnt = 0;
        
        while(n > 1) {
            cnt += n & 1;
            n = n >> 1;
        }

        if (n == 1) cnt++;
        
        return cnt;
    }
};


class Solution5 {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int count = 0;

        while(ans > 0) { 
            count += (ans & 1); 
            ans >>= 1;          
        }

        return count;
    }
};

int main() {
    newline2;

    

    newline2;
    return 0;
}