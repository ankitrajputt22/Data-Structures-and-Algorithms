#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 189: Rotate Array

    Problem:
    We are given an integer array nums.
    We are also given an integer k.

    We have to rotate the array to the right by k steps.

    Right rotation:
    The last element moves to the first position.

    Example:
    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3

    After rotation:
    [5, 6, 7, 1, 2, 3, 4]
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Rotate the array one step at a time.
    Repeat this process k times.

    Step-by-step algorithm:
    1. Find size of array.
    2. If array is empty, return.
    3. Take k modulo n.
    4. Repeat k times.
    5. Store last element.
    6. Shift all elements one step to the right.
    7. Put last element at index 0.

    Time complexity:
    O(n * k)

    Space complexity:
    O(1)

    Note:
    This solution can give TLE for large input.
    It shifts the array many times.

------------------------------------------------------------*/
void rotateBruteForce(vector<int>& nums, int k) {
    int n = nums.size();

    if (n == 0) {
        return;
    }

    k = k % n;

    for (int step = 1; step <= k; step++) {
        int last = nums[n - 1];

        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i - 1];
        }

        nums[0] = last;
    }
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Extra Array

    Basic idea:
    Create a new array.
    Put every element directly at its rotated position.

    Step-by-step algorithm:
    1. Find size of array.
    2. If array is empty, return.
    3. Take k modulo n.
    4. Create temp array of size n.
    5. For every index i:
       new index will be (i + k) % n.
    6. Store nums[i] at temp[newIndex].
    7. Copy temp back to nums.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is better than brute force.
    It rotates the array in one pass.
    But it uses extra space.

------------------------------------------------------------*/
void rotateBetter(vector<int>& nums, int k) {
    int n = nums.size();

    if (n == 0) {
        return;
    }

    k = k % n;

    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        int newIndex = (i + k) % n;
        temp[newIndex] = nums[i];
    }

    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Reversal

    Basic idea:
    Reverse the full array.
    Then reverse first k elements.
    Then reverse remaining elements.

    Example:
    nums = [1, 2, 3, 4, 5, 6, 7], k = 3

    Reverse full array:
    [7, 6, 5, 4, 3, 2, 1]

    Reverse first k elements:
    [5, 6, 7, 4, 3, 2, 1]

    Reverse remaining elements:
    [5, 6, 7, 1, 2, 3, 4]

    Step-by-step algorithm:
    1. Find size of array.
    2. If array is empty, return.
    3. Take k modulo n.
    4. Reverse the whole array.
    5. Reverse from index 0 to k - 1.
    6. Reverse from index k to n - 1.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best and simplest approach.
    It rotates the array in-place.

------------------------------------------------------------*/
void reverseArray(vector<int>& nums, int left, int right) {
    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

void rotateOptimalReverse(vector<int>& nums, int k) {
    int n = nums.size();

    if (n == 0) {
        return;
    }

    k = k % n;

    reverseArray(nums, 0, n - 1);
    reverseArray(nums, 0, k - 1);
    reverseArray(nums, k, n - 1);
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Cyclic Replacement

    Basic idea:
    Move every element to its final position.
    Use cycles to avoid extra array.

    Step-by-step algorithm:
    1. Find size of array.
    2. If array is empty, return.
    3. Take k modulo n.
    4. Start from index 0.
    5. Move current element to (current + k) % n.
    6. Keep moving replaced element forward.
    7. If cycle ends, start from next index.
    8. Stop when all n elements are moved.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is also an optimal approach.
    It is in-place.
    But reversal approach is easier to remember.

------------------------------------------------------------*/
void rotateOptimalCyclic(vector<int>& nums, int k) {
    int n = nums.size();

    if (n == 0) {
        return;
    }

    k = k % n;

    if (k == 0) {
        return;
    }

    int moved = 0;

    for (int start = 0; moved < n; start++) {
        int current = start;
        int previous = nums[start];

        do {
            int nextIndex = (current + k) % n;
            int temp = nums[nextIndex];

            nums[nextIndex] = previous;
            previous = temp;

            current = nextIndex;
            moved++;

        } while (start != current);
    }
}

/*------------------------------------------------------------

    Helper function:
    This function prints the array.

------------------------------------------------------------*/
void printArray(vector<int>& nums) {
    cout << "[";

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];

        if (i != nums.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    vector<int> nums1 = nums;
    vector<int> nums2 = nums;
    vector<int> nums3 = nums;
    vector<int> nums4 = nums;

    rotateBruteForce(nums1, k);
    rotateBetter(nums2, k);
    rotateOptimalReverse(nums3, k);
    rotateOptimalCyclic(nums4, k);

    cout << "Brute Force Solution:" << endl;
    printArray(nums1);

    cout << "Better Solution:" << endl;
    printArray(nums2);

    cout << "Optimal Solution using Reversal:" << endl;
    printArray(nums3);

    cout << "Optimal Solution using Cyclic Replacement:" << endl;
    printArray(nums4);

    return 0;
}