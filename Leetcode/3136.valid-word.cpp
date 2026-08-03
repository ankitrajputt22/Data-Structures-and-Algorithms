#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
    LeetCode 3136: Valid Word

    Problem:
    We are given a string word.
    We have to check if it is a valid word.

    A word is valid if:
    1. It has at least 3 characters.
    2. It contains only English letters and digits.
    3. It contains at least one vowel.
    4. It contains at least one consonant.

    Vowels:
    a, e, i, o, u
    Both lowercase and uppercase are allowed.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Check every character manually.
    Use strings to search whether a character is valid,
    vowel, digit, or consonant.

    Step-by-step algorithm:
    1. If word length is less than 3, return false.
    2. Create strings for letters, digits, and vowels.
    3. Traverse every character of word.
    4. Check if character is letter or digit.
    5. If not, return false.
    6. If character is vowel, mark hasVowel true.
    7. Else if character is letter, mark hasConsonant true.
    8. At the end, return true only if both flags are true.

    Time complexity:
    O(n * 62)

    Space complexity:
    O(1)

    Note:
    n is the length of word.
    62 is for checking all letters and digits.
    This is simple but does extra searching.

------------------------------------------------------------*/
bool isPresent(char ch, string s) {
    for (int i = 0; i < s.size(); i++) {
        if (ch == s[i]) {
            return true;
        }
    }

    return false;
}

bool isValidBruteForce(string word) {
    if (word.size() < 3) {
        return false;
    }

    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string vowels = "aeiouAEIOU";

    bool hasVowel = false;
    bool hasConsonant = false;

    for (int i = 0; i < word.size(); i++) {
        char ch = word[i];

        bool isLetter = isPresent(ch, letters);
        bool isDigit = isPresent(ch, digits);

        if (isLetter == false && isDigit == false) {
            return false;
        }

        if (isPresent(ch, vowels)) {
            hasVowel = true;
        } else if (isLetter == true) {
            hasConsonant = true;
        }
    }

    if (hasVowel == true && hasConsonant == true) {
        return true;
    }

    return false;
}

/*------------------------------------------------------------

    Approach 2: Better Solution

    Basic idea:
    Use built-in function isalnum.
    Use a helper function to check vowels.
    Traverse the string only once.

    Step-by-step algorithm:
    1. If word length is less than 3, return false.
    2. Create hasVowel and hasConsonant as false.
    3. Traverse every character.
    4. If character is not letter or digit, return false.
    5. If character is a letter:
       check if it is vowel.
    6. If vowel, mark hasVowel true.
    7. Else mark hasConsonant true.
    8. Return true if both flags are true.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is better than brute force.
    It avoids repeated searching in long strings.

------------------------------------------------------------*/
bool isVowelBetter(char ch) {
    ch = tolower(ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    }

    return false;
}

bool isValidBetter(string word) {
    if (word.size() < 3) {
        return false;
    }

    bool hasVowel = false;
    bool hasConsonant = false;

    for (int i = 0; i < word.size(); i++) {
        char ch = word[i];

        if (!isalnum(ch)) {
            return false;
        }

        if (isalpha(ch)) {
            if (isVowelBetter(ch)) {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        }
    }

    return hasVowel && hasConsonant;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution

    Basic idea:
    Check everything in one pass.
    Use ASCII conditions.
    Do not use extra strings.

    Step-by-step algorithm:
    1. If word length is less than 3, return false.
    2. Create hasVowel and hasConsonant as false.
    3. Traverse every character.
    4. Check if it is lowercase letter.
    5. Check if it is uppercase letter.
    6. Check if it is digit.
    7. If it is none of them, return false.
    8. If it is a letter, check vowel or consonant.
    9. Return true if both vowel and consonant exist.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It is simple and checks each character once.

------------------------------------------------------------*/
bool isVowelOptimal(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
    }

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    }

    return false;
}

bool isValidOptimal(string word) {
    if (word.size() < 3) {
        return false;
    }

    bool hasVowel = false;
    bool hasConsonant = false;

    for (int i = 0; i < word.size(); i++) {
        char ch = word[i];

        bool isLower = (ch >= 'a' && ch <= 'z');
        bool isUpper = (ch >= 'A' && ch <= 'Z');
        bool isDigit = (ch >= '0' && ch <= '9');

        if (isLower == false && isUpper == false && isDigit == false) {
            return false;
        }

        if (isLower == true || isUpper == true) {
            if (isVowelOptimal(ch)) {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        }
    }

    return hasVowel && hasConsonant;
}

/*------------------------------------------------------------

    Helper function:
    This function prints boolean answer.

------------------------------------------------------------*/
void printAnswer(bool ans) {
    if (ans == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    string word = "234Adas";

    bool ans1 = isValidBruteForce(word);
    bool ans2 = isValidBetter(word);
    bool ans3 = isValidOptimal(word);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}