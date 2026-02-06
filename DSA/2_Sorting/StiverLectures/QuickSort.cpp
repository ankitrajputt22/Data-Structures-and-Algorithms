#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
====================================================
QUICK SORT — COMPLETE THEORY + IMPLEMENTATION
====================================================

----------------------------------------------------
1. INTRODUCTION TO QUICK SORT
----------------------------------------------------

Quick Sort is a Divide and Conquer algorithm.

Like Merge Sort, Quick Sort has an average
time complexity of O(N log N).

However, Quick Sort is often preferred because:
✔ It is an IN-PLACE sorting algorithm
✔ It does NOT require extra temporary arrays
   (unlike Merge Sort)

----------------------------------------------------
CORE INTUITION OF QUICK SORT
----------------------------------------------------

The fundamental idea of Quick Sort is:

1️⃣ Pick a Pivot
   - Choose any element as pivot
   - Can be first, last, random, or median
   - In this implementation, we pick the FIRST element

2️⃣ Place Pivot Correctly
   - The pivot should end up in its correct
     sorted position in the array

3️⃣ Partition the Array
   - All elements smaller than pivot → LEFT side
   - All elements greater than pivot → RIGHT side

4️⃣ Repeat Recursively
   - Apply the same logic to left subarray
   - Apply the same logic to right subarray

----------------------------------------------------
2. PARTITIONING LOGIC (HEART OF QUICK SORT)
----------------------------------------------------

We use TWO POINTERS: i and j

----------------------------------------------------
INITIALIZATION
----------------------------------------------------
low  → starting index of array
high → ending index of array

pivot = arr[low]   (first element as pivot)

i = low
j = high

----------------------------------------------------
POINTER MOVEMENT
----------------------------------------------------

Pointer i:
• Move i to the RIGHT
• Stop when arr[i] > pivot

Pointer j:
• Move j to the LEFT
• Stop when arr[j] <= pivot

----------------------------------------------------
SWAPPING LOGIC
----------------------------------------------------

If i < j:
• Swap arr[i] and arr[j]

Repeat this process until:
j < i

----------------------------------------------------
FINAL STEP (MOST IMPORTANT)
----------------------------------------------------

When j < i:
• Swap pivot (arr[low]) with arr[j]

Now:
✔ Pivot is in its correct sorted position
✔ Left side contains smaller elements
✔ Right side contains larger elements

Return j → Partition Index

----------------------------------------------------
3. COMPLEXITY ANALYSIS
----------------------------------------------------

TIME COMPLEXITY
----------------
Best Case:     O(N log N)
Average Case:  O(N log N)
Worst Case:    O(N^2)

Worst case occurs when:
• Array is already sorted
• Pivot is always first or last element
• Leads to unbalanced partitions

----------------------------------------------------
SPACE COMPLEXITY
----------------------------------------------------

Auxiliary Space: O(1)
• No extra arrays used (in-place sorting)

Recursion Stack Space:
• Worst Case: O(N)
• Average Case: O(log N)

----------------------------------------------------
4. QUICK SORT vs MERGE SORT
----------------------------------------------------

Feature            Quick Sort        Merge Sort
------------------------------------------------
Strategy           Pivot-based       Split-based
Approach           Divide & Conquer  Divide & Conquer
Extra Space        O(1)              O(N)
Stability          Not Stable        Stable
Worst Case Time    O(N^2)            O(N log N)

----------------------------------------------------
HIGH-LEVEL SUMMARY
----------------------------------------------------

Quick Sort works by:
1) Choosing a pivot
2) Partitioning the array
   • Elements ≤ pivot go left
   • Elements > pivot go right
3) Recursively sorting left and right parts

====================================================
END OF THEORY
====================================================
*/

/* -------------------------------------------------
   PARTITION FUNCTION (FIRST ELEMENT AS PIVOT)
------------------------------------------------- */
int partitionArray(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // move i right until element > pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        // move j left until element <= pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        // swap if pointers have not crossed
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // place pivot in correct position
    swap(arr[low], arr[j]);

    return j;  // partition index
}

/* -------------------------------------------------
   QUICK SORT FUNCTION
------------------------------------------------- */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partitionArray(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

/* -------------------------------------------------
   MAIN FUNCTION
------------------------------------------------- */
int main() {

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}







// to do -- pivot element changed ????