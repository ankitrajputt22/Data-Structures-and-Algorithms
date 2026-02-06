#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


//Approach-1 - Maths derivation
//T.C : O(log(num1)) upper bound
//S.C : O(1)
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 0;

        while(true) {
            long long val = (long long)num1 - (long long)t * num2;

            if(val < 0)
                return -1;
            
            if(__builtin_popcountll(val) <= t && t <= val) {
                return t;
            }

            t++;
        }

        return -1;
    }
};


//Approach-2 - Maths derivation and finding strict bound of t
//T.C : O(log(num1)) upper bound
//S.C : O(1)
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {

        for(int t = 1; t <= 36; t++) {
            long long val = (long long)num1 - (long long)t * num2;

            if(val < 0)
                return -1;
            
            if(__builtin_popcountll(val) <= t && t <= val) {
                return t;
            }
        }

        return -1;
    }
};


int main() {
    
    return 0;
}