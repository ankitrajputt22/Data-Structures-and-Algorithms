#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    LeetCode 1399: Count Largest Group

    Problem:
    We are given an integer n.

    We have to group all numbers from 1 to n.
    Numbers are grouped by the sum of their digits.

    Example:
    13

    1  -> digit sum 1
    2  -> digit sum 2
    3  -> digit sum 3
    ...
    10 -> digit sum 1
    11 -> digit sum 2
    12 -> digit sum 3
    13 -> digit sum 4

    We have to return the number of groups
    which have the largest size.
*/

/*------------------------------------------------------------

    Helper function:
    This function finds digit sum using string.

------------------------------------------------------------*/
int getDigitSumString(int num) {
    string s = to_string(num);
    int sum = 0;

    for (int i = 0; i < s.size(); i++) {
        sum = sum + (s[i] - '0');
    }

    return sum;
}

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Store all numbers in groups.
    The group number is the digit sum.

    Step-by-step algorithm:
    1. Create groups array.
    2. Traverse numbers from 1 to n.
    3. Find digit sum of current number.
    4. Put the number in that digit sum group.
    5. Find the largest group size.
    6. Count how many groups have that size.
    7. Return the count.

    Time complexity:
    O(n * d)

    Space complexity:
    O(n)

    Note:
    d is the number of digits in n.
    This solution is simple.
    But it stores all numbers in groups.

------------------------------------------------------------*/
int countLargestGroupBruteForce(int n) {
    vector<vector<int>> groups(100);

    for (int num = 1; num <= n; num++) {
        int digitSum = getDigitSumString(num);
        groups[digitSum].push_back(num);
    }

    int maxSize = 0;

    for (int i = 0; i < groups.size(); i++) {
        int size = groups[i].size();
        maxSize = max(maxSize, size);
    }

    int count = 0;

    for (int i = 0; i < groups.size(); i++) {
        if (groups[i].size() == maxSize) {
            count++;
        }
    }

    return count;
}

/*------------------------------------------------------------

    Helper function:
    This function finds digit sum using math.

------------------------------------------------------------*/
int getDigitSumMath(int num) {
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }

    return sum;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Hash Map

    Basic idea:
    We do not need to store numbers.
    We only need size of each group.

    Step-by-step algorithm:
    1. Create a hash map.
    2. Traverse numbers from 1 to n.
    3. Find digit sum of current number.
    4. Increase count of that digit sum in map.
    5. Find the maximum group size.
    6. Count how many groups have maximum size.
    7. Return the count.

    Time complexity:
    O(n * d)

    Space complexity:
    O(digitSumRange)

    Note:
    This is better than brute force.
    It stores only group sizes.
    It does not store all numbers.

------------------------------------------------------------*/
int countLargestGroupBetter(int n) {
    unordered_map<int, int> mp;

    for (int num = 1; num <= n; num++) {
        int digitSum = getDigitSumMath(num);
        mp[digitSum]++;
    }

    int maxSize = 0;

    for (auto it : mp) {
        maxSize = max(maxSize, it.second);
    }

    int count = 0;

    for (auto it : mp) {
        if (it.second == maxSize) {
            count++;
        }
    }

    return count;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Frequency Array

    Basic idea:
    Digit sum range is small.
    So use an array instead of hash map.

    Step-by-step algorithm:
    1. Create frequency array.
    2. Traverse numbers from 1 to n.
    3. Find digit sum of current number.
    4. Increase frequency of that digit sum.
    5. Track the largest group size.
    6. Traverse frequency array.
    7. Count how many values are equal to largest size.
    8. Return the count.

    Time complexity:
    O(n * d)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It uses fixed size array.
    It checks each number once.

------------------------------------------------------------*/
int countLargestGroupOptimal(int n) {
    vector<int> freq(100, 0);

    int maxSize = 0;

    for (int num = 1; num <= n; num++) {
        int digitSum = getDigitSumMath(num);
        freq[digitSum]++;

        maxSize = max(maxSize, freq[digitSum]);
    }

    int count = 0;

    for (int i = 0; i < freq.size(); i++) {
        if (freq[i] == maxSize) {
            count++;
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
    int n = 13;

    int ans1 = countLargestGroupBruteForce(n);
    int ans2 = countLargestGroupBetter(n);
    int ans3 = countLargestGroupOptimal(n);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}