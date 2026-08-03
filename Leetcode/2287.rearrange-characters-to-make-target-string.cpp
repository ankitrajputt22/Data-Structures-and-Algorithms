#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
    LeetCode 2287: Rearrange Characters to Make Target String

    Problem:
    We are given two strings s and target.

    We have to find how many copies of target
    can be made using characters from s.

    Each character from s can be used only once.

    Example:
    s = "ilovecodingonleetcode"
    target = "code"

    We can make "code" 2 times.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Try to make target again and again.
    Mark used characters from s.
    Stop when target cannot be formed.

    Step-by-step algorithm:
    1. Create a used array for string s.
    2. Create count as 0.
    3. Try to form target.
    4. For each character of target,
       search the same unused character in s.
    5. If found, mark it as used.
    6. If any character is not found,
       stop the loop.
    7. If full target is formed, increase count.
    8. Return count.

    Time complexity:
    O(ans * targetLength * sLength)

    Space complexity:
    O(sLength)

    Note:
    ans is the number of copies formed.
    This solution is simple.
    But it can be slow for large input.
    It searches the string again and again.

------------------------------------------------------------*/
int rearrangeCharactersBruteForce(string s, string target) {
    vector<bool> used(s.size(), false);
    int count = 0;

    while (true) {
        vector<int> currentUsed;
        bool canMake = true;

        for (int i = 0; i < target.size(); i++) {
            bool found = false;

            for (int j = 0; j < s.size(); j++) {
                if (used[j] == false && s[j] == target[i]) {
                    used[j] = true;
                    currentUsed.push_back(j);
                    found = true;
                    break;
                }
            }

            if (found == false) {
                canMake = false;
                break;
            }
        }

        if (canMake == true) {
            count++;
        } else {
            for (int i = 0; i < currentUsed.size(); i++) {
                used[currentUsed[i]] = false;
            }

            break;
        }
    }

    return count;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Hash Map

    Basic idea:
    Count frequency of characters in s.
    Count frequency of characters in target.
    Compare how many times each target character can be used.

    Step-by-step algorithm:
    1. Create two hash maps.
    2. Store frequency of each character in s.
    3. Store frequency of each character in target.
    4. Create answer as a large number.
    5. For every character in target map:
       find freqS[ch] / freqTarget[ch].
    6. Take the minimum value.
    7. Return the answer.

    Time complexity:
    O(n + m)

    Space complexity:
    O(26)

    Note:
    n is the length of s.
    m is the length of target.
    This is better than brute force.
    It does not repeatedly search characters.

------------------------------------------------------------*/
int rearrangeCharactersBetter(string s, string target) {
    unordered_map<char, int> freqS;
    unordered_map<char, int> freqTarget;

    for (int i = 0; i < s.size(); i++) {
        freqS[s[i]]++;
    }

    for (int i = 0; i < target.size(); i++) {
        freqTarget[target[i]]++;
    }

    int ans = s.size();

    for (auto it : freqTarget) {
        char ch = it.first;
        int needed = it.second;

        ans = min(ans, freqS[ch] / needed);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Frequency Array

    Basic idea:
    Since strings contain lowercase English letters,
    use arrays of size 26 instead of hash maps.

    Step-by-step algorithm:
    1. Create freqS array of size 26.
    2. Create freqTarget array of size 26.
    3. Count characters of s in freqS.
    4. Count characters of target in freqTarget.
    5. Create answer as a large number.
    6. For every letter from a to z:
       if target needs this letter,
       calculate freqS[i] / freqTarget[i].
    7. Take minimum value.
    8. Return answer.

    Time complexity:
    O(n + m + 26)

    Space complexity:
    O(26)

    Note:
    This is the best approach.
    It is simple and fast.
    It checks each character only once.

------------------------------------------------------------*/
int rearrangeCharactersOptimal(string s, string target) {
    vector<int> freqS(26, 0);
    vector<int> freqTarget(26, 0);

    for (int i = 0; i < s.size(); i++) {
        freqS[s[i] - 'a']++;
    }

    for (int i = 0; i < target.size(); i++) {
        freqTarget[target[i] - 'a']++;
    }

    int ans = s.size();

    for (int i = 0; i < 26; i++) {
        if (freqTarget[i] > 0) {
            ans = min(ans, freqS[i] / freqTarget[i]);
        }
    }

    return ans;
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
    string s = "ilovecodingonleetcode";
    string target = "code";

    int ans1 = rearrangeCharactersBruteForce(s, target);
    int ans2 = rearrangeCharactersBetter(s, target);
    int ans3 = rearrangeCharactersOptimal(s, target);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}