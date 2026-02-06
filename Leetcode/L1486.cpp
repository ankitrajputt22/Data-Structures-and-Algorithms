#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums(n);
        
        int xorr = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = start + 2*i;
            xorr ^= nums[i];
        }

        return xorr;
    }
};

int main() {
    
    return 0;
}