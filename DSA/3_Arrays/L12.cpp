#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        vector<int> leader;
        for (int i = 0; i < n; i++) {
            bool isLeader = true;
            for (int j = i+1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    isLeader = false;
                }
            }
            
            if (isLeader) {
                leader.push_back(arr[i]);
            }
        }
        
        return leader;
    }
};




class Solution_2 {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        int rightMax = -1;
        vector<int> leader;
        for (int i = n-1; i >= 0; i--) {
            if (arr[i] >= rightMax) {
                leader.push_back(arr[i]);
            }
            
            rightMax = max(rightMax, arr[i]);
        }
        
        reverse(leader.begin(), leader.end());
        return leader;
    }
};

int main() {
    
    return 0;
}