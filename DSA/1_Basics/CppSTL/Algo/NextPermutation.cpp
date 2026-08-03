/*********************************************************
    File: next_permutation_notes.cpp
    Topic: std::next_permutation in C++ STL
    Header Required: <algorithm>

    ------------------------------------------------------
    🔁 WHAT std::next_permutation DOES
    ------------------------------------------------------
    Rearranges elements into the next lexicographically
    greater permutation.

    If such permutation exists:
        → Returns true
        → Modifies container to next permutation

    If not (already largest permutation):
        → Rearranges to smallest (sorted order)
        → Returns false

    ------------------------------------------------------
    📌 SYNTAX
    ------------------------------------------------------
        bool next_permutation(first, last);

    ------------------------------------------------------
    📌 REQUIREMENTS
    ------------------------------------------------------
    ✔ Elements should be comparable (< operator)
    ✔ Works best with sorted initial order
    ✔ Time Complexity: O(n)
    ✔ Space Complexity: O(1)

*********************************************************/

#include <iostream>
#include <vector>
#include <algorithm>   // Required for next_permutation
using namespace std;

int main() {

    /*****************************************************
        EXAMPLE 1: BASIC USAGE
    *****************************************************/
    vector<int> v1 = {1, 2, 3};

    cout << "All permutations:\n";

    // IMPORTANT: Start with sorted order
    sort(v1.begin(), v1.end());

    do {
        for (int x : v1)
            cout << x << " ";
        cout << "\n";
    } while (next_permutation(v1.begin(), v1.end()));

    cout << "\n";


    /*****************************************************
        EXAMPLE 2: RETURN VALUE UNDERSTANDING
    *****************************************************/
    vector<int> v2 = {3, 2, 1};

    bool hasNext = next_permutation(v2.begin(), v2.end());

    cout << "Has next permutation? " << hasNext << "\n";

    cout << "After call: ";
    for (int x : v2)
        cout << x << " ";
    cout << "\n\n";

    // Since {3,2,1} is largest permutation,
    // it resets to smallest: {1,2,3}
    // and returns false.


    /*****************************************************
        EXAMPLE 3: STRING PERMUTATION
    *****************************************************/
    string s = "abc";

    cout << "String permutations:\n";

    sort(s.begin(), s.end());

    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));


    return 0;
}


/*********************************************************
    🧠 HOW next_permutation WORKS INTERNALLY
    ------------------------------------------------------

    Given: 1 2 3 6 5 4

    STEP 1: Find first decreasing element from right
            (pivot)
            3 < 6 → pivot = 3

    STEP 2: Find next greater element than pivot from right
            4 (smallest greater than 3)

    STEP 3: Swap pivot and that element
            1 2 4 6 5 3

    STEP 4: Reverse everything after pivot position
            1 2 4 3 5 6

    That is the next lexicographical permutation.

*********************************************************/


/*********************************************************
    🚨 IMPORTANT INTERVIEW NOTES

    1️⃣ Always sort first if generating all permutations.

    2️⃣ If array is already in descending order:
           next_permutation() returns false
           and resets to ascending order.

    3️⃣ Total permutations of n elements = n!

    4️⃣ For large n (n > 10), generating all permutations
       is expensive (factorial growth).

    5️⃣ Works with:
           ✔ vector
           ✔ array
           ✔ string
           ✔ any container with iterators

    6️⃣ To generate previous permutation:
           use prev_permutation()

*********************************************************/