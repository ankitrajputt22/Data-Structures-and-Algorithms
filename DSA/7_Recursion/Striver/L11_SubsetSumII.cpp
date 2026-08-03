#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: SUBSET SUM II (UNIQUE SUBSETS)
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

Given an array (may contain duplicates),
👉 Return all UNIQUE subsets

Example:
Input: [1,2,2]

Output:
[]
[1]
[2]
[1,2]
[2,2]
[1,2,2]

-----------------------------------------------------------
⚠️ CHALLENGE
-----------------------------------------------------------

Duplicates cause repeated subsets:
[1,2] can appear multiple times ❌

We must AVOID duplicates efficiently

===========================================================
🔴 NAIVE APPROACH (NOT OPTIMAL)
===========================================================

- Generate all subsets (2^N)
- Store in set to remove duplicates

TIME:
O(2^N * N log(2^N)) ❌

===========================================================
🟢 OPTIMAL APPROACH (IMPORTANT)
===========================================================

-----------------------------------------------------------
🔹 KEY IDEA:
-----------------------------------------------------------

👉 Use LOOP instead of pick/not pick
👉 Skip duplicates during recursion

-----------------------------------------------------------
🔹 STEP 1: SORT ARRAY
-----------------------------------------------------------

WHY?
👉 Duplicates become adjacent

Example:
[1,2,2]

===========================================================
🔹 STEP 2: LOOP-BASED RECURSION
===========================================================

At each level:
👉 Generate subsets of different sizes

-----------------------------------------------------------
🔹 STEP 3: SKIP DUPLICATES
-----------------------------------------------------------

Condition:

if (i > index && nums[i] == nums[i-1])
    continue;

-----------------------------------------------------------
🧠 MEANING:
-----------------------------------------------------------

- Skip duplicate elements ONLY at SAME level
- Allow duplicates across different levels

===========================================================
*/


/*
===========================================================
🔵 MAIN FUNCTION
===========================================================
*/

void solve(int index,
           vector<int>& nums,
           vector<int>& ds,
           vector<vector<int>>& ans) {

    // Every call is a valid subset
    ans.push_back(ds);

    for (int i = index; i < nums.size(); i++) {

        // SKIP DUPLICATES (VERY IMPORTANT 🚨)
        if (i > index && nums[i] == nums[i - 1])
            continue;

        // PICK
        ds.push_back(nums[i]);

        solve(i + 1, nums, ds, ans);

        // BACKTRACK
        ds.pop_back();
    }
}



/*
===========================================================
🟢 DRIVER FUNCTION
===========================================================
*/

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> ds;

    // STEP 1: SORT
    sort(nums.begin(), nums.end());

    solve(0, nums, ds, ans);

    return ans;
}



/*
===========================================================
🧠 DRY RUN
===========================================================

nums = [1,2,2]

Sorted → [1,2,2]

Level 0:
[]

Level 1:
[1], [2]

Level 2:
[1,2], [2,2]

Level 3:
[1,2,2]

Duplicate [2] avoided ✔

===========================================================
*/


/*
===========================================================
🧠 COMPLEXITY ANALYSIS
===========================================================

Time:
O(2^N * N)

Space:
O(2^N * K) → store subsets
O(N) → recursion stack

===========================================================
*/


/*
===========================================================
🔥 KEY TAKEAWAYS (VERY IMPORTANT 🚨)
===========================================================

✔ Always SORT first
✔ Use LOOP instead of binary recursion
✔ Skip duplicates using:
   if (i > index && nums[i] == nums[i-1])

-----------------------------------------------------------
🧠 INTERVIEW INSIGHT:
-----------------------------------------------------------

If input has duplicates:
👉 NEVER use plain pick/not pick

Instead:
👉 Use loop + skip duplicates

===========================================================
*/


/*
===========================================================
🧩 PATTERN COMPARISON
===========================================================

| Problem              | Technique                |
|---------------------|--------------------------|
| Subset Sum I        | Pick / Not Pick          |
| Subset Sum II       | Loop + Skip duplicates   |
| Combination Sum     | Stay on same index       |
| Permutations        | Swapping                 |

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = subsetsWithDup(nums);

    cout << "Unique Subsets:\n";

    for (auto &vec : result) {
        cout << "[ ";
        for (auto x : vec) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}



#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

int main() {
    newline2;

    

    newline2;
    return 0;
}


// Brute force
class Solution {
public:
    void subsets(vector<int> &nums, int i, vector<int> sub, set<vector<int>> &res) {
        if (i >= nums.size()) {
            // sort(sub.begin(), sub.end());
            res.insert(sub);
            return;
        }

        sub.push_back(nums[i]);
        subsets(nums, i+1, sub, res);

        sub.pop_back();
        subsets(nums, i+1, sub, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> res;
        vector<int> sub;

        subsets(nums, 0, sub, res);
        vector<vector<int>> ans(res.begin(), res.end());

        return ans;
    }
};



// optimal solution
class Solution {
public:
    void find_subsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        ans.push_back(ds);

        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;

            ds.push_back(nums[i]);
            find_subsets(i + 1, nums, ds, ans);

            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());

        find_subsets(0, nums, ds, ans);
        
        return ans;
    }
};