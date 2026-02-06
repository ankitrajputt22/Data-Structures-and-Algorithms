#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

int BruteForce_maxSubarrayWithSumK(vector<int> &arr, int tar) {
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum == tar) len = max(len, j - i + 1);
        }
    }
    return len;
}

int BruteForce2_maxSubarrayWithSumK(vector<int> &arr, int tar) {
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == tar) len = max(len, j - i + 1);
        }
    }
    return len;
}

int Better_maxSubarrayLenWithSumK(vector<int> &arr, int k) {
    unordered_map<int, int> prefixIndex;
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // If prefixSum itself is equal to target
        if (prefixSum == k) maxLen = i + 1;
            

        // If (prefixSum - k) seen before
        int rem = prefixSum - k;
        if (prefixIndex.find(rem) != prefixIndex.end()) {
            int len = i - prefixIndex[rem];
            maxLen = max(maxLen, len);
        }

        // Store the first occurrence of prefixSum
        if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
            prefixIndex[prefixSum] = i;
        }  
    }

    return maxLen;
}

int Optimal_Positives_maxSubarrayLenWithSumK(vector<int> &arr, int k) {
    int n = arr.size();

    int i = 0, j = 0;
    int sum = 0, len = 0;
    while (j < n) {
        sum += arr[j];

        if (sum == k) len = max(len, j - i + 1);

        while (sum > k) {
            sum -= arr[i];
            i++;
        }

        j++;
    }
    
    return len;
}


int main() {
    
    return 0;
}