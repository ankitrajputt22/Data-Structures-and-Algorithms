#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: SUBSET SUM I
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

Given an array of N integers,
👉 Return ALL subset sums in increasing order

-----------------------------------------------------------
🧠 KEY FACT:
-----------------------------------------------------------

Total subsets = 2^N

Each subset → contributes one sum

===========================================================
🔴 APPROACH 1: BRUTE FORCE (BIT MANIPULATION)
===========================================================

Idea:
- Use bitmask from 0 → (2^N - 1)
- Each bit represents pick/not pick

TIME:
O(2^N * N)

-----------------------------------------------------------
*/

vector<int> subsetSums_bruteforce(vector<int>& arr) {
    int n = arr.size();
    vector<int> res;

    int total = (1 << n); // 2^n

    for (int mask = 0; mask < total; mask++) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }

        res.push_back(sum);
    }

    sort(res.begin(), res.end());
    return res;
}



/*
===========================================================
🟢 APPROACH 2: RECURSION (OPTIMAL / INTERVIEW)
===========================================================

CORE IDEA:
👉 Pick / Not Pick

-----------------------------------------------------------
RECURSION:
-----------------------------------------------------------

f(index, sum)

Base Case:
if index == n:
    store sum

Pick:
add arr[index]

Not Pick:
skip arr[index]

===========================================================
*/

void solve(int index, int sum,
           vector<int>& arr,
           vector<int>& ans) {

    // Base Case
    if (index == arr.size()) {
        ans.push_back(sum);
        return;
    }

    // PICK
    solve(index + 1, sum + arr[index], arr, ans);

    // NOT PICK
    solve(index + 1, sum, arr, ans);
}

vector<int> subsetSums(vector<int>& arr) {
    vector<int> ans;

    solve(0, 0, arr, ans);

    sort(ans.begin(), ans.end()); // required

    return ans;
}



/*
===========================================================
🧠 DRY RUN
===========================================================

arr = [1,2]

Subsets:
{}
{1}
{2}
{1,2}

Sums:
0,1,2,3

===========================================================
*/


/*
===========================================================
🧠 COMPLEXITY ANALYSIS
===========================================================

Time:
O(2^N) → generate subsets
O(2^N log(2^N)) → sorting

Total:
O(2^N log(2^N))

Space:
O(2^N) → store sums
O(N) → recursion stack

===========================================================
*/


/*
===========================================================
🔥 KEY TAKEAWAYS
===========================================================

✔ Classic PICK / NOT PICK problem
✔ Always store result at base case
✔ Sorting required at end

-----------------------------------------------------------
🧠 INTERVIEW INSIGHT:
-----------------------------------------------------------

If question says:
👉 "All subset sums"
👉 "Power set + sum"

Think:
👉 Recursion (Pick / Not Pick)

===========================================================
*/


/*
===========================================================
🧩 RELATED PROBLEMS
===========================================================

- Subset Sum II (with duplicates)
- Combination Sum
- Partition Equal Subset Sum (DP)
- Target Sum (DP)

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<int> arr = {1, 2, 3};

    vector<int> result = subsetSums(arr);

    cout << "Subset Sums:\n";

    for (int x : result) cout << x << " ";

    cout << endl;

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
  public:
    void helper(int i, int sum, vector<int> &arr, vector<int> &res) {
        if (i == arr.size()) {
            res.push_back(sum);
            return;
        }
        
        helper(i+1, sum+arr[i], arr, res);
        helper(i+1, sum, arr, res);
    }
  
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        helper(0, 0, arr, res);
        
        return res;
    }
};