/*
 * @lc app=leetcode id=3147 lang=cpp
 *
 * [3147] Taking Maximum Energy From the Mystic Dungeon
 */

// @lc code=start
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
    }
};
// @lc code=end


// Simply iteration
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        vector<int> dp(n);
        int maxE = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i] = 0;
            for (int j = i; j < n; j += k) {
                dp[i] += energy[j];
            }

            maxE = max(dp[i], maxE);
        }

        return maxE;
    }
};


// Recursion
class Solution {
public:
    int solve(int i, vector<int> &energy, int k) {
        if (i >= energy.size()) {
            return 0;
        }

        return energy[i] + solve(i+k, energy, k);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        int maxE = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxE = max(maxE, solve(i, energy, k));
        }

        return maxE;
    }
};


// memoization

class Solution {
public:
    int solve(int i, vector<int> &energy, int k, vector<int> &dp) {
        if (i >= energy.size()) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        return dp[i] = energy[i] + solve(i+k, energy, k, dp);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        int maxE = INT_MIN;
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) {
            maxE = max(maxE, solve(i, energy, k, dp));
        }

        return maxE;
    }
};


//Approach-2 - Bottom Up
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> t(n, 0); // DP array

        for (int i = n - 1; i >= 0; i--) { // see my video to understand why right to left traversal is needed here
            if (i + k < n)
                t[i] = energy[i] + t[i + k];
            else
                t[i] = energy[i];
        }

        return *max_element(begin(t), end(t));
    }
};



//Approach-1 - Recursion + Memoization
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int n;
    int K;

    int solve(int i, vector<int>& energy, vector<int>& t) {
        if (i >= n) 
            return 0;
        
        if (t[i] != INT_MIN)
            return t[i];

        // Take energy at i and then best from (i + k) onwards - Recursion leap of faith
        t[i] = energy[i] + solve(i + K, energy, t);
        
        return t[i];
    }

    int maximumEnergy(vector<int>& energy, int k) {
        n = energy.size();
        K = k;
        vector<int> t(n, INT_MIN);     // Initialize memoization array

        int maxEnergy = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxEnergy = max(maxEnergy, solve(i, energy, t));
        }

        return maxEnergy;
    }
};
