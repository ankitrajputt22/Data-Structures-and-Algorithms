#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: PERMUTATIONS (SWAPPING TECHNIQUE)
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

Given an array (or string), generate all possible permutations.

Example:
Input: [1,2,3]

Output:
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,2,1]
[3,1,2]

===========================================================
🔴 CORE IDEA: SWAPPING + BACKTRACKING
===========================================================

Instead of using extra arrays (visited/map),
we modify the given array itself.

-----------------------------------------------------------
🧠 LOGIC:
-----------------------------------------------------------

At each index:
👉 Try every possible element for that position

FOR i = index → n-1:
    swap(index, i)
    recurse for next index
    backtrack (swap back)

-----------------------------------------------------------
WHY SWAP?
-----------------------------------------------------------

To bring a new element to the current position

===========================================================
*/


/*
===========================================================
🔵 MAIN FUNCTION
===========================================================

Parameters:
- index → current position
- nums → array
- ans → result

-----------------------------------------------------------
BASE CASE:
-----------------------------------------------------------

if (index == n):
    store permutation

===========================================================
*/

void solve(int index, vector<int>& nums,
           vector<vector<int>>& ans) {

    // Base Case
    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {

        // STEP 1: SWAP
        swap(nums[index], nums[i]);

        // STEP 2: RECURSE
        solve(index + 1, nums, ans);

        // STEP 3: BACKTRACK (VERY IMPORTANT 🚨)
        swap(nums[index], nums[i]);
    }
}



/*
===========================================================
🟢 DRIVER FUNCTION
===========================================================
*/

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    solve(0, nums, ans);
    return ans;
}



/*
===========================================================
🧠 DRY RUN (IMPORTANT)
===========================================================

nums = [1,2,3]

index = 0:
    swap(0,0) → [1,2,3]
    swap(0,1) → [2,1,3]
    swap(0,2) → [3,2,1]

Each branch explores all permutations

===========================================================
*/


/*
===========================================================
🧠 BACKTRACKING (MOST IMPORTANT)
===========================================================

After recursion:
👉 Restore original array

WHY?
👉 So next iteration starts fresh

Without backtracking:
❌ Wrong permutations

===========================================================
*/


/*
===========================================================
🧠 COMPLEXITY ANALYSIS
===========================================================

Time Complexity:
O(N! * N)
- N! permutations
- O(N) to copy each

Space Complexity:
O(N)
- recursion stack

===========================================================
*/


/*
===========================================================
🔥 APPROACH COMPARISON
===========================================================

| Approach              | Extra Space | Idea                |
|----------------------|------------|---------------------|
| Using visited array  | O(N)       | Track used elements |
| Swapping method      | O(1)       | Modify array        |

-----------------------------------------------------------
🧠 CONCLUSION:
-----------------------------------------------------------

✔ Swapping is more space efficient
✔ Most preferred in interviews

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = permute(nums);

    cout << "Permutations:\n";

    for (auto &vec : result) {
        cout << "[ ";
        for (auto x : vec) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}




#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

int main() {
    newline2;

    

    newline2;
    return 0;
}


class Solution {
private:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]); // backtrack
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};
