#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

/*
    LeetCode 3513: Number of Unique XOR Triplets I

    Problem:
    We are given an integer array nums of length n.
    nums is a permutation of numbers from 1 to n.

    A XOR triplet is:
    nums[i] XOR nums[j] XOR nums[k]

    Conditions:
    i <= j <= k

    We have to return the number of unique XOR triplet values.

    Important:
    Since XOR does not depend on order,
    any three selected indices can be sorted.
    So we only need unique XOR values.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Try all valid triplets.
    Store every XOR value in a set.
    Return the size of the set.

    Step-by-step algorithm:
    1. Create a set to store unique XOR values.
    2. Run a loop for i from 0 to n - 1.
    3. Run a loop for j from i to n - 1.
    4. Run a loop for k from j to n - 1.
    5. Calculate nums[i] XOR nums[j] XOR nums[k].
    6. Insert this value into the set.
    7. Return size of the set.

    Time complexity:
    O(n^3 * log n)

    Space complexity:
    O(n)

    Note:
    This solution can give TLE for large input.
    It checks every possible triplet.

------------------------------------------------------------*/
int uniqueXorTripletsBruteForce(vector<int>& nums) {
    int n = nums.size();

    set<int> uniqueValues;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                int value = nums[i] ^ nums[j] ^ nums[k];
                uniqueValues.insert(value);
            }
        }
    }

    return uniqueValues.size();
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Pair XOR

    Basic idea:
    First store XOR of every pair.
    Then combine every pair XOR with every third number.

    Step-by-step algorithm:
    1. Create a set pairXor.
    2. Store nums[i] XOR nums[j] for all pairs.
    3. Create another set answer.
    4. For every pair XOR value:
       XOR it with every number in nums.
    5. Store the final XOR value in answer set.
    6. Return size of answer set.

    Time complexity:
    O(n^2 + p * n)

    Space complexity:
    O(p + ans)

    Note:
    p is the number of unique pair XOR values.
    This is better than brute force.
    But it can still be slow for large input.

------------------------------------------------------------*/
int uniqueXorTripletsBetter(vector<int>& nums) {
    int n = nums.size();

    unordered_set<int> pairXor;
    unordered_set<int> answer;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            pairXor.insert(nums[i] ^ nums[j]);
        }
    }

    for (auto value : pairXor) {
        for (int i = 0; i < n; i++) {
            int finalValue = value ^ nums[i];
            answer.insert(finalValue);
        }
    }

    return answer.size();
}

/*------------------------------------------------------------

    Approach 3: Better Solution using Boolean Array

    Basic idea:
    XOR values are limited.
    Instead of set, use boolean arrays.
    This makes insertion faster.

    Step-by-step algorithm:
    1. Find a power of 2 greater than n.
    2. XOR values will stay below this range.
    3. Create pairSeen array.
    4. Store every pair XOR in pairSeen.
    5. Create ansSeen array.
    6. Combine pair XOR values with every nums[i].
    7. Mark final XOR values in ansSeen.
    8. Count true values in ansSeen.
    9. Return count.

    Time complexity:
    O(n^2 + range * n)

    Space complexity:
    O(range)

    Note:
    This avoids hash set overhead.
    But it can still be slow when n is large.

------------------------------------------------------------*/
int uniqueXorTripletsBetterBoolean(vector<int>& nums) {
    int n = nums.size();

    int range = 1;

    while (range <= n) {
        range = range * 2;
    }

    vector<bool> pairSeen(range, false);
    vector<bool> ansSeen(range, false);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int value = nums[i] ^ nums[j];
            pairSeen[value] = true;
        }
    }

    for (int value = 0; value < range; value++) {
        if (pairSeen[value] == true) {
            for (int i = 0; i < n; i++) {
                int finalValue = value ^ nums[i];
                ansSeen[finalValue] = true;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < range; i++) {
        if (ansSeen[i] == true) {
            count++;
        }
    }

    return count;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Math and Bit

    Basic idea:
    nums is always a permutation from 1 to n.
    So the actual order of nums does not matter.

    For n = 1:
    Only value 1 is possible.
    Answer is 1.

    For n = 2:
    Unique values are 1 and 2.
    Answer is 2.

    For n >= 3:
    All XOR values from 0 to power - 1 are possible.
    Here power is the smallest power of 2 greater than n.

    Step-by-step algorithm:
    1. Find n as nums.size().
    2. If n is 1 or 2, return n.
    3. Create answer as 1.
    4. Keep multiplying answer by 2 until answer > n.
    5. Return answer.

    Time complexity:
    O(log n)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It does not need to check triplets.
    It uses the special property that nums is a permutation.

------------------------------------------------------------*/
int uniqueXorTripletsOptimal(vector<int>& nums) {
    int n = nums.size();

    if (n <= 2) {
        return n;
    }

    int answer = 1;

    while (answer <= n) {
        answer = answer * 2;
    }

    return answer;
}

/*------------------------------------------------------------

    Approach 5: Optimal Solution using Bit Length

    Basic idea:
    For n >= 3, answer is:
    2 raised to number of bits in n.

    Example:
    n = 3
    Binary of 3 is 11.
    Number of bits is 2.
    Answer is 2^2 = 4.

    Step-by-step algorithm:
    1. Find n as nums.size().
    2. If n is 1 or 2, return n.
    3. Count number of bits in n.
    4. Return 1 shifted left by bit count.

    Time complexity:
    O(log n)

    Space complexity:
    O(1)

    Note:
    This is also an optimal approach.
    It is just another way to find next power of 2.

------------------------------------------------------------*/
int uniqueXorTripletsOptimalBitLength(vector<int>& nums) {
    int n = nums.size();

    if (n <= 2) {
        return n;
    }

    int bitCount = 0;
    int temp = n;

    while (temp > 0) {
        bitCount++;
        temp = temp / 2;
    }

    return 1 << bitCount;
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
    vector<int> nums = {3, 1, 2};

    int ans1 = uniqueXorTripletsBruteForce(nums);
    int ans2 = uniqueXorTripletsBetter(nums);
    int ans3 = uniqueXorTripletsBetterBoolean(nums);
    int ans4 = uniqueXorTripletsOptimal(nums);
    int ans5 = uniqueXorTripletsOptimalBitLength(nums);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Pair XOR:" << endl;
    printAnswer(ans2);

    cout << "Better Solution using Boolean Array:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution using Math and Bit:" << endl;
    printAnswer(ans4);

    cout << "Optimal Solution using Bit Length:" << endl;
    printAnswer(ans5);

    return 0;
}