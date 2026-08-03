/*
    ==============================================================
    PERMUTATIONS OF AN ARRAY - 3 APPROACHES
    ==============================================================

    1) Brute Force (Using set to remove duplicates)
    2) Backtracking with used[] array
    3) Optimal In-Place Swapping (Best approach)

    NOTE:
    Time Complexity for all approaches = O(n!)
    Because there are n! permutations.

    Compile:
    g++ permutations.cpp -o perm
    Run:
    ./perm
*/

#include <bits/stdc++.h>
using namespace std;

/* ==============================================================
   1️⃣ BRUTE FORCE APPROACH
   --------------------------------------------------------------
   Idea:
   - Try every number at every position.
   - Use set<vector<int>> to automatically remove duplicates.
   - Very inefficient because:
       - count() is O(n)
       - set insertion is expensive
       - Extra memory usage
   ============================================================== */

void generateBrute(vector<int>& nums,
                    vector<int> path,
                    set<vector<int>>& result)
{
    // Base case: If permutation is complete
    if (path.size() == nums.size()) {
        result.insert(path);   // Insert into set
        return;
    }

    for (int i = 0; i < nums.size(); i++) {

        // Ensure we don't use an element more times than it appears
        if (count(path.begin(), path.end(), nums[i]) <
            count(nums.begin(), nums.end(), nums[i])) {

            path.push_back(nums[i]);
            generateBrute(nums, path, result);
            path.pop_back();  // backtrack
        }
    }
}

vector<vector<int>> permuteBrute(vector<int>& nums)
{
    set<vector<int>> result;
    vector<int> path;

    generateBrute(nums, path, result);

    return vector<vector<int>>(result.begin(), result.end());
}


/* ==============================================================
   2️⃣ BACKTRACKING WITH USED ARRAY (INTERVIEW STANDARD)
   --------------------------------------------------------------
   Idea:
   - Maintain a boolean used[] array
   - Pick unused element
   - Recurse
   - Undo choice
   ============================================================== */

void backtrackUsed(vector<int>& nums,
                   vector<bool>& used,
                   vector<int>& path,
                   vector<vector<int>>& result)
{
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            used[i] = true;           // mark used
            path.push_back(nums[i]);  // choose

            backtrackUsed(nums, used, path, result);

            path.pop_back();          // undo choice
            used[i] = false;          // unmark
        }
    }
}

vector<vector<int>> permuteBacktracking(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);

    backtrackUsed(nums, used, path, result);
    return result;
}


/* ==============================================================
   3️⃣ OPTIMAL IN-PLACE SWAPPING (BEST APPROACH)
   --------------------------------------------------------------
   Idea:
   - Fix one index at a time
   - Swap current index with every possible candidate
   - Recurse for remaining positions
   - Swap back (backtracking)

   Advantages:
   - No extra used[] array
   - No set
   - Minimal extra memory
   ============================================================== */

void backtrackSwap(int start,
                   vector<int>& nums,
                   vector<vector<int>>& result)
{
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {

        swap(nums[start], nums[i]);  // choose

        backtrackSwap(start + 1, nums, result);

        swap(nums[start], nums[i]);  // undo (backtrack)
    }
}

vector<vector<int>> permuteOptimal(vector<int>& nums)
{
    vector<vector<int>> result;
    backtrackSwap(0, nums, result);
    return result;
}


/* ==============================================================
   Helper Function to Print Result
   ============================================================== */

void printResult(const vector<vector<int>>& result)
{
    for (const auto& perm : result) {
        for (int num : perm)
            cout << num << " ";
        cout << endl;
    }
}


/* ==============================================================
   MAIN FUNCTION
   ============================================================== */

int main()
{
    vector<int> nums = {1, 2, 3};

    cout << "===== BRUTE FORCE =====" << endl;
    vector<vector<int>> brute = permuteBrute(nums);
    printResult(brute);

    cout << "\n===== BACKTRACKING (USED ARRAY) =====" << endl;
    vector<vector<int>> backtracking = permuteBacktracking(nums);
    printResult(backtracking);

    cout << "\n===== OPTIMAL (IN-PLACE SWAP) =====" << endl;
    vector<vector<int>> optimal = permuteOptimal(nums);
    printResult(optimal);

    return 0;
}