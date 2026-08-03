#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    LeetCode 169: Majority Element

    Problem:
    We are given an integer array nums.

    Majority element:
    The element which appears more than n / 2 times.

    We have to return the majority element.

    Note:
    The majority element always exists in the array.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Count frequency of every element using loops.
    If any element appears more than n / 2 times,
    return that element.

    Step-by-step algorithm:
    1. Find size of array.
    2. Run a loop for every element.
    3. For each element, count how many times it appears.
    4. Use another loop to count frequency.
    5. If frequency is greater than n / 2,
       return that element.
    6. Return -1 if no answer is found.

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

    Note:
    This solution is simple.
    But it can be slow for large input.
    It checks frequency again and again.

------------------------------------------------------------*/
int majorityElementBruteForce(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }

        if (count > n / 2) {
            return nums[i];
        }
    }

    return -1;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Hash Map

    Basic idea:
    Store frequency of every element in a hash map.
    The element with frequency more than n / 2 is answer.

    Step-by-step algorithm:
    1. Create a hash map.
    2. Traverse the array.
    3. Increase frequency of current element.
    4. If frequency becomes greater than n / 2,
       return current element.
    5. Return -1 if no answer is found.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is better than brute force.
    It counts frequency in one pass.
    But it uses extra space.

------------------------------------------------------------*/
int majorityElementBetter(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        mp[nums[i]]++;

        if (mp[nums[i]] > n / 2) {
            return nums[i];
        }
    }

    return -1;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Moore's Voting Algorithm

    Basic idea:
    Cancel different elements with each other.
    Since majority element appears more than n / 2 times,
    it will remain at the end.

    Step-by-step algorithm:
    1. Create candidate as 0.
    2. Create count as 0.
    3. Traverse every element.
    4. If count is 0, make current element candidate.
    5. If current element is equal to candidate,
       increase count.
    6. Otherwise decrease count.
    7. At the end, candidate is the majority element.
    8. Return candidate.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It does not use extra space.
    It works because majority element always exists.

------------------------------------------------------------*/
int majorityElementOptimal(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
        }

        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
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
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int ans1 = majorityElementBruteForce(nums);
    int ans2 = majorityElementBetter(nums);
    int ans3 = majorityElementOptimal(nums);

    cout << "Brute Force Solution:" << endl;
    printAnswer(ans1);

    cout << "Better Solution:" << endl;
    printAnswer(ans2);

    cout << "Optimal Solution:" << endl;
    printAnswer(ans3);

    return 0;
}