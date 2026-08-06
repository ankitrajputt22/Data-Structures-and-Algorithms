#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
    LeetCode 26: Remove Duplicates from Sorted Array

    Problem:
    We are given an integer array nums.
    The array is sorted in non-decreasing order.

    We have to remove duplicates in-place.
    Each unique element should appear only once.

    We have to return k.
    k is the number of unique elements.

    Important:
    The first k elements of nums should contain
    the unique elements in sorted order.

    Example:
    nums = [1, 1, 2]

    After removing duplicates:
    nums = [1, 2, _]

    Return:
    k = 2
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution using Set

    Basic idea:
    Store all elements in a set.
    A set stores only unique values.
    Then copy set values back into nums.

    Step-by-step algorithm:
    1. Create an empty set.
    2. Traverse nums.
    3. Insert every element into the set.
    4. Create index as 0.
    5. Traverse the set.
    6. Copy each value back to nums[index].
    7. Increase index.
    8. Return index as k.

    Time complexity:
    O(n log n)

    Space complexity:
    O(n)

    Note:
    This solution is simple.
    But it uses extra space.
    It also does not fully use the sorted property.

------------------------------------------------------------*/
int removeDuplicatesBruteForce(vector<int>& nums) {
    set<int> st;

    for (int i = 0; i < nums.size(); i++) {
        st.insert(nums[i]);
    }

    int index = 0;

    for (auto value : st) {
        nums[index] = value;
        index++;
    }

    return index;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Extra Array

    Basic idea:
    Since nums is sorted, duplicates are adjacent.
    Store only the first occurrence of each value
    in a temporary array.

    Step-by-step algorithm:
    1. Create an empty temp array.
    2. Traverse nums.
    3. If temp is empty, add nums[i].
    4. Otherwise, compare nums[i] with last value of temp.
    5. If both are different, add nums[i].
    6. Copy temp values back into nums.
    7. Return temp size.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is better than set approach.
    It uses the sorted property.
    But it still uses extra space.

------------------------------------------------------------*/
int removeDuplicatesBetter(vector<int>& nums) {
    vector<int> temp;

    for (int i = 0; i < nums.size(); i++) {
        if (temp.size() == 0 || nums[i] != temp[temp.size() - 1]) {
            temp.push_back(nums[i]);
        }
    }

    for (int i = 0; i < temp.size(); i++) {
        nums[i] = temp[i];
    }

    return temp.size();
}

/*------------------------------------------------------------

    Approach 3: Optimal Solution using Two Pointers

    Basic idea:
    Use one pointer to place unique elements.
    Use another pointer to scan the array.

    Since array is sorted:
    If nums[i] is different from nums[i - 1],
    it is a new unique value.

    Step-by-step algorithm:
    1. If nums is empty, return 0.
    2. Create index as 1.
    3. Traverse nums from index 1.
    4. If nums[i] is different from nums[i - 1],
       place nums[i] at nums[index].
    5. Increase index.
    6. At the end, index is the number of unique elements.
    7. Return index.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best approach.
    It modifies the array in-place.
    It uses no extra array.

------------------------------------------------------------*/
int removeDuplicatesOptimal(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }

    int index = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}

/*------------------------------------------------------------

    Approach 4: STL Solution using unique

    Basic idea:
    C++ has a built-in function unique.
    It moves unique elements to the front.
    It returns an iterator after the last unique element.

    Step-by-step algorithm:
    1. Use unique on nums.
    2. It keeps unique elements in front.
    3. Find distance from nums.begin() to returned iterator.
    4. Return this distance as k.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is short and clean.
    But for interviews, two pointer logic is better to explain.

------------------------------------------------------------*/
int removeDuplicatesSTL(vector<int>& nums) {
    auto it = unique(nums.begin(), nums.end());

    int k = it - nums.begin();

    return k;
}

/*------------------------------------------------------------

    LeetCode style class

    Note:
    On LeetCode, submit only this class.
    Here it calls the optimal two pointer solution.

------------------------------------------------------------*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicatesOptimal(nums);
    }
};

/*------------------------------------------------------------

    Helper function:
    This function prints the first k elements of nums.

------------------------------------------------------------*/
void printArray(vector<int>& nums, int k) {
    cout << "[";

    for (int i = 0; i < k; i++) {
        cout << nums[i];

        if (i != k - 1) {
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
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    vector<int> nums1 = nums;
    vector<int> nums2 = nums;
    vector<int> nums3 = nums;
    vector<int> nums4 = nums;

    int k1 = removeDuplicatesBruteForce(nums1);
    int k2 = removeDuplicatesBetter(nums2);
    int k3 = removeDuplicatesOptimal(nums3);
    int k4 = removeDuplicatesSTL(nums4);

    cout << "Brute Force Solution:" << endl;
    cout << "k = " << k1 << endl;
    printArray(nums1, k1);

    cout << "Better Solution using Extra Array:" << endl;
    cout << "k = " << k2 << endl;
    printArray(nums2, k2);

    cout << "Optimal Solution using Two Pointers:" << endl;
    cout << "k = " << k3 << endl;
    printArray(nums3, k3);

    cout << "STL Solution using unique:" << endl;
    cout << "k = " << k4 << endl;
    printArray(nums4, k4);

    return 0;
}