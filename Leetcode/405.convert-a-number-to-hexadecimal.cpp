/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        
    }
};
// @lc code=end

/*
Here, you’re assigning a signed integer (int) to an unsigned integer variable.

In C++, when you assign a negative int to an unsigned, the compiler does not change the bits — it simply reinterprets the same bit pattern as a positive number in two’s complement form.

This is the entire trick that makes your hexadecimal conversion work for both positive and negative integers. ✅




🧠 Background: Two’s Complement Representation

In C++ (and most modern systems):
An int is stored in two’s complement form.
The most significant bit (MSB) represents the sign (0 = positive, 1 = negative).
Example (32-bit system):

Decimal	    Binary (32 bits)	                            Hexadecimal
26	        00000000 00000000 00000000 00011010	            0x0000001A
-26	        11111111 11111111 11111111 11100110	            0xFFFFFFE6

Notice that -26 in two’s complement is 0xFFFFFFE6.


Dry Run Example
int num2 = -26;
unsigned num = num2;

num2 = 11111111 11111111 11111111 11100110

Now, num gets the same bits, but is interpreted as a large unsigned number.
num = 11111111 11111111 11111111 11100110
    = 4294967270 (decimal)

So, effectively:
unsigned num = 4294967270;

rest while loop converts it into hexadecimal



Explicitly simulates 32-bit wraparound arithmetic -- if (num < 0) num = (1uLL << 32) + num;
num = -26
(1ULL << 32) = 4294967296
num = 4294967296 + (-26)
num = 4294967270


*/


class Solution {
public:
    string toHex(int num2) {
        string rep = "0123456789abcdef";
        if (num2 == 0) return "0";

        string ans = "";
        unsigned num = num2;
        while (num > 0) {
            int rem = num % 16;

            ans += rep[rem];
            num /= 16;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
public:
    string toHex(int num) {
        const string rep = "0123456789abcdef";
        if (num == 0) return "0";

        unsigned int n = static_cast<unsigned int>(num); // reinterpret bits as 32-bit unsigned
        string ans;

        while (n > 0) {
            int rem = n & 15;       // same as n % 16, but faster
            ans += rep[rem];
            n >>= 4;                // same as n /= 16
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};





class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        vector<char> toHexChar = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string result;
        while (num != 0 && result.size()<8){
            result = toHexChar[num&15] + result;
            num = num >> 4;
        }
        return result;
    }
};