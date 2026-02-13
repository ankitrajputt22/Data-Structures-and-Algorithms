#include <iostream>
#include <bits/stdc++.h>
#include <set>

using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();

        int maxF = 0;
        for (int i = 0; i < n; i++) {
            int cntF = 0;
            unordered_map<int, int> mp;

            for (int j = i; j < n; j++) {
                mp[nums[j]]++;

                if (mp.size() > 2) {
                    break;
                }

                cntF++;
            }   

            maxF = max(cntF, maxF);
        }

        return maxF;
    }
};


#include <bits/stdc++.h>
using namespace std;

/*
============================================================
        LECTURE: FRUIT INTO BASKETS
============================================================

PROBLEM:
You are given an array where each element represents
a type of fruit.

You have:
- 2 baskets
- Each basket can hold only ONE type of fruit
- You must collect fruits consecutively

Goal:
Return the maximum number of fruits you can collect.

------------------------------------------------------------
Simplified Problem:
Find the longest subarray containing
AT MOST 2 DISTINCT numbers.
------------------------------------------------------------

============================================================
1. BRUTE FORCE APPROACH
============================================================

Idea:
Generate all subarrays.
Use a set to track distinct fruit types.
Stop when distinct types > 2.

Time Complexity: O(N^2)
Space Complexity: O(3) ≈ O(1)

Not optimal for large input.
*/

int totalFruit_Brute(vector<int>& fruits) {
    int n = fruits.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        set<int> st;

        for (int j = i; j < n; j++) {
            st.insert(fruits[j]);

            if (st.size() > 2)
                break;

            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}

/*
============================================================
2. BETTER APPROACH: SLIDING WINDOW
============================================================

Maintain window [l, r]
Use frequency map to track fruit counts.

Steps:
1. Expand r → add fruit to map.
2. If map.size() > 2 → shrink from left using while loop.
3. Update maxLen whenever window valid.

Time Complexity: O(2N) ≈ O(N)
Space Complexity: O(3) ≈ O(1)
*/

int totalFruit_Better(vector<int>& fruits) {
    int n = fruits.size();
    int l = 0, r = 0;
    int maxLen = 0;
    unordered_map<int,int> mp;

    while (r < n) {

        mp[fruits[r]]++;

        while (mp.size() > 2) {
            mp[fruits[l]]--;
            if (mp[fruits[l]] == 0)
                mp.erase(fruits[l]);
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
}

/*
============================================================
3. OPTIMAL APPROACH
============================================================

Optimization:
Replace while with if.

Why?
Because we only care about maximum length.
No need to shrink fully.
Just shift window forward.

Time Complexity: STRICT O(N)
Space Complexity: O(1)
*/

int totalFruit_Optimal(vector<int>& fruits) {
    int n = fruits.size();
    int l = 0, r = 0;
    int maxLen = 0;
    unordered_map<int,int> mp;

    while (r < n) {

        mp[fruits[r]]++;

        if (mp.size() > 2) {
            mp[fruits[l]]--;
            if (mp[fruits[l]] == 0)
                mp.erase(fruits[l]);
            l++;
        }

        if (mp.size() <= 2)
            maxLen = max(maxLen, r - l + 1);

        r++;
    }

    return maxLen;
}

/*
============================================================
DRY RUN EXAMPLE
============================================================

fruits = [1,2,1,2,3,2,2]

Window expansion:

1 → {1}
1,2 → {1,2}
1,2,1 → {1,2}
1,2,1,2 → {1,2}
1,2,1,2,3 → {1,2,3} ❌ >2
Shrink from left

Max window found = 4

Answer = 4

============================================================
PATTERN IDENTIFICATION
============================================================

This belongs to:

Pattern 2:
Longest Subarray with a Condition

Condition:
Number of distinct elements <= 2

Template:

int l = 0;
for (int r = 0; r < n; r++) {
    add element
    while (condition invalid)
        remove from left
    update answer
}

============================================================
WHEN TO USE WHILE vs IF?
============================================================

• If question is LONGEST length → IF optimization works
• If question asks COUNT of subarrays → MUST use WHILE

============================================================
COMPLEXITY SUMMARY
============================================================

Brute      → O(N^2)
Better     → O(N)
Optimal    → O(N)

Space      → O(1)

============================================================
INTERVIEW INSIGHT
============================================================

If you see:
- "At most K distinct"
- "At most K zeros"
- "At most K replacements"

Think:
SLIDING WINDOW + HASH MAP

============================================================
*/

int main() {

    vector<int> fruits = {1,2,1,2,3,2,2};

    cout << "Brute Force: "
         << totalFruit_Brute(fruits) << endl;

    cout << "Better Sliding Window: "
         << totalFruit_Better(fruits) << endl;

    cout << "Optimal Sliding Window: "
         << totalFruit_Optimal(fruits) << endl;

    return 0;
}
