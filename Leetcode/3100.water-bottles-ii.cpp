/*
 * @lc app=leetcode id=3100 lang=cpp
 *
 * [3100] Water Bottles II
 */

// @lc code=start
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
    }
};
// @lc code=end


class Solution {
public:
    int maxBottlesDrunk(int numB, int numE) {
        int drinkB = numB;

        int emptyB = numB;
        while (emptyB >= numE) {
            emptyB -= numE;
            
            drinkB += 1;
            emptyB++;
            numE++;
        }

        return drinkB;
    }
};
