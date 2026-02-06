#include <stdio.h>
#include <stdlib.h>

void countingSortSimple(int arr[], int n, int k) {
    int count[k+1];           // to store the frequency of i element of the array arr

    for (int i = 0; i < k+1; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int ind = 0;
    for (int i = 0; i <= k; i++) {
        while (count[i] > 0) {
            arr[ind] = i;
            ind++;

            count[i]--;
        }
    }
}


int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 8;

    countingSortSimple(arr, n, max);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        
    return 0;
}