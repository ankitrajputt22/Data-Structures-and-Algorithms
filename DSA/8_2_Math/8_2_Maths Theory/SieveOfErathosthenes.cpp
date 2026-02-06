#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPrime_2(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}


vector<bool> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    return isPrime;
}

vector<bool> sieveOfEratosthenes_2(int n) {
    if (n < 2) return vector<bool>(n + 1, false);
    
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    isPrime[2] = true;
    
    // Mark even numbers except 2 as false
    for (int i = 4; i <= n; i += 2) {
        isPrime[i] = false;
    }
    
    // Check only odd numbers
    for (int i = 3; i * i <= n; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                isPrime[j] = false;
            }
        }
    }
    
    return isPrime;
}

vector<int> getPrimes(int n) {
    vector<bool> sieve = sieveOfEratosthenes(n);
    vector<int> primes;
    
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main() {
    newline1;
    int n = 30;
    vector<bool> isPrime = sieveOfEratosthenes(n);
    
    cout << "Primes up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    // Output: 2 3 5 7 11 13 17 19 23 29

    newline2;
    return 0;
}
