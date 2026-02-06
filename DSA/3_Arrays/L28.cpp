
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_Brute {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            long long a = nums[i];
            for (int j = i+1; j < n; j++) {
                long long b = (long long)2 * nums[j];
                if (a > b) {
                    cnt++;
                }                                           
            }   
        }

        return cnt;
    }
};

class Solution_Optimal {
  public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        vector<int> temp;
        
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
            temp.push_back(arr[i++]);
        }
        
        while (j <= high) {
            temp.push_back(arr[j++]);
        }
        
        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > (long long)2 * arr[right]) right++;
            cnt += right - (mid + 1);
        }
        return cnt;
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;                   
        if (low >= high) return cnt;    
        
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);     
        cnt += mergeSort(arr, mid + 1, high); 

        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);   
        
        return cnt;  
    }
  
    int reversePairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};




int main() {
    
    return 0;
}