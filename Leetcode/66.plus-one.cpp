/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
    }
};
// @lc code=end


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int sum = accumulate(digits.begin(), digits.end(), 0);

        int ind = n-1;
        
        while (ind >= 0) {
            digits[ind] = (digits[ind] + 1) % 10;

            if (digits[ind] != 0) {
                break;
            }
            ind--;
        }

        if (sum == 9*n) {
            digits.insert(digits.begin(), 1);
        }


        return digits;
    }
};




//Approach (Simple follow Math Addition Principles)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int i = n-1; //Start from LSB like usual math addition

        while(i >= 0) {
            if(digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }

            //else we did get 9
            digits[i] = 0; //9+1 = 10
            i--;
        }

        digits.insert(begin(digits), 1); //1 is the carry forwarded till the end

        return digits;


    }
};