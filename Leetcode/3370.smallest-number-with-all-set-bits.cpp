/*
 * @lc app=leetcode id=3370 lang=cpp
 *
 * [3370] Smallest Number With All Set Bits
 */

// @lc code=start
class Solution {
public:
    int smallestNumber(int n) {
        
    }
};
// @lc code=end


//Approach-1 (Simple looping till we get result)
//T.C : O(result - n), where result = (next power of 2 > n) - 1
//S.C : O(1)
class Solution {
public:
    bool isAllBitsSet(int x) {
        return (x & (x+1)) == 0;
    }
    int smallestNumber(int n) {
        int result = n;

        while(!isAllBitsSet(result)) {
            result++;
        }

        return result;
    }
};



//Approach-2 (Using properties of power of 2)
//T.C : O(log2(n))
//S.C : O(1)
class Solution {
public:
    int smallestNumber(int n) {
        int result = 1;

        while(result < n) {
            result = 2*result + 1;
        }

        return result;
    }
};



//Approach-3 (constant time but using same power of 2 property)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int smallestNumber(int n) {
        int bits = log2(n) + 1;

        return (1 << bits) - 1;
    }
};

