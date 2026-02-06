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
