/*
===============================================================================
                DATA STRUCTURE LAB – SORTING TECHNIQUES
===============================================================================
This program contains implementations of:

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Shell Sort
5. Radix Sort
6. Quick Sort

Each algorithm is written above its code as per AKTU Lab Manual format.
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*=============================================================================
                              BUBBLE SORT
===============================================================================

Algorithm: BubbleSort(A, n)
1. Repeat for i = 0 to n-2
2.     Repeat for j = 0 to n-i-2
3.         If A[j] > A[j+1]
4.             Swap A[j], A[j+1]
5. End

=============================================================================*/
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}


/*=============================================================================
                              SELECTION SORT
===============================================================================

Algorithm: SelectionSort(A, n)
1. Repeat for i = 0 to n-2
2.     min = i
3.     For j = i+1 to n-1
4.         If A[j] < A[min] → min = j
5.     Swap A[i], A[min]
6. End

=============================================================================*/
void selectionSort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
}


/*=============================================================================
                              INSERTION SORT
===============================================================================

Algorithm: InsertionSort(A, n)
1. Repeat for i = 1 to n-1
2.     key = A[i]
3.     j = i-1
4.     While j >=0 AND A[j] > key
5.         A[j+1] = A[j]
6.         j--
7.     A[j+1] = key
8. End

=============================================================================*/
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i-1;

        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}


/*=============================================================================
                                 SHELL SORT
===============================================================================

Algorithm: ShellSort(A, n)
1. gap = n/2
2. While gap > 0
3.     For i = gap to n-1
4.         temp = A[i]
5.         j = i
6.         While j >= gap AND A[j-gap] > temp
7.             A[j] = A[j-gap]
8.             j = j-gap
9.         A[j] = temp
10.    gap = gap / 2
=============================================================================*/
void shellSort(int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;

            while (j >= gap && a[j-gap] > temp) {
                a[j] = a[j-gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
}


/*=============================================================================
                              RADIX SORT (LSD)
===============================================================================

Algorithm (RadixSort):
1. Find max number
2. For exp = 1; max/exp > 0; exp *= 10
3.     Perform Counting Sort on each digit

=============================================================================*/
int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void countingSort(int a[], int n, int exp) {
    int output[MAX], count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i]/exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        output[count[(a[i]/exp)%10] - 1] = a[i];
        count[(a[i]/exp)%10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n) {
    int max = getMax(a, n);
    for (int exp = 1; max/exp > 0; exp *= 10)
        countingSort(a, n, exp);
}


/*=============================================================================
                               QUICK SORT
===============================================================================

Algorithm: QuickSort(A, low, high)
1. If low < high:
2.     pivot = Partition(A, low, high)
3.     QuickSort(A, low, pivot-1)
4.     QuickSort(A, pivot+1, high)

Partition (Lomuto):
1. pivot = A[high]
2. i = low-1
3. For j = low to high-1
4.     If A[j] < pivot:
5.         i++; swap(A[i], A[j])
6. swap(A[i+1], A[high])
7. return i+1

=============================================================================*/
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i+1]; a[i+1] = a[high]; a[high] = t;
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}


/*=============================================================================
                              UTILITY FUNCTIONS
=============================================================================*/
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


/*=============================================================================
                                 MAIN
=============================================================================*/
int main() {

    int arr[] = {50, 23, 9, 18, 61, 32};
    int n = 6;

    printf("Original Array: ");
    printArray(arr, n);

    // Uncomment any sorting function to test

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // shellSort(arr, n);
    // radixSort(arr, n);
    // quickSort(arr, 0, n-1);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}

