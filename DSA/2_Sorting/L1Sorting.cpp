

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {  // Correct comparison
                min = j;
            }
        }
        if (min != i) {
            swap(arr[i], arr[min]);

            // int temp = arr[i];
            // arr[i] = arr[min];
            // arr[min] = temp;
        }
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        int didSwap = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]); 

                // Swapping values
                // int temp = arr[j];
                // arr[j] = arr[j + 1];
                // arr[j + 1] = temp;

                didSwap = 1;
            }
        }
        // If no swaps happened in this pass, array is already sorted
        if (didSwap == 0) {
            break;
        }
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

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
    newline1;

    int arr[5] = {5, 4, 3, 2, 1};
    cout << "Before Sorting: " << endl;
    printArr(arr, 5);

    cout << "After Selection Sorting: " << endl;
    selectionSort(arr, 5);
    printArr(arr, 5);
    newline2;

    int arr2[6] = {9, 8, 7, 3, 2, 1};


    return 0;
}