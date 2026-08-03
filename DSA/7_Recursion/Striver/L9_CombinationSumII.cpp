#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=====================================================
LeetCode 40 : Combination Sum II
=====================================================

Goal:
Find all unique combinations where numbers sum to target.

Rules:
1. Each element can be used only once.
2. The array may contain duplicates.
3. Result combinations must be unique.

Example:
candidates = [10,1,2,7,6,1,5]
target = 8

Output:
[1,1,6]
[1,2,5]
[1,7]
[2,6]

-----------------------------------------------------
Key Idea

1. Sort the array.
2. Use Backtracking.
3. Skip duplicates.

-----------------------------------------------------
*/


class Solution
{
public:

    /*
    -------------------------------------------------
    Recursive helper function
    -------------------------------------------------
    */

    void backtrack(int index,
                   int target,
                   vector<int>& candidates,
                   vector<int>& current,
                   vector<vector<int>>& ans)
    {

        /*
        If target becomes zero,
        we found a valid combination
        */
        if (target == 0)
        {
            ans.push_back(current);
            return;
        }


        /*
        Loop through remaining elements
        */
        for (int i = index; i < candidates.size(); i++)
        {

            /*
            Skip duplicates

            Example:
            [1,1,2]

            If first 1 already used at this level,
            skip the next 1.
            */

            if (i > index && candidates[i] == candidates[i - 1])
                continue;


            /*
            Stop if element becomes greater than target
            (array is sorted)
            */

            if (candidates[i] > target)
                break;


            /*
            Choose element
            */

            current.push_back(candidates[i]);


            /*
            Move to next index
            (because element cannot be reused)
            */

            backtrack(i + 1,
                      target - candidates[i],
                      candidates,
                      current,
                      ans);


            /*
            Backtracking step
            */

            current.pop_back();
        }
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target)
    {

        vector<vector<int>> ans;
        vector<int> current;


        /*
        Sorting is necessary
        to detect duplicates
        */

        sort(candidates.begin(), candidates.end());


        backtrack(0,
                  target,
                  candidates,
                  current,
                  ans);

        return ans;
    }
};



/*
-----------------------------------------------------
Utility function to print result
-----------------------------------------------------
*/

void printResult(vector<vector<int>>& res)
{
    cout << "Combinations:\n";

    for (auto& vec : res)
    {
        cout << "[ ";

        for (int x : vec)
        {
            cout << x << " ";
        }

        cout << "]\n";
    }
}



/*
-----------------------------------------------------
Driver Code
-----------------------------------------------------
*/

int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};

    int target = 8;

    Solution obj;

    vector<vector<int>> result =
        obj.combinationSum2(candidates, target);

    printResult(result);

    return 0;
}




#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
========================================================
LeetCode 40 : Combination Sum II
========================================================

Approach : Recursion + Set (TLE approach)

Idea:
Generate all subsets using recursion.
Whenever sum equals target, store the combination.

To remove duplicate combinations we use:
set<vector<int>>

However this approach causes TLE because:
1) It explores all subsets
2) set insertion is expensive

========================================================
*/


class Solution
{
public:

    /*
    ----------------------------------------------------
    Recursive helper function
    ----------------------------------------------------

    ind        -> current index
    candidates -> input array
    target     -> required sum
    s          -> current sum
    res        -> set to store unique combinations
    com        -> current combination
    */

    void helper(int ind,
                vector<int>& candidates,
                int target,
                int s,
                set<vector<int>>& res,
                vector<int>& com)
    {

        /*
        If current sum exceeds target,
        stop exploring this branch
        */

        if (s > target)
            return;


        /*
        If we reached target,
        store the combination
        */

        if (s == target)
        {
            res.insert(com);
            return;
        }


        /*
        If index goes outside array,
        stop recursion
        */

        if (ind >= candidates.size())
            return;



        /*
        ------------------------------------------------
        Choice 1 : Take the element
        ------------------------------------------------
        */

        com.push_back(candidates[ind]);

        helper(ind + 1,
               candidates,
               target,
               s + candidates[ind],
               res,
               com);



        /*
        ------------------------------------------------
        Choice 2 : Do not take the element
        ------------------------------------------------
        */

        com.pop_back();

        helper(ind + 1,
               candidates,
               target,
               s,
               res,
               com);
    }



    /*
    ----------------------------------------------------
    Main Function
    ----------------------------------------------------
    */

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target)
    {

        /*
        Sorting helps keep combinations ordered
        */

        sort(candidates.begin(), candidates.end());

        set<vector<int>> res;

        vector<int> com;


        helper(0,
               candidates,
               target,
               0,
               res,
               com);


        /*
        Convert set to vector
        */

        vector<vector<int>> result(res.begin(), res.end());

        return result;
    }
};











#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


// give tle
class Solution {
public:
    void helper(int ind, vector<int>& candidates, int target, int s, set<vector<int>> &res, vector<int> &com) {
        if (s > target) return;
        if (s == target) {
            res.insert(com);
            return;
        }
        if (ind >= candidates.size()) return;

        // take
        com.push_back(candidates[ind]);
        helper(ind + 1, candidates, target, s + candidates[ind], res, com);

        // not take
        com.pop_back();
        helper(ind + 1, candidates, target, s, res, com);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());   

        set<vector<int>> res;
        vector<int> com;

        helper(0, candidates, target, 0, res, com);

        vector<vector<int>> res2(res.begin(), res.end());
        return res2;
    }
};



class Solution2 {
public:
    // helper function to find combinations while ignoring the duplicates one
    void helper(vector<int>& cand, int tar, int ind, vector<vector<int>> &res, vector<int> &com) { 
        if (tar == 0) {
            res.push_back(com);
            return;
        }
        if (tar < 0 || ind >= cand.size()) {
            return;
        }

        for (int pick = ind; pick < cand.size(); pick++) {
            if (pick > ind && cand[pick] == cand[pick-1]) {
                continue;
            }
            if (cand[pick] > tar) {
                break;
            }

            com.push_back(cand[pick]);
            helper(cand, tar-cand[pick], pick+1, res, com);
            com.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());

        vector<int> com;
        vector<vector<int>> res;

        helper(candidates, target, 0, res, com);

        return res;
    }
};


class Solution3 {
public:
    void combinations(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(ds);  
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;

            if (arr[i] > target) break; 

            ds.push_back(arr[i]);  
            combinations(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  
        vector<vector<int>> ans;
        vector<int> ds;

        combinations(0, target, candidates, ds, ans);

        return ans;
    }
};


int main() {
    newline2;

    

    newline2;
    return 0;
}