#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
============================================================
        LECTURE: SUBARRAY SUM EQUALS K
============================================================

PROBLEM:
Given an integer array nums and an integer k,
return the total number of continuous subarrays
whose sum equals k.

NOTE:
- Subarray must be contiguous.
- Array may contain negative numbers.

============================================================
APPROACH 1: BRUTE FORCE (O(N^2))
============================================================

Idea:
Fix starting index i.
Extend subarray using j.
Keep adding elements and check if sum == k.

Time Complexity: O(N^2)
Space Complexity: O(1)

Works for negative numbers.
But too slow for large N.
*/

int subarraySum_Brute(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k)
                cnt++;
        }
    }

    return cnt;
}

/*
============================================================
APPROACH 2: PREFIX SUM + HASHMAP (O(N))
============================================================

KEY IDEA:
Instead of checking all subarrays,
use prefix sum concept.

Let:
preSum[i] = sum of elements from index 0 to i

If:
preSum[j] - preSum[i-1] = k

Then:
preSum[i-1] = preSum[j] - k

So for every preSum,
we check if (preSum - k) already exists.

Why mp[0] = 1 ?
Because if preSum == k,
then (preSum - k = 0).
So we assume prefix sum 0 appeared once.

Time Complexity: O(N)
Space Complexity: O(N)

Works for negative numbers.
*/

int subarraySum_PrefixMap(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> mp;  // prefixSum -> frequency
    mp[0] = 1;

    int preSum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        preSum += nums[i];

        int rem = preSum - k;

        if (mp.find(rem) != mp.end()) {
            cnt += mp[rem];
        }

        mp[preSum]++;
    }

    return cnt;
}

/*
============================================================
APPROACH 3: OPTIMIZED HASHMAP VERSION
============================================================

Instead of checking existence,
we directly use:

cnt += mp[rem];

Because:
unordered_map returns 0 if key doesn't exist.

Cleaner and shorter version.
*/

int subarraySum_Optimized(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> mp;
    mp[0] = 1;

    int preSum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        preSum += nums[i];

        int rem = preSum - k;
        cnt += mp[rem];   // automatically 0 if not present

        mp[preSum]++;
    }

    return cnt;
}

/*
============================================================
DRY RUN EXAMPLE
============================================================

nums = [1,1,1]
k = 2

Iteration:

i=0 → preSum=1 → rem=-1 → cnt=0
i=1 → preSum=2 → rem=0  → cnt=1
i=2 → preSum=3 → rem=1  → cnt=2

Answer = 2

Subarrays:
[1,1] (index 0-1)
[1,1] (index 1-2)

============================================================
WHY SLIDING WINDOW DOES NOT WORK?
============================================================

Because array may contain negative numbers.
Sliding window only works when array contains
only positive numbers.

============================================================
WHEN TO USE PREFIX SUM + HASHMAP?
============================================================

1. Count subarrays with sum = K
2. Longest subarray with sum = K
3. Subarray sum divisible by K
4. Equal number of 0s and 1s
5. Subarray XOR = K

This is one of the MOST IMPORTANT interview patterns.
============================================================
*/

int main() {

    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << "Brute Force Answer: "
         << subarraySum_Brute(nums, k) << endl;

    cout << "Prefix Map Answer: "
         << subarraySum_PrefixMap(nums, k) << endl;

    cout << "Optimized Map Answer: "
         << subarraySum_Optimized(nums, k) << endl;

    return 0;
}
