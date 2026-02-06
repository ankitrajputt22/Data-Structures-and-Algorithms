#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


vector<int> alternateNumbers_App1(vector<int>& nums) {
    vector<int> pos, neg;
    
    for (int num : nums) {
        if (num > 0) pos.push_back(num);
        else neg.push_back(num);
    }

    vector<int> result;
    int i = 0, j = 0;

    // Alternate positives and negatives
    while (i < pos.size() && j < neg.size()) {
        result.push_back(pos[i++]);
        result.push_back(neg[j++]);
    }

    // Add remaining positives
    while (i < pos.size()) result.push_back(pos[i++]);

    // Add remaining negatives
    while (j < neg.size()) result.push_back(neg[j++]);

    return result;
}


vector<int> alternateNumbers_App2(vector<int>& nums) {
    int o = nums.size();

    vector<int> pos, neg;
    for (int i = 0; i < o; i++) {
        if (nums[i] > 0) {
            pos.push_back(nums[i]);
        }
        else {
            neg.push_back(nums[i]);
        }
    }
    
    int m = pos.size();
    int n = neg.size();

    if (m > n) {
        for (int i = 0; i < n; i++) {
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }

        int ind = n * 2;
        for (int i = n; i < m; i++) {
            nums[ind] = pos[i];
            ind++;
        }
    } else {
        for (int i = 0; i < m; i++) {
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }

        int ind = m * 2;
        for (int i = m; i < n; i++) {
            nums[ind] = neg[i];
            ind++;
        }
    }

    return nums;
}

void printVector(const vector<int> &v) {
    cout << "Vector elements: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    newline1;

    vector<int> nums = {1, 3, 4, -1, 3, 6, -2, 5};
    cout << "Original array: " << endl;
    printVector(nums);

    vector<int> res1 = alternateNumbers_App1(nums);
    cout << endl << "After altering the array App1: " << endl;
    printVector(res1);
    newline1;

    vector<int> res2 = alternateNumbers_App2(nums);
    cout << "After altering the array App2: " << endl;
    printVector(res2);
    newline2;


    return 0;
}