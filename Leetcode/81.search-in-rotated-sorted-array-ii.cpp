#include <iostream>
#include <vector>

using namespace std;

/*
=========================================================
LeetCode 81 : Search in Rotated Sorted Array II
=========================================================

Goal:
Search target in rotated sorted array with duplicates.

Return true if found, else false.

=========================================================

Approach : Modified Binary Search

---------------------------------------------------------
Key Problem:
Duplicates make it hard to identify sorted half.

Example:
[1,0,1,1,1]

nums[low] == nums[mid] == nums[high]
→ cannot decide which half is sorted

---------------------------------------------------------
Solution:
Shrink search space:
low++, high--

=========================================================
Time Complexity:
Average: O(log n)
Worst case: O(n) (due to duplicates)

Space Complexity:
O(1)
=========================================================
*/

class Solution {
public:

    bool search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target)
                return true;


            /*
            -------------------------------------------------
            Case 1: Duplicates → cannot decide sorted half
            -------------------------------------------------
            */
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }


            /*
            -------------------------------------------------
            Case 2: Left half is sorted
            -------------------------------------------------
            */
            else if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }


            /*
            -------------------------------------------------
            Case 3: Right half is sorted
            -------------------------------------------------
            */
            else
            {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;
    }
};



/*
=========================================================
Driver Code
=========================================================
*/

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    Solution obj;

    cout << "Found: "
         << obj.search(nums, target);

    return 0;
}