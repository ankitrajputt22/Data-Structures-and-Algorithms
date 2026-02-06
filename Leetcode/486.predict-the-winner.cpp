/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        
    }
};
// @lc code=end

class Solution {
public:
    int calculateScore(int i, int j, vector<int> &nums) {
        if (j <= i) {
            return nums[i];
        }

        // giving difference p1-p2 as both will play optimally then the difference p1-p2 >= 0 for p1 to win else p2 will win
        // now p1 will choose best and then p2 will choose best 
        int take_i = nums[i] - calculateScore(i+1, j, nums);  // p1 - maxby(p2)
        int take_j = nums[j] - calculateScore(i, j-1, nums);  // p1 - maxby(p2)
        
        return max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        return calculateScore(0, n-1, nums) >= 0;
    }   
};



//Recursion + Memo - I
//Approach-1 (Using same as Optimal Code Strategy)
class Solution {
public:
    int n;
    int t[23][23];
    int solve(vector<int>& nums, int l, int r) {
        
        if(l > r)
            return 0;
        
        if(l == r)
            return nums[l];
        
        if(t[l][r] != -1)
            return t[l][r];
        
        int take_left  = nums[l] + min(solve(nums, l+2, r), solve(nums, l+1, r-1));
        
        int take_right = nums[r] + min(solve(nums, l, r-2), solve(nums, l+1, r-1));
        
        
        return t[l][r] = max(take_left, take_right);
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        memset(t, -1, sizeof(t));
        
        n = nums.size();
        
        
        int total = accumulate(begin(nums), end(nums), 0);
        
        int player1 = solve(nums, 0, n-1);
        int player2 = total - player1;
        
        return player1 >= player2;
    }
};


//Recursion + Memo - II
//Approach-2 (Using diff of score between players)
class Solution {
public:
    int n;
    int t[23][23];
    
    //Player1 - Player2
    int maxDiff(vector<int>& nums, int l, int r) {
        
        if(l == r)
            return nums[l];
        
        if(t[l][r] != -1)
            return t[l][r];
        
        int take_left  = nums[l] - maxDiff(nums, l+1, r);
        int take_right = nums[r] - maxDiff(nums, l, r-1);
        
        return t[l][r] = max(take_left, take_right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return maxDiff(nums, 0, n-1) >= 0;
            
    }
};