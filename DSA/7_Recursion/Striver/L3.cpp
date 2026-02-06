#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

int factorial_Iterative(int X) {
    int ans = 1;
    for (int i = 1; i <= X; i++) {
        ans = ans * i;
    }
    return ans;
}

int factorial_Recursion(int n) {
    if (n <= 1) return 1;
    return n * factorial_Recursion(n-1);
}


int main() {
    
    return 0;
}