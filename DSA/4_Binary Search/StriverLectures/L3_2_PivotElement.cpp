#include <iostream>
#include <vector>

using namespace std;

/*
-------------------------------------------------------
Program: Find Pivot in Rotated Sorted Array
-------------------------------------------------------

Pivot Definition:
Pivot is the index of the SMALLEST element
in a rotated sorted array.

Example:

Original array:
[0,1,2,4,5,6,7]

Rotated array:
[4,5,6,7,0,1,2]

Pivot index = 4
Pivot value = 0

-------------------------------------------------------
Algorithm (Binary Search)

1. Start with low = 0, high = n-1

2. Find mid

3. Compare nums[mid] with nums[high]

   If nums[mid] > nums[high]
      → pivot is in RIGHT half

   Else
      → pivot is in LEFT half including mid

4. Continue until low == high

5. That index is pivot

Time Complexity : O(log n)
Space Complexity: O(1)

-------------------------------------------------------
*/

int findPivot(vector<int>& nums)
{
    int low  = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // If mid element is greater than last element
        // Pivot must be in the right half
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            // Pivot is in the left half (including mid)
            high = mid;
        }
    }

    return low;
}



int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int pivotIndex = findPivot(nums);

    cout << "Pivot Index : " << pivotIndex << endl;
    cout << "Pivot Value : " << nums[pivotIndex] << endl;

    return 0;
}