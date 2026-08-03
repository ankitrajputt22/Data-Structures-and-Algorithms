#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 74: SEARCH A 2D MATRIX
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

Given an m x n matrix with properties:

1. Each row is sorted in ascending order
2. First element of each row > last element of previous row

Goal:
👉 Determine if a target exists in the matrix

-----------------------------------------------------------
🧠 KEY OBSERVATION
-----------------------------------------------------------

The matrix behaves like a SORTED 1D ARRAY.

Example:
Matrix:
[1  3  5]
[7  9 11]

Equivalent 1D:
[1, 3, 5, 7, 9, 11]

-----------------------------------------------------------
👉 So we can apply BINARY SEARCH

===========================================================
*/


/*
===========================================================
🔴 APPROACH 1: BRUTE FORCE
===========================================================

👉 Traverse entire matrix

TIME: O(m*n)
SPACE: O(1)
*/

bool searchMatrix_bruteforce(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == target) return true;
        }
    }

    return false;
}



/*
===========================================================
🟠 APPROACH 2: ROW-WISE BINARY SEARCH
===========================================================

👉 First find correct row
👉 Then apply binary search on that row

-----------------------------------------------------------
🧠 IDEA:
-----------------------------------------------------------

Each row defines a range:
[row_start, row_end]

Check:
if target lies in this range → search inside row

TIME: O(m + log n)
SPACE: O(1)
*/

bool searchMatrix_rowBS(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {

        if (target >= matrix[i][0] && target <= matrix[i][n-1]) {

            int low = 0, high = n - 1;

            while (low <= high) {
                int mid = (low + high) / 2;

                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
    }

    return false;
}



/*
===========================================================
🟡 APPROACH 3: FULL BINARY SEARCH (OPTIMAL)
===========================================================

👉 Treat matrix as a 1D sorted array

-----------------------------------------------------------
🧠 MAPPING:
-----------------------------------------------------------

index → (row, col)

row = index / n
col = index % n

-----------------------------------------------------------
WHY THIS WORKS:
-----------------------------------------------------------

Because matrix is globally sorted

-----------------------------------------------------------
TIME: O(log(m*n))
SPACE: O(1)

===========================================================
*/

bool searchMatrix_optimal(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0, high = m * n - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        int row = mid / n;
        int col = mid % n;

        int val = matrix[row][col];

        if (val == target) return true;

        else if (val < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}



/*
===========================================================
🔵 APPROACH 4: STAIRCASE SEARCH (NOT VALID HERE)
===========================================================

NOTE:
This approach works ONLY when:

👉 Rows sorted
👉 Columns sorted

❌ NOT applicable for this problem

===========================================================
*/


/*
===========================================================
🧠 COMPLEXITY SUMMARY
===========================================================

| Approach       | Time          | Space |
|---------------|--------------|-------|
| Brute Force   | O(m*n)       | O(1)  |
| Row-wise BS   | O(m + log n) |
| Optimal BS    | O(log(m*n))  | O(1)  |

===========================================================
*/


/*
===========================================================
🔥 INTERVIEW INSIGHTS
===========================================================

✔ Recognize sorted structure
✔ Convert 2D → 1D
✔ Apply binary search

-----------------------------------------------------------
🧠 PATTERN:
-----------------------------------------------------------

👉 Binary Search on Matrix

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 3;

    cout << "Brute: "
         << searchMatrix_bruteforce(matrix, target) << endl;

    cout << "Row-wise BS: "
         << searchMatrix_rowBS(matrix, target) << endl;

    cout << "Optimal: "
         << searchMatrix_optimal(matrix, target) << endl;

    return 0;
}