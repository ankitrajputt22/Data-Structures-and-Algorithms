/*

L2. Must Know Tricks in Bit Manipulation | Swap two numbers without third variable @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

*/

#include <iostream>
using namespace std;
#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

string convert2binary(int x) {
    string res = "";
    while (x > 0) { 
        if (x % 2 == 1) {
            res += '1';
        } else {
            res += '0';
        }
        x /= 2; 
    }
    reverse(res.begin(), res.end());
    
    return res;
}

void swap2numbers(int &a, int &b) {
    cout << "Before swapping : " << a << " " << b << endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "After swapping inside function : " << a << " " << b <<endl;
}

bool checkSet(int n, int i) {
    if (((n >> i) & 1) == 1) {   // (n & (1 << i) == 1)
        return true;
    }

    return false;
}

string setBit(string &s, int i) {
    if (i < 0 || i >= s.length()) {
        cout << "Invalid index" << endl;
        return s;
    }

    s[s.length() - i - 1] = '1';
    return s;                                          
}

/*
How it works:
1 << i creates a bitmask where only the i-th bit is 1
Example: i = 3 → 1 << 3 → 00001000 (binary)

n | mask performs bitwise OR:
If the bit was 0, it becomes 1
If the bit was 1, it remains 1

The result is stored back in n
*/

void setBit_2(int &n, int i) {
    n = n | (1 << i);
}

void clearBit(int &n, int i) {
    n = n & ~(1 << i);
}

void toggleBit(int &n, int i) {
    n = n ^ (1 << i);
}

int unsetLastSetBit(int n)
{
    return n & (n - 1);
}

class Solution_Brute {
public:
    bool isPowerOfTwo(int n) {
        for (int i =0; i<= 30 ;i++){
            int ans = pow(2,i);
            if (ans == n) {
                return true;
            }
        }
        return false;
    }
};

class Solution_2 {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        return ((1 << 30) % n == 0);
    }
};

class Solution_3 {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;

        return (n % 2 == 0) && isPowerOfTwo(n / 2);
    }
};

class Solution_4 {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        return (n & (n-1)) == 0;
    }
};


int cntSetBits_1(int num) {
    int cnt = 0;
    unsigned int n = num;  // Convert to unsigned
    
    while (n > 0) {
        if ((n % 2) == 1) {  // Now safe with unsigned
            cnt++;
        }
        n = n / 2;  // Use division to match modulo
    }
    
    return cnt;
}

int cntSetBits_2(int num) {
    int cnt = 0;
    unsigned int n = num;  // Convert to unsigned to avoid sign issues
    
    while (n > 0) {
        if ((n & 1) == 1) {
            cnt++;
        }
        n = n >> 1;
    }
    
    return cnt;
}

int cntSetBits_3(int n) {
    int cnt = 0;
    
    for (int i = 0; i < 32; i++) {  // Fixed 32 iterations for 32-bit integers
        if ((n >> i) & 1) {
            cnt++;
        }
    }
    
    return cnt;
}

int cntSetBits_Optimal(int n) {
    int cnt = 0;
    
    while (n != 0) {
        n &= (n - 1);  // Clears the rightmost set bit
        cnt++;
    }
    
    return cnt;
}


/*
Method 1 Explanation:
n + 1 flips all bits from the rightmost unset bit onward
Example: n = 5 (0101), n + 1 = 6 (0110)
n | (n + 1) sets the rightmost unset bit:
0101 | 0110 = 0111 (7)
*/

int setRightmostUnsetBit_1(int n) {
    // If n is 0, set the first bit to get 1
    if (n == 0) {
        return 1;
    }
    
    // Check if all bits are set (n is of form 2^k - 1)
    if ((n & (n + 1)) == 0) {
        // All bits are set, so we need to set the next higher bit
        // Example: n=15 (01111) → return 31 (11111)
        return (n << 1) | 1;  // Equivalent to 2*n + 1
    }
    
    // Set the rightmost unset bit
    return n | (n + 1);
}



/*
Method 2 Explanation:
Start with mask = 1 (0001)
Keep shifting left until we find a position where n has 0
n | mask sets that bit
*/

int setRightmostUnsetBit_2(int n) {
    int mask = 1;
    
    // Find the rightmost unset bit
    while (n & mask) {
        mask <<= 1;
    }
    
    // Set the found bit
    return n | mask;
}


int main() {
    newline1;
    int a = 6, b = 5;
    swap2numbers(a, b);
    cout << "After swapping outside function : " << a << " " << b <<endl;
    newline2;

    int x = 8;
    cout << "ith bit is set or not : " << checkSet(x, 3) << endl;
    newline2;

    int y = 9;
    string y_binary = convert2binary(y);
    cout << "Before setting the ith bit: " << y_binary << endl;
    cout << "set the ith bit: " << setBit(y_binary, 2) <<endl;
    setBit_2(y, 2);
    cout << "Set the ith bit: " << convert2binary(y);
    newline2;

    int c = -5;  // -5 in binary: 11111111111111111111111111111011
    cout << cntSetBits_1(c) << endl;
    cout << cntSetBits_2(c) << endl;
    cout << cntSetBits_3(c) << endl;


    return 0;
}






