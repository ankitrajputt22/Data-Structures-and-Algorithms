#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 1846: Maximum Element After Decreasing and Rearranging

    Problem:
    We are given an array arr.

    We can do these operations:
    1. Rearrange the array in any order.
    2. Decrease any element to a smaller positive value.

    After operations:
    1. arr[0] should be 1.
    2. Difference between adjacent elements should be at most 1.

    We have to maximize the largest element in the final array.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Try every possible arrangement of the array.
    For each arrangement, decrease values greedily.
    Find the maximum possible last answer.

    Step-by-step algorithm:
    1. Sort the array first.
    2. Generate all permutations.
    3. For every permutation:
       make first element as 1.
    4. For every next element:
       it can be at most previous + 1.
    5. So take minimum of current value and previous + 1.
    6. Track the largest value in this permutation.
    7. Update the final answer.
    8. Return the final answer.

    Time complexity:
    O(n! * n)

    Space complexity:
    O(1)

    Note:
    This solution can give TLE for large input.
    It checks all possible arrangements.

------------------------------------------------------------*/
int maximumElementAfterDecrementingAndRearrangingBruteForce(vector<int> arr) {
    sort(arr.begin(), arr.end());

    int ans = 1;

    do {
        vector<int> temp = arr;

        temp[0] = 1;
        int maxValue = temp[0];

        for (int i = 1; i < temp.size(); i++) {
            temp[i] = min(temp[i], temp[i - 1] + 1);
            maxValue = max(maxValue, temp[i]);
        }

        ans = max(ans, maxValue);

    } while (next_permutation(arr.begin(), arr.end()));

    return ans;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Sorting

    Basic idea:
    To get the maximum answer, sort the array.
    Then make the first element 1.
    For each next element, keep it at most previous + 1.

    Step-by-step algorithm:
    1. Sort the array.
    2. Set arr[0] to 1.
    3. Traverse from index 1.
    4. If arr[i] is greater than arr[i - 1] + 1,
       decrease arr[i] to arr[i - 1] + 1.
    5. Otherwise keep arr[i] as it is.
    6. At the end, return the last element.

    Time complexity:
    O(n log n)

    Space complexity:
    O(1)

    Note:
    This is better than brute force.
    Sorting gives the best order.
    Then greedy decreasing works correctly.

------------------------------------------------------------*/
int maximumElementAfterDecrementingAndRearrangingBetter(vector<int> arr) {
    sort(arr.begin(), arr.end());

    arr[0] = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1] + 1) {
            arr[i] = arr[i - 1] + 1;
        }
    }

    return arr[arr.size() - 1];
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Counting

    Basic idea:
    The final maximum value can never be more than n.
    So values greater than n can be treated as n.
    Count frequencies and build answer from small to large.

    Step-by-step algorithm:
    1. Let n be the size of arr.
    2. Create frequency array of size n + 1.
    3. For every value:
       if value is greater than n, count it as n.
       otherwise count it normally.
    4. Create answer as 0.
    5. Traverse values from 1 to n.
    6. If frequency of current value is greater than 0,
       we can increase answer by 1.
    7. Return answer.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is the best approach.
    It avoids sorting.
    The answer cannot be greater than n.

------------------------------------------------------------*/
int maximumElementAfterDecrementingAndRearrangingOptimal(vector<int>& arr) {
    int n = arr.size();

    vector<int> freq(n + 1, 0);

    for (int i = 0; i < n; i++) {
        if (arr[i] > n) {
            freq[n]++;
        } else {
            freq[arr[i]]++;
        }
    }

    int ans = 0;

    for (int value = 1; value <= n; value++) {
        if (freq[value] > 0) {
            ans++;
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
    vector<int> arr = {2, 2, 1, 2, 1};

    int ans1 = maximumElementAfterDecrementingAndRearrangingBruteForce(arr);
    int ans2 = maximumElementAfterDecrementingAndRearrangingBetter(arr);
    int ans3 = maximumElementAfterDecrementingAndRearrangingOptimal(arr);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}