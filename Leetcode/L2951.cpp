#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();

        vector<int> ans;
        for (int i = 1; i < n-1; i++) {
            if (mountain[i-1] < mountain[i] && mountain[i] > mountain[i+1]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}