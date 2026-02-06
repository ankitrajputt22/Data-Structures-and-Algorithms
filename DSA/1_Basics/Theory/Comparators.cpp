#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";



bool myComparator(int a, int b) {
    if(a > b) {
        return true;
    }
    return false;
    
    // This can be simplified to: return a > b;
}

bool myComparator2(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) {
        if (p1.second > p2.second) {
            return true;
        }
    }

    if (p1.first > p2.first) {
        return true;
    }

    return false;
}

class myCompartor3 {
public: 
    bool operator()(int a, int b) {
        return a > b;
    }
};

void print(vector<pair<int, int>>& vec) {
    for(pair<int, int> &p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main() {
    newline1;
    vector<int> vec = {1, 3, 5, 6, 2};
    cout << "Original vector: ";
    for(int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    
    // Using custom comparator for ascending order
    sort(begin(vec), end(vec), myComparator);
    // sort(vec.begin(), vec.end(), myComparator); // Alternative syntax

    cout << "Sorted (descending order) vector: ";
    for(int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    newline2;




    vector<pair<int, int>> vec2 = {{2, 3}, {2, 4}, {3, 1}};
    cout << "Original vector: ";
    print(vec2);
    sort(begin(vec2), end(vec2));
    
    cout << "Sorted vector: ";
    print(vec2);

    cout << "Descending order vector: " << endl;
    sort(begin(vec2), end(vec2), myComparator2);
    print(vec2);
    newline2;



    vector<int> vec3 = {1, 3, 5, 6, 2};
    sort(begin(vec3), end(vec3), myCompartor3());
    cout << "Sorted (descending order) vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    newline2;


    /*
    auto lambda = [capture_clause](parameters) -> return_type {
    // lambda body
    };

    1. Capture Nothing []
    The lambda cannot access any variables from the surrounding scope. It can only use its parameters and global variables.
    int external = 10;
    auto lambda = []() { 
        // std::cout << external; // ERROR: 'external' is not captured
        return 42;
    };

    2. Capture by Value [=]
    Captures all variables from the surrounding scope by value. The lambda gets its own copy of the variables at the moment the lambda is defined.
    --> mutable Keyword: To modify the captured copies, use the mutable keyword. This does not affect the original variables. auto lambda = [=]() mutable 

    int x = 10;
    int y = 20;
    auto lambda = [=]() { // Captures 'x' and 'y' by value
        cout << x + y; // OK: Uses the copies (x=10, y=20)
        // x = 5; // ERROR: By-default, copies are const-by-value
    };
    lambda();
    cout << x; // Output: 10 (original is unchanged)


    3. Capture by Reference [&]
    Captures all variables from the surrounding scope by reference. Changes made inside the lambda affect the original variables.


    4. Mixed Capture [=, &y] or [&, x]
    Capture most variables one way, but specify specific variables to capture the other way.
    [=, &y]: Capture everything by value, but capture y by reference.
    [&, x]: Capture everything by reference, but capture x by value.


    5. Capture Specific Variables [x, &y]
    Explicitly list which variables to capture and how. This is often the safest and most readable option.
    [x]: Capture x by value.
    [&y]: Capture y by reference.
    [x, &y]: Capture x by value and y by reference.


    6. Capture this Pointer [this] or [*this]
    Inside a class member function, you can capture the class's members.
    [this]: Captures the this pointer by value. You can access all class members (including private ones) via the pointer.
    [*this] (C++17): Captures a copy of the current class object.

    class MyClass {
        int value = 5;
    public: 
        void print() {
            auto lambda = [this]() {
                std::cout << value; // OK: Accesses member via 'this'
            };
            lambda();
        }
    };


    */

    
    return 0;
}