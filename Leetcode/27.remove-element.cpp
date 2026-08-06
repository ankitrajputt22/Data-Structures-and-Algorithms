#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    LeetCode 27: Remove Element

    Problem:
    We are given an integer array nums.
    We are also given an integer val.

    We have to remove all occurrences of val in-place.

    We have to return k.
    k is the number of elements not equal to val.

    Important:
    The first k elements of nums should not contain val.
    The order of elements can be changed.

    Example:
    nums = [3, 2, 2, 3]
    val = 3

    After removing val:
    nums = [2, 2, _, _]

    Return:
    k = 2
*/

/*------------------------------------------------------------

    Approach 1: Brute Force Solution by Shifting

    Basic idea:
    Whenever val is found, remove it by shifting
    all elements after it one position left.

    Step-by-step algorithm:
    1. Create n as nums size.
    2. Start from index 0.
    3. If nums[i] is equal to val:
       shift all elements after i one step left.
    4. Decrease n by 1.
    5. Do not increase i after shifting.
    6. If nums[i] is not equal to val:
       move i forward.
    7. Return n.

    Time complexity:
    O(n^2)

    Space complexity:
    O(1)

    Note:
    This solution can give TLE for large input.
    It shifts elements again and again.

------------------------------------------------------------*/
int removeElementBruteForce(vector<int>& nums, int val) {
    int n = nums.size();
    int i = 0;

    while (i < n) {
        if (nums[i] == val) {
            for (int j = i; j < n - 1; j++) {
                nums[j] = nums[j + 1];
            }

            n--;
        } else {
            i++;
        }
    }

    return n;
}

/*------------------------------------------------------------

    Approach 2: Better Solution using Extra Array

    Basic idea:
    Store all elements which are not equal to val
    in a temporary array.
    Then copy them back into nums.

    Step-by-step algorithm:
    1. Create an empty temp array.
    2. Traverse nums.
    3. If nums[i] is not equal to val,
       add it to temp.
    4. Copy temp values back to nums.
    5. Return temp size.

    Time complexity:
    O(n)

    Space complexity:
    O(n)

    Note:
    This is better than brute force.
    It does not shift elements many times.
    But it uses extra space.

------------------------------------------------------------*/
int removeElementBetter(vector<int>& nums, int val) {
    vector<int> temp;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
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
    Use one pointer to scan the array.
    Use another pointer to place valid elements.

    Step-by-step algorithm:
    1. Create index as 0.
    2. Traverse nums using i.
    3. If nums[i] is not equal to val,
       place nums[i] at nums[index].
    4. Increase index.
    5. After loop, index is the number of valid elements.
    6. Return index.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is the best simple approach.
    It keeps the relative order of remaining elements.
    It modifies nums in-place.

------------------------------------------------------------*/
int removeElementOptimal(vector<int>& nums, int val) {
    int index = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}

/*------------------------------------------------------------

    Approach 4: Optimal Solution using Two Pointers from End

    Basic idea:
    Since order does not matter, replace val with
    the last unchecked element.

    Step-by-step algorithm:
    1. Create i as 0.
    2. Create n as nums size.
    3. While i is less than n:
       check nums[i].
    4. If nums[i] is equal to val:
       replace nums[i] with nums[n - 1].
    5. Decrease n.
    6. Do not increase i in this case.
    7. If nums[i] is not equal to val:
       increase i.
    8. Return n.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is also optimal.
    It can do fewer writes when val appears many times.
    It does not keep the order of elements.

------------------------------------------------------------*/
int removeElementOptimalFromEnd(vector<int>& nums, int val) {
    int i = 0;
    int n = nums.size();

    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            n--;
        } else {
            i++;
        }
    }

    return n;
}

/*------------------------------------------------------------

    Approach 5: STL Solution using remove

    Basic idea:
    C++ remove function moves all elements not equal to val
    to the front of the array.

    Step-by-step algorithm:
    1. Use remove on nums.
    2. remove returns iterator after the last valid element.
    3. Find distance from nums.begin() to that iterator.
    4. Return this distance as k.

    Time complexity:
    O(n)

    Space complexity:
    O(1)

    Note:
    This is short and clean.
    But for interviews, two pointer logic is better.

------------------------------------------------------------*/
int removeElementSTL(vector<int>& nums, int val) {
    auto it = remove(nums.begin(), nums.end(), val);

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
    int removeElement(vector<int>& nums, int val) {
        return removeElementOptimal(nums, val);
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
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    vector<int> nums1 = nums;
    vector<int> nums2 = nums;
    vector<int> nums3 = nums;
    vector<int> nums4 = nums;
    vector<int> nums5 = nums;

    int k1 = removeElementBruteForce(nums1, val);
    int k2 = removeElementBetter(nums2, val);
    int k3 = removeElementOptimal(nums3, val);
    int k4 = removeElementOptimalFromEnd(nums4, val);
    int k5 = removeElementSTL(nums5, val);

    cout << "Brute Force Solution:" << endl;
    cout << "k = " << k1 << endl;
    printArray(nums1, k1);

    cout << "Better Solution using Extra Array:" << endl;
    cout << "k = " << k2 << endl;
    printArray(nums2, k2);

    cout << "Optimal Solution using Two Pointers:" << endl;
    cout << "k = " << k3 << endl;
    printArray(nums3, k3);

    cout << "Optimal Solution using Two Pointers from End:" << endl;
    cout << "k = " << k4 << endl;
    printArray(nums4, k4);

    cout << "STL Solution using remove:" << endl;
    cout << "k = " << k5 << endl;
    printArray(nums5, k5);

    return 0;
}