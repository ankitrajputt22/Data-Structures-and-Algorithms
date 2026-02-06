/*
 * @lc app=leetcode id=1390 lang=cpp
 *
 * [1390] Four Divisors
 */

// @lc code=start
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
    }
};
// @lc code=end



class Solution {
public:
    int cntDivisorsSum2(int n) {
        int cnt = 2;

        int sum = 1 + n;
        for (int i = 2; i <= n/2; i++) {
            if (n % i == 0) {
                cnt++;
                sum += i;
            }
        }

        if (cnt == 4) {
            return sum;
        }

        return -1;
    }

    int cntDivisorsSum(int n) {
        int cnt = 0;
        int sum = 0;

        for (int i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                sum += i;

                if (i != n/i) {
                    cnt++;
                    sum += n/i;
                }
            }
        }

        if (cnt == 4) {
            return sum;
        }

        return -1;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int val = cntDivisorsSum(nums[i]);
            if (val != -1) {
                sum += val;
            }
        }

        return sum;
    }
};





//Approach - Simple maths - Iterate and find factors
//T.C : O(n * sqrt(maxNumber))
//S.C : O(1)
class Solution {
public:
    int sumIfFourDivisors(int num) {
        int divisors = 0;
        int sum = 0;

        for (int div = 1; div * div <= num; div++) {
            if (num % div == 0) {
                int other = num / div;

                if (div == other) {
                    divisors++;
                    sum += div;
                } else {
                    divisors += 2;
                    sum += (div + other);
                }
            }

            if (divisors > 4) {
                return 0;
            }
        }

        return divisors == 4 ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (int &num : nums) {
            result += sumIfFourDivisors(num);
        }

        return result;
    }
};
