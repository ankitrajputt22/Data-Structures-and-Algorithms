#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
============================================================
LeetCode 39 : Combination Sum
============================================================

Given:
An array of DISTINCT integers (candidates)
and a target integer.

Goal:
Return all UNIQUE combinations where numbers
sum to target.

Rules:
1. Same element can be chosen multiple times.
2. Order of combinations does not matter.

Example:
candidates = [2,3,6,7]
target = 7

Output:
[2,2,3]
[7]

============================================================
Approach Used:
Backtracking / Recursion

Idea:
For each number we have two choices

1) Pick the number
2) Skip the number

When we pick a number:
we stay at the same index because the number
can be used again.

When we skip:
we move to the next index.

============================================================
Time Complexity:
Exponential (depends on recursion tree)

Space Complexity:
O(target) recursion stack
============================================================
*/


class Solution
{
public:

    /*
    -------------------------------------------------------
    Recursive Helper Function
    -------------------------------------------------------

    Parameters:

    cand  -> candidate numbers
    target -> remaining target
    index  -> current index
    comb   -> current combination
    ans    -> result container

    -------------------------------------------------------
    */

    void helper(vector<int>& cand,
                int target,
                int index,
                vector<int>& comb,
                vector<vector<int>>& ans)
    {
        /*
        Base Case:
        If target becomes 0 → valid combination
        */
        if (target == 0)
        {
            ans.push_back(comb);
            return;
        }

        /*
        If index goes outside array
        */
        if (index == cand.size())
        {
            return;
        }

        /*
        --------------------------------------------------
        Choice 1 : Take the current element
        --------------------------------------------------
        We stay at the SAME index because we can reuse
        the same number multiple times.
        */
        if (cand[index] <= target)
        {
            comb.push_back(cand[index]);

            helper(cand,
                   target - cand[index],
                   index,
                   comb,
                   ans);

            // Backtracking step
            comb.pop_back();
        }

        /*
        --------------------------------------------------
        Choice 2 : Skip the element
        --------------------------------------------------
        Move to next index
        */
        helper(cand,
               target,
               index + 1,
               comb,
               ans);
    }



    /*
    -------------------------------------------------------
    Main Function
    -------------------------------------------------------
    */

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target)
    {
        vector<vector<int>> ans;
        vector<int> comb;

        helper(candidates,
               target,
               0,
               comb,
               ans);

        return ans;
    }
};



/*
============================================================
Second Implementation (Cleaner Version)
============================================================

Difference:
Base condition checks target first.
This version is slightly cleaner.

*/
class Solution2
{
public:

    void combinations(int index,
                      int target,
                      vector<int>& arr,
                      vector<int>& current,
                      vector<vector<int>>& ans)
    {

        // If target becomes zero we found a valid combination
        if (target == 0)
        {
            ans.push_back(current);
            return;
        }

        // If we reach end of array stop
        if (index == arr.size())
        {
            return;
        }

        /*
        ----------------------------------------------
        Pick the element
        ----------------------------------------------
        */

        if (arr[index] <= target)
        {
            current.push_back(arr[index]);

            combinations(index,
                         target - arr[index],
                         arr,
                         current,
                         ans);

            // Backtrack
            current.pop_back();
        }

        /*
        ----------------------------------------------
        Skip the element
        ----------------------------------------------
        */

        combinations(index + 1,
                     target,
                     arr,
                     current,
                     ans);
    }



    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target)
    {
        vector<vector<int>> ans;
        vector<int> current;

        combinations(0,
                     target,
                     candidates,
                     current,
                     ans);

        return ans;
    }
};



/*
============================================================
Utility function to print result
============================================================
*/

void printResult(vector<vector<int>> &res)
{
    cout << "Combinations:\n";

    for (auto &vec : res)
    {
        cout << "[ ";

        for (auto x : vec)
        {
            cout << x << " ";
        }

        cout << "]\n";
    }
}



/*
============================================================
Driver Code
============================================================
*/

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution obj;

    vector<vector<int>> result =
        obj.combinationSum(candidates, target);

    printResult(result);

    return 0;
}



