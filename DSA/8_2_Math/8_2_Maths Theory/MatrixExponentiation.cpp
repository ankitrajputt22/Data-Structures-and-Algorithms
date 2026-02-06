#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Multiply two 2x2 matrices
vector<vector<ll>> multiply(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    vector<vector<ll>> C(2, vector<ll>(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

// Raise matrix A to power n using binary exponentiation
vector<vector<ll>> matrixExpo(vector<vector<ll>> A, ll n) {
    vector<vector<ll>> res = {{1, 0}, {0, 1}}; // Identity matrix

    while (n > 0) {
        if (n & 1)
            res = multiply(res, A);
        A = multiply(A, A);
        n >>= 1;
    }
    return res;
}

// Get nth Fibonacci
ll fib(ll n) {
    if (n == 0) return 0;
    vector<vector<ll>> F = {{1, 1}, {1, 0}};
    vector<vector<ll>> Fn = matrixExpo(F, n - 1);
    return Fn[0][0];
}

int main() {
    ll n;
    cout << "Enter n: ";
    cin >> n;
    cout << "F(" << n << ") = " << fib(n) << endl;
}
