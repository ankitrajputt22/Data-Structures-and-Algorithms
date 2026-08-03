#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    LeetCode 14: Longest Common Prefix

    Problem:
    We are given an array of strings strs.
    We have to find the longest common prefix string
    among all strings.

    Prefix:
    A prefix is a starting part of a string.

    Example:
    strs = ["flower", "flow", "flight"]

    Common prefix:
    "fl"

    Answer:
    "fl"

    If there is no common prefix, return empty string.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Take the first string as prefix.
    Keep reducing it until it becomes prefix of all strings.

    Step-by-step algorithm:
    1. If array is empty, return empty string.
    2. Take first string as prefix.
    3. Check if prefix is present at start of every string.
    4. If yes, return prefix.
    5. If no, remove last character from prefix.
    6. Repeat until prefix becomes empty.
    7. Return empty string.

    Time complexity:
    O(n * m * m)

    Space complexity:
    O(m)

    Note:
    n is the number of strings.
    m is the length of the first string.
    This solution is simple.
    But it can be slow because substr is used again and again.

------------------------------------------------------------*/
bool isPrefix(string word, string prefix) {
    if (prefix.size() > word.size()) {
        return false;
    }

    for (int i = 0; i < prefix.size(); i++) {
        if (word[i] != prefix[i]) {
            return false;
        }
    }

    return true;
}

string longestCommonPrefixBruteForce(vector<string>& strs) {
    if (strs.size() == 0) {
        return "";
    }

    string prefix = strs[0];

    while (prefix.size() > 0) {
        bool valid = true;

        for (int i = 0; i < strs.size(); i++) {
            if (isPrefix(strs[i], prefix) == false) {
                valid = false;
                break;
            }
        }

        if (valid == true) {
            return prefix;
        }

        prefix.pop_back();
    }

    return "";
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Sorting

    Basic idea:
    Sort the array.
    After sorting, only first and last strings matter.
    The common prefix of first and last string
    will be common for all strings.

    Step-by-step algorithm:
    1. If array is empty, return empty string.
    2. Sort the array.
    3. Take first string.
    4. Take last string.
    5. Compare both strings character by character.
    6. Add same characters to answer.
    7. Stop when characters are different.
    8. Return answer.

    Time complexity:
    O(n log n * m)

    Space complexity:
    O(1)

    Note:
    This is better and easy to understand.
    Sorting brings similar strings together.
    But sorting is not actually needed for best solution.

------------------------------------------------------------*/
string longestCommonPrefixBetterSorting(vector<string> strs) {
    if (strs.size() == 0) {
        return "";
    }

    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[strs.size() - 1];

    string ans = "";

    int len = min(first.size(), last.size());

    for (int i = 0; i < len; i++) {
        if (first[i] == last[i]) {
            ans.push_back(first[i]);
        } else {
            break;
        }
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Vertical Scanning

    Basic idea:
    Check characters column by column.
    Compare each character of first string
    with the same position in all other strings.

    Step-by-step algorithm:
    1. If array is empty, return empty string.
    2. Traverse characters of first string.
    3. For every character position i,
       compare it with all other strings.
    4. If any string ends, return answer so far.
    5. If any character is different, return answer so far.
    6. Otherwise add current character to answer.
    7. Return answer.

    Time complexity:
    O(total characters checked)

    Space complexity:
    O(1)

    Note:
    This is the best simple approach.
    It does not sort the array.
    It stops as soon as mismatch is found.

------------------------------------------------------------*/
string longestCommonPrefixOptimal(vector<string>& strs) {
    if (strs.size() == 0) {
        return "";
    }

    string ans = "";

    for (int i = 0; i < strs[0].size(); i++) {
        char ch = strs[0][i];

        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].size() || strs[j][i] != ch) {
                return ans;
            }
        }

        ans.push_back(ch);
    }

    return ans;
}

/*------------------------------------------------------------

    Helper function:
    This function finds common prefix of two strings.

------------------------------------------------------------*/
string commonPrefixTwoStrings(string s1, string s2) {
    string ans = "";

    int len = min(s1.size(), s2.size());

    for (int i = 0; i < len; i++) {
        if (s1[i] == s2[i]) {
            ans.push_back(s1[i]);
        } else {
            break;
        }
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Divide and Conquer

    Basic idea:
    Divide the array into two parts.
    Find common prefix of left part.
    Find common prefix of right part.
    Then find common prefix of both answers.

    Step-by-step algorithm:
    1. If array is empty, return empty string.
    2. Divide the array into two halves.
    3. Recursively solve left half.
    4. Recursively solve right half.
    5. Find common prefix of both results.
    6. Return final prefix.

    Time complexity:
    O(total characters checked)

    Space complexity:
    O(log n)

    Note:
    This is also an optimal approach.
    It uses recursion.
    Vertical scanning is easier for direct submission.

------------------------------------------------------------*/
string solveDivideAndConquer(vector<string>& strs, int left, int right) {
    if (left == right) {
        return strs[left];
    }

    int mid = left + (right - left) / 2;

    string leftPrefix = solveDivideAndConquer(strs, left, mid);
    string rightPrefix = solveDivideAndConquer(strs, mid + 1, right);

    return commonPrefixTwoStrings(leftPrefix, rightPrefix);
}

string longestCommonPrefixDivideAndConquer(vector<string>& strs) {
    if (strs.size() == 0) {
        return "";
    }

    return solveDivideAndConquer(strs, 0, strs.size() - 1);
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal solution.

------------------------------------------------------------*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefixOptimal(strs);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints the answer.

------------------------------------------------------------*/
void printAnswer(string ans) {
    cout << "\"" << ans << "\"" << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    string ans1 = longestCommonPrefixBruteForce(strs);
    string ans2 = longestCommonPrefixBetterSorting(strs);
    string ans3 = longestCommonPrefixOptimal(strs);
    string ans4 = longestCommonPrefixDivideAndConquer(strs);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Sorting:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution using Vertical Scanning:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution using Divide and Conquer:" << endl;
    printAnswer(ans4);

    return 0;
}