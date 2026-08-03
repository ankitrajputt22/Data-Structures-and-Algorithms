#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    LeetCode 3020: Find the Maximum Number of Elements in Subset

    Problem:
    We are given an integer array nums.

    We have to find the maximum size of a subset
    that can be arranged like this:

    x, x^2, x^4, ..., x^4, x^2, x

    Important:
    The subset length should be odd.
    The first and last values are same.
    The second and second last values are same.
    The middle value appears only once.

    Example:
    nums = [5, 4, 1, 2, 2]

    We can take subset:
    [2, 4, 2]

    Because:
    2, 2^2, 2

    Answer = 3
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Try every number as starting value x.
    For every x, check powers:
    x, x^2, x^4, x^8 ...
    For every value except middle, we need 2 copies.
    For the middle value, we need 1 copy.

    Step-by-step algorithm:
    1. Store frequency of every number.
    2. Create answer as 1.
    3. Try every nums[i] as starting value.
    4. If x is 1, handle it separately.
    5. Otherwise keep checking x, x^2, x^4 ...
    6. If current value has at least 2 copies,
       add 2 to length.
    7. Move to next power by current = current * current.
    8. When 2 copies are not available,
       check if 1 copy is available for middle.
    9. If yes, add 1.
    10. If no, remove 1 pair because middle is missing.
    11. Update answer.
    12. Return answer.

    Time complexity:
    O(n * log log maxValue)

    Space complexity:
    O(n)

    Note:
    This solution can do repeated work.
    The same starting value can be checked many times.
    But powers grow very fast.

------------------------------------------------------------*/
int maximumLengthBruteForce(vector<int>& nums) {
    unordered_map<long long, int> freq;

    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }

    int ans = 1;

    for (int i = 0; i < nums.size(); i++) {
        long long x = nums[i];

        if (x == 1) {
            int countOne = freq[1];

            if (countOne % 2 == 0) {
                countOne--;
            }

            ans = max(ans, countOne);
            continue;
        }

        long long current = x;
        int length = 0;

        while (freq[current] >= 2) {
            length = length + 2;

            if (current > 1000000000 / current) {
                break;
            }

            current = current * current;
        }

        if (freq[current] >= 1) {
            length++;
        } else {
            length--;
        }

        ans = max(ans, length);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 2: Better Solution

    Basic idea:
    Sort the array.
    Try each different value only once.
    This avoids repeated checking for duplicate starting values.

    Step-by-step algorithm:
    1. Store frequency of every number.
    2. Sort nums.
    3. Create answer as 1.
    4. Traverse nums.
    5. Skip duplicate starting values.
    6. Handle value 1 separately.
    7. For other values, check powers:
       x, x^2, x^4 ...
    8. Add 2 while frequency is at least 2.
    9. Add 1 if middle value exists.
    10. Otherwise remove 1 from length.
    11. Update answer.
    12. Return answer.

    Time complexity:
    O(n log n + u * log log maxValue)

    Space complexity:
    O(n)

    Note:
    u is the number of unique values.
    This is better than brute force.
    It does not process duplicate starting values again.

------------------------------------------------------------*/
int maximumLengthBetter(vector<int> nums) {
    unordered_map<long long, int> freq;

    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }

    sort(nums.begin(), nums.end());

    int ans = 1;

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        long long x = nums[i];

        if (x == 1) {
            int countOne = freq[1];

            if (countOne % 2 == 0) {
                countOne--;
            }

            ans = max(ans, countOne);
            continue;
        }

        long long current = x;
        int length = 0;

        while (freq[current] >= 2) {
            length = length + 2;

            if (current > 1000000000 / current) {
                break;
            }

            current = current * current;
        }

        if (freq[current] >= 1) {
            length++;
        } else {
            length--;
        }

        ans = max(ans, length);
    }

    return ans;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Frequency Map

    Basic idea:
    Count frequencies first.
    Then try only unique starting values.
    Since values become squared again and again,
    the chain length is very small.

    Step-by-step algorithm:
    1. Store frequency of every number.
    2. Create answer as 1.
    3. Traverse each unique value in frequency map.
    4. If value is 1:
       maximum valid length is the largest odd count of 1.
    5. For any other value:
       start with current = value.
    6. While current has at least 2 copies:
       add 2 to length.
    7. Square current.
    8. After loop, if current exists:
       use it as middle and add 1.
    9. Otherwise remove 1,
       because the last pair cannot stand without middle.
    10. Update answer.
    11. Return answer.

    Time complexity:
    O(n + u * log log maxValue)

    Space complexity:
    O(n)

    Note:
    u is the number of unique values.
    This is the best approach.
    It avoids sorting.
    It checks each unique starting value only once.

------------------------------------------------------------*/
int maximumLengthOptimal(vector<int>& nums) {
    unordered_map<long long, int> freq;

    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }

    int ans = 1;

    for (auto it : freq) {
        long long x = it.first;

        if (x == 1) {
            int countOne = it.second;

            if (countOne % 2 == 0) {
                countOne--;
            }

            ans = max(ans, countOne);
            continue;
        }

        long long current = x;
        int length = 0;

        while (freq[current] >= 2) {
            length = length + 2;

            if (current > 1000000000 / current) {
                break;
            }

            current = current * current;
        }

        if (freq[current] >= 1) {
            length++;
        } else {
            length--;
        }

        ans = max(ans, length);
    }

    return ans;
}


/*------------------------------------------------------------

    Approach: Hash Map and Square Chain

    Basic idea:
    Count the frequency of every number.
    Then try to build a valid sequence starting from each number.

    A valid sequence looks like:
    x, x^2, x^4, x^8 ...

    For every number before the middle,
    we need 2 copies.

    For the middle number,
    we need only 1 copy.

    Special case:
    Number 1 is handled separately.
    Because 1 squared is still 1.
    So we can only take an odd count of 1.

    Step-by-step algorithm:
    1. Store frequency of every number in a hash map.
    2. Handle number 1 separately.
    3. If count of 1 is odd, use all ones.
    4. If count of 1 is even, use count - 1 ones.
    5. Traverse every number in the map.
    6. Skip number 1.
    7. Start a square chain from current number.
    8. While current number has frequency more than 1:
       a. Add 2 to length.
       b. Move to current * current.
    9. If current number exists, add 1 as the middle element.
    10. Otherwise, remove 1 from length.
    11. Update the maximum answer.
    12. Return answer.

    Time complexity:
    O(n * log log maxValue)

    Space complexity:
    O(n)

    Note:
    The chain grows very fast because we keep squaring.
    So the inner loop runs only a few times.

    For every level except the center,
    we need 2 same numbers.

    If we cannot place a center,
    we remove one element to keep the length odd.

------------------------------------------------------------*/
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;

        for (int &num : nums) {
            mp[num]++;
        }

        long long res = 0;

        if (mp.count(1)) {
            if (mp[1] % 2 == 1) {
                res = mp[1];
            } else {
                res = mp[1] - 1;
            }
        }

        for (auto &[num, freq] : mp) {
            if (num == 1) {
                continue;
            }

            long long curr = num;
            long long len = 0;

            while (mp.find(curr) != mp.end() && mp[curr] > 1) {
                len += 2;
                curr = curr * curr;
            }

            if (mp.find(curr) != mp.end()) {
                len += 1;
            } else {
                len -= 1;
            }

            res = max(res, len);
        }

        return res;
    }
};



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
    vector<int> nums = {5, 4, 1, 2, 2};

    int ans1 = maximumLengthBruteForce(nums);
    int ans2 = maximumLengthBetter(nums);
    int ans3 = maximumLengthOptimal(nums);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}