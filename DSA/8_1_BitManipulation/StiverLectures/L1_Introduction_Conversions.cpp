/*

L1. Introduction to Bit Manipulation | 1's 2's Compliment | Bit Operators @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

*/

#include <iostream>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";
#include <bits/stdc++.h>
using namespace std;



/*
====================================================
DECIMAL ↔ ANY BASE CONVERSION — COMPLETE NOTES
====================================================

🔹 Number Systems
-----------------
A number system has a base (radix).

Common bases:
Base 2  → Binary
Base 8  → Octal
Base 10 → Decimal
Base 16 → Hexadecimal
Base 36 → Uses digits + uppercase letters

Digits used (Base ≤ 36):
0–9  → values 0 to 9
A–Z  → values 10 to 35

----------------------------------------------------
DECIMAL → ANY BASE
----------------------------------------------------
Logic:
1) Repeatedly divide the decimal number by the base
2) Store the remainder
3) Convert remainder to character:
   - 0–9  → '0' to '9'
   - 10+  → 'A' to 'Z'
4) Reverse the collected characters

Example:
Decimal = 125, Base = 8

125 ÷ 8 = 15 remainder 5
15  ÷ 8 = 1  remainder 7
1   ÷ 8 = 0  remainder 1

Result (reverse): 175

Time Complexity: O(log₍base₎ n)
Space Complexity: O(log₍base₎ n)

----------------------------------------------------
ANY BASE → DECIMAL
----------------------------------------------------
Logic:
1) Traverse digits from right to left
2) Convert each character to numeric value
3) Multiply by increasing powers of base
4) Add to result

Example:
"175" (base 8)
= 1×8² + 7×8¹ + 5×8⁰
= 125

Time Complexity: O(n)
Space Complexity: O(1)

----------------------------------------------------
IMPORTANT NOTES
----------------------------------------------------
✔ Base must be between 2 and 36
✔ Avoid pow() for performance
✔ Works for binary, octal, hex, etc.
====================================================
*/

/* -------------------------------------------------
   DECIMAL → ANY BASE
------------------------------------------------- */
string decimalToAnyBase(int n, int base) {
    if (n == 0) return "0";

    string res = "";
    while (n > 0) {
        int rem = n % base;
        if (rem < 10)
            res += char(rem + '0');
        else
            res += char(rem - 10 + 'A');
        n /= base;
    }

    reverse(res.begin(), res.end());
    return res;
}

/* -------------------------------------------------
   ANY BASE → DECIMAL
------------------------------------------------- */
int anyBaseToDecimal(const string &s, int base) {
    int res = 0;
    int power = 1;

    for (int i = s.length() - 1; i >= 0; i--) {
        char ch = s[i];
        int value;

        if (ch >= '0' && ch <= '9')
            value = ch - '0';
        else
            value = ch - 'A' + 10;

        res += value * power;
        power *= base;
    }

    return res;
}





/*
====================================================
DECIMAL ↔ BINARY CONVERSION NOTES
====================================================

1️⃣ Decimal to Binary
--------------------
Logic:
- Repeatedly divide the number by 2
- Store remainder (0 or 1)
- Reverse the result at the end

Example:
x = 13
13 % 2 = 1
6  % 2 = 0
3  % 2 = 1
1  % 2 = 1

Binary (reverse order): 1101

Time Complexity: O(log₂ n)
Space Complexity: O(log₂ n)

2️⃣ Binary to Decimal
--------------------
Logic:
- Start from rightmost bit
- Multiply by powers of 2
- Add to result

Example:
"1101"
= 1×2³ + 1×2² + 0×2¹ + 1×2⁰
= 13

Time Complexity: O(n)
Space Complexity: O(1)

====================================================
*/

/* -------------------------------------------------
   DECIMAL → BINARY
------------------------------------------------- */
string convertToBinary(int x) {
    if (x == 0) return "0";

    string res = "";
    while (x > 0) {
        if (x % 2 == 1)
            res += '1';
        else
            res += '0';
        x /= 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

/* -------------------------------------------------
   BINARY → DECIMAL
------------------------------------------------- */
int binaryToDecimal(const string &s) {
    int res = 0;
    int p2 = 1;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1')
            res += p2;
        p2 *= 2;
    }
    return res;
}


/*
====================================================
DECIMAL ↔ OCTAL CONVERSION — COMPLETE NOTES
====================================================

🔹 Octal Number System
---------------------
• Base = 8
• Digits allowed: 0 to 7

----------------------------------------------------
DECIMAL → OCTAL
----------------------------------------------------
Logic:
• Repeatedly divide the number by 8
• Store the remainder
• Reverse the collected digits

Example:
Decimal: 125

125 ÷ 8 = 15  remainder 5
15  ÷ 8 = 1   remainder 7
1   ÷ 8 = 0   remainder 1

Octal: 175

Time Complexity: O(log₈ n)
Space Complexity: O(log₈ n)

----------------------------------------------------
OCTAL → DECIMAL
----------------------------------------------------
Logic:
• Process digits from right to left
• Multiply each digit by powers of 8
• Add to result

Example:
Octal: 175

= 1×8² + 7×8¹ + 5×8⁰
= 64 + 56 + 5
= 125

Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/

/* -------------------------------------------------
   DECIMAL → OCTAL
------------------------------------------------- */
string decimalToOctal(int n) {
    if (n == 0) return "0";

    string res = "";
    while (n > 0) {
        int rem = n % 8;
        res += char(rem + '0');
        n /= 8;
    }
    reverse(res.begin(), res.end());
    return res;
}

/* -------------------------------------------------
   OCTAL → DECIMAL
------------------------------------------------- */
int octalToDecimal(const string &s) {
    int res = 0;
    int p8 = 1;

    for (int i = s.length() - 1; i >= 0; i--) {
        int digit = s[i] - '0';
        res += digit * p8;
        p8 *= 8;
    }
    return res;
}



/*
====================================================
DECIMAL ↔ HEXADECIMAL CONVERSION — COMPLETE NOTES
====================================================

🔹 Hexadecimal Number System
----------------------------
• Base = 16
• Digits allowed:
  0–9  → values 0 to 9
  A–F  → values 10 to 15

Mapping:
A = 10, B = 11, C = 12,
D = 13, E = 14, F = 15

----------------------------------------------------
DECIMAL → HEXADECIMAL
----------------------------------------------------
Logic:
• Repeatedly divide the decimal number by 16
• Store the remainder
• Convert remainder:
    - 0–9 → '0' to '9'
    - 10–15 → 'A' to 'F'
• Reverse the collected characters

Example:
Decimal: 254

254 ÷ 16 = 15  remainder F
15  ÷ 16 = 0   remainder F

Hexadecimal: FF

Time Complexity: O(log₁₆ n)
Space Complexity: O(log₁₆ n)

----------------------------------------------------
HEXADECIMAL → DECIMAL
----------------------------------------------------
Logic:
• Traverse from right to left
• Convert each character to its numeric value
• Multiply by powers of 16
• Add to result

Example:
Hexadecimal: FF

= 15×16¹ + 15×16⁰
= 240 + 15
= 255

Time Complexity: O(n)
Space Complexity: O(1)
====================================================
*/

/* -------------------------------------------------
   DECIMAL → HEXADECIMAL
------------------------------------------------- */
string decimalToHexadecimal(int n) {
    if (n == 0) return "0";

    string res = "";
    while (n > 0) {
        int rem = n % 16;
        if (rem < 10)
            res += char(rem + '0');
        else
            res += char(rem - 10 + 'A');
        n /= 16;
    }

    reverse(res.begin(), res.end());
    return res;
}

/* -------------------------------------------------
   HEXADECIMAL → DECIMAL
------------------------------------------------- */
int hexadecimalToDecimal(const string &s) {
    int res = 0;
    int p16 = 1;

    for (int i = s.length() - 1; i >= 0; i--) {
        char ch = s[i];
        int value;

        if (ch >= '0' && ch <= '9')
            value = ch - '0';
        else
            value = ch - 'A' + 10;

        res += value * p16;
        p16 *= 16;
    }

    return res;
}




/* -------------------------------------------------
   MAIN FUNCTION
------------------------------------------------- */
int main() {

    int x;
    cin >> x;

    string binary = convertToBinary(x);
    cout << "Binary representation: " << binary << endl;

    cout << "Converted back to decimal: "
         << binaryToDecimal(binary) << endl;

    return 0;
}
