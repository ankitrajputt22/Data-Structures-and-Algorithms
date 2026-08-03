#include <iostream>
#include <map>
using namespace std;

/*
=====================================================
                  ORDERED MAP (map) NOTES
=====================================================

1. WHAT IS map?
---------------------------------
- map is an associative container in C++ STL.
- Stores elements in (key, value) pairs.
- Keys are UNIQUE.
- Elements are ALWAYS stored in SORTED order of keys.

-----------------------------------------------------

2. INTERNAL IMPLEMENTATION
---------------------------------
- Implemented using RED-BLACK TREE (self-balancing BST).
- Tree remains balanced automatically.
- Height of tree is O(log n).

-----------------------------------------------------

3. ORDERING
---------------------------------
- Default ordering: ASCENDING by key.
- Custom ordering is possible using comparator.

Example:
map<int, int> mp;                   // ascending
map<int, int, greater<int>> mp;     // descending

-----------------------------------------------------

4. TIME COMPLEXITY (GUARANTEED)
---------------------------------
Operation      Time Complexity
Insert            O(log n)
Search            O(log n)
Delete            O(log n)

- No worst-case degradation like unordered_map.
- Slower than unordered_map but safer.

-----------------------------------------------------

5. map vs unordered_map
---------------------------------
map:
- Sorted
- Red-Black Tree
- O(log n)
- Supports range queries

unordered_map:
- Unsorted
- Hash Table
- O(1) average
- No range queries

-----------------------------------------------------

6. WHEN TO USE map?
---------------------------------
- When sorted data is required
- Range queries needed
- Ordered traversal
- Predictable performance

-----------------------------------------------------

7. WHEN NOT TO USE map?
---------------------------------
- When fast O(1) lookup is required
- When order does not matter
- Competitive programming with large input (sometimes)

-----------------------------------------------------

8. INSERTION METHODS
---------------------------------
mp[key]           -> inserts or updates
mp.insert()       -> inserts pair
mp.emplace()      -> faster insertion

-----------------------------------------------------

9. WARNING ABOUT [] OPERATOR
---------------------------------
- mp[key] creates key if it does NOT exist.
- Use find() or count() for safe existence check.

-----------------------------------------------------

10. SEARCHING
---------------------------------
mp.find(key)      -> returns iterator
mp.count(key)     -> returns 0 or 1

-----------------------------------------------------

11. ITERATION
---------------------------------
- Iteration happens in SORTED order of keys.

-----------------------------------------------------

12. DELETION
---------------------------------
mp.erase(key)     -> deletes key
mp.clear()        -> deletes all elements

-----------------------------------------------------

13. SPECIAL FUNCTIONS (INTERVIEW FAVORITES)
---------------------------------
lower_bound(key):
- First element with key >= given key

upper_bound(key):
- First element with key > given key

Used for:
- Range queries
- Interval problems

-----------------------------------------------------

14. COMMON MISTAKES
---------------------------------
- Assuming O(1) complexity
- Using map when order is not needed
- Using [] to only check existence
- Assuming sorting by value (sorting is by KEY)

=====================================================
*/


// Function to print map
void printMap(const map<int, string>& m) {
    if (m.empty()) {
        cout << "Map is empty\n\n";
        return;
    }

    for (auto it : m) {
        cout << it.first << " -> " << it.second << endl;
    }
    cout << endl;
}

int main() {


    // Ordered map (keys are stored in sorted order)
    map<int, string> m;

    // ---------- INSERTION (O(log n)) ----------
    m[1] = "abc";   // O(log n)
    m[5] = "cdc";
    m[3] = "acd";
    m[6] = "a";

    // Updating value of existing key
    m[5] = "cde";

    printMap(m);

    // ---------- FIND (O(log n)) ----------
    auto it = m.find(7);   // searching key 7

    // ---------- ERASE (O(log n)) ----------
    if (it != m.end()) {
        m.erase(it);      // safe erase using iterator
    } else {
        cout << "Key 7 not found, nothing erased\n\n";
    }

    printMap(m);

    // ---------- CLEAR ----------
    // Removes all key-value pairs
    m.clear();

    printMap(m);
    cout << endl;
    cout << endl;
    cout << endl;


    // 1. Declaration
    map<int, int> mp;

    // 2. Insertion
    mp[3] = 30;             // inserts key 3
    mp[1] = 10;             // inserts key 1
    mp.insert({2, 20});     // insert using pair
    mp.emplace(4, 40);      // faster insertion

    /*
    NOTE:
    - Keys are stored in SORTED order automatically
    */

    // 3. Accessing elements
    cout << "Value at key 1: " << mp[1] << endl;

    /*
    WARNING:
    mp[100] creates key 100 with value 0
    */

    // 4. Safe searching
    if (mp.find(2) != mp.end()) {
        cout << "Key 2 exists\n";
    }

    if (mp.count(3)) {
        cout << "Key 3 exists\n";
    }

    // 5. Iteration (always sorted)
    cout << "\nIterating map (sorted order):\n";
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // 6. lower_bound & upper_bound
    auto lb = mp.lower_bound(2);
    auto ub = mp.upper_bound(3);

    cout << "\nLower bound of 2: " << lb->first << endl;
    cout << "Upper bound of 3: " << ub->first << endl;

    // 7. Range query example [2, 4]
    cout << "\nRange [2, 4]:\n";
    for (auto it = mp.lower_bound(2); it != mp.upper_bound(4); it++) {
        cout << it->first << " ";
    }
    cout << endl;

    // 8. Deletion
    mp.erase(1);    // deletes key 1

    // 9. Size and empty check
    cout << "\nSize after deletion: " << mp.size() << endl;
    cout << "Is empty? " << (mp.empty() ? "Yes" : "No") << endl;

    // 10. Descending order map
    map<int, int, greater<int>> descMap;
    descMap[1] = 10;
    descMap[2] = 20;
    descMap[3] = 30;

    cout << "\nDescending order map:\n";
    for (auto it : descMap) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}
