#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

int nCr(int n, int r) {
    int res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n-i);
        res = res / (i+1);
    }

    return res;
}

int elPascal(int r, int c) {
    return nCr(r-1, c-1);
}

void printNthRow(int n) { // n is 1 based indexing
    for (int c = 1; c <= n; c++) {
        cout << nCr(n-1, c-1) << " ";
    }
    cout << endl;
}

void printNthRow_Optimal(int n) { // n is 0 based indexing
    int ans = 1;
    cout << ans << " "; // First element is always 1
    
    for (int i = 1; i <= n; i++) { // Loop should run n times (for n+1 elements)
        ans = ans * (n - i + 1) / i;
        cout << ans << " ";
    }
    cout << endl;
}


class Solution_1 {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) { // 0 based indexing
            vector<int> row;
            int a = 1;
            row.push_back(a);
            
            for (int j = 1; j <= i; j++) {
                a = a * (i - j + 1) / j; 
                row.push_back(a);
            }
            
            ans.push_back(row);
        }
        return ans;
    }
};

class Solution_2 {
public:
    int nCr(int n, int r) {
        int ans = 1;
        for (int i = 0; i < r; i++) {
            ans = ans * (n - i);
            ans = ans / (i+1);
        }   

        return ans;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> row;

            for (int j = 0; j <= i; j++) {
                row.push_back(nCr(i, j));
            }

            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
    newline1;

    for (int i = 0; i < 6; i++) {
        printNthRow(i);
    }
    newline2;

    for (int i = 0; i < 6; i++) {
        printNthRow_Optimal(i);
    }
    
    return 0;
}