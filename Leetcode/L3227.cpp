#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//Approach-1 (Simple math)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool doesAliceWin(string s) {

        for(char &ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }

        return false;
    }
};


//Approach-2 (Using one liner STL)
//T.C : O(n)
//S.C : O(1)
class Solution_2 {
public:
    bool doesAliceWin(string s) {
        /*
        auto lambda = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }
        */

        auto lambda = [](char ch) {
            return string("aeiou").find(ch) != string::npos;
        };

        return any_of(s.begin(), s.end(), lambda);
    }
};

int main() {
    newline1;
    vector<int> numbers = {1, 5, -2, 10, 8};

    // Check if any element is negative
    auto lambda = [](int num) {
        return num < 0;
    };

    if (any_of(numbers.begin(), numbers.end(), lambda)) {
        std::cout << "Yes, there is at least one negative number.\n";
    } else {
        std::cout << "All numbers are non-negative.\n";
    }
    newline2;


    int n = numbers.size();    
    bool hasEven = any_of(numbers.begin(), numbers.end(), [](int x) { return x % 2 == 0; });
                        
    cout << "Array has an even number: " << boolalpha << hasEven << endl;
    newline2;

    return 0;
}