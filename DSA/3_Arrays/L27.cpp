


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_Brute {
  public:
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (arr[i] > arr[j]) cnt++;
            }
        }  
        
        return cnt;
    }
};

class Solution_Optimal {
  public:
    int merge(vector<int> &arr, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int cnt = 0;
        vector<int> temp;
        
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                cnt += (mid - i + 1);  
            }
        }
        
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }
        
        while (j <= high) {
            temp.push_back(arr[j++]);
        }
        
        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
        
        return cnt;
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;                    // Local counter for THIS function call
        if (low >= high) return cnt;    // Base case: return 0 for single element
        
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);     // Count inversions in left half
        cnt += mergeSort(arr, mid + 1, high); // Count inversions in right half
        cnt += merge(arr, low, mid, high);   // Count cross inversions during merge
        
        return cnt;  // Return total for this subtree
    }
  
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    
    return 0;
}