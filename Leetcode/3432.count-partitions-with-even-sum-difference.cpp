/*
 * @lc app=leetcode id=3432 lang=cpp
 *
 * [3432] Count Partitions with Even Sum Difference
 */

// @lc code=start
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
    }
};
// @lc code=end


class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sumT = accumulate(nums.begin(), nums.end(), 0);

        int leftS = 0, rightS = 0;
        int part = 0;
        for (int i = 0; i < n-1; i++) {
            leftS += nums[i];
            rightS = sumT - leftS;

            if ((leftS - rightS) % 2 == 0) {
                part++;
            }
        }

        return part;
    }
};


//Approach-1 (Using cumulative sum)
//T.C : O(n) ( 2 Pass  )
//S.C : O(1)
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        int leftSum = 0;
        int result = 0;
        
        for(int i = 0; i < n-1; i++) {
            leftSum      += nums[i];
            int rightSum = sum - leftSum;

            if((leftSum - rightSum)%2 == 0)
                result++;
        }

        return result;
    }
};



//Approach-2 (Using one pass - Maths)
//T.C : O(n) ( 1 Pass  )
//S.C : O(1)
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum % 2 == 0)
            return n-1; //all partitions will be possible as it only depends on sum
        
        return 0;
    }
};



