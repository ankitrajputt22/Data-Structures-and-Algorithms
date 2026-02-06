#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
====================================================
TOPIC 1: USER INPUT / OUTPUT
====================================================

cout  → used to print output to the screen
cin   → used to take input from the user

Important:
- cin ignores whitespace
- getline() reads a full line including spaces
- Use cin.ignore() before getline() if mixed with cin

Example:
cin >> a;
getline(cin, s);

====================================================
TOPIC 2: DATA TYPES
====================================================

int        → stores integers (4 bytes)
long long → stores very large integers (8 bytes)
float     → decimal values (less precision)
double    → decimal values (more precision)
char      → single character
string    → sequence of characters

====================================================
TOPIC 3: IF ELSE STATEMENTS
====================================================

Used for decision making.

Syntax:
if (condition) { }
else if (condition) { }
else { }

Rules:
- Conditions must be boolean
- Checked top to bottom
- First true condition executes

====================================================
TOPIC 4: SWITCH STATEMENT
====================================================

Used when comparing a variable with fixed values.

Syntax:
switch(variable) {
  case value:
    statements;
    break;
  default:
    statements;
}

Rules:
- Works with int, char (not string)
- break is important to avoid fall-through
====================================================
*/

int main() {

    /* -------------------------------
       USER INPUT / OUTPUT
    -------------------------------- */
    int a, b;
    cin >> a >> b;
    cout << "Sum: " << a + b << endl;

    cin.ignore();
    string line;
    getline(cin, line);
    cout << "You entered: " << line << endl;

    /* -------------------------------
       DATA TYPES
    -------------------------------- */
    int x = 10;
    long long y = 10000000000LL;
    float f = 3.14f;
    double d = 3.1415926535;
    char ch = 'A';
    string s = "C++";

    cout << x << " " << y << " " << f << " "
         << d << " " << ch << " " << s << endl;

    /* -------------------------------
       IF ELSE STATEMENT
    -------------------------------- */
    int marks;
    cin >> marks;

    if (marks < 25) {
        cout << "Grade: F" << endl;
    }
    else if (marks <= 44) {
        cout << "Grade: E" << endl;
    }
    else if (marks <= 59) {
        cout << "Grade: C" << endl;
    }
    else if (marks <= 79) {
        cout << "Grade: B" << endl;
    }
    else if (marks <= 100) {
        cout << "Grade: A" << endl;
    }
    else {
        cout << "Invalid Marks" << endl;
    }

    /* -------------------------------
       SWITCH STATEMENT
    -------------------------------- */
    int day;
    cin >> day;

    switch (day) {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        case 7:
            cout << "Sunday" << endl;
            break;
        default:
            cout << "Invalid Day" << endl;
    }

    return 0;
}



//L6.... Hashing | Maps | Time Complexity | Collisions | Division Rule of Hashing | Strivers A2Z DSA Course ............@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// // Function for integer frequency hashing
// int integerFrequencyHashing(const vector<int>& arr, int num) {
//     unordered_map<int, int> freq;
//     for (int x : arr) {
//         freq[x]++;
//     }
//     return freq[num]; // Returns 0 if num doesn't exist
// }

// // Function for character frequency hashing (fixed version of your code)
// void characterFrequencyHashing() {
//     string s;
//     cout << "Enter a string: ";
//     cin >> s;

//     // Precompute frequencies (a-z, case-sensitive)
//     int hash[26] = {0}; // Only works for lowercase letters
//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] >= 'a' && s[i] <= 'z') {
//             hash[s[i] - 'a']++; // Map 'a'-'z' to 0-25
//         }
//     }

//     // Query handling
//     int q;
//     cout << "Enter number of queries: ";
//     cin >> q;
//     while (q--) {
//         char c;
//         cout << "Enter a character to check its frequency: ";
//         cin >> c;
//         if (c >= 'a' && c <= 'z') {
//             cout << "Frequency of '" << c << "': " << hash[c - 'a'] << endl;
//         } else {
//             cout << "Only lowercase letters (a-z) are supported.\n";
//         }
//     }
// }

// // Function for STL-based number hashing
// void numHashingUsingStl() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     vector<int> arr(n);  // Using vector instead of VLA
//     cout << "Enter the array elements: ";
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     // Precompute frequencies using unordered_map
//     unordered_map<int, int> mpp;
//     for(int i = 0; i < n; i++) {
//         mpp[arr[i]]++;
//     }

//     // Query handling
//     int q;
//     cout << "Enter number of queries: ";
//     cin >> q;
//     while(q--) {
//         int number;
//         cout << "Enter a number to check its frequency: ";
//         cin >> number;
//         cout << "Frequency: " << mpp[number] << endl;
//     }
// }

// int main() {
//     int choice;
//     cout << "Choose mode:\n1. Integer Hashing\n2. Character Hashing\n3. STL Number Hashing\nEnter choice: ";
//     cin >> choice;


//     if (choice == 1) {
//         // Integer Hashing Mode
//         int n;
//         cout << "Enter number of elements: ";
//         cin >> n;

//         vector<int> arr(n);
//         cout << "Enter the array elements: ";
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }

//         int num;
//         cout << "Enter a number to check its frequency: ";
//         cin >> num;

//         int freq = integerFrequencyHashing(arr, num);
//         cout << "Frequency of " << num << " in the array is: " << freq << endl;
//     } 
//     else if (choice == 2) {
//         // Character Hashing Mode (fixed version)
//         characterFrequencyHashing();
//     } 
//     else if(choice == 3) {
//         numHashingUsingStl();
//     }
//     else {
//         cout << "Invalid choice!\n";
//     }

//     return 0;
// }




