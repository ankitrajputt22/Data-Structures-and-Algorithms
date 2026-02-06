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
