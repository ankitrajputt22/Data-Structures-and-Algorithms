#include <iostream>
#include <vector>

using namespace std;

/*
=========================================================
LeetCode 77 : Combinations
=========================================================

Goal:
Generate all combinations of size k from numbers 1 to n.

Total combinations:
nCk = n! / (k! * (n-k)!)

Example:
n = 4, k = 2

Output:
[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]

=========================================================
*/

/*
=========================================================
Approach 1 : Brute Force (Subset Generation)
=========================================================

Idea:
Generate ALL subsets of array [1..n]
and pick only those whose size == k.

Steps:
1. Generate all subsets using recursion
2. Check size of subset
3. If size == k → store

Time Complexity:
O(2^n * n)

Space Complexity:
O(n)

---------------------------------------------------------
Intuition:
We try all possibilities (include/exclude each element)
→ This generates full power set
=========================================================
*/

class Solution1
{
public:
    void combinations(vector<int> &arr,
                      int ind,
                      vector<int> &com,
                      vector<vector<int>> &res,
                      int k)
    {
        // Base case: reached end
        if (ind == arr.size())
        {
            if (com.size() == k)
            {
                res.push_back(com);
            }
            return;
        }

        // Take element
        com.push_back(arr[ind]);
        combinations(arr, ind + 1, com, res, k);

        // Not take element
        com.pop_back();
        combinations(arr, ind + 1, com, res, k);
    }

    vector<vector<int>> combine(int n, int k)
    {

        vector<int> arr;

        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }

        vector<int> com;
        vector<vector<int>> res;

        combinations(arr, 0, com, res, k);

        return res;
    }
};

/*
=========================================================
Approach 2 : Backtracking (For Loop - Khandani)
=========================================================

Idea:
Instead of generating all subsets,
we directly build combinations of size k.

Steps:
1. Start from a number
2. Pick it
3. Move forward (i+1)
4. Stop when k elements are chosen

Time Complexity:
O(nCk * k)

Space Complexity:
O(k)

---------------------------------------------------------
Intuition:
We only explore valid combinations,
not all subsets → much faster than brute force
=========================================================
*/

class Solution2
{
public:
    vector<vector<int>> result;

    void solve(int start,
               int n,
               int k,
               vector<int> &temp)
    {
        // If k elements selected
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++)
        {

            temp.push_back(i);

            solve(i + 1, n, k - 1, temp);

            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k)
    {

        vector<int> temp;

        solve(1, n, k, temp);

        return result;
    }
};

/*
=========================================================
Approach 3 : Backtracking (Without Loop)
=========================================================

Idea:
At each number:
1. Take it
2. Skip it

Similar to subset recursion but with size control.

Time Complexity:
O(2^n)

Space Complexity:
O(n)

---------------------------------------------------------
Intuition:
Binary decision tree (take / not take)
=========================================================
*/

class Solution3
{
public:
    vector<vector<int>> result;

    void solve(int start,
               int n,
               int k,
               vector<int> &temp)
    {
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }

        if (start > n)
            return;

        // Take
        temp.push_back(start);
        solve(start + 1, n, k - 1, temp);

        // Not take
        temp.pop_back();
        solve(start + 1, n, k, temp);
    }

    vector<vector<int>> combine(int n, int k)
    {

        vector<int> temp;

        solve(1, n, k, temp);

        return result;
    }
};

/*
=========================================================
Approach 4 : Optimal (Pruning Optimization)
=========================================================

Idea:
Avoid unnecessary recursion using pruning.

If remaining elements are not enough to fill k,
we stop early.

Condition:
Remaining elements = (n - i + 1)

If remaining < k → stop

Time Complexity:
O(nCk)

Space Complexity:
O(k)

---------------------------------------------------------
Intuition:
Cut branches early → faster execution
=========================================================
*/

class Solution4
{
public:
    vector<vector<int>> result;

    void solve(int start,
               int n,
               int k,
               vector<int> &temp)
    {
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++)
        {

            // Pruning condition
            if ((n - i + 1) < k)
                break;

            temp.push_back(i);

            solve(i + 1, n, k - 1, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {

        vector<int> temp;

        solve(1, n, k, temp);

        return result;
    }
};

/*
=========================================================
Driver Code
=========================================================
*/

int main()
{

    int n = 4, k = 2;

    Solution4 obj;

    vector<vector<int>> res = obj.combine(n, k);

    cout << "Combinations:\n";

    for (auto &vec : res)
    {
        cout << "[ ";
        for (auto x : vec)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}

class Solution
{
public:
    void combinations(vector<int> &arr, int ind, vector<int> &com, vector<vector<int>> &res, int k)
    {
        if (ind == arr.size())
        {
            if (com.size() == k)
            {
                res.push_back(com);
            }
            return;
        }

        com.push_back(arr[ind]);
        combinations(arr, ind + 1, com, res, k);

        com.pop_back();
        combinations(arr, ind + 1, com, res, k);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> arr;
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }

        vector<int> com;
        vector<vector<int>> res;
        combinations(arr, 0, com, res, k);

        return res;
    }
};

// Khandani Approach of backtracking (Using for loop)
class Solution
{
public:
    vector<vector<int>> result;

    void solve(int start, int n, int k, vector<int> &temp)
    {
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            temp.push_back(i);
            solve(i + 1, n, k - 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;

        solve(1, n, k, temp);

        return result;
    }
};

// Khandani Backtracking Approach (without for loop)
class Solution
{
public:
    vector<vector<int>> result;

    void solve(int start, int n, int k, vector<int> &temp)
    {
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }

        if (start > n)
            return;

        temp.push_back(start);
        solve(start + 1, n, k - 1, temp);
        temp.pop_back();
        solve(start + 1, n, k, temp);
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;

        solve(1, n, k, temp);

        return result;
    }
};