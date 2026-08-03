#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <unordered_set>

using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

/*
============================================================
LeetCode 46 : Permutations
============================================================

Goal:
Generate all possible permutations of given array.

Example:
nums = [1,2,3]

Output:
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]

Total permutations = n!

============================================================
*/

/*
============================================================
Approach 1 : Using unordered_set
============================================================

Idea:
Keep track of used elements using a set.

If element is not used → add it to permutation.

After recursion remove it (backtracking).

Time Complexity : O(n! * n)
Space Complexity : O(n)
*/

class Solution1
{
public:
    void solve(vector<int> &per,
               vector<vector<int>> &ans,
               vector<int> &nums,
               unordered_set<int> st)
    {
        int n = nums.size();

        if (per.size() == n)
        {
            ans.push_back(per);
            return;
        }

        for (int i = 0; i < n; i++)
        {

            if (st.find(nums[i]) == st.end())
            {

                per.push_back(nums[i]);
                st.insert(nums[i]);

                solve(per, ans, nums, st);

                st.erase(nums[i]);
                per.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<int> per;
        vector<vector<int>> ans;
        unordered_set<int> st;

        solve(per, ans, nums, st);

        return ans;
    }
};

/*
============================================================
Approach 2 : Using find() in vector
============================================================

Idea:
Check if element already exists in permutation.

If not → add it.

This approach is slower because find() is O(n).

Time Complexity : O(n! * n)
Space Complexity : O(n)
*/

class Solution2
{
public:
    void permutations(vector<int> &nums,
                      vector<int> &ds,
                      vector<vector<int>> &ans)
    {

        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {

            if (find(ds.begin(), ds.end(), nums[i]) == ds.end())
            {

                ds.push_back(nums[i]);

                permutations(nums, ds, ans);

                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<int> ds;
        vector<vector<int>> ans;

        permutations(nums, ds, ans);

        return ans;
    }
};

/*
============================================================
Approach 3 : Using Frequency Array
============================================================

Idea:
Use a visited array (freq).

freq[i] = 1 → element already used
freq[i] = 0 → element available

This is a common backtracking approach.

Time Complexity : O(n! * n)
Space Complexity : O(n)
*/

class Solution3
{

private:
    void recurPermute(vector<int> &ds,
                      vector<int> &nums,
                      vector<vector<int>> &ans,
                      int freq[])
    {

        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {

            if (!freq[i])
            {

                ds.push_back(nums[i]);
                freq[i] = 1;

                recurPermute(ds, nums, ans, freq);

                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> ds;

        int freq[nums.size()];

        for (int i = 0; i < nums.size(); i++)
            freq[i] = 0;

        recurPermute(ds, nums, ans, freq);

        return ans;
    }
};

/*
============================================================
Approach 4 : Swap Method (Most Optimal)
============================================================

Idea:
Fix one element at current position and permute the rest.

Example:
[1,2,3]

Fix 1 → permute [2,3]
Fix 2 → permute [1,3]
Fix 3 → permute [1,2]

This avoids extra space.

Time Complexity : O(n!)
Space Complexity : O(1) extra
*/

class Solution4
{
public:
    void generate(int index,
                  vector<int> &nums,
                  vector<vector<int>> &ans)
    {

        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {

            swap(nums[index], nums[i]);

            generate(index + 1, nums, ans);

            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;

        generate(0, nums, ans);

        return ans;
    }
};

/*
============================================================
Driver Code
============================================================
*/

int main()
{

    newline2;

    vector<int> nums = {1, 2, 3};

    Solution4 obj;

    vector<vector<int>> result = obj.permute(nums);

    cout << "Permutations:\n";

    for (auto &vec : result)
    {

        cout << "[ ";

        for (auto x : vec)
            cout << x << " ";

        cout << "]\n";
    }

    newline2;

    return 0;
}