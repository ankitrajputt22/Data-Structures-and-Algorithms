#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
    LeetCode 3514: Number of Unique XOR Triplets II

    Problem:
    We are given an integer array nums.

    A XOR triplet is:
    nums[i] XOR nums[j] XOR nums[k]

    Condition:
    i <= j <= k

    We have to return the number of unique XOR triplet values.

    Important:
    The same index can be used more than once.
    So nums[i], nums[i], nums[i] is allowed.

    nums[i] is at most 1500.
    So XOR values stay in a small range.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Try every valid triplet.
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
    It checks all possible triplets.

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
    Then XOR each pair value with every number.

    Step-by-step algorithm:
    1. Create a set pairXor.
    2. Run two loops to find nums[i] XOR nums[j].
    3. Store all pair XOR values in pairXor.
    4. Create another set answer.
    5. For every value in pairXor:
       XOR it with every number in nums.
    6. Store the final XOR value in answer.
    7. Return size of answer.

    Time complexity:
    O(n^2 + p * n)

    Space complexity:
    O(p + ans)

    Note:
    p is the number of unique pair XOR values.
    This is better than brute force.
    But it still uses hash sets.

------------------------------------------------------------*/
int uniqueXorTripletsBetter(vector<int>& nums) {
    int n = nums.size();

    unordered_set<int> pairXor;
    unordered_set<int> answer;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int value = nums[i] ^ nums[j];
            pairXor.insert(value);
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

    Approach 3: Better Solution using Boolean Arrays

    Basic idea:
    XOR values are small.
    So use boolean arrays instead of hash sets.
    This makes marking faster.

    Step-by-step algorithm:
    1. Create a boolean array pairSeen.
    2. Mark every pair XOR value.
    3. Create a boolean array answerSeen.
    4. For every marked pair XOR value:
       XOR it with every number in nums.
    5. Mark the final XOR value.
    6. Count all true values in answerSeen.
    7. Return count.

    Time complexity:
    O(n^2 + range * n)

    Space complexity:
    O(range)

    Note:
    range is small because nums[i] <= 1500.
    This is faster than hash set approach.

------------------------------------------------------------*/
int uniqueXorTripletsBetterBoolean(vector<int>& nums) {
    int range = 2048;

    vector<bool> pairSeen(range, false);
    vector<bool> answerSeen(range, false);

    int n = nums.size();

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
                answerSeen[finalValue] = true;
            }
        }
    }

    int count = 0;

    for (int value = 0; value < range; value++) {
        if (answerSeen[value] == true) {
            count++;
        }
    }

    return count;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Unique Values and DP

    Basic idea:
    The same index can be used many times.
    So only unique numbers matter.

    We need XOR values after choosing exactly 3 numbers.
    We can use DP for this.

    dp[count][xorValue] means:
    Can we make xorValue by choosing count numbers?

    Step-by-step algorithm:
    1. Store all unique numbers.
    2. Create dp array of size 4 x range.
    3. Mark dp[0][0] as true.
    4. For count from 0 to 2:
       try adding every unique number.
    5. New XOR becomes oldXor XOR number.
    6. Mark dp[count + 1][newXor] as true.
    7. Count all true values in dp[3].
    8. Return count.

    Time complexity:
    O(3 * uniqueValues * range)

    Space complexity:
    O(4 * range)

    Note:
    This is the best approach.
    It avoids checking all pairs and triplets.
    It uses the small XOR range.

------------------------------------------------------------*/
int uniqueXorTripletsOptimalDP(vector<int>& nums) {
    int range = 2048;

    vector<bool> present(range, false);
    vector<int> uniqueValues;

    for (int i = 0; i < nums.size(); i++) {
        if (present[nums[i]] == false) {
            present[nums[i]] = true;
            uniqueValues.push_back(nums[i]);
        }
    }

    vector<vector<bool>> dp(4, vector<bool>(range, false));

    dp[0][0] = true;

    for (int count = 0; count < 3; count++) {
        for (int xorValue = 0; xorValue < range; xorValue++) {
            if (dp[count][xorValue] == true) {
                for (int i = 0; i < uniqueValues.size(); i++) {
                    int newXor = xorValue ^ uniqueValues[i];
                    dp[count + 1][newXor] = true;
                }
            }
        }
    }

    int answer = 0;

    for (int value = 0; value < range; value++) {
        if (dp[3][value] == true) {
            answer++;
        }
    }

    return answer;
}

/*------------------------------------------------------------

    Approach 5: Optimal Solution using Two Steps DP

    Basic idea:
    First find all XOR values using 2 selected numbers.
    Then use those values to find all XOR values
    using 3 selected numbers.

    Step-by-step algorithm:
    1. Store all unique numbers.
    2. Mark all possible XOR values of two numbers.
    3. For every pair XOR value:
       XOR it with every unique number.
    4. Mark the final XOR value.
    5. Count all marked final values.
    6. Return count.

    Time complexity:
    O(uniqueValues^2 + range * uniqueValues)

    Space complexity:
    O(range)

    Note:
    This is also optimal for this problem.
    It is close to the official idea.
    It uses only boolean arrays.

------------------------------------------------------------*/
int uniqueXorTripletsOptimalTwoSteps(vector<int>& nums) {
    int range = 2048;

    vector<bool> present(range, false);
    vector<int> uniqueValues;

    for (int i = 0; i < nums.size(); i++) {
        if (present[nums[i]] == false) {
            present[nums[i]] = true;
            uniqueValues.push_back(nums[i]);
        }
    }

    vector<bool> pairSeen(range, false);
    vector<bool> answerSeen(range, false);

    for (int i = 0; i < uniqueValues.size(); i++) {
        for (int j = 0; j < uniqueValues.size(); j++) {
            int value = uniqueValues[i] ^ uniqueValues[j];
            pairSeen[value] = true;
        }
    }

    for (int value = 0; value < range; value++) {
        if (pairSeen[value] == true) {
            for (int i = 0; i < uniqueValues.size(); i++) {
                int finalValue = value ^ uniqueValues[i];
                answerSeen[finalValue] = true;
            }
        }
    }

    int answer = 0;

    for (int value = 0; value < range; value++) {
        if (answerSeen[value] == true) {
            answer++;
        }
    }

    return answer;
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
    vector<int> nums = {6, 7, 8, 9};

    int ans1 = uniqueXorTripletsBruteForce(nums);
    int ans2 = uniqueXorTripletsBetter(nums);
    int ans3 = uniqueXorTripletsBetterBoolean(nums);
    int ans4 = uniqueXorTripletsOptimalDP(nums);
    int ans5 = uniqueXorTripletsOptimalTwoSteps(nums);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution using Pair XOR:" << endl;
    printAnswer(ans2);

    cout << "Better Solution using Boolean Array:" << endl;
    printAnswer(ans3);

    cout << "Optimal Solution using DP:" << endl;
    printAnswer(ans4);

    cout << "Optimal Solution using Two Steps:" << endl;
    printAnswer(ans5);

    return 0;
}