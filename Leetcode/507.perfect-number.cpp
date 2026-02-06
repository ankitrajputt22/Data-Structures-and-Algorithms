/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {
        
    }
};
// @lc code=end

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 0;

        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        return sum == num;
    }
};


bool checkPerfectNumber(int num) {
    if(num == 1) return false;
    
    int sum = 1;

    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            sum += i + (num/i);
        }
    }

    return sum == num;
}

