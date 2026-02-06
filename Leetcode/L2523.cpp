#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Solution_1 {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }

        return true;
    }
    
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }
        
        if (primes.size() < 2) return {-1, -1};
        
        int num1 = -1, num2 = -1;
        int minDiff = INT_MAX;
        
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                num1 = primes[i];
                num2 = primes[i + 1];
            }
        }
        
        return {num1, num2};
    }
};


//Approach-1 (Using Sieve Of Eratosthenes)
//T.C : O(Rlog(log(R)) + (R-L))
//S.C : O(R)
class Solution_2 {
public:
    vector<bool> sieveHelper(int right) {
        vector<bool> isPrime(right+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i*i <= right; i++) {
            if(isPrime[i] == true) {
                for(int j = 2; i*j <= right; j++) {
                    isPrime[i*j] = false;
                }
            }
        }

        return isPrime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = sieveHelper(right);

        vector<int> primes;
        for(int num = left; num <= right; num++) {
            if(isPrime[num] == true) {
                primes.push_back(num);
            }
        }

        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for(int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i-1];

            if(diff < minDiff) {
                minDiff = diff;
                result = {primes[i-1], primes[i]};
            }
        }

        return result;
    }
};


//Approach-2 (Using Sieve Of Eratosthenes)
//T.C : O((R-L) * sqrt(R))
//S.C : O(R-L)
class Solution {
public:
    bool isPrime(int num) {
        if(num == 1) { //not a prime
            return false;
        }
        for(int div = 2; div*div <= num; div++) {
            if(num % div == 0) {
                return false;
            }
        }

        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;

        for(int num = left; num <= right; num++) {
            if(isPrime(num) == true) {
                if(!primes.empty() && num - primes.back() <= 2) {
                    return {primes.back(), num}; //Early return
                }

                primes.push_back(num);
            }
        }


        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};
        for(int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i-1];
            if(diff < minDiff) {
                minDiff = diff;
                result = {primes[i-1], primes[i]};
            }
        }

        return result;
    }
};

int main() {
    
    return 0;
}