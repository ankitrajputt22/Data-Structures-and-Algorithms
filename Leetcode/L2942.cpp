#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";



//Approach (usin c++ STL)
//T.C : O(m*n) 
//S.C : O(1)
class Solution_1 {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i].find(x) != string::npos) {
                res.push_back(i);
            }
        }
        return res;
    }
};

/*
std::string str = "Hello123";

// Check if any character is a digit
bool hasDigit = std::any_of(str.begin(), str.end(), ::isdigit);

// Check if any character is uppercase
bool hasUpper = std::any_of(str.begin(), str.end(), ::isupper);

// Check if any character is a punctuation mark
bool hasPunct = std::any_of(str.begin(), str.end(), ::ispunct);
*/


class Solution_2 {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        auto lambda = [x](int num) {
            return num == x;
        };

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (any_of(words[i].begin(), words[i].end(), lambda)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};


/*
What is std::string::find?
It's a member function of the std::string class used to search for a substring or character within a string. It returns the position (index) of the first occurrence.
example-
    size_t second_abc = data.find("abc", 1); // Start searching from index 1

rfind(): Finds the last occurrence (searches from the end).
find_first_of(): Finds the first occurrence of any character in a given set.
find_last_of(): Finds the last occurrence of any character in a given set.


*/

int main() {
    newline1;
    string sentence = "I love C++ programming";
    
    size_t found = sentence.find("C++"); // Search for "C++"
    
    if (found != string::npos) {
        cout << "Found at index: " << found; // Output: Found at index: 7
    } else {
        cout << "Not found";
    }
    return 0;
}