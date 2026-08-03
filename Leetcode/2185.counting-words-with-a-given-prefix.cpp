#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
    LeetCode 2185: Counting Words With a Given Prefix

    Problem:
    We are given an array of strings words.
    We are also given a string pref.

    We have to count how many words have pref as prefix.

    Prefix:
    A string pref is a prefix of a word
    if the word starts with pref.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Check every word.
    Use substr to get starting part of the word.
    Compare it with pref.

    Step-by-step algorithm:
    1. Create count as 0.
    2. Traverse every word.
    3. If word length is smaller than pref length, skip it.
    4. Take substring from index 0 of length pref.size().
    5. Compare substring with pref.
    6. If both are equal, increase count.
    7. Return count.

    Time complexity:
    O(n * p)

    Space complexity:
    O(p)

    Note:
    n is the number of words.
    p is the length of pref.
    This is simple.
    But substr creates an extra string.

------------------------------------------------------------*/
int prefixCountBruteForce(vector<string>& words, string pref) {
    int count = 0;
    int p = pref.size();

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];

        if (word.size() < p) {
            continue;
        }

        string start = word.substr(0, p);

        if (start == pref) {
            count++;
        }
    }

    return count;
}

/*------------------------------------------------------------

    Approach 2: Better Solution

    Basic idea:
    Check every word.
    Compare characters directly.
    Do not create substring.

    Step-by-step algorithm:
    1. Create count as 0.
    2. Traverse every word.
    3. If word length is smaller than pref length, skip it.
    4. Compare every character of pref with word.
    5. If all characters match, increase count.
    6. Return count.

    Time complexity:
    O(n * p)

    Space complexity:
    O(1)

    Note:
    This is better than brute force in space.
    It avoids creating extra substring.

------------------------------------------------------------*/
bool startsWithBetter(string word, string pref) {
    if (word.size() < pref.size()) {
        return false;
    }

    for (int i = 0; i < pref.size(); i++) {
        if (word[i] != pref[i]) {
            return false;
        }
    }

    return true;
}

int prefixCountBetter(vector<string>& words, string pref) {
    int count = 0;

    for (int i = 0; i < words.size(); i++) {
        if (startsWithBetter(words[i], pref)) {
            count++;
        }
    }

    return count;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Hash Map

    Basic idea:
    Store frequency of all prefixes of all words.
    Then answer for pref directly from map.

    Step-by-step algorithm:
    1. Create a hash map.
    2. Traverse every word.
    3. Create an empty string prefix.
    4. Add characters one by one to prefix.
    5. Increase frequency of this prefix in map.
    6. After all words are processed, return map[pref].

    Time complexity:
    O(total characters)

    Space complexity:
    O(total characters)

    Note:
    This is useful when many prefix queries are asked.
    For one query, better approach is also simple and good.
    This approach makes lookup very fast.

------------------------------------------------------------*/
int prefixCountOptimal(vector<string>& words, string pref) {
    unordered_map<string, int> mp;

    for (int i = 0; i < words.size(); i++) {
        string prefix = "";

        for (int j = 0; j < words[i].size(); j++) {
            prefix.push_back(words[i][j]);
            mp[prefix]++;
        }
    }

    return mp[pref];
}

/*------------------------------------------------------------

    Helper function:
    This function prints the answer.

------------------------------------------------------------*/
void printAnswer(int ans) {
    cout << ans << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    vector<string> words = {"pay", "attention", "practice", "attend"};
    string pref = "at";

    int ans1 = prefixCountBruteForce(words, pref);
    int ans2 = prefixCountBetter(words, pref);
    int ans3 = prefixCountOptimal(words, pref);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}