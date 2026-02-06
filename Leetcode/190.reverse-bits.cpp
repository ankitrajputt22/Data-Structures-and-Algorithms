/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
        
    }
};
// @lc code=end

/*
🔢 String → Number Conversion in C++
Function	Converts to	     Example	            Output
stoi(s)	    int	            stoi("123")	            123
stol(s)	    long	        stol("1234567890")	    1234567890
stoll(s)	long long	    stoll("9876543210")	    9876543210
stof(s)	    float	         stof("12.34")	         12.34
stod(s)	    double	        stod("45.678")	        45.678
stold(s)	long double	    stold("3.14159")	    3.14159

*/

int binaryToDecimal(string binary) {
    int decimal = 0;
    long long base = 1; 
    
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; 
    }
    return decimal;
}


class Solution {
public:

    int binaryToDecimal(string binary) {
        int decimal = 0;
        long long base = 1; 
        
        for (int i = binary.length() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                decimal += base;
            }
            base *= 2; 
        }
        return decimal;
    }

    int reverseBits(int n) {
        string s;
        for (int i = 0; i < 32; i++) {
            if (n == 0) {
                s += '0';
                continue;
            }
            if (n & 1) {
                s += '1';
            }
            else {
                s += '0';
            }

            n >>= 1;
        }
        cout << s;
        
        int m = binaryToDecimal(s);

        return m;
    }
};


class Solution {
public:
    int reverseBits(int n) {
        unsigned int rev = 0;
        for (int i = 0; i < 32; i++) {
            rev = (rev << 1) | (n & 1);
            n >>= 1;
        }
        return rev;
    }
};

