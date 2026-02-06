#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
====================================================
LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
BRUTE FORCE APPROACH
====================================================

Approach:
- Fix a starting index i
- Expand substring using j
- Use a hash array to detect duplicates
- Update maximum length

Time Complexity: O(n^2)
Space Complexity: O(1)
====================================================
*/

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLen = INT_MIN;

    for (int i = 0; i < n; i++) {
        vector<int> hash(256, 0);

        for (int j = i; j < n; j++) {
            if (hash[s[j]] == 1)
                break;

            hash[s[j]] = 1;
            maxLen = max(maxLen, j - i + 1);
        }
    }

    return (maxLen == INT_MIN) ? 0 : maxLen;
}


/*
====================================================
LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
OPTIMAL SLIDING WINDOW APPROACH
====================================================

🔹 Problem:
Given a string s, find the length of the longest
substring without repeating characters.

----------------------------------------------------
🔹 Core Idea (Sliding Window)
----------------------------------------------------
We use two pointers:
- i → left boundary of window
- j → right boundary of window

We expand the window using j.
If a character repeats:
- Shrink the window from the left using i
- Until the substring becomes valid again

----------------------------------------------------
🔹 Data Structure Used
----------------------------------------------------
unordered_map<char, int> mp

- mp[c] stores frequency of character c
- Helps detect repetition in O(1) average time

----------------------------------------------------
🔹 Algorithm Steps
----------------------------------------------------
1) Initialize i = 0, j = 0
2) Move j forward and include s[j]
3) If s[j] appears more than once:
   - Move i forward
   - Decrease frequency of s[i]
4) Update max length
5) Repeat until j reaches end

----------------------------------------------------
🔹 Time Complexity
----------------------------------------------------
O(n)
Each character is visited at most twice (i and j)

----------------------------------------------------
🔹 Space Complexity
----------------------------------------------------
O(1)
At most 256 characters stored
====================================================
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int maxLen = 0;

        while (j < n) {

            // include current character
            mp[s[j]]++;

            // shrink window if duplicate found
            while (mp[s[j]] > 1) {
                mp[s[i]]--;
                i++;
            }

            // update maximum length
            maxLen = max(maxLen, j - i + 1);

            // expand window
            j++;
        }

        return maxLen;
    }
};

/*
====================================================
DRY RUN
====================================================

Input:
s = "abcabcbb"

Initial:
i = 0, j = 0, maxLen = 0

Step-by-step:

j=0 → 'a'
window = "a"
maxLen = 1

j=1 → 'b'
window = "ab"
maxLen = 2

j=2 → 'c'
window = "abc"
maxLen = 3

j=3 → 'a'
duplicate found
shrink from left:
remove 'a', i=1
window = "bca"
maxLen = 3

j=4 → 'b'
duplicate found
remove 'b', i=2
window = "cab"
maxLen = 3

j=5 → 'c'
duplicate found
remove 'c', i=3
window = "abc"
maxLen = 3

j=6 → 'b'
duplicate found
shrink window
window = "cb"
maxLen = 3

j=7 → 'b'
duplicate found
shrink window
window = "b"
maxLen = 3

Output:
3
====================================================
*/



/*
====================================================
LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
OPTIMIZED SLIDING WINDOW (LAST SEEN INDEX)
====================================================

🔹 Problem:
Find the length of the longest substring
without repeating characters.

----------------------------------------------------
🔹 Key Idea
----------------------------------------------------
Instead of storing frequency of characters,
we store the LAST INDEX where each character
was seen.

This allows us to jump the left pointer directly
to the correct position.

----------------------------------------------------
🔹 Data Structure Used
----------------------------------------------------
vector<int> hash(256, -1)

- Index represents ASCII character
- Value represents last index where character appeared
- -1 means character not seen yet

----------------------------------------------------
🔹 Two Pointer Technique
----------------------------------------------------
l → left boundary of window
r → right boundary of window

Window = s[l ... r]

----------------------------------------------------
🔹 Algorithm Steps
----------------------------------------------------
1) Initialize l = 0, r = 0
2) For each character s[r]:
   - If character was seen before AND
     its last index ≥ l:
       → move l to lastIndex + 1
3) Update max length
4) Update last index of s[r]
5) Move r forward

----------------------------------------------------
🔹 Time Complexity
----------------------------------------------------
O(n)
Each character processed once

----------------------------------------------------
🔹 Space Complexity
----------------------------------------------------
O(1)
(256 size array)
====================================================
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        vector<int> hash(256, -1);
        int l = 0, r = 0;
        int maxLen = 0;

        while (r < n) {

            // If character already seen and inside window
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            // Update maximum window length
            maxLen = max(maxLen, r - l + 1);

            // Update last seen index
            hash[s[r]] = r;

            // Expand window
            r++;
        }

        return maxLen;
    }
};

/*
====================================================
DRY RUN
====================================================

Input:
s = "abcabcbb"

Initial:
l = 0, r = 0, maxLen = 0

Step-by-step:

r=0 → 'a'
hash['a'] = -1
window = "a"
maxLen = 1

r=1 → 'b'
hash['b'] = -1
window = "ab"
maxLen = 2

r=2 → 'c'
hash['c'] = -1
window = "abc"
maxLen = 3

r=3 → 'a'
hash['a'] = 0 >= l
l = 0 + 1 = 1
window = "bca"
maxLen = 3

r=4 → 'b'
hash['b'] = 1 >= l
l = 1 + 1 = 2
window = "cab"
maxLen = 3

r=5 → 'c'
hash['c'] = 2 >= l
l = 2 + 1 = 3
window = "abc"
maxLen = 3

r=6 → 'b'
hash['b'] = 4 >= l
l = 4 + 1 = 5
window = "cb"
maxLen = 3

r=7 → 'b'
hash['b'] = 6 >= l
l = 6 + 1 = 7
window = "b"
maxLen = 3

Output:
3
====================================================
*/

int main() {
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
