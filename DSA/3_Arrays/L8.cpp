#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";
void printMaxSArray(vector<int> &arr, int start, int end) {
    cout << "SubArray is: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printMaxS_Subarray(vector<int> &arr) {
    int n = arr.size();

    int sum = 0, maxS = INT_MIN;
    int start = 0, tempStart = 0, end = 0;

    for (int i = 0; i < n; i++) {
        if (sum == 0) tempStart = i;  // or the code in if (sum < 0) block

        sum += arr[i];

        if (sum > maxS) {
            maxS = sum;
            start = tempStart;
            end = i;
        }

        if (sum < 0) {
            sum = 0;
            // tempStart = i + 1;  // next element might be new subarray start
        }
    }

    printMaxSArray(arr, start, end);
    cout << "Sum of MaxSum subarray is: " << maxS << endl;
}

int main() {
    newline1;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printMaxS_Subarray(nums);
    newline2;

    return 0;
}