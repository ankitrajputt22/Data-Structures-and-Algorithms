#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

int main() {
    newline2;

    

    newline2;
    return 0;
}

class Solution {
  public:
    void helper(int i, int sum, vector<int> &arr, vector<int> &res) {
        if (i == arr.size()) {
            res.push_back(sum);
            return;
        }
        
        helper(i+1, sum+arr[i], arr, res);
        helper(i+1, sum, arr, res);
    }
  
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        helper(0, 0, arr, res);
        
        return res;
    }
};