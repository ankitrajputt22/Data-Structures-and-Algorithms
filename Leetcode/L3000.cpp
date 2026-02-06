#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//Approach (Simple and straight forward)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        int maxDiag = 0;
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];

            int diag = l*l + w*w;
            int area = l*w;

            if(diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if(diag == maxDiag) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};

int main() {
    
    return 0;
}