#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=======================================================
LeetCode 35
Search Insert Position
=======================================================

Problem:
Given a sorted array and a target value,
return the index if the target is found.

If not found, return the index where it should
be inserted to maintain sorted order.

Example:
nums = [1,3,5,6]
target = 5

Output = 2

=======================================================
*/

class Solution
{
public:

    /*
    ---------------------------------------------------
    Approach 1 : Brute Force (Linear Search)
    ---------------------------------------------------

    Traverse the array and return the first index
    where nums[i] >= target.

    If no such element exists, return n.

    Time Complexity  : O(n)
    Space Complexity : O(1)
    */

    int searchInsertBrute(vector<int>& nums, int target)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= target)
            {
                return i;
            }
        }

        return n;
    }



    /*
    ---------------------------------------------------
    Approach 2 : Binary Search (Optimal)
    ---------------------------------------------------

    Since array is sorted, use binary search.

    Key idea:
    At the end of binary search, 'low'
    represents the correct insertion position.

    Time Complexity  : O(log n)
    Space Complexity : O(1)
    */

    int searchInsertBinary(vector<int>& nums, int target)
    {
        int low  = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            else if (nums[mid] < target)
            {
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }

        // If target not found, low is insert position
        return low;
    }



    /*
    ---------------------------------------------------
    Approach 3 : STL using lower_bound()
    ---------------------------------------------------

    lower_bound returns the first element >= target.

    That index is exactly the insertion position.

    Time Complexity  : O(log n)
    Space Complexity : O(1)
    */

    int searchInsertSTL(vector<int>& nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};



int main()
{
    Solution obj;

    vector<int> nums = {1,3,5,6};
    int target = 5;

    cout << "Brute Force Result: "
         << obj.searchInsertBrute(nums, target) << endl;

    cout << "Binary Search Result: "
         << obj.searchInsertBinary(nums, target) << endl;

    cout << "STL Result: "
         << obj.searchInsertSTL(nums, target) << endl;

    return 0;
}