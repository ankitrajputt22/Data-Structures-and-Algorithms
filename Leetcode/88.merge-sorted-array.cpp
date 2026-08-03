#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=========================================================
LeetCode 88 : Merge Sorted Array
=========================================================

Goal:
Merge nums2 into nums1 in sorted order.

nums1 has extra space at end (size m+n)

=========================================================
*/



/*
=========================================================
Approach 1 : Brute Force (Extra Array)
=========================================================

Idea:
1. Copy both arrays into a new array
2. Sort the result
3. Copy back to nums1

Time Complexity : O((m+n) log(m+n))
Space Complexity : O(m+n)

---------------------------------------------------------
Intuition:
Simplest but not optimal
=========================================================
*/

class Solution1 {
public:

    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n)
    {
        vector<int> temp;

        for (int i = 0; i < m; i++)
            temp.push_back(nums1[i]);

        for (int j = 0; j < n; j++)
            temp.push_back(nums2[j]);

        sort(temp.begin(), temp.end());

        for (int i = 0; i < m + n; i++)
            nums1[i] = temp[i];
    }
};




/*
=========================================================
Approach 2 : Two Pointer (Forward + Extra Space)
=========================================================

Idea:
1. Merge like merge-sort
2. Use temporary array

Time Complexity : O(m+n)
Space Complexity : O(m+n)

---------------------------------------------------------
Better than brute but still uses extra space
=========================================================
*/

class Solution2 {
public:

    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n)
    {
        vector<int> temp;

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j])
                temp.push_back(nums1[i++]);
            else
                temp.push_back(nums2[j++]);
        }

        while (i < m) temp.push_back(nums1[i++]);
        while (j < n) temp.push_back(nums2[j++]);

        for (int k = 0; k < m + n; k++)
            nums1[k] = temp[k];
    }
};




/*
=========================================================
Approach 3 : Optimal (Two Pointer from Back)
=========================================================

Idea:
Fill nums1 from the END.

Why?
Because nums1 has empty space at the end,
so we avoid overwriting existing values.

Steps:
1. i = m-1 (end of nums1 valid part)
2. j = n-1 (end of nums2)
3. k = m+n-1 (end of nums1)

Compare and place largest element at k

Time Complexity : O(m+n)
Space Complexity : O(1)

---------------------------------------------------------
This is the BEST solution (expected in interviews)
=========================================================
*/

class Solution3 {
public:

    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        // If nums2 still has elements
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // No need to copy nums1 elements
    }
};



/*
=========================================================
Driver Code
=========================================================
*/

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3, n = 3;

    Solution3 obj;

    obj.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int x : nums1)
        cout << x << " ";

    return 0;
}