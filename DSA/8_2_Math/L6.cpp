//204. Count Primes

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_BruteForce {
public:
    bool isPrime(int n) {
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) {
                cnt++;
                cout << i << " ";
            }
        }

        return cnt;
    }
};

class Solution_Better {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<int> prime(n, 1); 
        prime[0] = prime[1] = 0;

        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                for (int j = 2 * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }

        return accumulate(prime.begin(), prime.end(), 0);
    }
};


class Solution_Optimal {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<int> prime(n, 1); 
        prime[0] = prime[1] = 0;

        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }

        return accumulate(prime.begin(), prime.end(), 0);
    }
};


int main() {
    
    return 0;
}