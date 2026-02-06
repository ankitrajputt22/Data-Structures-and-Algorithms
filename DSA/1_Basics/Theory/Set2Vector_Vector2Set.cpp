#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

int main() {

    /* -------------------------------
       Original SET (stores unique, sorted elements)
       ------------------------------- */
    set<int> s = {5, 1, 3, 3, 2};
    cout << "Original set: ";
    for (auto x : s) cout << x << " ";
    cout << endl;

    /* =====================================================
       1) SET → VECTOR using Constructor
       Copies all elements from set into vector
       Vector will contain sorted unique elements
       ===================================================== */
    vector<int> v1(s.begin(), s.end());
    cout << "Vector v1 (set → vector using constructor): ";
    for (auto x : v1) cout << x << " ";
    cout << endl;

    /* =====================================================
       2) SET → VECTOR using assign()
       Another way to copy elements from set into vector
       ===================================================== */
    vector<int> v2;
    v2.assign(s.begin(), s.end());
    cout << "Vector v2 (set → vector using assign): ";
    for (auto x : v2) cout << x << " ";
    cout << endl;

    /* -------------------------------
       Original VECTOR (may contain duplicates, unsorted)
       ------------------------------- */
    vector<int> v = {7, 4, 4, 2, 9, 1};
    cout << "Original vector: ";
    for (auto x : v) cout << x << " ";
    cout << endl;

    /* =====================================================
       3) VECTOR → SET using Constructor
       Converts vector to set
       Automatically removes duplicates and sorts elements
       ===================================================== */
    set<int> s1(v.begin(), v.end());
    cout << "Set s1 (vector → set using constructor): ";
    for (auto x : s1) cout << x << " ";
    cout << endl;

    /* =====================================================
       4) VECTOR → SET using insert()
       Inserts all vector elements into set
       Also removes duplicates and sorts
       ===================================================== */
    set<int> s2;
    s2.insert(v.begin(), v.end());
    cout << "Set s2 (vector → set using insert): ";
    for (auto x : s2) cout << x << " ";
    cout << endl;

    return 0;
}
