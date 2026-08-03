#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 1189: Maximum Number of Balloons

    Problem:
    We are given a string text.
    We have to find how many times we can form the word "balloon".

    Word:
    balloon

    Required letters:
    b -> 1 time
    a -> 1 time
    l -> 2 times
    o -> 2 times
    n -> 1 time
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Try to form the word "balloon" again and again.
    For every word formation, remove used characters.

    Step-by-step algorithm:
    1. Create a used array to mark used characters.
    2. Create count as 0.
    3. Try to form the word "balloon".
    4. For every character of "balloon",
       search it in text.
    5. If found, mark that character as used.
    6. If any character is not found,
       stop the process.
    7. If full word is formed, increase count.
    8. Return count.

    Time complexity:
    O(ans * 7 * n)

    Space complexity:
    O(n)

    Note:
    n is the length of text.
    ans is number of times balloon can be formed.
    This solution is simple.
    But it can be slow because it searches again and again.

------------------------------------------------------------*/
int maxNumberOfBalloonsBruteForce(string text) {
    string word = "balloon";
    vector<bool> used(text.size(), false);

    int count = 0;

    while (true) {
        vector<int> currentUsed;
        bool canMake = true;

        for (int i = 0; i < word.size(); i++) {
            bool found = false;

            for (int j = 0; j < text.size(); j++) {
                if (used[j] == false && text[j] == word[i]) {
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

    Approach 2: Better Solution using Frequency Array

    Basic idea:
    Count frequency of all characters.
    Then check how many times each required character
    can be used to make "balloon".

    Step-by-step algorithm:
    1. Create a frequency array of size 26.
    2. Count all characters in text.
    3. Find count of b.
    4. Find count of a.
    5. Find count of l divided by 2.
    6. Find count of o divided by 2.
    7. Find count of n.
    8. Return the minimum of these values.

    Time complexity:
    O(n)

    Space complexity:
    O(26)

    Note:
    This is better than brute force.
    It counts every character only once.

------------------------------------------------------------*/
int maxNumberOfBalloonsBetter(string text) {
    vector<int> freq(26, 0);

    for (int i = 0; i < text.size(); i++) {
        freq[text[i] - 'a']++;
    }

    int b = freq['b' - 'a'];
    int a = freq['a' - 'a'];
    int l = freq['l' - 'a'] / 2;
    int o = freq['o' - 'a'] / 2;
    int n = freq['n' - 'a'];

    return min({b, a, l, o, n});
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution

    Basic idea:
    We do not need to count all letters.
    Count only the letters needed for "balloon".

    Step-by-step algorithm:
    1. Create counters for b, a, l, o, n.
    2. Traverse the text.
    3. If character is b, increase b.
    4. If character is a, increase a.
    5. If character is l, increase l.
    6. If character is o, increase o.
    7. If character is n, increase n.
    8. Divide l and o by 2.
    9. Return minimum of all required counts.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It uses only fixed variables.
    Every character is checked once.

------------------------------------------------------------*/
int maxNumberOfBalloonsOptimal(string text) {
    int b = 0;
    int a = 0;
    int l = 0;
    int o = 0;
    int n = 0;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == 'b') {
            b++;
        } else if (text[i] == 'a') {
            a++;
        } else if (text[i] == 'l') {
            l++;
        } else if (text[i] == 'o') {
            o++;
        } else if (text[i] == 'n') {
            n++;
        }
    }

    l = l / 2;
    o = o / 2;

    return min({b, a, l, o, n});
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
    string text = "nlaebolko";

    int ans1 = maxNumberOfBalloonsBruteForce(text);
    int ans2 = maxNumberOfBalloonsBetter(text);
    int ans3 = maxNumberOfBalloonsOptimal(text);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}