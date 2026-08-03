#include <bits/stdc++.h>
using namespace std;

/*
========================================================
LEETCODE 33 : SEARCH IN ROTATED SORTED ARRAY
========================================================

Given:
A rotated sorted array with DISTINCT elements.

Goal:
Return index of target element.

Constraint:
Time Complexity must be O(log n)

Example:
nums = [4,5,6,7,0,1,2]
target = 0
Output = 4

========================================================
KEY PROPERTY

In a rotated sorted array,
ONE HALF IS ALWAYS SORTED.

Example:
[4,5,6,7,0,1,2]

Left half  : sorted
Right half : sorted

We exploit this property using binary search.
========================================================
*/

class Solution
{

public:
    /*
    ========================================================
    APPROACH 1 : BRUTE FORCE (LINEAR SEARCH)
    ========================================================

    Idea:
    Simply traverse the array.

    Algorithm:
    Check every element.

    Time Complexity : O(n)
    Space Complexity: O(1)

    Not acceptable for this problem because
    question requires O(log n).
    ========================================================
    */

    int searchBrute(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
        }

        return -1;
    }

    /*
    ========================================================
    APPROACH 2 : TWO PASS BINARY SEARCH
    ========================================================

    Step 1
    Find pivot (smallest element)

    Example:
    [4,5,6,7,0,1,2]
    pivot = 4

    Step 2
    Do binary search in correct half.

    If target >= nums[0]
    search left half

    Else
    search right half

    Time Complexity:
    O(log n)

    Space Complexity:
    O(1)
    ========================================================
    */

    int findPivot(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }

    int binarySearch(vector<int> &nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }

    int searchTwoPass(vector<int> &nums, int target)
    {
        int n = nums.size();

        int pivot = findPivot(nums);

        if (pivot == 0)
            return binarySearch(nums, 0, n - 1, target);

        if (target >= nums[0])
            return binarySearch(nums, 0, pivot - 1, target);

        return binarySearch(nums, pivot, n - 1, target);
    }

    /*
    ========================================================
    APPROACH 3 : OPTIMAL ONE PASS BINARY SEARCH
    ========================================================

    Core Idea:
    At any time,
    either LEFT half or RIGHT half is sorted.

    We detect which half is sorted and decide
    where the target lies.

    Steps:

    1. Calculate mid
    2. If nums[mid] == target → return mid

    3. Check if LEFT half sorted

        nums[low] <= nums[mid]

    4. If target lies in that range
        search left half
       else
        search right half

    5. Otherwise RIGHT half must be sorted

    Time Complexity : O(log n)
    Space Complexity: O(1)

    This is the EXPECTED interview solution.
    ========================================================
    */

    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            // LEFT HALF SORTED
            if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // RIGHT HALF SORTED
            else
            {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

/*
========================================================
DRY RUN

nums = [4,5,6,7,0,1,2]
target = 0

Iteration 1
low=0 high=6 mid=3
nums[mid]=7

Left half sorted
Target not in range
Search right

Iteration 2
low=4 high=6 mid=5
nums[mid]=1

Left sorted

Target in range
Search left

Iteration 3
low=4 high=4 mid=4
nums[mid]=0

FOUND
Return 4

========================================================
EDGE CASES

1) Single element
[1]

2) Not rotated
[1,2,3,4,5]

3) Two elements
[3,1]

4) Target not present
Return -1

========================================================
*/

int main()
{
    Solution obj;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int target = 0;

    int ans = obj.search(nums, target);

    cout << "Target index : " << ans << endl;

    return 0;
}