#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

/*
    LeetCode 4: Median of Two Sorted Arrays

    Problem:
    We are given two sorted arrays nums1 and nums2.
    We have to find the median of both arrays together.

    Median:
    If total size is odd, middle element is median.
    If total size is even, average of two middle elements is median.
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution

    Basic idea:
    Put all elements in one array.
    Sort the new array.
    Find the median.

    Step-by-step algorithm:
    1. Create an empty array.
    2. Push all elements of nums1 into it.
    3. Push all elements of nums2 into it.
    4. Sort the array.
    5. Find total size.
    6. If size is odd, return middle element.
    7. If size is even, return average of two middle elements.

    Time complexity:
    O((n + m) log(n + m))

    Space complexity:
    O(n + m)

    Note:
    n is the size of nums1.
    m is the size of nums2.
    This solution is simple.
    But it does not use the fact that both arrays are already sorted.

------------------------------------------------------------*/
double findMedianSortedArraysBruteForce(vector<int>& nums1, vector<int>& nums2) {
    vector<int> arr;

    for (int i = 0; i < nums1.size(); i++) {
        arr.push_back(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++) {
        arr.push_back(nums2[i]);
    }

    sort(arr.begin(), arr.end());

    int n = arr.size();

    if (n % 2 == 1) {
        return arr[n / 2];
    }

    long long first = arr[n / 2 - 1];
    long long second = arr[n / 2];

    return (first + second) / 2.0;
}

/*------------------------------------------------------------

    Approach 2: Better Solution

    Basic idea:
    Use two pointers like merge sort.
    We do not need to store the full merged array.
    We only need the middle elements.

    Step-by-step algorithm:
    1. Find total size of both arrays.
    2. Find the middle index.
    3. Use two pointers i and j.
    4. Keep taking the smaller element.
    5. Store previous and current selected elements.
    6. Stop when we reach the middle index.
    7. If total size is odd, return current element.
    8. If total size is even, return average of previous and current.

    Time complexity:
    O(n + m)

    Space complexity:
    O(1)

    Note:
    This is better than brute force.
    It uses sorted property.
    It does not store all elements.

------------------------------------------------------------*/
double findMedianSortedArraysBetter(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    int total = n + m;
    int mid = total / 2;

    int i = 0;
    int j = 0;

    int prev = 0;
    int curr = 0;

    for (int count = 0; count <= mid; count++) {
        prev = curr;

        if (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }
        } else if (i < n) {
            curr = nums1[i];
            i++;
        } else {
            curr = nums2[j];
            j++;
        }
    }

    if (total % 2 == 1) {
        return curr;
    }

    return ((long long)prev + curr) / 2.0;
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution

    Basic idea:
    Use binary search on the smaller array.
    Split both arrays into left half and right half.
    All left half elements should be smaller than right half elements.

    Step-by-step algorithm:
    1. Always apply binary search on the smaller array.
    2. Let n be size of nums1 and m be size of nums2.
    3. Binary search the cut position in nums1.
    4. Find cut position in nums2 using total left size.
    5. Find left and right values around both cuts.
    6. If left1 <= right2 and left2 <= right1, partition is correct.
    7. If total size is odd, return max(left1, left2).
    8. If total size is even, return average of max left and min right.
    9. If left1 > right2, move search left.
    10. Otherwise move search right.

    Time complexity:
    O(log(min(n, m)))

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It does not merge the arrays.
    It only finds the correct partition.

------------------------------------------------------------*/
double findMedianSortedArraysOptimal(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArraysOptimal(nums2, nums1);
    }

    int n = nums1.size();
    int m = nums2.size();

    int low = 0;
    int high = n;

    int totalLeft = (n + m + 1) / 2;

    while (low <= high) {
        int cut1 = low + (high - low) / 2;
        int cut2 = totalLeft - cut1;

        int left1;
        int left2;
        int right1;
        int right2;

        if (cut1 == 0) {
            left1 = INT_MIN;
        } else {
            left1 = nums1[cut1 - 1];
        }

        if (cut2 == 0) {
            left2 = INT_MIN;
        } else {
            left2 = nums2[cut2 - 1];
        }

        if (cut1 == n) {
            right1 = INT_MAX;
        } else {
            right1 = nums1[cut1];
        }

        if (cut2 == m) {
            right2 = INT_MAX;
        } else {
            right2 = nums2[cut2];
        }

        if (left1 <= right2 && left2 <= right1) {
            if ((n + m) % 2 == 1) {
                return max(left1, left2);
            }

            long long first = max(left1, left2);
            long long second = min(right1, right2);

            return (first + second) / 2.0;
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0.0;
}

/*------------------------------------------------------------

    Main function:
    This is only for simple testing.

------------------------------------------------------------*/
int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double ans1 = findMedianSortedArraysBruteForce(nums1, nums2);
    double ans2 = findMedianSortedArraysBetter(nums1, nums2);
    double ans3 = findMedianSortedArraysOptimal(nums1, nums2);

    cout << fixed << setprecision(5);

    cout << "Brute Force Solution:" << endl;
    cout << ans1 << endl;

    cout << "Better Solution:" << endl;
    cout << ans2 << endl;

    cout << "Optimal Solution:" << endl;
    cout << ans3 << endl;

    return 0;
}