#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

void swapNumbers(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "After swapNumbers: a = " << a << ", b = " << b << endl;
}

void swapNumbers2(int a, int b) {
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After swapNumbers2: a = " << a << ", b = " << b << endl;
}

void swapNumbersBitMani(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "After swapNumbersBitMani: a = " << a << ", b = " << b << endl;
}


bool checkIthBitIsSet(int n, int i) {
    return (n & (1 << i)) != 0;
}


/*
====================================================
SETTING THE i-th BIT — NOTES
====================================================

🔹 What does it mean to set the i-th bit?
----------------------------------------
Setting the i-th bit means:
- If the bit is 0 → make it 1
- If the bit is already 1 → keep it 1

----------------------------------------------------
BITWISE IDEA
----------------------------------------------------
We use the bitwise OR ( | ) operator.

Expression:
n | (1 << i)

Explanation:
- (1 << i) creates a number where only the i-th bit is 1
- OR operation ensures the i-th bit in n becomes 1

----------------------------------------------------
Example:
n = 10 (1010 in binary)
i = 1

1 << 1 = 0010
1010 | 0010 = 1010  → result = 10

----------------------------------------------------
Time Complexity: O(1)
Space Complexity: O(1)
====================================================
*/

int setIthBit(int n, int i) {
    return n | (1 << i);
}

/*
🔹 Step-by-Step Explanation
Step 1: Convert decimal to binary
Repeatedly divide the number by 2
Store remainders (0 or 1) as characters

Step 2: Ensure i-th position exists
If the binary string is shorter than i + 1, append '0's

Step 3: Set the i-th bit
Directly assign '1' at index i (0-based from LSB)

Step 4: Convert binary back to decimal
Traverse from right to left
Multiply each bit by powers of 2
Add to result

*/

int setIthBitBruteForce(int n, int i) {
    string binary = "";

    // Step 1: Convert decimal to binary (LSB first)
    while (n > 0) {
        binary += char((n % 2) + '0');
        n /= 2;
    }

    // Step 2: Make sure the binary string is long enough
    while ((int)binary.size() <= i) {
        binary += '0';
    }

    // Step 3: Set the i-th bit
    binary[i] = '1';

    // Step 4: Convert binary back to decimal
    int result = 0;
    int power = 1;
    for (int j = 0; j < binary.size(); j++) {
        if (binary[j] == '1')
            result += power;
        power *= 2;
    }

    return result;
}


int clearIthBitBruteForce(int n, int i) {
    string binary = "";

    // Convert decimal to binary (LSB first)
    while (n > 0) {
        binary += char((n % 2) + '0');
        n /= 2;
    }

    // Ensure length is enough
    while ((int)binary.size() <= i) {
        binary += '0';
    }

    // Clear the i-th bit
    binary[i] = '0';

    // Convert binary back to decimal
    int result = 0, power = 1;
    for (int j = 0; j < binary.size(); j++) {
        if (binary[j] == '1') result += power;
        power *= 2;
    }

    return result;
}

int clearIthBitOptimal(int n, int i) {
    return n & ~(1 << i);
}




int toggleIthBitBruteForce(int n, int i) {
    string binary = "";

    // Convert decimal to binary (LSB first)
    while (n > 0) {
        binary += char((n % 2) + '0');
        n /= 2;
    }

    // Ensure length is enough
    while ((int)binary.size() <= i) {
        binary += '0';
    }

    // Toggle the i-th bit
    binary[i] = (binary[i] == '0') ? '1' : '0';

    // Convert binary back to decimal
    int result = 0, power = 1;
    for (int j = 0; j < binary.size(); j++) {
        if (binary[j] == '1') result += power;
        power *= 2;
    }

    return result;
}

int toggleIthBitOptimal(int n, int i) {
    return n ^ (1 << i);
}



/*
====================================================
TURN OFF THE RIGHTMOST SET BIT — NOTES
====================================================

Expression:
n & (n - 1)

Explanation:
- n       = 100100
- n - 1   = 100011
- Result  = 100000

Effect:
✔ Rightmost set bit is turned off
✔ All other bits remain unchanged

Edge Case:
- If n = 0 → result is 0

Time Complexity: O(1)
Space Complexity: O(1)
====================================================
*/

int turnOffRightmostSetBit(int n) {
    return n & (n - 1);
}



/*
====================================================
CHECK IF A NUMBER IS POWER OF 2 — NOTES
====================================================

Condition:
n > 0 AND (n & (n - 1)) == 0

Explanation:
- n       = 1000
- n - 1   = 0111
- n&(n-1) = 0000  → power of 2

Edge Cases:
- n = 0 → NOT a power of 2
- Negative numbers → NOT powers of 2

Time Complexity: O(1)
Space Complexity: O(1)
====================================================
*/

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}



/*
====================================================
COUNT NUMBER OF SET BITS — NOTES
====================================================

Method 1: Brian Kernighan’s Algorithm
- Removes one set bit at a time
- Very efficient

Method 2: STL Built-in
- __builtin_popcount(n)
- __builtin_popcountll(n) for long long

Time Complexity:
- Kernighan: O(number of set bits)
- Built-in: O(1)

Space Complexity: O(1)
====================================================
*/

int countSetBitsOptimal(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int countSetBitsSTL(int n) {
    return __builtin_popcount(n);
}

int countSetBitsBrute(int n) {
    int cnt = 0;

    while (n > 1) {
        cnt += (n & 1);
        n = n >> 1;   // equivalent to n = n / 2
    }

    if (n == 1) cnt += 1;

    return cnt;
}


int main() {
    newline2;

    

    newline2;
    return 0;
}