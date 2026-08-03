#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 3517: Smallest Palindromic Rearrangement I

    Problem:
    We are given a palindromic string s.

    We have to rearrange its characters and return
    the lexicographically smallest palindrome.

    Lexicographically smallest:
    Smaller characters should come as early as possible.

    Important:
    s is already palindromic.
    So a palindromic rearrangement is always possible.
*/

/*------------------------------------------------------------

    Helper function:
    This function checks if a string is palindrome.

------------------------------------------------------------*/
bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Generate all permutations in sorted order.
    The first palindrome found will be the smallest answer.

    Step-by-step algorithm:
    1. Sort the string.
    2. Generate all permutations.
    3. For every permutation, check if it is palindrome.
    4. If it is palindrome, return it.
    5. If no answer is found, return empty string.

    Time complexity:
    O(n! * n)

    Space complexity:
    O(1)

    Note:
    This solution can give TLE for large input.
    It checks many permutations.
    It is only for understanding.

------------------------------------------------------------*/
string smallestPalindromeBruteForce(string s) {
    sort(s.begin(), s.end());

    do {
        if (isPalindrome(s)) {
            return s;
        }
    } while (next_permutation(s.begin(), s.end()));

    return "";
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Sorting

    Basic idea:
    Sort the string.
    Use half count of every character for the left side.
    Use the odd character in the middle.
    Mirror the left side to make the right side.

    Step-by-step algorithm:
    1. Sort the string.
    2. Traverse the sorted string.
    3. Count frequency of the current character.
    4. Add frequency / 2 characters to left part.
    5. If frequency is odd, store it as middle character.
    6. Reverse left part to make right part.
    7. Return left + middle + right.

    Time complexity:
    O(n log n)

    Space complexity:
    O(n)

    Note:
    This is better than brute force.
    Sorting helps us place smaller characters first.
    But sorting is not needed because only lowercase letters exist.

------------------------------------------------------------*/
string smallestPalindromeBetter(string s) {
    sort(s.begin(), s.end());

    string left = "";
    string middle = "";

    int i = 0;
    int n = s.size();

    while (i < n) {
        char ch = s[i];
        int count = 0;

        while (i < n && s[i] == ch) {
            count++;
            i++;
        }

        for (int j = 0; j < count / 2; j++) {
            left.push_back(ch);
        }

        if (count % 2 == 1) {
            middle = ch;
        }
    }

    string right = left;
    reverse(right.begin(), right.end());

    return left + middle + right;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Frequency Array

    Basic idea:
    Count frequency of each character.
    Build the left half from 'a' to 'z'.
    Put the odd character in the middle.
    Then mirror the left half.

    Step-by-step algorithm:
    1. Create frequency array of size 26.
    2. Count every character in s.
    3. Create left string.
    4. Create middle string.
    5. Traverse characters from 'a' to 'z'.
    6. Add half of each character to left.
    7. If any character has odd frequency,
       store it as middle.
    8. Reverse left to create right.
    9. Return left + middle + right.

    Time complexity:
    O(n + 26)

    Space complexity:
    O(n)

    Note:
    This is the best simple approach.
    It does not sort the string.
    It uses the lowercase English letter property.

------------------------------------------------------------*/
string smallestPalindromeOptimal(string s) {
    vector<int> freq(26, 0);

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
    }

    string left = "";
    string middle = "";

    for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;

        for (int j = 0; j < freq[i] / 2; j++) {
            left.push_back(ch);
        }

        if (freq[i] % 2 == 1) {
            middle = ch;
        }
    }

    string right = left;
    reverse(right.begin(), right.end());

    return left + middle + right;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Direct Filling

    Basic idea:
    Count frequency of each character.
    Fill the answer from both ends.
    Put smaller characters first on the left side.

    Step-by-step algorithm:
    1. Count frequency of all characters.
    2. Create answer string of same size as s.
    3. Create left pointer at 0.
    4. Create right pointer at n - 1.
    5. Traverse characters from 'a' to 'z'.
    6. While frequency is at least 2:
       place character at left and right.
    7. Move left forward and right backward.
    8. If one odd character remains,
       place it in the middle.
    9. Return answer.

    Time complexity:
    O(n + 26)

    Space complexity:
    O(n)

    Note:
    This is also optimal.
    It avoids creating a separate reversed string.
    It directly builds the final answer.

------------------------------------------------------------*/
string smallestPalindromeOptimalDirectFill(string s) {
    vector<int> freq(26, 0);

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
    }

    int n = s.size();
    string ans(n, ' ');

    int left = 0;
    int right = n - 1;

    for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;

        while (freq[i] >= 2) {
            ans[left] = ch;
            ans[right] = ch;

            left++;
            right--;

            freq[i] = freq[i] - 2;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] == 1) {
            ans[n / 2] = 'a' + i;
            break;
        }
    }

    return ans;
}

/*------------------------------------------------------------

    Helper function:
    This function prints the answer.

------------------------------------------------------------*/
void printAnswer(string ans) {
    cout << ans << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    string s = "babab";

    string ans1 = smallestPalindromeBruteForce(s);
    string ans2 = smallestPalindromeBetter(s);
    string ans3 = smallestPalindromeOptimal(s);
    string ans4 = smallestPalindromeOptimalDirectFill(s);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Sorting:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution using Frequency Array:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution using Direct Filling:" << endl;
    printAnswer(ans4);

    return 0;
}