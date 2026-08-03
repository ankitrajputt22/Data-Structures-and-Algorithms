#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LEETCODE 73: SET MATRIX ZEROES
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

Given an m x n matrix.

If an element is 0,
👉 set its entire row and column to 0.

Do it IN-PLACE.

-----------------------------------------------------------
🧠 EXAMPLE
-----------------------------------------------------------

Input:
[1 1 1]
[1 0 1]
[1 1 1]

Output:
[1 0 1]
[0 0 0]
[1 0 1]

===========================================================
🔴 APPROACH 1: BRUTE FORCE
===========================================================

👉 When you find 0:
   mark entire row & column as -1 (temporary)

👉 Then convert all -1 → 0

TIME: O(m*n*(m+n)) ❌
SPACE: O(1)
*/

void setZeroes_bruteforce(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    // Mark with -1
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 0) {

                // Row
                for (int k = 0; k < n; k++) {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                }

                // Column
                for (int k = 0; k < m; k++) {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                }
            }
        }
    }

    // Convert -1 → 0
    for (auto &row : matrix) {
        for (auto &x : row) {
            if (x == -1) x = 0;
        }
    }
}



/*
===========================================================
🟠 APPROACH 2: USING EXTRA ARRAYS
===========================================================

👉 Use two arrays:
   row[m], col[n]

TIME: O(m*n)
SPACE: O(m+n)
*/

void setZeroes_better(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> row(m, 0), col(n, 0);

    // Mark rows & cols
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Update matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}



/*
===========================================================
🟢 APPROACH 3: OPTIMAL (O(1) SPACE)
===========================================================

👉 Use first row & first column as markers

-----------------------------------------------------------
🧠 IDEA:
-----------------------------------------------------------

- Use matrix[i][0] → row marker
- Use matrix[0][j] → column marker

-----------------------------------------------------------
⚠️ SPECIAL:
-----------------------------------------------------------

Need extra variable to track first column

===========================================================
*/

void setZeroes_optimal(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    int col0 = 1;

    // Step 1: Mark
    for (int i = 0; i < m; i++) {

        if (matrix[i][0] == 0) col0 = 0;

        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 2: Fill (reverse order)
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--) {

            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }

        if (col0 == 0) {
            matrix[i][0] = 0;
        }
    }
}



/*
===========================================================
🧠 COMPLEXITY SUMMARY
===========================================================

| Approach       | Time   | Space |
|---------------|--------|-------|
| Brute Force   | O(m*n*(m+n)) ❌ |
| Better        | O(m*n) |
| Optimal       | O(m*n) | O(1) |

===========================================================
*/


/*
===========================================================
🔥 INTERVIEW INSIGHTS
===========================================================

✔ First row & column used as storage
✔ Need extra variable for first column
✔ Traverse backward while updating

-----------------------------------------------------------
🧠 PATTERN:
-----------------------------------------------------------

👉 In-place matrix modification

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes_optimal(matrix);

    cout << "Result:\n";

    for (auto &row : matrix) {
        for (auto x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}