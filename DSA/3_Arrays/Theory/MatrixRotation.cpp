/************************************************************
    File: matrix_rotations.cpp

    Rotations Covered
    -----------------
    90°  clockwise
    180° rotation
    270° clockwise (or 90° anticlockwise)

    Key Transformations
    -------------------
    90°  = transpose + reverse row
    180° = reverse row + reverse column
    270° = transpose + reverse column

************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*********************** PRINT MATRIX ************************/
void printMatrix(vector<vector<int>>& matrix)
{
    for(auto &row : matrix)
    {
        for(auto &x : row)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;
}


/************************************************************
    FUNCTION: TRANSPOSE MATRIX

    Swap matrix[i][j] with matrix[j][i]

    Example
    -------
    1 2 3        1 4 7
    4 5 6   ->   2 5 8
    7 8 9        3 6 9
************************************************************/
void transpose(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}


/************************************************************
    FUNCTION: REVERSE EACH ROW
************************************************************/
void reverseRows(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    for(int i=0;i<n;i++)
        reverse(matrix[i].begin(), matrix[i].end());
}


/************************************************************
    FUNCTION: REVERSE EACH COLUMN
************************************************************/
void reverseColumns(vector<vector<int>>& matrix)
{
    int n = matrix.size();

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
    ROTATE 90° CLOCKWISE

    Rule
    ----
    90° = transpose + reverse row

    Mapping
    -------
    (i, j) → (j, n-1-i)
************************************************************/
void rotate90(vector<vector<int>>& matrix)
{
    transpose(matrix);
    reverseRows(matrix);
}


/************************************************************
    ROTATE 180°

    Rule
    ----
    reverse rows + reverse columns

    Equivalent to flipping matrix upside down
    and then left-right.
************************************************************/
void rotate180(vector<vector<int>>& matrix)
{
    reverse(matrix.begin(), matrix.end());  // reverse rows

    for(auto &row : matrix)
        reverse(row.begin(), row.end());    // reverse columns
}


/************************************************************
    ROTATE 270° CLOCKWISE
    (same as 90° anticlockwise)

    Rule
    ----
    transpose + reverse column

    Mapping
    -------
    (i, j) → (n-1-j, i)
************************************************************/
void rotate270(vector<vector<int>>& matrix)
{
    transpose(matrix);
    reverseColumns(matrix);
}


/*********************** MAIN ************************/
int main()
{
    vector<vector<int>> matrix =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "Original Matrix\n";
    printMatrix(matrix);


    vector<vector<int>> m1 = matrix;
    rotate90(m1);
    cout << "90 Degree Rotation\n";
    printMatrix(m1);


    vector<vector<int>> m2 = matrix;
    rotate180(m2);
    cout << "180 Degree Rotation\n";
    printMatrix(m2);


    vector<vector<int>> m3 = matrix;
    rotate270(m3);
    cout << "270 Degree Rotation\n";
    printMatrix(m3);

}