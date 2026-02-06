/*
Merge Sort | Algorithm | Pseudocode | Dry Run | Code | Strivers A2Z DSA Course
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;

        int i = low;
        int j = mid + 1;
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }
        
        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }

        // for (int k = low; k <= high; k++) {
        //     arr[k] = temp[k - low];  // Correct indexing
        // }
        
    }
    void mergeSort(vector<int> &nums, int low, int high) {
        if (low >= high) return;

        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);

        return nums;
    }
};

int main() {
    
    return 0;
}