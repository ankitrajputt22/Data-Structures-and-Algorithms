#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


class Solution {
public:
    int partitionIndHelper(vector<int>& nums, int low, int high) {
        int pivot = nums[low];   
        int i = low;
        int j = high;

        while (i < j) {
            while (nums[i] <= pivot && i < high) i++;
            while (nums[j] > pivot && j > low) j--;

            if (i < j) swap(nums[i], nums[j]);
        }

        swap(nums[low], nums[j]);   
        return j;
    }

    void quickSort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int pInd = partitionIndHelper(nums, low, high);
            
            quickSort(nums, low, pInd-1);
            quickSort(nums, pInd+1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        quickSort(nums, 0, n-1);

        return nums;
    }
};


int main() {
    newline2;

    

    newline2;
    return 0;
}