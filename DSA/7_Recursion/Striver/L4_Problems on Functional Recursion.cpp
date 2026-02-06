#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

//125. Valid Palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right){
            if (!isalnum(s[left])){
                left++;
            } 
            else if (!isalnum(s[right])){
                right--;
            }
            else if (tolower(s[left]) != tolower(s[right])){
                return false;
            } 
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};



bool isPalindrome(int i, string s) {
    int n = s.length();
    if (i >= n / 2) return true;

    if (s[i] != s[n - i - 1]) return false;
    
    return isPalindrome(i + 1, s);
}


class Solution_2 {
public:
    bool isPalindrome(string s) {
        int n = s.length();

        int l = 0, r = n - 1;
        while (l < r) {
            while (l < n && !isalnum(s[l])) {
                l++;
            }

            while (r >= 0 && !isalnum(s[r])) {
                r--;
            }

            if (l >= r) break;

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};


int main() {
    newline1;


    return 0;
}