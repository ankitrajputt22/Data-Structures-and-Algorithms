/*
L6.... Hashing | Maps | Time Complexity | Collisions | Division Rule of Hashing | Strivers A2Z DSA Course ............@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function for integer frequency hashing
int integerFrequencyHashing(const vector<int>& arr, int num) {
    unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }
    return freq[num]; // Returns 0 if num doesn't exist
}

// Function for character frequency hashing (fixed version of your code)
void characterFrequencyHashing() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // Precompute frequencies (a-z, case-sensitive)
    int hash[26] = {0}; // Only works for lowercase letters
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            hash[s[i] - 'a']++; // Map 'a'-'z' to 0-25
        }
    }

    // Query handling
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while (q--) {
        char c;
        cout << "Enter a character to check its frequency: ";
        cin >> c;
        if (c >= 'a' && c <= 'z') {
            cout << "Frequency of '" << c << "': " << hash[c - 'a'] << endl;
        } else {
            cout << "Only lowercase letters (a-z) are supported.\n";
        }
    }
}

// Function for STL-based number hashing
void numHashingUsingStl() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);  // Using vector instead of VLA
    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Precompute frequencies using unordered_map
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    // Query handling
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while(q--) {
        int number;
        cout << "Enter a number to check its frequency: ";
        cin >> number;
        cout << "Frequency: " << mpp[number] << endl;
    }
}

int main() {
    int choice;
    cout << "Choose mode:\n1. Integer Hashing\n2. Character Hashing\n3. STL Number Hashing\nEnter choice: ";
    cin >> choice;


    if (choice == 1) {
        // Integer Hashing Mode
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int num;
        cout << "Enter a number to check its frequency: ";
        cin >> num;

        int freq = integerFrequencyHashing(arr, num);
        cout << "Frequency of " << num << " in the array is: " << freq << endl;
    } 
    else if (choice == 2) {
        // Character Hashing Mode (fixed version)
        characterFrequencyHashing();
    } 
    else if(choice == 3) {
        numHashingUsingStl();
    }
    else {
        cout << "Invalid choice!\n";
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




