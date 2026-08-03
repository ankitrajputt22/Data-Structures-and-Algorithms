#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>

using namespace std;

/*
========================================================
               COMPARATORS IN C++ (STL)
========================================================

A COMPARATOR is a function (or function-like object)
that defines HOW elements are ordered.

--------------------------------------------------------
BASIC RULE:
--------------------------------------------------------
comp(a, b) == true  → a comes BEFORE b

--------------------------------------------------------
WHY COMPARATORS ARE IMPORTANT?
--------------------------------------------------------
- Custom sorting
- Used in sort(), set, map, priority_queue
- Needed for pairs, structs, classes
- Critical for interviews & competitive programming

--------------------------------------------------------
DEFAULT BEHAVIOR:
--------------------------------------------------------
sort(v.begin(), v.end());
→ Sorts in ASCENDING order using operator<

--------------------------------------------------------
COMPARATOR MUST FOLLOW STRICT WEAK ORDERING
--------------------------------------------------------
1. comp(a, a) == false
2. If comp(a, b) == true, then comp(b, a) == false
3. Transitive:
   If comp(a, b) && comp(b, c) → comp(a, c)

❌ Violating these rules → UNDEFINED BEHAVIOR

========================================================
TYPES OF COMPARATORS
========================================================
1. Lambda comparator
2. Normal function comparator
3. Functor (struct with operator())
4. STL provided (greater<>)

========================================================
*/

////////////////////////////////////////////////////////
// 1. NORMAL FUNCTION COMPARATOR
////////////////////////////////////////////////////////

bool descCompare(int a, int b) {
    return a > b;   // descending order
}

////////////////////////////////////////////////////////
// 2. FUNCTOR COMPARATOR (Function Object)
////////////////////////////////////////////////////////

struct FunctorCompare {
    bool operator()(int a, int b) const {
        return a > b;   // descending
    }
};

////////////////////////////////////////////////////////
// CUSTOM CLASS FOR SORTING
////////////////////////////////////////////////////////

class Student {
public:
    string name;
    int marks;
};

bool studentCompare(Student a, Student b) {
    return a.marks > b.marks;   // sort by marks descending
}

////////////////////////////////////////////////////////
// MAIN PROGRAM
////////////////////////////////////////////////////////

int main() {

    /*
    ====================================================
    SORT WITH COMPARATORS
    ====================================================
    */

    vector<int> v = {5, 1, 4, 2, 3};

    // Default sort (ascending)
    sort(v.begin(), v.end());

    // Lambda comparator (descending)
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });

    // Normal function comparator
    sort(v.begin(), v.end(), descCompare);

    // Functor comparator
    sort(v.begin(), v.end(), FunctorCompare());

    /*
    ====================================================
    SORTING PAIRS USING COMPARATOR
    ====================================================
    */

    vector<pair<int,int>> vp = {{1,3}, {2,2}, {3,1}};

    // Sort by second element
    sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });

    // Sort by second, then first
    sort(vp.begin(), vp.end(), [](auto &a, auto &b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    /*
    ====================================================
    SORTING CUSTOM OBJECTS
    ====================================================
    */

    vector<Student> students = {
        {"Alice", 85},
        {"Bob", 90},
        {"Charlie", 80}
    };

    sort(students.begin(), students.end(), studentCompare);

    /*
    ====================================================
    COMPARATORS IN set AND map
    ====================================================
    */

    // Default ascending
    set<int> s1;

    // Descending using STL comparator
    set<int, greater<int>> s2;

    // Custom functor comparator
    set<int, FunctorCompare> s3;

    /*
    IMPORTANT:
    - Comparator in set/map defines UNIQUENESS
    - If comp(a,b)==false AND comp(b,a)==false
      → a and b are considered EQUAL
    */

    /*
    ====================================================
    COMPARATORS IN map
    ====================================================
    */

    map<int,int> mp1;                      // ascending
    map<int,int, greater<int>> mp2;        // descending
    map<int,int, FunctorCompare> mp3;      // custom

    /*
    ====================================================
    COMPARATORS IN priority_queue
    ====================================================
    */

    // Default max heap
    priority_queue<int> pq1;

    // Min heap using STL comparator
    priority_queue<int, vector<int>, greater<int>> pq2;

    // Min heap using custom functor
    priority_queue<int, vector<int>, FunctorCompare> pq3;

    /*
    NOTE (VERY IMPORTANT):
    priority_queue comparator logic feels REVERSED.

    In priority_queue:
    comp(a, b) == true → a has LOWER priority than b
    */

    /*
    ====================================================
    COMMON MISTAKES (DO NOT DO THIS)
    ====================================================

    ❌ Using >= or <= in comparator
    ❌ Returning true for equal elements
    ❌ Violating transitivity
    ❌ Assuming comparator works same in priority_queue
    ❌ Forgetting comparator defines uniqueness in set/map
    */

    /*
    ====================================================
    WHEN TO USE WHICH COMPARATOR
    ====================================================

    Lambda:
    - Short logic
    - One-time usage
    - Most common in CP

    Function:
    - Simple reusable logic

    Functor:
    - Required for set/map/priority_queue
    - Best for complex logic
    */

    /*
    ====================================================
    INTERVIEW QUESTIONS TO PREPARE
    ====================================================

    1. What is a comparator?
    2. What does comp(a,b) return?
    3. Why strict weak ordering is required?
    4. How comparator affects set uniqueness?
    5. Why priority_queue comparator is reversed?
    6. Difference between sort and stable_sort?
    7. Lambda vs functor?
    */

    return 0;
}
