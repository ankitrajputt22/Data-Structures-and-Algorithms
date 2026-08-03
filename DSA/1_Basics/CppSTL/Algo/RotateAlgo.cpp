/*******************************************************
    File: rotate_notes.cpp
    Topic: std::rotate in C++ STL
    Header Required: <algorithm>

    ----------------------------------------------------
    🔁 WHAT std::rotate DOES
    ----------------------------------------------------
    Rearranges elements in range [first, last)
    so that the element at 'middle' becomes
    the first element of the new range.

    Syntax:
        std::rotate(first, middle, last);

    After rotation:
        [first, middle)  -> moves to end
        [middle, last)   -> moves to beginning

    ----------------------------------------------------
    📌 IMPORTANT PROPERTIES
    ----------------------------------------------------
    ✔ In-place operation (O(1) extra space)
    ✔ Time complexity: O(n)
    ✔ Works with:
        - Forward Iterators
        - Bidirectional Iterators
        - Random Access Iterators
    ✔ Returns:
        Iterator to the element originally at 'first'
        after rotation.

********************************************************/

#include <iostream>
#include <vector>
#include <algorithm>   // Required for std::rotate
using namespace std;

int main() {

    /***************************************************
        EXAMPLE 1: BASIC LEFT ROTATION
        --------------------------------
        Rotate left by k positions:
            rotate(begin, begin + k, end);
    ***************************************************/
    vector<int> v1 = {1, 2, 3, 4, 5};

    int k = 2;

    // Before: 1 2 3 4 5
    rotate(v1.begin(), v1.begin() + k, v1.end());
    // After:  3 4 5 1 2

    cout << "Left Rotation by 2: ";
    for (int x : v1)
        cout << x << " ";
    cout << "\n\n";


    /***************************************************
        EXAMPLE 2: RIGHT ROTATION
        --------------------------------
        Rotate right by k positions:
            rotate(begin, end - k, end);
    ***************************************************/
    vector<int> v2 = {1, 2, 3, 4, 5};

    k = 2;

    // Before: 1 2 3 4 5
    rotate(v2.begin(), v2.end() - k, v2.end());
    // After:  4 5 1 2 3

    cout << "Right Rotation by 2: ";
    for (int x : v2)
        cout << x << " ";
    cout << "\n\n";


    /***************************************************
        EXAMPLE 3: USING RETURN VALUE
        --------------------------------
        rotate returns iterator to the new position
        of the element originally at 'first'
    ***************************************************/
    vector<int> v3 = {10, 20, 30, 40, 50};

    auto it = rotate(v3.begin(), v3.begin() + 3, v3.end());

    cout << "After rotation: ";
    for (int x : v3)
        cout << x << " ";

    cout << "\nReturned Iterator Points To: " << *it;
    cout << "\n\n";


    /***************************************************
        EXAMPLE 4: ROTATING SUBRANGE
        --------------------------------
        You can rotate only a part of container.
    ***************************************************/
    vector<int> v4 = {1, 2, 3, 4, 5, 6};

    // Rotate only middle part [1, 5)
    rotate(v4.begin() + 1, v4.begin() + 3, v4.begin() + 5);

    cout << "Subrange Rotation: ";
    for (int x : v4)
        cout << x << " ";
    cout << "\n\n";


    /***************************************************
        EXAMPLE 5: COMMON USE CASE
        --------------------------------
        Make smallest element first
    ***************************************************/
    vector<int> v5 = {7, 9, 2, 5, 6};

    auto minIt = min_element(v5.begin(), v5.end());

    rotate(v5.begin(), minIt, v5.end());

    cout << "Make Minimum First: ";
    for (int x : v5)
        cout << x << " ";
    cout << "\n";


    return 0;
}


/********************************************************
    🚨 IMPORTANT NOTES FOR INTERVIEWS

    1️⃣ rotate does NOT sort.
       It only shifts positions.

    2️⃣ If middle == first → No change.
       If middle == last  → No change.

    3️⃣ For large k:
         k = k % n;  (to avoid unnecessary rotation)

    4️⃣ rotate is better than manual shifting because:
         - Cleaner
         - Optimized
         - Less error-prone

    5️⃣ Common competitive programming uses:
         ✔ Circular array problems
         ✔ Making minimum element first
         ✔ String rotation problems
         ✔ Checking if two arrays are rotations

********************************************************/