#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

pair<int, int> firstLastDigit(int n) {
    n = abs(n);              // Handle negative numbers safely

    int lastDigit = n % 10;  // Last digit

    while (n >= 10) {        // Reduce number to first digit
        n /= 10;
    }

    int firstDigit = n;

    return {firstDigit, lastDigit};
}

int countDigits(int n) {
    n = abs(n);          // Handle negative numbers

    // Special case: if n is 0, it has 1 digit
    if (n == 0) return 1;

    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }

    return count;
}


int countDigits_usingLog(int n) {
    n = abs(n);              // Handle negative numbers

    // Special case: 0 has exactly 1 digit
    if (n == 0) return 1;

    return floor(log10(n)) + 1;
}


int reverseInteger(int n) {
    int rev = 0;

    while (n != 0) {
        int digit = n % 10;
        n /= 10;

        // Overflow check
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
            return 0;   // overflow case
        }

        rev = rev * 10 + digit;
    }

    return rev;
}



bool isPalindrome(int n) {
    // Negative numbers are NOT palindromes
    if (n < 0) return false;

    int original = n;
    int rev = 0;

    while (n > 0) {
        int digit = n % 10;
        n /= 10;

        // Optional overflow check (safe practice)
        if (rev > INT_MAX / 10) return false;

        rev = rev * 10 + digit;
    }

    return original == rev;
}



bool armstrongNumber(int n) {
    if (n < 0) return false;   // Negative numbers are not Armstrong

    int original = n;
    int digits = 0;
    int temp = n;

    // Count number of digits
    if (temp == 0) digits = 1;
    else {
        while (temp > 0) {
            digits++;
            temp /= 10;
        }
    }

    int sum = 0;
    temp = n;

    // Calculate sum of digits raised to power = digits
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}



/*
========================================================
        PRINT ALL DIVISORS OF A NUMBER (C++)
========================================================

A DIVISOR of a number 'n' is a number that divides 'n'
completely (remainder = 0).

Example:
n = 36
Divisors: 1 2 3 4 6 9 12 18 36

--------------------------------------------------------
METHOD 1: BRUTE FORCE APPROACH
--------------------------------------------------------
Idea:
- Check every number from 1 to n
- If i divides n, then i is a divisor

Time Complexity: O(n)
Space Complexity: O(1)

--------------------------------------------------------
METHOD 2: OPTIMAL APPROACH (Square Root Method)
--------------------------------------------------------
Idea:
- Divisors come in pairs: (i, n/i)
- We only need to check from 1 to sqrt(n)

Example:
n = 36
Pairs:
1 x 36
2 x 18
3 x 12
4 x 9
6 x 6

Time Complexity: O(√n)
Space Complexity: O(1)

IMPORTANT:
- For perfect squares, print sqrt(n) only once
========================================================
*/

/*
--------------------------------------------------------
BRUTE FORCE METHOD
--------------------------------------------------------
*/
void printDivisors_BruteForce(int n) {

    // Handle invalid or zero input
    if (n <= 0) {
        cout << "Invalid input" << endl;
        return;
    }

    // Check all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {   // If i divides n
            cout << i << " ";
        }
    }
    cout << endl;
}

/*
--------------------------------------------------------
OPTIMAL METHOD (O(sqrt(n)))
--------------------------------------------------------
*/
void printDivisors_Optimal(int n) {

    // Handle invalid or zero input
    if (n <= 0) {
        cout << "Invalid input" << endl;
        return;
    }

    vector<int> divisors;   // To store divisors in sorted order

    // Loop till square root of n
    for (int i = 1; i * i <= n; i++) {

        if (n % i == 0) {
            divisors.push_back(i);      // First divisor

            // Avoid duplicate for perfect square
            if (i != n / i) {
                divisors.push_back(n / i);  // Paired divisor
            }
        }
    }

    // Sort divisors to print in ascending order
    sort(divisors.begin(), divisors.end());

    // Print all divisors
    for (int d : divisors) {
        cout << d << " ";
    }
    cout << endl;
}


/*
========================================================
              CHECK PRIME NUMBER (C++)
========================================================

A PRIME NUMBER is a number greater than 1 that has
exactly two distinct divisors:
1 and the number itself.

Examples:
2, 3, 5, 7, 11 → Prime
1, 4, 6, 9, 10 → Not Prime

--------------------------------------------------------
METHOD 1: BRUTE FORCE APPROACH
--------------------------------------------------------
Idea:
- Count the number of divisors of n
- If divisors > 2 → Not Prime

Time Complexity: O(n)
Space Complexity: O(1)

--------------------------------------------------------
METHOD 2: OPTIMAL APPROACH (Square Root Method)
--------------------------------------------------------
Idea:
- If n has a divisor > sqrt(n),
  then it must have a divisor < sqrt(n)
- So we check divisibility only up to sqrt(n)

Time Complexity: O(√n)
Space Complexity: O(1)

IMPORTANT:
- Numbers ≤ 1 are NOT prime
========================================================
*/

/*
--------------------------------------------------------
BRUTE FORCE METHOD
--------------------------------------------------------
*/
bool isPrime_BruteForce(int n) {

    // Numbers <= 1 are not prime
    if (n <= 1) return false;

    int count = 0;

    // Count divisors from 1 to n
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }

    // Prime numbers have exactly 2 divisors
    return count == 2;
}

/*
--------------------------------------------------------
OPTIMAL METHOD (O(sqrt(n)))
--------------------------------------------------------
*/
bool isPrime_Optimal(int n) {

    // Numbers <= 1 are not prime
    if (n <= 1) return false;

    // Check divisibility up to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;   // Not prime
        }
    }

    return true;  // Prime
}


/*
========================================================
            GCD / HCF (Greatest Common Divisor)
========================================================

GCD (or HCF) of two numbers is the LARGEST number
that divides BOTH numbers completely.

Example:
a = 36, b = 24
Divisors of 36: 1 2 3 4 6 9 12 18 36
Divisors of 24: 1 2 3 4 6 8 12 24
GCD = 12

--------------------------------------------------------
APPROACH 1: BRUTE FORCE
--------------------------------------------------------
Idea:
- Check all numbers from 1 to min(a, b)
- Store the largest number that divides both

Time Complexity: O(min(a, b))
Space Complexity: O(1)

--------------------------------------------------------
APPROACH 2: BETTER (Reverse Loop)
--------------------------------------------------------
Idea:
- Start checking from min(a, b) down to 1
- First common divisor found is the GCD

Time Complexity: O(min(a, b))
Best Case: O(1)
Space Complexity: O(1)

--------------------------------------------------------
APPROACH 3: OPTIMAL (EUCLIDEAN ALGORITHM)
--------------------------------------------------------
Idea:
- gcd(a, b) = gcd(b, a % b)
- Repeat until b becomes 0

Time Complexity: O(log(min(a, b)))
Space Complexity: O(1)

IMPORTANT:
- Euclidean Algorithm is EXPECTED in interviews
========================================================
*/

/*
--------------------------------------------------------
BRUTE FORCE METHOD
--------------------------------------------------------
*/
int gcd_BruteForce(int a, int b) {

    int gcd = 1;

    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

/*
--------------------------------------------------------
BETTER METHOD (REVERSE LOOP)
--------------------------------------------------------
*/
int gcd_Better(int a, int b) {

    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;   // First common divisor is GCD
        }
    }

    return 1;
}

/*
--------------------------------------------------------
OPTIMAL METHOD (EUCLIDEAN ALGORITHM)
--------------------------------------------------------
*/
int gcd_Optimal(int a, int b) {

    // Euclidean Algorithm
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }

    return a;
}

int gcdOptimalRecur(int a, int b) {
    if (b == 0) return a;

    return gcdOptimalRecur(b, a % b);
}

int main() {
    
    
    return 0;
}