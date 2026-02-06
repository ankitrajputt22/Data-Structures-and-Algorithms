/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        
    }
};
// @lc code=end

class Solution {
public:
    bool check(char c) {
        unordered_set<char> st = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

        if (st.find(c) != st.end()) {
            return true;
        }

        return false;
    }

    int myAtoi(string s) {
        int n = s.length();

        int sign = 1;
        long long res = 0;
        int i = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }


        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int d = s[i] - '0';

            if (sign == 1 && res > (INT_MAX - d) / 10)
                return INT_MAX;

            if (sign == -1 && res > ((long long)INT_MAX + 1 - d) / 10)
                return INT_MIN;

            res = res * 10 + d;
            i++;
        }
        
        return res * sign;
    }
};



class Solution {
public:
    int helper(string &s, int i, int n, int sign, long long res) {
        // Base case: stop if end or non-digit
        if (i >= n || s[i] < '0' || s[i] > '9') {
            return (int)(res * sign);
        }

        int d = s[i] - '0';

        // Overflow check without using 7 or 8
        if (res > (INT_MAX - d) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        // Recursive step
        return helper(s, i + 1, n, sign, res * 10 + d);
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        if (i < n && s[i] == '-') {
            sign = -1; 
            i++;
        } 
        else if (i < n && s[i] == '+') {
            i++;
        }

        // Start recursion
        return helper(s, i, n, sign, 0);
    }
};
