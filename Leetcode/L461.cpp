#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;

        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1 == 1) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    
    return 0;
}