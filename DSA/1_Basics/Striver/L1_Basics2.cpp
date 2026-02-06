#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
====================================================
TOPIC 1: ARRAYS
====================================================

An array is a collection of elements of the same
data type stored in contiguous memory locations.

Properties:
- Fixed size
- Indexed starting from 0
- Fast access using index
- Uninitialized arrays may contain garbage values

Example:
int arr[5];

====================================================
TOPIC 2: STRINGS
====================================================

Strings are sequences of characters.

In C++:
1) char array  → char name[20]
2) string class → string name

Important:
- cin ignores spaces
- getline() reads full line
- string supports many built-in functions

====================================================
TOPIC 3: LOOPS
====================================================

Loops are used to execute code repeatedly.

Types:
1) for loop     → known number of iterations
2) while loop  → condition based
3) do-while    → executes at least once

====================================================
TOPIC 4: FUNCTIONS
====================================================

Functions are blocks of code that perform a task.

Benefits:
- Code reusability
- Modularity
- Better readability

PASS BY VALUE:
- Copy of variable is passed
- Original value does NOT change

PASS BY REFERENCE:
- Reference (alias) is passed
- Original value DOES change
====================================================
*/

void passByValue(int num) {
    cout << "Inside passByValue\n";
    num += 10;
    cout << "Value inside function: " << num << endl;
}

void passByReference(int &num) {
    cout << "Inside passByReference\n";
    num += 10;
    cout << "Value inside function: " << num << endl;
}

int main() {

    /* -------------------------------
       ARRAYS
    -------------------------------- */
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    /* -------------------------------
       STRINGS
    -------------------------------- */
    cin.ignore();
    string s;
    getline(cin, s);
    cout << "String entered: " << s << endl;

    /* -------------------------------
       LOOPS
    -------------------------------- */
    cout << "For loop:\n";
    for (int i = 1; i <= 3; i++) {
        cout << i << " ";
    }
    cout << endl;

    cout << "While loop:\n";
    int i = 1;
    while (i <= 3) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    cout << "Do-While loop:\n";
    int j = 1;
    do {
        cout << j << " ";
        j++;
    } while (j <= 3);
    cout << endl;

    /* -------------------------------
       FUNCTIONS
    -------------------------------- */
    int x = 20;

    passByValue(x);
    cout << "After passByValue, x = " << x << endl;

    passByReference(x);
    cout << "After passByReference, x = " << x << endl;

    return 0;
}
