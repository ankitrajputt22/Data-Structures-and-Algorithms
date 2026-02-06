/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution {
public:
    int totalMoney(int n) {
        
    }
};
// @lc code=end

class Solution {
public:
    int totalMoney(int n) {
        int mon = 0;
        int res = 0;

        int toAdd = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 7 == 1) {
                mon++;
                toAdd = mon;
            }
            
            res += toAdd;
            toAdd++;
        }

        return res;
    }
};





//Approach-1 (Simple simulation)
//T.C : O(1) - see the video above to know why
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int result = 0;

        int monday_money = 1; //1dollar

        while(n > 0) {

            int money = monday_money; //1
            for(int day = 1; day <= min(n, 7); day++) {
                result += money;
                money++;
            }

            n -= 7;
            monday_money++;
        }

        return result;
    }
};



//Approach-2 (Using AP and a for loop)
//T.C : O(1) - see the video above to know why
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7; //Weeks

        int first = 28;
        int last  = 28 + (terms - 1) * 7; //AP formula for n-th term

        int result = terms * (first + last) / 2; //Sum of nth terms in an AP


        //Final week remaining days = n%7
        int start_money = 1 + terms;

        for(int day = 1; day <= (n%7); day++) {
            result += start_money;
            start_money++;
        }

        return result;
    }
};



//Approach-3 (Using AP completely)
//T.C : O(1) - see the video above to know why
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7; //Weeks

        int first = 28;
        int last  = 28 + (terms - 1) * 7; //AP formula for n-th term

        int result = terms * (first + last) / 2; //Sum of nth terms in an AP


        //remaining days
        int remain = n%7;
        int first_term = (1 + terms);
        int last_term  = first_term + remain - 1;
        result += remain * (first_term + last_term) / 2;

        return result;
    }
};