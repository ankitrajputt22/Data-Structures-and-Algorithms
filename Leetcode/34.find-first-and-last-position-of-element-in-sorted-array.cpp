#include <iostream>
#include <algo
#include <vector>

using namespace std;

/*
-----------------------------------------------------------
LeetCode 34
Find First and Last Position of Element in Sorted Array
-----------------------------------------------------------

Given:
A sorted array nums and a target value.

Return:
The first and last position of the target.

If not found:
return [-1,-1]

Example:
nums = [5,7,7,8,8,10]
target = 8

Output:
[3,4]

-----------------------------------------------------------
Important Idea

Since the array is sorted,
we can use Binary Search.

But we need TWO binary searches:

1) Find FIRST occurrence
2) Find LAST occurrence

Time Complexity : O(log n)
Space Complexity: O(1)

-----------------------------------------------------------
*/


class Solution
{
public:

    /*
    -------------------------------------------------------
    Approach 1 : Brute Force
    -------------------------------------------------------

    Traverse entire array and record
    first and last index.

    Time Complexity : O(n)
    Space Complexity: O(1)
    */

    vector<int> searchRangeBrute(vector<int>& nums, int target)
    {
        int first = -1;
        int last  = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                if (first == -1)
                {
                    first = i;
                }

                last = i;
            }
        }

        return {first, last};
    }



    /*
    -------------------------------------------------------
    Binary Search to find FIRST occurrence
    -------------------------------------------------------
    */

    int findFirst(vector<int>& nums, int target)
    {
        int low  = 0;
        int high = nums.size() - 1;

        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                high = mid - 1;   // search left side
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

        return ans;
    }



    /*
    -------------------------------------------------------
    Binary Search to find LAST occurrence
    -------------------------------------------------------
    */

    int findLast(vector<int>& nums, int target)
    {
        int low  = 0;
        int high = nums.size() - 1;

        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                low = mid + 1;   // search right side
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

        return ans;
    }



    /*
    -------------------------------------------------------
    Approach 2 : Optimal Solution
    -------------------------------------------------------

    Use two binary searches
    */

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int first = findFirst(nums, target);
        int last  = findLast(nums, target);

        return {first, last};
    }
};



---------------------------------------------------------
Key Idea

Instead of writing binary search manually,
we can use C++ STL functions:

1) lower_bound()
2) upper_bound()

Both functions internally use binary search.
So the time complexity remains O(log n).

---------------------------------------------------------
lower_bound()

Definition:
Returns iterator pointing to the FIRST element
that is >= target.

Example:
nums = [5,7,7,8,8,10]
target = 8

lower_bound → index 3

---------------------------------------------------------
upper_bound()

Definition:
Returns iterator pointing to the FIRST element
that is > target.

Example:
nums = [5,7,7,8,8,10]
target = 8

upper_bound → index 5

So last occurrence = upper_bound - 1

---------------------------------------------------------
Time Complexity
O(log n)

Space Complexity
O(1)

=========================================================
*/

class Solution
{
public:

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();

        /*
        -------------------------------------------------
        Step 1 : Find the lower bound

        lower_bound returns iterator of first element
        >= target.

        To convert iterator to index we subtract
        nums.begin()
        -------------------------------------------------
        */

        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();


        /*
        -------------------------------------------------
        Step 2 : Check if target exists

        Two conditions when target does not exist:

        1) lb == n
           lower_bound points outside the array

        2) nums[lb] != target
           element found is not equal to target
        -------------------------------------------------
        */

        if (lb == n || nums[lb] != target)
        {
            return {-1, -1};
        }


        /*
        -------------------------------------------------
        Step 3 : Find upper bound

        upper_bound returns iterator of first element
        strictly greater than target.

        That means:
        the last occurrence of target = ub - 1
        -------------------------------------------------
        */

        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();


        /*
        -------------------------------------------------
        Step 4 : Return the answer

        first occurrence = lb
        last occurrence  = ub - 1
        -------------------------------------------------
        */

        return {lb, ub - 1};
    }
};




int main()
{
    Solution obj;

    vector<int> nums = {5,7,7,8,8,10};

    int target = 8;

    vector<int> result = obj.searchRange(nums, target);

    cout << "First Position : " << result[0] << endl;
    cout << "Last Position  : " << result[1] << endl;

    return 0;
}



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=========================================================
LeetCode 34
Find First and Last Position of Element in Sorted Array
=========================================================

Problem:
Given a sorted array nums and a target value,
return the starting and ending position of the target.

If target is not found:
return [-1, -1]

Example:
nums = [5,7,7,8,8,10]
target = 8

Output:
[3,4]

---------------------------------------------------------
Key Idea

Instead of writing binary search manually,
we can use C++ STL functions:

1) lower_bound()
2) upper_bound()

Both functions internally use binary search.
So the time complexity remains O(log n).

---------------------------------------------------------
lower_bound()

Definition:
Returns iterator pointing to the FIRST element
that is >= target.

Example:
nums = [5,7,7,8,8,10]
target = 8

lower_bound → index 3

---------------------------------------------------------
upper_bound()

Definition:
Returns iterator pointing to the FIRST element
that is > target.

Example:
nums = [5,7,7,8,8,10]
target = 8

upper_bound → index 5

So last occurrence = upper_bound - 1

---------------------------------------------------------
Time Complexity
O(log n)

Space Complexity
O(1)

=========================================================
*/

class Solution
{
public:

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();

        /*
        -------------------------------------------------
        Step 1 : Find the lower bound

        lower_bound returns iterator of first element
        >= target.

        To convert iterator to index we subtract
        nums.begin()
        -------------------------------------------------
        */

        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();


        /*
        -------------------------------------------------
        Step 2 : Check if target exists

        Two conditions when target does not exist:

        1) lb == n
           lower_bound points outside the array

        2) nums[lb] != target
           element found is not equal to target
        -------------------------------------------------
        */

        if (lb == n || nums[lb] != target)
        {
            return {-1, -1};
        }


        /*
        -------------------------------------------------
        Step 3 : Find upper bound

        upper_bound returns iterator of first element
        strictly greater than target.

        That means:
        the last occurrence of target = ub - 1
        -------------------------------------------------
        */

        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();


        /*
        -------------------------------------------------
        Step 4 : Return the answer

        first occurrence = lb
        last occurrence  = ub - 1
        -------------------------------------------------
        */

        return {lb, ub - 1};
    }
};


int main()
{
    Solution obj;

    vector<int> nums = {5,7,7,8,8,10};

    int target = 8;

    vector<int> result = obj.searchRange(nums, target);

    cout << "First Position : " << result[0] << endl;
    cout << "Last Position  : " << result[1] << endl;

    return 0;
}