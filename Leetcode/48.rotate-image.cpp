/************************************************************
    File: rotate_image_all_solutions.cpp
    Problem: Rotate Image (90° Clockwise)
    Matrix size: n x n

    Goal:
    Rotate the matrix 90 degrees clockwise.

    Example:
        Input:
        1 2 3
        4 5 6
        7 8 9

        Output:
        7 4 1
        8 5 2
        9 6 3

    Important Constraint:
        Must modify matrix in-place for optimal solution.
************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/************************************************************
    Helper Function: Print Matrix
************************************************************/
void printMatrix(const vector<vector<int>>& matrix)
{
    for (auto &row : matrix)
    {
        for (auto &x : row)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;
}


/************************************************************
    SOLUTION 1: BRUTE FORCE (Using Extra Matrix)

    Idea:
    Create a temporary matrix and place each element
    in its rotated position.

    Rotation Formula:
        new[j][n-1-i] = matrix[i][j]

    Steps:
        1. Create temp matrix
        2. Copy rotated positions
        3. Copy temp back to original

    Time Complexity: O(n²)
    Space Complexity: O(n²)
************************************************************/
void rotateBruteForce(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    vector<vector<int>> temp(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp[j][n - 1 - i] = matrix[i][j];
        }
    }

    matrix = temp;
}


/************************************************************
    SOLUTION 2: TRANSPOSE + REVERSE (MOST POPULAR)

    Idea:
    A 90° clockwise rotation can be done using:

        Step 1: Transpose matrix
        Step 2: Reverse each row

    Transpose:
        matrix[i][j] ↔ matrix[j][i]

    Example:

        Original
        1 2 3
        4 5 6
        7 8 9

        After Transpose
        1 4 7
        2 5 8
        3 6 9

        Reverse rows
        7 4 1
        8 5 2
        9 6 3

    Time Complexity: O(n²)
    Space Complexity: O(1)
************************************************************/
void rotateTransposeReverse(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    // Step 1: Transpose matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for(int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


/************************************************************
    SOLUTION 3: LAYER-BY-LAYER ROTATION

    Idea:
    Rotate the matrix layer by layer (like onion layers).

    Each step rotates 4 elements:

        top -> right
        right -> bottom
        bottom -> left
        left -> top

    Example cycle:

        temp = top
        top = left
        left = bottom
        bottom = right
        right = temp

    Time Complexity: O(n²)
    Space Complexity: O(1)
************************************************************/
void rotateLayerMethod(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    for(int layer = 0; layer < n/2; layer++)
    {
        int first = layer;
        int last = n - layer - 1;

        for(int i = first; i < last; i++)
        {
            int offset = i - first;

            int top = matrix[first][i];

            // left -> top
            matrix[first][i] = matrix[last-offset][first];

            // bottom -> left
            matrix[last-offset][first] = matrix[last][last-offset];

            // right -> bottom
            matrix[last][last-offset] = matrix[i][last];

            // top -> right
            matrix[i][last] = top;
        }
    }
}


/************************************************************
    BONUS: ROTATE 90° ANTICLOCKWISE

    Steps:
        1. Transpose matrix
        2. Reverse each column

    Time Complexity: O(n²)
    Space Complexity: O(1)
************************************************************/
void rotateAntiClockwise(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    // transpose
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse columns
    for(int j=0;j<n;j++)
    {
        int top = 0;
        int bottom = n-1;

        while(top < bottom)
        {
            swap(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    }
}


/************************************************************
    MAIN FUNCTION
************************************************************/
int main()
{
    vector<vector<int>> matrix =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);


    /*************** BRUTE FORCE *****************/
    vector<vector<int>> m1 = matrix;
    rotateBruteForce(m1);

    cout << "After Rotation (Brute Force):\n";
    printMatrix(m1);


    /*************** TRANSPOSE + REVERSE *********/
    vector<vector<int>> m2 = matrix;
    rotateTransposeReverse(m2);

    cout << "After Rotation (Transpose + Reverse):\n";
    printMatrix(m2);


    /*************** LAYER METHOD ****************/
    vector<vector<int>> m3 = matrix;
    rotateLayerMethod(m3);

    cout << "After Rotation (Layer Method):\n";
    printMatrix(m3);


    /*************** ANTICLOCKWISE ROTATION ******/
    vector<vector<int>> m4 = matrix;
    rotateAntiClockwise(m4);

    cout << "After AntiClockwise Rotation:\n";
    printMatrix(m4);

    return 0;
}


/************************************************************
    IMPORTANT CONCEPT

    Rotation Mapping (Clockwise):

        (i, j)  →  (j, n-1-i)

    Rotation Mapping (AntiClockwise):

        (i, j)  →  (n-1-j, i)

************************************************************/