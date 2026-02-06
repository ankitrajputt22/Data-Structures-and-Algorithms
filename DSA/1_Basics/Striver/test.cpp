#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

int main() {
    newline2;

    cout << -1 % 3 << endl; 
    cout << (-1 + 3) % 3 << endl;
    cout << -8 % 3 << endl;
    int a = -8 % 3;
    int b = (a + 3) % 3;
    cout << "value of b is : " << b << endl;
    cout << "value of a is : " << a << endl;
    cout << -8 / 3 << endl;

    newline2;
    return 0;
}