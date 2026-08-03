#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

/*
    LeetCode 17: Letter Combinations of a Phone Number

    Problem:
    We are given a string digits.
    It contains digits from 2 to 9.

    Each digit maps to some letters like phone keypad.

    Mapping:
    2 -> abc
    3 -> def
    4 -> ghi
    5 -> jkl
    6 -> mno
    7 -> pqrs
    8 -> tuv
    9 -> wxyz

    We have to return all possible letter combinations.

    Example:
    digits = "23"

    Answer:
    ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
*/

/*------------------------------------------------------------

    Phone keypad mapping

------------------------------------------------------------*/
vector<string> phone = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

/*------------------------------------------------------------

    Helper function:
    This function checks if character ch is present
    in the string letters.

------------------------------------------------------------*/
bool isPresent(char ch, string letters) {
    for (int i = 0; i < letters.size(); i++) {
        if (letters[i] == ch) {
            return true;
        }
    }

    return false;
}

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    For every digit, try all letters from 'a' to 'z'.
    Take only those letters which belong to current digit.

    Step-by-step algorithm:
    1. If digits is empty, return empty answer.
    2. Start recursion from index 0.
    3. For current digit, get its valid letters.
    4. Try every character from 'a' to 'z'.
    5. If character is present in valid letters,
       add it to current combination.
    6. Recursively solve for next index.
    7. Remove the last added character.
    8. When index reaches end, store combination.
    9. Return all combinations.

    Time complexity:
    O(26 * totalCombinations)

    Space complexity:
    O(n)

    Note:
    n is the length of digits.
    This is a brute force style solution.
    It checks many letters which are not needed.
    For large input, it can be slow.

------------------------------------------------------------*/
void solveBruteForce(int index, string& digits, string& current, vector<string>& ans) {
    if (index == digits.size()) {
        ans.push_back(current);
        return;
    }

    int digit = digits[index] - '0';
    string letters = phone[digit];

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (isPresent(ch, letters)) {
            current.push_back(ch);

            solveBruteForce(index + 1, digits, current, ans);

            current.pop_back();
        }
    }
}

vector<string> letterCombinationsBruteForce(string digits) {
    vector<string> ans;

    if (digits.size() == 0) {
        return ans;
    }

    string current = "";

    solveBruteForce(0, digits, current, ans);

    return ans;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Iteration

    Basic idea:
    Build combinations digit by digit.
    For every new digit, attach its letters
    to all previous combinations.

    Step-by-step algorithm:
    1. If digits is empty, return empty answer.
    2. Start answer with one empty string.
    3. Traverse every digit.
    4. Get letters for current digit.
    5. Create a temporary vector.
    6. For every old combination:
       add every possible current letter.
    7. Store new combinations in temp.
    8. Replace answer with temp.
    9. Return answer.

    Time complexity:
    O(totalCombinations * n)

    Space complexity:
    O(totalCombinations * n)

    Note:
    This is better than brute force.
    It only tries valid letters.
    It builds answers level by level.

------------------------------------------------------------*/
vector<string> letterCombinationsBetterIterative(string digits) {
    vector<string> ans;

    if (digits.size() == 0) {
        return ans;
    }

    ans.push_back("");

    for (int i = 0; i < digits.size(); i++) {
        int digit = digits[i] - '0';
        string letters = phone[digit];

        vector<string> temp;

        for (int j = 0; j < ans.size(); j++) {
            for (int k = 0; k < letters.size(); k++) {
                string newString = ans[j] + letters[k];
                temp.push_back(newString);
            }
        }

        ans = temp;
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 3: Better Solution using Queue

    Basic idea:
    Use a queue to build combinations.
    Each level of queue represents one digit.

    Step-by-step algorithm:
    1. If digits is empty, return empty answer.
    2. Push empty string into queue.
    3. Traverse every digit.
    4. Find current queue size.
    5. Remove old combinations one by one.
    6. Add each possible letter to old combination.
    7. Push new combination back into queue.
    8. After all digits are processed,
       move queue values into answer.
    9. Return answer.

    Time complexity:
    O(totalCombinations * n)

    Space complexity:
    O(totalCombinations * n)

    Note:
    This is also a good approach.
    It is like BFS.
    It avoids recursion.

------------------------------------------------------------*/
vector<string> letterCombinationsBetterQueue(string digits) {
    vector<string> ans;

    if (digits.size() == 0) {
        return ans;
    }

    queue<string> q;
    q.push("");

    for (int i = 0; i < digits.size(); i++) {
        int digit = digits[i] - '0';
        string letters = phone[digit];

        int size = q.size();

        for (int j = 0; j < size; j++) {
            string current = q.front();
            q.pop();

            for (int k = 0; k < letters.size(); k++) {
                q.push(current + letters[k]);
            }
        }
    }

    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Backtracking

    Basic idea:
    Use recursion and backtracking.
    At each index, choose one letter for current digit.
    Then move to next digit.

    Step-by-step algorithm:
    1. If digits is empty, return empty answer.
    2. Start recursion from index 0.
    3. If index becomes digits length,
       store current combination.
    4. Find digit at current index.
    5. Get mapped letters for this digit.
    6. Try every letter one by one.
    7. Add the letter to current combination.
    8. Recursively solve next index.
    9. Remove the letter while going back.

    Time complexity:
    O(totalCombinations * n)

    Space complexity:
    O(n)

    Note:
    This is the best common approach.
    We must generate all combinations.
    So output size is unavoidable.
    This approach is simple and clean.

------------------------------------------------------------*/
void combinations(int index, string& digits, string& current, vector<string>& ans) {
    if (index == digits.length()) {
        ans.push_back(current);
        return;
    }

    int digit = digits[index] - '0';
    string letters = phone[digit];

    for (int i = 0; i < letters.length(); i++) {
        current.push_back(letters[i]);

        combinations(index + 1, digits, current, ans);

        current.pop_back();
    }
}

vector<string> letterCombinationsOptimal(string digits) {
    vector<string> ans;

    if (digits.size() == 0) {
        return ans;
    }

    string current = "";

    combinations(0, digits, current, ans);

    return ans;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal backtracking solution.

------------------------------------------------------------*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return letterCombinationsOptimal(digits);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints all strings.

------------------------------------------------------------*/
void printAnswer(vector<string>& ans) {
    cout << "[";

    for (int i = 0; i < ans.size(); i++) {
        cout << "\"" << ans[i] << "\"";

        if (i != ans.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    string digits = "23";

    vector<string> ans1 = letterCombinationsBruteForce(digits);
    vector<string> ans2 = letterCombinationsBetterIterative(digits);
    vector<string> ans3 = letterCombinationsBetterQueue(digits);
    vector<string> ans4 = letterCombinationsOptimal(digits);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Iteration:" << endl;
    printAnswer(ans2);

    cout << "Better Solution using Queue:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution using Backtracking:" << endl;
    printAnswer(ans4);

    return 0;
}