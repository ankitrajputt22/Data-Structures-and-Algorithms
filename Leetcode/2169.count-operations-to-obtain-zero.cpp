/*
 * @lc app=leetcode id=2169 lang=cpp
 *
 * [2169] Count Operations to Obtain Zero
 */

// @lc code=start
class Solution {
public:
    int countOperations(int num1, int num2) {
        
    }
};
// @lc code=end
#include <bits/stdc++.h>
#include <regex>

class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;

        while (num1 != 0 && num2 != 0) {
            if (num1 >= num2) {
                num1 = num1- num2;
                count++;
            } 
            else {
                num2 = num2 - num1;
                count++;
            }
        }

        return count;
    }
};



//Approach-1 (Using Maths similar to Euclidean Algorithm - Iterative)
//T.C : O(log(min(a, b)))
//S.C : O(1)
class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;

        while(num1 > 0 && num2 > 0) {
            count += num1/num2;

            num1 %= num2;

            swap(num1, num2);
        }

        return count;
    }
};


//Approach-2 (Using Maths similar to Euclidean Algorithm - Recursion)
//T.C : O(log(min(a, b)))
//S.C : O(1)
class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0)
            return 0;

        if(num1 < num2)
            swap(num1, num2);

        
        return num1/num2 + countOperations(num1%num2, num2);
    }
};

