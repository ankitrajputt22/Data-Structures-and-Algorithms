#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

/*
Algorithm: Sequential-Bubble-Sort (A)
fori ← 1 to length [A] do
for j ← length [A] down-to i +1 do
   if A[A] < A[j-1] then
      Exchange A[j] ⟷ A[j-1]
*/

void bubbleSort(int *array, int size){
   for(int i = 0; i<size; i++) {
      int swaps = 0; //flag to detect any swap is there or not
      for(int j = 0; j<size-i-1; j++) {
         if(array[j] > array[j+1]) { //when the current item is bigger than next
            int temp;
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            swaps = 1; //set swap flag
         }
      }
      if(!swaps)
         break; // No swap in this pass, so array is sorted
   }
}

/*
Algorithm: Insertion-Sort(A)
for j = 2 to A.length
   key = A[j]
   i = j  1
   while i > 0 and A[i] > key
      A[i + 1] = A[i]
      i = i -1
   A[i + 1] = key

*/


void insertionSort(int *array, int size){
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];//take value
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key; //insert in right place
   }
}


/*
Algorithm: Selection-Sort (A)
fori← 1 to n-1 do
   min j ←i;
   min x ← A[i]
   for j ←i + 1 to n do
      if A[j] < min x then
         min j ← j
         min x ← A[j]
   A[min j] ← A [i]
   A[i] ← min x

*/

void swapping(int &a, int &b) {  //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void selectionSort(int *array, int size){
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i; //get index of minimum data
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;

      //placing in correct position
      swap(array[i], array[imin]);
   }
}



/*
Merge Sort Algorithm
Step 1: If it is only one element in the list, consider it already 
sorted, so return.
Step 2: Divide the list recursively into two halves until it can no  
more be divided.
Step 3: Merge the smaller lists into new list in sorted order.

*/


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


// Approach 2 of merge Sort
//T.C : O(nlogn)
//S.C : O(n)
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temporary arrays to store the two halves
        int L[n1], R[n2];

        int k = l;
        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = arr[k++];
        for (int j = 0; j < n2; j++)
            R[j] = arr[k++];

        // Merge the temporary arrays back into arr[l..r]
        int i = 0; // Initial index of first subarray
        int j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    public:
    void mergeSort(int arr[], int l, int r) {
        
        if(l >= r) {
            return;
        }
        
        int mid = l + (r-l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, mid ,r);
        
    }
};



int main() {
    
    return 0;
}