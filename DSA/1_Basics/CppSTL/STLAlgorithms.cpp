#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
========================================================
        IMPORTANT STL ALGORITHMS (C++ STL)
========================================================

NOTE:
- Most STL algorithms are defined in <algorithm>
- Numeric algorithms are in <numeric>

STL algorithms work mainly on ITERATORS.
--------------------------------------------------------

========================
1. all_of / any_of / none_of
========================
Used to check conditions on ALL / ANY / NONE elements.

Return type: bool

all_of   -> true if condition is true for ALL elements
any_of   -> true if condition is true for AT LEAST ONE element
none_of  -> true if condition is false for ALL elements

Time Complexity: O(n)

--------------------------------------------------------

========================
2. min_element / max_element
========================
Finds minimum or maximum element in a range.

Return type: iterator
Must DEREFERENCE (*) to get value.

Time Complexity: O(n)

--------------------------------------------------------

========================
3. accumulate
========================
Used to calculate SUM of elements.

Defined in <numeric>

Syntax:
accumulate(start, end, initial_value)

Time Complexity: O(n)

--------------------------------------------------------

========================
4. count / count_if
========================
count     -> counts occurrences of a value
count_if  -> counts based on condition

Time Complexity: O(n)

--------------------------------------------------------

========================
5. find / find_if
========================
find     -> finds a value
find_if  -> finds based on condition

Returns iterator to element or end() if not found.

Time Complexity: O(n)

--------------------------------------------------------

========================
6. reverse
========================
Reverses elements in a range.

Time Complexity: O(n)

--------------------------------------------------------

========================
7. sort
========================
Sorts elements in ascending order by default.

Time Complexity: O(n log n)

--------------------------------------------------------

========================
8. binary_search
========================
Checks if element exists in SORTED range.

Time Complexity: O(log n)

--------------------------------------------------------

========================
9. lower_bound / upper_bound
========================
Works ONLY on sorted ranges.

lower_bound -> first element >= value
upper_bound -> first element > value

Time Complexity: O(log n)

--------------------------------------------------------

========================
10. next_permutation / prev_permutation
========================
Generates next or previous lexicographical permutation.

Time Complexity: O(n)

--------------------------------------------------------

========================
11. unique
========================
Removes consecutive duplicates (array must be sorted).

--------------------------------------------------------

========================
12. rotate
========================
Rotates elements in a range.

--------------------------------------------------------

========================
13. partition
========================
Rearranges elements based on condition.

--------------------------------------------------------

========================
14. iota
========================
Fills range with sequentially increasing values.

Defined in <numeric>

========================================================
*/

int main() {

    vector<int> v = {2, -4, -5, 3, 2};

    // ---------- all_of / any_of / none_of ----------
    cout << all_of(v.begin(), v.end(), [](int x) {
        return x > 0;
    }) << endl;

    cout << any_of(v.begin(), v.end(), [](int x) {
        return x > 0;
    }) << endl;

    cout << none_of(v.begin(), v.end(), [](int x) {
        return x > 0;
    }) << endl;

    // ---------- min_element / max_element ----------
    int mn = *min_element(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());
    cout << "Min: " << mn << endl;
    cout << "Max: " << mx << endl;

    // ---------- accumulate ----------
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum: " << sum << endl;

    // ---------- count ----------
    int ct = count(v.begin(), v.end(), 2);
    cout << "Count of 2: " << ct << endl;

    // ---------- find ----------
    auto it = find(v.begin(), v.end(), 10);
    if (it != v.end())
        cout << *it << endl;
    else
        cout << "Element not found\n";

    // ---------- reverse ----------
    reverse(v.begin() + 2, v.end());
    cout << "After reverse: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // ---------- sort ----------
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // ---------- binary_search ----------
    cout << "Binary search 3: "
         << binary_search(v.begin(), v.end(), 3) << endl;

    // ---------- lower_bound / upper_bound ----------
    cout << "Lower bound of 2 index: "
         << lower_bound(v.begin(), v.end(), 2) - v.begin() << endl;

    cout << "Upper bound of 2 index: "
         << upper_bound(v.begin(), v.end(), 2) - v.begin() << endl;

    // ---------- next_permutation ----------
    vector<int> p = {1, 2, 3};
    next_permutation(p.begin(), p.end());
    cout << "Next permutation: ";
    for (int x : p) cout << x << " ";
    cout << endl;

    // ---------- unique ----------
    vector<int> u = {1,1,2,2,3,3};
    auto last = unique(u.begin(), u.end());
    u.erase(last, u.end());
    cout << "After unique: ";
    for (int x : u) cout << x << " ";
    cout << endl;

    // ---------- rotate ----------
    vector<int> r = {1,2,3,4,5};
    rotate(r.begin(), r.begin() + 2, r.end());
    cout << "After rotate: ";
    for (int x : r) cout << x << " ";
    cout << endl;

    // ---------- partition ----------
    vector<int> part = {1,2,3,4,5,6};
    partition(part.begin(), part.end(), [](int x){
        return x % 2 == 0;
    });
    cout << "After partition: ";
    for (int x : part) cout << x << " ";
    cout << endl;

    // ---------- iota ----------
    vector<int> seq(5);
    iota(seq.begin(), seq.end(), 1);
    cout << "Iota: ";
    for (int x : seq) cout << x << " ";
    cout << endl;

    return 0;
}
