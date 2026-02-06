#include <stdio.h>

void countingSort(int arr[], int n, int k) {
    int count[k + 1];
    int output[n];

    // Step 1: Initialize count array
    for (int i = 0; i <= k; i++)
        count[i] = 0;

    // Step 2: Count each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 3: Prefix sum (cumulative count) // YES — if you want proper sorting with correct positions (and stability)
    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];

    // Step 4: Build output array (stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 5: Copy back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 8;   // maximum value in array

    countingSort(arr, n, max);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
