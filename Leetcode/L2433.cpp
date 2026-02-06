#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        for (int i = n-1; i >= 1; i--) {
            pref[i] = pref[i] ^ pref[i - 1];
        }

        return pref;
    }
};

int main() {
    
    return 0;
}