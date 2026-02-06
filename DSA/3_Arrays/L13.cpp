#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    bool ls(vector<int> &arr, int el) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == el) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        if (n == 0) return 0;
            
        
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            int len = 0;
            
            int el = arr[i];
            len++;
            
            while (ls(arr, el+1)) {
                len++;
                el = el + 1;
            }
            
            maxi = max(maxi, len);
        }   
        
        return maxi;
    }
};

class Solution_2 {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        sort(arr.begin(), arr.end());
        
        int maxLen = 1;  
        int currLen = 1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i-1]) {
                continue;  // Skip duplicates
            }
            else if (arr[i] == arr[i-1] + 1) {
                currLen++;
            }
            else {
                currLen = 1;  // Reset only for non-consecutive
            }
            maxLen = max(maxLen, currLen);
        }
        
        return maxLen;
    }
};


class Solution_3 {
public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(arr[i]);
        }
        
        int maxi = 1;
        for (auto el : st) {
            if (st.find(el - 1) == st.end()) { // el will be the first el in the subsequence
                int len = 1;
                
                while (st.find(el+1) != st.end()) {
                    el = el + 1;
                    len++;
                }
                
                maxi = max(len, maxi);
            }
        }
        
        return maxi;
    }
};

int main() {
    
    return 0;
}