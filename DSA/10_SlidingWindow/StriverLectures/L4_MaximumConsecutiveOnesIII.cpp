#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
============================================================
        LECTURE: MAX CONSECUTIVE ONES III
============================================================

PROBLEM:
You are given:
- A binary array nums (contains only 0s and 1s)
- An integer k

You can flip at most k zeros to 1.

Goal:
Return the maximum number of consecutive 1s possible.

------------------------------------------------------------
Equivalent Interpretation:
Find the longest subarray containing AT MOST k zeros.
------------------------------------------------------------

============================================================
1. BRUTE FORCE APPROACH
============================================================

Idea:
Generate all subarrays.
Count zeros in each.
Stop extending if zero count exceeds k.

Time Complexity: O(N^2)
Space Complexity: O(1)

Not efficient for large N.
*/

int longestOnes_Brute(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        int zeros = 0;
        for (int j = i; j < n; j++) {
            if (nums[j] == 0) zeros++;

            if (zeros > k) break;

            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}

/*
============================================================
2. BETTER APPROACH: SLIDING WINDOW (Two Pointers)
============================================================

Idea:
Maintain a window [l, r] that always has at most k zeros.

Steps:
1. Expand r.
2. Count zeros.
3. If zeros > k → shrink from left using while loop.
4. Track max window size.

Why O(2N)?
Each element is visited at most twice:
- Once by r
- Once by l

Time Complexity: O(N)
Space Complexity: O(1)
*/

int longestOnes_Better(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = 0;
    int zeros = 0;
    int maxLen = 0;

    while (r < n) {

        if (nums[r] == 0)
            zeros++;

        while (zeros > k) {
            if (nums[l] == 0)
                zeros--;
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

Observation:
We only care about maximum window length.
We do NOT need to fully shrink window each time.

Optimization:
Replace "while" with "if".

When zeros > k:
Just move left pointer once.
This keeps window sliding at max size.

Why does this work?
Because shrinking more than once is unnecessary
if we only track maximum length.

Time Complexity: STRICT O(N)
Space Complexity: O(1)
*/

int longestOnes_Optimal(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = 0;
    int zeros = 0;
    int maxLen = 0;

    while (r < n) {
        if (nums[r] == 0)
            zeros++;

        if (zeros > k) {
            if (nums[l] == 0)
                zeros--;
            l++;
        }

        if (zeros <= k)
            maxLen = max(maxLen, r - l + 1);

        r++;
    }

    return maxLen;
}

/*
============================================================
DRY RUN EXAMPLE
============================================================

nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2

Process:
Window expands until zeros exceed 2.
Then shrink from left.
Maximum window found = 6

Output = 6

============================================================
WHY SLIDING WINDOW WORKS?
============================================================

Because:
- Array is binary.
- We are maintaining "at most k zeros".
- Window validity can be adjusted dynamically.

============================================================
PATTERN RECOGNITION
============================================================

This is Pattern 2:
Longest Subarray with a Condition.

Template:

int l = 0;
for (int r = 0; r < n; r++) {
    update condition
    while (condition invalid)
        l++;
    update answer
}

============================================================
INTERVIEW INSIGHT
============================================================

If question says:
- Longest subarray with at most K something
→ Sliding window

If question says:
- Count subarrays
→ Usually prefix sum or advanced sliding window

============================================================
*/

int main() {

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << "Brute Force: "
         << longestOnes_Brute(nums, k) << endl;

    cout << "Better Sliding Window: "
         << longestOnes_Better(nums, k) << endl;

    cout << "Optimal Sliding Window: "
         << longestOnes_Optimal(nums, k) << endl;

    return 0;
}
