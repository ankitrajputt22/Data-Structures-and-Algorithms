/*
===============================================================================
EXPERIMENT – 2
SEARCHING & HASHING TECHNIQUES
===============================================================================
Includes:
1. Linear Search  
2. Binary Search  
3. Hashing Methods:
     - Modulo Division
     - Digit Extraction
     - Folding (Shift & Boundary)
     - Direct Hashing
     - Subtraction Hashing
     - Collision Handling: Linear Probing
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define TABLE_SIZE 10

/*===============================================================================
🔹 1. LINEAR SEARCH — ALGORITHM
--------------------------------
1. Traverse array from left to right.
2. If arr[i] == key → return index.
3. If end reached → key not found.
===============================================================================*/
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}


/*===============================================================================
🔹 2. BINARY SEARCH — ALGORITHM
--------------------------------
(Works only on sorted array)

1. Set low = 0, high = n-1
2. Repeat:
      mid = (low + high) / 2
      If key == arr[mid] → found
      If key < arr[mid] → search left
      Else → search right
3. If low > high → not found
===============================================================================*/
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}


/*===============================================================================
SECTION – HASHING METHODS
Hash Table size = 10 (0–9)
===============================================================================*/

int hashTable[TABLE_SIZE];

/* Initialize table */
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

void printTable() {
    printf("Hash Table: ");
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("%d ", hashTable[i]);
    printf("\n");
}


/*===============================================================================
🔹 3. HASHING — MODULO DIVISION METHOD
--------------------------------------
hash = key % TABLE_SIZE
===============================================================================*/
int hashModulo(int key) {
    return key % TABLE_SIZE;
}


/*===============================================================================
🔹 4. DIGIT EXTRACTION METHOD
--------------------------------
Example:
    key = 58392
    Extract digits 2,5 → combine → 25 → index
===============================================================================*/
int hashDigitExtraction(int key) {
    int d1 = key % 10;        // last digit
    int d2 = (key / 100) % 10; // 3rd digit
    return (d1 * 10 + d2) % TABLE_SIZE;
}


/*===============================================================================
🔹 5. FOLDING — SHIFT METHOD
-----------------------------
Break key into equal segments, add them

Example: key = 123456 → 12 + 34 + 56 = 102 → 102 % 10
===============================================================================*/
int hashFoldShift(int key) {
    int sum = 0;
    while (key > 0) {
        sum += key % 100;  // take 2 digits
        key /= 100;
    }
    return sum % TABLE_SIZE;
}


/*===============================================================================
🔹 6. FOLDING — BOUNDARY METHOD
--------------------------------
Reverse alternate segments before adding.

Example:
    key = 123456  
    segments → 12, 34, 56  
    reverse middle → 12 + 43 + 56 → sum
===============================================================================*/
int hashFoldBoundary(int key) {
    int a = key % 100; key /= 100;   // 56
    int b = key % 100; key /= 100;   // 34
    int c = key % 100;               // 12

    int revB = (b / 10) + (b % 10) * 10;  // reverse 34 → 43

    return (a + revB + c) % TABLE_SIZE;
}


/*===============================================================================
🔹 7. DIRECT HASHING
--------------------
hash = key  
(Works only when keys ≤ table size)
===============================================================================*/
int hashDirect(int key) {
    return key % TABLE_SIZE;
}


/*===============================================================================
🔹 8. SUBTRACTION HASHING
--------------------------
hash = TABLE_SIZE - key % TABLE_SIZE
===============================================================================*/
int hashSubtract(int key) {
    return (TABLE_SIZE - (key % TABLE_SIZE)) % TABLE_SIZE;
}


/*===============================================================================
🔹 9. LINEAR PROBING FOR COLLISION RESOLUTION
----------------------------------------------
Insert(key):
1. index = hash(key)
2. If table[index] empty → insert
3. Else linear probe:
      index = (index + 1) % TABLE_SIZE
===============================================================================*/
void insertLinearProbe(int key, int (*hashFunc)(int)) {
    int index = hashFunc(key);

    while (hashTable[index] != -1)
        index = (index + 1) % TABLE_SIZE;

    hashTable[index] = key;
}


/*===============================================================================
🔹 MAIN FUNCTION — AUTO RUN ALL SEARCH & HASH OPERATIONS
===============================================================================*/
int main() {

    printf("\n====================================\n");
    printf("          LINEAR SEARCH\n");
    printf("====================================\n");

    int arr1[] = {10, 25, 30, 45, 50};
    int pos1 = linearSearch(arr1, 5, 30);
    printf("Searching 30 → %s (index %d)\n", (pos1 != -1) ? "Found" : "Not Found", pos1);


    printf("\n====================================\n");
    printf("          BINARY SEARCH\n");
    printf("====================================\n");

    int arr2[] = {5, 10, 20, 40, 60, 80};
    int pos2 = binarySearch(arr2, 6, 40);
    printf("Searching 40 → %s (index %d)\n", (pos2 != -1) ? "Found" : "Not Found", pos2);


    printf("\n====================================\n");
    printf("     HASHING METHODS DEMONSTRATION\n");
    printf("====================================\n");

    initTable();

    int keys[] = {23, 45, 67, 89};
    int n = 4;

    printf("\n--- Modulo Method ---\n");
    for (int i = 0; i < n; i++)
        insertLinearProbe(keys[i], hashModulo);
    printTable();


    printf("\n--- Digit Extraction ---\n");
    initTable();
    for (int i = 0; i < n; i++)
        insertLinearProbe(5820 + keys[i], hashDigitExtraction);
    printTable();


    printf("\n--- Fold Shift ---\n");
    initTable();
    for (int i = 0; i < n; i++)
        insertLinearProbe(123400 + keys[i], hashFoldShift);
    printTable();


    printf("\n--- Fold Boundary ---\n");
    initTable();
    for (int i = 0; i < n; i++)
        insertLinearProbe(123400 + keys[i], hashFoldBoundary);
    printTable();


    printf("\n--- Direct Hashing ---\n");
    initTable();
    for (int i = 0; i < n; i++)
        insertLinearProbe(keys[i], hashDirect);
    printTable();


    printf("\n--- Subtraction Hashing ---\n");
    initTable();
    for (int i = 0; i < n; i++)
        insertLinearProbe(keys[i], hashSubtract);
    printTable();

    return 0;
}
