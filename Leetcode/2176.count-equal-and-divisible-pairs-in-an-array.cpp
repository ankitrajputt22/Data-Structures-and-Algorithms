#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode 2176: Count Equal and Divisible Pairs in an Array

    Problem:
    We are given an integer array nums.
    We are also given an integer k.

    We have to count pairs (i, j) such that:
    1. i < j
    2. nums[i] == nums[j]
    3. (i * j) is divisible by k
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Check every possible pair.
    If both conditions are true, increase count.

    Step-by-step algorithm:
    1. Create count as 0.
    2. Run a loop for i from 0 to n - 1.
    3. Run another loop for j from i + 1 to n - 1.
    4. Check if nums[i] is equal to nums[j].
    5. Check if i * j is divisible by k.
    6. If both are true, increase count.
    7. Return count.

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

    Note:
    This solution is simple.
    It checks all possible pairs.

------------------------------------------------------------*/
int countPairsBruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j] && (i * j) % k == 0) {
                count++;
            }
        }
    }

    return count;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Grouping

    Basic idea:
    Store indices of the same values together.
    Then only check pairs with equal values.

    Step-by-step algorithm:
    1. Create a hash map.
    2. Store all indices for every value.
    3. Traverse each group of indices.
    4. Check pairs only inside the same group.
    5. If index product is divisible by k, increase count.
    6. Return count.

    Time complexity:
    O(n + samePairs)

    Space complexity:
    O(n)

    Note:
    samePairs means pairs having same value.
    This avoids checking pairs with different values.
    It is better when many values are different.

------------------------------------------------------------*/
int countPairsBetter(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> mp;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    for (auto it : mp) {
        vector<int> indices = it.second;

        for (int i = 0; i < indices.size(); i++) {
            for (int j = i + 1; j < indices.size(); j++) {
                int firstIndex = indices[i];
                int secondIndex = indices[j];

                if ((firstIndex * secondIndex) % k == 0) {
                    count++;
                }
            }
        }
    }

    return count;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using GCD and Hash Map

    Basic idea:
    Process indices from left to right.
    For current index j, find what type of previous index i
    can make i * j divisible by k.

    Important formula:
    Let g = gcd(j, k).
    Then i * j is divisible by k if
    i is divisible by k / g.

    Step-by-step algorithm:
    1. Create a hash map countDivisible.
    2. countDivisible[value][d] stores:
       number of previous indices with this value
       which are divisible by d.
    3. Traverse index j from left to right.
    4. Find g = gcd(j, k).
    5. Find need = k / g.
    6. Add countDivisible[nums[j]][need] to answer.
    7. Now add current index j into the map.
    8. For every d from 1 to k:
       if j is divisible by d, increase countDivisible[nums[j]][d].
    9. Return answer.

    Time complexity:
    O(n * k)

    Space complexity:
    O(uniqueValues * k)

    Note:
    This is useful because it counts valid previous indices directly.
    It does not check every pair.

------------------------------------------------------------*/
int countPairsOptimal(vector<int>& nums, int k) {
    unordered_map<int, unordered_map<int, int>> countDivisible;
    int count = 0;

    for (int j = 0; j < nums.size(); j++) {
        int g = gcd(j, k);
        int need = k / g;

        count = count + countDivisible[nums[j]][need];

        for (int d = 1; d <= k; d++) {
            if (j % d == 0) {
                countDivisible[nums[j]][d]++;
            }
        }
    }

    return count;
}



/*------------------------------------------------------------

    Approach 3: Optimized Solution using GCD and Divisors

    Basic idea:
    Store indices of the same values together.
    Then count valid pairs inside each group.

    For a pair (i, j):
    nums[i] == nums[j]
    and
    (i * j) % k == 0

    Suppose current index is i.
    We need to find previous index j such that:
    (i * j) is divisible by k.

    We use gcd(i, k) to find the required factor.

    Step-by-step algorithm:
    1. Create a hash map.
    2. Store all indices for every value.
    3. Find all divisors of k.
    4. Traverse each group of same values.
    5. For every index i in that group:
       a. Find gcd(i, k).
       b. Find required factor as k / gcd(i, k).
       c. Add count of previous indices divisible by required factor.
       d. Update factor count for current index.
    6. Return answer.

    Time complexity:
    O(n * (log k + sqrt(k)))

    Space complexity:
    O(n)

    Note:
    gcd(i, k) tells how much part of k is already covered by i.
    The remaining part must be covered by the previous index.

    This is better than checking every pair inside the same group.

------------------------------------------------------------*/
int countPairsOptimized(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> mp;
    int count = 0;

    /*
        Store indices of same values together.
    */
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    /*
        Store all divisors of k.

        Example:
        k = 36

        Divisors are:
        1, 2, 3, 4, 6, 9, 12, 18, 36
    */
    unordered_set<int> divisors;

    for (int f = 1; f * f <= k; f++) {
        if (k % f == 0) {
            divisors.insert(f);
            divisors.insert(k / f);
        }
    }

    /*
        Process every group separately.
        We only need pairs with same values.
    */
    for (auto& it : mp) {
        vector<int>& indices = it.second;

        /*
            factorCount[f] stores how many previous indices
            are divisible by f.
        */
        unordered_map<int, int> factorCount;

        for (int i : indices) {
            /*
                gcd(i, k) gives the part of k covered by i.

                The remaining part is:
                k / gcd(i, k)

                Previous index must be divisible by this remaining part.
            */
            int common = gcd(i, k);
            int requiredFactor = k / common;

            count += factorCount[requiredFactor];

            /*
                Now add current index for future pairs.

                If current index is divisible by divisor f,
                then it can help future indices needing factor f.
            */
            for (int f : divisors) {
                if (i % f == 0) {
                    factorCount[f]++;
                }
            }
        }
    }

    return count;
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
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;

    int ans1 = countPairsBruteForce(nums, k);
    int ans2 = countPairsBetter(nums, k);
    int ans3 = countPairsOptimal(nums, k);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}