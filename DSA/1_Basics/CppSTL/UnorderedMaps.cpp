#include <iostream>
#include <unordered_map>
using namespace std;

/*
=====================================================
                UNORDERED_MAP NOTES (C++)
=====================================================

1. WHAT IS unordered_map?
---------------------------------
- unordered_map is a hash table based associative container.
- Stores data in (key, value) pairs.
- Keys are UNIQUE.
- Order of elements is NOT maintained.
- Average time complexity for insert, find, erase is O(1).

-----------------------------------------------------

2. INTERNAL WORKING
---------------------------------
- Uses HASH TABLE.
- A hash function converts key -> bucket index.
- Multiple elements in same bucket cause COLLISION.
- C++ handles collisions using SEPARATE CHAINING (linked list).

-----------------------------------------------------

3. TIME COMPLEXITY
---------------------------------
Operation      Average Case     Worst Case
Insert            O(1)             O(n)
Search            O(1)             O(n)
Delete            O(1)             O(n)

Worst case occurs due to too many collisions.

-----------------------------------------------------

4. WHEN TO USE unordered_map?
---------------------------------
- Fast lookup needed
- Frequency counting
- DSA & competitive programming
- No need for sorted order

-----------------------------------------------------

5. WHEN NOT TO USE unordered_map?
---------------------------------
- When sorted order is required
- Memory critical systems
- Very small datasets

-----------------------------------------------------

6. unordered_map vs map
---------------------------------
unordered_map:
- Unordered
- Hash Table
- Faster (O(1) average)

map:
- Sorted
- Red-Black Tree
- Slower (O(log n))

-----------------------------------------------------

7. IMPORTANT FUNCTIONS
---------------------------------
mp[key]              -> insert/access
mp.insert()          -> insert element
mp.emplace()         -> faster insertion
mp.find(key)         -> search key
mp.count(key)        -> returns 0 or 1
mp.erase(key)        -> delete key
mp.size()            -> size
mp.clear()           -> delete all
mp.empty()           -> check empty

-----------------------------------------------------

8. IMPORTANT WARNING ABOUT []
---------------------------------
- mp[key] CREATES key if it does not exist.
- Use find() or count() to check existence safely.

-----------------------------------------------------

9. ITERATION
---------------------------------
- Iteration order is RANDOM.
- Never assume sorted order.

-----------------------------------------------------

10. LOAD FACTOR & REHASHING
---------------------------------
- load_factor = (number of elements) / (number of buckets)
- If load factor becomes too high -> rehashing occurs
- Rehashing is costly.

-----------------------------------------------------

11. CUSTOM KEY (INTERVIEW FAVORITE)
---------------------------------
- Custom data types need custom hash function.

-----------------------------------------------------

12. COMMON MISTAKES
---------------------------------
- Assuming sorted order
- Using [] to check existence
- Forgetting worst-case O(n)
- Not defining hash for custom keys

=====================================================
*/

int main() {
    // Create an unordered_map (key = string, value = int)
    unordered_map<string, int> marks;

    // ---------- INSERTION METHODS ----------

    // Method 1: insert using make_pair
    marks.insert(make_pair("babbar", 3));

    // Method 2: insert using pair constructor
    marks.insert({"love", 2});

    // Method 3: insert using [] operator
    marks["mera"] = 1;

    // Updating existing key
    marks["mera"] = 5;   // value changes from 1 → 5

    // ---------- ACCESSING VALUES ----------

    cout << "mera  : " << marks["mera"] << endl;
    cout << "babbar: " << marks.at("babbar") << endl;

    // ---------- UNKNOWN KEY BEHAVIOR ----------
    // cout << m.at("unknownKey") << endl; // throws exception
    // Using [] with unknown key
    cout << "unknownKey: " << marks["unknownKey"] << endl;
    // After this line, "unknownKey" is added to map with value 0
    cout << endl;
    cout << endl;
    cout << endl;




    // unordered_map<pair<int, int>, int> canNotDoThisInUnorderedMap_butcanDoThisWithOrderedMaps;


    // 1. Declaration
    unordered_map<int, int> mp;

    // 2. Insertion methods
    mp[1] = 10;              // inserts key 1 with value 10
    mp.insert({2, 20});      // insert using pair
    mp.emplace(3, 30);       // faster insertion

    /*
    NOTE:
    - mp[key] creates key if not present
    - insert() does NOT overwrite existing key
    */

    // 3. Accessing elements
    cout << "Value at key 1: " << mp[1] << endl;

    /*
    WARNING:
    mp[100] will CREATE key 100 with value 0
    */

    // 4. Safe searching
    if (mp.find(2) != mp.end()) {
        cout << "Key 2 exists\n";
    }

    if (mp.count(3)) {
        cout << "Key 3 exists\n";
    }

    // 5. Iteration (order NOT guaranteed)
    cout << "\nIterating unordered_map:\n";
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // 6. Deletion
    mp.erase(2);     // deletes key 2

    // 7. Size and checks
    cout << "\nSize: " << mp.size() << endl;
    cout << "Is empty? " << (mp.empty() ? "Yes" : "No") << endl;

    // 8. Load factor info
    cout << "\nLoad Factor: " << mp.load_factor() << endl;
    cout << "Max Load Factor: " << mp.max_load_factor() << endl;

    /*
    NOTE:
    - High load factor causes rehashing
    - Rehashing reduces performance temporarily
    */

    // 9. Frequency counting example
    int arr[] = {1, 2, 2, 3, 3, 3};
    unordered_map<int, int> freq;

    for (int x : arr) {
        freq[x]++;
    }

    cout << "\nFrequency Count:\n";
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}
