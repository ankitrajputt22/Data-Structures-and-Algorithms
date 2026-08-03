#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: SUBSEQUENCE PATTERNS (TAKE / NOT TAKE)
===========================================================

-----------------------------------------------------------
🔹 CORE IDEA: TAKE / NOT TAKE
-----------------------------------------------------------

At every index, we have TWO choices:

1. TAKE (Pick the element)
2. NOT TAKE (Skip the element)

This creates:
👉 2^N subsequences

-----------------------------------------------------------
🧠 RECURSION STRUCTURE:
-----------------------------------------------------------

f(index, ds, sum)

Base Case:
if (index == n)
    check condition
    return

Take:
include element → move forward

Backtrack:
remove element

Not Take:
skip element → move forward

===========================================================
*/


/*
===========================================================
🔴 PATTERN 1: PRINT ALL SUBSEQUENCES WITH SUM = K
===========================================================

Return Type: void

WHY?
👉 We want ALL answers

-----------------------------------------------------------
LOGIC:
-----------------------------------------------------------

- Carry:
  index, current list, current sum

- At base case:
  if sum == K → print

TIME: O(2^N * N)
*/

void printAll(int index, vector<int>& ds, int sum,
              int k, vector<int>& arr, int n) {

    if (index == n) {
        if (sum == k) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }

    // TAKE
    ds.push_back(arr[index]);
    sum += arr[index];

    printAll(index + 1, ds, sum, k, arr, n);

    // BACKTRACK
    sum -= arr[index];
    ds.pop_back();

    // NOT TAKE
    printAll(index + 1, ds, sum, k, arr, n);
}



/*
===========================================================
🟠 PATTERN 2: PRINT ONLY ONE SUBSEQUENCE
===========================================================

Return Type: bool

WHY?
👉 Stop recursion once one answer is found

-----------------------------------------------------------
KEY IDEA:
-----------------------------------------------------------

If any branch returns TRUE → stop everything

-----------------------------------------------------------
FLOW:
-----------------------------------------------------------

if (take branch returns true) → return true
if (not take returns true) → return true
else → return false

===========================================================
*/

bool printOne(int index, vector<int>& ds, int sum,
              int k, vector<int>& arr, int n) {

    if (index == n) {
        if (sum == k) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // TAKE
    ds.push_back(arr[index]);
    sum += arr[index];

    if (printOne(index + 1, ds, sum, k, arr, n))
        return true;

    // BACKTRACK
    sum -= arr[index];
    ds.pop_back();

    // NOT TAKE
    if (printOne(index + 1, ds, sum, k, arr, n))
        return true;

    return false;
}



/*
===========================================================
🟡 PATTERN 3: COUNT ALL SUBSEQUENCES WITH SUM = K
===========================================================

Return Type: int

WHY?
👉 Count total number of valid subsequences

-----------------------------------------------------------
LOGIC:
-----------------------------------------------------------

Base Case:
if sum == k → return 1
else → return 0

Recursive:
return left + right

===========================================================
*/

int countAll(int index, int sum, int k,
             vector<int>& arr, int n) {

    if (index == n) {
        return (sum == k);
    }

    // TAKE
    sum += arr[index];
    int left = countAll(index + 1, sum, k, arr, n);

    // BACKTRACK
    sum -= arr[index];

    // NOT TAKE
    int right = countAll(index + 1, sum, k, arr, n);

    return left + right;
}



/*
===========================================================
🧠 RETURN TYPE STRATEGY (VERY IMPORTANT 🚨)
===========================================================

| Goal                          | Return Type |
|-------------------------------|------------|
| Print all answers             | void       |
| Print only one answer         | bool       |
| Count number of answers       | int        |

-----------------------------------------------------------
🧠 GOLDEN RULE:
-----------------------------------------------------------

👉 Return type depends on WHAT problem asks

===========================================================
*/


/*
===========================================================
🧠 COMPLEXITY
===========================================================

Time: O(2^N)
Space: O(N) recursion stack

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    vector<int> arr = {1, 2, 1};
    int n = arr.size();
    int k = 2;

    vector<int> ds;

    cout << "All Subsequences with sum = " << k << ":\n";
    printAll(0, ds, 0, k, arr, n);

    cout << "\nOne Subsequence with sum = " << k << ":\n";
    printOne(0, ds, 0, k, arr, n);

    cout << "\nCount of subsequences with sum = " << k << ":\n";
    cout << countAll(0, 0, k, arr, n) << endl;

    return 0;
}




#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

// ===================================================================
// 1. Print ALL subsequences whose sum = K
// ===================================================================
void printAllSubsequences(int i, vector<int> &subseq, int s, int sum, vector<int> &nums) {
    int n = nums.size();

    if (i == n) {
        if (s == sum) {
            for (auto it : subseq) cout << it << " ";
            cout << "\n";
        }
        return;
    }

    // Pick
    subseq.push_back(nums[i]);
    s += nums[i];
    printAllSubsequences(i + 1, subseq, s, sum, nums);

    // Not pick
    s -= nums[i];
    subseq.pop_back();
    printAllSubsequences(i + 1, subseq, s, sum, nums);
}


// ===================================================================
// 2. Print ONLY ONE subsequence whose sum = K
// ===================================================================
bool printOneSubsequence(int i, vector<int> &subseq, int s, int sum, vector<int> &nums) {
    int n = nums.size();

    if (i == n) {
        if (s == sum) {
            for (auto it : subseq) cout << it << " ";
            cout << "\n";
            return true;
        }
        return false;
    }

    // Pick
    subseq.push_back(nums[i]);
    s += nums[i];
    if (printOneSubsequence(i + 1, subseq, s, sum, nums)) 
        return true;

    // Not pick
    s -= nums[i];
    subseq.pop_back();
    if (printOneSubsequence(i + 1, subseq, s, sum, nums))
        return true;

    return false;
}


// ===================================================================
// 3. Count ALL subsequences whose sum = K
// ===================================================================
int countSubsequences(int i, int s, int sum, vector<int> &nums) {
    int n = nums.size();

    if (i == n) {
        return (s == sum) ? 1 : 0;
    }

    // Pick
    int left = countSubsequences(i + 1, s + nums[i], sum, nums);

    // Not pick
    int right = countSubsequences(i + 1, s, sum, nums);

    return left + right;
}


// ===================================================================
// MAIN FUNCTION WITH PROPER EXAMPLES
// ===================================================================
int main() {
    newline2;

    vector<int> nums = {1, 2, 1};
    int targetSum = 2;

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nTarget Sum = " << targetSum << "\n\n";

    // --------------------------------------------------------
    cout << "1️⃣  All subsequences with sum = " << targetSum << ":\n";
    vector<int> subseq1;
    printAllSubsequences(0, subseq1, 0, targetSum, nums);

    newline2;

    // --------------------------------------------------------
    cout << "2️⃣  Only ONE subsequence with sum = " << targetSum << ":\n";
    vector<int> subseq2;
    bool found = printOneSubsequence(0, subseq2, 0, targetSum, nums);
    if (!found) cout << "No valid subsequence found\n";

    newline2;

    // --------------------------------------------------------
    cout << "3️⃣  Count of subsequences with sum = " << targetSum << ":\n";
    int count = countSubsequences(0, 0, targetSum, nums);
    cout << "Total = " << count << "\n";

    newline2;

    return 0;
}
