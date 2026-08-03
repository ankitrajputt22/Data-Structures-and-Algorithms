#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: RECURSION ON SUBSEQUENCES
   → PICK / NOT PICK PATTERN
===========================================================

-----------------------------------------------------------
🔹 WHAT IS A SUBSEQUENCE?
-----------------------------------------------------------

A subsequence is formed by deleting zero or more elements
without changing the order.

✔ Order matters:
   [3,2] is valid from [3,1,2]
   [2,3] is NOT valid

✔ Not necessarily contiguous:
   [1,3] is valid from [1,2,3]

-----------------------------------------------------------
🔹 TOTAL SUBSEQUENCES
-----------------------------------------------------------

For array size N:
👉 Total subsequences = 2^N

Reason:
Each element has 2 choices:
- Take
- Not take

===========================================================
🔴 PICK / NOT PICK PATTERN
===========================================================

At every index:
👉 Two choices:

1. PICK the element
2. NOT PICK the element

-----------------------------------------------------------
🧠 CORE TEMPLATE:
-----------------------------------------------------------

f(index, current_list)

Base Case:
if (index == n)
    print current_list
    return

Pick:
add element
call recursion
remove element (backtrack)

Not Pick:
call recursion

===========================================================
*/


/*
===========================================================
🔵 PRINT ALL SUBSEQUENCES
===========================================================

TIME: O(2^N * N)
SPACE: O(N)
*/

void printSubsequences(int index, vector<int>& ds,
                       vector<int>& arr, int n) {

    // Base Case
    if (index == n) {
        // print subsequence
        if (ds.empty()) cout << "{}";
        for (auto it : ds) cout << it << " ";
        cout << endl;
        return;
    }

    // PICK
    ds.push_back(arr[index]);
    printSubsequences(index + 1, ds, arr, n);

    // BACKTRACK (VERY IMPORTANT 🚨)
    ds.pop_back();

    // NOT PICK
    printSubsequences(index + 1, ds, arr, n);
}



/*
===========================================================
🧠 BACKTRACKING INTUITION
===========================================================

Trial Room Analogy:

👉 If you wear a shirt (pick element)
👉 You must remove it before trying another (not pick)

Otherwise:
❌ Wrong combinations will form

===========================================================
*/


/*
===========================================================
🟠 PRINT SUBSEQUENCES WITH SUM = K
===========================================================

VERY IMPORTANT VARIATION 🚀

Print all subsequences whose sum = K
*/

void printSubseqSumK(int index, vector<int>& ds,
                    int sum, int k,
                    vector<int>& arr, int n) {

    if (index == n) {
        if (sum == k) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }

    // PICK
    ds.push_back(arr[index]);
    sum += arr[index];

    printSubseqSumK(index + 1, ds, sum, k, arr, n);

    // BACKTRACK
    sum -= arr[index];
    ds.pop_back();

    // NOT PICK
    printSubseqSumK(index + 1, ds, sum, k, arr, n);
}



/*
===========================================================
🟡 PRINT ANY ONE SUBSEQUENCE WITH SUM = K
===========================================================

Optimization:
👉 Stop once one valid answer is found

Return type → bool
*/

bool printOneSubseqSumK(int index, vector<int>& ds,
                       int sum, int k,
                       vector<int>& arr, int n) {

    if (index == n) {
        if (sum == k) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // PICK
    ds.push_back(arr[index]);
    sum += arr[index];

    if (printOneSubseqSumK(index + 1, ds, sum, k, arr, n))
        return true;

    // BACKTRACK
    sum -= arr[index];
    ds.pop_back();

    // NOT PICK
    if (printOneSubseqSumK(index + 1, ds, sum, k, arr, n))
        return true;

    return false;
}



/*
===========================================================
🟢 COUNT SUBSEQUENCES WITH SUM = K
===========================================================

Return count instead of printing
*/

int countSubseqSumK(int index, int sum, int k,
                    vector<int>& arr, int n) {

    if (index == n) {
        return (sum == k);
    }

    // PICK
    sum += arr[index];
    int left = countSubseqSumK(index + 1, sum, k, arr, n);

    // BACKTRACK
    sum -= arr[index];

    // NOT PICK
    int right = countSubseqSumK(index + 1, sum, k, arr, n);

    return left + right;
}



/*
===========================================================
🧠 COMPLEXITY ANALYSIS
===========================================================

Time Complexity:
O(2^N * N)
- 2^N subsequences
- Each takes O(N) to print

Space Complexity:
O(N)
- Recursion stack depth

===========================================================
*/


/*
===========================================================
🔥 KEY TAKEAWAYS (VERY IMPORTANT)
===========================================================

✔ Every element → 2 choices
✔ Always BACKTRACK after PICK
✔ Forms recursion tree of size 2^N

-----------------------------------------------------------
🧠 PATTERN RECOGNITION:
-----------------------------------------------------------

If problem says:
- "All subsets"
- "All combinations"
- "Subsequence with condition"

👉 USE PICK / NOT PICK

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    vector<int> ds;

    cout << "All Subsequences:\n";
    printSubsequences(0, ds, arr, n);

    cout << "\nSubsequences with sum = 3:\n";
    printSubseqSumK(0, ds, 0, 3, arr, n);

    cout << "\nOne Subsequence with sum = 3:\n";
    printOneSubseqSumK(0, ds, 0, 3, arr, n);

    cout << "\nCount of subsequences with sum = 3:\n";
    cout << countSubseqSumK(0, 0, 3, arr, n) << endl;

    return 0;
}







#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";


//78. Subsets
// Power Set Algorithm
class Solution_1 { 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;

        vector<vector<int>> ans;

        for(int num = 0; num < subsets; num++) {
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};


// Recursive way to print subsets
class Solution_2 {
public:
    void solve(int ind, vector<int> &subset, vector<vector<int>> &ans, vector<int> &nums) {
        int n = nums.size();
        if (ind == n) {   
            for (auto &it : subset) {
                cout << it << " ";
            }         
            cout << endl;
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[ind]);
        solve(ind+1, subset, ans, nums);
        subset.pop_back();
        solve(ind+1, subset, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(0, subset, ans, nums);
        
        for (auto &subset : ans) {
            cout << "[ ";
            for (auto &val : subset) {
                cout << val << " ";
            }
            cout << "]";
            cout << endl;
        }

        return ans;
    }
};

vector<string> AllPossibleStrings(string s) {
    int n = s.length();
    vector<string> ans;

    for (int num = 0; num < (1 << n); num++) {
        string sub = "";
        for (int i = 0; i < n; i++) {
            if (num & (1 << i)) {
                sub += s[i];
            }
        }
        if (sub.length() > 0) {
            ans.push_back(sub);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    
    return 0;
}