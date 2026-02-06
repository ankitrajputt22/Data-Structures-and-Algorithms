/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 */

// @lc code=start
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
    }
};
// @lc code=end

//Approach-1 (Using STL count_if())
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {

        auto lambdaP = [](int num) {
            return num > 0;
        };

        auto lambdaN = [](int num) {
            return num < 0;
        };

        int countPositive = count_if(begin(nums), end(nums), lambdaP);
        int countNegative = count_if(begin(nums), end(nums), lambdaN);

        return max(countPositive, countNegative);
    }
};


//Approach-2 (Using lowerbound)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int firstP = lower_bound(begin(nums), end(nums), 1) - begin(nums);
        int firstN = lower_bound(begin(nums), end(nums), 0) - begin(nums);

        return max(n-firstP, firstN);
        
    }
};


