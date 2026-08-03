#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
📌 LECTURE: K-th PERMUTATION SEQUENCE
===========================================================

-----------------------------------------------------------
🔹 PROBLEM
-----------------------------------------------------------

Given:
- N → numbers from 1 to N
- K → find Kth permutation (1-based index)

Example:
N = 3

Permutations:
123
132
213  ← K=3
231
312
321

Answer = "213"

===========================================================
🔴 BRUTE FORCE APPROACH
===========================================================

Generate all permutations → sort → pick Kth

TIME:
O(N! * N)

SPACE:
O(N! * N)

❌ Not feasible for large N

===========================================================
🟢 OPTIMAL APPROACH (MATHEMATICS)
===========================================================

-----------------------------------------------------------
🔹 CORE IDEA: FACTORIAL BLOCKS
-----------------------------------------------------------

For N numbers:
Total permutations = N!

Each number repeats in blocks of (N-1)!

Example:
N = 4 → 4! = 24 permutations

Each starting digit appears:
(4-1)! = 6 times

1 → 6 perms
2 → 6 perms
3 → 6 perms
4 → 6 perms

-----------------------------------------------------------
🧠 KEY FORMULA:
-----------------------------------------------------------

index = k / fact

k = k % fact

===========================================================
*/


/*
===========================================================
🔵 OPTIMAL FUNCTION
===========================================================
*/

string getPermutation(int n, int k) {

    vector<int> numbers;
    int fact = 1;

    // Build factorial and numbers list
    for (int i = 1; i < n; i++) {
        fact *= i;
        numbers.push_back(i);
    }
    numbers.push_back(n);

    string ans = "";

    // Convert to 0-based index
    k = k - 1;

    while (true) {

        // Select element
        ans += to_string(numbers[k / fact]);

        // Remove used element
        numbers.erase(numbers.begin() + k / fact);

        // Break condition
        if (numbers.empty()) break;

        // Update k
        k = k % fact;

        // Update factorial
        fact = fact / numbers.size();
    }

    return ans;
}



/*
===========================================================
🧠 DRY RUN (VERY IMPORTANT)
===========================================================

N = 4, K = 17

Convert to 0-based:
k = 16

numbers = [1,2,3,4]
fact = 3! = 6

Step 1:
index = 16 / 6 = 2 → pick 3
k = 16 % 6 = 4
numbers = [1,2,4]

Step 2:
fact = 2! = 2
index = 4 / 2 = 2 → pick 4
k = 4 % 2 = 0
numbers = [1,2]

Step 3:
fact = 1
index = 0 → pick 1
numbers = [2]

Step 4:
pick 2

Answer = 3412

===========================================================
*/


/*
===========================================================
🧠 COMPLEXITY ANALYSIS
===========================================================

Time Complexity:
O(N^2)
- N steps
- Each erase → O(N)

Space Complexity:
O(N)

===========================================================
*/


/*
===========================================================
🔥 KEY TAKEAWAYS (VERY IMPORTANT 🚨)
===========================================================

✔ Use factorial to skip blocks
✔ Convert K → 0-based index
✔ Maintain list of available numbers
✔ Remove element after using

-----------------------------------------------------------
🧠 INTERVIEW INSIGHT:
-----------------------------------------------------------

If problem says:
👉 "Kth permutation / sequence"

Think:
👉 FACTORIAL NUMBER SYSTEM

===========================================================
*/


/*
===========================================================
🚀 DRIVER CODE
===========================================================
*/

int main() {

    int n = 4, k = 17;

    cout << "K-th Permutation: "
         << getPermutation(n, k) << endl;

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
    void permutations(vector<int> &ds, vector<vector<int>> &ans, int n) {
        if (ds.size() == n) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (find(ds.begin(), ds.end(), i+1) == ds.end()) {
                ds.push_back(i+1);

                permutations(ds, ans, n);
                ds.pop_back();
            }
        }
    }

    string getPermutation(int n, int k) {
        vector<int> per;
        vector<vector<int>> ans;

        permutations(per, ans, n);
        for (auto per : ans) {
            cout << "[ ";
            for (auto el : per) {
                cout << el << " ";
            }
            cout << "] ";
        }

        string res;
        for (auto el : ans[k-1]) {
            res += to_string(el);
        }
        return res;
    }
};





class Solution {
public:
    int fact(int n) {
        if (n == 0) return 1;
        return n * fact(n-1);
    }

    void permutation(vector<int> &nums, int k, string &res) {
        if (k == 0) {
            for (int i = 0; i < nums.size(); i++) {
                res += to_string(nums[i]);
            }

            return;
        }

        int n = nums.size();
        int ind = k / fact(n-1);

        res += to_string(nums[ind]);
        nums.erase(nums.begin() + ind);

        k = k - ind * fact(n-1);
        permutation(nums, k, res);
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        string res;
        permutation(nums, k-1, res);

        return res;
    }
};




class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;

        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k = k - 1;

        while (true) {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);

            if (numbers.size() == 0) {
                break;
            }

            k = k % fact;
            fact = fact / numbers.size();
        }

        return ans;
    }
};
